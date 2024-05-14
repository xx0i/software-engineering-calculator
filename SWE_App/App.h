#pragma once
#include "wx/wx.h"
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"

class Window; //forward calling Window class

class App : public wxApp //class app deriving from wxApp
{
	Window* window = nullptr; //window ptr
public:
	App() {}
	~App() { delete ButtonFactory::instance; delete CalculatorProcessor::instance; } //deletes the instances used in the singleton classes
	virtual bool OnInit(); //virtual bool
};