#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include "CommonHeader.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
	protected: 
		std::string _name;
		AMateria *_inventory[4];
	public:
		/*************/
		/* COPLIENS' */
		/*************/
		Character();
		Character(std::string const & name); 
		Character( Character const & src );
		Character & operator=( Character const & rhs );
		~Character();

		/***********/
		/* GETTERS */
		/***********/
		std::string const & getName() const;

		/*************/
		/* INTERFACE */
		/*************/
		void equip(AMateria* m); //In case we try to equip a Materia in a full inventory, or use/uneqip a nonexistent Materia, don’t do a thing.
		void unequip(int idx); //The unequip method must NOT delete Materia!
		void use(int idx, ICharacter& target);
};

#endif