/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:21 by kallard           #+#    #+#             */
/*   Updated: 2021/01/12 15:12:39 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"

#include <iostream>
#include <string>

Sorcerer::Sorcerer() : _name(""), _title("") {
	std::cout << "\x1b[31;1mSorcerer : default constructor called\033[0m" << std::endl;
}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << "🧙 " << _name << ", " << _title << ", is born! " << std::endl;
}

Sorcerer::Sorcerer( Sorcerer const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Sorcerer::~Sorcerer() {
		std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer & Sorcerer::operator=( Sorcerer const & rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs) {
		this->set_name(rhs.get_name());
		this->set_title(rhs.get_title());
	}
	return *this;
}

std::ostream & operator<<( std::ostream & o, Sorcerer const & rhs) {
	o << "\033[3m— ";
	o << "I am "<< rhs.get_name() << ", " << rhs.get_title() << ", and I like ponies!" << std::endl;
	o << "\033[0m";
	return (o);
}

/***********/
/* GETTERS */
/***********/
std::string Sorcerer::get_name() const {
	return (_name);
}

std::string Sorcerer::get_title() const {
	return(_title);
}

/***********/
/* SETTERS */
/***********/
void Sorcerer::set_name(std::string name) {
	_name = name;
}

void Sorcerer::set_title(std::string title) {
	_title = title;
}

/*************/
/* INTERFACE */
/*************/
void Sorcerer::polymorph(Victim const & target) const {
	target.getPolymorphed();
}
