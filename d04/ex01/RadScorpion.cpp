/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:38:45 by kallard           #+#    #+#             */
/*   Updated: 2021/01/13 19:59:34 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"
#include <iostream>

/*************/
/* COPLIENS' */
/*************/
RadScorpion::RadScorpion() : Enemy(80, "Rad Scorpion") {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion::RadScorpion( RadScorpion const & src ) : Enemy(src) {}

RadScorpion & RadScorpion::operator=( RadScorpion const & rhs ) {
	if (this != &rhs) {
		_type = rhs._type;
		_hitPoints = rhs._hitPoints;
	}
	return *this;
}
