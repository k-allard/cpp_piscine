#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <string>

class AWeapon {
	protected:
		std::string _name;
		int _damage;
		int _APCost;

	public:
		/*************/
		/* COPLIENS' */
		/*************/
		AWeapon();
		AWeapon(std::string const & name, int apcost, int damage); 
		virtual ~AWeapon();
		AWeapon( AWeapon const & src );
		AWeapon & operator=( AWeapon const & rhs );

		/***********/
		/* GETTERS */
		/***********/
		const std::string & getName() const;
		int getAPCost() const;
		int getDamage() const;
		
		/*************/
		/* INTERFACE */
		/*************/
		virtual void attack() const = 0;
};

#endif