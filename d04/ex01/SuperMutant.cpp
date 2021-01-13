/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:38:53 by kallard           #+#    #+#             */
/*   Updated: 2021/01/13 19:52:51 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant::SuperMutant( SuperMutant const & src ) : Enemy(src) {}

SuperMutant & SuperMutant::operator=( SuperMutant const & rhs ) {
	if (this != &rhs) {
		_type = rhs._type;
		_hitPoints = rhs._hitPoints;
	}
	return *this;
}

/*************/
/* INTERFACE */
/*************/
void SuperMutant::takeDamage(int damage)
{
	damage -= 3;
	if (damage > 0)
		_hitPoints -= damage;
	if (_hitPoints < 0)
		_hitPoints = 0;
}