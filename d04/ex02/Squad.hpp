#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad {
	private:
		typedef	struct		s_squad
		{
			ISpaceMarine	*unit;
			struct s_squad	*next;
		}					t_squad;
		t_squad				*_head;
		int					_numOfUnits;

	public:
		/*************/
		/* COPLIENS' */
		/*************/
		Squad();
		virtual ~Squad();
		Squad( Squad const & src );
		Squad & operator=( Squad const & rhs );

		/***********/
		/* GETTERS */
		/***********/
		virtual int getCount() const ;

		/*************/
		/* INTERFACE */
		/*************/
		virtual ISpaceMarine* getUnit(int) const ;
		virtual int push(ISpaceMarine*) ;
};

#endif