#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <deque>

#include <iostream>

template<typename T>
class MutantStack : public std::stack<T> {

public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack & src) : std::stack<T>(src) {}
	virtual ~MutantStack() {}
	MutantStack &operator=(const MutantStack & rhs) {
		this->c = rhs.c;
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

	// iterator begin() {
		
	// 	return (this->c.begin());
	// }
	iterator begin();

	iterator end() {
		return this->c.end();
	}

	reverse_iterator rbegin(void) {
		return this->c.rbegin();
	}

	reverse_iterator rend(void) {
		return this->c.rend();
	}
};

#include "mutantstack.cpp"

#endif