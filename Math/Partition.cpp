// shortcut : Partition
// description : 分割数 dp[i][j] := j の i 分割の総数
template <class T> vector<vector<T>> Partition(int n, int m) {
	vector<vector<T>> dp(m + 1, vector<T>(n + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j - i >= 0) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - i];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp;
}