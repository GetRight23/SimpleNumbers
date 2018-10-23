#include "pch.h"
#include "Configuration.h"

Configuration::Configuration(std::string fileName) {
	loadFile(fileName);
}

void Configuration::loadFile(std::string fileName) {
	try {
		std::ifstream s(fileName);
		std::stringstream ss;
		ss << s.rdbuf();
		s.close();

		std::string xml = ss.str();

		std::regex re("<interval>\\s*<low>(\\d+)</low>\\s*<high>(\\d+)</high>\\s*</interval>", std::regex::ECMAScript);

		std::sregex_iterator next(xml.begin(), xml.end(), re);
		std::sregex_iterator end;
		while (next != end) {
			std::smatch match = *next;
			std::pair <size_t, size_t> pr;
			size_t low = std::stoi(match[1]);
			size_t high = std::stoi(match[2]);
			try {
				if (low > high) {
					throw WrongBoundsException();
				}				
				pr = std::make_pair(std::stoi(match[1]), std::stoi(match[2]));
				bounds.push_back(pr);	
			}
			catch (WrongBoundsException& ex) {
				std::cerr << ex.what() << std::endl;
			}
			next++;
		}
	}
	catch (std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		throw;
	}

	if (bounds.size() == 0) {
		throw WrongConfigurationException();
	}

}

void Configuration::writeToFile(std::list<size_t> numbers, std::string outputPath) {
	std::ofstream outfile(outputPath, std::ios_base::out);
	if (!outfile.is_open()) {
		throw std::exception("File is not open");
	}

	outfile << "<root>" << std::endl;
	outfile << "\t<primes>";
	for (auto number : numbers) {
		outfile << " " << std::to_string(number) << " ";
	}
	outfile << "<primes>\n";
	outfile << "<root>";

	outfile.close();
}