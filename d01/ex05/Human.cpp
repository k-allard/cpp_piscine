#include "Brain.hpp"
#include "Human.hpp"

Human::Human() {
	this->brain = new Brain(30, 120);
}

Human::~Human(){
	delete this->brain;
}

std::string Human::identify(){
	return(this->brain->identify());
}

Brain& Human::getBrain(){
	Brain& brainRef = *(this->brain);
	return (brainRef);
}
