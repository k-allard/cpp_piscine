#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
	public:
		/*************/
		/* COPLIENS' */
		/*************/
		TacticalMarine();			
		virtual ~TacticalMarine();
		TacticalMarine( TacticalMarine const & src );
		TacticalMarine & operator=( TacticalMarine const & rhs );

		/*************/
		/* INTERFACE */
		/*************/
		ISpaceMarine* clone() const;
		void battleCry() const ;	
		void rangedAttack() const ;	
		void meleeAttack() const ;	
};

#endif