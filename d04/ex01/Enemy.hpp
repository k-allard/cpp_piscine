#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <string>

class Enemy {
	protected: 
		int			_hitPoints; 
		std::string	_type;

	public:
		/*************/
		/* COPLIENS' */
		/*************/
		Enemy();
		Enemy(int hp, std::string const & type);
		virtual ~Enemy();
		Enemy( Enemy const & src );
		Enemy & operator=( Enemy const & rhs );

		/***********/
		/* GETTERS */
		/***********/
		const std::string & getType() const;
		int getHP() const;

		/*************/
		/* INTERFACE */
		/*************/
		virtual void takeDamage(int);
};

#endif