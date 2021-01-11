/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:21 by kallard           #+#    #+#             */
/*   Updated: 2021/01/11 20:40:16 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"
#include <iostream>
#include <string>

Peon::Peon() : _name("") {
	std::cout << "\x1b[31;1mPeon : default constructor called\033[0m" << std::endl;
}

Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon( Peon const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Peon::~Peon() {
		std::cout << "Bleuark..." << std::endl;
}

Peon & Peon::operator=( Peon const & rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs) {
		this->set_name(rhs.get_name());
	}
	return *this;
}

/*************/
/* INTERFACE */
/*************/
void Peon::getPolymorphed() const {
	std::cout << get_name() << " has been turned into a pink pony!" << std::endl;
}
