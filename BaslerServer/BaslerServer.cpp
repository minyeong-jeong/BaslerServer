#include <iostream>
#include <conio.h>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <direct.h>
#include <thread>
#include <chrono>
#include <vector>

#include <pylon/PylonIncludes.h>
#include <pylon/PylonGUI.h>


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

			Pylon::CEnumParameter areaTriggerMode(tlNodemap, "AreaTriggerMode");
			areaTriggerMode.SetValue("Generator");
			std::cout << "AreaTriggerMode set to: " << areaTriggerMode.GetValue() << std::endl;

			Pylon::CFloatParameter triggerOutputFrequency(tlNodemap, "TriggerOutputFrequency");
			triggerOutputFrequency.SetValue(24.0);
			std::cout << "TriggerOutputFrequency set to: " << triggerOutputFrequency.GetValue() << std::endl;


			/* Routing the trigger to GPO */

			Pylon::CEnumParameter triggerOutSelectFrontGPO0(tlNodemap, "TriggerOutSelectFrontGPO0");
			triggerOutSelectFrontGPO0.SetValue("PulseGenerator0");
			std::cout << "TriggerOutSelectFrontGPO0 set to: " << triggerOutSelectFrontGPO0.GetValue() << std::endl;


			/* Routing the trigger to the camera */

			Pylon::CEnumParameter cxpLinkTrigger0Source(tlNodemap, "CxpLinkTrigger0Source");
			cxpLinkTrigger0Source.SetValue("PulseGeneratorRisingEdge");
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


			/* Setting the trigger on slave camera */

			Pylon::CEnumParameter areaTriggerMode(tlNodemap, "AreaTriggerMode");
			areaTriggerMode.SetValue("Synchronized");
			std::cout << "AreaTriggerMode set to: " << areaTriggerMode.GetValue() << std::endl;

			Pylon::CFloatParameter triggerOutputFrequency(tlNodemap, "TriggerOutputFrequency");
			triggerOutputFrequency.SetValue(35.0);
			std::cout << "TriggerOutputFrequency set to: " << triggerOutputFrequency.GetValue() << std::endl;



			/* Routing the trigger to the camera */

			Pylon::CEnumParameter cxpLinkTrigger0Source(tlNodemap, "CxpLinkTrigger0Source");
			cxpLinkTrigger0Source.SetValue("CamBPulseGenerator0RisingEdge");
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


			/* Slaves are activated early */

			Pylon::CEnumParameter triggerState(tlNodemap, "TriggerState");
			triggerState.SetValue("Active");
			std::cout << "TriggerState set to: " << triggerState.GetValue() << std::endl;

        }
        catch (const Pylon::GenericException& e) {
            throw RUNTIME_EXCEPTION("Could not apply configuration. const GenericExecption caught in OnOpened method ms=%hs", e.what());
        }
    }
};

