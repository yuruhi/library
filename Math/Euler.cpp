#pragma once
#include "./PrimeFactor.cpp"
#include <numeric>

template <class T> T Euler(T x) {
	T result = x;
	for (auto [p, e] : PrimeFactor(x)) {
		result = result / p * (p - 1);
	}
	return result;
}

vector<int> EnumerateEuler(int x) {
	vector<int> result(x + 1);
	iota(result.begin(), result.end(), 0);
	for (int i = 2; i <= x; ++i) {
		if (result[i] == i) {
			for (int j = i; j <= x; j += i) {
				result[j] = result[j] / i * (i - 1);
			}
		}
	}
	return result;
}