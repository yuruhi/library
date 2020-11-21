#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>
using namespace std;

template <class T> class Imos {
public:
	using value_type = T;

private:
	const int N;
	vector<value_type> table;
	bool builded = false;

public:
	Imos(int _n) : N(_n), table(_n + 1) {}
	void add(int l, int r, value_type v = 1) {
		assert(!builded);
		l = clamp(l, 0, N);
		r = clamp(r, 0, N);
		if (l < r) {
			table[l] += v;
			table[r] -= v;
		}
	}
	void add(const pair<int, int>& section, value_type v = 1) {
		add(section.first, section.second, v);
	}
	void add_closed(int l, int r, value_type v = 1) {
		add(l, r + 1, v);
	}
	void add_closed(const pair<int, int>& section, value_type v = 1) {
		add_closed(section.first, section.second, v);
	}
	void build() {
		builded = true;
		for (int i = 1; i < N; ++i) {
			table[i] += table[i - 1];
		}
	}
	value_type operator[](int i) const {
		assert(builded);
		return table[i];
	}
	const vector<value_type>& operator*() const {
		assert(builded);
		return table;
	}
	vector<value_type> to_a() const {
		return vector(table.begin(), table.begin() + N);
	}
};
