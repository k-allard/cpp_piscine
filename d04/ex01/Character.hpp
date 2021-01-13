#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include "CommonHeader.hpp"

class Character {

private: 
	std::string _name;
	int _numOfAP;
	AWeapon *_weapon;
public:
	/*************/
	/* COPLIENS' */
	/*************/
	Character();
	Character(std::string const & name); 
	Character( Character const & src );
	Character & operator=( Character const & rhs );
	~Character();

	/*************/
	/* INTERFACE */
	/*************/
	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);

	/***********/
	/* GETTERS */
	/***********/
	const std::string & getName() const;
	AWeapon * getWeapon() const;
	int getNumOfAP() const ;

};

std::ostream & operator<<( std::ostream & o, Character const & rhs);

#endif