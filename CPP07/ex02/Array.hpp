#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <class t>
class Array
{
	private:
		t	*array;
		unsigned int total;
	public:
		Array() : array(NULL), total(0) {}
		Array(unsigned int n) : array(new t[n]), total(n) {}
		Array(Array const & cpy) : array(NULL), total(0) {*this = cpy;}
		Array<t> & operator=(Array<t> const & copy_from)
		{
			if (&copy_from == this)
				return (*this);
			delete[] array;
			total = copy_from.total;
			array = new t[total];
			for (unsigned int i = 0 ; i < total ; i++)
				array[i] = copy_from.array[i];
			return (*this);
		}
		~Array() { delete[] this->array;}
		t & operator[](const int i) const
		{
			if (i < 0 || static_cast<unsigned int>(i) >= this->total)
				throw std::exception();
			return (this->array[i]);
		}
		unsigned int size(void) const { return (this->total);}
};

#endif
