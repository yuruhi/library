#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

template <class T> class RangeAddQuery {
	int n;
	vector<T> a;
	static int ceil2(int n) {
		int m = 1;
		while (m < n)
			m *= 2;
		return m;
	}

public:
	RangeAddQuery(int _n) : n(ceil2(_n)), a(n * 2) {}
	RangeAddQuery(const vector<T>& v) : n(ceil2(v.size())), a(n * 2) {
		for (size_t i = 0; i < v.size(); ++i) {
			a[i + n] = v[i];
		}
	}
	void add(int l, int r, const T& x) {
		l = clamp(l, 0, n);
		r = clamp(r, 0, n);
		if (l >= r) return;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) a[l++] += x;
			if (r & 1) a[--r] += x;
		}
	}
	void add(int i, const T& x) {
		add(i, i + 1, x);
	}
	T operator[](int i) const {
		assert(0 <= i && i < n);
		T res = a[i += n];
		while (i >>= 1) {
			res += a[i];
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
