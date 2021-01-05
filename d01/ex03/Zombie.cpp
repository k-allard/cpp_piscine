/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:21 by kallard           #+#    #+#             */
/*   Updated: 2021/01/05 20:50:18 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(){
	this->_name = "";
	this->_type = "";
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " destructed" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

void Zombie::setType(std::string type)
{
	this->_type = type;
}

void Zombie::announce()
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braaiiiiiinnnssss..." << std::endl;
}
