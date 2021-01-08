/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:13:36 by kallard           #+#    #+#             */
/*   Updated: 2021/01/08 22:04:04 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include "Zombie.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

std::string ZombieHorde::getRandomName(){
	const std::string arrayName[21] = {"Quarrelfeat", "Reyesenstein", "Burrowrub",
		"Drabblepatch", "Hedgehog", "Archenlander", 
		"Blathertooth", "Dibblering", "Grrmurphy", 
		"Undeadha", "Faulkner", "Euan", 
		"Cutthroat", "Largeparrot", "Pete", 
		"Buster", "Greasydoc", "Keyser", 
		"Inspectah", "Georgormous", "Greasyface"};
	int randIndex = rand() % 21;
	return (arrayName[randIndex]);
}

ZombieHorde::ZombieHorde(int n) : _n(n){
	if (n <= 0)
	{
		std::cerr << "Num of zombies must be 1 or more" << std::endl;
		return ;	
	}
	srand(time(NULL));
	this->_horde = new Zombie[this->_n];
	
	int i = 0;
	while (i < this->_n)
	{
		this->_horde[i].setName(this->getRandomName());
		this->_horde[i].setType("Brain eater");
		i++;
	}
}

void ZombieHorde::announce(){
	int i = 0;
	while (i < this->_n)
	{
		this->_horde[i].announce();
		i++;
	}
}

ZombieHorde::~ZombieHorde(){
	delete [] this->_horde;
}