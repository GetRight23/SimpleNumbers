#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(DividersEnumerationTest) {
		public:

			TEST_METHOD(DividersEnumerationPrimaryTest) {
				size_t number = 2;
				DividersEnumeration sieve;
				Assert::AreEqual(sieve.isPrime(number), true);
			}

			TEST_METHOD(DividersEnumerationNotPrimaryTest) {
				size_t number = 4;
				DividersEnumeration sieve;
				Assert::AreEqual(sieve.isPrime(number), false);
			}

			TEST_METHOD(DividersEnumerationZeroTest) {
				size_t number = 0;
				DividersEnumeration sieve;
				Assert::AreEqual(sieve.isPrime(number), false);
			}

			TEST_METHOD(DividersEnumerationOneTest) {
				size_t number = 1;
				DividersEnumeration sieve;
				Assert::AreEqual(sieve.isPrime(number), false);
			}
	};
}