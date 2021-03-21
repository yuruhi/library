#pragma once
#include <vector>
#include <string>
#include <algorithm>

int Levenshtein(const std::string& s, const std::string& t) {
	int S = s.size(), T = t.size();
	std::vector dp(S + 1, std::vector<int>(T + 1));
	for (int i = 0; i <= S; i++) dp[i][0] = i;
	for (int i = 0; i <= T; i++) dp[0][i] = i;
	for (int i = 1; i <= S; i++)
		for (int j = 1; j <= T; j++)
			dp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1,
			                dp[i - 1][j - 1] + (s[i - 1] != t[j - 1])});
	return dp[S][T];
}
