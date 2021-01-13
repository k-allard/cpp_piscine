/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:21 by kallard           #+#    #+#             */
/*   Updated: 2021/01/12 15:02:23 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#include <iostream>
#include <string>

Victim::Victim() : _name("") {
	std::cout << "\x1b[31;1mVictim : default constructor called\033[0m" << std::endl;
}

Victim::Victim(std::string name) : _name(name) {
	std::cout << "🧝‍ Some random victim called " << _name << " just appeared!" << std::endl;
}

Victim::Victim( Victim const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Victim::~Victim() {
		std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

Victim & Victim::operator=( Victim const & rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs) {
		this->set_name(rhs.get_name());
	}
	return *this;
}

std::ostream & operator<<( std::ostream & o, Victim const & rhs) {
	o << "\033[3m— ";
	o << "I'm "<< rhs.get_name() << " and I like otters!" << std::endl;
	o << "\033[0m";
	return (o);
}

/***********/
/* GETTERS */
/***********/
std::string Victim::get_name() const {
	return (_name);
}

/***********/
/* SETTERS */
/***********/
void Victim::set_name(std::string name) {
	_name = name;
}

/*************/
/* INTERFACE */
/*************/
void Victim::getPolymorphed() const {
	std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}
