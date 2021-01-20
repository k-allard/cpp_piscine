/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 23:51:33 by kallard           #+#    #+#             */
/*   Updated: 2021/01/20 23:51:44 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
 
int main()
{
	Array<int> intArray(10);
	Array<double> doubleArray(10);
 
	for (int count = 0; count < intArray.size(); ++count) {
		intArray[count] = count;
		doubleArray[count] = count + 0.5;
	}
 
	for (int count = intArray.size()-1; count >= 0; --count)
		std::cout << intArray[count] << "  |  " << doubleArray[count] << '\n';

	try {
		intArray[11];
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
		return 0;
}
