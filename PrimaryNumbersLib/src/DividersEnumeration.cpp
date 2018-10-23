#include "pch.h"
#include "DividersEnumeration.h"

bool DividersEnumeration::isPrime(size_t number) {
	if (number == 1 || number == 0) {
		return false;
	}

	for (size_t i = 2; i * i <= number; ++i) {

		if (number % i == 0) {
			return false;
		}

	}
	return true;
}

std::list<size_t> DividersEnumeration::isPrimeInRange(size_t begin, size_t end) {
	std::list<size_t> result;

	if (begin > end) {
		throw WrongBoundsException();
	}

	for (size_t i = begin; i < end; ++i) {

		if (isPrime(i) == true) {
			result.push_back(i);
		}

	}

	return result;
}