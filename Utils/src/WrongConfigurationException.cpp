#include "WrongConfigurationException.h"

WrongConfigurationException::WrongConfigurationException() : std::runtime_error("invalid configuration") {}
