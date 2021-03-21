#pragma once
#include <vector>
#include <string>
#include <algorithm>

int LCS(const std::string& s, const std::string& t) {
	int n = s.size(), m = t.size();
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i] == t[j]) dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] + 1);
			dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i + 1][j]);
			dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j + 1]);
		}
	}
	return dp[n][m];
}
