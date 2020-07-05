// description : 累積和
template <class T> class CulSum {
	size_t n;
	vector<T> s;

public:
	CulSum(const vector<T> &a) : n(a.size()), s(n + 1) {
		for (size_t i = 0; i < n; ++i) s[i + 1] = s[i] + a[i];
	}
	template <class F> CulSum(int _n, F f) : n(_n), s(n + 1) {
		for (size_t i = 0; i < n; ++i) s[i + 1] = s[i] + static_cast<T>(f(i));
	}
	template <class U, class F> CulSum(const U &a, F f) : n(a.size()), s(n + 1) {
		for (size_t i = 0; i < n; ++i) s[i + 1] = s[i] + static_cast<T>(f(a[i]));
	}
	// [l, r)
	T operator()(size_t l, size_t r) const {
		return l > r ? 0 : s[r] - s[l];
	}
	// [0, r)
	T operator()(size_t r) const {
		assert(r <= n);
		return s[r];
	}
	const vector<T> &get_s() const {
		return s;
	}
};