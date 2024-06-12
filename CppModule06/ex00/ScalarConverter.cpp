#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}


int ScalarConverter::checkType(const std::string &input)
{
	char *endptr = NULL;

	if (input == "inff" || input == "+inff" || input == "-inff" || input == "nanf")
		return FLOAT;
	if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan")
		return DOUBLE;

	if (input.length() == 1 && (input[0] < '0' || input[0] > '9'))
		return CHAR;

	errno = 0;
	long int li = strtol(input.c_str(), &endptr, 10);

	if (errno != ERANGE && li <= INT_MAX && li >= INT_MIN && *endptr == '\0')
		return INT;

	errno = 0;
	strtof(input.c_str(), &endptr);
	if (errno != ERANGE && std::strcmp(endptr, "f") == 0)
		return FLOAT;

	errno = 0;
	strtod(input.c_str(), &endptr);
	if (errno != ERANGE) {
		if (std::strcmp(endptr, "f") == 0)
			return FLOAT;
		if (*endptr == '\0')
			return DOUBLE;
	}
	return ARGUMENT_ERROR;
}


void ScalarConverter::convert(const std::string &input)
{
	int type = checkType(input);

	switch (type)
	{
	case CHAR:
		printChar(input);
		break;
	case INT:
		printInt(input);
		break;
	case FLOAT:
		printFloat(input);
		break;
	case DOUBLE:
		printDouble(input);
		break;
	case ARGUMENT_ERROR:
		printError();
		break;
	default:
		break;
	}
}

void ScalarConverter::printChar(const std::string &input)
{
	char c = input[0];
	if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::printInt(const std::string &input)
{
	int i = std::atoi(input.c_str());

	std::cout << "char: ";
	if (i < 32 || i > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::printFloat(const std::string &input)
{
	float f = std::strtof(input.c_str(), NULL);
	char c = static_cast<char>(f);
	long l = std::strtol(input.c_str(), NULL, 10);
	//int i = static_cast<int>(f); ????
	int i = static_cast<int>(l);
	double d = static_cast<double>(f);

	if (input == "inff" || input == "+inff" || input == "-inf" 
		|| input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "char: ";
		if (l > 2147483647 || l < -2147483648)
			std::cout << "impossible" << std::endl;
		else if (c < 32 || c > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;

		std::cout << "int: ";
		if (l > 2147483647 || l < -2147483648)
			std::cout << "impossible" << std::endl;
		else
			std::cout << i << std::endl;
	}
	if (f - i == 0) {
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else {
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void ScalarConverter::printDouble(const std::string &input)
{
	double d = std::strtod(input.c_str(), NULL);

	char c = static_cast<char>(d);
	long l = static_cast<long>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "char: ";
		if (l > 2147483647 || l < -2147483648)
			std::cout << "impossible" << std::endl;
		else if (c < 32 || c > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
		std::cout << "int: ";
		if (l > 2147483647 || l < -2147483648)
			std::cout << "impossible" << std::endl;
		else
			std::cout << i << std::endl;
	}
	if (d - i == 0) {
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else {
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void ScalarConverter::printError()
{
	std::cout << "Error: invalid argument" << std::endl;
}
