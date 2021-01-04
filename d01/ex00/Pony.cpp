/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:21 by kallard           #+#    #+#             */
/*   Updated: 2021/01/04 13:37:22 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>
#include <string>

Pony::Pony(std::string name, int age, std::string	color) : _name(name), _age(age), _color(color) {
	std::cout << "Pony created :" << std::endl;
	std::cout << "\tName : " << this->_name << std::endl;
	std::cout << "\tAge : " << this->_age << std::endl;
	std::cout << "\tColor : " << this->_color << std::endl;

}

Pony::~Pony()
{
	std::cout << "Pony " << this->_name << " destructed." << std::endl;
	std::cout << "________________________" << std::endl;

}
