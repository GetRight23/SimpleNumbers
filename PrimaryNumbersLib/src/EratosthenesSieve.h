#ifndef ERATOSTHENES_SIEVE_H
#define ERATOSTHENES_SIEVE_H

#include "pch.h"

#include <list>
#include <vector>
#include <cstdint>

#include "PrimaryNumbersHandler.h"

class EratosthenesSieve : public PrimaryNumbersHandler {
	private:
		static std::vector<bool> m_sieve;

	public:
		EratosthenesSieve();
		EratosthenesSieve(size_t n);

		bool isPrime(size_t number) override;
		std::list<size_t> isPrimeInRange(size_t begin, size_t end) override;

	private:
		void recalculate(size_t n);
};

#endif//ERATOSTHENES_SIEVE_H