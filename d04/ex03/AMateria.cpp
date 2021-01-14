/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:05:32 by kallard           #+#    #+#             */
/*   Updated: 2021/01/14 17:22:22 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

/*************/
/* COPLIENS' */
/*************/
AMateria::AMateria() : _type(""), _xp(0) {
	std::cout << "\x1b[31;1mAMateria : default constructor called\033[0m" << std::endl;
}

AMateria::AMateria(std::string const & type) : 
	_type(type), _xp(0) {}

AMateria::~AMateria() {}

AMateria::AMateria( AMateria const & src ) {
	*this = src;
	return ;
}

AMateria & AMateria::operator=( AMateria const & rhs ) {
	if (this != &rhs) {
		_type = rhs._type;
		_xp = rhs._xp;
	}
	return *this;
}

/***********/
/* GETTERS */
/***********/
unsigned int AMateria::getXP() const {
	return(_xp);
}

std::string const & AMateria::getType() const {
	return (_type);
}

/*************/
/* INTERFACE */
/*************/
void AMateria::use(ICharacter &) { 
	_xp += 10; 
}
