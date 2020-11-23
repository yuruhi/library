#pragma once
#include "./PrimeFactor.cpp"

template <class T> T Euler(T x) {
	T result = x;
	for (auto [p, e] : PrimeFactor(x)) {
		result = result / p * (p - 1);
	}
	return result;
}
