/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Seeker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:21 by kallard           #+#    #+#             */
/*   Updated: 2021/01/11 21:24:38 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Seeker.hpp"
#include <iostream>
#include <string>

Seeker::Seeker() : _name("") {
	std::cout << "\x1b[31;1mSeeker : default constructor called\033[0m" << std::endl;
}

Seeker::Seeker(std::string name) : Victim(name) {
	std::cout << "Tag tag." << std::endl;
}

Seeker::Seeker( Seeker const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Seeker::~Seeker() {
		std::cout << "Krueot..." << std::endl;
}

Seeker & Seeker::operator=( Seeker const & rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs) {
		this->set_name(rhs.get_name());
	}
	return *this;
}

/*************/
/* INTERFACE */
/*************/
void Seeker::getPolymorphed() const {
	std::cout << get_name() << " has been turned into an old hat!" << std::endl;
}
