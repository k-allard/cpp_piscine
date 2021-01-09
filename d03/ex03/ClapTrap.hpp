#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

#include <string>

class	ClapTrap {
	protected:
		int			_hitPoints;
		int 		_maxHitPoints;
		int			_energyPoints;
		int 		_maxEnergyPoints;
		int			_level;
		std::string	_name;
		int			_meleeAttackDamage;
		int			_rangedAttackDamage;
		int			_armorDamageReduction;
		int			getRandomIndex() const;

	public:
		ClapTrap( std::string name );
		ClapTrap(		
			int			_hitPoints,
			int 		_maxHitPoints,
			int			_energyPoints,
			int 		_maxEnergyPoints,
			int			_level,
			std::string	_name,
			int			_meleeAttackDamage,
			int			_rangedAttackDamage,
			int			_armorDamageReduction
		);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();
		ClapTrap & operator=( ClapTrap const & rhs );
		
		/***********/
		/* GETTERS */
		/***********/
		int get_hitPoints() const;
		int get_maxHitPoints() const;
		int get_energyPoints() const;
		int get_maxEnergyPoints() const;
		int get_level() const;
		std::string get_name() const;
		int get_meleeAttackDamage() const;
		int get_rangedAttackDamage() const;
		int get_armorDamageReduction() const;

		/***********/
		/* SETTERS */
		/***********/
		void set_hitPoints(int hitPoints);
		void set_maxHitPoints(int maxHitPoints);
		void set_energyPoints(int energyPoints);
		void set_maxEnergyPoints(int maxEnergyPoints);
		void set_level(int level);
		void set_name(std::string name);
		void set_meleeAttackDamage(int meleeAttackDamage);
		void set_rangedAttackDamage(int rangedAttackDamage);
		void set_armorDamageReduction(int armorDamageReduction);

		/*************/
		/* INTERFACE */
		/*************/
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
