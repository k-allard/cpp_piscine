#ifndef SORCERER_HPP
# define SORCERER_HPP

#include "CommonHeader.hpp"
#include <string>

class	Sorcerer {
	private:
		std::string			_name;
		std::string			_title;
		Sorcerer();
	public:
		Sorcerer( std::string name ,  std::string title);
		Sorcerer( Sorcerer const & src );
		~Sorcerer();
		Sorcerer & operator=( Sorcerer const & rhs );

		/***********/
		/* GETTERS */
		/***********/
		std::string get_name() const;
		std::string get_title() const;

		/***********/
		/* SETTERS */
		/***********/
		void set_name( std::string name );
		void set_title( std::string title ) ;

		/*************/
		/* INTERFACE */
		/*************/
		void polymorph( Victim const & target ) const ;
		
};

std::ostream & operator<<( std::ostream & o, Sorcerer const & rhs );

#endif
