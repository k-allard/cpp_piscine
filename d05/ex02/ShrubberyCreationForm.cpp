/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:32:04 by kallard           #+#    #+#             */
/*   Updated: 2021/01/16 15:50:52 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <fstream>

#include <iostream>

/*************/
/* COPLIENS' */
/*************/
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreation", 145, 137),
	_target(target) { }

ShrubberyCreationForm::~ShrubberyCreationForm() { }

/*************/
/* INTERFACE */
/*************/

void ShrubberyCreationForm::execute(Bureaucrat const & clerk) const {
	AForm::execute(clerk);
	std::string filenameOut = _target + "_shrubbery";
	std::ofstream fileStreamOutput(filenameOut);
	if (fileStreamOutput.fail()) {
		std::cerr << "File " << filenameOut << " error\n";
		exit(1);
	}
	fileStreamOutput << "            	   ,@@@@@@@," << std::endl;
	fileStreamOutput << "			,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	fileStreamOutput << "		,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	fileStreamOutput << "		,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	fileStreamOutput << "		%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	fileStreamOutput << "		%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	fileStreamOutput << "		`&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	fileStreamOutput << "			|o|        | |         | |" << std::endl;
	fileStreamOutput << "			|.|        | |         | |" << std::endl;
	fileStreamOutput << "		 \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
}
