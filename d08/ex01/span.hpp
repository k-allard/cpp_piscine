#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <string>
#include <iostream>
#include <set>


class Span {
	protected: 
		int					_N;		//max num of ints to store
		std::multiset<int>	_mSet;	//multiset of ints

	public:
		/*************/
		/* COPLIENS' */
		/*************/
		Span();
		Span(int N); 
		Span( const Span & src );
		Span & operator=( const Span & rhs );
		~Span();
		
		/*************/
		/* INTERFACE */
		/*************/
		void				addNumber(int n);
		void				addVector(std::vector<int> arr);
		int					shortestSpan();
		int					longestSpan();
		void				printSet();
		int 				getAnInt(int n);

		/***********/
		/* GETTERS */
		/***********/
		int					get_N() const ;
		std::multiset<int>	get_mSet() const ;
};

#endif
