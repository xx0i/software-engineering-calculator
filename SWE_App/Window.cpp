#include "Window.h"
#include <wx/tokenzr.h>
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"

//EVENT TABLE
wxBEGIN_EVENT_TABLE(Window, wxFrame)
EVT_BUTTON(wxID_ANY, Window::buttonClickEvent)
wxEND_EVENT_TABLE()

Window::Window() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(392, 462)) //default constructor
{
	//text control
	textBox = new wxTextCtrl(this, 12312, "", wxPoint(16, 20), wxSize(345, 166));
	//BUTTON INITIALIZATION
	//ButtonFactory instance created + buttons vector initialized to hold the buttons
	ButtonFactory::getInstance();
	buttonLabels = { {"0", "1", "2", "3", "4", "="}, {"5", "6", "7", "8", "9", "clear"},
	{"+", "-", "*", "/", "%", "delete"}, {"x²", "sin", "cos", "tan", "dec.(.)", "neg.(-)"} };
	buttons = { {zero, one, two, three, four, equals}, {five, six, seven, eight, nine, clear},
		{addition, subtraction, multiplication, division, modulo, del}, {squared, sin, cos, tan, decimal, negative} };
	//nested for-loop used to actually initialize the buttons
	for (int row = 0; row < buttons.size(); row++) {
		for (int col = 0; col < buttons[row].size(); col++) {
			ButtonFactory::createButton(buttons[row][col], this, buttonLabels[row][col], row, col); //calls createButton from ButtonFactory with necessary parameters
		}
	}
}

//MANAGES BUTTON PRESSING
void Window::buttonClickEvent(wxCommandEvent& event) {
	std::string label = std::string((wxDynamicCast(event.GetEventObject(), wxButton))->GetLabel());
	if (label == "0") {
		textBox->WriteText("0");
	}
	else if (label == "1") {
		textBox->WriteText("1");
	}
	else if (label == "2") {
		textBox->WriteText("2");
	}
	else if (label == "3") {
		textBox->WriteText("3");
	}
	else if (label == "4") {
		textBox->WriteText("4");
	}
	else if (label == "5") {
		textBox->WriteText("5");
	}
	else if (label == "6") {
		textBox->WriteText("6");
	}
	else if (label == "7") {
		textBox->WriteText("7");
	}
	else if (label == "8") {
		textBox->WriteText("8");
	}
	else if (label == "9") {
		textBox->WriteText("9");
	}
	else if (label == "+") {
		textBox->WriteText(" + ");
	}
	else if (label == "-") {
		textBox->WriteText(" - ");
	}
	else if (label == "*") {
		textBox->WriteText(" * ");
	}
	else if (label == "/") {
		textBox->WriteText(" / ");
	}
	else if (label == "%") {
		textBox->WriteText(" % ");
	}
	else if (label == "sin") {
		textBox->WriteText(" Sin");
	}
	else if (label == "cos") {
		textBox->WriteText(" Cos");
	}
	else if (label == "tan") {
		textBox->WriteText(" Tan");
	}
	else if (label == "clear") {
		textBox->Clear();
	}
	else if (label == "delete") {
		wxString text = textBox->GetValue();
		if (!text.IsEmpty()) {
			//checks if the string ends with s,n, or a space) meaning it would be an operator (unary or binary),
			//and removes three characters instead of 1 to remove the operator
			if (text.ends_with("s") || text.ends_with("n") || text.ends_with(" ")) {
				textBox->Remove(text.length() - 3, text.length());
			}
			else { //otherwise just removes the last character
				textBox->Remove(text.length() - 1, text.length());
			}
		}
	}
	else if (label == "=") {
		equationSolving();
	}
	else if (label == "dec.(.)") {
		textBox->WriteText(".");
	}
	else if (label == "neg.(-)") {
		textBox->WriteText("-");
	}
	else if (label == "x²") {
		textBox->WriteText("²");
	}
}

