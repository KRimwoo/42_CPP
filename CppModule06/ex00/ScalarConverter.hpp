#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:
	std::string _input;
	ScalarConverter();
public:
	ScalarConverter(std::string input);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
	
	void convert();

	void toChar();
	void toInt();
	void toFloat();
	void toDouble();

	
};

#endif