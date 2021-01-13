#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {
	public:
		/*************/
		/* COPLIENS' */
		/*************/
		AssaultTerminator();			// • Birth: "* teleports from space *"
		virtual ~AssaultTerminator();	// • Death: "I’ll be back..."
		AssaultTerminator( AssaultTerminator const & src );
		AssaultTerminator & operator=( AssaultTerminator const & rhs );

		/*************/
		/* INTERFACE */
		/*************/
		ISpaceMarine* clone() const;
		void battleCry() const ;		// "This code is unclean. PURIFY IT!" 
		void rangedAttack() const ;		// "* does nothing *"
		void meleeAttack() const ;		// "* attacks with chainfists *"
};

#endif
