#pragma once
#include <set>
#include <utility>
#include <cassert>
using namespace std;

template <class T> class RangeSet {
public:
	using size_type = size_t;
	using value_type = T;
	using range_type = pair<value_type, value_type>;

private:
	constexpr static value_type MIN = numeric_limits<value_type>::min();
	constexpr static value_type MAX = numeric_limits<value_type>::max();
	set<range_type> ranges;
	size_t size_m;

	auto prev_range_iterator(value_type x) const {
		return prev(ranges.lower_bound({x + 1, x + 1}));
	}
	range_type prev_range(value_type x) const {
		return *prev_range_iterator(x);
	}

public:
	RangeSet() : size_m(0) {
		ranges.emplace(MIN, MIN);
		ranges.emplace(MAX, MAX);
	};
	size_t size() const {
		return size_m;
	}
	size_t count_ranges() const {
		return ranges.size() - 2;
	}
	bool empty() const {
		return size() == 0;
	}
	void clear() {
		ranges.clear();
		ranges.emplace(MIN, MIN);
		ranges.smplace(MAX, MAX);
		size_m = 0;
	}
	bool contains(value_type l, value_type r) const {
		assert(l <= r);
		auto [L, R] = prev_range(l);
		return L <= l && r <= R;
	}
	bool contains(value_type x) const {
		return contains(x, x);
	}
	value_type insert(value_type l, value_type r) {
		assert(l <= r);
		auto it = prev_range_iterator(l);
		value_type erased_count = 0;
		if (l < it->first || it->second < r) {
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
		}
		value_type inserted_count = r - l + 1 - erased_count;
		size_m += inserted_count;
		return inserted_count;
	}
	value_type insert(value_type x) {
		return insert(x, x);
	}
	value_type erase(value_type l, value_type r) {
		assert(l <= r);
		auto it = prev_range_iterator(l);
		value_type erased_count = 0;
		if (it->first <= l && r <= it->second) {
			if (it->first < l) {
				ranges.emplace(it->first, l - 1);
			}
			if (r < it->second) {
				ranges.emplace(r + 1, it->second);
			}
			ranges.erase(it);
			erased_count = r - l + 1;
		} else {
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
		}
		size_m -= erased_count;
		return erased_count;
	}
	value_type erase(value_type x) {
		return erase(x, x);
	}
	value_type find_next(value_type x) const {
		auto [l, r] = prev_range(x);
		if (l <= x && x <= r) {
			return x;
		} else {
			return l;
		}
	}
	value_type mex(value_type x) const {
		auto [l, r] = prev_range(x);
		if (l <= x && x <= r) {
			return r + 1;
		} else {
			return x;
		}
	}
};
