/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:31:53 by kallard           #+#    #+#             */
/*   Updated: 2021/01/16 15:48:59 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardon", 25, 5),
	_target(target) { }

PresidentialPardonForm::~PresidentialPardonForm() { }

/*************/
/* INTERFACE */
/*************/

void PresidentialPardonForm::execute(Bureaucrat const & clerk) const {
	AForm::execute(clerk);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox\n";
}
