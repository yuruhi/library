#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int LCS(const string& s, const string& t) {
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i] == t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
		}
	}
	return dp[n][m];
}
