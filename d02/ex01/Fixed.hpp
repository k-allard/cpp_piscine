#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>

class	Fixed {
	private:
		int					_fixedPointValue;
		static int const	_numOfFractionalBits = 8;
	public:
		Fixed();
		Fixed( int const intValue);
		Fixed( float const floatValue);
		Fixed( Fixed const & src );
		~Fixed();

		Fixed & operator=( Fixed const & rhs );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		std::string toBinaryString( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs );

#endif
