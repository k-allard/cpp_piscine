#pragma once
#include <string>
class ASpell;

class ATarget {
private:
	std::string type;
	// std::string effects;

public:
	ATarget();
	~ATarget();
	ATarget(ATarget const & src);
	ATarget & operator=(ATarget const & rhs);

	ATarget(std::string type);

	std::string const & getType() const ;

	void getHitBySpell(ASpell const &spell) const ;

	virtual ATarget *clone() const = 0;
};
