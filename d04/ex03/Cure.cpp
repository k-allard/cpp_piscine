/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:05:37 by kallard           #+#    #+#             */
/*   Updated: 2021/01/14 17:44:54 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
Cure::Cure() : AMateria("cure") { }

Cure::~Cure() { }

Cure::Cure( const Cure & ) : AMateria("cure") { }

Cure & Cure::operator=( const Cure & ) {
	return *this; 
}

/*************/
/* INTERFACE */
/*************/
		
AMateria* Cure::clone() const { 
	return (new Cure(*this)); 
}

void Cure::use(ICharacter& target) {
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
