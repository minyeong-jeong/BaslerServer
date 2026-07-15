# install-service.ps1  (BaslerServer -- Computer 1, the Basler trigger MASTER)
#
# Installs BaslerServer.exe as an auto-restarting Windows service via NSSM so it
# starts on boot (headless, no login) and is relaunched if it crashes.
#
# Run from an *elevated* PowerShell on Computer 1 after building BaslerServer.exe
# (x64 / Release). Requires nssm.exe on PATH (e.g. `choco install nssm`).
#
#   .\install-service.ps1
#   .\install-service.ps1 -ExePath D:\apps\BaslerServer.exe
#   .\install-service.ps1 -Account ".\camops"     # run as a specific user
#
# Boot order across the 4 PCs is enforced by the orchestrator (dashboard sends
# /configure to the master first), NOT by service start order -- so a plain
# per-machine auto-start is all that's needed here.

param(
    [string]$ServiceName = "BaslerServer",
    [string]$ExePath     = "C:\vision\BaslerServer.exe",
    [string]$LogDir      = "C:\vision\logs",
    [string]$Account     = "LocalSystem",   # or ".\user" / "DOMAIN\user"
    [string]$Password    = ""                # required only for a non-system account
)

$ErrorActionPreference = "Stop"

# --- preflight -----------------------------------------------------------------
$isAdmin = ([Security.Principal.WindowsPrincipal] `
    [Security.Principal.WindowsIdentity]::GetCurrent()`
    ).IsInRole([Security.Principal.WindowsBuiltinRole]::Administrator)
if (-not $isAdmin) { Write-Error "Run this from an elevated (Administrator) PowerShell."; exit 1 }

if (-not (Get-Command nssm -ErrorAction SilentlyContinue)) {
    Write-Error "nssm.exe not found on PATH. Install NSSM first (e.g. choco install nssm)."; exit 1
}
if (-not (Test-Path $ExePath)) {
    Write-Error "$ExePath not found. Build x64/Release first, or pass -ExePath."; exit 1
}

$exeDir = Split-Path -Parent $ExePath
New-Item -ItemType Directory -Force $LogDir | Out-Null

# --- idempotent: remove any prior install --------------------------------------
& nssm status $ServiceName 2>$null | Out-Null
if ($LASTEXITCODE -eq 0) {
    Write-Host "Existing $ServiceName found - stopping and removing..."
    & nssm stop   $ServiceName confirm 2>$null | Out-Null
    & nssm remove $ServiceName confirm | Out-Null
    Start-Sleep -Seconds 1
}

# --- install -------------------------------------------------------------------
Write-Host "Installing $ServiceName -> $ExePath"
& nssm install $ServiceName $ExePath

# Working dir so the Pylon runtime DLLs resolve at launch.
& nssm set $ServiceName AppDirectory $exeDir

# Account. LocalSystem starts on boot with no login; use a named user only if your
# camera drivers grant device access solely to that user's session.
if ($Account -eq "LocalSystem") {
    & nssm set $ServiceName ObjectName LocalSystem
} else {
    if (-not $Password) {
        $sec = Read-Host "Password for $Account" -AsSecureString
        $Password = [Runtime.InteropServices.Marshal]::PtrToStringAuto(
            [Runtime.InteropServices.Marshal]::SecureStringToBSTR($sec))
    }
    & nssm set $ServiceName ObjectName $Account $Password
}

# Start on boot, but DELAYED so the CXP frame-grabber drivers come up first.
& nssm set $ServiceName Start SERVICE_DELAYED_AUTO_START

# --- auto-restart on crash -----------------------------------------------------
& nssm set $ServiceName AppExit Default Restart     # always restart on exit
& nssm set $ServiceName AppRestartDelay 3000        # wait 3s before relaunch
& nssm set $ServiceName AppThrottle 5000            # <5s uptime => crash-loop backoff

# --- graceful stop: Ctrl-C first so the app's SIGINT handler can clean up -------
& nssm set $ServiceName AppStopMethodConsole 10000
& nssm set $ServiceName AppStopMethodWindow 5000
& nssm set $ServiceName AppStopMethodThreads 5000

# --- logging with rotation (these apps are very chatty) ------------------------
& nssm set $ServiceName AppStdout "$LogDir\$ServiceName-out.log"
& nssm set $ServiceName AppStderr "$LogDir\$ServiceName-err.log"
& nssm set $ServiceName AppRotateFiles 1
& nssm set $ServiceName AppRotateOnline 1
& nssm set $ServiceName AppRotateBytes 10485760     # rotate at 10 MB

# --- go ------------------------------------------------------------------------
& nssm start $ServiceName
Start-Sleep -Seconds 2
& nssm status $ServiceName

Write-Host ""
Write-Host "Done. Verify with:  Invoke-WebRequest http://localhost:8080/status"
Write-Host "  (expect UNINITIALIZED until the dashboard sends /configure)"
