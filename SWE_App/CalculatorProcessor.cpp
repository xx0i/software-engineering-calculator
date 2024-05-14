#include "CalculatorProcessor.h"

CalculatorProcessor* CalculatorProcessor::instance = 0;

CalculatorProcessor* CalculatorProcessor::getInstance()
{
	if (instance == 0) {
		instance = new CalculatorProcessor(); //memory for instance cleaned/deleted in app destructor, since that is where the calculator runs from
	}
	return instance;
}
