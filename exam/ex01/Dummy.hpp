#pragma once
#include <string>
#include "ATarget.hpp"

class Dummy : public ATarget {
public:
	Dummy();
	~Dummy();

	Dummy *clone() const;
};
