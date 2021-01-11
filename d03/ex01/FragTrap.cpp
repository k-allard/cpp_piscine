/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:21 by kallard           #+#    #+#             */
/*   Updated: 2021/01/11 11:03:13 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap() : _hitPoints(0),
					_maxHitPoints(0),
					_energyPoints(0),
					_maxEnergyPoints(0),
					_level(0),
					_name(""),
					_meleeAttackDamage(0),
					_rangedAttackDamage(0),
					_armorDamageReduction(0) {
	std::cout << "\x1b[31;1mFragTrap : default constructor called\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : _hitPoints(100),
									_maxHitPoints(100),
									_energyPoints(50),
									_maxEnergyPoints(50),
									_level(1),
									_name(name),
									_meleeAttackDamage(30),
									_rangedAttackDamage(20),
									_armorDamageReduction(5) {
	std::cout << "FR4G-TP 🤖 ";
	std::cout << _name << " constructed" << std::endl;
}

FragTrap::FragTrap( FragTrap const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap() {
	std::cout << "FR4G-TP ";
	std::cout << _name << " destructed" << std::endl;}

FragTrap & FragTrap::operator=( FragTrap const & rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->set_hitPoints(rhs.get_hitPoints());
		this->set_maxHitPoints(rhs.get_maxHitPoints());
		this->set_energyPoints(rhs.get_energyPoints());
		this->set_maxEnergyPoints(rhs.get_maxEnergyPoints());
		this->set_level(rhs.get_level());
		this->set_name(rhs.get_name());
		this->set_meleeAttackDamage(rhs.get_meleeAttackDamage());
		this->set_rangedAttackDamage(rhs.get_rangedAttackDamage());
		this->set_armorDamageReduction(rhs.get_armorDamageReduction());
	}
		
	return *this;
}

/***********/
/* GETTERS */
/***********/
int FragTrap::get_hitPoints() const {
	return(_hitPoints);
}

int FragTrap::get_maxHitPoints() const {
	return (_maxHitPoints);
}

int FragTrap::get_energyPoints() const {
	return (_energyPoints);
}

int FragTrap::get_maxEnergyPoints() const {
	return (_maxEnergyPoints);
}

int FragTrap::get_level() const {
	return (_level);
}

std::string FragTrap::get_name() const {
	return (_name);
}

int FragTrap::get_meleeAttackDamage() const {
	return (_meleeAttackDamage);
}

int FragTrap::get_rangedAttackDamage() const {
	return (_rangedAttackDamage);
}

int FragTrap::get_armorDamageReduction() const {
	return (_armorDamageReduction);
}

/***********/
/* SETTERS */
/***********/
void FragTrap::set_hitPoints(int hitPoints) {
	_hitPoints = hitPoints;
}

void FragTrap::set_maxHitPoints(int maxHitPoints) {
	_maxHitPoints = maxHitPoints;
}

void FragTrap::set_energyPoints(int energyPoints) {
	_energyPoints = energyPoints;
}

void FragTrap::set_maxEnergyPoints(int maxEnergyPoints) {
	_maxEnergyPoints = maxEnergyPoints;
}

void FragTrap::set_level(int level) {
	_level = level;
}

void FragTrap::set_name(std::string name) {
	_name = name;
}

void FragTrap::set_meleeAttackDamage(int meleeAttackDamage) {
	_meleeAttackDamage = meleeAttackDamage;
}

void FragTrap::set_rangedAttackDamage(int rangedAttackDamage) {
	_rangedAttackDamage = rangedAttackDamage;
}

void FragTrap::set_armorDamageReduction(int armorDamageReduction) {
	_armorDamageReduction = armorDamageReduction;
}

