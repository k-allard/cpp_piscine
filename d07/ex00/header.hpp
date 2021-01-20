#include <iostream>

template <typename T1>
const T1& max(const T1& a, const T1& b) {
    return (b >= a) ? b : a;
}

template <typename T2>
const T2& min(const T2& a, const T2& b) {
    return (b <= a) ? b : a;
}

template <typename T3>
void swap(T3& a, T3& b) {
	T3 c = a;
	a = b;
	b = c;
}
