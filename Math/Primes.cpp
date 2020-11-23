#pragma once
#include "./Eratosthenes.cpp"
#include <vector>
using namespace std;

vector<int> Primes(int n) {
	vector<int> result;
	auto p = Eratosthenes(n);
	for (int i = 0; i <= n; ++i) {
		if (p[i]) result.push_back(i);
	}
	return result;
}
