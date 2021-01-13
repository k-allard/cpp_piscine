/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:37:55 by kallard           #+#    #+#             */
/*   Updated: 2021/01/13 20:37:39 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
AWeapon::AWeapon() : _name(""), _damage(0), _APCost(0) {
	std::cout << "\x1b[31;1mAWeapon : default constructor called\033[0m" << std::endl;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : 
	_name(name),
	_damage(damage),
	_APCost(apcost) {}

AWeapon::AWeapon( AWeapon const & src ) {
	*this = src;
	return ;
}

AWeapon::~AWeapon() {}

AWeapon & AWeapon::operator=( AWeapon const & rhs ) {
	if (this != &rhs)
	{
		_name = rhs._name;
		_damage = rhs._damage;
		_APCost = rhs._APCost;
	}
	return *this;
}

/***********/
/* GETTERS */
/***********/
int AWeapon::getAPCost() const {
	return(_APCost);
}

int AWeapon::getDamage() const {
	return (_damage);
}

const std::string & AWeapon::getName() const {
	return (_name);
}
