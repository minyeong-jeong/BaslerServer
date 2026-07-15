#include <iostream>
#include <conio.h>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <direct.h>
#include <thread>
#include <chrono>
#include <vector>
#include <thread>
#include <atomic>
#include <csignal>
#include <cctype>

#include "httplib.h"
#include "json.hpp"

#include <pylon/PylonIncludes.h>
#include <pylon/PylonGUI.h>


namespace Pylon {
    class CInstantCamera;
}
class CMasterCardMasterCameraConfiguration : public Pylon::CConfigurationEventHandler {
public:
    std::string pixelFormat;
    CMasterCardMasterCameraConfiguration(const std::string& pixelFormat = "RGB8") : pixelFormat(pixelFormat) {}
    void OnOpened(Pylon::CInstantCamera& camera) {
        try {

			GenApi::INodeMap& nodemap = camera.GetNodeMap();
			GenApi::INodeMap& tlNodemap = camera.GetTLNodeMap();


			/* Setting the trigger on master camera */

			Pylon::CEnumParameter areaTriggerMode(tlNodemap, "AreaTriggerMode");
			areaTriggerMode.SetValue("Generator");
			// std::cout << "AreaTriggerMode set to: " << areaTriggerMode.GetValue() << std::endl;

			Pylon::CFloatParameter triggerOutputFrequency(tlNodemap, "TriggerOutputFrequency");
			triggerOutputFrequency.SetValue(24.0);
			// std::cout << "TriggerOutputFrequency set to: " << triggerOutputFrequency.GetValue() << std::endl;


			/* Routing the trigger to GPO */

			Pylon::CEnumParameter triggerOutSelectFrontGPO0(tlNodemap, "TriggerOutSelectFrontGPO0");
			triggerOutSelectFrontGPO0.SetValue("PulseGenerator0");
			// std::cout << "TriggerOutSelectFrontGPO0 set to: " << triggerOutSelectFrontGPO0.GetValue() << std::endl;


			/* Routing the trigger to the camera */

			Pylon::CEnumParameter cxpLinkTrigger0Source(tlNodemap, "CxpLinkTrigger0Source");
			cxpLinkTrigger0Source.SetValue("PulseGeneratorRisingEdge");
			// std::cout << "CxpLinkTrigger0Source set to: " << cxpLinkTrigger0Source.GetValue() << std::endl;


			/* Setting the camera to recieve the trigger */

			Pylon::CEnumParameter frameStart(nodemap, "TriggerSelector");
			frameStart.SetValue("FrameStart");
			// std::cout << "TriggerSelector set to: " << frameStart.GetValue() << std::endl;

			Pylon::CEnumParameter triggerMode(nodemap, "TriggerMode");
			triggerMode.SetValue("On");
			// std::cout << "TriggerMode set to: " << triggerMode.GetValue() << std::endl;

			Pylon::CEnumParameter triggerSource(nodemap, "TriggerSource");
			triggerSource.SetValue("CxpTrigger0");
			// std::cout << "TriggerSource set to: " << triggerSource.GetValue() << std::endl;


			/* Setting camera variables */

			/* Exposure time */

			Pylon::CEnumParameter exposureMode(nodemap, "ExposureMode");
			exposureMode.SetValue("Timed");
			// std::cout << "ExposureMode set to: " << exposureMode.GetValue() << std::endl;

			Pylon::CEnumParameter exposureAuto(nodemap, "ExposureAuto");
			exposureAuto.SetValue("Off");
			// std::cout << "ExposureAuto set to: " << exposureAuto.GetValue() << std::endl;

			Pylon::CEnumParameter exposureTimeMode(nodemap, "ExposureTimeMode");
			exposureTimeMode.SetValue("Common");
			// std::cout << "ExposureTimeMode set to: " << exposureTimeMode.GetValue() << std::endl;

			Pylon::CEnumParameter exposureTimeSelector(nodemap, "ExposureTimeSelector");
			exposureTimeSelector.SetValue("Common");
			// std::cout << "ExposureTimeSelector set to: " << exposureTimeSelector.GetValue() << std::endl;

			Pylon::CFloatParameter exposureTime(nodemap, "ExposureTime");
			exposureTime.SetValue(2000.0);
			// std::cout << "ExposureTime set to: " << exposureTime.GetValue() << std::endl;

			/* Gain */

			Pylon::CEnumParameter gainAuto(nodemap, "GainAuto");
			gainAuto.SetValue("Off");
			// std::cout << "GainAuto set to: " << gainAuto.GetValue() << std::endl;

			Pylon::CEnumParameter gainSelector(nodemap, "GainSelector");
			gainSelector.SetValue("All");
			// std::cout << "GainSelector set to: " << gainSelector.GetValue() << std::endl;

			Pylon::CFloatParameter gain(nodemap, "Gain");
			gain.SetValue(0.0);
			// std::cout << "Gain set to: " << gain.GetValue() << std::endl;

			/* Image Pattern */

			Pylon::CEnumParameter pixelFormat(nodemap, "PixelFormat");
			pixelFormat.SetValue(this->pixelFormat.c_str());
			// std::cout << "PixelFormat set to: " << pixelFormat.GetValue() << std::endl;

			std::cout << "Master camera configured" << std::endl;

        }
        catch (const Pylon::GenericException& e) {
            throw RUNTIME_EXCEPTION("Could not apply configuration. const GenericExecption caught in OnOpened method ms=%hs", e.what());
        }
    }
};
class CMasterCardSlaveCameraConfiguration : public Pylon::CConfigurationEventHandler {
public:
    std::string pixelFormat;
    CMasterCardSlaveCameraConfiguration(const std::string& pixelFormat = "RGB8") : pixelFormat(pixelFormat) {}
    void OnOpened(Pylon::CInstantCamera& camera) {
        try {

			GenApi::INodeMap& nodemap = camera.GetNodeMap();
			GenApi::INodeMap& tlNodemap = camera.GetTLNodeMap();


			/* Setting the trigger on slave camera */

			Pylon::CEnumParameter areaTriggerMode(tlNodemap, "AreaTriggerMode");
			areaTriggerMode.SetValue("Synchronized");
			// std::cout << "AreaTriggerMode set to: " << areaTriggerMode.GetValue() << std::endl;

			Pylon::CFloatParameter triggerOutputFrequency(tlNodemap, "TriggerOutputFrequency");
			triggerOutputFrequency.SetValue(35.0);
			// std::cout << "TriggerOutputFrequency set to: " << triggerOutputFrequency.GetValue() << std::endl;



			/* Routing the trigger to the camera */

			Pylon::CEnumParameter cxpLinkTrigger0Source(tlNodemap, "CxpLinkTrigger0Source");
			cxpLinkTrigger0Source.SetValue("CamBPulseGenerator0RisingEdge");
			// std::cout << "CxpLinkTrigger0Source set to: " << cxpLinkTrigger0Source.GetValue() << std::endl;


			/* Setting the camera to recieve the trigger */

			Pylon::CEnumParameter frameStart(nodemap, "TriggerSelector");
			frameStart.SetValue("FrameStart");
			// std::cout << "TriggerSelector set to: " << frameStart.GetValue() << std::endl;

			Pylon::CEnumParameter triggerMode(nodemap, "TriggerMode");
			triggerMode.SetValue("On");
			// std::cout << "TriggerMode set to: " << triggerMode.GetValue() << std::endl;

			Pylon::CEnumParameter triggerSource(nodemap, "TriggerSource");
			triggerSource.SetValue("CxpTrigger0");
			// std::cout << "TriggerSource set to: " << triggerSource.GetValue() << std::endl;


			/* Setting camera variables */

			/* Exposure time */

			Pylon::CEnumParameter exposureMode(nodemap, "ExposureMode");
			exposureMode.SetValue("Timed");
			// std::cout << "ExposureMode set to: " << exposureMode.GetValue() << std::endl;

			Pylon::CEnumParameter exposureAuto(nodemap, "ExposureAuto");
			exposureAuto.SetValue("Off");
			// std::cout << "ExposureAuto set to: " << exposureAuto.GetValue() << std::endl;

			Pylon::CEnumParameter exposureTimeMode(nodemap, "ExposureTimeMode");
			exposureTimeMode.SetValue("Common");
			// std::cout << "ExposureTimeMode set to: " << exposureTimeMode.GetValue() << std::endl;

			Pylon::CEnumParameter exposureTimeSelector(nodemap, "ExposureTimeSelector");
			exposureTimeSelector.SetValue("Common");
			// std::cout << "ExposureTimeSelector set to: " << exposureTimeSelector.GetValue() << std::endl;

			Pylon::CFloatParameter exposureTime(nodemap, "ExposureTime");
			exposureTime.SetValue(2000.0);
			// std::cout << "ExposureTime set to: " << exposureTime.GetValue() << std::endl;

			/* Gain */

			Pylon::CEnumParameter gainAuto(nodemap, "GainAuto");
			gainAuto.SetValue("Off");
			// std::cout << "GainAuto set to: " << gainAuto.GetValue() << std::endl;

			Pylon::CEnumParameter gainSelector(nodemap, "GainSelector");
			gainSelector.SetValue("All");
			// std::cout << "GainSelector set to: " << gainSelector.GetValue() << std::endl;

			Pylon::CFloatParameter gain(nodemap, "Gain");
			gain.SetValue(0.0);
			// std::cout << "Gain set to: " << gain.GetValue() << std::endl;

			/* Image Pattern */

			Pylon::CEnumParameter pixelFormat(nodemap, "PixelFormat");
			pixelFormat.SetValue(this->pixelFormat.c_str());
			// std::cout << "PixelFormat set to: " << pixelFormat.GetValue() << std::endl;

			/* Slaves are activated early */

			Pylon::CEnumParameter triggerState(tlNodemap, "TriggerState");
			triggerState.SetValue("Active");
			// std::cout << "TriggerState set to: " << triggerState.GetValue() << std::endl;

			std::cout << "Slave camera configured" << std::endl;

        }
        catch (const Pylon::GenericException& e) {
            throw RUNTIME_EXCEPTION("Could not apply configuration. const GenericExecption caught in OnOpened method ms=%hs", e.what());
        }
    }
};

