#pragma once
#include <vector>
using namespace std;

template <class value_type = long long> vector<value_type> FibonacciTable(int n) {
	vector<value_type> res(n + 1);
	for (int i = 0; i <= n; ++i) {
		if (i < 2) {
			res[i] = i;
		} else {
			res[i] = res[i - 1] + res[i - 2];
		}
	}
	return res;
}
