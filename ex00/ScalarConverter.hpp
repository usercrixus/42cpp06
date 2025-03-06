#ifndef SCALAR
#define SCALAR

#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <iomanip>

class ScalarConverter
{
private:
	/* data */
public:
	ScalarConverter();
	~ScalarConverter();

	static void convert(const std::string &s);
};

#endif