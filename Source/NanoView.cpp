
#include "NanoView.h"
#include "NanoController.h"
#include "NanoModel.h"

#include <windows.h>
#include <string>
#include <shlobj.h>
#include <iostream>
#include <sstream>

#include <nanogui/opengl.h>
#include <nanogui/window.h>
#include <nanogui/layout.h>
#include <nanogui/label.h>
#include <nanogui/checkbox.h>
#include <nanogui/button.h>
#include <nanogui/toolbutton.h>
#include <nanogui/popupbutton.h>
#include <nanogui/combobox.h>
#include <nanogui/progressbar.h>
#include <nanogui/entypo.h>
#include <nanogui/messagedialog.h>
#include <nanogui/textbox.h>
#include <nanogui/slider.h>
#include <nanogui/imagepanel.h>
#include <nanogui/imageview.h>
#include <nanogui/vscrollpanel.h>
#include <nanogui/colorwheel.h>
#include <nanogui/colorpicker.h>
#include <nanogui/graph.h>
#include <nanogui/tabwidget.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using std::cout;
using std::endl;

// ctor
NanoView::NanoView (NanoController * const controller, NanoModel * const model)
	: controller(controller),
	  model(model)
{		
	
}

// createGui
void NanoView::createGui()
{
	using namespace nanogui;

	Window *window = new Window(controller, "");
	window->setPosition(Vector2i(15, 15));
	window->setLayout(new GroupLayout());

	Button * b = new Button(window, "Select Cuda input folder");
	b->setCallback([&] {
		try
		{ 
			std::string path = browseFolder(defaultFolder);
			model->addCudaInputFolder(path);
		}
		catch (std::runtime_error & e)
		{
			LOG_CRIT << e.what();
			auto dlg = new MessageDialog(controller, MessageDialog::Type::Warning, "Fatal error", e.what());
			dlg->setCallback([](int result) { cout << "Dialog result: " << result << endl; });
		}
	});

	b = new Button(window, "Select Ptx output folder");
	b->setCallback([&] {
		try
		{
			std::string path = browseFolder(defaultFolder);
			model->addPtxOutputFolder(path);
		}
		catch (std::runtime_error & e)
		{
			LOG_CRIT << e.what();
			auto dlg = new MessageDialog(controller, MessageDialog::Type::Warning, "Fatal error", e.what());
			dlg->setCallback([](int result) { cout << "Dialog result: " << result << endl; });
		}
	});

	CheckBox *cb = new CheckBox(window, "Create Ptx header",
		[&](bool state) { createHeaders = state; }
	);
	cb->setChecked(true);

	b = new Button(window, "Compile");
	b->setCallback([this] {
		try
		{
			model->compile(createHeaders);
		}
		catch (optix::Exception & e)
		{
			LOG_CRIT << e.getErrorString();
			auto dlg = new MessageDialog(controller, MessageDialog::Type::Warning, "Fatal error", e.getErrorString());
			dlg->setCallback([](int result) { cout << "Dialog result: " << result << endl; });
		}
		catch (std::runtime_error & e)
		{
			LOG_CRIT << e.what();
			auto dlg = new MessageDialog(controller, MessageDialog::Type::Warning, "Fatal error", e.what());
			dlg->setCallback([](int result) { cout << "Dialog result: " << result << endl; });
		}
		catch (...)
		{
			LOG_CRIT << "Caught unknown exception";
			auto dlg = new MessageDialog(controller, MessageDialog::Type::Warning, "Fatal error", "Caught unknown exception");
			dlg->setCallback([](int result) { cout << "Dialog result: " << result << endl; });
		}
	
	});
	b->setTooltip("short tooltip");

	controller->performLayout();
}

// https://stackoverflow.com/questions/12034943/win32-select-directory-dialog-from-c-c
// browseCallbackProc
int CALLBACK  NanoView::browseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	if (uMsg == BFFM_INITIALIZED)
	{
		std::string tmp = (const char *)lpData;
		std::cout << "path: " << tmp << std::endl;
		SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);
	}

	return 0;
}

// https://stackoverflow.com/questions/12034943/win32-select-directory-dialog-from-c-c
// browseFolder
std::string NanoView::browseFolder(std::string saved_path)
{
	TCHAR path[MAX_PATH];

	const char * path_param = saved_path.c_str();

	BROWSEINFO bi = { 0 };
	bi.lpszTitle = ("Browse for folder...");
	bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
	bi.lpfn = &NanoView::browseCallbackProc;
	bi.lParam = (LPARAM)path_param;

	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);

	if (pidl != 0)
	{
		//get the name of the folder and put it in path
		SHGetPathFromIDList(pidl, path);

		//free memory used
		IMalloc * imalloc = 0;
		if (SUCCEEDED(SHGetMalloc(&imalloc)))
		{
			imalloc->Free(pidl);
			imalloc->Release();
		}
		std::cout << "path: " << path << std::endl;
		return path;
	}

	return "";
}