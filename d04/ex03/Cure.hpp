#ifndef CURE_HPP
# define CURE_HPP

#include "CommonHeader.hpp"
#include "AMateria.hpp"
#include <string>

class Cure : public AMateria {
	public:
		/*************/
		/* COPLIENS' */
		/*************/
		Cure();
		virtual ~Cure();
		Cure( Cure const & src );
		Cure & operator=( Cure const & rhs );

		/*************/
		/* INTERFACE */
		/*************/
		AMateria* clone() const;	// will, of course, return a new instance of the real Materia’s type.
		void use(ICharacter& target); 
};

#endif