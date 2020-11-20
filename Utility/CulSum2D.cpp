#pragma once
#include <vector>
#include <algorithm>
using namespace std;

template <class T> class CulSum2D {
public:
	using value_type = T;
	using data_type = vector<vector<value_type>>;

private:
	size_t h, w;
	vector<vector<T>> s;

public:
	CulSum2D(const data_type& a)
	    : h(a.size()), w(a.front().size()), s(h + 1, vector<value_type>(w + 1)) {
		for (size_t i = 0; i < h; ++i) {
			for (size_t j = 0; j < w; ++j) {
				s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];
			}
		}
	}
	template <class F>
	CulSum2D(size_t _h, size_t _w, F f)
	    : h(_h), w(_w), s(h + 1, vector<value_type>(w + 1)) {
		for (size_t i = 0; i < h; ++i) {
			for (size_t j = 0; j < w; ++j) {
				s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + f(i, j);
			}
		}
	}
	template <class U, class F>
	CulSum2D(const U& a, F f)
	    : CulSum2D(a.size(), a.front().size(),
	               [a, f](size_t i, size_t j) -> value_type { return f(a[i][j]); }) {}
	// [y1, y2) * [x1, x2)
	value_type operator()(size_t y1, size_t y2, size_t x1, size_t x2) const {
		y1 = min(y1, h);
		y2 = min(y2, h);
		x1 = min(x1, w);
		x2 = min(x2, w);
		return (x1 > x2 || y1 > y2) ? 0 : s[y2][x2] - s[y1][x2] - s[y2][x1] + s[y1][x1];
	}
	// [0, y) * [0, x)
	value_type operator()(size_t y, size_t x) const {
		y = min(y, h);
		x = min(x, w);
		return s[y][x];
	}
	const data_type& get_data() const {
		return s;
	}
};
