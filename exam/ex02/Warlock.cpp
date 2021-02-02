#include "Warlock.hpp"
#include <iostream>

Warlock::Warlock(std::string name, std::string title) {
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {
	std::cout << this->name << ": My job here is done!\n";
}
	
std::string const & Warlock::getName() const { return (this->name); }
std::string const & Warlock::getTitle() const { return (this->title); }

void Warlock::setTitle(std::string const & t) { this->title = t; }

void Warlock::introduce() const {
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

//makes the Warlock learn a spell
void Warlock::learnSpell(ASpell *spell) {
 	std::vector<ASpell *>::iterator it = spells.begin();
    std::vector<ASpell *>::iterator ite = spells.end();
    if (!spell)
		return ;
	while (it != ite) {
		if ((*it)->getName() == spell->getName())
			return ;
		it++;
	}
	spells.push_back(spell->clone());
}

//  makes the Warlock forget the spell. If it's not a known spell, does nothing.
void Warlock::forgetSpell(std::string spellName) {
 	std::vector<ASpell *>::iterator it = spells.begin();
    std::vector<ASpell *>::iterator ite = spells.end();
    while (it != ite) {
        if ((*it)->getName() == spellName) {
            delete *it;
            spells.erase(it);
            return ;
        }
        it++;
    }
}

//   launches the spell on the selected target. If it's not a known spell, does
//   nothing.
void Warlock::launchSpell(std::string spellName, ATarget & target) {
 	std::vector<ASpell *>::iterator it = spells.begin();
    std::vector<ASpell *>::iterator ite = spells.end();
    while (it != ite)
    {
        if ((*it)->getName() == spellName) {
            (*it)->launch(target);
            return ;
        }
    	it++;
    }
}
