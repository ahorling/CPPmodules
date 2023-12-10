#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
#include <deque>

template <class t>
class MutantStack : public std::stack<t>
{
	public:
		MutantStack(void){}
		MutantStack(MutantStack const & src) : std::stack<t>(src){};
		MutantStack& operator=(MutantStack const & src)
		{
			std::stack<t>::operator=(src);
			return (*this);
		}
		~MutantStack(void){};

		typedef typename MutantStack::container_type::iterator iterator;

		iterator begin(void)
		{
			return (this->c.begin());
		}
		iterator end(void)
		{
			return (this->c.end());
		}
};

#endif
