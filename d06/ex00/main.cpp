/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:40:41 by kallard           #+#    #+#             */
/*   Updated: 2021/01/18 23:10:29 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac == 2) {
		Convert n(av[1]);
		n.convertInput();
		std::cout << n;
		return (0);
	}
	std::cout << "Program takes one argument\n";
	return (1);
}
