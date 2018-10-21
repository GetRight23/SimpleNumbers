#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {		
	TEST_CLASS(AtkinsSieveTest) {
		private:
			const size_t sieveSize = 1000;

		public:
		
			TEST_METHOD(AtkinsSievePrimaryTest) {
				size_t number = 2;
				AtkinsSieve sieve(sieveSize);
				Assert::AreEqual(sieve.isPrime(number), true);
			}

			TEST_METHOD(AtkinsSieveNotPrimaryTest) {
				size_t number = 4;
				AtkinsSieve sieve(sieveSize);
				Assert::AreEqual(sieve.isPrime(number), false);
			}

			TEST_METHOD(AtkinsSieveZeroTest) {
				size_t number = 0;
				AtkinsSieve sieve(sieveSize);
				Assert::AreEqual(sieve.isPrime(number), false);
			}

			TEST_METHOD(AtkinsSieveOneTest) {
				size_t number = 1;
				AtkinsSieve sieve(sieveSize);
				Assert::AreEqual(sieve.isPrime(number), false);
			}

			TEST_METHOD(AtkinsSieveBiggerThenTableSieTest) {
				size_t number = 1009;
				AtkinsSieve sieve(sieveSize);
				Assert::AreEqual(sieve.isPrime(number), true);
			}
	};
}