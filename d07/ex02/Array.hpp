#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<class T>
class Array {
private:
	int			_length;
	T			*_arr;

public:
	Array() : _length(0), _arr(nullptr) {}
	Array(unsigned int n) : _length(n), _arr(new T[n]()) {}
	Array(const Array &src) : Array() { *this = src; }
	virtual ~Array() { delete[] _arr; }

	Array &operator=(const Array &rhs) {
		if (_arr)
			delete[] _arr;
		_arr = new T[rhs._length]();
		_length = rhs._length;
		for (int i = 0; i < _length; i++) {
			_arr[i] = rhs._arr[i];
		}
		return *this;
	}

	T	&operator[](int idx) {
		if (idx < 0 || idx >= _length) {
			throw std::out_of_range("Bad index access");
		}
		return _arr[idx];
	}
	int size() const { return _length; }
};

#endif
