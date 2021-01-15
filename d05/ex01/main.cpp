/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:32:09 by kallard           #+#    #+#             */
/*   Updated: 2021/01/16 00:28:48 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define CLERK_GRADE 80
#define GRADE_TO_SIGN 50
#define GRADE_TO_EXECUTE 25

int main()
{
	try {
		std::cout << "Creating bureaucrat Sally with grade " << CLERK_GRADE << " . . ." << std::endl;		
		Bureaucrat Sally("Sally", CLERK_GRADE);
		std::cout << "SUCCESS!\n" << Sally;
		try {
			std::cout << "Creating form 'document' with grade to sign ";
				std::cout << GRADE_TO_SIGN << " and grade to execute " << GRADE_TO_EXECUTE << " . . .\n";		
			Form document("document", GRADE_TO_SIGN, GRADE_TO_EXECUTE);
			std::cout << "SUCCESS!\n" << document;
			std::cout << "Trying to sign the form . . .\n";		
			Sally.signForm(document);
		}
		catch (std::exception &e) {
			std::cout << "❌ Error in creating form" << std::endl;
		}
		return (0);
	}
	catch (std::exception &e) {
		std::cout << "❌ Error in creating bureaucrat" << std::endl;
	}
	return (0);
}
