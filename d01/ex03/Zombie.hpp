#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class	Zombie{
	private:
		std::string	_name;
		std::string	_type;	//can be Brain_eater or Vegan

	public:
		void announce();
		Zombie(std::string name, std::string type);
		~Zombie();
};

#endif
