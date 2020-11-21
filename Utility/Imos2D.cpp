#pragma once
#include <vector>
#include <utility>
#include <cassert>
using namespace std;

template <class T> class Imos2D {
public:
	using value_type = T;
	using data_type = vector<vector<value_type>>;

private:
	size_t h, w;
	data_type table;
	bool builded = false;

public:
	Imos2D(size_t _h, size_t _w) : h(_h), w(_w), table(_h + 1, vector<T>(_w + 1)) {}
	size_t height() const {
		return h;
	}
	size_t weight() const {
		return w;
	}
	// [x1, x2) * [y1, y2)
	void add(size_t y1, size_t y2, size_t x1, size_t x2, const T& value = 1) {
		assert(0 <= x1 && x1 < x2 && x2 <= w);
		assert(0 <= y1 && y1 < y2 && y2 <= h);
		assert(!builded);
		table[y1][x1] += value;
		table[y1][x2] -= value;
		table[y2][x1] -= value;
		table[y2][x2] += value;
	}
	void add(const pair<size_t, size_t>& y, const pair<size_t, size_t>& x,
	         const T& value = 1) {
		assert(!builded);
		add(y.first, y.second, x.first, x.second, value);
	}
	void build() {
		builded = true;
		for (size_t y = 0; y <= h; ++y) {
			for (size_t x = 1; x <= w; ++x) {
				table[y][x] += table[y][x - 1];
			}
		}
		for (size_t y = 1; y <= h; ++y) {
			for (size_t x = 0; x <= w; ++x) {
				table[y][x] += table[y - 1][x];
			}
		}
	}
	const value_type& operator()(size_t y, size_t x) const {
		assert(builded);
		return table[y][x];
	}
	const data_type& operator*() const {
		assert(builded);
		return table;
	}
};
