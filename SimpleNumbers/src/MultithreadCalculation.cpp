#include "pch.h"
#include "MultithreadCalculation.h"

void MultithreadCalculation::operator()(const std::shared_ptr<PrimaryNumbersCalculator>& calc, SharedList<size_t>& list, size_t begin, size_t end) {
	std::list<size_t> result = calc.get()->isPrimeInRange(begin, end);

	for (auto value : result) {
		if (list.listContains(value) == false) {
			list.addToList(value);
		}
	}
}

