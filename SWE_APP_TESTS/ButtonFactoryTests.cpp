#include "CppUnitTest.h"
#include "../SWE_App/ButtonFactory.h"
#include "../SWE_App/Window.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace buttonFactTests
{
	TEST_CLASS(buttonFactTests)
	{
	public:
		//FOR THE NEXT 2 TESTS createGeneralButton : only checks id instead of every part since it isn't actually used in my code
		TEST_METHOD(genButtonNull) //null
		{
			wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Testing");
			wxButton* button1 = nullptr;
			button1 = ButtonFactory::createGeneralButton(button1, window, 12343, "test1", 21, 23, 12, 21);
			Assert::IsNotNull(button1);
		}
		TEST_METHOD(genButtonID) //id
		{
			wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Testing");
			wxButton* button2 = nullptr;
			button2 = ButtonFactory::createGeneralButton(button2, window, 12343, "test2", 21, 23, 12, 21);
			Assert::IsTrue(button2->GetId() == 12343);
		}
		//FOR THE NEXT 5 TESTS : tests createButton without a vector using 2 for the row and 3 for the col : doesn't check id since its wxID_ANY
		TEST_METHOD(buttonNull) //null
		{
			wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Testing");
			wxButton* button3 = nullptr;
			button3 = ButtonFactory::createButton(button3, window, "test3", 2, 3);
			Assert::IsNotNull(button3);
		}
		TEST_METHOD(buttonParent) //parent
		{
			wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Testing");
			wxButton* button4 = nullptr;
			button4 = ButtonFactory::createButton(button4, window, "test4", 2, 3);
			Assert::IsTrue(button4->GetParent() == window);
		}
		TEST_METHOD(buttonLabel) //label
		{
			wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Testing");
			wxButton* button5 = nullptr;
			button5 = ButtonFactory::createButton(button5, window, "test5", 2, 3);
			Assert::IsTrue(button5->GetLabel() == "test5");
		}
		TEST_METHOD(buttonPosition) //position
		{
			wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Testing");
			wxButton* button6 = nullptr;
			button6 = ButtonFactory::createButton(button6, window, "test6", 2, 3);
			Assert::IsTrue(button6->GetPosition() == wxPoint(200, 308));
		}
		TEST_METHOD(buttonSize) //size
		{
			wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Testing");
			wxButton* button7 = nullptr;
			button7 = ButtonFactory::createButton(button7, window, "test6", 2, 3);
			Assert::IsTrue(button7->GetSize() == wxSize(40, 40));
		}
		//FOR THE NEXT 5 TESTS : tests createButton using a 2D vector of size 2x2 : doesn't check id since its wxID_ANY
		TEST_METHOD(buttonVectorNull) //null
		{
			wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Testing");
			wxButton* button81 = nullptr;
			wxButton* button82 = nullptr;
			wxButton* button83 = nullptr;
			wxButton* button84 = nullptr;
			std::vector<std::vector<std::string>> buttonLabels = { {"test8.1", "test8.2"}, {"test8.3", "test8.4"}};
			std::vector<std::vector<wxButton*>> buttons = {{button81, button82}, {button83, button84}};
			for (int row = 0; row < buttons.size(); row++) {
				for (int col = 0; col < buttons[row].size(); col++) {
					buttons[row][col] = ButtonFactory::createButton(buttons[row][col], window, buttonLabels[row][col], row, col);
				}
			}
			for (int row = 0; row < buttons.size(); row++) {
				for (int col = 0; col < buttons[row].size(); col++) {
					Assert::IsNotNull(buttons[row][col]);
				}
			}
		}
		TEST_METHOD(buttonVectorParent) //parent
		{
			wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Testing");
			wxButton* button91 = nullptr;
			wxButton* button92 = nullptr;
			wxButton* button93 = nullptr;
			wxButton* button94 = nullptr;
			std::vector<std::vector<std::string>> buttonLabels = { {"test9.1", "test9.2"}, {"test9.3", "test9.4"} };
			std::vector<std::vector<wxButton*>> buttons = { {button91, button92}, {button93, button94} };
			for (int row = 0; row < buttons.size(); row++) {
				for (int col = 0; col < buttons[row].size(); col++) {
					buttons[row][col] = ButtonFactory::createButton(buttons[row][col], window, buttonLabels[row][col], row, col);
				}
			}
			for (int row = 0; row < buttons.size(); row++) {
				for (int col = 0; col < buttons[row].size(); col++) {
					Assert::IsTrue(buttons[row][col]->GetParent() == window);
				}
			}
		}
		TEST_METHOD(buttonVectorLabel) //label
		{
			wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Testing");
			wxButton* button101 = nullptr;
			wxButton* button102 = nullptr;
			wxButton* button103 = nullptr;
			wxButton* button104 = nullptr;
			std::vector<std::vector<std::string>> buttonLabels = { {"test10.1", "test10.2"}, {"test10.3", "test10.4"} };
			std::vector<std::vector<wxButton*>> buttons = { {button101, button102}, {button103, button104} };
			for (int row = 0; row < buttons.size(); row++) {
				for (int col = 0; col < buttons[row].size(); col++) {
					buttons[row][col] = ButtonFactory::createButton(buttons[row][col], window, buttonLabels[row][col], row, col);
				}
			}
			for (int row = 0; row < buttons.size(); row++) {
				for (int col = 0; col < buttons[row].size(); col++) {
					Assert::IsTrue(buttons[row][col]->GetLabel() == buttonLabels[row][col]);
				}
			}
		}
		TEST_METHOD(buttonVectorPosition) //position
		{
			wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Testing");
			wxButton* button111 = nullptr;
			wxButton* button112 = nullptr;
			wxButton* button113 = nullptr;
			wxButton* button114 = nullptr;
			std::vector<std::vector<std::string>> buttonLabels = { {"test11.1", "test11.2"}, {"test11.3", "test11.4"} };
			std::vector<std::vector<wxButton*>> buttons = { {button111, button112}, {button113, button114} };
			for (int row = 0; row < buttons.size(); row++) {
				for (int col = 0; col < buttons[row].size(); col++) {
					buttons[row][col] = ButtonFactory::createButton(buttons[row][col], window, buttonLabels[row][col], row, col);
				}
			}
			for (int row = 0; row < buttons.size(); row++) {
				for (int col = 0; col < buttons[row].size(); col++) {
					Assert::IsTrue(buttons[row][col]->GetPosition() == wxPoint((20 + col * 60), (200 + row * 54))); //numbers from ButtonFactory.h
				}
			}
		}
		TEST_METHOD(buttonVectorSize) //size
		{
			wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Testing");
			wxButton* button121 = nullptr;
			wxButton* button122 = nullptr;
			wxButton* button123 = nullptr;
			wxButton* button124 = nullptr;
			std::vector<std::vector<std::string>> buttonLabels = { {"test12.1", "test12.2"}, {"test12.3", "test12.4"} };
			std::vector<std::vector<wxButton*>> buttons = { {button121, button122}, {button123, button124} };
			for (int row = 0; row < buttons.size(); row++) {
				for (int col = 0; col < buttons[row].size(); col++) {
					buttons[row][col] = ButtonFactory::createButton(buttons[row][col], window, buttonLabels[row][col], row, col);
				}
			}
			for (int row = 0; row < buttons.size(); row++) {
				for (int col = 0; col < buttons[row].size(); col++) {
					Assert::IsTrue(buttons[row][col]->GetSize() == wxSize(40, 40));
				}
			}
		}

	};
}