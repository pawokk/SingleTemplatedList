#include "pch.h"
#include "CppUnitTest.h"
#include"..//Project1/list.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DeckTest
{
	TEST_CLASS(DeckTest)
	{
	public:
		
		TEST_METHOD(DeckCopyConstructorSuccess)
		{
			Deck<int> d1;

			d1.pushBack(2);
			d1.pushBack(3);
			Deck<int> d2(d1);
			bool AreEqual = d1 == d2;
			
			
			Assert::IsTrue(AreEqual);
		}
		TEST_METHOD(DeckCopyOperatorSuccess)
		{
			Deck<int> d1;

			d1.pushBack(2);
			d1.pushBack(3);
			Deck<int> d2 = d1;
			bool AreEqual = d1 == d2;


			Assert::IsTrue(AreEqual);
		}
		TEST_METHOD(DeckPushBackSuccess)
		{
			Deck<int> d1;

			d1.pushBack(2);
			d1.pushBack(3);
			std::string realstring = d1.tostring();
			std::string Expstring = "2 3 ";
			bool AreEqual = realstring == Expstring;
			
			Assert::IsTrue(AreEqual);
		}
		TEST_METHOD(DeckIsEmptySuccess)
		{
			Deck<int> d1;

			d1.pushBack(2);
			d1.pushBack(3);
			
			bool isEmpty = d1.isempty();

			Assert::IsFalse(isEmpty);
		}
		TEST_METHOD(DeckComparisonOperatorSuccess)
		{
			Deck<int> d1;
			Deck<int> d2;
			d1.pushBack(2);
			d1.pushBack(3);
			d2.pushBack(2);
			d2.pushBack(3);
			bool AreEqual = d1== d2;

			Assert::IsTrue(AreEqual);
		}
		TEST_METHOD(DeckPopSuccess)
		{
			Deck<int> d1;
			Deck<int> d2;
			d1.pushBack(2);
			d1.pushBack(3);
			d2.pushBack(2);
			d2.pushBack(3);
			d2.pop();
			bool AreEqual = d1 == d2;

			Assert::IsFalse(AreEqual);
		}
		TEST_METHOD(DeckPeekFrontSuccess)
		{
			Deck<int> d1;
			d1.pushBack(3);
			d1.pushBack(5);
			int fr = d1.peekFront();
			bool AreEqual = fr == 3;

			Assert::IsTrue(AreEqual);
		}
		TEST_METHOD(DeckPeekBackSuccess)
		{
			Deck<int> d1;
			d1.pushBack(3);
			d1.pushBack(5);
			int fr = d1.peekBack();
			bool AreEqual = fr == 5;

			Assert::IsTrue(AreEqual);
		}
	};
}
