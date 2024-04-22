#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string* strPtr = &str;
	std::string& strRef = str;

	std::cout << "Printing memory addresses" << std::endl;
	std::cout << "Memory address of the string: " << &str << std::endl;
	std::cout << "Memory address of the string pointer: " << &strPtr << std::endl;
	std::cout << "Memory address of the string reference: " << &strRef << std::endl;

	std::cout << std::endl << "Printing the string" << std::endl;
	std::cout << "String: " << str << std::endl;
	std::cout << "String pointer: " << *strPtr << std::endl;
	std::cout << "String reference: " << strRef << std::endl;

}