#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		Base();
		virtual ~Base();
};

class A: public Base{};
class B: public Base{};
class C: public Base{};

#endif
