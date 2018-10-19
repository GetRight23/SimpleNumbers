#include "WrongType.h"

const char* WrongType::what() const {
	return "Your type is not supported";
}