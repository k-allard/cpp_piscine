/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:05:45 by kallard           #+#    #+#             */
/*   Updated: 2021/01/14 18:06:12 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
MateriaSource::MateriaSource() { 
	int i = 0;
	while (i < 4) {
		_inventory[i] = NULL;
		i++;
	}
}

MateriaSource::~MateriaSource() {
	int i = 0;
	while (i < 4) {
		delete _inventory[i];
		i++;
	}
}

MateriaSource::MateriaSource( const MateriaSource &MateriaSource ) {
	int i = 0;
	while (i < 4) {
		if (MateriaSource._inventory[i])
			_inventory[i] = MateriaSource._inventory[i]->clone();
		else
			_inventory[i] = NULL;
		i++;
	}
}

MateriaSource & MateriaSource::operator=( const MateriaSource &MateriaSource ) {	
	int i = 0;
	while (i < 4) {
		_inventory[i] = MateriaSource._inventory[i];
		i++;
	}
	return *this; 
}

/*************/
/* INTERFACE */
/*************/
// learnMateria() must copy the Materia passed as parameter, 
// and store it in memory to be cloned later. 
// the Source can know at most 4 Materia, which are not necessarily unique.
void MateriaSource::learnMateria(AMateria * m) {
	int i = 0;
	while (i < 4) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			break;
		}
		i++;
	}
}

// createMateria() will return a new Materia, which will be a copy of the Materia (previously learned by the Source) 
// 		which type equals the parameter. Returns 0 if the type is unknown.
// In a nutshell, your Source must be able to learn "templates" of Materia, and re-create them on demand.
//  You’ll then be able to create a Materia without knowing it "real" type, just a string identifying it.
AMateria *MateriaSource::createMateria(std::string const &type) {
	int i = 0;
	while (i < 4 && _inventory[i]) {	
		if (_inventory[i]->getType() == type)
			return (_inventory[i]->clone());
		i++;
	}
	return (0);
}
