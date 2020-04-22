// shortcut : SpanningTree
// description : 全域木構築 有向木を返す
Graph SpanningTree(const Graph& g, int root) {
	int n = g.size();
	Graph res(n);
	queue<int> q; q.push(root);
	vector<bool> flag(n); flag[root] = true;
	while (!q.empty()) {
		int f = q.front(); q.pop();
		for (const Edge& e : g[f]) {
			if (!flag[e.to]) {
				res[f].push_back(e);
				flag[e.to] = true;
				q.push(e.to);
			}
		}
	}
	return res;
}