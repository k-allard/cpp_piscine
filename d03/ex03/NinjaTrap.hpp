#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "commonHeader.hpp"

class	NinjaTrap : public ClapTrap {
	public:
		NinjaTrap( std::string name );
		NinjaTrap( NinjaTrap const & src );
		~NinjaTrap();

		/*************/
		/*  SHOEBOX  */
		/*************/
		void ninjaShoebox(FragTrap & target);
		void ninjaShoebox(NinjaTrap & target);
		void ninjaShoebox(ClapTrap & target);
		void ninjaShoebox(ScavTrap & target);
};

#endif
