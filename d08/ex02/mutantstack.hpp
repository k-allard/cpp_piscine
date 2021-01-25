#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack & src);
		virtual ~MutantStack();
		MutantStack &operator=(const MutantStack & rhs);

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
};

#include "mutantstack.cpp"

#endif