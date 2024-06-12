#include "Serializer.hpp"

int main()
{
	Data data;
	Data *deserializedData;
	uintptr_t serializedData;

	data._data = "Hello, world!";

	std::cout << "Original data: " << data._data << std::endl;

	serializedData = Serializer::serialize(&data);
	std::cout << "Serialized data: " << serializedData << std::endl;

	deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Deserialized data: " << deserializedData->_data << std::endl;

	return 0;
}