class BaslerServer {
private:
	size_t capacity;        // max frames per camera reserved at /configure time
	size_t frameCount;      // frames to record for the current job (<= capacity)
	Pylon::CInstantCameraArray* cameras;
	const size_t cameraCount = 4;
	std::string folderName;
	std::string pixelFormat;
	bool pylonInitialized;
	std::atomic<bool> configured;

	std::vector<std::vector<Pylon::CGrabResultPtr>> grabResultVector;

public:
	BaslerServer()
		: capacity(0)
		, frameCount(0)
		, cameras(nullptr)
		, folderName("")
		, pixelFormat("RGB8")
		, pylonInitialized(false)
		, configured(false)
	{
	}

	void setFolderName(std::string folderName) {
		this->folderName = "E:\\" + folderName;
	}

	bool isConfigured() const { return configured.load(); }
	size_t getCapacity() const { return capacity; }

	// Phase-2 init: apply the run-independent settings the orchestrator chose
	// (pixel format + memory capacity), open the cameras and start grabbing.
	// Re-callable to change settings between runs (tears the old session down first).
	// Returns true once the cameras are grabbing and jobs can be accepted.
	bool configure(size_t capacity, const std::string& pixelFormat) {

		// Tear down a previous session so capacity/format can change between runs.
		if (cameras != nullptr) {
			try {
				if (cameras->IsGrabbing()) cameras->StopGrabbing();
			}
			catch (...) {}
			delete cameras;
			cameras = nullptr;
		}
		configured = false;

		this->capacity = capacity;
		this->pixelFormat = pixelFormat;

		std::cout << "Configuring: capacity=" << capacity
			<< " pixelFormat=" << pixelFormat << std::endl;

		const int maxAttempts = 30;

		for (int attempt = 1; attempt <= maxAttempts; ++attempt) {

			std::cout << "Configure attempt " << attempt << "/" << maxAttempts << std::endl;

			try {

				if (!pylonInitialized) {
					Pylon::PylonInitialize();
					pylonInitialized = true;
				}

				Pylon::CTlFactory& tlFactory = Pylon::CTlFactory::GetInstance();

				Pylon::DeviceInfoList_t devices;
				tlFactory.EnumerateDevices(devices);
				if (devices.size() < this->cameraCount) {
					std::cerr << "Found " << devices.size() << " cameras, need "
						<< this->cameraCount << ". Retrying..." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(2));
					continue;
				}

				for (Pylon::DeviceInfoList_t::const_iterator it = devices.begin(); it != devices.end(); ++it) {
					std::cout << "Camera found:\t" << it->GetFullName() << std::endl;
				}

				cameras = new Pylon::CInstantCameraArray(this->cameraCount);

				for (size_t i = 0; i < this->cameraCount; ++i) {
					(*cameras)[i].Attach(tlFactory.CreateDevice(devices[i]));
				}

				// Camera 3 is the trigger master; 0..2 are synchronized slaves.
				// The chosen pixel format is injected into each configuration handler.
				(*cameras)[3].RegisterConfiguration(new CMasterCardMasterCameraConfiguration(this->pixelFormat), Pylon::RegistrationMode_Append, Pylon::Cleanup_Delete);

				for (size_t i = 0; i < this->cameraCount - 1; ++i) {
					(*cameras)[i].RegisterConfiguration(new CMasterCardSlaveCameraConfiguration(this->pixelFormat), Pylon::RegistrationMode_Append, Pylon::Cleanup_Delete);
				}

				// Reserve enough grab buffers per camera for the largest job (capacity).
				for (size_t i = 0; i < this->cameraCount; ++i) {
					(*cameras)[i].MaxNumBuffer = static_cast<int>(this->capacity);
				}

				std::cout << "Start grabbing" << std::endl;
				cameras->StartGrabbing();

				for (size_t i = 0; i < this->cameraCount; ++i) {
					GenApi::INodeMap& tlNodemap = (*cameras)[i].GetTLNodeMap();
					Pylon::CCommandParameter countClear(tlNodemap, "TriggerOutStatisticsPulseCountClear");
					countClear.Execute();
				}

				configured = true;
				std::cout << "Configured. Ready for jobs." << std::endl;
				return true;

			}
			catch (const Pylon::GenericException& e) {
				std::cerr << "Configure attempt failed: " << e.GetDescription() << std::endl;
				if (cameras != nullptr) { delete cameras; cameras = nullptr; }
				std::this_thread::sleep_for(std::chrono::seconds(2));
			}
			catch (...) {
				std::cerr << "Configure attempt failed: unknown exception" << std::endl;
				if (cameras != nullptr) { delete cameras; cameras = nullptr; }
				std::this_thread::sleep_for(std::chrono::seconds(2));
			}
		}

