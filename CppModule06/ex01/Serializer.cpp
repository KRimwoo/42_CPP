#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer()
{}

uintptr_t Serializer::serialize(Data *dataPtr)
{
	return reinterpret_cast<uintptr_t>(dataPtr);
}

Data *Serializer::deserialize(uintptr_t rawData)
{
	return reinterpret_cast<Data *>(rawData);
}