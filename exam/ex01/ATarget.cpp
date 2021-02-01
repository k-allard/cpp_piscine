#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

ATarget::ATarget(std::string type) {
	this->type = type;
}

ATarget::~ATarget() { }
	
std::string const & ATarget::getType() const { return (this->type); }

void ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << this->type << " has been " << spell.getEffects() << std::endl;
} 
