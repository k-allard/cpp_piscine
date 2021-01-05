/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 21:16:59 by kallard           #+#    #+#             */
/*   Updated: 2021/01/05 22:21:36 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <iostream>

Brain::Brain(int age, int iq) : _age(age), _iq(iq){
	std::cout << "Brain created : age " << this->_age << ", IQ " << this->_iq << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain destructed" << std::endl;
}

std::string Brain::identify(){
	char str[20];
	sprintf(str, "%p", this);
	return (std::string(str));
}
