// shortcut : ConnectedComponet
// description : 連結成分 return : { 連結成分数, {番号} }
pair<int, vector<int>> ConnectedComponet(const UnWeightedGraph& g) {
	int V = g.size(), N = 0;
	VI id(V, -1);
	function<void(int, int)> dfs = [&](int ID, int v) {
		id[v] = ID;
		for (auto e : g[v])
			if (id[e] == -1)dfs(ID, e);
	};
	for (int i = 0; i < V; ++i)
		if (id[i] == -1)dfs(N++, i);
	return make_pair(N, id);
}