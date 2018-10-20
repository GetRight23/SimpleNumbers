#include "pch.h"
#include <memory>
#include <thread>
#include <iostream>
#include "MultithreadCalculation.h"

int main() {
	SharedList<size_t> list;

	std::shared_ptr<PrimaryNumbersCalculator> calculatorDivider{ new DividersEnumeration() };
	std::shared_ptr<PrimaryNumbersCalculator> calculatorEratosthenes{ new EratosthenesSieve(1000000) };
	std::shared_ptr<PrimaryNumbersCalculator> calculatorAtkins{ new AtkinsSieve(1000000) };
	
	std::vector<std::thread> threadVector;
	MultithreadCalculation calculator;
		
	threadVector.push_back(std::thread{ calculator, std::ref(calculatorDivider), std::ref(list), 100, 200 });
	threadVector.push_back(std::thread{ calculator, std::ref(calculatorEratosthenes), std::ref(list), 0, 200 });
	threadVector.push_back(std::thread{ calculator, std::ref(calculatorAtkins), std::ref(list), 188, 888 });

	for (size_t i = 0; i < threadVector.size(); i++) {
		threadVector[i].join();
	}

	std::list<size_t> result = list.getList();
	result.sort();

	for (auto value : result) {
		std::cout << value << " ";
	}

	std::cin.get();
	return 0;
}