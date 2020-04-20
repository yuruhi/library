// shortcut : BipartiteGraph
// description : 二部グラフ判定 O(V + E)
int BipartiteGraph(const Graph& graph) {
	int V = graph.size(), White = 0;
	vector<int> Cr(V);
	function<bool(int, int)> dfs = [&](int v, int c) {
		Cr[v] = c;
		White += c == 1;
		for (auto e : graph[v]) {
			if (Cr[e.to] == c)return false;
			if (Cr[e.to] == 0 && !dfs(e.to, -c))return false;
		}
		return true;
	};
	for (int i = 0; i < V; i++) {
		if (Cr[i] == 0)
			if (!dfs(i, 1))return -1;
	}
	return White;
}