//#pragma once
#include <wx/tokenzr.h>
class CalculatorProcessor
{
private:
	CalculatorProcessor() {} //default constructor
	//static bool isOperator(std::string oper);						   //checks if operator
	static int precedence(std::string binaryOper);					   //determines precedence/order of operations
	//static bool isNumber(std::string s);							   //checks if number [whole or decimal & pos or neg counts]
	static float evaluateTrigFunction(std::string func, float value);  //solves trig functions
	static std::string infixToPostfix(std::string text);			   //sets the passed equation into postfix form
	static float postfixSolving(std::string text);					   //solves the equation from the postfix form

public:
	static CalculatorProcessor* instance; //static pointer to manage singleton behaviour [wether or an instance has already been created or not
	static CalculatorProcessor* getInstance(); //static getInstance method -> how the class is initialized
	static float shuntingYard(std::string text); //calls infixToPostfix and postFixSolving to complete the reverse polish notation
	static bool isOperator(std::string oper);						   //checks if operator
	static bool isNumber(std::string s);							   //checks if number [whole or decimal & pos or neg counts]
};
