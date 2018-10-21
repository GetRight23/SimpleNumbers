#ifndef MULTITHREAD_CALCULATION_H
#define MULTITHREAD_CALCULATION_H

#include <memory>

class MultithreadCalculation {
	public:
		void operator()(const std::shared_ptr<PrimaryNumbersCalculator>& calc, SharedList<size_t>& list, size_t begin, size_t end);	

};

#endif //MULTITHREAD_CALCULATION_H