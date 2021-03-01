#pragma once
#include <vector>
#include <type_traits>
#include <cassert>
using namespace std;

template <class T> class CulSum {
public:
	using value_type = T;
	using data_type = vector<value_type>;

private:
	size_t n;
	data_type data;

public:
	CulSum() = default;
	CulSum(const data_type& a) : n(a.size()), data(n + 1) {
		for (size_t i = 0; i < n; ++i) {
			data[i + 1] = data[i] + a[i];
		}
	}
	template <class U, class F, enable_if_t<is_integral_v<U>, nullptr_t> = nullptr>
	CulSum(const U& _n, F f) : n(_n), data(n + 1) {
		for (size_t i = 0; i < n; ++i) {
			data[i + 1] = data[i] + static_cast<value_type>(f(i));
		}
	}
	template <class U, class F, enable_if_t<!is_integral_v<U>, nullptr_t> = nullptr>
	CulSum(const U& a, F f)
	    : CulSum(a.size(), [a, f](size_t i) -> value_type { return f(a[i]); }) {}
	size_t size() const {
		return n;
	}
	value_type at(size_t i) const {
		return operator()(i, i + 1);
	}
	// [l, r)
	value_type operator()(size_t l, size_t r) const {
		l = min(l, n);
		r = min(r, n);
		return l > r ? 0 : data[r] - data[l];
	}
	// [0, r)
	value_type operator()(size_t r) const {
		r = min(r, n);
		return data[r];
	}
	const data_type& get_data() const {
		return data;
	}
};
