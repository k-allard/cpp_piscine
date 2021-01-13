#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "RadScorpion.hpp"
#include "Enemy.hpp"
#include <string>

// Enemy
//  HP: 80
//  Type: "RadScorpion"
// ◦ On birth, displays: "* click click click *" 
// ◦ Upon death, displays: "* SPROTCH *"

class RadScorpion : public Enemy {
	public:
		/*************/
		/* COPLIENS' */
		/*************/
		RadScorpion();
		RadScorpion( RadScorpion const & src );
		RadScorpion & operator=( RadScorpion const & rhs );
		virtual ~RadScorpion();
};

#endif