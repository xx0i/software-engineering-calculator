#include "../SWE_App/CalculatorProcessor.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace CalcProcessorTests
{
	TEST_CLASS(CalcProcessorTests)
	{
	public:
		//FOR THE NEXT 9 TESTS : testing single operator math
		TEST_METHOD(singleAddition1) //addition - reg
		{
			float reg = 1 + 1;
			float reg2 = CalculatorProcessor::shuntingYard("1 + 1");
			Assert::IsTrue(reg == reg2);
		}
		TEST_METHOD(singleAddition2) //addition - dec
		{
			float dec = 2.1f + 2.7f;
			float dec2 = CalculatorProcessor::shuntingYard("2.1 + 2.7");
			Assert::IsTrue(dec == dec2);
		}
		TEST_METHOD(singleAddition3) //addition - neg
		{
			float neg = -2 + -5;
			float neg2 = CalculatorProcessor::shuntingYard("-2 + -5");
			Assert::IsTrue(neg == neg2);
		}
		TEST_METHOD(singleAddition4) //addition - mix
		{
			float mix = 9 + -3.3f;
			float mix2 = CalculatorProcessor::shuntingYard("9 + -3.3");
			Assert::IsTrue(mix == mix2);
		}
		TEST_METHOD(singleSubtraction1) //subtraction - reg
		{
			float reg = 18 - 3;
			float reg2 = CalculatorProcessor::shuntingYard("18 - 3");
			Assert::IsTrue(reg == reg2);
		}
		TEST_METHOD(singleSubtraction2) //subtraction - dec
		{
			float dec = 6.2f - 2.7f;
			float dec2 = CalculatorProcessor::shuntingYard("6.2 - 2.7");
			Assert::IsTrue(dec == dec2);
		}
		TEST_METHOD(singleSubtraction3) //subtraction - neg
		{
			float neg = -7 - -2;
			float neg2 = CalculatorProcessor::shuntingYard("-7 - -2");
			Assert::IsTrue(neg == neg2);
		}
		TEST_METHOD(singleSubtraction4) //subtraction - mix
		{
			float mix = -9 - 12.3f;
			float mix2 = CalculatorProcessor::shuntingYard("-9 - 12.3");
			Assert::IsTrue(mix == mix2);
		}
		TEST_METHOD(singleMultiplication1) //multiplication - reg
		{
			float reg = 5 * 6;
			float reg2 = CalculatorProcessor::shuntingYard("5 * 6");
			Assert::IsTrue(reg == reg2);
		}
		TEST_METHOD(singleMultiplication2) //multiplication - dec
		{
			float dec = 2.4f * 4.1f;
			float dec2 = CalculatorProcessor::shuntingYard("2.4 * 4.1");
			Assert::IsTrue(dec == dec2);
		}
		TEST_METHOD(singleMultiplication3) //multiplication - neg
		{
			float neg = -9 * -7;
			float neg2 = CalculatorProcessor::shuntingYard("-9 * -7");
			Assert::IsTrue(neg == neg2);
		}
		TEST_METHOD(singleMultiplication4) //multiplication - mix
		{
			float mix = 11 * -8.3f;
			float mix2 = CalculatorProcessor::shuntingYard("11 * -8.3");
			Assert::IsTrue(mix == mix2);
		}
		TEST_METHOD(singleDivision1) //division - reg
		{
			float reg = 12.0f / 4.0f;
			float reg2 = CalculatorProcessor::shuntingYard("12 / 4");
			Assert::IsTrue(reg == reg2);
		}
		TEST_METHOD(singleDivision2) //division - dec
		{
			float dec = 5.4f / 2.5f;
			float dec2 = CalculatorProcessor::shuntingYard("5.4 / 2.5");
			Assert::IsTrue(dec == dec2);
		}
		TEST_METHOD(singleDivision3) //division - neg
		{
			float neg = -3.0f / -23.0f;
			float neg2 = CalculatorProcessor::shuntingYard("-3 / -23");
			Assert::IsTrue(neg == neg2);
		}
		TEST_METHOD(singleDivision) //division - mix
		{
			float mix = 5.1f / -8.0f;
			float mix2 = CalculatorProcessor::shuntingYard("5.1 / -8");
			Assert::IsTrue(mix == mix2);
		}
		TEST_METHOD(singleModulo1) //modulo - reg
		{
			float reg = std::fmodf(9, 5);
			float reg2 = CalculatorProcessor::shuntingYard("9 % 5");
			Assert::IsTrue(reg == reg2);
		}
		TEST_METHOD(singleModulo2) //modulo - dec
		{
			float dec = std::fmodf(23.2, 9.7);
			float dec2 = CalculatorProcessor::shuntingYard("23.2 % 9.7");
			Assert::IsTrue(dec == dec2);
		}
		TEST_METHOD(singleModulo3) //modulo - neg
		{
			float neg = std::fmodf(-32, -13);
			float neg2 = CalculatorProcessor::shuntingYard("-32 % -13");
			Assert::IsTrue(neg == neg2);
		}
		TEST_METHOD(singleModulo4) //modulo - mix
		{
			float mix = std::fmodf(71, -32.2);
			float mix2 = CalculatorProcessor::shuntingYard("71 % -32.2");
			Assert::IsTrue(mix == mix2);
		}
		TEST_METHOD(singleSquared1) //squared - reg
		{
			float reg = 6 * 6;
			float reg2 = CalculatorProcessor::shuntingYard("6²");
			Assert::IsTrue(reg == reg2);
		}
		TEST_METHOD(singleSquared2) //squared - dec
		{
			float dec = 12.2f * 12.2f;
			float dec2 = CalculatorProcessor::shuntingYard("12.2²");
			Assert::IsTrue(dec == dec2);
		}
		TEST_METHOD(singleSquared3) //squared - neg
		{
			float neg = -5 * -5;
			float neg2 = CalculatorProcessor::shuntingYard("-5²");
			Assert::IsTrue(neg == neg2);
		}
		TEST_METHOD(singleSquared4) //squared - mix
		{
			float mix = -8.4f * -8.4f;
			float mix2 = CalculatorProcessor::shuntingYard("-8.4²");
			Assert::IsTrue(mix == mix2);
		}
	   	TEST_METHOD(singleSin1) //sin - reg
		{
			const float epsilon = 1e-6;
			float reg = std::sinf(5);
			float reg2 = CalculatorProcessor::shuntingYard(" Sin5");
			Assert::IsTrue(std::abs(reg2 - reg) < epsilon);
		}
		TEST_METHOD(singleSin2) //sin - dec
		{
			const float epsilon = 1e-6;
			float dec = std::sinf(4.5);
			float dec2 = CalculatorProcessor::shuntingYard(" Sin4.5");
			Assert::IsTrue(std::abs(dec2 - dec) < epsilon);
		}
		TEST_METHOD(singleSin3) //sin - neg
		{
			const float epsilon = 1e-6;
			float neg = std::sinf(-7);
			float neg2 = CalculatorProcessor::shuntingYard(" Sin-7");
			Assert::IsTrue(std::abs(neg2 - neg) < epsilon);
		}
		TEST_METHOD(singleSin4) //sin - mix
		{
			const float epsilon = 1e-6;
			float mix = std::sinf(-3.2);
			float mix2 = CalculatorProcessor::shuntingYard(" Sin-3.2");
			Assert::IsTrue(std::abs(mix2 - mix) < epsilon);
		}
		TEST_METHOD(singleCos1) //cos - reg
		{
			const float epsilon = 1e-6;
			float reg = std::cosf(7);
			float reg2 = CalculatorProcessor::shuntingYard(" Cos7");
			Assert::IsTrue(std::abs(reg2 - reg) < epsilon);
		}
		TEST_METHOD(singleCos2) //cos - dec
		{
			const float epsilon = 1e-6;
			float dec = std::cosf(8.4);
			float dec2 = CalculatorProcessor::shuntingYard(" Cos8.4");
			Assert::IsTrue(std::abs(dec2 - dec) < epsilon);
		}
		TEST_METHOD(singleCos3) //cos - neg
		{
			const float epsilon = 1e-6;
			float neg = std::cosf(-5);
			float neg2 = CalculatorProcessor::shuntingYard(" Cos-5");
			Assert::IsTrue(std::abs(neg2 - neg) < epsilon);
		}
		TEST_METHOD(singleCos4) //cos - mix
		{
			const float epsilon = 1e-6;
			float mix = std::cosf(-2.8);
			float mix2 = CalculatorProcessor::shuntingYard(" Cos-2.8");
			Assert::IsTrue(std::abs(mix2 - mix) < epsilon);
		}
		TEST_METHOD(singleTan1) //tan - reg
		{
			const float epsilon = 1e-6;
			float reg = std::tanf(9);
			float reg2 = CalculatorProcessor::shuntingYard(" Tan9");
			Assert::IsTrue(std::abs(reg2 - reg) < epsilon);
		}
		TEST_METHOD(singleTan2) //tan - dec
		{
			const float epsilon = 1e-6;
			float dec = std::tanf(2.3);
			float dec2 = CalculatorProcessor::shuntingYard(" Tan2.3");
			Assert::IsTrue(std::abs(dec2 - dec) < epsilon);
		}
		TEST_METHOD(singleTan3) //tan - neg
		{
			const float epsilon = 1e-6;
			float neg = std::tanf(-8);
			float neg2 = CalculatorProcessor::shuntingYard(" Tan-8");
			Assert::IsTrue(std::abs(neg2 - neg) < epsilon);
		}
		TEST_METHOD(singleTan4) //tan - mix
		{
			const float epsilon = 1e-6;
			float mix = std::tanf(-1.8);
			float mix2 = CalculatorProcessor::shuntingYard(" Tan-1.8");
			Assert::IsTrue(std::abs(mix2 - mix) < epsilon);
		}
		//FOR THE NEXT 3 TEST SETS : testing multiple operators math
		TEST_METHOD(multipleBinary1) //multiple binary operators only - reg
		{
			float reg = ((((12*7)/2)+5)-1);
			float reg2 = CalculatorProcessor::shuntingYard("5 + 12 * 7 / 2 - 1");
			Assert::IsTrue(reg == reg2);
		}
		TEST_METHOD(multipleBinary2) //multiple binary operators only - dec
		{
			float dec = (((2.4f * 4.1f) - 32.3) + (std::fmodf((3.1 * 3.1), 3.4)));
			float dec2 = CalculatorProcessor::shuntingYard("2.4 * 4.1 - 32.3 + 3.1² % 3.4");
			Assert::IsTrue(dec == dec2);
		}
		TEST_METHOD(multipleBinary3) //multiple binary operators only - neg
		{
			float neg = ((((-9 / -3) + -2.1) - (-3.2)) + (-21 * -7));
			float neg2 = CalculatorProcessor::shuntingYard("-9 / -3 + -2.1 - -3.2 + -21 * -7");
			Assert::IsTrue(neg == neg2);
		}
		TEST_METHOD(multipleBinary4) //multiple binary operators only - mix
		{
			float mix = ((((2 * 2) * 11.2) + (9 % 4)) - (0 * -8.3));
			float mix2 = CalculatorProcessor::shuntingYard("2² * 11.2 + 9 % 4 - 0 * -8.3");
			Assert::IsTrue(mix == mix2);
		}
		TEST_METHOD(multipleTrig1) //multiple trig operators (no non trig numbers) - reg
		{
			const float epsilon = 1e-6;
			float reg = (std::sinf(3*3) + ((std::sinf(4.5) * std::tanf(12.3)) / std::cosf(21)));
			float reg2 = CalculatorProcessor::shuntingYard(" Sin3² +  Sin4.5 *  Tan12.3 /  Cos21");
			Assert::IsTrue(std::abs(reg2 - reg) < epsilon);
		}
		TEST_METHOD(multipleTrig2) //multiple trig operators (no non trig numbers) - dec
		{
			const float epsilon = 1e-6;
			float dec = ((std::sinf(5.6)) * ((std::cosf(7.2)))) - ((std::tanf(2.8)) * ((std::sinf(8.5))));
			float dec2 = CalculatorProcessor::shuntingYard(" Sin5.6 *  Cos7.2 -  Tan2.8 *  Sin8.5");
			Assert::IsTrue(std::abs(dec2 - dec) < epsilon);
		}
		TEST_METHOD(multipleTrig3) //multiple trig operators (no non trig numbers) - neg
		{
			const float epsilon = 1e-6;
			float neg = (std::tanf(-12 * -12) + (std::fmodf(std::cosf(-2), std::sinf(-8)) * std::cos(-6)));
			float neg2 = CalculatorProcessor::shuntingYard(" Tan-12² +  Cos-2 %  Sin-8 * Cos-6");
			Assert::IsTrue(std::abs(neg2 - neg) < epsilon);
		}
		TEST_METHOD(multipleTrig4) //multiple trig operators (no non trig numbers) - mix
		{
			const float epsilon = 1e-6;
			float mix = ((std::sinf(2.3) + (std::tanf(-12) / std::cosf(5 * 5))) - (std::sinf(9) * std::tanf(-2.4)));
			float mix2 = CalculatorProcessor::shuntingYard(" Sin2.3 +  Tan-12 /  Cos5² -  Sin9 *  Tan-2.4");
			Assert::IsTrue(std::abs(mix2 - mix) < epsilon);
		}
		TEST_METHOD(multipleBinaryTrig1) //multiple binary and trig operators - reg
		{
			const float epsilon = 1e-6;
			float reg = (12 + (((std::sinf(5)) * (3)) / std::cosf(12)));
			float reg2 = CalculatorProcessor::shuntingYard("12 +  Sin5 * 3 /  Cos12");
			Assert::IsTrue(std::abs(reg2 - reg) < epsilon);
		}
		TEST_METHOD(multipleBinaryTrig2) //multiple binary and trig operators - dec
		{
			const float epsilon = 1e-6;
			float dec = ((std::tanf(2.1)) - (std::fmodf(34.23, 3.1)) + (std::sinf(9.12)));
			float dec2 = CalculatorProcessor::shuntingYard(" Tan2.1 - 34.23 % 3.1 +  Sin9.12");
			Assert::IsTrue(std::abs(dec2 - dec) < epsilon);
		}
		TEST_METHOD(multipleBinaryTrig3) //multiple binary and trig operators - neg
		{
			const float epsilon = 1e-6;
			float neg = (-91.2 + ((std::tanf(-23)) * (std::cosf(-2))) + (-2 * -2));
			float neg2 = CalculatorProcessor::shuntingYard(" -91.2 +  Tan-23 *  Cos-2 + -2²");
			Assert::IsTrue(std::abs(neg2 - neg) < epsilon);
		}
		TEST_METHOD(multipleBinaryTrig4) //multiple binary and trig operators - mix
		{
			const float epsilon = 1e-6;
			float mix = (90 + (-12 * (std::sinf(4.3))) + (std::fmodf(((std::cosf(-2.1)) / (5.3 * 5.3)), -2.1)) + (std::tanf(2)));
			float mix2 = CalculatorProcessor::shuntingYard(" 90 + -12 *  Sin4.3 + Cos-2.1 / 5.3² % -2.1 +  Tan2");
			Assert::IsTrue(std::abs(mix2 - mix) < epsilon);
		}
		//FOR THE NEXT TEST SET : testing zero division and modulo
		TEST_METHOD(singleZeroDiv) //zero div single vers
		{
			float divZero = CalculatorProcessor::shuntingYard("3 / 0");
			Assert::IsTrue(isinf(divZero));
		}
		TEST_METHOD(singleZeroMod) //zero mod single vers
		{
			float modZero = CalculatorProcessor::shuntingYard("9 % 0");
			Assert::IsTrue(isnan(modZero));
		}
		TEST_METHOD(multipleZeroDiv) //if a zero div is in a multiple operator statement
		{
			float divZeroMultiple = CalculatorProcessor::shuntingYard("9 +  Sin23 - -12 * 8 +  Cos3 / 0");
			Assert::IsTrue(isinf(divZeroMultiple));
		}
		TEST_METHOD(multipleZeroMod) //if a zero mod is in a multiple operator statement
		{
			float modZeroMultiple = CalculatorProcessor::shuntingYard("9 /  Tan3 - 45 +  Sin6.1 - 21 % 0 * 2.3");
			Assert::IsTrue(isnan(modZeroMultiple));
		}
	};
}