class BaslerServer {
private:
	size_t frameCount;
	Pylon::CInstantCameraArray* cameras;
	GenApi::INodeMap* tlNodemap;
	Pylon::CEnumParameter* triggerState;
	const size_t cameraCount = 4;
	std::string folderName;

public:
	BaslerServer(int frame_count)
		: frameCount(0)
		, cameras(nullptr)
		, tlNodemap(nullptr)
		, triggerState(nullptr) 
		, folderName("")
	{

		this->frameCount = frame_count;

		/* Generate folder for images */

		std::time_t t = std::time(nullptr);
		std::tm now;
		localtime_s(&now, &t);

		std::ostringstream oss;
		oss << std::put_time(&now, "D:\\%Y_%m%d_%H%M");

		this->folderName = oss.str();

		if (_mkdir(this->folderName.c_str()) != 0) {
			std::cerr << "Folder already exists" << std::endl;
		}

		// Before using any pylon methods, the pylon runtime must be initialized.
		Pylon::PylonInitialize();

		Pylon::CTlFactory& tlFactory = Pylon::CTlFactory::GetInstance();

		Pylon::DeviceInfoList_t devices;
		if (tlFactory.EnumerateDevices(devices) == 0) {
			std::cerr << "No cameras found." << std::endl;
			return;
		}

		cameras = new Pylon::CInstantCameraArray(this->cameraCount);

		for (size_t i = 0; i < this->cameraCount; ++i) {
			(*cameras)[i].Attach(tlFactory.CreateDevice(devices[i]));
		}

		(*cameras)[3].RegisterConfiguration(new CMasterCardMasterCameraConfiguration, Pylon::RegistrationMode_Append, Pylon::Cleanup_Delete);

		for (size_t i = 0; i < this->cameraCount-1; ++i) {
			(*cameras)[i].RegisterConfiguration(new CMasterCardSlaveCameraConfiguration, Pylon::RegistrationMode_Append, Pylon::Cleanup_Delete);
		}

		for (size_t i = 0; i < this->cameraCount; ++i) {
			(*cameras)[i].MaxNumBuffer = frame_count;
		}

		(*cameras).Open();

		this->tlNodemap = &(*cameras)[3].GetTLNodeMap();

		// For debug purposes
		Pylon::CCommandParameter countClear((*(this->tlNodemap)), "TriggerOutStatisticsPulseCountClear");
		countClear.Execute();
		std::cout << "Count Clear Executed: " << countClear.IsDone() << std::endl;

		this->triggerState = new Pylon::CEnumParameter((*(this->tlNodemap)), "TriggerState");
	}

	void startRecord() {

		std::vector<std::vector<Pylon::CGrabResultPtr>> grabResultVector(4, std::vector<Pylon::CGrabResultPtr>(this->frameCount));

		Pylon::CGrabResultPtr ptrGrabResult;

		(*cameras).StartGrabbing();

		this->triggerState->SetValue("Active");

		// Main grabbing loop
		for (size_t i = 0; i < this->frameCount * 4 && this->cameras->IsGrabbing(); ++i) {
			this->cameras->RetrieveResult(5000, ptrGrabResult, Pylon::TimeoutHandling_Return);
			std::cout << "grabbing image..." << std::endl;

			if (ptrGrabResult->GrabSucceeded()) {
				intptr_t cameraContextValue = ptrGrabResult->GetCameraContext();
				intptr_t imageNumber = ptrGrabResult->GetImageNumber();
				std::cout << "Image grabbed successfully from camera " << cameraContextValue << ", image number: " << imageNumber << std::endl;
				grabResultVector[cameraContextValue][imageNumber - 1] = ptrGrabResult;
			}
			else {
				std::cout << "Error: " << std::hex << ptrGrabResult->GetErrorCode() << std::dec << " " << ptrGrabResult->GetErrorDescription() << std::endl;
			}
		}

		this->triggerState->SetValue("SyncStop");

		// For debug purposes
		Pylon::CIntegerParameter triggerOutStatisticsPulseCount((*(this->tlNodemap)), "TriggerOutStatisticsPulseCount");
		std::cout << "TriggerOutStatisticsPulseCount: " << triggerOutStatisticsPulseCount.GetValue() << std::endl;

		// Turn trigger mode to off to let liveview easier on basler pylon viewer
		for (size_t i = 0; i < this->cameraCount; ++i) {
			GenApi::INodeMap& nodemap = (*(this->cameras))[i].GetNodeMap();
			Pylon::CEnumParameter triggerMode(nodemap, "TriggerMode");
			triggerMode.SetValue("Off");
			std::cout << "TriggerMode set to: " << triggerMode.GetValue() << std::endl;
		}

		this->cameras->StopGrabbing();

		// save images
		for (size_t i = 0; i < this->frameCount; ++i) {
			for (size_t cam = 0; cam < this->cameraCount; ++cam) {

				std::cout << "Saving " << cam << " of frame " << i << std::endl;

				Pylon::CPylonImage image;

				image.AttachGrabResultBuffer(grabResultVector[cam][i]);

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

	~BaslerServer() {

		// Releases all pylon resources.
		Pylon::PylonTerminate();

	}
};

int main(int /*argc*/, char* /*argv*/[])
{
	BaslerServer server(10);
	std::cin.get();
	server.startRecord();

	return 0;
}