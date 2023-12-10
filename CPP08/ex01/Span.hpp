#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
	private:
		int *_n;
		unsigned int _max;
		unsigned int _current;
	public:
		Span(unsigned int i);
		Span(const Span &obj);
		Span& operator=(const Span &obj);
		~Span();
	public:
		void	addNumber(int i);
		int		shortestSpan();
		int		longestSpan();
};

#endif
