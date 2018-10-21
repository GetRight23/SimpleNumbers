#ifndef PRIMARY_NUMBERS_APP_H
#define PRIMARY_NUMBERS_APP_H

#include "MultithreadCalculation.h"
#include "Configuration.h"

class PrimaryNumbersApp {
	private:
		SharedList<size_t> m_list;
		MultithreadCalculation m_calculator;
		Configuration m_configuration;
		std::vector<std::thread> m_threadVector;
		
	public:
		PrimaryNumbersApp();
		void exec();

};

#endif //PRIMARY_NUMBERS_APP_H