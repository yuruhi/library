#pragma once
#include <vector>
#include <utility>
#include <cassert>

template <class T> class Imos2D {
public:
	using value_type = T;
	using data_type = std::vector<std::vector<value_type>>;

private:
	std::size_t h, w;
	data_type table;
	bool builded = false;

public:
	Imos2D(std::size_t _h, std::size_t _w)
	    : h(_h), w(_w), table(_h + 1, std::vector<T>(_w + 1)) {}
	std::size_t height() const {
		return h;
	}
	std::size_t weight() const {
		return w;
	}
	// [x1, x2) * [y1, y2)
	void add(std::size_t y1, std::size_t y2, std::size_t x1, std::size_t x2,
	         const T& value = 1) {
		assert(0 <= x1 && x1 < x2 && x2 <= w);
		assert(0 <= y1 && y1 < y2 && y2 <= h);
		assert(!builded);
		table[y1][x1] += value;
		table[y1][x2] -= value;
		table[y2][x1] -= value;
		table[y2][x2] += value;
	}
	void add(const std::pair<std::size_t, std::size_t>& y,
	         const std::pair<std::size_t, std::size_t>& x, const T& value = 1) {
		assert(!builded);
		add(y.first, y.second, x.first, x.second, value);
	}
	void build() {
		builded = true;
		for (std::size_t y = 0; y <= h; ++y) {
			for (std::size_t x = 1; x <= w; ++x) {
				table[y][x] += table[y][x - 1];
			}
		}
		for (std::size_t y = 1; y <= h; ++y) {
			for (std::size_t x = 0; x <= w; ++x) {
				table[y][x] += table[y - 1][x];
			}
		}
	}
	const value_type& operator()(std::size_t y, std::size_t x) const {
		assert(builded);
		return table[y][x];
	}
	const data_type& operator*() const {
		assert(builded);
		return table;
	}
};
