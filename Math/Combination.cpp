// description : v[n][k] := nCk O(N^2)
template <class T> vector<vector<T>> Combi(int n, T _Mod = 1000000007) {
	vector<vector<T>> v(n, vector<T>(n));
	for (int i = 0; i < n; ++i) v[i][0] = v[i][i] = 1;
	for (int k = 1; k < n; ++k)
		for (int j = 1; j < k; ++j) v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]) % _Mod;
	return v;
}