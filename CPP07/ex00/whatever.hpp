#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <class malleable> malleable max(malleable x, malleable y)
{
	if (x > y)
		return (x);
	return (y);
}

template <class malleable> malleable min(malleable x, malleable y)
{
	if (x < y)
		return (x);
	return (y);
}

template <class malleable> void swap(malleable &x, malleable &y)
{
	malleable temp = x;
	x = y;
	y = temp;
}

#endif
