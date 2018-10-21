#ifndef ERATOSTHENES_SIEVE_H
#define ERATOSTHENES_SIEVE_H

#include <list>
#include <vector>
#include "SieveCalculator.h"

class EratosthenesSieve : public SieveCalculator {
	public:
		EratosthenesSieve(size_t limit);
		void recalculate(size_t n) override;

};

#endif//ERATOSTHENES_SIEVE_H