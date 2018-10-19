#ifndef WRONG_TYPE_H
#define WRONG_TYPE_H

#include <exception>

class WrongType : public std::exception {

	public:
		const char* what() const override;

};

#endif//WRONG_TYPE_H

