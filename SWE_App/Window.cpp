#include "Window.h"
#include <wx/tokenzr.h>
#include "ButtonFactory.h"

//EVENT TABLE
wxBEGIN_EVENT_TABLE(Window, wxFrame)
EVT_BUTTON(20123, Window::zeroEvent)
EVT_BUTTON(11212, Window::oneEvent)
EVT_BUTTON(32313, Window::twoEvent)
EVT_BUTTON(13212, Window::threeEvent)
EVT_BUTTON(24234, Window::fourEvent)
EVT_BUTTON(15623, Window::fiveEvent)
EVT_BUTTON(13523, Window::sixEvent)
EVT_BUTTON(14322, Window::sevenEvent)
EVT_BUTTON(25453, Window::eightEvent)
EVT_BUTTON(15354, Window::nineEvent)
EVT_BUTTON(26433, Window::addEvent)
EVT_BUTTON(18743, Window::minusEvent)
EVT_BUTTON(32412, Window::multiplyEvent)
EVT_BUTTON(25231, Window::divideEvent)
EVT_BUTTON(12643, Window::modEvent)
EVT_BUTTON(16431, Window::sinEvent)
EVT_BUTTON(19321, Window::cosEvent)
EVT_BUTTON(15423, Window::tanEvent)
EVT_BUTTON(32134, Window::equalsEvent)
EVT_BUTTON(32221, Window::clearEvent)
EVT_BUTTON(31123, Window::deleteEvent)
EVT_BUTTON(17934, Window::decimalEvent)
EVT_BUTTON(29723, Window::negativeEvent)
EVT_BUTTON(31323, Window::squaredEvent)
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
	buttonIds = { {20123, 11212, 32313, 13212, 24234, 32134}, {15623, 13523, 14322, 25453, 15354, 32221},
		{26433, 18743, 32412, 25231, 12643, 31123}, {31323, 16431, 19321, 15423, 17934, 29723} };
	buttons = {{zero, one, two, three, four, equals}, {five, six, seven, eight, nine, clear},
		{addition, subtraction, multiplication, division, modulo, del}, {squared, sin, cos, tan, decimal, negative}};
	//nested for-loop used to actually initialize the buttons
	for (int row = 0; row < buttons.size(); row++) {
		for (int col = 0; col < buttons[row].size(); col++) {
			ButtonFactory::createButton(buttons[row][col], this, buttonIds[row][col], buttonLabels[row][col], row, col); //calls createButton from ButtonFactory with necessary parameters
		}
	}
}

