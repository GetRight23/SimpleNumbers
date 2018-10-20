#ifndef ATKINS_SIEVE_H
#define ATKINS_SIEVE_H

#include <list>
#include <vector>
#include "SieveCalculator.h"

class AtkinsSieve : public SieveCalculator {
	private:
		std::vector<uint8_t> m_sieve;

	public:
		AtkinsSieve(size_t limit);

		bool isPrime(size_t number) override;
		void recalculate(size_t limit) override;
};

#endif//ATKINS_SIEVE_H