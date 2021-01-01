#pragma once
#include <vector>
#include <functional>
#include <cassert>
using namespace std;

template <class T> class SegmentTree {
public:
	using value_type = T;
	using func_type = function<value_type(value_type, value_type)>;

private:
	int n, original_n;
	value_type init;
	vector<value_type> data;
	func_type func;
	static int ceil2(int n) {
		int m = 1;
		while (m < n) m *= 2;
		return m;
	}

	template <class C> int ff(int a, int b, const C& c, int k, int l, int r) const {
		if (!c(data[k]) || r <= a || b <= l) {
			return -1;
		} else if (k >= n) {
			return k - n;
		} else {
			int lv = ff(a, b, c, 2 * k, l, (l + r) / 2);
			if (lv != -1) return lv;
			return ff(a, b, c, 2 * k + 1, (l + r) / 2, r);
		}
	}
	template <class C> int fl(int a, int b, const C& c, int k, int l, int r) const {
		if (!c(data[k]) || r <= a || b <= l) {
			return -1;
		} else if (k >= n) {
			return k - n;
		} else {
			int rv = fl(a, b, c, 2 * k + 1, (l + r) / 2, r);
			if (rv != -1) return rv;
			return fl(a, b, c, 2 * k, l, (l + r) / 2);
		}
	}

public:
	SegmentTree(int _n, const value_type& init_, const func_type& _func)
	    : n(ceil2(_n)), original_n(_n), init(init_), data(n * 2, init), func(_func) {}
	SegmentTree(const vector<value_type>& vec, const value_type& init_, const func_type& _func)
	    : init(init_), func(_func) {
		build(vec);
	}
	void build(const vector<value_type>& v) {
		n = ceil2(v.size());
		original_n = v.size();
		data.assign(n * 2, init);
		for (size_t i = 0; i < v.size(); ++i) {
			data[i + n] = v[i];
		}
		for (int i = n - 1; i > 0; --i) {
			data[i] = func(data[i * 2], data[i * 2 + 1]);
		}
	}
	void update(int i, const value_type& x) {
		assert(0 <= i && i < n);
		data[i += n] = x;
		while (i >>= 1) {
			data[i] = func(data[i * 2], data[i * 2 + 1]);
		}
	}
	void add(int i, const value_type& x) {
		update(i, operator[](i) + x);
	}
	value_type operator[](int i) const {
		assert(0 <= i && i < n);
		return data[i + n];
	}
	value_type operator()(int l, int r) const {
		assert(0 <= l && l < r && r <= n);
		value_type L = init, R = init;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) L = func(L, data[l++]);
			if (r & 1) R = func(data[--r], R);
		}
		return func(L, R);
	}
	template <class C> int find_first(int l, int r, const C& c) const {
		return ff(l, r, c, 1, 0, n);
	}
	template <class C> int find_last(int l, int r, const C& c) const {
		return fl(l, r, c, 1, 0, n);
	}
	vector<value_type> to_a() const {
		vector<value_type> res(original_n);
		for (int i = 0; i < original_n; ++i) {
			res[i] = operator[](i);
		}
		return res;
	}
};
