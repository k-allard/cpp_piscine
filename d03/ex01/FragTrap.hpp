#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>

class	FragTrap {
	private:
		int					_hitPoints;
		int 				_maxHitPoints;
		int					_energyPoints;
		int 				_maxEnergyPoints;
		int					_level;
		std::string			_name;
		int					_meleeAttackDamage; //Урон от атаки в ближнем бою
		int					_rangedAttackDamage; //Урон от атаки в дальнем бою
		int					_armorDamageReduction; //Снижение урона оружия 
		int					getRandomIndex() const;
	public:
		FragTrap();
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );
		~FragTrap();

		FragTrap & operator=( FragTrap const & rhs );
		
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
		
		/******************/
		/* CUSTOM ATTACKS */
		/******************/
		int vaulthunter_dot_exe(std::string const & target);
		void customAttack(std::string const & target);
		// void bulletnatorAttack(std::string const & target);
		// void funnyAttack(std::string const & target);
		// void purposeAttack(std::string const & target);
		// void scaryAttack(std::string const & target);
		// void awesomeAttack(std::string const & target);

};

#endif
