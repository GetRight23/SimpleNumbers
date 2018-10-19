#ifndef PRIMARY_NUMBERS_HANDLER_H
#define PRIMARY_NUMBERS_HANDLER_H

#include <list>

class PrimaryNumbersHandler {
	public:
		virtual bool isPrime(size_t number) = 0;
		virtual std::list<size_t> isPrimeInRange(size_t begin, size_t end) = 0;
};

#endif//PRIMARY_NUMBERS_HANDLER_H