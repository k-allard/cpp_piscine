#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "commonHeader.hpp"
#include "ClapTrap.hpp"

#include <string>

class	FragTrap : virtual public ClapTrap {
	public:
		FragTrap( std::string name );
		FragTrap();
		FragTrap( FragTrap const & src );
		~FragTrap();
	
		/********************/
		/* SPECIFIC GETTERS */
		/********************/
		int get_defaultHitPoints() const ;
		int get_defaultMaxHitPoints() const ;
		int get_defaultRangedAttackDamage() const ;
		int get_defaultArmorDamageReduction() const ;
		
		/******************/
		/* CUSTOM ATTACKS */
		/******************/
		int vaulthunter_dot_exe(std::string const & target);
		void customAttack(std::string const & target);
};

#endif
