#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &s)
{
	char *end;

	// ** Handle special floating-point values **
	if (s == "nan" || s == "nanf") {
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (s == "inf" || s == "+inf" || s == "-inf" || s == "inff" || s == "+inff" || s == "-inff") {
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: " << s << "f" << std::endl;
		std::cout << "double: " << s << std::endl;
		return;
	}

	// ** Check if input is an integer **
	long i = std::strtol(s.c_str(), &end, 10);
	if (*end == '\0') {  // If conversion is fully successful
		if (std::isprint(i))
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
		return;
	}

	// ** Handle floating-point conversion **
	std::string cleanStr = s;
	if (cleanStr[cleanStr.length() - 1] == 'f') {
		cleanStr = cleanStr.substr(0, cleanStr.length() - 1);  // Remove 'f'
	}

	double d = std::strtod(cleanStr.c_str(), &end);
	if (*end == '\0') {  // Ensure full conversion
		if (std::isprint(static_cast<int>(d)))
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char: Impossible" << std::endl;

		if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		else
			std::cout << "int: Impossible" << std::endl;

		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	} else {
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: Impossible" << std::endl;
		std::cout << "double: Impossible" << std::endl;
	}
}
