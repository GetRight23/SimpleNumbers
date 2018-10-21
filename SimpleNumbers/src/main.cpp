#include "pch.h"
#include <iostream>
#include "PrimaryNumbersApp.h"

int main() {
	try {
		PrimaryNumbersApp app;
		app.exec();
	}
	catch (std::bad_alloc& ex) {
		exit(-1);
	}
	catch (std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		system("pause");
	}

	return 0;
}