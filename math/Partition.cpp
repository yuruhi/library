#pragma once
#include <vector>
using namespace std;

template <class T> vector<vector<T>> Partition(int num, int sum) {
	vector<vector<T>> dp(num + 1, vector<T>(sum + 1));
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
