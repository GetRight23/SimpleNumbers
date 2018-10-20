#include "pch.h"
#include <iostream>
#include <ctime>
#include <memory>

int main() {
	std::shared_ptr<PrimaryNumbersCalculator> calculatorDivider { new DividersEnumeration() };
	std::shared_ptr<PrimaryNumbersCalculator> calculatorEratosthenes { new EratosthenesSieve(1000000) };
	std::shared_ptr<PrimaryNumbersCalculator> calculatorAtkins { new AtkinsSieve(1000000) };

	time_t dividerStart = clock();
	calculatorDivider->isPrimeInRange(0, 1000000);
	time_t dividerEnd = clock();

	time_t eratosthenesStart = clock();
	calculatorEratosthenes->isPrimeInRange(0, 1000000);
	time_t eratosthenesEnd = clock();

	time_t atkinsStart = clock();
	calculatorAtkins->isPrimeInRange(0, 1000000);
	time_t atkinsEnd = clock();


	std::cout << "DividersEnumeration time: " << float(dividerEnd - dividerStart) / (float)CLOCKS_PER_SEC << std::endl;
	std::cout << "EratosthenesSieve time: " << float(eratosthenesEnd - eratosthenesStart) / (float)CLOCKS_PER_SEC << std::endl;
	std::cout << "AtkinsSieve time: " << float(atkinsEnd - atkinsStart) / (float)CLOCKS_PER_SEC << std::endl;

	std::cin.get();
	return 0;
}