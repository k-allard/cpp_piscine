/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:32:00 by kallard           #+#    #+#             */
/*   Updated: 2021/01/16 20:50:33 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>
#include <string>
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequest", 72, 45),
	_target(target) { }

RobotomyRequestForm::~RobotomyRequestForm() { }

/*************/
/* INTERFACE */
/*************/

void RobotomyRequestForm::execute(Bureaucrat const & clerk) const {
	static int random = 0;
	AForm::execute(clerk);
	if (!random) {
		std::cout << _target + " was not robotomized\n";
		random = 1;
	}
	else {
		std::cout << _target << " has been robotomized successfully\n";
		random = 0;
	}
}
