// description : return : { cnt, edges }
class BipartiteMatching {
	int V, L;
	vector<vector<int>> G;
	vector<int> match;
	vector<int> used;
	int used_i = 0;
	bool dfs(int v) {
		used[v] = used_i;
		for (auto u : G[v]) {
			int w = match[u];
			if (w == -1 || used[w] != used_i && dfs(w)) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}

public:
	BipartiteMatching(int l, int r) : V(l + r), L(l), G(V), match(V), used(V) {}
	void add_edge(int u, int v) {
		G[u].push_back(L + v);
		G[L + v].push_back(u);
	}
	pair<int, vector<pair<int, int>>> operator()() {
		int res = 0;
		fill(match.begin(), match.end(), -1);
		for (int i = 0; i < V; ++i) {
			if (match[i] == -1) {
				used_i++;
				res += dfs(i);
			}
		}

		vector<pair<int, int>> res2;
		for (int i = 0; i < L; ++i) {
			if (match[i] != -1) {
				res2.emplace_back(i, match[i] - L);
			}
		}
		return make_pair(res, res2);
	}
};