#pragma once
#include "wx/wx.h"

class Window : public wxFrame //windows class deriving from wxFrame
{
	wxDECLARE_EVENT_TABLE(); //event table declaration

private:
	~Window(){}
	//BUTTONS
	//text control
	wxTextCtrl* textBox = nullptr;
	//numbers 0-9
	wxButton* zero = nullptr;
	wxButton* one = nullptr;
	wxButton* two = nullptr;
	wxButton* three = nullptr;
	wxButton* four = nullptr;
	wxButton* five = nullptr;
	wxButton* six = nullptr;
	wxButton* seven = nullptr;
	wxButton* eight = nullptr;
	wxButton* nine = nullptr;
	//binary operators
	wxButton* addition = nullptr;
	wxButton* subtraction = nullptr;
	wxButton* multiplication = nullptr;
	wxButton* division = nullptr;
	wxButton* modulo = nullptr;
	//unary operators
	wxButton* sin = nullptr;
	wxButton* cos = nullptr;
	wxButton* tan = nullptr;
	//equals
	wxButton* equals = nullptr;
	//clear
	wxButton* clear = nullptr;
	//backspace
	wxButton* del = nullptr;
	//decimal
	wxButton* decimal = nullptr;
	//negative
	wxButton* negative = nullptr;
	//x^2 (adding extra to make buttons even)
	wxButton* squared = nullptr;

	//vectors used in button initialization
	std::vector<std::vector<std::string>> buttonLabels;
	std::vector<std::vector<int>> buttonIds;
	std::vector<std::vector<wxButton*>> buttons;
	
	//EVENTS
	void zeroEvent(wxCommandEvent&); //zero event
	void oneEvent(wxCommandEvent&); //one event
	void twoEvent(wxCommandEvent&); //two event
	void threeEvent(wxCommandEvent&); //three event
	void fourEvent(wxCommandEvent&); //four event
	void fiveEvent(wxCommandEvent&); //five event
	void sixEvent(wxCommandEvent&); //six event
	void sevenEvent(wxCommandEvent&); //seven event
	void eightEvent(wxCommandEvent&); //eight event
	void nineEvent(wxCommandEvent&); //nine event

	void addEvent(wxCommandEvent&); //addition event
	void minusEvent(wxCommandEvent&); //subtraction event
	void multiplyEvent(wxCommandEvent&); //multiplication event
	void divideEvent(wxCommandEvent&); //division event
	void modEvent(wxCommandEvent&); //modulo event

	void sinEvent(wxCommandEvent&); //sin event
	void cosEvent(wxCommandEvent&); //cos event
	void tanEvent(wxCommandEvent&); //tan event

	void equalsEvent(wxCommandEvent&); //equals event
	void clearEvent(wxCommandEvent&); //clear event
	void deleteEvent(wxCommandEvent&); //del event
	void decimalEvent(wxCommandEvent&); //decimal event
	void negativeEvent(wxCommandEvent&); //negative event
	void squaredEvent(wxCommandEvent&); //squared event

	bool isNumber(std::string s); //custom isNumber function

public:
	Window(); //default constructor
};