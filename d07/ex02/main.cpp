/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 23:51:33 by kallard           #+#    #+#             */
/*   Updated: 2021/01/21 15:41:25 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
 
int main() {
	Array<int> intArray(10);
	Array<double> doubleArray(10);
 
	for (int index = 0; index < intArray.size(); ++index) {
		intArray[index] = index;
		doubleArray[index] = index + 0.5;
	}
 
	for (int index = intArray.size() - 1; index >= 0; --index)
		std::cout << intArray[index] << "  |  " << doubleArray[index] << '\n';

	try {
		intArray[11];
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
