// shortcut : FordFulkerson
// description : Ford-Fulkerson法 O(EF)
class FordFulkerson {
	int V;
	GraphF G;
	vector<bool> used;
	FLOW dfs(int v, int t, FLOW f) {
		if (v == t)return f;
		used[v] = true;
		for (auto& e : G[v]) {
			if (!used[e.to] && e.cap > 0) {
				FLOW d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

public:
	FordFulkerson(int v) :V(v), G(v), used(v) {}
	const GraphF& get_G() { return G; }
	void add(int from, int to, FLOW cap) {
		G[from].emplace_back(to, G[to].size(), cap);
		G[to].emplace_back(from, G[from].size() - 1, 0);
	}
	FLOW operator()(int s, int t) {
		FLOW res = 0;
		while (true) {
			fill(used.begin(), used.end(), false);
			FLOW f = dfs(s, t, INF_FLOW);
			if (!f)return res;
			res += f;
		}
	}
};