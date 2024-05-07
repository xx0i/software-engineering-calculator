#pragma once
#include "wx/wx.h"

class Window; //forward calling Window class

class App : public wxApp //class app deriving from wxApp
{
	Window* window = nullptr; //window ptr
public:
	virtual bool OnInit(); //virtual bool
};