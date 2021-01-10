/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:06:40 by kallard           #+#    #+#             */
/*   Updated: 2021/01/10 15:20:48 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>
#include <string>

NinjaTrap::NinjaTrap(std::string name) : 
	ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0) {
	std::cout << "INAC 🤖 ";
	std::cout << _name << " constructed" << std::endl;
}

NinjaTrap::NinjaTrap( NinjaTrap const & src ) : ClapTrap(src) {
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

NinjaTrap::~NinjaTrap() {
	std::cout << "INAC ";
	std::cout << _name << " destructed" << std::endl;
}

/*************/
/*  SHOEBOX  */
/*************/
int NinjaTrap::ninjaShoebox(FragTrap & target) {
	if (_hitPoints == 0) {
		std::cout << " ❌ " << _name << " tried to attack, but has no HP left"; 
		std::cout << std::endl;
		return 0;
	}
	if (_energyPoints < 15) {
		std::cout << " ❌ " << _name << " tried to attack, ";
		std::cout << "but doesn't have enough energy points" << std::endl;
		return 0;
	}
	std::cout << "INAC " << _name << " attacks FR4G-TP " << target.get_name();
	std::cout << " at range 🔫 , causing " << 50;
	std::cout << " points of damage!" << std::endl;
	std::cout << "\033[3m< " << _name << ": > See how our enemies crumble beneath the wheel of the claptrap Robolution! ";
	std::cout << "\033[0m" << std::endl;
	_energyPoints -= 15;
	return 1;
}

int NinjaTrap::ninjaShoebox(NinjaTrap & target) {
	if (_hitPoints == 0) {
		std::cout << " ❌ " << _name << " tried to attack, but has no HP left"; 
		std::cout << std::endl;
		return 0;
	}
	if (_energyPoints < 15) {
		std::cout << " ❌ " << _name << " tried to attack at range, ";
		std::cout << "but doesn't have enough energy points" << std::endl;
		return 0;
	}
	std::cout << "INAC " << _name << " attacks FR4G-TP " << target.get_name();
	std::cout << " at range 🔫 , causing " << 50;
	std::cout << " points of damage!" << std::endl;
	std::cout << "\033[3m< " << _name << ": > Another fleshbag falls to the Robolution! ";
	std::cout << "\033[0m" << std::endl;
	_energyPoints -= 15;
	return 1;
}

int NinjaTrap::ninjaShoebox(ClapTrap & target) {
	if (_hitPoints == 0) {
		std::cout << " ❌ " << _name << " tried to attack, but has no HP left"; 
		std::cout << std::endl;
		return 0;
	}
	if (_energyPoints < 15) {
		std::cout << " ❌ " << _name << " tried to attack at range, ";
		std::cout << "but doesn't have enough energy points" << std::endl;
		return 0;
	}
	std::cout << "INAC " << _name << " attacks FR4G-TP " << target.get_name();
	std::cout << " at range 🔫 , causing " << 50;
	std::cout << " points of damage!" << std::endl;
	std::cout << "\033[3m< " << _name << ": > How do YOU like target practice? Huh? HUH?! ";
	std::cout << "\033[0m" << std::endl;
	_energyPoints -= 15;
	return 1;
}

int NinjaTrap::ninjaShoebox(ScavTrap & target) {
	if (_hitPoints == 0) {
		std::cout << " ❌ " << _name << " tried to attack, but has no HP left"; 
		std::cout << std::endl;
		return 0;
	}
	if (_energyPoints < 15) {
		std::cout << " ❌ " << _name << " tried to attack at range, ";
		std::cout << "but doesn't have enough energy points" << std::endl;
		return 0;
	}
	std::cout << "INAC " << _name << " attacks SC4V-TP " << target.get_name();
	std::cout << " at range 🔫 , causing " << 50;
	std::cout << " points of damage!" << std::endl;
	std::cout << "\033[3m< " << _name << ": > Target disassembled! ";
	std::cout << "\033[0m" << std::endl;
	_energyPoints -= 15;
	return 1;
}