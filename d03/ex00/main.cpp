/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:27 by kallard           #+#    #+#             */
/*   Updated: 2021/01/09 00:35:46 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include <stdlib.h>
#include <time.h>

void rangedAttack(FragTrap &robot1, FragTrap &robot2)
{
	if (robot1.get_hitPoints() == 0) {
		std::cout << " ❌ " << robot1.get_name() << " tried to attack, but has no HP left"; 
		std::cout << std::endl;
		return ;
	}
	if (robot1.get_energyPoints() < 10) {
		std::cout << " ❌ " << robot1.get_name() << " tried to attack at range, ";
		std::cout << "but doesn't have enough energy points" << std::endl;
		return ;
	}
	robot1.rangedAttack(robot2.get_name());
	robot2.takeDamage(robot1.get_rangedAttackDamage());
}

void meleeAttack(FragTrap &robot1, FragTrap &robot2) {
	if (robot1.get_hitPoints() == 0) {
		std::cout << " ❌ " << robot1.get_name() << " tried to attack, but has no HP left"; 
		std::cout << std::endl;
		return ;
	}
	if (robot1.get_energyPoints() < 5) {
		std::cout << " ❌ " << robot1.get_name() << " tried to melee attack, ";
		std::cout << "but doesn't have enough energy points" << std::endl;
		return ;
	}
	robot1.meleeAttack(robot2.get_name());
	robot2.takeDamage(robot1.get_meleeAttackDamage());
}

void vaulthunter_dot_exe(FragTrap &robot1, FragTrap &robot2) {
	if (robot1.get_hitPoints() == 0) {
		std::cout << " ❌ " << robot1.get_name() << " tried to attack, but has no HP left"; 
		std::cout << std::endl;
		return ;
	}
	if (robot1.get_energyPoints() < 25) {
		std::cout << " ❌ " << robot1.get_name() << " tried to attack, ";
		std::cout << "but doesn't have enough energy points" << std::endl;
		return ;
	}
	robot1.vaulthunter_dot_exe(robot2.get_name());
	robot2.takeDamage(25);
}

int main( void ) {
	srand(time(NULL));

	FragTrap Bob = FragTrap("Bob");
	FragTrap Sam = FragTrap("Sam");
	FragTrap Din = FragTrap("Din");
	
	rangedAttack(Din, Sam);
	meleeAttack(Din, Bob);
	meleeAttack(Din, Bob);
	rangedAttack(Din, Sam);
	rangedAttack(Din, Bob);
	rangedAttack(Din, Sam);
	meleeAttack(Din, Sam);

	Din.beRepaired(30);
	
	meleeAttack(Din, Bob);
	meleeAttack(Bob, Din);
	vaulthunter_dot_exe(Din, Sam);
	Bob.beRepaired(30);
	vaulthunter_dot_exe(Bob, Sam);
	vaulthunter_dot_exe(Bob, Din);
	vaulthunter_dot_exe(Bob, Din);

	return 0;
}
