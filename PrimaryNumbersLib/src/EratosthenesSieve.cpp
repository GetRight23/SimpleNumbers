#include "pch.h"
#include "EratosthenesSieve.h"

EratosthenesSieve::EratosthenesSieve(size_t limit) {
	recalculate(limit);
}

bool EratosthenesSieve::isPrime(size_t number) {
	return m_sieve[number];
}

std::list<size_t> EratosthenesSieve::isPrimeInRange(size_t begin, size_t end) {
	std::list<size_t> result;

	if (begin > end) {
		throw WrongBounds();
	}

	if (end > m_sieve.size()) {
		recalculate(end);
	}

	for (size_t i = begin; i < end; ++i) {

		if (isPrime(i) == true) {
			result.push_back(i);
		}

	}

	return result;
}

void EratosthenesSieve::recalculate(size_t limit) {
	m_sieve.resize(limit + 1, true);
	m_sieve[0] = 0;
	m_sieve[1] = 0;

	for (size_t i = 2; i <= limit; ++i) {

		if (m_sieve[i] == 1) {

			if (i * i <= limit) {

				for (size_t j = i * i; j <= limit; j += i) {
					m_sieve[j] = 0;
				}

			}

		}
	}
}