/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:14:51 by kallard           #+#    #+#             */
/*   Updated: 2020/12/27 12:14:52 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			phonebook.add_contact();
		else if (!command.compare("SEARCH"))
			phonebook.search();
		else if (!command.compare("EXIT"))
			is_exit = 1;
	}
}
