#include "Phonebook.hpp"
#include <iostream>
#include <string>

int	main()
{
	std::string command;
	int is_exit = 0;
	Phonebook phonebook;
	while (is_exit == 0)
	{
		std::cout << "Enter command: ";
		getline(std::cin, command);
		if (command.empty())
			continue ;
		if (!command.compare("ADD"))
		{
			phonebook.add_contact();
		}
		else if (!command.compare("SEARCH"))
		{
			phonebook.search();
		}
		else if (!command.compare("EXIT"))
		{
			is_exit = 1;
		}
	}
}
