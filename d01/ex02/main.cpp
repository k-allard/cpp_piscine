/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:27 by kallard           #+#    #+#             */
/*   Updated: 2021/01/04 21:43:26 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieEvent.hpp"

int main()
{
	ZombieEvent	zombieEvent;
	Zombie		*zombie;
	
	zombieEvent.setZombieType("Vegan");
	zombie = zombieEvent.newZombie("Vasya");
	zombie->announce();
	delete zombie;
	zombieEvent.randomChump();
	zombieEvent.setZombieType("Brain eater");
	zombieEvent.randomChump();
	zombieEvent.randomChump();

	return (0);
}
