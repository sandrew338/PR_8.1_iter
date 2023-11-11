
#include "pch.h"
#include "CppUnitTest.h"
#include "../main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[3] = "++";
			Assert::AreEqual(QuantityOfSymb(str, '+'), 2);
		}
	};
}
