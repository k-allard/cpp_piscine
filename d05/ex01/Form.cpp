/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:40:51 by kallard           #+#    #+#             */
/*   Updated: 2021/01/16 00:01:10 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : 
		_name(name),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute),
		_ifSigned(false) { 
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form( Form const & src ) : 
	_name(src._name),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute),
	_ifSigned(src._ifSigned) { }

Form::~Form() { }

/***********/
/* GETTERS */
/***********/
std::string const & Form::get_name() const { return (_name); }

bool Form::get_ifSigned() const { return (_ifSigned); }

int Form::get_gradeToSign() const { return (_gradeToSign); }

int Form::get_gradeToExecute() const { return (_gradeToExecute); }

/*************/
/* INTERFACE */
/*************/
void Form::beSigned(const Bureaucrat & clerk) { 
	if (clerk.getGrade() <= get_gradeToSign())
		_ifSigned = true; 
	else
		throw Form::GradeTooLowException();
}

/*****************************/
/* Stream insertion overload */
/*****************************/
std::ostream & operator<<( std::ostream & o, Form const & rhs) {
	o << "📄 Form " + rhs.get_name();
	if (rhs.get_ifSigned())
		o << ": SIGNED ✅ , ";
	else
		o << ": NOT SIGNED ❎ , " << rhs.get_gradeToSign() << " grade required to sign, ";
	o << rhs.get_gradeToExecute() << " grade required to execute\n";
	return (o);
}
