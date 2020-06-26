// shortcut : RangeAddQueyLazy
// description : 区間加算、区間クエリ
template <class T> class RangeAddQuery {
	using Func = function<T(T, T)>;
	int n;
	T init;
	vector<T> node, lazy;
	Func func;
	static int ceil2(int n) {
		int m = 1;
		while (m < n) m *= 2;
		return m;
	}
	void eval(int k, int l, int r) {
		if (lazy[k] != 0) {
			node[k] += lazy[k];
			if (r - l > 1) {
				lazy[2 * k + 0] += lazy[k] / 2;
				lazy[2 * k + 1] += lazy[k] / 2;
			}
			lazy[k] = 0;
		}
	}
	void add_impl(int a, int b, const T& x, int k, int l, int r) {
		eval(k, l, r);
		if (b <= l || r <= a) {
			return;
		} else if (a <= l && r <= b) {
			lazy[k] += x * (r - l);
			eval(k, l, r);
		} else {
			add_impl(a, b, x, 2 * k + 0, l, (l + r) / 2);
			add_impl(a, b, x, 2 * k + 1, (l + r) / 2, r);
			node[k] = node[2 * k] + node[2 * k + 1];
		}
	}
	T query_impl(int a, int b, int k, int l, int r) {
		if (b <= l || r <= a) {
			return 0;
		}
		eval(k, l, r);
		if (a <= l && r <= b) {
			return node[k];
		} else {
			auto vl = query_impl(a, b, 2 * k + 0, l, (l + r) / 2);
			auto vr = query_impl(a, b, 2 * k + 1, (l + r) / 2, r);
			return func(vl, vr);
		}
	}

public:
	RangeAddQuery(int _n, const T& _init, const Func& f)
	    : n(ceil2(_n)), init(_init), node(n * 2, init), lazy(n * 2, 0), func(f) {}
	RangeAddQuery(const vector<T>& vec, const T& _init, const Func& f) : init(_init), func(f) {
		build(vec);
	}
	void build(const vector<T>& v) {
		n = ceil2(v.size());
		node.assign(n * 2, init);
		lazy.assign(n * 2, 0);
		for (int i = 0; i < v.size(); ++i) {
			node[i + n] = v[i];
		}
		for (int i = n - 1; i > 0; --i) {
			node[i] = func(node[i * 2], node[i * 2 + 1]);
		}
	}
	void add(int l, int r, const T& x) {
		add_impl(l, r, x, 1, 0, n);
	}
	T operator[](int i) const {
		assert(0 <= i && i < n);
		return operator()(i, i + 1);
	}
	T operator()(int l, int r) {
		assert(0 <= l && l < r && r <= n);
		return query_impl(l, r, 1, 0, n);
	}
};