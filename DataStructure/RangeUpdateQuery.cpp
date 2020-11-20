#pragma once
#include <vector>
#include <utility>
using namespace std;

template <class T> class RangeUpdateQuery {
	int n;
	vector<pair<size_t, T>> a;
	size_t update_count = 1;
	static int ceil2(int n) {
		int m = 1;
		while (m < n) m *= 2;
		return m;
	}

public:
	RangeUpdateQuery(int _n, const T& init)
	    : n(ceil2(_n)), a(n * 2, make_pair(0, init)) {}
	RangeUpdateQuery(const vector<T>& v) : n(ceil2(v.size())), a(n * 2) {
		for (size_t i = 0; i < v.size(); ++i) {
			a[i + n] = make_pair(0, v[i]);
		}
	}
	void update(int l, int r, const T& x) {
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) a[l++] = make_pair(update_count, x);
			if (r & 1) a[--r] = make_pair(update_count, x);
		}
		update_count++;
	}
	T operator[](int i) const {
		auto [max_count, res] = a[i += n];
		while (i >>= 1) {
			if (max_count < a[i].first) {
				max_count = a[i].first;
				res = a[i].second;
			}
		}
		return res;
	}
	vector<T> to_a() const {
		vector<T> res(n);
		for (int i = 0; i < n; ++i) {
			res[i] = operator[](i);
		}
		return res;
	}
};
