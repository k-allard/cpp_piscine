/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:38:16 by kallard           #+#    #+#             */
/*   Updated: 2021/01/13 19:57:25 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::~PlasmaRifle() {}

PlasmaRifle::PlasmaRifle( PlasmaRifle const & src ) : AWeapon(src) {}

PlasmaRifle & PlasmaRifle::operator=( PlasmaRifle const & rhs ) {
	std::cout << "Assignation operator overload called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_damage = rhs._damage;
		_APCost = rhs._APCost;
	}
	return *this;
}

/*************/
/* INTERFACE */
/*************/
void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
