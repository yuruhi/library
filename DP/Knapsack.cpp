// description : 01ナップザック問題
template <class T> vector<T> Knapsack(int N, T W, const vector<T>& v, const vector<T>& w) {
	vector<T> dp(W + 1, 0);
	for (int i = 0; i < N; ++i) {
		for (int j = W; j >= 0; --j) {
			if (j - w[i] >= 0) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	return dp;
}