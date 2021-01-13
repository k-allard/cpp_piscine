#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"
#include <string>

// • Weapon:
// 	◦ Name: "Power Fist"
// 	◦ Damage: 50
// 	◦ AP cost: 8
// 	◦ Output of attack(): "* pschhh... SBAM! *"

class PowerFist : public AWeapon {
	public:
		/*************/
		/* COPLIENS' */
		/*************/
		PowerFist();
		virtual ~PowerFist();
		PowerFist( PowerFist const & src );
		PowerFist & operator=( PowerFist const & rhs );

		/*************/
		/* INTERFACE */
		/*************/
		virtual void attack() const ;
};

#endif