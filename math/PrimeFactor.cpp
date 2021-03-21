#pragma once
#include <map>
#include <vector>
#include <utility>
#include <cassert>

template <class T> std::vector<std::pair<T, int>> PrimeFactor(T n) {
	assert(1 <= n);
	if (n == 1) {
		return {};
	}
	std::vector<std::pair<T, int>> result;
	for (T i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			result.emplace_back(i, 0);
			while (n % i == 0) {
				result.back().second++;
				n /= i;
			}
		}
	}
	if (n != 1) {
		result.emplace_back(n, 1);
	}
	return result;
}
template <class T> std::map<T, int> PrimeFactor_map(T n) {
	assert(1 <= n);
	if (n == 1) {
		return {};
	}
	std::map<T, int> result;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			result[i]++;
			n /= i;
		}
	}
	if (n != 1) {
		result[n] = 1;
	}
	return result;
}
template <class T> std::vector<T> PrimeFactor_vector(T n) {
	assert(1 <= n);
	if (n == 1) {
		return {};
	}
	std::vector<T> result;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			result.push_back(i);
			n /= i;
		}
	}
	if (n != 1) {
		result.push_back(n);
	}
	return result;
}