		std::cerr << "Configure failed after " << maxAttempts << " attempts." << std::endl;
		return false;
	}

	void startRecord(size_t actualFrameCount, size_t offset) {

		try {

			std::cout << "Generate Folder" << std::endl;

			std::cout << this->folderName << std::endl;

			if (_mkdir(this->folderName.c_str()) != 0) {
				std::cerr << "Folder already exists" << std::endl;
			}

			std::cout << "Generated folder" << std::endl;

			this->grabResultVector = std::vector<std::vector<Pylon::CGrabResultPtr>>(4, std::vector<Pylon::CGrabResultPtr>(actualFrameCount));

			Pylon::CGrabResultPtr ptrGrabResult;

			std::cout << "set to trigger active" << std::endl;


			GenApi::INodeMap& tlNodemap = (*cameras)[3].GetTLNodeMap();
			Pylon::CEnumParameter triggerState(tlNodemap, "TriggerState");


			std::cout << "set to start grabbing" << std::endl;
			triggerState.SetValue("Active");

			std::cout << "Main grabbing loop" << std::endl;

			// Main grabbing loop
			for (size_t i = 0; i < actualFrameCount * 4 && this->cameras->IsGrabbing(); ++i) {
				this->cameras->RetrieveResult(5000, ptrGrabResult, Pylon::TimeoutHandling_Return);
				std::cout << "grabbing image..." << std::endl;

				if (ptrGrabResult->GrabSucceeded()) {
					intptr_t cameraContextValue = ptrGrabResult->GetCameraContext();
					intptr_t imageNumber = ptrGrabResult->GetImageNumber();
					std::cout << "Image grabbed successfully from camera " << cameraContextValue << ", image number: " << imageNumber << ", offset: " << offset << std::endl;
					this->grabResultVector[cameraContextValue][imageNumber - offset - 1] = ptrGrabResult;
				}
				else {
					std::cout << "Error: " << std::hex << ptrGrabResult->GetErrorCode() << std::dec << " " << ptrGrabResult->GetErrorDescription() << std::endl;
				}
			}

			triggerState.SetValue("SyncStop");
		}
		catch (const Pylon::GenericException& e) {
			// Log and continue; do not tear down the Pylon runtime on a transient error.
			std::cerr << "An exception occurred." << std::endl
				<< e.GetDescription() << std::endl;
		}
		catch (...) {
			std::cerr << "An unknown exception occurred." << std::endl;
		}

	}


	void saveImages(size_t actualFrameCount) {

		try {

			// For debug purposes
			// Pylon::CIntegerParameter triggerOutStatisticsPulseCount((*(this->tlNodemap)), "TriggerOutStatisticsPulseCount");
			// std::cout << "TriggerOutStatisticsPulseCount: " << triggerOutStatisticsPulseCount.GetValue() << std::endl;

			// save images
			for (size_t i = 0; i < actualFrameCount; ++i) {
				for (size_t cam = 0; cam < this->cameraCount; ++cam) {

					std::cout << "Saving " << cam << " of frame " << i << std::endl;

					Pylon::CPylonImage image;

					image.AttachGrabResultBuffer(this->grabResultVector[cam][i]);

					std::ostringstream oss;
					oss << std::setw(6) << std::setfill('0') << i;
					std::string imageNumberStr = oss.str();

					std::string imageName =
						this->folderName
						+ "\\"
						+ imageNumberStr
						+ "_"
						+ std::to_string(cam)
						+ ".bmp";
					image.Save(Pylon::ImageFileFormat_Bmp, Pylon::String_t(imageName.c_str()));
				}
			}

		}
		catch (const Pylon::GenericException& e) {
			// Log and continue; do not tear down the Pylon runtime on a transient error.
			std::cerr << "An exception occurred." << std::endl
				<< e.GetDescription() << std::endl;
		}
		catch (...) {
			std::cerr << "An unknown exception occurred." << std::endl;
		}



	}

	~BaslerServer() {
		if (cameras != nullptr) {
			delete cameras;
			cameras = nullptr;
		}
		if (pylonInitialized) {
			Pylon::PylonTerminate();
		}
	}
};

