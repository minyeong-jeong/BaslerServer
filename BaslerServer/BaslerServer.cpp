#include <iostream>

#include <pylon/PylonIncludes.h>
#ifdef PYLON_WIN_BUILD
#    include <pylon/PylonGUI.h>
#endif

namespace Pylon {
    class CInstantCamera;
}
class CMasterCardMasterCameraConfiguration : public Pylon::CConfigurationEventHandler {
public:
    void OnOpened(Pylon::CInstantCamera& camera) {
        try {

			GenApi::INodeMap& nodemap = camera.GetNodeMap();
			GenApi::INodeMap& tlNodemap = camera.GetTLNodeMap();

			std::cout << "Attempting to set AreaTriggerMode to Generator." << std::endl;
			Pylon::CEnumParameter areaTriggerMode(tlNodemap, "AreaTriggerMode");
			std::cout << "Writable: " << areaTriggerMode.IsWritable() << std::endl;
			areaTriggerMode.SetValue("Generator");
			std::cout << "AreaTriggerMode set to: " << areaTriggerMode.GetValue() << std::endl;

			std::cout << "Attempting to set TriggerOutputFrequency to 1.0." << std::endl;
			Pylon::CFloatParameter triggerOutputFrequency(tlNodemap, "TriggerOutputFrequency");
			triggerOutputFrequency.SetValue(1.0);
			std::cout << "TriggerOutputFrequency set to: " << triggerOutputFrequency.GetValue() << std::endl;

			std::cout << "Attempting to set TriggerOutSelectFrontGPO0 to CamAPulseGenerator0." << std::endl;
			Pylon::CEnumParameter triggerOutSelectFrontGPO0(tlNodemap, "TriggerOutSelectFrontGPO0");
			triggerOutSelectFrontGPO0.SetValue("CamAPulseGenerator0");
			std::cout << "TriggerOutSelectFrontGPO0 set to: " << triggerOutSelectFrontGPO0.GetValue() << std::endl;

			std::cout << "Attempting to set TriggerState to Active." << std::endl;
			Pylon::CEnumParameter triggerState(tlNodemap, "TriggerState");
			triggerState.SetValue("Active");
			std::cout << "TriggerState set to: " << triggerState.GetValue() << std::endl;

			std::cout << "Attempting to set CxpLinkTrigger0Source to PulseGenerator0RisingEdge." << std::endl;
			Pylon::CEnumParameter cxpLinkTrigger0Source(tlNodemap, "CxpLinkTrigger0Source");
			cxpLinkTrigger0Source.SetValue("PulseGeneratorRisingEdge");
			std::cout << "CxpLinkTrigger0Source set to: " << cxpLinkTrigger0Source.GetValue() << std::endl;

			std::cout << "Attempting to set TriggerSelector to FrameStart." << std::endl;
			Pylon::CEnumParameter frameStart(nodemap, "TriggerSelector");
			frameStart.SetValue("FrameStart");
			std::cout << "TriggerSelector set to: " << frameStart.GetValue() << std::endl;

			std::cout << "Attempting to set TriggerMode to On." << std::endl;
			Pylon::CEnumParameter triggerMode(nodemap, "TriggerMode");
			triggerMode.SetValue("On");
			std::cout << "TriggerMode set to: " << triggerMode.GetValue() << std::endl;

			std::cout << "Attempting to set TriggerSource to CXPTrigger0." << std::endl;
			Pylon::CEnumParameter triggerSource(nodemap, "TriggerSource");
			triggerSource.SetValue("CxpTrigger0");
			std::cout << "TriggerSource set to: " << triggerSource.GetValue() << std::endl;


        }
        catch (const Pylon::GenericException& e) {
            throw RUNTIME_EXCEPTION("Could not apply configuration. const GenericExecption caught in OnOpened method ms=%hs", e.what());
        }
    }
};
class CMasterCardSlaveCameraConfiguration : public Pylon::CConfigurationEventHandler {
public:
    void OnOpened(Pylon::CInstantCamera& camera) {
        try {

			GenApi::INodeMap& nodemap = camera.GetNodeMap();
			GenApi::INodeMap& tlNodemap = camera.GetTLNodeMap();

			std::cout << "Attempting to set TriggerState to Active." << std::endl;
			Pylon::CEnumParameter triggerState(tlNodemap, "TriggerState");
			triggerState.SetValue("Active");
			std::cout << "TriggerState set to: " << triggerState.GetValue() << std::endl;

			std::cout << "Attempting to set CxpLinkTrigger0Source to PulseGenerator0RisingEdge." << std::endl;
			Pylon::CEnumParameter cxpLinkTrigger0Source(tlNodemap, "CxpLinkTrigger0Source");
			cxpLinkTrigger0Source.SetValue("PulseGeneratorRisingEdge");
			std::cout << "CxpLinkTrigger0Source set to: " << cxpLinkTrigger0Source.GetValue() << std::endl;

			std::cout << "Attempting to set TriggerSelector to FrameStart." << std::endl;
			Pylon::CEnumParameter frameStart(nodemap, "TriggerSelector");
			frameStart.SetValue("FrameStart");
			std::cout << "TriggerSelector set to: " << frameStart.GetValue() << std::endl;

			std::cout << "Attempting to set TriggerMode to On." << std::endl;
			Pylon::CEnumParameter triggerMode(nodemap, "TriggerMode");
			triggerMode.SetValue("On");
			std::cout << "TriggerMode set to: " << triggerMode.GetValue() << std::endl;

			std::cout << "Attempting to set TriggerSource to CXPTrigger0." << std::endl;
			Pylon::CEnumParameter triggerSource(nodemap, "TriggerSource");
			triggerSource.SetValue("CxpTrigger0");
			std::cout << "TriggerSource set to: " << triggerSource.GetValue() << std::endl;

        }
        catch (const Pylon::GenericException& e) {
            throw RUNTIME_EXCEPTION("Could not apply configuration. const GenericExecption caught in OnOpened method ms=%hs", e.what());
        }
    }
};


