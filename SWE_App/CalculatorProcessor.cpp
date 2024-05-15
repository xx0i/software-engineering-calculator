#include "CalculatorProcessor.h"
#include <cmath>
#include <stack>

//SINGLETON METHODS
CalculatorProcessor* CalculatorProcessor::instance = 0;

CalculatorProcessor* CalculatorProcessor::getInstance()
{
	if (instance == 0) {
		instance = new CalculatorProcessor(); //memory for instance cleaned/deleted in app destructor, since that is where the calculator runs from
	}
	return instance;
}

//SHUNTING YARD METHODS
bool CalculatorProcessor::isOperator(std::string binOp) { //checks if the passed string is a binary operator
	return ((binOp == '+') || (binOp == '-') || (binOp == '*') || (binOp == '/') || (binOp == '%'));
}

bool CalculatorProcessor::isNumber(std::string value) { //checks if the passed string is a num [can be a whole number or decimal & pos or neg]
    std::size_t pos(0);
    if (value[pos] == '+' || value[pos] == '-') ++pos; //ignores sign if needed

    int num;
    int pt;
    //checks if the number is a valid whole number or decimal
    for (num = 0, pt = 0; std::isdigit(value[pos]) || value[pos] == '.'; ++pos) {
        value[pos] == '.' ? ++pt : ++num;
    }
    if (pt > 1 || num < 1) //makes sure that there is only one point and an actual num
        return false;

    return pos == value.size(); //makes sure the entire string is checked
}



int CalculatorProcessor::precedence(std::string oper) { //checks the order of precedence of the passed string to determine the order or operations
    if (oper == '+' || oper == '-') { //addition/subtraction
		return 1;
	}
	else if (oper == '*' || oper == '/' || oper == '%') { //multiplication/division/modulo
		return 2;
	}
}

float CalculatorProcessor::evaluateTrigFunction(std::string func, float value) { //solves the trig functions
	if (func == "Sin") { //sin
		return std::sinf(value);
	}
	else if (func == "Cos") { //cos
		return std::cosf(value);
	}
	else if (func == "Tan") { //tan
		return std::tanf(value);
	}
}

std::string CalculatorProcessor::infixToPostfix(std::string text) {
    //initializes the stack and string to be returned
    std::stack<std::string> operators;
    std::string postFix;
        //sets up tokenizer and the string ver of the token
        wxStringTokenizer tokenizer(text, " ");
        tokenizer.SetString(text, " ");
        while (tokenizer.HasMoreTokens()) {
        wxString ogToken = tokenizer.GetNextToken();
        std::string token = ogToken.ToStdString();
        if (isOperator(token)) { //if the token is a binary operator -> checks precedence -> adds to operators accordingly
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                postFix += operators.top() + " ";
                operators.pop();
            }
            operators.push(token);
            /*if (isOperator((tokenizer.GetNextToken()).ToStdString())) {
                return ("Invalid Equation, Please Enter a valid Equation");
            }*/
        }
        else if (token.size() > 1 && token[token.size() - 1] == '²') { //squares here and adds result to the postfix form
            float result = std::stof(token);
            result *= result;
            std::string resultSquared = std::to_string(result);
            postFix += resultSquared + " ";
        }
        else if (isNumber(token)) { //if the token is a number -> adds to string (with space)
            postFix += token + " ";
        }
        else if (token[0] == 'S' || token[0] == 'C' || token[0] == 'T') { //if the token is an unary operator -> separates num and txt and passes to evaluate trig function
            std::string unaryFunc;
            unaryFunc += token;
            unaryFunc.erase(unaryFunc.end() - 1);
            token.erase(token.begin(), token.begin()+3);
            std::string te = std::to_string(evaluateTrigFunction(unaryFunc, std::stof(token)));
            postFix += te + " ";
        }
    }

    while (!operators.empty()) { //adds the operators from the stack to the string to return (with a space)
        postFix += operators.top() + " ";
        operators.pop();
    }

    return postFix; //returns the equation now in postFix form
}

float CalculatorProcessor::postfixSolving(std::string text)
{
     std::stack<float> stack; //stack used in solving
         //sets up tokenizer and string ver of the token
         wxStringTokenizer tokenizer(text, " ");
         tokenizer.SetString(text, " ");
         while (tokenizer.HasMoreTokens()) {
         wxString ogToken = tokenizer.GetNextToken();
         std::string token = ogToken.ToStdString();

         if (isNumber(token)) { //if the token is a number adds converts to a float and adds to the stack
             stack.push(std::stof(token));
         }
         else if (isOperator(token)) { //if the token is a binary operator gets the top two values of the stack -> and plugs them into the corresponding operator
             float op2 = stack.top();
             stack.pop();
             float op1 = stack.top();
             stack.pop();

             char c = token[0];
             switch (c) {
             case '+': {
                 stack.push(op1 + op2); 
                 break;
             }
             case '-': {
                 stack.push(op1 - op2); 
                 break;
             }
             case '*': {
                 stack.push(op1 * op2);
                 break;
             }
             case '/': {
                 stack.push(op1 / op2); break;
             }
             case '%': {
                 stack.push(std::fmodf(op1, op2)); break;
             }
             }
         }
    }

     return stack.top(); //the answer is now the top of the stack
}

float CalculatorProcessor::shuntingYard(std::string text) //method called in Window.cpp -> calls infixToPost then postfixSolving with correct arguments
{
    std::string result = infixToPostfix(text);
    float result2 = postfixSolving(result);
    return result2; //returns the answer
}