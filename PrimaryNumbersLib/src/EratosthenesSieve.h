#ifndef ERATOSTHENES_SIEVE_H
#define ERATOSTHENES_SIEVE_H

#include <list>
#include <vector>
#include "PrimaryNumbersCalculator.h"

class EratosthenesSieve : public PrimaryNumbersCalculator {
	private:
		std::vector<uint8_t> m_sieve;

	public:
		EratosthenesSieve(size_t limit);

		bool isPrime(size_t number) override;
		std::list<size_t> isPrimeInRange(size_t begin, size_t end) override;
		void recalculate(size_t n);
};

#endif//ERATOSTHENES_SIEVE_H