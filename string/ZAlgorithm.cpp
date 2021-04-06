#pragma once
#include <vector>

template <class T> std::vector<int> ZAlgorithm(const T& s) {
	if (s.size() == 0) {
		return {};
	}
	int n = s.size(), i = 1, j = 0;
	std::vector<int> result(n);
	result[0] = n;
	while (i < n) {
		while (i + j < n && s[j] == s[i + j]) j++;
		result[i] = j;
		if (j == 0) {
			i++;
			continue;
		}
		int k = 1;
		while (i + k < n && k + result[k] < j) {
			result[i + k] = result[k];
			k++;
		}
		i += k;
		j -= k;
	}
	return result;
}
