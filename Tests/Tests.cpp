#include "pch.h"
#include "CppUnitTest.h"
#include "../List/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(ToString_ValidData_Success)
		{
			//arrange
			DoublyLinkedList<int> list1 = { 1, 2, 3 };

			//act & assert
			Assert::IsTrue(list1.toString() == "1 2 3 ");
		}

		TEST_METHOD(LeftShiftOperator_ValidData_Success)
		{
			//arrange
			DoublyLinkedList<int> list1 = { 1, 2, 3 };

			//act
			list1 << 4;

			//assert
			Assert::IsTrue(list1.toString() == "1 2 3 4 ");
		}

		TEST_METHOD(RightShiftOperator_ValidData_Success)
		{
			//arrange
			DoublyLinkedList<int> list1 = { 1, 2, 3 };
			
			//act
			list1 >> 2;

			//assert
			Assert::IsTrue(list1.toString() == "2 3 ");
		}

		TEST_METHOD(IsEmpty_ValidData_Success)
		{
			//arrange
			DoublyLinkedList<int> list1 = {};

			//act & assert
			Assert::IsTrue(list1.isEmpty());
		}
	};
}
