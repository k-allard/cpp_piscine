/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 00:21:12 by kallard           #+#    #+#             */
/*   Updated: 2021/01/14 00:21:15 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"
#include <iostream>

int main() {
	ISpaceMarine* bob = new TacticalMarine; 
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i) {
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry(); 
		cur->rangedAttack(); 
		cur->meleeAttack();
	}

	std::cout << "/*** EXTRA TESTS ***/" << std::endl;
	ISpaceMarine* tmp = vlc->getUnit(-1);
	if (tmp)
		tmp->battleCry(); 
	else
		std::cout << "Incorrect index" << std::endl;
	ISpaceMarine* tmp2 = vlc->getUnit(2);
	if (tmp2)
		tmp2->battleCry(); 
	else
		std::cout << "Incorrect index" << std::endl;
	std::cout << "There are " << vlc->getCount() << " marines in the squad" << std::endl;
	std::cout << "/*******************/" << std::endl;


	delete vlc;
	return 0; 
}