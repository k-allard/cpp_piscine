/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:21:14 by kallard           #+#    #+#             */
/*   Updated: 2021/01/21 00:33:17 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

class Awesome {
	public :
		int getN() const {return (this->_n);} 
		Awesome(int n) : _n(n) { };
		bool operator==(Awesome const & rhs) { return (this->_n == rhs._n); }
		bool operator!=(Awesome const & rhs) { return (this->_n != rhs._n); }
		bool operator>(Awesome const & rhs) { return (this->_n > rhs._n); }
		bool operator<(Awesome const & rhs) { return (this->_n < rhs._n); }
		bool operator>=(Awesome const & rhs) const { return (this->_n >= rhs._n); }
		bool operator<=(Awesome const & rhs) const { return (this->_n <= rhs._n); }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & src) {
	o << src.getN();
	return (o);
}


int main( void ) {
	std::cout << "********* subject tests 1 *********" << std::endl;

	int a = 2;
	int b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "After swap :" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "string1";
	std::string d = "string2";
	std::cout << std::endl << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap :" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
 
	char c1 = 'v';
	char c2 = '+';
	 std::cout << std::endl << c1 << " | " << c2 << std::endl;
	::swap(c1, c2);
	std::cout << "After swap :" << std::endl;
    std::cout << c1 << " | " << c2 << std::endl;
	
	std::cout << "\n********* subject tests 2 *********" << std::endl;
	Awesome a1 = Awesome(2);
	Awesome a2 = Awesome(4);

	std::cout << a1 << " | " << a2 << std::endl;
	std::cout << "Trying swap . . ." << std::endl;
	::swap(a1, a2);
	std::cout << a1 << " | " << a2 << std::endl;
	std::cout << "Trying min . . ." << std::endl;
	std::cout << ::min(a1, a2) << std::endl;
	std::cout << "Trying max . . ." << std::endl;
	std::cout << ::max(a1, a2) << std::endl;


	return (0);
}