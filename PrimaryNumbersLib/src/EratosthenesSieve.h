#ifndef ERATOSTHENES_SIEVE_H
#define ERATOSTHENES_SIEVE_H

#include <list>
#include <vector>
#include "SieveCalculator.h"

class EratosthenesSieve : public SieveCalculator {
	private:
		std::vector<uint8_t> m_sieve;

	public:
		EratosthenesSieve(size_t limit);

		bool isPrime(size_t number) override;
		void recalculate(size_t n) override;
};

#endif//ERATOSTHENES_SIEVE_H