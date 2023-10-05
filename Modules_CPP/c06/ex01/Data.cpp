#include "Data.hpp"

Data::Data() {}

Data::~Data() {}

Data::Data(const Data &other)
{
	test = other.test;
}

Data&	Data::operator=(const Data &other)
{
	test = other.test;
	return (*this);
}

uintptr_t	serialize(Data	*ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t  raw)
{
	return (reinterpret_cast<Data*>(raw));
}