//BUTTON EVENTS
//number events
void Window::zeroEvent(wxCommandEvent&)
{
	textBox->WriteText("0");
}
void Window::oneEvent(wxCommandEvent&)
{
	textBox->WriteText("1");
}
void Window::twoEvent(wxCommandEvent&)
{
	textBox->WriteText("2");
}
void Window::threeEvent(wxCommandEvent&)
{
	textBox->WriteText("3");
}
void Window::fourEvent(wxCommandEvent&)
{
	textBox->WriteText("4");
}
void Window::fiveEvent(wxCommandEvent&)
{
	textBox->WriteText("5");
}
void Window::sixEvent(wxCommandEvent&)
{
	textBox->WriteText("6");
}
void Window::sevenEvent(wxCommandEvent&)
{
	textBox->WriteText("7");
}
void Window::eightEvent(wxCommandEvent&)
{
	textBox->WriteText("8");
}
void Window::nineEvent(wxCommandEvent&)
{
	textBox->WriteText("9");
}
//binary operators
void Window::addEvent(wxCommandEvent&)
{
	textBox->WriteText("+");
}
void Window::minusEvent(wxCommandEvent&)
{
	textBox->WriteText("-");
}
void Window::multiplyEvent(wxCommandEvent&)
{
	textBox->WriteText("*");
}
void Window::divideEvent(wxCommandEvent&)
{
	textBox->WriteText("/");
}
void Window::modEvent(wxCommandEvent&)
{
	textBox->WriteText("%");
}
//unary operators
void Window::sinEvent(wxCommandEvent&)
{
	textBox->WriteText("Sin");
}
void Window::cosEvent(wxCommandEvent&)
{
	textBox->WriteText("Cos");
}
void Window::tanEvent(wxCommandEvent&)
{
	textBox->WriteText("Tan");
}
//equals
void Window::equalsEvent(wxCommandEvent&)
{
	//sets up the string and textctrl for later
	textBox->WriteText("=");
	wxString text = textBox->GetValue();
	textBox->Clear();

	//EXCEPTION HANDLING
	//checks the box isn't empty
	if (text.IsEmpty() || text == '=') {
		textBox->WriteText("Please Enter an Equation");
		return;
	}

	//checks the length isn't one
	if (text.length() == 2) {
		textBox->WriteText("Please Enter a valid Equation");
		return;
	}

	//checks that no operator is repeated in a row
	for (int txtChar = 0; txtChar < text.length(); txtChar++) {
		if ((text[txtChar] == '+' && text[txtChar + 1] == text[txtChar]) || (text[txtChar] == '*' && text[txtChar + 1] == text[txtChar]) || (text[txtChar] == '/' && text[txtChar + 1] == text[txtChar]) ||
			(text[txtChar] == '%' && text[txtChar + 1] == text[txtChar]) || (text[txtChar] == '.' && text[txtChar + 1] == text[txtChar]) || (text[txtChar] == '²' && text[txtChar + 1] == text[txtChar]) ||
			(text[txtChar] == 'S' && text[txtChar + 1] == 'i' && text[txtChar + 2] == 'n' && text[txtChar + 3] == 'S' && text[txtChar + 4] == 'i' && text[txtChar + 5] == 'n') ||
			(text[txtChar] == 'C' && text[txtChar + 1] == 'o' && text[txtChar + 2] == 's' && text[txtChar + 3] == 'C' && text[txtChar + 4] == 'o' && text[txtChar + 5] == 's') ||
			(text[txtChar] == 'T' && text[txtChar + 1] == 'a' && text[txtChar + 2] == 'n' && text[txtChar + 3] == 'T' && text[txtChar + 4] == 'a' && text[txtChar + 5] == 'n')) {
			textBox->WriteText("Invalid Equation, Please Enter a valid Equation");
			return;
		}
	}
	//checks that the equation has a value before/after the operator
	if ((text.ends_with("+=")) || (text.ends_with("-=")) || (text.ends_with("*=")) || (text.ends_with("/=")) || (text.ends_with("%=")) || (text.ends_with(".="))
		|| (text.ends_with("n=")) || (text.ends_with("s=")) || (text.ends_with(")=")) || text[0] == '+' || text[0] == '*' || text[0] == '/' || text[0] == '%' || text[0] == '²') {
		textBox->WriteText("Invalid Equation, Please Enter a valid Equation");
		return;
	}

	//VALID EQUATION SOLVING
	//initializes the variables and the tokenizer
	float result = 0.0f;
	float whole;
	float decimal;
	wxStringTokenizer tokenizer(text, "+-*/%");
	tokenizer.SetString(text, "+-*/%");
	//loops until there are no more tokens in the tokenizer
	while (tokenizer.HasMoreTokens())
	{
		wxString token = tokenizer.GetNextToken();
		std::string tokenVer2 = token.ToStdString();

		//START OF TOKEN PROCESSING -> for all calculations if the number is whole no decimal values are shown, otherwise six decimal values are shown
		//how to get past the first parenthesis for the negative sign
		if (tokenVer2 == '(' || tokenVer2 == "Sin(" || tokenVer2 == "Cos(" || tokenVer2 == "Tan(") {
			continue;
		}
		//calculations for if the negative sign is in front of the sin/cos/tan
		if ((tokenVer2[0] == ')' && tokenVer2[1] == 'S') || (tokenVer2[0] == ')' && tokenVer2[1] == 'C') || (tokenVer2[0] == ')' && tokenVer2[1] == 'T')) {
			//(-)Sinx
			if (tokenVer2[1] == 'S') {
				std::string num = tokenVer2.substr(4);
				float result = std::stof(num);
				result = (std::sinf(result) * -1);
				decimal = std::modf(result, &whole);
				if (decimal == 0.0f) {
					int result2 = result;
					textBox->WriteText(std::to_string(result2) + " (radians)");
				}
				else {
					textBox->WriteText(std::to_string(result) + " (radians)");
				}
			}
			//(-)Cosx
			else if (tokenVer2[1] == 'C') {
				std::string num = tokenVer2.substr(4);
				float result = std::stof(num);
				result = (std::cosf(result) * -1);
				decimal = std::modf(result, &whole);
				if (decimal == 0.0f) {
					int result2 = result;
					textBox->WriteText(std::to_string(result2) + " (radians)");
				}
				else {
					textBox->WriteText(std::to_string(result) + " (radians)");
				}
			}
			//(-)Tanx
			else if (tokenVer2[1] == 'T') {
				std::string num = tokenVer2.substr(4);
				float result = std::stof(num);
				result = (std::tanf(result * -1));
				decimal = std::modf(result, &whole);
				if (decimal == 0.0f) {
					int result2 = result;
					textBox->WriteText(std::to_string(result2) + " (radians)");
				}
				else {
					textBox->WriteText(std::to_string(result) + " (radians)");
				}
			}
			continue;
		}
		//calculations for if the number is being squared [x²/(-)x^²]
		if (tokenVer2.size() > 1 && tokenVer2[tokenVer2.size() - 2] == '²') {
			if (tokenVer2[0] == ')') {
				tokenVer2 = tokenVer2.substr(1);
			}
			result = std::stof(tokenVer2);
			result *= result;
			decimal = std::modf(result, &whole);
			if (decimal == 0.0f) {
				int result2 = result;
				textBox->WriteText(std::to_string(result2));
			}
			else {
				textBox->WriteText(std::to_string(result));
			}
			continue;
		}
		//calculations for if the first half of the equation/the operand is negative [+-*/%]
		if (isNumber(token.ToStdString()) || token.ToStdString()[0] == ')') {
			std::string tokenVer2 = token.ToStdString();
			if (tokenVer2[0] == ')' && tokenizer.HasMoreTokens()) {
				tokenVer2 = tokenVer2.substr(1);
				result = (std::stof(tokenVer2) * -1);
			}
			//calculations for if the second half of the equation/the operand is negative [+-*/% sin/cos/tan (for unary operators the negative is between the operator and the term]
			else if (tokenVer2[0] == ')' && tokenizer.HasMoreTokens() == false) {
				for (int currTextChar = 0; currTextChar < text.size(); currTextChar++) {
					//addition
					if (text[currTextChar] == '+') {
						tokenVer2 = tokenVer2.substr(1, tokenVer2.length());
						result += (std::stof(tokenVer2) * -1);
						decimal = std::modf(result, &whole);
						if (decimal == 0.0f) {
							int result2 = result;
							textBox->WriteText(std::to_string(result2));
						}
						else {
							textBox->WriteText(std::to_string(result));
						}
						break;
					}
					//subtraction
					else if (text[currTextChar] == '-') {
						if (text.Contains("-") && text.Contains("+") || text.Contains("-") && text.Contains("*") || text.Contains("-") && text.Contains("/")
							|| text.Contains("-") && text.Contains("%")) {
							continue;
						}
						tokenVer2 = tokenVer2.substr(1, tokenVer2.length());
						result -= (std::stof(tokenVer2) * -1);
						decimal = std::modf(result, &whole);
						if (decimal == 0.0f) {
							int result2 = result;
							textBox->WriteText(std::to_string(result2));
						}
						else {
							textBox->WriteText(std::to_string(result));
						}
						break;
					}
					//multiplication
					else if (text[currTextChar] == '*') {
						tokenVer2 = tokenVer2.substr(1, tokenVer2.length());
						result *= (std::stof(tokenVer2) * -1);
						decimal = std::modf(result, &whole);
						if (decimal == 0.0f) {
							int result2 = result;
							textBox->WriteText(std::to_string(result2));
						}
						else {
							textBox->WriteText(std::to_string(result));
						}
						break;
					}
					//division
					else if (text[currTextChar] == '/') {
						tokenVer2 = tokenVer2.substr(1, tokenVer2.length());
						if (std::stof(tokenVer2) != 0) {
							result /= (std::stof(tokenVer2) * -1);
							decimal = std::modf(result, &whole);
							if (decimal == 0.0f) {
								int result2 = result;
								textBox->WriteText(std::to_string(result2));
							}
							else {
								textBox->WriteText(std::to_string(result));
							}
						}
						else {
							textBox->WriteText("Cannot divide by 0");
						}
						break;
					}
					//modulo
					else if (text[currTextChar] == '%') {
						tokenVer2 = tokenVer2.substr(1, tokenVer2.length());
						if (std::stof(tokenVer2) != 0) {
							result = std::fmodf(result, std::stof(tokenVer2));
							decimal = std::modf(result, &whole);
							if (decimal == 0.0f) {
								int result2 = result;
								textBox->WriteText(std::to_string(result2));
							}
							else {
								textBox->WriteText(std::to_string(result));
							}
						}
						else {
							textBox->WriteText("Cannot mod by 0");
						}
						break;
					}
					//Sin
					else if (text[currTextChar] == 'S') {
						tokenVer2 = tokenVer2.substr(1, tokenVer2.length());
						std::string num = tokenVer2;
						float result = std::stof(num);
						result = std::sinf(result * -1);
						decimal = std::modf(result, &whole);
						if (decimal == 0.0f) {
							int result2 = result;
							textBox->WriteText(std::to_string(result2) + " (radians)");
						}
						else {
							textBox->WriteText(std::to_string(result) + " (radians)");
						}
						break;
					}
					//Cos
					else if (text[currTextChar] == 'C') {
						tokenVer2 = tokenVer2.substr(1, tokenVer2.length());
						std::string num = tokenVer2;
						float result = std::stof(num);
						result = std::cosf(result * -1);
						decimal = std::modf(result, &whole);
						if (decimal == 0.0f) {
							int result2 = result;
							textBox->WriteText(std::to_string(result2) + " (radians)");
						}
						else {
							textBox->WriteText(std::to_string(result) + " (radians)");
						}
						break;
					}
					//Tan
					else if (text[currTextChar] == 'T') {
						tokenVer2 = tokenVer2.substr(1, tokenVer2.length());
						std::string num = tokenVer2;
						float result = std::stof(num);
						result = std::tanf(result * -1);
						decimal = std::modf(result, &whole);
						if (decimal == 0.0f) {
							int result2 = result;
							textBox->WriteText(std::to_string(result2) + " (radians)");
						}
						else {
							textBox->WriteText(std::to_string(result) + " (radians)");
						}
						break;
					}
				}
				continue;
			}
			else {
				result = std::stof(tokenVer2);
			}
			//positive +-*/% calculations -> if runs into the start of a negative number '(' calls continue
			//addition
			if (tokenizer.GetLastDelimiter() == '+') {
				wxString token = tokenizer.GetNextToken();
				std::string tokenVer2 = token.ToStdString();
				if (tokenVer2[0] == '(') {
					continue;
				}
				result += std::stof(tokenVer2);
				decimal = std::modf(result, &whole);
				if (decimal == 0.0f) {
					int result2 = result;
					textBox->WriteText(std::to_string(result2));
				}
				else {
					textBox->WriteText(std::to_string(result));
				}
			}
			//subtraction
			else if (tokenizer.GetLastDelimiter() == '-') {
				wxString token = tokenizer.GetNextToken();
				std::string tokenVer2 = token.ToStdString();
				if (tokenVer2[0] == '(') {
					continue;
				}
				result -= std::stof(tokenVer2);
				decimal = std::modf(result, &whole);
				if (decimal == 0.0f) {
					int result2 = result;
					textBox->WriteText(std::to_string(result2));
				}
				else {
					textBox->WriteText(std::to_string(result));
				}
			}
			//multiplication
			else if (tokenizer.GetLastDelimiter() == '*') {
				wxString token = tokenizer.GetNextToken();
				std::string tokenVer2 = token.ToStdString();
				if (tokenVer2[0] == '(') {
					continue;
				}
				result *= std::stof(tokenVer2);
				decimal = std::modf(result, &whole);
				if (decimal == 0.0f) {
					int result2 = result;
					textBox->WriteText(std::to_string(result2));
				}
				else {
					textBox->WriteText(std::to_string(result));
				}
			}
			//division
			else if (tokenizer.GetLastDelimiter() == '/') {
				wxString token = tokenizer.GetNextToken();
				std::string tokenVer2 = token.ToStdString();
				if (tokenVer2[0] == '(') {
					continue;
				}
				if (std::stof(tokenVer2) != 0) {
					result /= std::stof(tokenVer2);
					decimal = std::modf(result, &whole);
					if (decimal == 0.0f) {
						int result2 = result;
						textBox->WriteText(std::to_string(result2));
					}
					else {
						textBox->WriteText(std::to_string(result));
					}
				}
				else {
					textBox->WriteText("Cannot divide by 0");
				}
			}
			//modulo
			else if (tokenizer.GetLastDelimiter() == '%') {
				wxString token = tokenizer.GetNextToken();
				std::string tokenVer2 = token.ToStdString();
				if (tokenVer2[0] == '(') {
					continue;
				}
				if (std::stof(tokenVer2) != 0) {
					result = std::fmodf(result, std::stof(tokenVer2));
					decimal = std::modf(result, &whole);
					if (decimal == 0.0f) {
						int result2 = result;
						textBox->WriteText(std::to_string(result2));
					}
					else {
						textBox->WriteText(std::to_string(result));
					}
				}
				else {
					textBox->WriteText("Cannot mod by 0");
				}
			}
		}
		//positive sin/cos/tan calculations
		std::string tokenTemp = token.ToStdString();
		std::string num = tokenTemp.substr(0, 3);
		if (num == "Sin" || num == "Cos" || num == "Tan") {
			//Sin
			if (tokenTemp[0] == 'S') {
				std::string num = tokenTemp.substr(3);
				float result = std::stof(num);
				result = std::sinf(result);
				decimal = std::modf(result, &whole);
				if (decimal == 0.0f) {
					int result2 = result;
					textBox->WriteText(std::to_string(result2) + " (radians)");
				}
				else {
					textBox->WriteText(std::to_string(result) + " (radians)");
				}
			}
			//Cos
			else if (tokenTemp[0] == 'C') {
				std::string num = tokenTemp.substr(3);
				float result = std::stof(num);
				result = std::cosf(result);
				decimal = std::modf(result, &whole);
				if (decimal == 0.0f) {
					int result2 = result;
					textBox->WriteText(std::to_string(result2) + " (radians)");
				}
				else {
					textBox->WriteText(std::to_string(result) + " (radians)");
				}
			}
			//Tan
			else if (tokenTemp[0] == 'T') {
				std::string num = tokenTemp.substr(3);
				float result = std::stof(num);
				result = std::tanf(result);
				decimal = std::modf(result, &whole);
				if (decimal == 0.0f) {
					int result2 = result;
					textBox->WriteText(std::to_string(result2) + " (radians)");
				}
				else {
					textBox->WriteText(std::to_string(result) + " (radians)");
				}
			}
		}
	}
}

