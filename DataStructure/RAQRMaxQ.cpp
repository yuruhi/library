// description : 区間加算、区間max
template <class T> class RAQRMQ {
	int n;
	T init;
	vector<T> node, lazy;
	static int ceil2(int n) {
		int m = 1;
		while (m < n) m *= 2;
		return m;
	}
	void eval(int k, int l, int r) {
		if (lazy[k] != 0) {
			node[k] += lazy[k];
			if (r - l > 1) {
				lazy[2 * k + 0] += lazy[k];
				lazy[2 * k + 1] += lazy[k];
			}
			lazy[k] = 0;
		}
	}
	void add_impl(int a, int b, const T &x, int k, int l, int r) {
		eval(k, l, r);
		if (b <= l || r <= a) {
			return;
		} else if (a <= l && r <= b) {
			lazy[k] += x;
			eval(k, l, r);
		} else {
			add_impl(a, b, x, 2 * k + 0, l, (l + r) / 2);
			add_impl(a, b, x, 2 * k + 1, (l + r) / 2, r);
			node[k] = max(node[2 * k + 0], node[2 * k + 1]);
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
			return max(vl, vr);
		}
	}

public:
	RAQRMQ(const vector<T> &vec, const T &_init) : init(_init) {
		build(vec);
	}
	void build(const vector<T> &v) {
		n = ceil2(v.size());
		node.assign(n * 2, init);
		lazy.assign(n * 2, 0);
		for (int i = 0; i < v.size(); ++i) {
			node[i + n] = v[i];
		}
		for (int i = n - 1; i > 0; --i) {
			node[i] = max(node[i * 2 + 0], node[i * 2 + 1]);
		}
	}
	void add(int l, int r, const T &x) {
		add_impl(l, r, x, 1, 0, n);
	}
	T operator[](int i) {
		assert(0 <= i && i < n);
		return operator()(i, i + 1);
	}
	T operator()(int l, int r) {
		l = clamp(l, 0, n - 1);
		r = clamp(r, 0 + 1, n);
		assert(l < r);
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