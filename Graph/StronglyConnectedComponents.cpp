// description : 強連結成分分解
class StronglyConnectedComponents {
	int V, k = 0;
	vector<vector<int>> G, rG;
	vector<int> vs, cmp;
	vector<bool> used;
	void dfs(int v) {
		used[v] = true;
		for (auto e : G[v]) {
			if (!used[e]) dfs(e);
		}
		vs.push_back(v);
	}
	void rdfs(int v, int k) {
		used[v] = true;
		cmp[v] = k;
		for (auto e : rG[v]) {
			if (!used[e]) rdfs(e, k);
		}
	}

public:
	StronglyConnectedComponents(int v) : V(v), G(V), rG(V), used(V), cmp(V) {}
	void add_edge(int s, int t) {
		G[s].push_back(t);
		rG[t].push_back(s);
	}
	int operator[](int i) const {
		return cmp[i];
	}
	void build() {
		vs.clear();
		fill(used.begin(), used.end(), false);
		for (int i = 0; i < V; ++i) {
			if (!used[i]) dfs(i);
		}
		k = 0;
		fill(used.begin(), used.end(), false);
		for (int i = vs.size() - 1; i >= 0; --i) {
			if (!used[vs[i]]) rdfs(vs[i], k++);
		}
	}
	vector<vector<int>> make_DAG() {
		vector<vector<int>> res(k);
		for (int i = 0; i < V; ++i)
			for (auto e : G[i]) {
				if (cmp[i] != cmp[e]) res[cmp[i]].push_back(cmp[e]);
			}
		for (auto &v : res) {
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
		}
		return res;
	}
};