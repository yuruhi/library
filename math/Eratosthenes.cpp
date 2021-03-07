#pragma once
#include <vector>
using namespace std;

vector<bool> Eratosthenes(size_t n) {
	vector<bool> result(n + 1, true);
	result[0] = result[1] = false;
	for (size_t i = 2; i * i <= n; ++i) {
		if (result[i]) {
			for (size_t j = i * i; j <= n; j += i) result[j] = false;
		}
	}
	return result;
}
