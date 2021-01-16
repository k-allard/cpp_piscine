/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:56:34 by kallard           #+#    #+#             */
/*   Updated: 2021/01/17 00:33:59 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*******************************************************************/
/* https://isocpp.org/wiki/faq/pointers-to-members#array-memfnptrs */
/*******************************************************************/
#define CALL_MEMBER_FN(ptrToMember)  (*(ptrToMember))

/*************/
/* COPLIENS' */
/*************/
Intern::Intern() { }

Intern::Intern( Intern const & ) { }

Intern::~Intern() { }

/*************/
/* INTERFACE */
/*************/

AForm *Intern::makeShrubberyCreationForm(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

int		Intern::getFunctionIndex(const std::string &name)
{
	const std::string formsArray[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	int i = 0;
	while (i < 3) {
		if(formsArray[i] == name)
			return (i);
		i++;
	}
	throw NotFoundException();
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
	int i = getFunctionIndex(name);
	AForm *(Intern::*functArray[])(const std::string &target) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};
	std::cout << "DONE ✅ Intern creates \"" << name << "\"\n";
	return (this->*functArray[i])(target);
}
