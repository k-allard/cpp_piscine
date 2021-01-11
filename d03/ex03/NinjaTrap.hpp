#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "CommonHeader.hpp"

class	NinjaTrap : public ClapTrap {
	public:
		NinjaTrap();
		NinjaTrap( std::string name );
		NinjaTrap( NinjaTrap const & src );
		~NinjaTrap();

		/*************/
		/*  SHOEBOX  */
		/*************/
		int ninjaShoebox(FragTrap & target);
		int ninjaShoebox(NinjaTrap & target);
		int ninjaShoebox(ClapTrap & target);
		int ninjaShoebox(ScavTrap & target);
};

#endif
