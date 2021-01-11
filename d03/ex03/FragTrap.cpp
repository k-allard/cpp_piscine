/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:21 by kallard           #+#    #+#             */
/*   Updated: 2021/01/11 11:08:38 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap() {
	std::cout << "\x1b[31;1mFragTrap : default constructor called\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : 
	ClapTrap(100, 100, 50, 50, 1, name, 30, 20, 5) {
	std::cout << "FR4G-TP 🤖 ";
	std::cout << _name << " constructed" << std::endl;
}

FragTrap::FragTrap( FragTrap const & src ) : ClapTrap(src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap() {
	std::cout << "FR4G-TP ";
	std::cout << _name << " destructed" << std::endl;}

/******************/
/* CUSTOM ATTACKS */
/******************/
void FragTrap::customAttack(std::string const & target) {
	std::cout << "FR4G-TP " << _name << " attacks " << target;
	std::cout << ", causing 25";
	std::cout << " points of damage!" << std::endl;
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
