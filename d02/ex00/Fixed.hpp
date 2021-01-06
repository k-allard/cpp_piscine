#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>

class	Fixed{
	private:
		int					_fixedPointValue;
		static int const	_numOfFractionalBits = 8;
	public:
		Fixed();
		Fixed( Fixed const & src );
		~Fixed();

		Fixed & operator=( Fixed const & rhs );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
