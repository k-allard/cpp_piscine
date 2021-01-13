/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 00:19:35 by kallard           #+#    #+#             */
/*   Updated: 2021/01/14 01:21:10 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
TacticalMarine::TacticalMarine() { 
	std::cout << "Tactical Marine ready for battle!" << std::endl; 
}

TacticalMarine::~TacticalMarine() { 
	std::cout << "💀 Aaargh..." << std::endl; 
}

TacticalMarine::TacticalMarine( TacticalMarine const & ) {}

TacticalMarine & TacticalMarine::operator=( TacticalMarine const & ) {	
	return *this; 
}

/*************/
/* INTERFACE */
/*************/
ISpaceMarine* TacticalMarine::clone() const { 
	return (new TacticalMarine(*this)); 
}
	
void TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with a chainsword *" << std::endl;
}
