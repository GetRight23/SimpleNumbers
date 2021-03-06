#ifndef ATKINS_SIEVE_H
#define ATKINS_SIEVE_H

#include <list>
#include <vector>
#include "SieveCalculator.h"

class AtkinsSieve : public SieveCalculator {
	public:
		AtkinsSieve(size_t limit);
		void recalculate(size_t limit) override;

};

#endif//ATKINS_SIEVE_H