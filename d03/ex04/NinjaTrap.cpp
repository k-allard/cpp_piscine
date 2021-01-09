#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>
#include <string>

NinjaTrap::NinjaTrap() : 
	ClapTrap(60, 60, 120, 120, 1, "", 60, 5, 0) {
	std::cout << "INAC ";
	std::cout << _name << " constructed" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : 
	ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0) {
	std::cout << "INAC ";
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
void NinjaTrap::ninjaShoebox(FragTrap & target) {
	std::cout << "INAC " << _name << " attacks FR4G-TP " << target.get_name();
	std::cout << " at range 🔫 , causing " << _rangedAttackDamage;
	std::cout << " points of damage!" << std::endl;
	std::cout << "\033[3m< " << _name << ": > See how our enemies crumble beneath the wheel of the claptrap Robolution! ";
	std::cout << "\033[0m" << std::endl;
	_energyPoints -= 15;
}

void NinjaTrap::ninjaShoebox(NinjaTrap & target) {
	std::cout << "INAC " << _name << " attacks FR4G-TP " << target.get_name();
	std::cout << " at range 🔫 , causing " << _rangedAttackDamage;
	std::cout << " points of damage!" << std::endl;
	std::cout << "\033[3m< " << _name << ": > Another fleshbag falls to the Robolution! ";
	std::cout << "\033[0m" << std::endl;
	_energyPoints -= 15;
}

void NinjaTrap::ninjaShoebox(ClapTrap & target) {
	std::cout << "INAC " << _name << " attacks FR4G-TP " << target.get_name();
	std::cout << " at range 🔫 , causing " << _rangedAttackDamage;
	std::cout << " points of damage!" << std::endl;
	std::cout << "\033[3m< " << _name << ": > How do YOU like target practice? Huh? HUH?! ";
	std::cout << "\033[0m" << std::endl;
	_energyPoints -= 15;
}
void NinjaTrap::ninjaShoebox(ScavTrap & target) {
	std::cout << "INAC " << _name << " attacks SC4V-TP " << target.get_name();
	std::cout << " at range 🔫 , causing " << _rangedAttackDamage;
	std::cout << " points of damage!" << std::endl;
	std::cout << "\033[3m< " << _name << ": > Target disassembled! ";
	std::cout << "\033[0m" << std::endl;
	_energyPoints -= 15;
}