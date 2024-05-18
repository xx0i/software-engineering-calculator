#include "ButtonFactory.h"

ButtonFactory* ButtonFactory::instance = 0;

ButtonFactory* ButtonFactory::getInstance() //getInstance -> if instancePtr is 0 creates an instance and returns otherwise just returns instance
{
	if (instance == 0) {
		instance = new ButtonFactory(); //memory for instance cleaned/deleted in app destructor, since that is where the calculator runs from
	}
		return instance;
}

//not used in my code but can be considered like a default constructor to create any kind of button by requiring everything to be passed
wxButton* ButtonFactory::createGeneralButton(wxButton* button, wxWindow* Parent, int idNum, std::string label, int xPoint, int yPoint, int xSize, int ySize)
{
	button = new wxButton(Parent, idNum, label, wxPoint(xPoint, yPoint), wxSize(xSize, ySize));
	return button;
}

wxButton* ButtonFactory::createButton(wxButton* button, wxWindow* Parent, std::string label, int row, int col) //createButton -> with necessary parameters
{
	button = new wxButton(Parent, wxID_ANY, label, wxPoint(startX + col * spaceX, startY + row * spaceY), wxSize(buttonWidth, buttonHeight));
	return button;
}
