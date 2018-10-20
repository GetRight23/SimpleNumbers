#include "pch.h"

#include <memory>
#include <thread>
#include <iostream>

void calculate(const std::shared_ptr<PrimaryNumbersCalculator>& calc, SharedList<size_t>& list, size_t begin, size_t end) {
	std::list<size_t> result = calc.get()->isPrimeInRange(begin, end);

	for (auto value : result) {
		if (list.listContains(value) == false) {
			list.addToList(value);
		}		
	}
}

int main() {
	SharedList<size_t> list;

	std::shared_ptr<PrimaryNumbersCalculator> calculatorDivider{ new DividersEnumeration() };
	std::shared_ptr<PrimaryNumbersCalculator> calculatorEratosthenes{ new EratosthenesSieve(1000000) };
	std::shared_ptr<PrimaryNumbersCalculator> calculatorAtkins{ new AtkinsSieve(1000000) };

	std::thread t1(calculate, std::ref(calculatorDivider), std::ref(list), 100, 200);
	std::thread t2(calculate, std::ref(calculatorEratosthenes), std::ref(list), 0, 200);
	std::thread t3(calculate, std::ref(calculatorAtkins), std::ref(list), 188, 888);

	
	std::vector<std::thread> threadVector;
	threadVector.push_back(std::thread{ calculate, std::ref(calculatorDivider), std::ref(list), 100, 200 });
	threadVector.push_back(std::thread{ calculate, std::ref(calculatorEratosthenes), std::ref(list),0, 200 });
	threadVector.push_back(std::thread{ calculate, std::ref(calculatorAtkins), std::ref(list), 188, 888 });

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