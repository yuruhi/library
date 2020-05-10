// shortcut : Imos2D
// description : いもす法2次元
template<class T>class Imos2D {
	vector<vector<T>> table;
	bool flag = false;
public:
	const int H, W;
	Imos2D(int _h, int _w) :H(_h), W(_w), table(_h + 1, vector<T>(_w + 1)) {}
	// [x1, x2) * [y1, y2)
	void add(int x1, int x2, int y1, int y2, T v = 1) {
		assert(x1 < x2);
		assert(y1 < y2);
		assert(!flag);
		table[y1][x1] += v;
		table[y1][x2] -= v;
		table[y2][x1] -= v;
		table[y2][x2] += v;
	}
	void build() {
		flag = true;
		for (int y = 0; y < H; ++y)
			for (int x = 1; x < W; ++x)
				table[y][x] += table[y][x - 1];
		for (int y = 1; y < H; ++y)
			for (int x = 0; x < W; ++x)
				table[y][x] += table[y - 1][x];
	}
	const T& operator()(int y, int x)const {
		assert(flag);
		return table[y][x];
	}
	const auto& operator*()const {
		assert(flag);
		return table;
	}
};