#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _hitPoints(100),
									_maxHitPoints(100),
									_energyPoints(50),
									_maxEnergyPoints(50),
									_level(1),
									_name(name),
									_meleeAttackDamage(30),
									_rangedAttackDamage(20),
									_armorDamageReduction(5) {
	std::cout << "CLAP-9000 (parent for ";
	std::cout << _name << ") constructed" << std::endl;
}


ClapTrap::ClapTrap(		
	    int			hitPoints,
		int 		maxHitPoints,
		int			energyPoints,
		int 		maxEnergyPoints,
		int			level,
		std::string	name,
		int			meleeAttackDamage,
		int			rangedAttackDamage,
		int			armorDamageReduction
) : _hitPoints(hitPoints),
	_maxHitPoints(maxHitPoints),
	_energyPoints(energyPoints),
	_maxEnergyPoints(maxEnergyPoints),
	_level(level),
	_name(name),
	_meleeAttackDamage(meleeAttackDamage),
	_rangedAttackDamage(rangedAttackDamage),
	_armorDamageReduction(armorDamageReduction) {
	std::cout << "CLAP-9000 (parent for ";
	std::cout << _name << ") constructed" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap() {
	std::cout << "CLAP-9000 (parent for ";
	std::cout << _name << ") destructed" << std::endl;}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs ) {
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
int ClapTrap::get_hitPoints() const {
	return(_hitPoints);
}

int ClapTrap::get_maxHitPoints() const {
	return (_maxHitPoints);
}

int ClapTrap::get_energyPoints() const {
	return (_energyPoints);
}

int ClapTrap::get_maxEnergyPoints() const {
	return (_maxEnergyPoints);
}

int ClapTrap::get_level() const {
	return (_level);
}

std::string ClapTrap::get_name() const {
	return (_name);
}

int ClapTrap::get_meleeAttackDamage() const {
	return (_meleeAttackDamage);
}

int ClapTrap::get_rangedAttackDamage() const {
	return (_rangedAttackDamage);
}

int ClapTrap::get_armorDamageReduction() const {
	return (_armorDamageReduction);
}

/***********/
/* SETTERS */
/***********/
void ClapTrap::set_hitPoints(int hitPoints) {
	_hitPoints = hitPoints;
}

void ClapTrap::set_maxHitPoints(int maxHitPoints) {
	_maxHitPoints = maxHitPoints;
}

void ClapTrap::set_energyPoints(int energyPoints) {
	_energyPoints = energyPoints;
}

void ClapTrap::set_maxEnergyPoints(int maxEnergyPoints) {
	_maxEnergyPoints = maxEnergyPoints;
}

void ClapTrap::set_level(int level) {
	_level = level;
}

void ClapTrap::set_name(std::string name) {
	_name = name;
}

void ClapTrap::set_meleeAttackDamage(int meleeAttackDamage) {
	_meleeAttackDamage = meleeAttackDamage;
}

void ClapTrap::set_rangedAttackDamage(int rangedAttackDamage) {
	_rangedAttackDamage = rangedAttackDamage;
}

void ClapTrap::set_armorDamageReduction(int armorDamageReduction) {
	_armorDamageReduction = armorDamageReduction;
}

/*************/
/* INTERFACE */
/*************/
int ClapTrap::rangedAttack(std::string const & target) {
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
	std::cout << _name << " attacks " << target;
	std::cout << " at range 🔫 , causing " << _rangedAttackDamage;
	std::cout << " points of damage!" << std::endl;
	_energyPoints -= 10;
	return 1;
}

int ClapTrap::meleeAttack(std::string const & target) {
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
	std::cout << _name << " hits " << target;
	std::cout << " with the melee attack 🗡️ , causing " << _meleeAttackDamage;
	std::cout << " points of damage!" << std::endl;
	_energyPoints -= 15;
	return 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << _name << " was attacked! ";
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

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << _name << " was repaired 🏥 + " << amount << " HP! ";
	std::cout << "Health : [" <<_hitPoints << " --> ";
	_hitPoints += amount;
	if (_hitPoints > _maxHitPoints)
		_hitPoints = _maxHitPoints;
	std::cout << _hitPoints << "] Energy poits : [" << _energyPoints << " --> ";
	_energyPoints = _maxEnergyPoints;
	std::cout << _energyPoints << "]" << std::endl;
}

int ClapTrap::getRandomIndex() const {
	return (rand() % 6);
}
