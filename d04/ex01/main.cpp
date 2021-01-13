/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:38:12 by kallard           #+#    #+#             */
/*   Updated: 2021/01/13 20:58:39 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Enemy.hpp"
#include "AWeapon.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"

#include <iostream>

int main() {
	Character* me = new Character("me"); 
	std::cout << *me;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle(); 
	AWeapon* pf = new PowerFist();
	
	me->equip(pr); 
	std::cout << *me; 
	me->equip(pf);
	
	me->attack(b);
	std::cout << *me; 
	me->equip(pr); 
	std::cout << *me; 
	me->attack(b); 
	std::cout << *me;
	me->attack(b);					//RadScorpion dies!!
	std::cout << *me;

	/***************/
	/* EXTRA TESTS */
	/***************/
	Enemy* sm = new SuperMutant(); //170 hp
	me->equip(pf);
	me->attack(sm);					//-47 hp
	me->attack(sm); 				//-47 hp
	std::cout << *me;
	me->attack(sm);					//not enought AP to perform this attack
	me->recoverAP();				//+10 AP
	me->attack(sm); 				//-47 hp
	me->attack(sm); 				//-47 hp SuperMutant dies!!
	std::cout << *me;
	
	delete pr;
	delete pf;
	delete me;
	return 0; 
}