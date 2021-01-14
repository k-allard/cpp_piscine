#ifndef ICE_HPP
# define ICE_HPP

#include "CommonHeader.hpp"
#include "AMateria.hpp"
#include <string>

class Ice : public AMateria {
	public:
		/*************/
		/* COPLIENS' */
		/*************/
		Ice();
		virtual ~Ice();
		Ice( Ice const & src );
		Ice & operator=( Ice const & rhs );

		/*************/
		/* INTERFACE */
		/*************/
		AMateria* clone() const;	// will, of course, return a new instance of the real Materia’s type.
		void use(ICharacter& target); // Ice: "* shoots an ice bolt at NAME *"
};

#endif