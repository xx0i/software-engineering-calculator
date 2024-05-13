#pragma once
#include "wx/wx.h"
#include "ButtonFactory.h"

class Window; //forward calling Window class

class App : public wxApp //class app deriving from wxApp
{
	Window* window = nullptr; //window ptr
public:
	App() {}
	~App() { delete ButtonFactory::instance; } //deletes ButtonFactory::instance 
	virtual bool OnInit(); //virtual bool
};