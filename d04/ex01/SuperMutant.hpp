#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "SuperMutant.hpp"
#include "Enemy.hpp"
#include <string>

// Enemy
// HP: 170
// Type: "Super Mutant"
// • On birth, displays: "Gaaah. Me want smash heads!"
// • Upon death, displays: "Aaargh..."
// • Take 3 less damage points than normal

class SuperMutant : public Enemy {
	public:
		/*************/
		/* COPLIENS' */
		/*************/
		SuperMutant();
		virtual ~SuperMutant();
		SuperMutant( SuperMutant const & src );
		SuperMutant & operator=( SuperMutant const & rhs );

		/*************/
		/* INTERFACE */
		/*************/
		virtual void takeDamage(int);
};

#endif