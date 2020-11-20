#pragma once
#include <vector>
#include <algorithm>
using namespace std;

template <class T> class CulSum2D {
public:
	using value_type = T;
	using data_type = vector<vector<value_type>>;

private:
	int h, w;
	vector<vector<T>> s;

public:
	CulSum2D(const data_type& a)
	    : h(a.size()), w(a.front().size()), s(h + 1, vector<value_type>(w + 1)) {
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];
			}
		}
	}
	template <class F>
	CulSum2D(int _h, int _w, F f) : h(_h), w(_w), s(h + 1, vector<value_type>(w + 1)) {
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + f(i, j);
			}
		}
	}
	template <class U, class F>
	CulSum2D(const U& a, F f)
	    : CulSum2D(a.size(), a.front().size(),
	               [a, f](int i, int j) -> value_type { return f(a[i][j]); }) {}
	// [y1, y2) * [x1, x2)
	value_type operator()(int y1, int y2, int x1, int x2) const {
		y1 = min(max(y1, 0), h);
		y2 = min(max(y2, 0), h);
		x1 = min(max(x1, 0), w);
		x2 = min(max(x2, 0), w);
		return (x1 > x2 || y1 > y2) ? 0 : s[y2][x2] - s[y1][x2] - s[y2][x1] + s[y1][x1];
	}
	// [0, y) * [0, x)
	value_type operator()(int y, int x) const {
		y = min(max(y, 0), h);
		x = min(max(x, 0), w);
		return s[y][x];
	}
	const data_type& get_s() const {
		return s;
	}
};
