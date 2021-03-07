#pragma once
#include <tuple>

template <class T> T extGcd(T a, T b, T& x, T& y) {
	T d = a;
	if (b != 0) {
		d = extGcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1;
		y = 0;
	}
	return d;
}

template <class T> std::tuple<T, T, T> extGcd(T a, T b) {
	T x, y;
	T gcd = extGcd(a, b, x, y);
	return {gcd, x, y};
}
