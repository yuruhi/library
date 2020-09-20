// description : BinaryIndexedTree
template <class T> class BinaryIndexedTree {
	int n, n2;
	vector<T> a;

public:
	BinaryIndexedTree(int n_) : n(n_), a(n_ + 1), n2(1) {
		while (n2 < n)
			n2 *= 2;
		n2 /= 2;
	}
	T operator()(int i) const {  // [0, i]
		assert(0 < ++i);
		T res = 0;
		for (; i > 0; i -= i & -i)
			res += a[i];
		return res;
	}
	T operator()(int i, int j) const {  // [i, j]
		return operator()(j) - (i ? operator()(i - 1) : 0);
	}
	T operator[](int i) const {
		return operator()(i, i);
	}
	void add(int i, T x) {
		assert(0 < ++i);
		for (; i <= n; i += i & -i)
			a[i] += x;
	}
	int lower_bound(T k) const {
		if (k <= 0) return 0;
		int res = 0;
		for (int i = n2; i > 0; i /= 2) {
			if (res + i <= n && a[res + i] < k) {
				k -= a[res + i];
				res += i;
			}
		}
		return res;
	}
	vector<int> debug() const {
		vector<int> res(n);
		for (int i = 0; i < n; ++i)
			res[i] = operator()(i, i);
		return res;
	}
};