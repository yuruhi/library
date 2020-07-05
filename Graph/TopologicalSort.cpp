// description : トポロジカルソート O(V + E)
vector<int> TopologicalSort(const vector<vector<int>> &graph) {
	int V = graph.size();
	vector<bool> visited(V);
	vector<int> ret;
	function<void(int)> dfs = [&](int u) {
		if (visited[u]) return;
		visited[u] = true;
		for (auto &i : graph[u]) dfs(i);
		ret.push_back(u);
	};
	for (int i = 0; i < V; i++) dfs(i);
	reverse(ret.begin(), ret.end());
	return ret;
}