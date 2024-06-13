#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

#define uintptr_t unsigned long

struct Data
{
	std::string _data;
	int _number;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();

	public:
		static uintptr_t serialize(Data *dataPtr);
		static Data *deserialize(uintptr_t rawData);

};

#endif