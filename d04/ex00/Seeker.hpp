#ifndef SEEKER_HPP
# define SEEKER_HPP

#include <string>
#include "Victim.hpp"

class	Seeker : public Victim {
	private:
		std::string			_name;

	public:
		Seeker();
		Seeker( std::string name);
		Seeker( Seeker const & src );
		~Seeker();
		Seeker & operator=( Seeker const & rhs );

		/*************/
		/* INTERFACE */
		/*************/
		virtual void getPolymorphed() const ;
};

#endif
