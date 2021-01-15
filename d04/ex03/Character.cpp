/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:05:34 by kallard           #+#    #+#             */
/*   Updated: 2021/01/15 00:10:33 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

/*************/
/* COPLIENS' */
/*************/
Character::Character() : _name("") {
	int i = 0;
	while (i < 4) {
		_inventory[i] = NULL;
		i++;
	}
}

Character::Character(const std::string &name) : _name(name) {
	int i = 0;
	while (i < 4) {
		_inventory[i] = NULL;
		i++;
	}
}

Character::Character( Character const & src ) : _name(src._name) {
	int i = 0;
	while (i < 4) {
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
		i++;
	}
}


Character & Character::operator=( Character const & rhs ) {
	_name = rhs._name;
	int i = 0;
	while (i < 4) {
		_inventory[i] = rhs._inventory[i];
		i++;
	}
	return *this;
}

Character::~Character()  {
	int i = 0;
	while (i < 4) {
		delete _inventory[i];
		i++;
	}
}

/***********/
/* GETTERS */
/***********/
std::string const & Character::getName() const {
	return (_name);
}

/*************/
/* INTERFACE */
/*************/
void Character::equip(AMateria* m) {
	int i = 0;
	if (!m)
		return ;
	while (i < 4) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			break;
		}
		i++;
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3)
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if ((idx >= 0 && idx <= 3) && _inventory[idx])
		_inventory[idx]->use(target);
}

