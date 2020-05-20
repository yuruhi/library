// shortcut : DiameterPath
// description : 木の直径とそのパスを求める
tuple<Weight, vector<int>> DiameterPath(const Graph& g) {
	int n = g.size();
	vector<Weight> dist0(n);
	function<void(int, int, Weight)> dfs = [&](int v, int p, Weight d) {
		dist0[v] = d;
		for (const auto& u : g[v])if (u.to != p) {
			dfs(u.to, v, d + u.cost);
		}
	};
	dfs(0, -1, 0);

	int s = max_element(dist0.begin(), dist0.end()) - dist0.begin();
	vector<Weight> dist(n); vector<int> par(n);
	function<void(int, int, Weight)> dfs2 = [&](int v, int p, Weight d) {
		dist[v] = d;
		par[v] = p;
		for (const auto& u : g[v])if (u.to != p) {
			dfs2(u.to, v, d + u.cost);
		}
	};
	dfs2(s, -1, 0);
	auto t = max_element(dist.begin(), dist.end());
	vector<int> path{ t - dist.begin() };
	for (int p = 0; (p = par[path.back()]) != -1;) {
		path.push_back(p);
	}
	reverse(path.begin(), path.end());
	return { *t,path };
}