/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:05:39 by kallard           #+#    #+#             */
/*   Updated: 2021/01/14 18:05:43 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
Ice::Ice() : AMateria("ice") { }

Ice::~Ice() { }

Ice::Ice( const Ice & ) : AMateria("ice") { }

Ice & Ice::operator=( const Ice & ) {
	return *this; 
}

/*************/
/* INTERFACE */
/*************/
		
AMateria* Ice::clone() const { 
	return (new Ice(*this)); 
}

void Ice::use(ICharacter& target) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
