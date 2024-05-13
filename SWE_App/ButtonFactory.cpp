#include "ButtonFactory.h"

ButtonFactory* ButtonFactory::instance = 0;

ButtonFactory* ButtonFactory::getInstance() //getInstance -> if instancePtr is 0 creates an instance and returns otherwise just returns instance
{
	if (instance == 0) {
		instance = new ButtonFactory(); //memory for instance cleaned/deleted in app destructor, since that is where the calculator runs from
	}
		return instance;
}

void ButtonFactory::createButton(wxButton* button, Window* Parent, int idNum, std::string label, int row, int col) //createButton -> with necessary parameters
{
	button = new wxButton(Parent, idNum, label, wxPoint(startX + col * spaceX, startY + row * spaceY), wxSize(buttonWidth, buttonHeight));
}
