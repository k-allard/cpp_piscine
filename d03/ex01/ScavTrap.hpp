#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "FragTrap.hpp"

#include <string>

class	ScavTrap {
	private:
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
		void		challenge1() const;
		void		challenge2() const;
		void		challenge3() const;
		void		challenge4() const;
		void		challenge5() const;
	public:
		ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src );
		~ScavTrap();

		ScavTrap & operator=( ScavTrap const & rhs );
		
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
		int rangedAttack(std::string const & target);
		int meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		/**************/
		/* CHALLENGES */
		/**************/
		void challengeNewcomer(FragTrap & newcomer) const;
};

#endif
