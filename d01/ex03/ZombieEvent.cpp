/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:13:36 by kallard           #+#    #+#             */
/*   Updated: 2021/01/04 21:43:12 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

Zombie *ZombieEvent::newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name, this->type);
	return (zombie);
}

void ZombieEvent::randomChump()
{
	const std::string arrayName[10] = {"Quarrelfeat", "Reyesenstein", "Burrowrub", "Drabblepatch", "Hedgehog", "Archenlander", "Blathertooth", "Dibblering", "Grrmurphy", "Undeadha"};
	int randIndex = rand() % 10;
	Zombie zombie(arrayName[randIndex], this->type);
	zombie.announce();
}

void ZombieEvent::setZombieType(std::string	type)
{
	this->type = type;
}

ZombieEvent::ZombieEvent()
{
	srand(time(NULL));
	this->type = "";
}