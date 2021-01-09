/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:21 by kallard           #+#    #+#             */
/*   Updated: 2021/01/09 23:32:37 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(std::string name) : 
	ClapTrap(100, 100, 50, 50, 1, name, 30, 20, 5) {
	std::cout << "FR4G-TP ";
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
void FragTrap::sweetAttack(std::string const & target) {
	std::cout << "FR4G-TP " << _name << " attacks " << target;
	std::cout << ", causing 25";
	std::cout << " points of damage!" << std::endl;
	std::cout << "\033[3m< " << _name << ": > Who needs ammo anyway, am I right?\033[0m 💞 " << std::endl;
	_energyPoints -= 25;
}

void FragTrap::bulletnatorAttack(std::string const & target) {
	std::cout << "\033[3m< " << _name << ": > Step right up, to the Bulletnator 9000!\033[0m" << std::endl;
	std::cout << "FR4G-TP " << _name << " attacks " << target;
	std::cout << ", causing 25";
	std::cout << " points of damage!" << std::endl;
	_energyPoints -= 25;
}

void FragTrap::funnyAttack(std::string const & target) {
	std::cout << "FR4G-TP " << _name << " attacks " << target;
	std::cout << ", causing 25";
	std::cout << " points of damage!" << std::endl;
	std::cout << "\033[3m< " << _name << ": > Hehehehe, mwaa ha ha ha, MWAA HA HA HA!\033[0m" << std::endl;
	_energyPoints -= 25;
}

void FragTrap::purposeAttack(std::string const & target) {
	std::cout << "\033[3m< " << _name << ": > This is why I was built!\033[0m" << std::endl;
	std::cout << "FR4G-TP " << _name << " attacks " << target;
	std::cout << ", causing 25";
	std::cout << " points of damage!" << std::endl;
	_energyPoints -= 25;
}

void FragTrap::scaryAttack(std::string const & target) {
	std::cout << "FR4G-TP " << _name << " attacks " << target;
	std::cout << ", causing 25";
	std::cout << " points of damage!" << std::endl;
	std::cout << "\033[3m< " << _name << ": > Is it dead? Can, can I open my eyes now?\033[0m" << std::endl;
	_energyPoints -= 25;
}

void FragTrap::awesomeAttack(std::string const & target) {
	std::cout << "FR4G-TP " << _name << " attacks " << target;
	std::cout << ", causing 25";
	std::cout << " points of damage!" << std::endl;
	std::cout << "\033[3m< " << _name << ": > Don't tell me that wasn't awesome!\033[0m" << std::endl;
	_energyPoints -= 25;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	switch (getRandomIndex()) {
		case 0:
			sweetAttack(target);
			break;
		case 1:
			bulletnatorAttack(target);
			break;
		case 2:
			funnyAttack(target);
			break;
		case 3:
			purposeAttack(target);
			break;
		case 4:
			scaryAttack(target);
			break;
		case 5:
			awesomeAttack(target);
			break;
	}
}
