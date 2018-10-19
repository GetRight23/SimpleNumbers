#include "pch.h"
#include "EratosthenesSieve.h"

std::vector<bool> EratosthenesSieve::m_sieve;

EratosthenesSieve::EratosthenesSieve() {}

EratosthenesSieve::EratosthenesSieve(size_t n) {
	recalculate(n);
}

bool EratosthenesSieve::isPrime(size_t number) {
	if ((size_t)number > m_sieve.size()) {
		recalculate((size_t)number);
	}

	return m_sieve[number];
}
std::list<size_t> EratosthenesSieve::isPrimeInRange(size_t begin, size_t end) {
	std::list<size_t> result;

	if (begin > end) {
		throw WrongBounds();
	}

	if ((size_t)end > m_sieve.size()) {
		recalculate(end);
	}

	for (size_t i = begin; i < end; ++i) {

		if (isPrime(i) == true) {
			result.push_back(i);
		}

	}

	return result;
}

void EratosthenesSieve::recalculate(size_t n) {
	m_sieve.resize(n + 1, true);
	m_sieve[0] = m_sieve[1] = false;
	for (size_t i = 2; i <= n; ++i) {

		if (m_sieve[i] == true) {

			if (i * i <= n) {

				for (size_t j = i * i; j <= n; j += i) {
					m_sieve[j] = false;
				}

			}

		}
	}
}