/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:38:00 by kallard           #+#    #+#             */
/*   Updated: 2021/01/13 20:37:44 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"

#include <iostream>

/*************/
/* COPLIENS' */
/*************/
Character::Character() {}

Character::Character(std::string const & name) : _name (name), _numOfAP(40), _weapon(NULL) {}

Character::Character( Character const & src ) {
	*this = src;
	return ;
}

Character & Character::operator=( Character const & rhs ) {
	if (this != &rhs)
	{
		_name = rhs._name;
		_numOfAP = rhs._numOfAP;
		_weapon = rhs._weapon;
	}
	return *this;
}

Character::~Character() {}

/***********/
/* GETTERS */
/***********/
AWeapon * Character::getWeapon() const {
	return (_weapon);
}

int Character::getNumOfAP() const {
	return (_numOfAP);
}

const std::string & Character::getName() const {
	return (_name);
}

/*************/
/* INTERFACE */
/*************/
void Character::recoverAP() {
	if (_numOfAP + 10 > 40)
		_numOfAP = 40;
	else 
		_numOfAP += 10;
}

void Character::equip(AWeapon* weapon) {
	_weapon = weapon;
}

void Character::attack(Enemy* enemy) {
	if (!_weapon || _weapon->getAPCost() > _numOfAP)
		return ;
	_numOfAP -= _weapon->getAPCost();
	std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
		_weapon->attack();
	enemy->takeDamage(_weapon->getDamage());
	if (enemy->getHP() <= 0) {
		delete enemy;
	}
}

std::ostream & operator<<( std::ostream & o, Character const & rhs) {
	if (rhs.getWeapon() != NULL)
		o << rhs.getName() << " has " << rhs.getNumOfAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
	else
		o << rhs.getName() << " has " << rhs.getNumOfAP() << " AP and is unarmed" << std::endl;
	return (o);
}
