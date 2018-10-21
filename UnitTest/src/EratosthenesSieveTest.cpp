#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(EratosthenesSieveTest) {
		private:
			const size_t sieveSize = 1000;

		public:

			TEST_METHOD(EratosthenesSievePrimaryTest) {
				size_t number = 2;
				EratosthenesSieve sieve(sieveSize);
				Assert::AreEqual(sieve.isPrime(number), true);
			}

			TEST_METHOD(EratosthenesSieveNotPrimaryTest) {
				size_t number = 4;
				EratosthenesSieve sieve(sieveSize);
				Assert::AreEqual(sieve.isPrime(number), false);
			}

			TEST_METHOD(EratosthenesSieveZeroTest) {
				size_t number = 0;
				EratosthenesSieve sieve(sieveSize);
				Assert::AreEqual(sieve.isPrime(number), false);
			}

			TEST_METHOD(EratosthenesSieveOneTest) {
				size_t number = 1;
				EratosthenesSieve sieve(sieveSize);
				Assert::AreEqual(sieve.isPrime(number), false);
			}

			TEST_METHOD(EratosthenesSieveBiggerThenTableSieTest) {
				size_t number = 1009;
				EratosthenesSieve sieve(sieveSize);
				Assert::AreEqual(sieve.isPrime(number), true);
			}
	};
}