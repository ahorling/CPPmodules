#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"


int main(void)
{
	Data *something;
	something = new Data;

	uintptr_t	*serializedThing = Serializer::serialize(something);
	Data* deserializedThing = Serializer::deserialize(serializedThing);

	something->X = 42;

	std::cout << "original pointer: " << &something << std::endl;
	std::cout << "something->data: " << something->X << std::endl;
	std::cout << "after serializing: " << serializedThing << std::endl;
	std::cout << "after deserializing: " << deserializedThing << std::endl;

	delete something;
	return (0);
}