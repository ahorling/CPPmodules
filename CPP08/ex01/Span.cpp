#include "Span.hpp"
#include <exception>
#include <algorithm>

#include <iostream>

Span::Span(unsigned int i)
{
	_n = new int[i];
	_max = i;
	_current = 0;
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span& Span::operator=(const Span &obj)
{
	if (&obj == this)
		return (*this);
	delete [] _n;
	_max = obj._max;
	_current = obj._current;
	_n = new int[_max];
	for (unsigned int i = 0; i < _max; i++)
		_n[i] = obj._n[i];
	return (*this);
}

Span::~Span()
{
	delete [] _n;
}

void	Span::addNumber(int num)
{
	if (_current >= _max)
		throw std::exception();
	_n[_current] = num;
	_current++;
}

int		Span::shortestSpan(void)
{
	if (_current < 2)
		throw std::exception();
	int* cpy = _n;
	std::sort(cpy, cpy + _current);
	long int store = _n[1] - _n[0];
	long int store2;
	for (unsigned int i = 1; i < _current; i++)
	{
		store2 = abs((cpy[i] - cpy[i - 1]));
		if (store2 < store)
			store = store2;
	}
	return (store);
}

int		Span::longestSpan(void)
{
	if (_current < 2)
		throw std::exception();
	int* cpy = _n;
	std::sort(cpy, cpy + _current);
	return (abs(cpy[_current - 1] - cpy[0]));
}
