/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:40:51 by kallard           #+#    #+#             */
/*   Updated: 2021/01/16 15:16:49 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : 
		_name(name),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute),
		_ifSigned(false) { 
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm( AForm const & src ) : 
	_name(src._name),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute),
	_ifSigned(src._ifSigned) { }

AForm::~AForm() { }

/***********/
/* GETTERS */
/***********/
std::string const & AForm::get_name() const { return (_name); }

bool AForm::get_ifSigned() const { return (_ifSigned); }

int AForm::get_gradeToSign() const { return (_gradeToSign); }

int AForm::get_gradeToExecute() const { return (_gradeToExecute); }

/*************/
/* INTERFACE */
/*************/
void AForm::beSigned(const Bureaucrat & clerk) { 
	if (clerk.getGrade() <= get_gradeToSign())
		_ifSigned = true; 
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & clerk) const {
	if (!get_ifSigned())
		throw NotSignedForExecutionException();
	if (clerk.getGrade() > this->get_gradeToExecute())
		throw GradeTooLowException();
}

/*****************************/
/* Stream insertion overload */
/*****************************/
std::ostream & operator<<( std::ostream & o, AForm const & rhs) {
	o << "📄 AForm " + rhs.get_name();
	if (rhs.get_ifSigned())
		o << ": SIGNED ✅ , ";
	else
		o << ": NOT SIGNED ❎ , " << rhs.get_gradeToSign() << " grade required to sign, ";
	o << rhs.get_gradeToExecute() << " grade required to execute\n";
	return (o);
}
