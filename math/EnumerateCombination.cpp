#pragma once
#include <vector>

template <class T> std::vector<std::vector<T>> EnumerateCombination(std::size_t n) {
	std::vector result(n + 1, std::vector<T>(n + 1));
	for (std::size_t i = 0; i <= n; ++i) result[i][0] = result[i][i] = 1;
	for (std::size_t i = 1; i <= n; ++i) {
		for (std::size_t j = 1; j < i; ++j) {
			result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
	}
	return result;
}
