/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 21:16:59 by kallard           #+#    #+#             */
/*   Updated: 2021/01/06 00:18:22 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>
#include <iostream>

Weapon::Weapon() {
	std::cout << "Weapon created" << std::endl;
}

Weapon::Weapon(std::string type) : _type(type) {
	std::cout << "Weapon created" << std::endl;
}

Weapon::~Weapon(){
	std::cout << "Weapon destructed" << std::endl;
}

void Weapon::setType(std::string type){
	this->_type = type;
}

const std::string& Weapon::getType()
{
	const std::string& type_ref = this->_type;
	return (type_ref);
}

