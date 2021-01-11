/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:27 by kallard           #+#    #+#             */
/*   Updated: 2021/01/11 13:41:43 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

void rangedAttack(FragTrap &robot1, FragTrap &robot2)
{
	if (robot1.rangedAttack(robot2.get_name()))
		robot2.takeDamage(robot1.get_rangedAttackDamage());
}

void rangedAttack(ScavTrap &robot1, FragTrap &robot2)
{
	if (robot1.rangedAttack(robot2.get_name()))
		robot2.takeDamage(robot1.get_rangedAttackDamage());
}

void rangedAttack(FragTrap &robot1, ScavTrap &robot2)
{
	if (robot1.rangedAttack(robot2.get_name()))
		robot2.takeDamage(robot1.get_rangedAttackDamage());
}

void rangedAttack(ScavTrap &robot1, ScavTrap &robot2)
{
	if (robot1.rangedAttack(robot2.get_name()))
		robot2.takeDamage(robot1.get_rangedAttackDamage());
}

void meleeAttack(FragTrap &robot1, FragTrap &robot2) {
	if (robot1.meleeAttack(robot2.get_name()))
		robot2.takeDamage(robot1.get_meleeAttackDamage());
}

void meleeAttack(ScavTrap &robot1, FragTrap &robot2) {
	if (robot1.meleeAttack(robot2.get_name()))
		robot2.takeDamage(robot1.get_meleeAttackDamage());
}

void meleeAttack(FragTrap &robot1, ScavTrap &robot2) {
	if (robot1.meleeAttack(robot2.get_name()))
		robot2.takeDamage(robot1.get_meleeAttackDamage());
}

void meleeAttack(ScavTrap &robot1, ScavTrap &robot2) {
	if (robot1.meleeAttack(robot2.get_name()))
		robot2.takeDamage(robot1.get_meleeAttackDamage());
}

void vaulthunter_dot_exe(FragTrap &robot1, FragTrap &robot2) {
	if (robot1.vaulthunter_dot_exe(robot2.get_name()))
		robot2.takeDamage(25);
}

int main( void ) {
	srand(time(NULL));

	FragTrap Bob = FragTrap("Bob");
	ScavTrap Lucy = ScavTrap("Lucy");
	NinjaTrap Sally = NinjaTrap("Sally");

	std::cout << "\x1b[36m************\n*  FIGHT!  *\n************\x1b[0m" << std::endl;

	Lucy.challengeNewcomer(Sally);

	if (Sally.ninjaShoebox(Lucy))
		Lucy.takeDamage(50);
	if (Sally.ninjaShoebox(Bob))
		Bob.takeDamage(50);

	std::cout << "\x1b[36m*****************\n* GAME FINISHED *\n*****************\x1b[0m" << std::endl;
	return 0;
}
