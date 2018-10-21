#include "pch.h"
#include "PrimaryNumbersApp.h"

PrimaryNumbersApp::PrimaryNumbersApp() : m_configuration("demo.xml") {}

void PrimaryNumbersApp::exec() {
	//std::shared_ptr<PrimaryNumbersCalculator> calculatorDivider{ new DividersEnumeration() };	
	//std::shared_ptr<PrimaryNumbersCalculator> calculatorAtkins{ new AtkinsSieve(1000000) };
	//we can use different algorithms

	std::shared_ptr<PrimaryNumbersCalculator> calculatorEratosthenes{ new EratosthenesSieve(1000000) };
	std::vector<std::pair<size_t, size_t>> bounds = m_configuration.getBounds();

	for (size_t i = 0; i < bounds.size(); i++) {
		m_threadVector.push_back(std::thread{ m_calculator, std::ref(calculatorEratosthenes), std::ref(m_list), bounds[i].first, bounds[i].second });
	}

	for (size_t i = 0; i < m_threadVector.size(); i++) {
		m_threadVector[i].join();
	}

	std::list<size_t> result = m_list.getList();
	result.sort();

	m_configuration.writeToFile(m_list.getList(), "primes.xml");
}