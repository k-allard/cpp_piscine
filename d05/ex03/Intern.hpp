#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		int		getFunctionIndex(const std::string &name);

	public:
		/*************/
		/* COPLIENS' */
		/*************/
		Intern();
		Intern( Intern const & src );
		Intern & operator=( Intern const & rhs );
		~Intern();

		AForm	*makePresidentialPardonForm(const std::string &target);
		AForm	*makeRobotomyRequestForm(const std::string &target);
		AForm	*makeShrubberyCreationForm(const std::string &target);

		AForm	*makeForm(const std::string &name, const std::string &target);

		class NotFoundException : public std::exception { };

};

typedef AForm *(Intern::*InternMemberFunction)(const std::string &target);

#endif
