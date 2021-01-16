/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:32:09 by kallard           #+#    #+#             */
/*   Updated: 2021/01/16 21:44:06 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define CLERK_GRADE 72

int main()
{
	ShrubberyCreationForm SCF("trees");		//sign 145, exec 137
	RobotomyRequestForm RRF("bureaucracy");	//sign 72, exec 45
	PresidentialPardonForm PPF("Bob");		//sign 25, exec 5

	try {
		std::cout << "Creating bureaucrat Sally with grade " << CLERK_GRADE << " . . ." << std::endl;		
		Bureaucrat Sally("Sally", CLERK_GRADE);
		std::cout << "SUCCESS!\n" << Sally;

			std::cout << "Trying to sign all forms . . .\n";
			Sally.signForm(SCF);
			Sally.signForm(RRF);
			Sally.signForm(PPF);
			std::cout << "Trying to execute all forms . . .\n";
			Sally.executeForm(SCF);	
			Sally.executeForm(RRF);
			// for (int i = 0; i < 5; i++)
			// 	Sally.executeForm(RRF);
			Sally.executeForm(PPF);
		return (0);
	}
	catch (std::exception &e) {
		std::cout << "❌ Error in creating bureaucrat" << std::endl;
	}
	return (0);
}
