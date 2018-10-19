#include "WrongBounds.h"

const char* WrongBounds::what() const {
	return "Lower bound(begin) is bigger than upper bound(end)";
}