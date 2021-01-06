#include "Brain.hpp"
#include "Human.hpp"

Human::Human() : brain(30, 120) {}

Human::~Human() {}

std::string Human::identify() const {
	return(this->brain.identify());
}

const Brain& Human::getBrain() const {
	const Brain& brainRef = this->brain;
	return (brainRef);
}
