#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "CommonHeader.hpp"
#include <iostream>

class AMateria {
	protected:
		std::string _type; //Their type will be their name in lowercase ("ice" for Ice, etc...).
		unsigned int _xp;

	public:
		/*************/
		/* COPLIENS' */
		/*************/
		AMateria();
		AMateria(std::string const & type); 
		virtual ~AMateria();
		AMateria( AMateria const & src );
		AMateria & operator=( AMateria const & rhs );

		/***********/
		/* GETTERS */
		/***********/
		std::string const & getType() const;
		unsigned int getXP() const;

		/*************/
		/* INTERFACE */
		/*************/
		virtual AMateria* clone() const = 0;	// will, of course, return a new instance of the real Materia’s type.
		virtual void use(ICharacter& target); // Ice: "* shoots an ice bolt at NAME *" • Cure: "* heals NAME’s wounds *"
};	

#endif