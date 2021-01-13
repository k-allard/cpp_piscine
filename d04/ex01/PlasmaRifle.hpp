#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"
#include <string>

// • Weapon:
// 	◦ Name: "Plasma Rifle"
// 	◦ Damage: 21
// 	◦ AP cost: 5
// 	◦ Output of attack(): "* piouuu piouuu piouuu *"

class PlasmaRifle : public AWeapon {
	public:
		/*************/
		/* COPLIENS' */
		/*************/
		PlasmaRifle();
		virtual ~PlasmaRifle();
		PlasmaRifle( PlasmaRifle const & src );
		PlasmaRifle & operator=( PlasmaRifle const & rhs );

		/*************/
		/* INTERFACE */
		/*************/
		virtual void attack() const ;
};

#endif