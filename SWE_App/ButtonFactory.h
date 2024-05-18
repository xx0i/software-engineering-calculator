#pragma once
#include "Window.h"
#include <string>
#include "wx/wx.h"

class ButtonFactory
{
private:
	//ints + vectors used in button initialization
static const int buttonWidth = 40;
static const int buttonHeight = 40;
static const int startX = 20;
static const int startY = 200;
static const int spaceX = 60;
static const int spaceY = 54;
ButtonFactory() {} //default constructor

public:
	static ButtonFactory* instance; //static pointer to manage singleton behaviour [wether or an instance has already been created or not
	static ButtonFactory* getInstance(); //static getInstance method -> how the class is initialized
	static wxButton* createGeneralButton(wxButton* button, wxWindow* Parent, int idNum, std::string label, int xPoint, int yPoint, int xSize, int ySize); //createGeneralButton -> requires everything to be passed as parameters (not used in my code but similar to a default constructor)
	static wxButton* createButton(wxButton* button, wxWindow* Parent, std::string Label, int col, int row); //createButton -> parameters based on what's needed to initialize a button
};