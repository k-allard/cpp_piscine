#include <iostream>
#include "Megaphone.hpp"

int main(int argc, char **argv)
{
	int i = 1;
	Megaphone megaphone;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < argc)
	{
		megaphone.uppercaser(argv[i]);
		std::cout << argv[i];
		i++;
	}
	std::cout << std::endl;
	return (0);
}
