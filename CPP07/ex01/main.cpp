#include <iostream>
#include "iter.hpp"

void	strdisplay(char str)
{
	std::cout << str << std::endl;
}

int main(void)
{
	int stuff[5];
	stuff[0] = 0;
	stuff[1] = 1;
	stuff[2] = 2;
	stuff[3] = 3;
	stuff[4] = 4;

	char test[6] = "hello";
	::iter(stuff, 5, display);
	::iter(test, 5, strdisplay);
}