class CImageEventPrinter : public Pylon::CImageEventHandler
{
public:

	virtual void OnImageGrabbed(Pylon::CInstantCamera& camera, const Pylon::CGrabResultPtr& ptrGrabResult)
	{
		std::cout << "OnImageGrabbed event for device " << camera.GetDeviceInfo().GetModelName() << std::endl;

		// Image grabbed successfully?
		if (ptrGrabResult->GrabSucceeded())
		{
			intptr_t cameraContextValue = ptrGrabResult->GetCameraContext();
			std::cout << cameraContextValue << " ";
		}
		else
		{
			std::cout << "Error: " << std::hex << ptrGrabResult->GetErrorCode() << std::dec << " " << ptrGrabResult->GetErrorDescription() << std::endl;
		}
	}
};

int main(int /*argc*/, char* /*argv*/[])
{
    // The exit code of the sample application.
    int exitCode = 0;

    // Before using any pylon methods, the pylon runtime must be initialized.
    Pylon::PylonInitialize();

    try
    {
		Pylon::CTlFactory& tlFactory = Pylon::CTlFactory::GetInstance();

		Pylon::DeviceInfoList_t devices;

		Pylon::CInstantCamera camera(Pylon::CTlFactory::GetInstance().CreateFirstDevice());

		camera.RegisterConfiguration(new CMasterCardMasterCameraConfiguration, Pylon::RegistrationMode_Append, Pylon::Cleanup_Delete);
		camera.RegisterImageEventHandler(new CImageEventPrinter, Pylon::RegistrationMode_ReplaceAll, Pylon::Cleanup_Delete);

		camera.GrabCameraEvents = true;

		camera.Open();

		camera.StartGrabbing(50);

		Pylon::CGrabResultPtr ptrGrabResult;

		while (camera.IsGrabbing()) {
			camera.RetrieveResult(5000, ptrGrabResult, Pylon::TimeoutHandling_ThrowException);
		}

    }
    catch (const Pylon::GenericException& e)
    {
        // Error handling.
        std::cerr << "An exception occurred." << std::endl
            << e.GetDescription() << std::endl;
        exitCode = 1;
    }

    // Comment the following two lines to disable waiting on exit.
    std::cerr << std::endl << "Press enter to exit." << std::endl;
    while (std::cin.get() != '\n');

    // Releases all pylon resources.
    Pylon::PylonTerminate();

    return exitCode;
}