#ifndef HUMAN_HPP
# define HUMAN_HPP
#include <string>
#include "Brain.hpp"

class Human{
	private :
		Brain* brain;
	public :
		std::string identify();
		Brain& getBrain();
		Human();
		~Human();
};

#endif