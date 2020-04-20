// shortcut : UnionFind
// description : UnionFind木
class UnionFind {
	vector<int> d;
public:
	UnionFind(int n = 0) {
		init(n);
	}
	void init(int n) {
		d.assign(n, -1);
	}
	int root(int x) {
		return d[x] < 0 ? x : d[x] = root(d[x]);
	}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (d[x] > d[y])swap(x, y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	int size(int x) {
		return -d[root(x)];
	}
};