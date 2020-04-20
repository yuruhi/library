// shortcut : SpanningTree
// description : 全域木構築 return : { {parent}, {depth, index} }
tuple<vector<int>, vector<pair<int, int>>> SpanningTree(const vector<vector<int>>& g, int root) {
	const int V = g.size(), nil = -2;
	vector<int> parent(V, nil);
	parent[root] = -1;
	vector<pair<int, int>> depth(V); // (depth, index)
	for (int i = 0; i < V; ++i)
		depth[i].second = i;

	queue<int> q; q.push(root);
	while (!q.empty()) {
		int f = q.front(); q.pop();
		for (auto e : g[f]) {
			if (parent[e] == nil) {
				parent[e] = f;
				depth[e].first = depth[f].first + 1;
				q.push(e);
			}
		}
	}
	return make_tuple(parent, depth);
}