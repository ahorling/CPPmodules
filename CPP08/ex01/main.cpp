#include <iostream>
#include "Span.hpp"

int main(void)
{
	{
		Span test(10000);
		Span test2(50);

		srand(time(NULL));
		for (int i = 0; i < 10000; i++)
			test.addNumber(rand());
		try
		{
			test.addNumber(rand());
		}
		catch(const std::exception& e)
		{
			std::cout << "Adding more numbers then allowed!" << std::endl;
		}
		std::cout << "shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "longest span: " << test.longestSpan() << std::endl;

		test2.addNumber(55);
		try
		{
			test2.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cout << "Can't find span with 1 number" << std::endl;
		}
	}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		return 0;
	}
}