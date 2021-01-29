/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:21:14 by kallard           #+#    #+#             */
/*   Updated: 2021/01/21 16:19:51 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

void	increment_int(int &ch) {
		ch++;
}

void	to_upper_case(char &ch) {
	if (ch >= 'a' && ch <= 'z')
		ch = ch - ('a' - 'A');
}

int main() {
	std::cout << "\n********* char array *********" << std::endl;

	char array1[] = "abc 123";
	std::cout << "Array before : \"" << array1 << "\"" << std::endl;
    std::cout << "iter() . . .\n";
    ::iter(array1, sizeof(array1), to_upper_case);
    std::cout << "Array after : \"" << array1 << "\"" << std::endl;
	
	std::cout << "\n********* int array *********" << std::endl;
	int array2[5] = {0, 1, 2, 3, 4};
	std::cout << "Array before : \"";
	for (int i = 0; i < 5; i++) {
		std::cout << array2[i];
	}
	std::cout << "\"" << std::endl;
    std::cout << "iter() . . .\n";
    ::iter(array2, 5, increment_int);
    std::cout << "Array after : \"";
		for (int i = 0; i < 5; i++) {
		std::cout << array2[i];
	}
	std::cout << "\"" << std::endl;

	std::cout << "\n********* subject test *********" << std::endl;
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];
	iter( tab, 5, print );
	iter( tab2, 5, print );
	return 0;
	return 0;
}


