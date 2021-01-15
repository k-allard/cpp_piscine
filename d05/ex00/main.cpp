/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:32:09 by kallard           #+#    #+#             */
/*   Updated: 2021/01/15 23:51:56 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "Creating bureaucrat with grade 0 . . ." << std::endl;
	try {
		Bureaucrat Bob = Bureaucrat("Bob", 0);
		std::cout << Bob;			
	}
	catch (std::exception &e) {
		std::cout << "❌ Error" << std::endl;
	}
	std::cout << "Creating bureaucrat with grade 151 . . ." << std::endl;
	try {
		Bureaucrat Tom = Bureaucrat("Tom", 151);
		std::cout << Tom;			
	}
	catch (std::exception &e) {
		std::cout << "❌ Error" << std::endl;
	}

	try {
		std::cout << "Creating bureaucrat Sally with grade 2 . . ." << std::endl;		
		Bureaucrat Sally = Bureaucrat("Sally", 2);
		std::cout << Sally;
		try {
			std::cout << "Increasing Sally's grade from 2 to 0. . ." << std::endl;
			while (42)
				Sally.incrementGrade();
		}
		catch (std::exception &e) {
			std::cout << "❌ Error in Sally.incrementGrade()" << std::endl;
		}
		std::cout << Sally;
		try {
			std::cout << "Decreasing Sally's grade from 1 to 151. . ." << std::endl;
			while (42)
				Sally.decrementGrade();
		}
		catch (std::exception &e) {
			std::cout << "❌ Error in Sally.decrementGrade()" << std::endl;
		}
		std::cout << Sally << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "❌ Error in creating Sally" << std::endl;
	}
	return (0);
}
