#pragma once
#include <vector>
using namespace std;

vector<long long> Fibonacci(int n) {
	vector<long long> res(n + 1);
	for (int i = 0; i <= n; ++i) {
		if (i < 2) {
			res[i] = i;
		} else {
			res[i] = res[i - 1] + res[i - 2];
		}
	}
	return res;
}
