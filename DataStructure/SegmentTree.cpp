// description : update, range query
template <class T> class SegmentTree {
	using Func = function<T(T, T)>;
	int N;
	T init;
	vector<T> A;
	Func F;
	static int ceil2(int n) {
		int m = 1;
		while (m < n)
			m *= 2;
		return m;
	}

	template <class C> int ff(int a, int b, const C& c, int k, int l, int r) const {
		if (!c(A[k]) || r <= a || b <= l) {
			return -1;
		} else if (k >= N) {
			return k - N;
		} else {
			int lv = ff(a, b, c, 2 * k, l, (l + r) / 2);
			if (lv != -1) return lv;
			return ff(a, b, c, 2 * k + 1, (l + r) / 2, r);
		}
	}
	template <class C> int fl(int a, int b, const C& c, int k, int l, int r) const {
		if (!c(A[k]) || r <= a || b <= l) {
			return -1;
		} else if (k >= N) {
			return k - N;
		} else {
			int rv = fl(a, b, c, 2 * k + 1, (l + r) / 2, r);
			if (rv != -1) return rv;
			return fl(a, b, c, 2 * k, l, (l + r) / 2);
		}
	}

public:
	SegmentTree(int n, const T& init_, const Func& f) : N(ceil2(n)), init(init_), A(N * 2, init), F(f) {}
	SegmentTree(const vector<T>& vec, const T& init_, const Func& f) : init(init_), F(f) {
		build(vec);
	}
	void build(const vector<T>& v) {
		N = ceil2(v.size());
		A.assign(N * 2, init);
		for (size_t i = 0; i < v.size(); ++i) {
			A[i + N] = v[i];
		}
		for (int i = N - 1; i > 0; --i) {
			A[i] = F(A[i * 2], A[i * 2 + 1]);
		}
	}
	void update(int i, const T& x) {
		assert(0 <= i && i < N);
		A[i += N] = x;
		while (i >>= 1) {
			A[i] = F(A[i * 2], A[i * 2 + 1]);
		}
	}
	T operator[](int i) const {
		assert(0 <= i && i < N);
		return A[i + N];
	}
	T operator()(int l, int r) const {  // [l, r)
		assert(0 <= l && l < r && r <= N);
		T L = init, R = init;
		for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
			if (l & 1) L = F(L, A[l++]);
			if (r & 1) R = F(A[--r], R);
		}
		return F(L, R);
	}
	template <class C> int find_first(int l, int r, const C& c) const {
		return ff(l, r, c, 1, 0, N);
	}
	template <class C> int find_last(int l, int r, const C& c) const {
		return fl(l, r, c, 1, 0, N);
	}
	vector<T> to_a() const {
		vector<T> res(N);
		for (int i = 0; i < N; ++i)
			res[i] = operator[](i);
		return res;
	}
};