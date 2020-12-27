/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:14:41 by kallard           #+#    #+#             */
/*   Updated: 2020/12/27 12:14:42 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->login = "";
	this->address = "";
	this->email = "";
	this->phone = "";
	this->birthday = "";
	this->meal = "";
	this->underwear_color = "";
	this->secret = "";
}

void		print_field(std::string text)
{
	if (text.size() <= 10)
	{
		std::cout << std::setw(10);
		std::cout << text;
	}
	else
		std::cout << text.substr(0, 9) << ".";
	std::cout << "|";	
}

void		Contact::print_line()
{
	print_field(first_name);
	print_field(last_name);
	print_field(nickname);
	std::cout << std::endl;
}

void		Contact::print_detail()
{
	std::cout << "	First name: " << first_name << std::endl;
	std::cout << "	Last name: " << last_name << std::endl;
	std::cout << "	Nickname: " << nickname << std::endl;
	std::cout << "	Login: " << login << std::endl;
	std::cout << "	Postal address: " << address << std::endl;
	std::cout << "	Email: " << email << std::endl;
	std::cout << "	Phone number: " << phone << std::endl;
	std::cout << "	Birthday date: " << birthday << std::endl;
	std::cout << "	Favorite meal: " << meal << std::endl;
	std::cout << "	Underwear color: " << underwear_color << std::endl;
	std::cout << "	Darkest secret: " << secret << std::endl;
}

void		Contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

void		Contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

void		Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void		Contact::set_login(std::string login)
{
	this->login = login;
}

void		Contact::set_address(std::string address)
{
	this->address = address;
}

void		Contact::set_email(std::string email)
{
	this->email = email;
}

void		Contact::set_phone(std::string phone)
{
	this->phone = phone;
}

void		Contact::set_birthday(std::string birthday)
{
	this->birthday = birthday;
}

void		Contact::set_meal(std::string meal)
{
	this->meal = meal;
}

void		Contact::set_underwear_color(std::string underwear_color)
{
	this->underwear_color = underwear_color;
}

void		Contact::set_secret(std::string secret)
{
	this->secret = secret;
}
