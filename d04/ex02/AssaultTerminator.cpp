/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:45:05 by kallard           #+#    #+#             */
/*   Updated: 2021/01/14 01:21:07 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
AssaultTerminator::AssaultTerminator() {
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator() { 
	std::cout << "💀 I’ll be back..." << std::endl; 
}

AssaultTerminator::AssaultTerminator( AssaultTerminator const & ) {}

AssaultTerminator & AssaultTerminator::operator=( AssaultTerminator const & ) {	
	return *this; 
}

/*************/
/* INTERFACE */
/*************/
ISpaceMarine* AssaultTerminator::clone() const { 
	return (new AssaultTerminator(*this)); 
}
	
void AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with chainfists *" << std::endl;
}
