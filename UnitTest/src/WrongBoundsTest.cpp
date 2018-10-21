#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(WrongBoundsTest) {

		public:
			TEST_METHOD(WrongBoundsWhatsTest) {
				WrongBounds wrongBounds;	
				Assert::AreEqual(wrongBounds.what(), "Lower bound(begin) is bigger than upper bound(end)");
			}
	};
}