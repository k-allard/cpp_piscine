/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:32:09 by kallard           #+#    #+#             */
/*   Updated: 2021/01/17 00:47:38 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

#define CLERK_GRADE 46
// #define FORM "shrubbery creation"	//sign 145, exec 137
#define FORM "robotomy request"		//sign 72, exec 45
// #define FORM "presidential pardon"	//sign 25, exec 5



int main()
{
	Intern  Bob;
	AForm*   form;
	try {
		std::cout << "Intern is trying to create \"" << FORM << "\" form . . .\n";		
		form = Bob.makeForm(FORM, "Bender");
		try {
			std::cout << "Creating bureaucrat Sally with grade " << CLERK_GRADE << " . . ." << std::endl;		
			Bureaucrat Sally("Sally", CLERK_GRADE);
			std::cout << "SUCCESS!\n" << Sally;

			std::cout << "Trying to sign the form . . .\n";
			Sally.signForm(*form);
			std::cout << "Trying to execute the form . . .\n";
			Sally.executeForm(*form);	
			return (0);
		}
		catch (std::exception &e) {
			std::cout << "❌ Error in creating bureaucrat" << std::endl;
		}
	}
	catch (Intern::NotFoundException &e) {
		std::cout << "FAILED FORM CREATION ❌  Intern doesn't know it" << std::endl;
	}


	return (0);
}