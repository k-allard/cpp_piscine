#include "Dummy.hpp"
#include "ATarget.hpp"

#include <iostream>

Dummy::Dummy() : ATarget("Target Practice Dummy") { }

Dummy::~Dummy() { }

Dummy *Dummy::clone() const { return (new Dummy); }
