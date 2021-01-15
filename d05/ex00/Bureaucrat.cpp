/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:11:55 by kallard           #+#    #+#             */
/*   Updated: 2021/01/15 23:54:09 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*****************************/
/* Stream insertion overload */
/*****************************/
std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs) {
	o << "👩‍ " << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (o);
}
