#include <iostream>

#include "EratosthenesSieve.h"

int main() {
	EratosthenesSieve sieve;
	std::list<int> res;
	try {
		res = sieve.isPrimeInRange(100, 200);
	}
	catch (WrongBounds exception) {
		std::cout << "Wrong bounds(line:" << __LINE__ << ") (file:"<< __FILE__ << ")" << std::endl;
	}
	
	for (auto var : res) {
		std::cout << var << " ";
	}

	std::cin.get();
	return 0;
}