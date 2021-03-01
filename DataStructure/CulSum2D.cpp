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
	vector<vector<T>> data;

public:
	CulSum2D() = default;
	CulSum2D(const data_type& a)
	    : h(a.size()), w(a.front().size()), data(h + 1, vector<value_type>(w + 1)) {
		for (size_t i = 0; i < h; ++i) {
			for (size_t j = 0; j < w; ++j) {
				data[i + 1][j + 1] = data[i][j + 1] + data[i + 1][j] - data[i][j] + a[i][j];
			}
		}
	}
	template <class U, class F, enable_if_t<is_integral_v<U>, nullptr_t> = nullptr>
	CulSum2D(const U& _h, const U& _w, F f)
	    : h(_h), w(_w), data(h + 1, vector<value_type>(w + 1)) {
		for (size_t i = 0; i < h; ++i) {
			for (size_t j = 0; j < w; ++j) {
				data[i + 1][j + 1] = data[i][j + 1] + data[i + 1][j] - data[i][j] + f(i, j);
			}
		}
	}
	template <class U, class F, enable_if_t<!is_integral_v<U>, nullptr_t> = nullptr>
	CulSum2D(const U& a, F f)
	    : CulSum2D(a.size(), a.front().size(),
	               [a, f](size_t i, size_t j) -> value_type { return f(a[i][j]); }) {}
	// [y1, y2) * [x1, x2)
	value_type operator()(size_t y1, size_t y2, size_t x1, size_t x2) const {
		y1 = min(y1, h);
		y2 = min(y2, h);
		x1 = min(x1, w);
		x2 = min(x2, w);
		return (x1 > x2 || y1 > y2)
		    ? 0
		    : data[y2][x2] - data[y1][x2] - data[y2][x1] + data[y1][x1];
	}
	// [0, y) * [0, x)
	value_type operator()(size_t y, size_t x) const {
		y = min(y, h);
		x = min(x, w);
		return data[y][x];
	}
	const data_type& get_data() const {
		return data;
	}
};
