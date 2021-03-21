#pragma once
#include "./Eratosthenes.cpp"
#include <vector>

std::vector<int> EnumeratePrimes(std::size_t n) {
	std::vector<int> result;
	auto p = Eratosthenes(n);
	for (std::size_t i = 2; i <= n; ++i) {
		if (p[i]) result.push_back(i);
	}
	return result;
}
