#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>
#include <string>

ScavTrap::ScavTrap() : _hitPoints(0),
					_maxHitPoints(0),
					_energyPoints(0),
					_maxEnergyPoints(0),
					_level(0),
					_name(""),
					_meleeAttackDamage(0),
					_rangedAttackDamage(0),
					_armorDamageReduction(0) {
	std::cout << "\x1b[31;1mScavTrap : default constructor called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _hitPoints(100),
									_maxHitPoints(100),
									_energyPoints(50),
									_maxEnergyPoints(50),
									_level(1),
									_name(name),
									_meleeAttackDamage(20),
									_rangedAttackDamage(15),
									_armorDamageReduction(3) {
	std::cout << "SC4V-TP 🤖 ";
	std::cout << _name << " constructed" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap() {
	std::cout << "SC4V-TP ";
	std::cout << _name << " destructed" << std::endl;}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) {
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
int ScavTrap::get_hitPoints() const {
	return(_hitPoints);
}

int ScavTrap::get_maxHitPoints() const {
	return (_maxHitPoints);
}

int ScavTrap::get_energyPoints() const {
	return (_energyPoints);
}

int ScavTrap::get_maxEnergyPoints() const {
	return (_maxEnergyPoints);
}

int ScavTrap::get_level() const {
	return (_level);
}

std::string ScavTrap::get_name() const {
	return (_name);
}

int ScavTrap::get_meleeAttackDamage() const {
	return (_meleeAttackDamage);
}

int ScavTrap::get_rangedAttackDamage() const {
	return (_rangedAttackDamage);
}

int ScavTrap::get_armorDamageReduction() const {
	return (_armorDamageReduction);
}

/***********/
/* SETTERS */
/***********/
void ScavTrap::set_hitPoints(int hitPoints) {
	_hitPoints = hitPoints;
}

void ScavTrap::set_maxHitPoints(int maxHitPoints) {
	_maxHitPoints = maxHitPoints;
}

void ScavTrap::set_energyPoints(int energyPoints) {
	_energyPoints = energyPoints;
}

void ScavTrap::set_maxEnergyPoints(int maxEnergyPoints) {
	_maxEnergyPoints = maxEnergyPoints;
}

void ScavTrap::set_level(int level) {
	_level = level;
}

void ScavTrap::set_name(std::string name) {
	_name = name;
}

void ScavTrap::set_meleeAttackDamage(int meleeAttackDamage) {
	_meleeAttackDamage = meleeAttackDamage;
}

void ScavTrap::set_rangedAttackDamage(int rangedAttackDamage) {
	_rangedAttackDamage = rangedAttackDamage;
}

void ScavTrap::set_armorDamageReduction(int armorDamageReduction) {
	_armorDamageReduction = armorDamageReduction;
}

/*************/
/* INTERFACE */
/*************/
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
	std::cout << "\033[3m< " << _name << ": > Here, take this!\033[0m" << std::endl;
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
	if (_energyPoints < 5) {
		std::cout << " ❌ " << _name << " tried to attack at range, ";
		std::cout << "but doesn't have enough energy points" << std::endl;
		return 0;
	}
	std::cout << "\033[3m< " << _name << ": > Let's get this party started!\033[0m" << std::endl;
	std::cout << "SC4V-TP " << _name << " hits " << target;
	std::cout << " with the melee attack 🗡️ , causing " << _meleeAttackDamage;
	std::cout << " points of damage!" << std::endl;
	_energyPoints -= 5;
	return 1;
}

void ScavTrap::takeDamage(unsigned int amount) {
	std::cout << "SC4V-TP " << _name << " was attacked! ";
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

void ScavTrap::beRepaired(unsigned int amount) {
	std::cout << "SC4V-TP " << _name << " was repaired 🏥 + " << amount << " HP! ";
	std::cout << "Health : [" <<_hitPoints << " --> ";
	_hitPoints += amount;
	if (_hitPoints > _maxHitPoints)
		_hitPoints = _maxHitPoints;
	std::cout << _hitPoints << "] Energy poits : [" << _energyPoints << " --> ";
	_energyPoints = _maxEnergyPoints;
	std::cout << _energyPoints << "]" << std::endl;
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

int ScavTrap::getRandomIndex() const {
	return (rand() % 5);
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
	}
}
