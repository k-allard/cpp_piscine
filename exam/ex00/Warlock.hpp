#pragma once
#include <string>

class Warlock {
private:
	std::string name;
	std::string title;

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
};
