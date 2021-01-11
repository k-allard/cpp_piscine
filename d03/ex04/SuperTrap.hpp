#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include <string>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "commonHeader.hpp"

class	SuperTrap : public NinjaTrap, public FragTrap {
	public:
		SuperTrap();
		SuperTrap( std::string name );
		SuperTrap( SuperTrap const & src );
		~SuperTrap();
		int rangedAttack(std::string const & target);
		int meleeAttack(std::string const & target);
};

#endif
