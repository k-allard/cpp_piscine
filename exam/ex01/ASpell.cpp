#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

ASpell::ASpell(std::string name, std::string effects) {
	this->name = name;
	this->effects = effects;
}

ASpell::~ASpell() { }
	
std::string const & ASpell::getName() const { return (this->name); }
std::string const & ASpell::getEffects() const { return (this->effects); }

void ASpell::launch(ATarget const &target) const {
		target.getHitBySpell(* this);
}
