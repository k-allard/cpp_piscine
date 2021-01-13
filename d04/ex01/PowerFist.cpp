/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:38:35 by kallard           #+#    #+#             */
/*   Updated: 2021/01/13 19:58:15 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}

PowerFist::~PowerFist() {}

PowerFist::PowerFist( PowerFist const & src ) : AWeapon(src) {}

PowerFist & PowerFist::operator=( PowerFist const & rhs ) {
	if (this != &rhs) {
		_name = rhs._name;
		_damage = rhs._damage;
		_APCost = rhs._APCost;
	}
	return *this;
}

/*************/
/* INTERFACE */
/*************/
void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
