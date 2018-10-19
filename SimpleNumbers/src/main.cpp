#include "pch.h"
#include <iostream>

int main() {
	PrimaryNumbersHandler *handler = new EratosthenesSieve;
	std::list<size_t> res;

	try {
		res = handler->isPrimeInRange(100, 200);
	}
	catch (WrongBounds exception) {
		std::cout << "Wrong bounds(line:" << __LINE__ << ") (file:"<< __FILE__ << ")" << std::endl;
	}
	
	for (auto var : res) {
		std::cout << var << " ";
	}

	delete handler;
	std::cin.get();
	return 0;
}