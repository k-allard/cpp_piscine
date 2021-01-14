#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "CommonHeader.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	protected:
		AMateria *_inventory[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &MateriaSource);
		MateriaSource &operator=(const MateriaSource &MateriaSource);

		void learnMateria(AMateria *);
		AMateria *createMateria(std::string const &type);
};

#endif
