#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0; 
		virtual void equip(AMateria* m) = 0; //In case we try to equip a Materia in a full inventory, or use/uneqip a nonexistent Materia, don’t do a thing.
		virtual void unequip(int idx) = 0; //The unequip method must NOT delete Materia!
		virtual void use(int idx, ICharacter& target) = 0; //will have to use the Materia at the idx slot,
//and pass target as parameter to the AMateria::use method.
	};

 #endif
