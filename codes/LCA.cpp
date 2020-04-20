// shortcut : LCA
// description : 最小共通祖先（ダブリング）
struct LCA {
	const int V, LOG;
	vector<int> dist;
	vector<vector<int>> table;

	LCA(const Graph& g, const int root)
		: V(g.size()), LOG(log2(V) + 1)
		, dist(V), table(LOG, vector<int>(V)) {
		dfs(g, root, -1, 0);
		for (int k = 0; k + 1 < LOG; ++k) {
			for (int v = 0; v < V; ++v) {
				if (table[k][v] < 0) {
					table[k + 1][v] = -1;
				} else {
					table[k + 1][v] = table[k][table[k][v]];
				}
			}
		}
	}
	void dfs(const Graph& g, int v, int p, int d) {
		table[0][v] = p;
		dist[v] = d;
		for (auto e : g[v])if (e.to != p) {
			dfs(g, e.to, v, d + 1);
		}
	}
	int operator()(int u, int v) {
		if (dist[u] > dist[v])swap(u, v);
		for (int k = 0; k < LOG; ++k) {
			if ((dist[v] - dist[u]) >> k & 1) {
				v = table[k][v];
			}
		}
		if (u == v)return u;
		for (int k = LOG - 1; k >= 0; --k) {
			if (table[k][u] != table[k][v]) {
				u = table[k][u];
				v = table[k][v];
			}
		}
		return table[0][u];
	}
};