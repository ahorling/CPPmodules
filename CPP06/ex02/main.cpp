#include <iostream>
#include "base.hpp"

Base* generate(void)
{
	int type = rand() % 3;

	switch (type)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			std::cout << "Something has gone horribly wrong in the generate function" << std::endl;
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type A!" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type B!" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type C!" << std::endl;
	else
		std::cout << "Something has gone horribly wrong in the pointer function" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A test = dynamic_cast<A&>(p);
		std::cout << "Type A!" << std::endl;
	}
	catch(...){}
	try
	{
		B test = dynamic_cast<B&>(p);
		std::cout << "Type B!" << std::endl;
	}
	catch(...){}
	try
	{
		C test = dynamic_cast<C&>(p);
		std::cout << "Type C!" << std::endl;
	}
	catch(...){}
}

int main(void)
{
	srand(time(NULL));
	
	Base* check = generate();
	identify(check);
	identify(*check);

	Base* check2 = generate();
	identify(check2);
	identify(*check2);

	delete check;
	delete check2;
}