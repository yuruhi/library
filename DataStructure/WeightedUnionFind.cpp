// description : 重み付きUnionFind木
template <class T> class UnionFind {
	vector<int> par, rank;
	vector<T> weight_;

public:
	UnionFind(int n) : par(n), rank(n, 0), weight_(n, 0) {
		for (int i = 0; i < n; ++i)
			par[i] = i;
	}
	int root(int x) {
		if (par[x] == x) return x;
		int r = root(par[x]);
		weight_[x] += weight_[par[x]];
		return par[x] = r;
	}
	T weight(int x) {
		root(x);
		return weight_[x];
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool merge(int x, int y, T w) {
		w += weight(x);
		w -= weight(y);
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) {
			swap(x, y);
			w = -w;
		}
		if (rank[x] == rank[y]) rank[x]++;
		par[y] = x;
		weight_[y] = w;
		return true;
	}
	T diff(int x, int y) {
		return weight(y) - weight(x);
	}
};