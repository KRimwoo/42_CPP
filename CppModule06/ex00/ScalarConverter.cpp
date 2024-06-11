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
	if (errno != ERANGE && *endptr == '\0')
		return DOUBLE;

	return ARGUMENT_ERROR;
}


void ScalarConverter::convert(const std::string &input)
{
	int type = checkType(input);

	std::cout << "type: " << type << std::endl;
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
		printImpossible(input);
		break;
	default:
		break;
	}


	//char *endptr = NULL;
	//double doubleValue = 0.0;
	
	//std::cout << "max long int: " << LONG_MAX << std::endl;

	////doubleValue = strtol(input.c_str(), &endptr, 10);
	////std::cout << "errno" << ERANGE << std::endl;
	////std::cout << "errno" << errno << std::endl;




	//std::cout << "endptr: " << *endptr << std::endl;
	//if (doubleValue == 0.0 && (input[0] != '+' && input[0] != '-' && !std::isdigit(input[0]))
	//	 && (*endptr && strcmp(endptr, "f")))
	//{
	//	std::cout << "char: impossible" << std::endl;
	//	std::cout << "int: impossible" << std::endl;
	//	std::cout << "float: impossible" << std::endl;
	//	std::cout << "double: impossible" << std::endl;
	//}
	//else {
	//	//toChar
	//	if(isnan(doubleValue) || isinf(doubleValue))
	//		std::cout << "impossible" << std::endl;
	//	else if (isprint(static_cast<char>(doubleValue)))
	//		std::cout << "'" << static_cast<char>(doubleValue) << "'" << std::endl;
	//	else
	//		std::cout << "Non displayable" << std::endl;
	//	//toInt
	//	std::cout << "int: ";
	//	if(isnan(doubleValue) || isinf(doubleValue) || doubleValue > INT_MAX || doubleValue < INT_MIN)
	//		std::cout << "impossible" << std::endl;
	//	else
	//		std::cout << static_cast<int>(doubleValue) << std::endl;
	//	//toFloat, toDouble
	//	if(isnan(doubleValue) || isinf(doubleValue))
	//	{
	//		std::cout << "float: " << std::showpos << static_cast<float>(doubleValue) << "f" << std::endl;
	//		std::cout << "double: " << static_cast<double>(doubleValue) << std::endl;
	//	}
	//	else {
	//		if (static_cast<float>(doubleValue) == static_cast<int>(doubleValue)) {
	//			std::cout << "float: " << static_cast<float>(doubleValue) << ".0f" << std::endl;
	//			std::cout << "double: " << static_cast<double>(doubleValue) << ".0" << std::endl;
	//		}
	//		else {
	//			std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
	//			std::cout << "double: " << static_cast<double>(doubleValue) << std::endl;
	//		}
	//	}
	//}	
}

