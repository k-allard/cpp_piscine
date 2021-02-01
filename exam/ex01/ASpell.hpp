#pragma once
#include <string>
class ATarget;

class ASpell {
private:
	std::string name;
	std::string effects;

public:
	ASpell();
	virtual ~ASpell();
	ASpell(ASpell const & src);
	ASpell & operator=(ASpell const & rhs);

	ASpell(std::string name, std::string effects);

	std::string const & getName() const ;
	std::string const & getEffects() const ;

	void launch(ATarget const &target) const ;

	virtual ASpell *clone() const = 0; //ASpell *ASpell::clone() const { return (new ASpell); }


};
