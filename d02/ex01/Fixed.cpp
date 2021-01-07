/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:21 by kallard           #+#    #+#             */
/*   Updated: 2021/01/07 14:57:49 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( float const floatValue ) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = (int)roundf(floatValue * (1 << _numOfFractionalBits));
}

Fixed::Fixed( int const intValue ) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = intValue << _numOfFractionalBits;
}

Fixed::Fixed( Fixed const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
	return *this;
}

std::ostream & operator<<( std::ostream & o, Fixed const & fixedValue) {
	o << fixedValue.toFloat();
	return (o);
}

int Fixed::getRawBits( void ) const {
	return ( _fixedPointValue );
}

void Fixed::setRawBits( int const raw ) {
	_fixedPointValue = raw;
}

float Fixed::toFloat( void ) const {
	unsigned int base = (1 << _numOfFractionalBits);
	return((float)_fixedPointValue / base);
}

int Fixed::toInt( void ) const {
	return (_fixedPointValue >> _numOfFractionalBits);
}

std::string Fixed::toBinaryString(void) const
{
	unsigned int i1 = (1 << (sizeof(_fixedPointValue) * 8 - 1));
	std::string binaryString = "";

	while(i1)
	{
		if((_fixedPointValue & i1) == 0)
			binaryString += '0';
		else
			binaryString += '1';
		if (i1 == (1 << _numOfFractionalBits))
			binaryString += ".";
		i1 >>= 1;
	}
	return (binaryString);
}
