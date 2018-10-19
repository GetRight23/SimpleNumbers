#ifndef ERATOSTHENES_SIEVE_H
#define ERATOSTHENES_SIEVE_H

#include <list>
#include <vector>
#include <cstdint>

class EratosthenesSieve {

	private:
		static std::vector<bool> m_sieve;

	public:
		EratosthenesSieve(size_t n);
		EratosthenesSieve();

		template<class T> bool isPrime(T number);
		template<class T> std::list<T> isPrimeInRange(T begin, T end);

		template<> bool isPrime<float>(float number);
		template<> bool isPrime<double>(double number);

	private:
		void recalculate(size_t n);
};

template<class T> std::list<T> EratosthenesSieve::isPrimeInRange(T begin,T end) {
	std::list<T> result;

	if (begin > end) {
		throw WrongBounds();
	}
		
	if ((size_t)end > m_sieve.size()) {
		recalculate(end);
	}

	for (T i = begin; i < end; ++i) {

		if (isPrime(i) == true) {
			result.push_back(i);
		}

	}

	return result;
}

template<class T> bool EratosthenesSieve::isPrime(T number) {
	if ((size_t)number > m_sieve.size()) {
		recalculate((size_t)number);
	}

	return m_sieve[number];
}

//exceptions
template<> bool EratosthenesSieve::isPrime<float>(float number) {
	(void)number;
	return false;
}

template<> bool EratosthenesSieve::isPrime<double>(double number) {
	(void)number;
	return false;
}

#endif//ERATOSTHENES_SIEVE_H