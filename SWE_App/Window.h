#pragma once
#include "wx/wx.h"

class Window : public wxFrame //windows class deriving from wxFrame
{
private:
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
	wxButton* backspace = nullptr;
	//decimal
	wxButton* decimal = nullptr;
	//negative
	wxButton* negative = nullptr;
	//x^2 (adding extra to make buttons even)
	wxButton* squared = nullptr;
public:
	Window(); //default constructor
};