#pragma once
#include "./PrimeFactor.cpp"
#include <map>

template <class T> std::map<T, int> Moebius(T n) {
	std::map<T, int> result;
	auto primes = PrimeFactor(n);
	int m = primes.size();
	for (int bit = 0; bit < (1 << m); ++bit) {
		int mul = 1, d = 1;
		for (int i = 0; i < m; ++i) {
			if (bit & (1 << i)) {
				mul *= -1;
				d *= primes[i].first;
			}
		}
		result[d] = mul;
	}
	return result;
}