// description : s-t 間のパスを求める
vector<int> BuildPathTree(const Graph &g, int s, int t) {
	int n = g.size();
	vector<int> par(n);
	function<void(int, int)> dfs = [&](int v, int p) {
		for (const auto &u : g[v])
			if (u.to != p) {
				par[u.to] = v;
				dfs(u.to, v);
			}
	};
	dfs(s, -1);
	vector<int> path{t};
	while (path.back() != s) {
		path.push_back(par[path.back()]);
	}
	reverse(path.begin(), path.end());
	return path;
}