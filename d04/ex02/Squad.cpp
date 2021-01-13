/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 00:19:15 by kallard           #+#    #+#             */
/*   Updated: 2021/01/14 01:11:11 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
Squad::Squad() : _head(NULL), _numOfUnits(0) { }

Squad::~Squad() { 
	t_squad *tmp = _head;
	t_squad *tmp2;
	while (_numOfUnits) {
		tmp2 = tmp->next;
		delete tmp->unit;
		delete tmp;
		tmp = tmp2;
		_numOfUnits--;
	}
 }

Squad::Squad( ISquad const & src) :  _head(NULL), _numOfUnits(0) {
	*this = src;
}

Squad & Squad::operator=( ISquad const & rhs ) {
	t_squad *tmp = _head;
	t_squad *tmp2;
	while (_numOfUnits) {
		tmp2 = tmp->next;
		tmp->next = NULL;
		delete tmp->unit;
		delete tmp;
		tmp = tmp2;
		_numOfUnits--;
	}
	int n = rhs.getCount();
	_head = NULL;
	_numOfUnits = 0;
	for (int i = 0; i < n; ++i) {
		push(rhs.getUnit(i)->clone());
	}
	return *this;
}

/***********/
/* GETTERS */
/***********/
int Squad::getCount() const {
	return (_numOfUnits);
}

/*************/
/* INTERFACE */
/*************/
ISpaceMarine* Squad::getUnit(int n) const { 
	if (n < 0 || n > _numOfUnits - 1)
		return (NULL);
	t_squad *tmp = _head;
	while (tmp && n > 0) {
		tmp = tmp->next;
		n--;
	}
	return tmp->unit;
}

int Squad::push(ISpaceMarine* newUnit) {
	t_squad *tmp = _head;
	t_squad *newSquadElem;
	newSquadElem = new t_squad;
	newSquadElem->unit = newUnit;
	newSquadElem->next = NULL;
	if (!tmp)
		_head = newSquadElem;
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newSquadElem;
	}
	_numOfUnits++;
	return (_numOfUnits);
}
