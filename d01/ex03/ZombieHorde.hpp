#ifndef ZOMBIEHORD_HPP
# define ZOMBIEHORD_HPP

#include <string>
#include "Zombie.hpp"

class	ZombieHorde{
	private:
		Zombie      *_horde;
		int			_n;
		std::string getRandomName();
	public:
		ZombieHorde(int n);
		~ZombieHorde();
		void announce();
};

#endif
