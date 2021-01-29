/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:45:55 by kallard           #+#    #+#             */
/*   Updated: 2021/01/25 23:45:56 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

#include "easyFind.hpp"

int main() {
	std::vector<int> myVector;
	std::list<int> myList;

	for (int index = 0; index < 5; ++index) {
		myVector.push_back(index);
		myList.push_back(index);
	}
	std::vector<int>::const_iterator vectorIter;
	std::list<int>::const_iterator listIter;
	try {
		vectorIter = easyFind(myVector, 2);
		listIter = easyFind(myList, 3);
		std::cout << *vectorIter << " | " << *listIter << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
