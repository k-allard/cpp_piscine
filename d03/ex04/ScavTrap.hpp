#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "commonHeader.hpp"
#include "ClapTrap.hpp"

#include <string>

class	ScavTrap : public ClapTrap {
	private:
		void		challenge1() const;
		void		challenge2() const;
		void		challenge3() const;
		void		challenge4() const;
		void		challenge5() const;
		void		challenge6() const;

	public:
		ScavTrap( std::string name );
		ScavTrap();
		ScavTrap( ScavTrap const & src );
		~ScavTrap();

		/**************/
		/* CHALLENGES */
		/**************/
		void challengeNewcomer(FragTrap & newcomer) const;
		void challengeNewcomer(NinjaTrap & newcomer) const;
		void challengeNewcomer(SuperTrap & newcomer) const;
};

#endif
