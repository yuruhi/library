#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

template <class T>
vector<T> Knapsack01(int n, int weight_limit, const vector<T>& value, const vector<int>& weight) {
	assert(n == static_cast<int>(value.size()));
	assert(n == static_cast<int>(weight.size()));
	vector<T> dp(weight_limit + 1, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = weight_limit; j >= 0; --j) {
			if (j - weight[i] >= 0) dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	return dp;
}
