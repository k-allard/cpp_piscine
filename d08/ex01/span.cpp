/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:47:26 by kallard           #+#    #+#             */
/*   Updated: 2021/01/25 19:49:24 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "span.hpp"
#include <set>

/*************/
/* COPLIENS' */
/*************/
Span::Span() : _N(0) {}

Span::Span(int N) : _N(N) { }

Span::Span(const Span & src) { *this = src; }

Span & Span::operator=( const Span & rhs ) {
	_mSet = rhs.get_mSet();
	_N = rhs.get_N();
	return (*this);
}

Span::~Span() {}

/*************/
/* INTERFACE */
/*************/
void Span::addNumber(int n) {
	if (static_cast<int>(_mSet.size()) < _N)
		_mSet.insert(n);
	else
		throw std::out_of_range("Set is full");
}


void Span::addVector(std::vector<int> arr) {
	int arrLength =  arr.size();
	if (_N - static_cast<int>(_mSet.size()) < arrLength)
		throw std::out_of_range("Int array can not be added");
	_mSet.insert(arr.begin(), arr.end());
}

int Span::shortestSpan() {
	if (static_cast<int>(_mSet.size()) < 2)
		throw std::out_of_range("Not enough elements to calculate a span");
	else {
		std::multiset<int>::iterator it = _mSet.begin();
		std::multiset<int>::iterator next = _mSet.begin();
		next++;
		int min = std::abs(*next - *it);
		while (next != _mSet.end())  {
			if (std::abs(*next - *it) < min)
				min = std::abs(*next - *it);
			next++;
			it++;
		}
		return min;
	}
}

int Span::longestSpan() {
	if (static_cast<int>(_mSet.size()) < 2)
		throw std::out_of_range("Not enough elements to calculate a span");
	else {
		std::multiset<int>::iterator it = _mSet.end();
		int maxValue = *(--it);
		return (maxValue - *_mSet.begin());
	}
}

void Span::printSet() {
	std::multiset<int>::iterator it = _mSet.begin();
	while (it != _mSet.end())  {
		std::cout << *it << " | ";
		it++;
	}
	std::cout << std::endl;
}

int Span::getAnInt(int n) {
	if (n >= static_cast<int>(_mSet.size()) || n < 0)
		throw std::out_of_range("No such element");

	std::multiset<int>::iterator it = _mSet.begin();
	int i = 0;
	while (i < n) {
		it++;
		i++;
	}
	return (*it);
}

/***********/
/* GETTERS */
/***********/
int Span::get_N() const { return _N; }
std::multiset<int> Span::get_mSet() const { return _mSet; }
