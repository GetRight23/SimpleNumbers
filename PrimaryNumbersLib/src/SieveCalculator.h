#ifndef SIEVE_CALCULATOR_H
#define SIEVE_CALCULATOR_H

#include <vector>
#include "PrimaryNumbersCalculator.h"


class SieveCalculator : public PrimaryNumbersCalculator {
	private:
		std::vector<uint8_t> m_sieve;

	public:
		std::list<size_t> isPrimeInRange(size_t begin, size_t end) override;
		virtual void recalculate(size_t n) = 0;
};

#endif //SIEVE_CALCULATOR_H