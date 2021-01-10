/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:27 by kallard           #+#    #+#             */
/*   Updated: 2021/01/10 17:29:13 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

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
	std::srand(std::time(NULL));

	// FragTrap Bob = FragTrap("Bob");
	// FragTrap Sam = FragTrap("Sam");
	// FragTrap Din = FragTrap("Din");
	// ScavTrap Lucy = ScavTrap("Lucy");
	
	// rangedAttack(Din, Sam);
	// meleeAttack(Din, Bob);
	// meleeAttack(Din, Bob);
	// rangedAttack(Din, Sam);
	// rangedAttack(Din, Bob);
	// rangedAttack(Din, Sam);
	// meleeAttack(Din, Sam);

	// Din.beRepaired(30);
	
	// meleeAttack(Din, Bob);
	// meleeAttack(Bob, Din);
	// vaulthunter_dot_exe(Din, Sam);
	// Bob.beRepaired(30);
	// vaulthunter_dot_exe(Bob, Sam);
	// vaulthunter_dot_exe(Bob, Din);
	// vaulthunter_dot_exe(Bob, Din);

	// rangedAttack(Lucy, Sam);
	// meleeAttack(Din, Lucy);
	// meleeAttack(Lucy, Bob);
	// rangedAttack(Lucy, Sam);
	// rangedAttack(Bob, Lucy);

	// FragTrap Rob = FragTrap("Rob");
	// Lucy.challengeNewcomer(Rob);

	// NinjaTrap Sally = NinjaTrap("Sally");

	// Sally.ninjaShoebox(Lucy);

	SuperTrap Jey = SuperTrap("Jey");
	// Lucy.challengeNewcomer(Jey);

	std::cout << "*****************\n* GAME FINISHED *\n*****************" << std::endl;
	return 0;
}
