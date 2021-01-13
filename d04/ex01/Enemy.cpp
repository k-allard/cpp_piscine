/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:38:06 by kallard           #+#    #+#             */
/*   Updated: 2021/01/13 19:56:26 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
Enemy::Enemy() : _hitPoints(0), _type("") {
	std::cout << "\x1b[31;1mEnemy : default constructor called\033[0m" << std::endl;
}

Enemy::Enemy(int hp, const std::string & type) : _hitPoints(hp), _type(type) {}

Enemy::Enemy( Enemy const & src ) {
	*this = src;
	return ;
}

Enemy::~Enemy() {}

Enemy & Enemy::operator=( Enemy const & rhs ) {
	if (this != &rhs) {
		_type = rhs._type;
		_hitPoints = rhs._hitPoints;
	}
	return *this;
}

/***********/
/* GETTERS */
/***********/
int Enemy::getHP() const {
	return (_hitPoints);
}

const std::string & Enemy::getType() const {
	return (_type);
}

/*************/
/* INTERFACE */
/*************/
void Enemy::takeDamage(int damage) {
	if (damage > 0)
		_hitPoints -= damage;
	if (_hitPoints < 0)
		_hitPoints = 0;
}
