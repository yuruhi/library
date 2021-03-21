#pragma once
#include "./PrimeFactor.cpp"
#include <vector>
#include <numeric>

template <class T> T Euler(T x) {
	T result = x;
	for (auto [p, e] : PrimeFactor(x)) {
		result = result / p * (p - 1);
	}
	return result;
}

std::vector<int> EnumerateEuler(int x) {
	std::vector<int> result(x + 1);
	std::iota(result.begin(), result.end(), 0);
	for (int i = 2; i <= x; ++i) {
		if (result[i] == i) {
			for (int j = i; j <= x; j += i) {
				result[j] = result[j] / i * (i - 1);
			}
		}
	}
	return result;
}
