#pragma once
#include <string>
#include <vector>
#include "ASpell.hpp"

class Warlock {
private:
	std::string name;
	std::string title;
	std::vector<ASpell *> spells;

public:
	Warlock();
	~Warlock();
	Warlock(Warlock const & src);
	Warlock & operator=(Warlock const & rhs);

	Warlock(std::string name, std::string title);

	std::string const & getName() const ;
	std::string const & getTitle() const ;

	void setTitle(std::string const & t);

	void introduce() const;

	void learnSpell(ASpell *spell);//makes the Warlock learn a spell
	void forgetSpell(std::string spellName);//  makes the Warlock forget the spell. If it's not a known spell, does nothing.
	void launchSpell(std::string spellName, ATarget & target);
//   launches the spell on the selected target. If it's not a known spell, does
//   nothing.
};
