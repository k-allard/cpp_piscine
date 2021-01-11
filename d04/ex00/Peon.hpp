#ifndef PEON_HPP
# define PEON_HPP

#include <string>
#include "Victim.hpp"

class	Peon : public Victim {
	private:
		std::string			_name;

	public:
		Peon();
		Peon( std::string name);
		Peon( Peon const & src );
		~Peon();
		Peon & operator=( Peon const & rhs );

		/*************/
		/* INTERFACE */
		/*************/
		virtual void getPolymorphed() const ;
};

#endif
