#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "commonHeader.hpp"

class	NinjaTrap : virtual public ClapTrap {
	public:
		NinjaTrap( std::string name );
		NinjaTrap();
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
		void ninjaShoebox(FragTrap & target);
		void ninjaShoebox(NinjaTrap & target);
		void ninjaShoebox(ClapTrap & target);
		void ninjaShoebox(ScavTrap & target);
};

#endif
