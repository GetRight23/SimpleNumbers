#ifndef WRONG_BOUNDS_H
#define WRONG_BOUNDS_H

#include <exception>

class WrongBounds : public std::exception {
	public:
		const char* what() const override;
};

#endif//WRONG_BOUNDS_H