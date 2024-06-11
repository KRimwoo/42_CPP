#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

#define ARGUMENT_ERROR 5

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static int checkType(const std::string &input);

	static void printChar(const std::string &input);
	static void printInt(const std::string &input);
	static void printFloat(const std::string &input);
	static void printDouble(const std::string &input);
	static void printImpossible(const std::string &input);
public:
	static void convert(const std::string &input);
	
};

#endif