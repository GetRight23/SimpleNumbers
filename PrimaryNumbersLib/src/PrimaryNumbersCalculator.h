#ifndef PRIMARY_NUMBERS_CALCULATOR_H
#define PRIMARY_NUMBERS_CALCULATOR_H

#include <list>

class PrimaryNumbersCalculator {
	public:
		virtual ~PrimaryNumbersCalculator() {}

		virtual bool isPrime(size_t number) = 0;
		virtual std::list<size_t> isPrimeInRange(size_t begin, size_t end) = 0;
};

#endif//PRIMARY_NUMBERS_CALCULATOR_H