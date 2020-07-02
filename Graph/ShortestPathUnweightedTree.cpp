// shortcut : ShortestPathUnWeightedTree
// description : 重さなし木の最短経路
vector<int> ShortestPathTree(const vector<vector<int>> &g, int s) {
	int V = g.size();
	vector<int> dist(V);
	function<void(int, int, int)> dfs = [&](int v, int p, int depth) {
		dist[v] = depth;
		for (int e : g[v])
			if (e != p) {
				dfs(e, v, depth + 1);
			}
	};
	dfs(s, -1, 0);
	return dist;
}