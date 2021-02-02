#include "Fwoosh.hpp"
#include "ASpell.hpp"

#include <iostream>

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") { }

Fwoosh::~Fwoosh() { }

Fwoosh *Fwoosh::clone() const { return (new Fwoosh); }

