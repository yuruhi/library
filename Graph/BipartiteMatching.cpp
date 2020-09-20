// description : N -> M の辺しか張らない O(VE)
class BipartiteMatching {
	int N, M;
	vector<vector<int>> G;
	vector<bool> used;
	vector<int> p, q;
	bool dfs(int v) {
		if (used[v]) return false;
		used[v] = true;
		for (auto u : G[v]) {
			if (q[u] == -1 || dfs(q[u])) {
				q[u] = v;
				p[v] = u;
				return true;
			}
		}
		return false;
	}

public:
	BipartiteMatching(int n, int m, const vector<vector<int>>& g) : N(n), M(m), G(g), used(N), p(N, -1), q(M, -1) {}
	BipartiteMatching(int n, int m) : N(n), M(m), G(n), used(N), p(N, -1), q(M, -1) {}
	void add_edge(int s, int t) {
		G[s].push_back(t);
	}
	int operator()() {
		int res = 0;
		bool flag = true;
		fill(p.begin(), p.end(), -1);
		fill(q.begin(), q.end(), -1);
		fill(used.begin(), used.end(), false);
		while (flag) {
			flag = false;
			for (int i = 0; i < N; ++i) {
				if (p[i] == -1 && dfs(i)) {
					flag = true;
					++res;
				}
			}
			if (flag) {
				fill(used.begin(), used.end(), false);
			}
		}
		return res;
	}
};