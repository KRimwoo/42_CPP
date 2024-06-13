#include "Serializer.hpp"

int main()
{
	Data data;
	Data *deserializedData;
	uintptr_t serializedData;

	data._data = "Hello, world!";
	data._number = 42;

	std::cout << "Original data _data: " << data._data << std::endl;
	std::cout << "Original data _number: " << data._number << std::endl << std::endl;

	serializedData = Serializer::serialize(&data);
	std::cout << "Original data ptr: " << &data << std::endl;
	std::cout << "Serialized data: " << serializedData << std::endl << std::endl;

	deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Deserialized data _data: " << deserializedData->_data << std::endl;
	std::cout << "Deserialized data _number: " << deserializedData->_number << std::endl;

	return 0;
}