#include <iostream>
#include <string>
#include <time.h>

class Base {
public:
	virtual ~Base() { };
};

class A : public Base { };
class B : public Base { };
class C : public Base { };

void identify_from_reference(Base &p) {
	try {
		A &try_a = dynamic_cast<A &>(p);
		(void)try_a;
		std::cout << "Class A identified by reference!\n";
	}
	catch (std::exception &e) { }
	try {
		B &try_b = dynamic_cast<B &>(p);
		(void)try_b;
		std::cout << "Class B identified by reference!\n";
	}
	catch (std::exception &e) { }
	try {
		C &try_c = dynamic_cast<C &>(p);
		(void)try_c;
		std::cout << "Class C identified by reference!\n";
	}
	catch (std::exception &e) { }
}

void identify_from_pointer(Base *p) {
	A *try_a = dynamic_cast<A *>(p);
	B *try_b = dynamic_cast<B *>(p);
	C *try_c = dynamic_cast<C *>(p);

	if (try_a)
		std::cout << "Class A identified by pointer!\n";
	else if (try_b)
		std::cout << "Class B identified by pointer!\n";
	else if (try_c)
		std::cout << "Class C identified by pointer!\n";
}

//randomly instanciates A, B or C and returns the instance as a Base pointer.
Base *generate(void) {
	int i = rand() % 3;
	switch (i) {
	case 0:
		std::cout << "Class A created\n";
		return (new A);
	case 1:
		std::cout << "Class B created\n";
		return (new B);
	case 2:
		std::cout << "Class C created\n";
		return (new C);
	default:
		std::cout << "Randomization error\n";
	}
	return nullptr;
}

int main() {
	srand(time(NULL));
	Base *randomChild;
	randomChild = generate();
	identify_from_pointer(randomChild);
	identify_from_reference(*randomChild);

	delete randomChild;
	return 0;
}