#pragma once
#include <vector>

template <class T> std::vector<std::vector<T>> Partition(int num, int sum) {
	std::vector dp(num + 1, std::vector<T>(sum + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= num; ++i) {
		for (int j = 0; j <= sum; ++j) {
			if (j - i >= 0) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - i];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp;
}
