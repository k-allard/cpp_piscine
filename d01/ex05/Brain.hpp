#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <string>

class Brain{
	private :
		int _age;
		int _iq;
	public :
		std::string identify() const;
		Brain(int age, int iq);
		~Brain();
};

#endif