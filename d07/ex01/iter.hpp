#include <iostream>

template <typename T1>
void iter(T1 *array, size_t size, void (*f)(const T1 &p)) {
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}
