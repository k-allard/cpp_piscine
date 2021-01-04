/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:21 by kallard           #+#    #+#             */
/*   Updated: 2021/01/04 15:49:12 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {
	std::cout << "Zombie created :" << std::endl;
	std::cout << "\tName : " << this->_name << std::endl;
	std::cout << "\tType : " << this->_type << std::endl;

}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " destructed." << std::endl;
	std::cout << "________________________" << std::endl;

}

void Zombie::announce()
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braaiiiiiinnnssss..." << std::endl;
}