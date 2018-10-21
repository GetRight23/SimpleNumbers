#ifndef SIEVE_CALCULATOR_H
#define SIEVE_CALCULATOR_H

#include <vector>
#include "PrimaryNumbersCalculator.h"


class SieveCalculator : public PrimaryNumbersCalculator {
	protected:
		std::vector<uint8_t> m_sieve;

	public:
		bool isPrime(size_t number) override;
		std::list<size_t> isPrimeInRange(size_t begin, size_t end) override;		
		virtual void recalculate(size_t n) = 0;

};

#endif //SIEVE_CALCULATOR_H