//clear/delete
void Window::clearEvent(wxCommandEvent&)
{
	textBox->Clear();
}
void Window::deleteEvent(wxCommandEvent&)
{
	wxString text = textBox->GetValue();
	if (!text.IsEmpty()) {
		//checks if the string ends with s,n, or ) meaning it would be a unary operator or a negative,
		//and removes three characters instead of 1 to remove the unary operator or negative sign
		if (text.ends_with("s") || text.ends_with("n") || text.ends_with(")")) {
			textBox->Remove(text.length() - 3, text.length());
		}
		else { //otherwise just removes the last character
			textBox->Remove(text.length() - 1, text.length());
		}
	}
}
//decimal/negative/squared(extra)
void Window::decimalEvent(wxCommandEvent&)
{
	textBox->WriteText(".");
}
void Window::negativeEvent(wxCommandEvent&)
{
	textBox->WriteText("(-)");
}
void Window::squaredEvent(wxCommandEvent&)
{
	textBox->WriteText("²");
}

//custom isNumber function
bool Window::isNumber(std::string str)
{
	std::size_t pos(0);
	if (str[pos] == '+' || str[pos] == '-') ++pos; //ignores sign if needed

	int num;
	int pt;
	//checks if the number is a valid whole number or decimal
	for (num = 0, pt = 0; std::isdigit(str[pos]) || str[pos] == '.'; ++pos) {
		str[pos] == '.' ? ++pt : ++num;
	}
	if (pt > 1 || num < 1) //makes sure that there is only one point and an actual num
		return false;

	return pos == str.size(); //makes sure the entire string is checked
}
