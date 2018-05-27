/*
NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
The widget drawing code is based on the NanoVG demo application
by Mikko Mononen.

All rights reserved. Use of this source code is governed by a
BSD-style license that can be found in the LICENSE.txt file.
*/

#pragma once

#include "Standard.h"
#include "nanogui/screen.h"
#include <nanogui/glutil.h>

class NanoController : public nanogui::Screen
{

 public:
	 NanoController();
	 ~NanoController() = default;
		
	virtual bool keyboardEvent(int key, int scancode, int action, int modifiers) override
	{
		if (Screen::keyboardEvent(key, scancode, action, modifiers))
			return true;
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
			setVisible(false);
			return true;
		}
		return false;
	}

	virtual void draw(NVGcontext *ctx) override
	{
		// Draw the user interface 
		Screen::draw(ctx);
	}

	virtual bool dropEvent(const std::vector<std::string> & filenames ) override
	{
		for (auto path : filenames)
		{
			LOG_INFO << path; // FIXME
		}
		return true;
	}

}; // end class NanoController
