/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:11:55 by kallard           #+#    #+#             */
/*   Updated: 2021/01/16 21:07:40 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
Bureaucrat::Bureaucrat(const std::string name, int grade) : 
		_name(name), 
		_grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : 
	_name(src._name), 
	_grade(src._grade) { }

Bureaucrat::~Bureaucrat() { }

/***********/
/* GETTERS */
/***********/
std::string const & Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

/*************/
/* INTERFACE */
/*************/
void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << "SIGNED ✅ : " << _name + " signs " + form.get_name() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << "❌ SIGN FAILED : " << _name + " (grade " << _grade << ") can not sign " << form.get_name();
		std::cout << ", required rank: " << form.get_gradeToSign();
		std::cout << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << "EXECUTE ✅ : " << _name + " executes " + form.get_name() << std::endl;
	}
	catch (AForm::NotSignedForExecutionException &e) {
		std::cout << "❌ EXECUTION FAILED : " + form.get_name() + " is not signed\n";
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << "❌ EXECUTION FAILED : " << _name + " (grade " << _grade << ") can not execute " << form.get_name();
		std::cout << ", required rank: " << form.get_gradeToExecute();
		std::cout << std::endl;
	}
}

/*****************************/
/* Stream insertion overload */
/*****************************/
std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs) {
	o << "👩‍ " << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (o);
}
