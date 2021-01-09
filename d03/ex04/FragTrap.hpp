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
		
		/******************/
		/* CUSTOM ATTACKS */
		/******************/
		void vaulthunter_dot_exe(std::string const & target);
		void sweetAttack(std::string const & target);
		void bulletnatorAttack(std::string const & target);
		void funnyAttack(std::string const & target);
		void purposeAttack(std::string const & target);
		void scaryAttack(std::string const & target);
		void awesomeAttack(std::string const & target);
};

#endif
