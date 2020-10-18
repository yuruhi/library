#pragma once
#include <vector>
#include <optional>
#include <cassert>
using namespace std;

template <class T> class RAUQRSQ {
	int n;
	T init;
	vector<T> node, lazy_a;
	vector<optional<T>> lazy_u;
	static int ceil2(int n) {
		int m = 1;
		while (m < n)
			m *= 2;
		return m;
	}
	void set_lazy_a(int i, const T& x) {
		lazy_a[i] += x;
	}
	void set_lazy_u(int i, const T& x) {
		lazy_a[i] = 0;
		lazy_u[i] = x;
	}
	void eval(int k, int l, int r) {
		if (lazy_u[k]) {
			node[k] = *lazy_u[k];
			if (r - l > 1) {
				set_lazy_u(2 * k + 0, *lazy_u[k]);
				set_lazy_u(2 * k + 1, *lazy_u[k]);
			}
			lazy_u[k].reset();
		}
		if (lazy_a[k] != 0) {
			node[k] += lazy_a[k];
			if (r - l > 1) {
				set_lazy_a(2 * k + 0, lazy_a[k] / 2);
				set_lazy_a(2 * k + 1, lazy_a[k] / 2);
			}
			lazy_a[k] = 0;
		}
	}
	void add_impl(int a, int b, const T& x, int k, int l, int r) {
		eval(k, l, r);
		if (b <= l || r <= a) {
			return;
		} else if (a <= l && r <= b) {
			set_lazy_a(k, x * (r - l));
			eval(k, l, r);
		} else {
			add_impl(a, b, x, 2 * k + 0, l, (l + r) / 2);
			add_impl(a, b, x, 2 * k + 1, (l + r) / 2, r);
			node[k] = node[2 * k + 0] + node[2 * k + 1];
		}
	}
	void update_impl(int a, int b, const T& x, int k, int l, int r) {
		eval(k, l, r);
		if (b <= l || r <= a) {
			return;
		} else if (a <= l && r <= b) {
			set_lazy_u(k, x);
			eval(k, l, r);
		} else {
			update_impl(a, b, x, 2 * k + 0, l, (l + r) / 2);
			update_impl(a, b, x, 2 * k + 1, (l + r) / 2, r);
			node[k] = node[2 * k + 0] + node[2 * k + 1];
		}
	}
	T query_impl(int a, int b, int k, int l, int r) {
		if (b <= l || r <= a) {
			return init;
		}
		eval(k, l, r);
		if (a <= l && r <= b) {
			return node[k];
		} else {
			auto vl = query_impl(a, b, 2 * k + 0, l, (l + r) / 2);
			auto vr = query_impl(a, b, 2 * k + 1, (l + r) / 2, r);
			return vl + vr;
		}
	}

public:
	RAUQRSQ(const vector<T>& vec, const T& _init) : init(_init) {
		build(vec);
	}
	void build(const vector<T>& v) {
		n = ceil2(v.size());
		node.assign(n * 2, init);
		lazy_a.assign(n * 2, 0);
		lazy_u.assign(n * 2, nullopt);
		for (size_t i = 0; i < v.size(); ++i) {
			node[i + n] = v[i];
		}
		for (int i = n - 1; i > 0; --i) {
			node[i] = node[i * 2 + 0] + node[i * 2 + 1];
		}
	}
	void add(int l, int r, const T& x) {
		add_impl(l, r, x, 1, 0, n);
	}
	void update(int l, int r, const T& x) {
		update_impl(l, r, x, 1, 0, n);
	}
	T operator[](int i) {
		assert(0 <= i && i < n);
		return operator()(i, i + 1);
	}
	T operator()(int l, int r) {
		assert(0 <= l && l < r && r <= n);
		return query_impl(l, r, 1, 0, n);
	}
	vector<T> to_a() {
		vector<T> res(n);
		for (int i = 0; i < n; ++i) {
			res[i] = operator[](i);
		}
		return res;
	}
};