//solves the equation when equals is pressed
void Window::equationSolving() {
	//sets up the string and textctrl for later
	textBox->WriteText("=");
	wxString text = textBox->GetValue();
	textBox->Clear();
	CalculatorProcessor::getInstance(); //gets the instance of CalculatorProcessor

	//EXCEPTION HANDLING
	//checks the box isn't empty
	if (text.IsEmpty() || text == '=') {
		textBox->WriteText("Please Enter an Equation");
		return;
	}

	//checks the length isn't one
	if (text.length() == 2 || (text.length() == 3 && text.starts_with('-'))) {
		textBox->WriteText("Please Enter a valid Equation");
		return;
	}

	//checks that the equation has a value before/after the operator
	if ((text.ends_with("+ =")) || (text.ends_with("- =")) || (text.ends_with("* =")) || (text.ends_with("/ =")) || (text.ends_with("% =")) || (text.ends_with(".="))
		|| (text.ends_with("-=")) || (text.ends_with("n=")) || (text.ends_with("s=")) || text[0] == '²' || text.Contains(".²")
		|| text.Contains("+ ²") || text.Contains("- ²") || text.Contains("* ²") || text.Contains("/ ²") || text.Contains("% ²")){
		textBox->WriteText("Invalid Equation, Please Enter a valid Equation");
		return;
	}

	//checks that the equation doesn't start with a binary operator
	if (text[0] == ' ') {
		std::string firstOper = text.ToStdString();
		firstOper = firstOper[1];
		if (CalculatorProcessor::isOperator(firstOper)) {
			textBox->WriteText("Invalid Equation, Please Enter a valid Equation");
			return;
		}
	}

	//loops to check no repeated binary operators + add a multiplication sign between repeated unary operators
	text.erase(text.end() - 1);
	wxStringTokenizer tokenizer(text, " ");
	tokenizer.SetString(text, " ");
	while (tokenizer.HasMoreTokens()) {
		wxString ogToken = tokenizer.GetNextToken();
		std::string token = ogToken.ToStdString();

		//Catches more than one binary operator in a row
		if (CalculatorProcessor::isOperator(token)) {
			ogToken = tokenizer.GetNextToken();
			token = ogToken.ToStdString();
			if (CalculatorProcessor::isOperator(token)) {
				textBox->WriteText("Invalid Equation, Please Enter a valid Equation");
				return;
			}
		}
		//skips squared operator -> 
		//numbers are also skipped but doesn't conflict with unary operator check so it doesn't need to be explicitly checked
		if ((token.size() > 1 && token[token.size() - 1] == '²')) {
			continue;
		}
		//checks if number is followed by a unary function [8 Cos7]
		if (CalculatorProcessor::isNumber(token)) {
			if (tokenizer.HasMoreTokens()) {
				ogToken = tokenizer.GetNextToken();
				std::string token2 = ogToken.ToStdString();
				if (!CalculatorProcessor::isOperator(token2) && !CalculatorProcessor::isNumber(token2)) {
					token2.erase(token2.end() - 1);

					if (token2 == "Sin" || token2 == "Cos" || token2 == "Tan") {
						wxString toFind = token + " " + token2;
						text.insert(text.find(toFind) + 2, "* ");
						continue;
					}
				}
			}
		}
		//checks for repeated Sin/Cos/Tan and adds a multiplication sign between to assist the shunting yard algorithm
		if (!CalculatorProcessor::isOperator(token) && !CalculatorProcessor::isNumber(token)) {
			std::string tokenTrig = token;
			tokenTrig.erase(tokenTrig.end() - 1);
			if (tokenTrig == "Sin" || tokenTrig == "Cos" || tokenTrig == "Tan") {
				if (tokenizer.HasMoreTokens()) {
					ogToken = tokenizer.GetNextToken();
					std::string token2 = ogToken.ToStdString();
					if (!CalculatorProcessor::isOperator(token2) && !CalculatorProcessor::isNumber(token2)) {
						std::string token2Trig = token2;
						token2Trig.erase(token2Trig.end() - 1);
						if (token2Trig == "Sin" || token2Trig == "Cos" || token2Trig == "Tan") {
							wxString toFind = token + " " + token2;
							text.insert(text.find(toFind) + 5, "* ");
						}
					}

				}

			}
		}
	}
	//VALID EQUATION SOLVING
	//initializes the variables and the tokenizer
	float result = 0.0f;
	float whole;
	float decimal;
	std::string textStrVer = text.ToStdString();

	result = CalculatorProcessor::shuntingYard(textStrVer); //passes the string ver of the equation to the shunting yard algorithm
	//if division or modulo by 0 was attempted returns an error message
	if (std::to_string(result) == "-nan(ind)" || std::to_string(result) == "inf") {
		textBox->WriteText("cannot divide or modulo by 0");
		return;
	}
	//if a number was returned checks if its a whole number and prints either a whole number or decimal
	decimal = std::modf(result, &whole);
	if (decimal == 0.0f) {
		int result2 = result;
		textBox->WriteText(std::to_string(result2));
	}
	else {
		textBox->WriteText(std::to_string(result));
	}
}