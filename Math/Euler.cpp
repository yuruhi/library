#pragma once
#include "./PrimeFactor.cpp"

template <class T> T Euler(T x) {
	T res = x;
	for (auto [p, e] : PrimeFactor(x)) {
		res = res / p * (p - 1);
	}
	return res;
}