// shortcut : Imos2D
// description : いもす法2次元
template <class T> class Imos2D {
	vector<vector<T>> table;
	bool flag = false;

public:
	const int H, W;
	Imos2D(int _h, int _w) : H(_h), W(_w), table(_h + 1, vector<T>(_w + 1)) {}
	// [x1, x2) * [y1, y2)
	void add(int y1, int y2, int x1, int x2, const T &v = 1) {
		assert(0 <= x1 && x1 < x2 && x2 <= W);
		assert(0 <= y1 && y1 < y2 && y2 <= H);
		assert(!flag);
		table[y1][x1] += v;
		table[y1][x2] -= v;
		table[y2][x1] -= v;
		table[y2][x2] += v;
	}
	void add(const pair<int, int> &y, const pair<int, int> &x, const T &v = 1) {
		assert(!flag);
		add(y.first, y.second, x.first, x.second, v);
	}
	void build() {
		flag = true;
		for (int y = 0; y <= H; ++y)
			for (int x = 1; x <= W; ++x) table[y][x] += table[y][x - 1];
		for (int y = 1; y <= H; ++y)
			for (int x = 0; x <= W; ++x) table[y][x] += table[y - 1][x];
	}
	const T &operator()(int y, int x) const {
		assert(flag);
		return table[y][x];
	}
	const auto &operator*() const {
		assert(flag);
		return table;
	}
};