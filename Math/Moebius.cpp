#pragma once
#include "./PrimeFactor.cpp"
#include <map>
using namespace std;

template <class T> map<T, int> Moebius(T n) {
	map<T, int> res;
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
		res[d] = mul;
	}
	return res;
}