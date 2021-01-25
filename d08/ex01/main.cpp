/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:55:59 by kallard           #+#    #+#             */
/*   Updated: 2021/01/25 19:48:15 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "span.hpp"

int main() {
	std::cout << "************ | Test 1 | ************" << std::endl; 
	Span sp = Span(5);
	sp.addNumber(5);
	sp.printSet();
	try { 
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	sp.addNumber(3); 
	sp.addNumber(17); 
	sp.addNumber(9); 
	sp.addNumber(11);
	try { sp.addNumber(8); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	sp.printSet();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << "************ | Test 2 | ************" << std::endl; 

	Span sp2 = Span(7);
	sp2.addNumber(21); 
	sp2.addNumber(22);
	
	int arr[] = { 2, 4, 1, 3, 5, 6 };
	std::vector<int> myVector2;
	myVector2.assign(arr, arr + (sizeof(arr) / sizeof(arr[0])));
	try { 
		sp2.addVector(myVector2); 
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	int arr2[] = { 2, 4, 1, 3, 5 }; 
	std::vector<int> myVector;
	myVector.assign(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])));
	sp2.addVector(myVector);
	
	sp2.printSet();

	std::cout << "************ | Test 3 | ************" << std::endl; 
	
	Span sp3 = Span(11111);
	int arr3[11111];
	for (int i = 0; i < 11111; i++) {
		arr3[i] = i;
	}
	std::vector<int> vectr2;
	vectr2.assign(arr3, arr3 + (sizeof(arr3) / sizeof(arr3[0])));
	try { 
		sp3.addVector(vectr2); 
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	try { 
		std::cout << "Element #9900 is [" << sp3.getAnInt(9900) << "]\n";
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	return (0);

}
