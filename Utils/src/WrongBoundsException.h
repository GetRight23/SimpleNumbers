#ifndef WRONG_BOUNDS_H
#define WRONG_BOUNDS_H

#include <stdexcept>

class WrongBoundsException : public std::logic_error {
	public:
		WrongBoundsException();

};

#endif//WRONG_BOUNDS_H