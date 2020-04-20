// shortcut : ShortestPathTree
// description : 木の最短経路
vector<Weight> ShortestPathTree(const Graph& g, int s) {
	int V = g.size();
	vector<Weight> dist(V);
	function<void(int, int, Weight)> dfs = [&](int v, int p, Weight depth) {
		dist[v] = depth;
		for (auto e : g[v])if (e.to != p) {
			dfs(e.to, v, depth + e.cost);
		}
	};
	dfs(s, -1, 0);
	return dist;
}