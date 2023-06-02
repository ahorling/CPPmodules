#include <iostream>

int main(int argc, char **argv)
{
	int		i = 1;
	int		j = 0;
	char	c;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	while (argv[i])
	{
		while (argv[i][j])
		{
			c = toupper(argv[i][j]);
			std::cout << c;
			j++;
		}
		i++;
		j = 0;
	}
	std::cout << std::endl;
	return (0);
}