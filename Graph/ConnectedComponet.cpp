// shortcut : ConnectedComponet
// description : 連結成分 return : { 連結成分数, {番号} }
tuple<int, vector<int>, vector<vector<int>>> ConnectedComponet(const vector<vector<int>> &g) {
	int V = g.size(), N = 0;
	vector<int> id(V, -1);
	vector<vector<int>> ind(V);
	function<void(int, int)> dfs = [&](int ID, int v) {
		id[v] = ID;
		ind[ID].push_back(v);
		for (auto e : g[v])
			if (id[e] == -1) dfs(ID, e);
	};
	for (int i = 0; i < V; ++i)
		if (id[i] == -1) dfs(N++, i);
	ind.resize(N);
	return make_tuple(N, id, ind);
}