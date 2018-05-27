
#include "NanoApp.h"

// ctor
NanoApp::NanoApp ()
	: view(&controller, &model)
{	
	const std::string logFolder = "C:/Users/Steve/Desktop/";
	nanolog::initialize(nanolog::GuaranteedLogger(), logFolder, "NanoApp", 1); 
}


