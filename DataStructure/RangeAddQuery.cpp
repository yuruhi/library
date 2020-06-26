// shortcut : RangeAddQuery
// description : 区間加算、一点取得
template<class T>class RangaAddQuery {
	int n;
	vector<T> a;
	static int ceil2(int n) {
		int m = 1;
		while (m < n)m *= 2;
		return m;
	}

public:
	RangaAddQuery(int _n) : n(ceil2(_n)), a(n * 2) {}
	void add(int l, int r, const T& x) {
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1)a[l++] += x;
			if (r & 1)a[--r] += x;
		}
	}
	T operator[](int i) {
		T res = a[i += n];
		while (i >>= 1) {
			res += a[i];
		}
		return res;
	}
};