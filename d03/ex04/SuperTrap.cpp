#include "SuperTrap.hpp"
#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>
#include <string>

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), NinjaTrap(name), FragTrap(name)
{
	ClapTrap::set_hitPoints(FragTrap::get_hitPoints());
	ClapTrap::set_maxHitPoints(FragTrap::get_maxHitPoints());
	ClapTrap::set_energyPoints(NinjaTrap::get_energyPoints());
	ClapTrap::set_maxEnergyPoints(NinjaTrap::get_maxEnergyPoints());
	ClapTrap::set_level(1);
	ClapTrap::set_name(name);
	ClapTrap::set_meleeAttackDamage(NinjaTrap::get_meleeAttackDamage());
	ClapTrap::set_rangedAttackDamage(FragTrap::get_rangedAttackDamage());
	ClapTrap::set_armorDamageReduction(FragTrap::get_armorDamageReduction());

	std::cout << "SuperTrap 🤖 ";
	std::cout << name << " constructed" << std::endl;

}

SuperTrap::SuperTrap( SuperTrap const & src ) : ClapTrap(src) {
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

SuperTrap::~SuperTrap() {
	std::cout << "SuperTrap ";
	std::cout << FragTrap::get_name() << " destructed" << std::endl;
}