#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

template <class T>
vector<T> Knapsack(int n, int wight_limit, const vector<T>& value, const vector<int>& weight) {
	assert(n == static_cast<int>(value.size()));
	assert(n == static_cast<int>(weight.size()));
	vector<T> dp(wight_limit + 1, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= wight_limit - weight[i]; ++j) {
			dp[j + weight[i]] = max(dp[j + weight[i]], dp[j] + value[i]);
		}
	}
	return dp;
}