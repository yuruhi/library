// description : 累積和2次元
template <class T> class CulSum2D {
	int h, w;
	vector<vector<T>> s;

public:
	CulSum2D(const vector<vector<T>>& a) : h(a.size()), w(a.front().size()), s(h + 1, vector<T>(w + 1)) {
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];
	}
	template <class U, class F>
	CulSum2D(const U& a, F f) : h(a.size()), w(a.front().size()), s(h + 1, vector<T>(w + 1)) {
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + static_cast<T>(f(a[i][j]));
	}
	// [y1, y2) * [x1, x2)
	T operator()(int y1, int y2, int x1, int x2) const {
		x1 = min(max(x1, 0), w);
		x2 = min(max(x2, 0), w);
		y1 = min(max(y1, 0), h);
		y2 = min(max(y2, 0), h);
		return (x1 > x2 || y1 > y2) ? 0 : s[y2][x2] - s[y1][x2] - s[y2][x1] + s[y1][x1];
	}
	// [0, y) * [0, x)
	T operator()(int y, int x) const {
		x = min(max(x, 0), w);
		y = min(max(y, 0), h);
		return s[y][x];
	}
	const vector<vector<T>>& get_s() {
		return s;
	}
};