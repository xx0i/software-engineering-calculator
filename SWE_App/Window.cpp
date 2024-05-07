#include "Window.h"

Window::Window() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(392, 462)) //default constructor
{
	//text control
	textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(16,20), wxSize(345,166));
	//numbers 0-9
	zero = new wxButton(this, wxID_ANY, "0", wxPoint(20,200), wxSize(40,40));
	one = new wxButton(this, wxID_ANY, "1", wxPoint(80,200), wxSize(40,40));
	two = new wxButton(this, wxID_ANY, "2", wxPoint(140,200), wxSize(40,40));
	three = new wxButton(this, wxID_ANY, "3", wxPoint(200,200), wxSize(40,40));
	four = new wxButton(this, wxID_ANY, "4", wxPoint(260,200), wxSize(40,40));
	five = new wxButton(this, wxID_ANY, "5", wxPoint(20,254), wxSize(40,40));
	six = new wxButton(this, wxID_ANY, "6", wxPoint(80,254), wxSize(40,40));
	seven = new wxButton(this, wxID_ANY, "7", wxPoint(140,254), wxSize(40,40));
	eight = new wxButton(this, wxID_ANY, "8", wxPoint(200,254), wxSize(40,40));
	nine = new wxButton(this, wxID_ANY, "9", wxPoint(260,254), wxSize(40,40));
	//binary operators
	addition = new wxButton(this, wxID_ANY, "+", wxPoint(20,308), wxSize(40,40));
	subtraction = new wxButton(this, wxID_ANY, "-", wxPoint(80,308), wxSize(40,40));
	multiplication = new wxButton(this, wxID_ANY, "*", wxPoint(140,308), wxSize(40,40));
	division = new wxButton(this, wxID_ANY, "/", wxPoint(200,308), wxSize(40,40));
	modulo = new wxButton(this, wxID_ANY, "%", wxPoint(260,308), wxSize(40,40));
	//unary operators
	sin = new wxButton(this, wxID_ANY, "sin", wxPoint(80,362), wxSize(40,40));
	cos = new wxButton(this, wxID_ANY, "cos", wxPoint(140,362), wxSize(40,40));
	tan = new wxButton(this, wxID_ANY, "tan", wxPoint(200,362), wxSize(40,40));
	//equals
	equals = new wxButton(this, wxID_ANY, "=", wxPoint(320,200), wxSize(40,40));
	//clear
	clear = new wxButton(this, wxID_ANY, "clear", wxPoint(320,254), wxSize(40,40));
	//backspace
	backspace = new wxButton(this, wxID_ANY, "delete", wxPoint(320,308), wxSize(40,40));
	//decimal
	decimal = new wxButton(this, wxID_ANY, ".", wxPoint(260,362), wxSize(40,40));
	//negative
	negative = new wxButton(this, wxID_ANY, "+/-", wxPoint(320,362), wxSize(40,40));
	//x^2 (adding extra to make buttons even)
	squared = new wxButton(this, wxID_ANY, "x²", wxPoint(20, 362), wxSize(40, 40));
}