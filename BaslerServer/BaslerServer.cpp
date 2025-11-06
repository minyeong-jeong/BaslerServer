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

#include "httplib.h"
#include "json.hpp"

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
			pixelFormat.SetValue("Mono8");
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
			pixelFormat.SetValue("Mono8");
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
	size_t frameCount;
	Pylon::CInstantCameraArray* cameras;
	GenApi::INodeMap* tlNodemap;
	Pylon::CEnumParameter* triggerState;
	const size_t cameraCount = 4;
	std::string folderName;

	std::vector<std::vector<Pylon::CGrabResultPtr>> grabResultVector;

public:
	BaslerServer()
		: frameCount(0)
		, cameras(nullptr)
		, tlNodemap(nullptr)
		, triggerState(nullptr)
		, folderName("")
	{
	}

	void setFolderName(std::string folderName) {
		this->folderName = "E:\\" + folderName;
	}

	void test() {}

	void initialize(int frame_count) {

		std::cout << "frame num: " << frame_count << std::endl;

		this->frameCount = frame_count;



		bool init_done = false;

		while (!init_done) {

			std::cout << "Try" << std::endl;

			try {

				// Before using any pylon methods, the pylon runtime must be initialized.
				Pylon::PylonInitialize();

				Pylon::CTlFactory& tlFactory = Pylon::CTlFactory::GetInstance();

				Pylon::DeviceInfoList_t devices;
				if (tlFactory.EnumerateDevices(devices) == 0) {
					std::cerr << "No cameras found." << std::endl;
				}

				Pylon::DeviceInfoList_t::const_iterator it;

				for (it = devices.begin(); it != devices.end(); ++it) {
					std::cout << "Camera found:\t" << it->GetFullName() << std::endl;
					std::cout << "\t\t" << it->GetDeviceID() << std::endl;
					std::cout << "\t\t" << it->GetInterfaceID() << std::endl;
				}

				cameras = new Pylon::CInstantCameraArray(this->cameraCount);

				for (size_t i = 0; i < this->cameraCount; ++i) {
					(*cameras)[i].Attach(tlFactory.CreateDevice(devices[i]));
				}

				(*cameras)[3].RegisterConfiguration(new CMasterCardMasterCameraConfiguration, Pylon::RegistrationMode_Append, Pylon::Cleanup_Delete);

				for (size_t i = 0; i < this->cameraCount - 1; ++i) {
					(*cameras)[i].RegisterConfiguration(new CMasterCardSlaveCameraConfiguration, Pylon::RegistrationMode_Append, Pylon::Cleanup_Delete);
				}

				for (size_t i = 0; i < this->cameraCount; ++i) {
					(*cameras)[i].MaxNumBuffer = frame_count;
				}

				std::cout << "Start grabbing" << std::endl;

				(*cameras).StartGrabbing();

				std::cout << "finsihed exec start grabbing" << std::endl;

				for (size_t i = 0; i < this->cameraCount; ++i) {
					GenApi::INodeMap& tlNodemap = (*cameras)[i].GetTLNodeMap();
					Pylon::CCommandParameter countClear(tlNodemap, "TriggerOutStatisticsPulseCountClear");
					countClear.Execute();
					std::cout << "Count Clear Executed: " << countClear.IsDone() << std::endl;
				}


				init_done = true;

			}
			catch (const Pylon::GenericException& e) {
				// Error handling.
				std::cerr << "An exception occurred." << std::endl
					<< e.GetDescription() << std::endl;
				Pylon::PylonTerminate();
				std::cout << init_done << std::endl;
			}
			catch (...) {
				std::cerr << "An unknown exception occurred." << std::endl;
				Pylon::PylonTerminate();
				std::cout << init_done << std::endl;
			}

			std::cout << "what???" << std::endl;

		}

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
			// Error handling.
			std::cerr << "An exception occurred." << std::endl
				<< e.GetDescription() << std::endl;
			Pylon::PylonTerminate();
		}
		catch (...) {
			std::cerr << "An unknown exception occurred." << std::endl;
			Pylon::PylonTerminate();
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
			// Error handling.
			std::cerr << "An exception occurred." << std::endl
				<< e.GetDescription() << std::endl;
			Pylon::PylonTerminate();
		}
		catch (...) {
			std::cerr << "An unknown exception occurred." << std::endl;
			Pylon::PylonTerminate();
		}



	}

	~BaslerServer() {

		// Releases all pylon resources.
		Pylon::PylonTerminate();

	}
};

enum class ServerStatus {
	IDLE,
	TRIGGER_FINISHED,
	WORKING,
	READY
};

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

	serverStatus = ServerStatus::WORKING;

	std::cout << "Starting server..." << std::endl;

	basler.initialize(7);
	serverStatus = ServerStatus::IDLE;

	std::cout << "Server ready..." << std::endl;


	svr.Get("/status", [&](const httplib::Request&, httplib::Response& res) {

		std::cout << "\t\t<- Status request received" << std::endl;

		res.set_header("Access-Control-Allow-Origin", "*");
		if (serverStatus.load() == ServerStatus::IDLE) {
			res.set_content("IDLE", "text/plain");
		}
		else if (serverStatus.load() == ServerStatus::WORKING) {
			res.set_content("WORKING", "text/plain");
		}
		else if (serverStatus.load() == ServerStatus::READY) {
			res.set_content("READY", "text/plain");
		}
		else if (serverStatus.load() == ServerStatus::TRIGGER_FINISHED) {
			res.set_content("TRIGGER_FINISHED", "text/plain");
		}
		else {
			res.set_content("Unknown server status", "text/plain");
		}
	});

	svr.Options("/start", [](const httplib::Request&, httplib::Response& res) {
		res.set_header("Access-Control-Allow-Origin", "*");
		res.set_header("Access-Control-Allow-Methods", "POST, GET, OPTIONS");
		res.set_header("Access-Control-Allow-Headers", "Content-Type");
		res.status = 200;
	});

	svr.Post("/start", [&](const httplib::Request& req, httplib::Response& res) {

		std::cout << "\t\t<- Start request received" << std::endl;

		res.set_header("Access-Control-Allow-Origin", "*");

		if (serverStatus.load() == ServerStatus::IDLE) {

			auto body_json = nlohmann::json::parse(req.body);

			std::string frameCountStr = body_json["frameCount"];
			std::string timestamp = body_json["timestamp"];

			std::cout << "\t\t<- Starting record with frame count: " << frameCountStr << std::endl;
			std::cout << "\t\t<- Starting record with timestamp count: " << timestamp << std::endl;

			frameCount = std::stoi(frameCountStr);

			basler.setFolderName(timestamp);
			serverStatus = ServerStatus::READY;

		}
		else {

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