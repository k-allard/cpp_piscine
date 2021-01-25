/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:35:41 by kallard           #+#    #+#             */
/*   Updated: 2021/01/25 23:41:37 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() { }

template<typename T>
MutantStack<T>::MutantStack(const MutantStack & src) : std::stack<T>(src) { }
	
template<typename T>
MutantStack<T>::~MutantStack() { }

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> & rhs) {
	this->c = rhs.c;
	return *this;
}
	
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
	return (this->c.rend());
}
