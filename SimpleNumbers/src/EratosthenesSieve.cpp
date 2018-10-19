#include "EratosthenesSieve.h"

std::vector<bool> EratosthenesSieve::m_sieve;

EratosthenesSieve::EratosthenesSieve() {}

EratosthenesSieve::EratosthenesSieve(size_t n) {
	recalculate(n);
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