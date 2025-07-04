#include <iostream>

#include <pylon/PylonIncludes.h>
#ifdef PYLON_WIN_BUILD
#    include <pylon/PylonGUI.h>
#endif

namespace Pylon {
    class CInstantCamera;
}
class C4DConfiguration : public Pylon::CConfigurationEventHandler {
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

int main(int /*argc*/, char* /*argv*/[])
{
    // The exit code of the sample application.
    int exitCode = 0;

    // Before using any pylon methods, the pylon runtime must be initialized.
    Pylon::PylonInitialize();

    try
    {
        // Create an instant camera object with the camera device found first.
        Pylon::CInstantCamera camera(Pylon::CTlFactory::GetInstance().CreateFirstDevice());

        camera.RegisterConfiguration(new C4DConfiguration, Pylon::RegistrationMode_Append, Pylon::Cleanup_Delete);

        camera.Open();

        // Print the model name of the camera.
        std::cout << "Using device: " << camera.GetDeviceInfo().GetModelName() << std::endl << std::endl;

        // GenApi::INodeMap& nodemap = camera.GetNodeMap();
        // GenApi::INodeMap& tlNodemap = camera.GetTLNodeMap();

        /*
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
        */

        /* =============================== */
        camera.StartGrabbing(10);

        /*
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
        */

        

        Pylon::CGrabResultPtr ptrGrabResult;

        while (camera.IsGrabbing()) {
            camera.RetrieveResult(5000, ptrGrabResult, Pylon::TimeoutHandling_ThrowException);

            if (ptrGrabResult->GrabSucceeded()) {
                std::cout << "Image grabbed successfully." << std::endl;
                std::cout << "SizeX: " << ptrGrabResult->GetWidth() << std::endl;
                std::cout << "SizeY: " << ptrGrabResult->GetHeight() << std::endl;
                const uint8_t* pImageBuffer = (uint8_t*)ptrGrabResult->GetBuffer();
                std::cout << "Gray value of first pixel: " << (uint32_t)pImageBuffer[0] << std::endl;

                Pylon::DisplayImage(1, ptrGrabResult);
            }
            else {
                std::cerr << "Error: " << ptrGrabResult->GetErrorDescription() << std::endl;
            }
        }


        /*
        GenApi::StringList_t values;

        triggerSource.GetSettableValues(values);

        for (size_t i = 0; i < values.size(); ++i) {
            std::cout << "Settable value: " << values[i] << std::endl;
		}
        */

        camera.Close();

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