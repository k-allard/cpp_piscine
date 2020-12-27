/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:14:57 by kallard           #+#    #+#             */
/*   Updated: 2020/12/27 12:14:58 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>


Phonebook::Phonebook()
{
	this->contacts_count = 0;
	this->contacts_count_max = 8;
}

std::string get_field(std::string field_name)
{
	std::string input;
	std::cout << std::setw(20);
	std::cout << field_name;
	getline(std::cin, input);
	return (input);
}

void	Phonebook::add_contact()
{
	if (contacts_count < contacts_count_max)
	{
		contacts[contacts_count].set_first_name(get_field("First Name: "));
		contacts[contacts_count].set_last_name(get_field("Last Name: "));
		contacts[contacts_count].set_nickname(get_field("Nickname: "));
		contacts[contacts_count].set_login(get_field("Login: "));
		contacts[contacts_count].set_address(get_field("Postal address: "));
		contacts[contacts_count].set_email(get_field("Email: "));
		contacts[contacts_count].set_phone(get_field("Phone number: "));
		contacts[contacts_count].set_birthday(get_field("Birthday date: "));
		contacts[contacts_count].set_meal(get_field("Favorite meal: "));
		contacts[contacts_count].set_underwear_color(get_field("Underwear color: "));
		contacts[contacts_count].set_secret(get_field("Darkest secret: "));
		contacts_count++;
	}
	else
		std::cout << "ERROR: Max contact number is reached" << std::endl;
}

void	Phonebook::search()
{
	std::string input;
	int index;

	print_list();
	std::cout << "Enter index : ";
	getline(std::cin, input);
	if (input.size() == 1 && input.at(0) >= '1' && input.at(0) <= '8')
	{
		index = input.at(0) - '0';
		if (index <= contacts_count)
			contacts[index - 1].print_detail();
		else
			std::cout << "Not found" << std::endl;
	}
	else
		std::cout << "Not found" << std::endl;
}

void	Phonebook::print_list()
{
	int i = 1;
	while (i <= contacts_count)
	{
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << i;
		std::cout << "|";
		contacts[i - 1].print_line();
		i++;
	}
}
