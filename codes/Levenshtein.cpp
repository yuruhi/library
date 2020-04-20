// shortcut : Levenshtein
// description : 編集距離
int Levenshtein(const string& s, const string& t) {
	int S = s.size(), T = t.size();
	vector<vector<int>> dp(S + 1, vector<int>(T + 1));
	for (int i = 0; i <= S; i++)dp[i][0] = i;
	for (int i = 0; i <= T; i++)dp[0][i] = i;
	for (int i = 1; i <= S; i++)for (int j = 1; j <= T; j++)
		dp[i][j] = min({ dp[i - 1][j] + 1,dp[i][j - 1] + 1,dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]) });
	return dp[S][T];
}