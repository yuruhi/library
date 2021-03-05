#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>

template <class T> class Imos {
public:
	using value_type = T;

private:
	int n;
	std::vector<value_type> table;
	bool builded = false;

public:
	Imos() = default;
	Imos(int _n) : n(_n), table(_n + 1) {}
	void add(int l, int r, value_type v = 1) {
		assert(!builded);
		l = std::clamp(l, 0, n);
		r = std::clamp(r, 0, n);
		if (l < r) {
			table[l] += v;
			table[r] -= v;
		}
	}
	void add(const std::pair<int, int>& section, value_type v = 1) {
		add(section.first, section.second, v);
	}
	void add_closed(int l, int r, value_type v = 1) {
		add(l, r + 1, v);
	}
	void add_closed(const std::pair<int, int>& section, value_type v = 1) {
		add_closed(section.first, section.second, v);
	}
	void build() {
		builded = true;
		for (int i = 1; i < n; ++i) {
			table[i] += table[i - 1];
		}
	}
	value_type operator[](int i) const {
		assert(builded);
		return table[i];
	}
	const std::vector<value_type>& operator*() const {
		assert(builded);
		return table;
	}
	std::vector<value_type> to_a() const {
		return std::vector(table.begin(), table.begin() + n);
	}
};
