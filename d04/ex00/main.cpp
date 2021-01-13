/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:27 by kallard           #+#    #+#             */
/*   Updated: 2021/01/12 16:07:38 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Peon.hpp"
#include "Victim.hpp"
#include "Sorcerer.hpp"
#include "Seeker.hpp"

int main( void ) {
	// Sorcerer Bobby;
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	// Seeker tom("Tom");
	
	std::cout << robert << jim << joe;// << tom;
	robert.polymorph(jim); 
	robert.polymorph(joe);
	// robert.polymorph(tom);

	return 0;
}
