#include "Contact.hpp"
#include <iostream>
#include <iomanip>      // std::setw

Contact::Contact()
{
	this->is_present = 0;
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
	std::cout << first_name << std::endl;
	std::cout << last_name << std::endl;
	std::cout << nickname << std::endl;
	std::cout << login << std::endl;
	std::cout << address << std::endl;
	std::cout << email << std::endl;
	std::cout << phone << std::endl;
	std::cout << birthday << std::endl;
	std::cout << meal << std::endl;
	std::cout << underwear_color << std::endl;
	std::cout << secret << std::endl;
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
