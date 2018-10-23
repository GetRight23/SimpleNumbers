#include "WrongBoundsException.h"

WrongBoundsException::WrongBoundsException() : std::logic_error("Lower bound(begin) is bigger than upper bound(end)") {}