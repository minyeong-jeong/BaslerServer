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

			/* Setting the trigger on master camera */

			std::cout << "Attempting to set AreaTriggerMode to Generator." << std::endl;
			Pylon::CEnumParameter areaTriggerMode(tlNodemap, "AreaTriggerMode");

			GenApi::StringList_t values;

			areaTriggerMode.GetSettableValues(values);

			for (size_t i = 0; i < values.size(); ++i) {
				std::cout << "Settable value: " << values[i] << std::endl;
			}
			areaTriggerMode.SetValue("Generator");
			std::cout << "AreaTriggerMode set to: " << areaTriggerMode.GetValue() << std::endl;

			std::cout << "Attempting to set TriggerOutputFrequency to 1.0." << std::endl;
			Pylon::CFloatParameter triggerOutputFrequency(tlNodemap, "TriggerOutputFrequency");
			triggerOutputFrequency.SetValue(24.0);
			std::cout << "TriggerOutputFrequency set to: " << triggerOutputFrequency.GetValue() << std::endl;

			/*
			std::cout << "Attempting to set TriggerOutSelectFrontGPO0 to CamAPulseGenerator0." << std::endl;
			Pylon::CEnumParameter triggerOutSelectFrontGPO0(tlNodemap, "TriggerOutSelectFrontGPO0");
			triggerOutSelectFrontGPO0.SetValue("CamAPulseGenerator0");
			std::cout << "TriggerOutSelectFrontGPO0 set to: " << triggerOutSelectFrontGPO0.GetValue() << std::endl;
			*/

			std::cout << "Attempting to set TriggerState to Active." << std::endl;
			Pylon::CEnumParameter triggerState(tlNodemap, "TriggerState");
			triggerState.SetValue("Active");
			std::cout << "TriggerState set to: " << triggerState.GetValue() << std::endl;

			/* Routing the trigger to the camera */

			Pylon::CEnumParameter cxpLinkTrigger0Source(tlNodemap, "CxpLinkTrigger0Source");
			cxpLinkTrigger0Source.SetValue("PulseGenerator3RisingEdge");
			std::cout << "CxpLinkTrigger0Source set to: " << cxpLinkTrigger0Source.GetValue() << std::endl;


			/* Setting the camera to recieve the trigger */

			Pylon::CEnumParameter frameStart(nodemap, "TriggerSelector");
			frameStart.SetValue("FrameStart");
			std::cout << "TriggerSelector set to: " << frameStart.GetValue() << std::endl;

			Pylon::CEnumParameter triggerMode(nodemap, "TriggerMode");
			triggerMode.SetValue("On");
			std::cout << "TriggerMode set to: " << triggerMode.GetValue() << std::endl;

			Pylon::CEnumParameter triggerSource(nodemap, "TriggerSource");
			triggerSource.SetValue("CxpTrigger0");
			std::cout << "TriggerSource set to: " << triggerSource.GetValue() << std::endl;

			/* Setting camera variables */

			/* Exposure time */
			Pylon::CEnumParameter exposureMode(nodemap, "ExposureMode");
			exposureMode.SetValue("Timed");
			std::cout << "ExposureMode set to: " << exposureMode.GetValue() << std::endl;

			Pylon::CEnumParameter exposureAuto(nodemap, "ExposureAuto");
			exposureAuto.SetValue("Off");
			std::cout << "ExposureAuto set to: " << exposureAuto.GetValue() << std::endl;

			Pylon::CEnumParameter exposureTimeMode(nodemap, "ExposureTimeMode");
			exposureTimeMode.SetValue("Common");
			std::cout << "ExposureTimeMode set to: " << exposureTimeMode.GetValue() << std::endl;

			Pylon::CEnumParameter exposureTimeSelector(nodemap, "ExposureTimeSelector");
			exposureTimeSelector.SetValue("Common");
			std::cout << "ExposureTimeSelector set to: " << exposureTimeSelector.GetValue() << std::endl;

			Pylon::CFloatParameter exposureTime(nodemap, "ExposureTime");
			exposureTime.SetValue(2000.0);
			std::cout << "ExposureTime set to: " << exposureTime.GetValue() << std::endl;

			/* Gain */
			Pylon::CEnumParameter gainAuto(nodemap, "GainAuto");
			gainAuto.SetValue("Off");
			std::cout << "GainAuto set to: " << gainAuto.GetValue() << std::endl;

			Pylon::CEnumParameter gainSelector(nodemap, "GainSelector");
			gainSelector.SetValue("All");
			std::cout << "GainSelector set to: " << gainSelector.GetValue() << std::endl;

			Pylon::CFloatParameter gain(nodemap, "Gain");
			gain.SetValue(0.0);
			std::cout << "Gain set to: " << gain.GetValue() << std::endl;

			/* Image Pattern */
			Pylon::CEnumParameter pixelFormat(nodemap, "PixelFormat");
			pixelFormat.SetValue("Mono8");
			std::cout << "PixelFormat set to: " << pixelFormat.GetValue() << std::endl;

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

			Pylon::CEnumParameter areaTriggerMode(tlNodemap, "AreaTriggerMode");

			GenApi::StringList_t values;

			areaTriggerMode.GetSettableValues(values);

			for (size_t i = 0; i < values.size(); ++i) {
				std::cout << "Settable value: " << values[i] << std::endl;
			}

			areaTriggerMode.SetValue("Synchronized");
			std::cout << "AreaTriggerMode set to: " << areaTriggerMode.GetValue() << std::endl;

			/*
			std::cout << "Attempting to set TriggerOutputFrequency to 1.0." << std::endl;
			Pylon::CFloatParameter triggerOutputFrequency(tlNodemap, "TriggerOutputFrequency");
			triggerOutputFrequency.SetValue(2.0);
			std::cout << "TriggerOutputFrequency set to: " << triggerOutputFrequency.GetValue() << std::endl;
			*/

			std::cout << "Attempting to set TriggerState to Active." << std::endl;
			Pylon::CEnumParameter triggerState(tlNodemap, "TriggerState");
			triggerState.SetValue("Active");
			std::cout << "TriggerState set to: " << triggerState.GetValue() << std::endl;

			Pylon::CEnumParameter cxpLinkTrigger0Source(tlNodemap, "CxpLinkTrigger0Source");
			cxpLinkTrigger0Source.SetValue("CamBPulseGenerator0RisingEdge");
			std::cout << "CxpLinkTrigger0Source set to: " << cxpLinkTrigger0Source.GetValue() << std::endl;

			Pylon::CEnumParameter frameStart(nodemap, "TriggerSelector");
			frameStart.SetValue("FrameStart");
			std::cout << "TriggerSelector set to: " << frameStart.GetValue() << std::endl;

			Pylon::CEnumParameter triggerMode(nodemap, "TriggerMode");
			triggerMode.SetValue("On");
			std::cout << "TriggerMode set to: " << triggerMode.GetValue() << std::endl;

			Pylon::CEnumParameter triggerSource(nodemap, "TriggerSource");
			triggerSource.SetValue("CxpTrigger0");
			std::cout << "TriggerSource set to: " << triggerSource.GetValue() << std::endl;


			/* Setting camera variables */

			/* Exposure time */
			Pylon::CEnumParameter exposureMode(nodemap, "ExposureMode");
			exposureMode.SetValue("Timed");
			std::cout << "ExposureMode set to: " << exposureMode.GetValue() << std::endl;

			Pylon::CEnumParameter exposureAuto(nodemap, "ExposureAuto");
			exposureAuto.SetValue("Off");
			std::cout << "ExposureAuto set to: " << exposureAuto.GetValue() << std::endl;

			Pylon::CEnumParameter exposureTimeMode(nodemap, "ExposureTimeMode");
			exposureTimeMode.SetValue("Common");
			std::cout << "ExposureTimeMode set to: " << exposureTimeMode.GetValue() << std::endl;

			Pylon::CEnumParameter exposureTimeSelector(nodemap, "ExposureTimeSelector");
			exposureTimeSelector.SetValue("Common");
			std::cout << "ExposureTimeSelector set to: " << exposureTimeSelector.GetValue() << std::endl;

			Pylon::CFloatParameter exposureTime(nodemap, "ExposureTime");
			exposureTime.SetValue(2000.0);
			std::cout << "ExposureTime set to: " << exposureTime.GetValue() << std::endl;

			/* Gain */
			Pylon::CEnumParameter gainAuto(nodemap, "GainAuto");
			gainAuto.SetValue("Off");
			std::cout << "GainAuto set to: " << gainAuto.GetValue() << std::endl;

			Pylon::CEnumParameter gainSelector(nodemap, "GainSelector");
			gainSelector.SetValue("All");
			std::cout << "GainSelector set to: " << gainSelector.GetValue() << std::endl;

			Pylon::CFloatParameter gain(nodemap, "Gain");
			gain.SetValue(0.0);
			std::cout << "Gain set to: " << gain.GetValue() << std::endl;

			/* Image Pattern */
			Pylon::CEnumParameter pixelFormat(nodemap, "PixelFormat");
			pixelFormat.SetValue("Mono8");
			std::cout << "PixelFormat set to: " << pixelFormat.GetValue() << std::endl;
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

			intptr_t imageNumber = ptrGrabResult->GetImageNumber();

			Pylon::CPylonImage image;
			image.AttachGrabResultBuffer(ptrGrabResult);

			std::string imageName = 
				"D:\\test\\camera_" 
				+ std::to_string(imageNumber)
				+ "_"
				+ std::to_string(cameraContextValue) 
				+ ".bmp";
			image.Save(Pylon::ImageFileFormat_Bmp, Pylon::String_t(imageName.c_str()));
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
		size_t CAMERA_COUNT = 4;

		Pylon::CTlFactory& tlFactory = Pylon::CTlFactory::GetInstance();

		Pylon::DeviceInfoList_t devices;
		if (tlFactory.EnumerateDevices(devices) == 0) {
			std::cerr << "No cameras found." << std::endl;
			return 1;
		}

		Pylon::CInstantCameraArray cameras(CAMERA_COUNT);

		for (size_t i = 0; i < CAMERA_COUNT; ++i) {
			cameras[i].Attach(tlFactory.CreateDevice(devices[i]));
		}

		cameras[3].RegisterConfiguration(new CMasterCardMasterCameraConfiguration, Pylon::RegistrationMode_Append, Pylon::Cleanup_Delete);
		cameras[3].RegisterImageEventHandler(new CImageEventPrinter, Pylon::RegistrationMode_ReplaceAll, Pylon::Cleanup_Delete);

		for (size_t i = 0; i < CAMERA_COUNT-1; ++i) {
			cameras[i].RegisterConfiguration(new CMasterCardSlaveCameraConfiguration, Pylon::RegistrationMode_Append, Pylon::Cleanup_Delete);
			cameras[i].RegisterImageEventHandler(new CImageEventPrinter, Pylon::RegistrationMode_ReplaceAll, Pylon::Cleanup_Delete);
		}

		for (size_t i = 0; i < CAMERA_COUNT; ++i) {
			cameras[i].GrabCameraEvents = true;
			cameras[i].MaxNumBuffer = 500;
			// cameras[i].Open();
			// cameras[i].StartGrabbing(50);
		}

		cameras.StartGrabbing();


		Pylon::CGrabResultPtr ptrGrabResult;

		while (cameras.IsGrabbing()) {
			cameras.RetrieveResult(5000, ptrGrabResult, Pylon::TimeoutHandling_ThrowException);
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