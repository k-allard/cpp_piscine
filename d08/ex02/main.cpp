#include "mutantstack.hpp"

int main () {
	MutantStack<int> mstack;
	mstack.push(5); 
	mstack.push(17);
	std::cout << "top is " << mstack.top() << std::endl; 
	mstack.pop();
	std::cout << "size is " << mstack.size() << std::endl;
	mstack.push(3); 
	mstack.push(5); 
	mstack.push(737); 
	mstack.push(0);
	std::cout << "size is " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin(); 
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "mstack1 is | ";
	while (it != ite) {
		std::cout << *it << " | ";
		++it; 
	}
	std::cout << std::endl;
	std::stack<int> s(mstack); 

	std::cout << "********* Extra tests *********" << std::endl; 
	MutantStack<int> mstack2;
	mstack2.push(4); 
	mstack2.push(8);
	MutantStack<int>::iterator it2 = mstack2.begin(); 
	MutantStack<int>::iterator ite2 = mstack2.end();

	std::cout << "mstack2 is | ";
	while (it2 != ite2) {
		std::cout << *it2 << " | ";
		++it2; 
	}
	std::cout << std::endl;
	mstack2.swap(mstack);
		std::cout << "After swap :\n";

	it = mstack.begin(); 
	ite = mstack.end();
	std::cout << "mstack1 is | ";
	while (it != ite) {
		std::cout << *it << " | ";
		++it; 
	}
	std::cout << std::endl;
	it2 = mstack2.begin(); 
	ite2 = mstack2.end();
	std::cout << "mstack2 is | ";
	while (it2 != ite2) {
		std::cout << *it2 << " | ";
		++it2; 
	}
	std::cout << std::endl;

	std::cout << "mstack2 reversed is | ";
	MutantStack<int>::reverse_iterator it_r = mstack2.rbegin(); 
	while (it_r != mstack2.rend()) {
		std::cout << *it_r << " | ";
		++it_r;
	} 
	std::cout << std::endl;
	return 0;
}