// shortcut : EulerTour
// description : [l[i], r[i]] : i の部分木
class EulerTour {
	vector<vector<int>> g;
	vector<int> ls, rs;
	int pos = 0;
	bool flag = false;
	void dfs(int v, int p = -1) {
		ls[v] = pos++;
		for (int u : g[v])
			if (u != p) {
				dfs(u, v);
			}
		rs[v] = pos++;
	}

public:
	EulerTour(int n) : g(n), ls(n), rs(n) {}
	EulerTour(const vector<vector<int>> &_g) : g(_g), ls(g.size()), rs(g.size()) {}
	void add_edge(int u, int v) {
		g[u].push_back(v);
		g[v].push_back(u);
	}
	void build(int root = 0) {
		flag = true;
		pos = 0;
		dfs(root);
	}
	int size() const {
		assert(flag);
		return pos;
	}
	int l(int i) const {
		assert(flag);
		return ls[i];
	}
	int r(int i) const {
		assert(flag);
		return rs[i];
	}
	pair<int, int> operator()(int i) {
		assert(flag);
		return make_pair(ls[i], rs[i]);
	}
	int operator[](int i) {
		assert(flag);
		return ls[i];
	}
	template <class T> auto call(int v, function<T(int, int)> &&f) {
		assert(flag);
		return f(ls[v], rs[v]);
	}
};