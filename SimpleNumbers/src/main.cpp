#include "pch.h"
#include <memory>
#include <thread>
#include <iostream>
#include "MultithreadCalculation.h"
#include "Configuration.h"

int main() {
	SharedList<size_t> list;

	std::shared_ptr<PrimaryNumbersCalculator> calculatorEratosthenes{ new EratosthenesSieve(1000000) };
	//std::shared_ptr<PrimaryNumbersCalculator> calculatorDivider{ new DividersEnumeration() };	
	//std::shared_ptr<PrimaryNumbersCalculator> calculatorAtkins{ new AtkinsSieve(1000000) };
	//we can use different algorithms
	
	std::vector<std::thread> threadVector;
	MultithreadCalculation calculator;

	Configuration conf;
	std::vector<std::pair<int, int>> bounds = conf.getBounds();

	for (size_t i = 0; i < bounds.size(); i++) {
		threadVector.push_back(std::thread{ calculator, std::ref(calculatorEratosthenes), std::ref(list), bounds[i].first, bounds[i].second });
	}

	for (size_t i = 0; i < threadVector.size(); i++) {
		threadVector[i].join();
	}

	std::list<size_t> result = list.getList();
	result.sort();

	conf.writeToFile(list.getList());

	return 0;
}