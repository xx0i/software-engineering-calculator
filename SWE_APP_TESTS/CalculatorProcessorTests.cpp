#include "../SWE_App/CalculatorProcessor.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace CalcProcessorTests
{
	TEST_CLASS(CalcProcessorTests)
	{
	public:
		//FOR THE NEXT 9 TESTS : testing single operator math
		TEST_METHOD(singleAddition) //addition
		{
			float reg = 1 + 1;
			float dec = 2.1f + 2.7f;
			float neg = -2 + -5;
			float mix = 9 + -3.3f;

			float reg2 = CalculatorProcessor::shuntingYard("1 + 1");
			float dec2= CalculatorProcessor::shuntingYard("2.1 + 2.7");
			float neg2 = CalculatorProcessor::shuntingYard("-2 + -5");
			float mix2 = CalculatorProcessor::shuntingYard("9 + -3.3");
			Assert::IsTrue(reg == reg2);
			Assert::IsTrue(dec == dec2);
			Assert::IsTrue(neg == neg2);
			Assert::IsTrue(mix == mix2);
		}
		TEST_METHOD(singleSubtraction) //subtraction
		{
			float reg = 18 - 3;
			float dec = 6.2f - 2.7f;
			float neg = -7 - -2;
			float mix = -9 - 12.3f;
			float reg2 = CalculatorProcessor::shuntingYard("18 - 3");
			float dec2 = CalculatorProcessor::shuntingYard("6.2 - 2.7");
			float neg2 = CalculatorProcessor::shuntingYard("-7 - -2");
			float mix2 = CalculatorProcessor::shuntingYard("-9 - 12.3");
			Assert::IsTrue(reg == reg2);
			Assert::IsTrue(dec == dec2);
			Assert::IsTrue(neg == neg2);
			Assert::IsTrue(mix == mix2);
		}
		TEST_METHOD(singleMultiplication) //multiplication
		{
			float reg = 5 * 6;
			float dec = 2.4f * 4.1f;
			float neg = -9 * -7;
			float mix = 11 * -8.3f;
			float reg2 = CalculatorProcessor::shuntingYard("5 * 6");
			float dec2 = CalculatorProcessor::shuntingYard("2.4 * 4.1");
			float neg2 = CalculatorProcessor::shuntingYard("-9 * -7");
			float mix2 = CalculatorProcessor::shuntingYard("11 * -8.3");
			Assert::IsTrue(reg == reg2);
			Assert::IsTrue(dec == dec2);
			Assert::IsTrue(neg == neg2);
			Assert::IsTrue(mix == mix2);
		}
		TEST_METHOD(singleDivision) //division
		{
			float reg = 12.0f / 4.0f;
			float dec = 5.4f / 2.5f;
			float neg = -3.0f / -23.0f;
			float mix = 5.1f / -8.0f;
			float reg2 = CalculatorProcessor::shuntingYard("12 / 4");
			float dec2 = CalculatorProcessor::shuntingYard("5.4 / 2.5");
			float neg2 = CalculatorProcessor::shuntingYard("-3 / -23");
			float mix2 = CalculatorProcessor::shuntingYard("5.1 / -8");
			Assert::IsTrue(reg == reg2);
			Assert::IsTrue(dec == dec2);
			Assert::IsTrue(neg == neg2);
			Assert::IsTrue(mix == mix2);
		}
		TEST_METHOD(singleModulo) //modulo
		{
			float reg = std::fmodf(9, 5);
			float dec = std::fmodf(23.2, 9.7);
			float neg = std::fmodf(-32, -13);
			float mix = std::fmodf(71, -32.2);
			float reg2 = CalculatorProcessor::shuntingYard("9 % 5");
			float dec2 = CalculatorProcessor::shuntingYard("23.2 % 9.7");
			float neg2 = CalculatorProcessor::shuntingYard("-32 % -13");
			float mix2 = CalculatorProcessor::shuntingYard("71 % -32.2");
			Assert::IsTrue(reg == reg2);
			Assert::IsTrue(dec == dec2);
			Assert::IsTrue(neg == neg2);
			Assert::IsTrue(mix == mix2);
		}
		TEST_METHOD(singleSquared) //squared
		{
			float reg = 6 * 6;
			float dec = 12.2f * 12.2f;
			float neg = -5 * -5;
			float mix = -8.4f * -8.4f;
			float reg2 = CalculatorProcessor::shuntingYard("6²");
			float dec2 = CalculatorProcessor::shuntingYard("12.2²");
			float neg2 = CalculatorProcessor::shuntingYard("-5²");
			float mix2 = CalculatorProcessor::shuntingYard("-8.4²");
			Assert::IsTrue(reg == reg2);
			Assert::IsTrue(dec == dec2);
			Assert::IsTrue(neg == neg2);
			Assert::IsTrue(mix == mix2);
		}
	   	TEST_METHOD(singleSin) //sin
		{
			const float epsilon = 1e-6;
			float reg = std::sinf(5);
			float dec = std::sinf(4.5);
			float neg = std::sinf(-7);
			float mix = std::sinf(-3.2);
			float reg2 = CalculatorProcessor::shuntingYard(" Sin5");
			float dec2 = CalculatorProcessor::shuntingYard(" Sin4.5");
			float neg2 = CalculatorProcessor::shuntingYard(" Sin-7");
			float mix2 = CalculatorProcessor::shuntingYard(" Sin-3.2");
			Assert::IsTrue(std::abs(reg2 - reg) < epsilon);
			Assert::IsTrue(std::abs(dec2 - dec) < epsilon);
			Assert::IsTrue(std::abs(neg2 - neg) < epsilon);
			Assert::IsTrue(std::abs(mix2 - mix) < epsilon);
		}
		TEST_METHOD(singleCos) //cos
		{
			const float epsilon = 1e-6;
			float reg = std::cosf(7);
			float dec = std::cosf(8.4);
			float neg = std::cosf(-5);
			float mix = std::cosf(-2.8);
			float reg2 = CalculatorProcessor::shuntingYard(" Cos7");
			float dec2 = CalculatorProcessor::shuntingYard(" Cos8.4");
			float neg2 = CalculatorProcessor::shuntingYard(" Cos-5");
			float mix2 = CalculatorProcessor::shuntingYard(" Cos-2.8");
			Assert::IsTrue(std::abs(reg2 - reg) < epsilon);
			Assert::IsTrue(std::abs(dec2 - dec) < epsilon);
			Assert::IsTrue(std::abs(neg2 - neg) < epsilon);
			Assert::IsTrue(std::abs(mix2 - mix) < epsilon);
		}
		TEST_METHOD(singleTan) //tan
		{
			const float epsilon = 1e-6;
			float reg = std::tanf(9);
			float dec = std::tanf(2.3);
			float neg = std::tanf(-8);
			float mix = std::tanf(-1.8);
			float reg2 = CalculatorProcessor::shuntingYard(" Tan9");
			float dec2 = CalculatorProcessor::shuntingYard(" Tan2.3");
			float neg2 = CalculatorProcessor::shuntingYard(" Tan-8");
			float mix2 = CalculatorProcessor::shuntingYard(" Tan-1.8");
			Assert::IsTrue(std::abs(reg2 - reg) < epsilon);
			Assert::IsTrue(std::abs(dec2 - dec) < epsilon);
			Assert::IsTrue(std::abs(neg2 - neg) < epsilon);
			Assert::IsTrue(std::abs(mix2 - mix) < epsilon);
		}
		//FOR THE NEXT 3 TESTS : testing multiple operators math
		TEST_METHOD(multipleBinary) //multiple binary operators only
		{
			float reg = ((((12*7)/2)+5)-1);
			float dec = (((2.4f * 4.1f) - 32.3) + (std::fmodf((3.1*3.1), 3.4)));
			float neg = ((((-9/-3)+-2.1)-(-3.2)) + (-21 * -7));
			float mix = ((((2*2)*11.2) + (9 % 4)) - (0 * -8.3));
			float reg2 = CalculatorProcessor::shuntingYard("5 + 12 * 7 / 2 - 1");
			float dec2 = CalculatorProcessor::shuntingYard("2.4 * 4.1 - 32.3 + 3.1² % 3.4");
			float neg2 = CalculatorProcessor::shuntingYard("-9 / -3 + -2.1 - -3.2 + -21 * -7");
			float mix2 = CalculatorProcessor::shuntingYard("2² * 11.2 + 9 % 4 - 0 * -8.3");
			Assert::IsTrue(reg == reg2);
			Assert::IsTrue(dec == dec2);
			Assert::IsTrue(neg == neg2);
			Assert::IsTrue(mix == mix2);
		}
		TEST_METHOD(multipleTrig) //multiple trig operators (no non trig numbers)
		{
			const float epsilon = 1e-6;
			float reg = (std::sinf(3*3) + ((std::sinf(4.5) * std::tanf(12.3)) / std::cosf(21)));
			float dec = ((std::sinf(5.6))*((std::cosf(7.2))))-((std::tanf(2.8))*((std::sinf(8.5))));
			float neg = (std::tanf(-12 * -12) + (std::fmodf(std::cosf(-2),std::sinf(-8)) * std::cos(-6)));
			float mix = ((std::sinf(2.3) + (std::tanf(-12) / std::cosf(5*5))) - (std::sinf(9) * std::tanf(-2.4)));
			float reg2 = CalculatorProcessor::shuntingYard(" Sin3² +  Sin4.5 *  Tan12.3 /  Cos21");
			float dec2 = CalculatorProcessor::shuntingYard(" Sin5.6 *  Cos7.2 -  Tan2.8 *  Sin8.5");
			float neg2 = CalculatorProcessor::shuntingYard(" Tan-12² +  Cos-2 %  Sin-8 * Cos-6");
			float mix2 = CalculatorProcessor::shuntingYard(" Sin2.3 +  Tan-12 /  Cos5² -  Sin9 *  Tan-2.4");
			Assert::IsTrue(std::abs(reg2 - reg) < epsilon);
			Assert::IsTrue(std::abs(dec2 - dec) < epsilon);
			Assert::IsTrue(std::abs(neg2 - neg) < epsilon);
			Assert::IsTrue(std::abs(mix2 - mix) < epsilon);
		}
		TEST_METHOD(multipleBinaryTrig) //multiple binary and trig operators
		{
			const float epsilon = 1e-6;
			float reg = (12 + (((std::sinf(5)) * (3)) / std::cosf(12)));
			float dec = ((std::tanf(2.1)) - (std::fmodf(34.23, 3.1)) + (std::sinf(9.12)));
			float neg = (-91.2 + ((std::tanf(-23)) * (std::cosf(-2))) + (-2 * -2));
			float mix = (90+ (-12 * (std::sinf(4.3))) + (std::fmodf(((std::cosf(-2.1)) / (5.3 * 5.3)), -2.1)) + (std::tanf(2)));
			float reg2 = CalculatorProcessor::shuntingYard("12 +  Sin5 * 3 /  Cos12");
			float dec2 = CalculatorProcessor::shuntingYard(" Tan2.1 - 34.23 % 3.1 +  Sin9.12");
			float neg2 = CalculatorProcessor::shuntingYard(" -91.2 +  Tan-23 *  Cos-2 + -2²");
			float mix2 = CalculatorProcessor::shuntingYard(" 90 + -12 *  Sin4.3 + Cos-2.1 / 5.3² % -2.1 +  Tan2");
			Assert::IsTrue(std::abs(reg2 - reg) < epsilon);
			Assert::IsTrue(std::abs(dec2 - dec) < epsilon);
			Assert::IsTrue(std::abs(neg2 - neg) < epsilon);
			Assert::IsTrue(std::abs(mix2 - mix) < epsilon);
		}
		//FOR THE NEXT TEST : testing zero division and modulo
		TEST_METHOD(zeroDivMod)
		{
			float divZero = CalculatorProcessor::shuntingYard("3 / 0");
			float modZero = CalculatorProcessor::shuntingYard("9 % 0");
			float divZeroMultiple = CalculatorProcessor::shuntingYard("9 +  Sin23 - -12 * 8 +  Cos3 / 0");
			float modZeroMultiple =  CalculatorProcessor::shuntingYard("9 /  Tan3 - 45 +  Sin6.1 - 21 % 0 * 2.3");
			Assert::IsTrue(isinf(divZero));
			Assert::IsTrue(isnan(modZero));
			Assert::IsTrue(isinf(divZeroMultiple));
			Assert::IsTrue(isnan(modZeroMultiple));
		}
	};
}