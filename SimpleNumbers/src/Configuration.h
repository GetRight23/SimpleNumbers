#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>
#include <vector>
#include <regex>
#include <iterator>
#include <fstream>
#include <sstream>
#include <exception>
#include <iostream>
#include <list>

class Configuration {
	private:
		std::vector<std::pair<size_t, size_t>> bounds;

	public:
		Configuration(std::string fileName = "demo.xml");
		std::vector<std::pair<size_t, size_t>> getBounds() { return bounds; };
		void writeToFile(std::list<size_t> numbers, std::string outputPath = "primes.xml");

	private:
		void loadFile(std::string fileName);

};
#endif //CONFIGURATION_H