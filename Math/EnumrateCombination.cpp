#pragma once
#include <vector>
using namespace std;

template <class T> vector<vector<T>> EnumrateCombination(size_t n) {
	vector<vector<T>> result(n + 1, vector<T>(n + 1));
	for (size_t i = 0; i <= n; ++i) result[i][0] = result[i][i] = 1;
	for (size_t i = 1; i <= n; ++i) {
		for (size_t j = 1; j < i; ++j) {
			result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
	}
	return result;
}
