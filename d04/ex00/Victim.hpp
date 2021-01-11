#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <string>

class	Victim {
	private:
		std::string			_name;
	public:
		Victim();
		Victim( std::string name);
		Victim( Victim const & src );
		~Victim();
		Victim & operator=( Victim const & rhs );

		/***********/
		/* GETTERS */
		/***********/
		std::string get_name() const;

		/***********/
		/* SETTERS */
		/***********/
		void set_name(std::string name);

		/*************/
		/* INTERFACE */
		/*************/
		virtual void getPolymorphed() const;
};

std::ostream & operator<<( std::ostream & o, Victim const & rhs );

#endif
