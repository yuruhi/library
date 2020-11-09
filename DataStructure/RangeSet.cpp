#pragma once
#include <set>
#include <utility>
#include <iostream>
using namespace std;

template <class T> class RangeSet {
	constexpr static T MIN = numeric_limits<T>::min();
	constexpr static T MAX = numeric_limits<T>::max();
	set<pair<T, T>> ranges;

	auto next_range_iterator(T x) const {
		return prev(ranges.lower_bound({x + 1, x + 1}));
	}
	pair<T, T> next_range(T x) const {
		return *next_range_iterator(x);
	}

public:
	RangeSet() {
		ranges.emplace(MIN, MIN);
		ranges.emplace(MAX, MAX);
	};
	size_t size() const {
		return ranges.size() - 2;
	}
	void clear() {
		ranges.clear();
		ranges.emplace(MIN, MIN);
		ranges.smplace(MAX, MAX);
	}
	bool empty() const {
		return size() == 0;
	}
	bool covered(T l, T r) const {
		assert(l <= r);
		auto [L, R] = next_range(l);
		return L <= l && r <= R;
	}
	bool coverd(T x) const {
		return covered(x, x);
	}
	T insert(T l, T r) {
		assert(l <= r);
		auto it = next_range_iterator(l);
		if (it->first <= l && r <= it->second) {
			return 0;
		}

		T erased_count = 0;
		if (it->first <= l && l <= it->second + 1) {
			l = it->first;
			erased_count += it->second - it->first + 1;
			it = ranges.erase(it);
		} else {
			it = next(it);
		}
		while (r > it->second) {
			erased_count += it->second - it->first + 1;
			it = ranges.erase(it);
		}
		if (it->first - 1 <= r && r <= it->second) {
			erased_count += it->second - it->first + 1;
			r = it->second;
			ranges.erase(it);
		}
		ranges.emplace(l, r);
		return r - l + 1 - erased_count;
	}
	T insert(T x) {
		return insert(x, x);
	}
	T erase(T l, T r) {
		assert(l <= r);
		auto it = next_range_iterator(l);
		if (it->first <= l && r <= it->second) {
			if (it->first < l) {
				ranges.emplace(it->first, l - 1);
			}
			if (r < it->second) {
				ranges.emplace(r + 1, it->second);
			}
			ranges.erase(it);
			return r - l + 1;
		}

		T erased_count = 0;
		if (it->first <= l && l <= it->second) {
			erased_count += it->second - l + 1;
			if (it->first < l) {
				ranges.emplace(it->first, l - 1);
			}
			it = ranges.erase(it);
		} else {
			it = next(it);
		}
		while (it->second <= r) {
			erased_count += it->second - it->first + 1;
			it = ranges.erase(it);
		}
		if (it->first <= r && r <= it->second) {
			erased_count += r - it->first + 1;
			if (r < it->second) {
				ranges.emplace(r + 1, it->second);
			}
			ranges.erase(it);
		}
		return erased_count;
	}
	T erase(T x) {
		return erase(x, x);
	}
	T find_next(T x) const {
		auto [l, r] = next_range(x);
		if (l <= x && x <= r) {
			return x;
		} else {
			return l;
		}
	}
	T mex(T x) const {
		auto [l, r] = next_range(x);
		if (l <= x && x <= r) {
			return r + 1;
		} else {
			return x;
		}
	}
};
