#include "pch.h"
#include "SieveCalculator.h"

bool SieveCalculator::isPrime(size_t number) {
	if (number > m_sieve.size()) {
		recalculate(number);
	}
	return m_sieve[number];
}

std::list<size_t> SieveCalculator::isPrimeInRange(size_t begin, size_t end) {
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
