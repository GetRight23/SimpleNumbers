#ifndef WRONG_CONFIGURATION_EXCEPTION_H
#define WRONG_CONFIGURATION_EXCEPTION_H

#include <stdexcept>

class WrongConfigurationException : public std::runtime_error {
	public:
		WrongConfigurationException();
};

#endif//WRONG_CONFIGURATION_EXCEPTION_H