enum class ServerStatus {
	UNINITIALIZED,
	IDLE,
	TRIGGER_FINISHED,
	WORKING,
	READY
};

// Accept RGB8 / Mono8 from the orchestrator (case-insensitive); return the exact
// Basler PixelFormat enum string, or "" if unsupported.
static std::string normalizePixelFormat(std::string s) {
	std::string up;
	for (char c : s) up += static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
	if (up == "RGB8") return "RGB8";
	if (up == "MONO8") return "Mono8";
	return "";
}

std::atomic<ServerStatus> serverStatus(ServerStatus::IDLE);

bool running = true;

void signalHandler(int signum) {
	std::cout << "Interrupt signal (" << signum << ") received. Exiting..." << std::endl;
	running = false;
}

int main(int /*argc*/, char* /*argv*/[])
{

	httplib::Server svr;
	BaslerServer basler;
	size_t frameCount;
	size_t offset = 0;

	std::signal(SIGINT, signalHandler);

	// Two-phase startup: come up UNINITIALIZED and serve immediately so the
	// orchestrator can /configure this machine (the master must be configured first).
	serverStatus = ServerStatus::UNINITIALIZED;
	std::cout << "Server up, UNINITIALIZED. Waiting for /configure..." << std::endl;

	auto addCors = [](httplib::Response& res) {
		res.set_header("Access-Control-Allow-Origin", "*");
	};
	auto preflight = [&](const httplib::Request&, httplib::Response& res) {
		addCors(res);
		res.set_header("Access-Control-Allow-Methods", "POST, GET, OPTIONS");
		res.set_header("Access-Control-Allow-Headers", "Content-Type");
		res.status = 200;
	};


	svr.Get("/status", [&](const httplib::Request&, httplib::Response& res) {
		addCors(res);
		switch (serverStatus.load()) {
		case ServerStatus::UNINITIALIZED:    res.set_content("UNINITIALIZED", "text/plain"); break;
		case ServerStatus::IDLE:             res.set_content("IDLE", "text/plain"); break;
		case ServerStatus::WORKING:          res.set_content("WORKING", "text/plain"); break;
		case ServerStatus::READY:            res.set_content("READY", "text/plain"); break;
		case ServerStatus::TRIGGER_FINISHED: res.set_content("TRIGGER_FINISHED", "text/plain"); break;
		default:                             res.set_content("Unknown server status", "text/plain"); break;
		}
	});

	// /configure: run-independent settings (pixel format + memory capacity).
	// Allowed from UNINITIALIZED (first time) or IDLE (re-configure between runs).
	// The orchestrator must configure the master (this program) before the others.
	svr.Options("/configure", preflight);

	svr.Post("/configure", [&](const httplib::Request& req, httplib::Response& res) {

		std::cout << "\t\t<- Configure request received" << std::endl;

		addCors(res);

		ServerStatus st = serverStatus.load();
		if (st != ServerStatus::UNINITIALIZED && st != ServerStatus::IDLE) {
			res.status = 409;
			res.set_content("Busy; cannot configure now", "text/plain");
			return;
		}

		size_t capacity = 0;
		std::string pixelFormat;
		try {
			auto body_json = nlohmann::json::parse(req.body);

			if (body_json["capacity"].is_string())
				capacity = static_cast<size_t>(std::stoi(body_json["capacity"].get<std::string>()));
			else
				capacity = body_json["capacity"].get<size_t>();

			pixelFormat = normalizePixelFormat(body_json.value("pixelFormat", std::string("RGB8")));
		}
		catch (const std::exception& e) {
			res.status = 400;
			res.set_content(std::string("Bad request: ") + e.what(), "text/plain");
			return;
		}

		if (capacity == 0 || pixelFormat.empty()) {
			res.status = 400;
			res.set_content("capacity must be > 0 and pixelFormat one of RGB8|Mono8", "text/plain");
			return;
		}

		std::cout << "\t\t<- Configuring capacity=" << capacity << " pixelFormat=" << pixelFormat << std::endl;

		serverStatus = ServerStatus::WORKING;
		res.set_content("Configuring...", "text/plain");

		// Configuration is slow (camera open + grab), so run it off the request thread.
		std::thread([&, capacity, pixelFormat]() {
			bool ok = basler.configure(capacity, pixelFormat);
			serverStatus = ok ? ServerStatus::IDLE : ServerStatus::UNINITIALIZED;
		}).detach();
	});

	svr.Options("/start", preflight);

	svr.Post("/start", [&](const httplib::Request& req, httplib::Response& res) {

		std::cout << "\t\t<- Start request received" << std::endl;

		addCors(res);

		if (serverStatus.load() != ServerStatus::IDLE) {
			res.status = 409;
			res.set_content("Not IDLE; configure first", "text/plain");
			return;
		}

		try {
			auto body_json = nlohmann::json::parse(req.body);

			std::string frameCountStr = body_json["frameCount"];
			std::string timestamp = body_json["timestamp"];

			std::cout << "\t\t<- Starting record with frame count: " << frameCountStr << std::endl;
			std::cout << "\t\t<- Starting record with timestamp: " << timestamp << std::endl;

			size_t requested = static_cast<size_t>(std::stoi(frameCountStr));
			if (requested > basler.getCapacity()) {
				res.status = 400;
				res.set_content("frameCount exceeds configured capacity", "text/plain");
				return;
			}

			frameCount = requested;
			basler.setFolderName(timestamp);
			serverStatus = ServerStatus::READY;
		}
		catch (const std::exception& e) {
			res.status = 400;
			res.set_content(std::string("Bad request: ") + e.what(), "text/plain");
			return;
		}

		res.set_content("Starting record...", "text/plain");
	});

	svr.Post("/record", [&](const httplib::Request& req, httplib::Response& res) {

		std::cout << "\t\t<- Record request received" << std::endl;

		if (serverStatus.load() == ServerStatus::READY) {
			std::cout << "\t\t<- Triggering record..." << std::endl;

			serverStatus = ServerStatus::WORKING;

			std::thread([&]() {
				basler.startRecord(frameCount, offset);
				std::this_thread::sleep_for(std::chrono::seconds(1));
				serverStatus = ServerStatus::TRIGGER_FINISHED;
				basler.saveImages(frameCount);
				offset += frameCount;
				std::this_thread::sleep_for(std::chrono::seconds(1));
				serverStatus = ServerStatus::IDLE;
			}).detach();
		}
		else {

		}

		res.set_header("Access-Control-Allow-Origin", "*");
		res.set_content("Starting record...", "text/plain");
	});

	std::cout << "\t\t<- server started..." << std::endl;

	std::thread server_thread([&]() {
		svr.listen("0.0.0.0", 8080);
	});

	while (running) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	std::cout << "\nExiting server..." << std::endl;
	svr.stop();
	server_thread.join();

	return 0;
}