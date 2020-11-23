#pragma once
#include <vector>
using namespace std;

template <class value_type = long long> vector<value_type> FibonacciTable(int n) {
	vector<value_type> result(n + 1);
	for (int i = 0; i <= n; ++i) {
		if (i < 2) {
			result[i] = i;
		} else {
			result[i] = result[i - 1] + result[i - 2];
		}
	}
	return result;
}
