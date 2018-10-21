#ifndef DIVIDERS_ENUMERATION_H
#define DIVIDERS_ENUMERATION_H

#include <list>
#include "PrimaryNumbersCalculator.h"

class DividersEnumeration : public PrimaryNumbersCalculator {
	public:
		bool isPrime(size_t number) override;
		std::list<size_t> isPrimeInRange(size_t begin, size_t end) override;

};

#endif//DIVIDERS_ENUMERATION_H