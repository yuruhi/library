#pragma once
#include <vector>
#include <algorithm>
#include <type_traits>

template <class T> class CulSum2D {
public:
	using value_type = T;
	using data_type = std::vector<std::vector<value_type>>;
	using size_type = std::size_t;

private:
	size_type h, w;
	data_type data;

public:
	CulSum2D() = default;
	CulSum2D(const data_type& a)
	    : h(a.size()), w(a.front().size()), data(h + 1, std::vector<value_type>(w + 1)) {
		for (size_type i = 0; i < h; ++i) {
			for (size_type j = 0; j < w; ++j) {
				data[i + 1][j + 1] = data[i][j + 1] + data[i + 1][j] - data[i][j] + a[i][j];
			}
		}
	}
	template <class U, class F,
	          std::enable_if_t<std::is_integral_v<U>, std::nullptr_t> = nullptr>
	CulSum2D(const U& _h, const U& _w, F f)
	    : h(_h), w(_w), data(h + 1, std::vector<value_type>(w + 1)) {
		for (size_type i = 0; i < h; ++i) {
			for (size_type j = 0; j < w; ++j) {
				data[i + 1][j + 1] = data[i][j + 1] + data[i + 1][j] - data[i][j] + f(i, j);
			}
		}
	}
	template <class U, class F,
	          std::enable_if_t<!std::is_integral_v<U>, std::nullptr_t> = nullptr>
	CulSum2D(const U& a, F f)
	    : CulSum2D(a.size(), a.front().size(),
	               [a, f](size_type i, size_type j) -> value_type { return f(a[i][j]); }) {}
	// [y1, y2) * [x1, x2)
	value_type operator()(size_type y1, size_type y2, size_type x1, size_type x2) const {
		y1 = std::min(y1, h);
		y2 = std::min(y2, h);
		x1 = std::min(x1, w);
		x2 = std::min(x2, w);
		return (x1 > x2 || y1 > y2)
		    ? 0
		    : data[y2][x2] - data[y1][x2] - data[y2][x1] + data[y1][x1];
	}
	// [0, y) * [0, x)
	value_type operator()(size_type y, size_type x) const {
		y = std::min(y, h);
		x = std::min(x, w);
		return data[y][x];
	}
	const data_type& get_data() const {
		return data;
	}
};
