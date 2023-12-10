#include <iostream>
#include "struct.hpp"

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
	Data *info = new Data;
	uintptr_t hold_info = serialize(info);
	Data *info2;

	info->a = 5;
	info->stuff = "Hello!";

	std::cout << "Address of Info [" << info << "]" << std::endl;
	std::cout << "Value of Info [" << info->a << "] [" << info->stuff << "]" << std::endl;
	std::cout << "hold_info seralize [" << std::hex << hold_info << std::dec << "]" << std::endl;
	info->a = 8;
	info2 = deserialize(hold_info);
	info->a = 9;
	std::cout << "Address of Info [" << info << "]" << std::endl;
	std::cout << "Value of Info [" << info->a << "] [" << info->stuff << "]" << std::endl;
	std::cout << "Address of Info2 [" << info2 << "]" << std::endl;
	std::cout << "Value of Info2 [" << info2->a << "] [" << info2->stuff << "]" << std::endl;

	delete info;
}