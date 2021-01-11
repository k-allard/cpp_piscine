#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>
#include <string>

ScavTrap::ScavTrap() {
	std::cout << "\x1b[31;1mScavTrap : default constructor called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : 
	ClapTrap(100, 100, 50, 50, 1, name, 20, 15, 3) {
	std::cout << "SC4V-TP ";
	std::cout << _name << " constructed" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap(src) {
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

ScavTrap::~ScavTrap() {
	std::cout << "SC4V-TP ";
	std::cout << _name << " destructed" << std::endl;
}

int ScavTrap::rangedAttack(std::string const & target) {
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
	std::cout << "SC4V-TP " << _name << " attacks " << target;
	std::cout << " at range 🔫 , causing " << _rangedAttackDamage;
	std::cout << " points of damage!" << std::endl;
	_energyPoints -= 10;
	return 1;
}

int ScavTrap::meleeAttack(std::string const & target) {
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
	std::cout << "SC4V-TP " << _name << " hits " << target;
	std::cout << " with the melee attack 🗡️ , causing " << _meleeAttackDamage;
	std::cout << " points of damage!" << std::endl;
	_energyPoints -= 15;
	return 1;
}

/**************/
/* CHALLENGES */
/**************/

void ScavTrap::challenge1() const {
	std::cout << "\033[3mthere's a raid boss that need defeating, and it's lurking somewhere in Eleseer.";
	std::cout << " Locate the entrance and prepare yourself. Post-script: you MAY want to bring a friend.";
	std::cout << " Or, you know, three.\033[0m" << std::endl;
}

void ScavTrap::challenge2() const {
	std::cout << "\033[3mif we're going to survive this, we need your help. Now, we thought Jack wanted ";
	std::cout << "to open a Vault and use its power to wipe us off Pandora, but, thanks to some intel I stole from a Hyperion convoy, I found out... we were wrong.";
	std::cout << " You'll need to get a fire weapon to wake him up. I'll explain when you get out there. ";
	std::cout << "If you don't have a fire weapon, Marcus might sell 'em.\033[0m" << std::endl;
}

void ScavTrap::challenge3() const {
	std::cout << "\033[3m";
	std::cout << "welcome to the Crimson Raiders, heh. Sorry you had to wake me up -- ";
	std::cout << "I mighta celebrated a little too hard last night after Bloodwing and ";
	std::cout << "I raided a Hyperion convoy. Ain't that right, Blood? Do what I'd do: steal the Key, get drunk, pass out.\033[0m" << std::endl;
}

void ScavTrap::challenge4() const {
	std::cout << "\033[3mwoah, never seen a FR4G-TP like you. The one we got from Reiss ";
	std::cout << "has nearly burnt out -- why don't you bring it back here? We may not have found the Vault Key, ";
	std::cout << "but at least Sanctuary will be safe a little longer thanks to you.\033[0m" << std::endl;
}

void ScavTrap::challenge5() const {
	std::cout << "\033[3mI made my own name beating down gangsters and taking out tyrants. ";
	std::cout << "I've won every fight I've ever been in, and I'm looking for a real challenge. ";
	std::cout << "Opening a Vault is the ultimate fight, right?\033[0m" << std::endl;
}

void ScavTrap::challenge6() const {
	std::cout << "\033[3mhi! I'm a robot, and I don't like that! Could you help me become human? ";
	std::cout << "Maybe? I don't wear clothes, but I see humans wearing lots of clothes -- could you get me clothes ";
	std::cout << "from those bandit guys nearby? I'll wear so many clothes, I'll be the best human ever!\033[0m" << std::endl;
}

void ScavTrap::challengeNewcomer(FragTrap & newcomer) const {
	std::cout << "\033[3m< " << _name << ": > Newcomer ";
	std::cout << newcomer.get_name() << ", \033[0m";
	switch (getRandomIndex()) {
		case 0:
			challenge1();
			break;
		case 1:
			challenge2();
			break;
		case 2:
			challenge3();
			break;
		case 3:
			challenge4();
			break;
		case 4:
			challenge5();
			break;
		case 5:
			challenge6();
			break;
		default:
			std::cout << "DEFAULT!!!" << std::endl;
	}
}

void ScavTrap::challengeNewcomer(NinjaTrap & newcomer) const {
	std::cout << "\033[3m< " << _name << ": > Newcomer ";
	std::cout << newcomer.get_name() << ", \033[0m";
	switch (getRandomIndex()) {
		case 0:
			challenge1();
			break;
		case 1:
			challenge2();
			break;
		case 2:
			challenge3();
			break;
		case 3:
			challenge4();
			break;
		case 4:
			challenge5();
			break;
		case 5:
			challenge6();
			break;
	}
}

void ScavTrap::challengeNewcomer(SuperTrap & newcomer) const {
	int index = getRandomIndex();
	std::cout << "\033[3m< " << _name << ": > Newcomer ";
	std::cout << newcomer.get_name() << ", \033[0m";
	switch (index) {
		case 0:
			challenge1();
			break;
		case 1:
			challenge2();
			break;
		case 2:
			challenge3();
			break;
		case 3:
			challenge4();
			break;
		case 4:
			challenge5();
			break;
		case 5:
			challenge6();
			break;
	}
}
