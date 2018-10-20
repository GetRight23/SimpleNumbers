#ifndef ATKINS_SIEVE_H
#define ATKINS_SIEVE_H

#include <list>
#include <vector>
#include "PrimaryNumbersCalculator.h"

class AtkinsSieve : public PrimaryNumbersCalculator {
	private:
		std::vector<uint8_t> m_sieve;

	public:
		AtkinsSieve(size_t limit);

		bool isPrime(size_t number) override;
		std::list<size_t> isPrimeInRange(size_t begin, size_t end) override;
		void recalculate(size_t limit);
};

#endif//ATKINS_SIEVE_H