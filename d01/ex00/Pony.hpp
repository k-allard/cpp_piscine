#ifndef PONY_HPP
# define PONY_HPP

#include <string>

class	Pony{
	private:
		std::string	_name;
		int			_age;
		std::string	_color;

	public:
		Pony(std::string name, int age, std::string	color);
		~Pony();
};

#endif
