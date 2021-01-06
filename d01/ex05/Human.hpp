#ifndef HUMAN_HPP
# define HUMAN_HPP
#include <string>
#include "Brain.hpp"

class Human{
	private :
		Brain const brain;
	public :
		std::string identify() const;
		const Brain& getBrain() const;
		Human();
		~Human();
};

#endif