/*************/
/* INTERFACE */
/*************/
int FragTrap::rangedAttack(std::string const & target) {
	if (_hitPoints == 0) {
		std::cout << " ❌ " << _name << " tried to attack, but has no HP left"; 
		std::cout << std::endl;
		return 0;
	}
	if (_energyPoints < 10) {
		std::cout << " ❌ " << _name << " tried to attack at range, ";
		std::cout << "but doesn't have enough energy points" << std::endl;
		return 0;
	}
	std::cout << "FR4G-TP " << _name << " attacks " << target;
	std::cout << " at range 🔫 , causing " << _rangedAttackDamage;
	std::cout << " points of damage!" << std::endl;
	_energyPoints -= 10;
	return 1;
}

int FragTrap::meleeAttack(std::string const & target) {
	if (_hitPoints == 0) {
		std::cout << " ❌ " << _name << " tried to attack, but has no HP left"; 
		std::cout << std::endl;
		return 0;
	}
	if (_energyPoints < 5) {
		std::cout << " ❌ " << _name << " tried to attack at range, ";
		std::cout << "but doesn't have enough energy points" << std::endl;
		return 0;
	}
	std::cout << "FR4G-TP " << _name << " hits " << target;
	std::cout << " with the melee attack 🗡️ , causing " << _meleeAttackDamage;
	std::cout << " points of damage!" << std::endl;
	_energyPoints -= 5;
	return 1;
}

void FragTrap::takeDamage(unsigned int amount) {
	std::cout << "FR4G-TP " << _name << " was attacked! ";
	std::cout << "Health : [" <<_hitPoints << " --> ";
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << _hitPoints << "]";
	if (_hitPoints == 0)
		std::cout << " " << _name << " destroyed! 😵 ";
	std::cout << std::endl;
	_meleeAttackDamage -= _armorDamageReduction;
	_rangedAttackDamage -= _armorDamageReduction;
	if (_meleeAttackDamage < 0)
		_meleeAttackDamage = 0;
	if (_rangedAttackDamage < 0)
		_rangedAttackDamage = 0;
}

void FragTrap::beRepaired(unsigned int amount) {
	std::cout << "FR4G-TP " << _name << " was repaired 🏥 + " << amount << " HP! ";
	std::cout << "Health : [" <<_hitPoints << " --> ";
	_hitPoints += amount;
	if (_hitPoints > _maxHitPoints)
		_hitPoints = _maxHitPoints;
	std::cout << _hitPoints << "] Energy poits : [" << _energyPoints << " --> ";
	_energyPoints = _maxEnergyPoints;
	std::cout << _energyPoints << "]" << std::endl;
}

/******************/
/* CUSTOM ATTACKS */
/******************/
void FragTrap::customAttack(std::string const & target) {
	std::cout << "FR4G-TP " << _name << " attacks " << target;
	std::cout << ", causing 25";
	std::cout << " points of damage!" << std::endl;
}

int FragTrap::getRandomIndex() const {
	return (rand() % 6);
}

int FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (_hitPoints == 0) {
		std::cout << " ❌ " << _name << " tried to attack, but has no HP left"; 
		std::cout << std::endl;
		return 0;
	}
	if (_energyPoints < 25) {
		std::cout << " ❌ " << _name << " tried to attack at range, ";
		std::cout << "but doesn't have enough energy points" << std::endl;
		return 0;
	}
	customAttack(target);
	std::cout << "\033[3m< " << _name << ": > ";
	switch (getRandomIndex()) {
		case 0:
			std::cout << "Who needs ammo anyway, am I right? 💞 " << std::endl;
			break;
		case 1:
			std::cout << "Step right up, to the Bulletnator 9000!" << std::endl;
			break;
		case 2:
			std::cout << "Hehehehe, mwaa ha ha ha, MWAA HA HA HA!" << std::endl;
			break;
		case 3:
			std::cout << "This is why I was built!" << std::endl;
			break;
		case 4:
			std::cout << "Is it dead? Can, can I open my eyes now?" << std::endl;
			break;
		case 5:
			std::cout << "Don't tell me that wasn't awesome!" << std::endl;
			break;
	}
	std::cout << "\033[0m";
	_energyPoints -= 25;
	return 1;
}
