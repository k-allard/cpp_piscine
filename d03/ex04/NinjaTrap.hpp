#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "commonHeader.hpp"

class	NinjaTrap : virtual public ClapTrap {
	public:
		NinjaTrap();
		NinjaTrap( std::string name );
		NinjaTrap( NinjaTrap const & src );
		~NinjaTrap();

		/********************/
		/* SPECIFIC GETTERS */
		/********************/
		int get_defaultEnergyPoints() const ;
		int get_defaultMaxEnergyPoints() const ;
		int get_defaultMeleeAttackDamage() const ;

		/*************/
		/*  SHOEBOX  */
		/*************/
		int ninjaShoebox(FragTrap & target);
		int ninjaShoebox(NinjaTrap & target);
		int ninjaShoebox(ClapTrap & target);
		int ninjaShoebox(ScavTrap & target);
};

#endif
