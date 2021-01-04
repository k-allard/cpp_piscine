/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:37:27 by kallard           #+#    #+#             */
/*   Updated: 2021/01/04 13:37:28 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

void ponyOnTheStack()
{
	Pony pony1("Sparkle", 5, "purple");
}

void ponyOnTheHeap()
{
	Pony *pony2 = new Pony("Pinkie", 4, "pink");
	delete pony2;
}

int main()
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return (0);
}
