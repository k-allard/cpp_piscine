#include "SuperTrap.hpp"
#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>
#include <string>

SuperTrap::SuperTrap() {
	std::cout << "\x1b[31;1mSuperTrap : default constructor called\033[0m" << std::endl;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), NinjaTrap(name), FragTrap(name)
{
	_hitPoints = FragTrap::get_defaultHitPoints();
	_maxHitPoints = FragTrap::get_defaultMaxHitPoints();
	_energyPoints = NinjaTrap::get_defaultEnergyPoints();
	_maxEnergyPoints = NinjaTrap::get_defaultMaxEnergyPoints();
	_level = 1;
	_name = name;
	_meleeAttackDamage = NinjaTrap::get_defaultMeleeAttackDamage();
	_rangedAttackDamage = FragTrap::get_defaultRangedAttackDamage();
	_armorDamageReduction = FragTrap::get_defaultArmorDamageReduction();

	std::cout << "SuperTrap 🤖 ";
	std::cout << name << " constructed :" << std::endl;

	std::cout << "______________________" << std::endl;
	std::cout << "HP_________________" << _hitPoints << std::endl;
	std::cout << "max HP_____________" << _maxHitPoints << std::endl;
	std::cout << "energy_____________" << _energyPoints << std::endl;
	std::cout << "max energy_________" << _maxEnergyPoints << std::endl;
	std::cout << "level________________" << _level << std::endl;
	std::cout << "melee damage________" << _meleeAttackDamage << std::endl;
	std::cout << "ranged damage_______" << _rangedAttackDamage << std::endl;
	std::cout << "armor reduction______" << _armorDamageReduction << std::endl;
	std::cout << "______________________" << std::endl;
}

SuperTrap::SuperTrap( SuperTrap const & src ) : ClapTrap(src) {
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

SuperTrap::~SuperTrap() {
	std::cout << "SuperTrap ";
	std::cout << FragTrap::get_name() << " destructed" << std::endl;
}
