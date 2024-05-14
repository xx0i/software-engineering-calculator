#pragma once
class CalculatorProcessor
{
private:

	CalculatorProcessor() {} //default constructor

public:
	static CalculatorProcessor* instance; //static pointer to manage singleton behaviour [wether or an instance has already been created or not
	static CalculatorProcessor* getInstance(); //static getInstance method -> how the class is initialized
};