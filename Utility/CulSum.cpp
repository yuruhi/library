#pragma once
#include <vector>
#include <cassert>
using namespace std;

template <class T> class CulSum {
public:
	using value_type = T;
	using data_type = vector<value_type>;

private:
	size_t n;
	data_type s;

public:
	CulSum(const data_type& a) : n(a.size()), s(n + 1) {
		for (size_t i = 0; i < n; ++i) {
			s[i + 1] = s[i] + a[i];
		}
	}
	template <class F> CulSum(int _n, F f) : n(_n), s(n + 1) {
		for (size_t i = 0; i < n; ++i) {
			s[i + 1] = s[i] + static_cast<value_type>(f(i));
		}
	}
	template <class U, class F>
	CulSum(const U& a, F f)
	    : CulSum(a.size(), [a, f](size_t i, size_t j) -> value_type { return f(a[i]); });
	// [l, r)
	value_type operator()(size_t l, size_t r) const {
		l = min(l, n);
		r = min(r, n);
		return l > r ? 0 : s[r] - s[l];
	}
	// [0, r)
	value_type operator()(size_t r) const {
		r = min(r, n);
		return s[r];
	}
	const data_type& get_data() const {
		return s;
	}
};
