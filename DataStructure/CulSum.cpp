#pragma once
#include <vector>
#include <algorithm>
#include <type_traits>

template <class T> class CulSum {
public:
	using value_type = T;
	using data_type = std::vector<value_type>;
	using size_type = std::size_t;

private:
	size_type n;
	data_type data;

public:
	CulSum() = default;
	CulSum(const data_type& a) : n(a.size()), data(n + 1) {
		for (size_type i = 0; i < n; ++i) {
			data[i + 1] = data[i] + a[i];
		}
	}
	template <class U, class F,
	          std::enable_if_t<std::is_integral_v<U>, std::nullptr_t> = nullptr>
	CulSum(const U& _n, F f) : n(_n), data(n + 1) {
		for (size_type i = 0; i < n; ++i) {
			data[i + 1] = data[i] + static_cast<value_type>(f(i));
		}
	}
	template <class U, class F,
	          std::enable_if_t<!std::is_integral_v<U>, std::nullptr_t> = nullptr>
	CulSum(const U& a, F f)
	    : CulSum(a.size(), [a, f](size_type i) -> value_type { return f(a[i]); }) {}
	size_type size() const {
		return n;
	}
	value_type at(size_type i) const {
		return operator()(i, i + 1);
	}
	// [l, r)
	value_type operator()(size_type l, size_type r) const {
		l = std::min(l, n);
		r = std::min(r, n);
		return l > r ? 0 : data[r] - data[l];
	}
	// [0, r)
	value_type operator()(size_type r) const {
		r = std::min(r, n);
		return data[r];
	}
	const data_type& get_data() const {
		return data;
	}
};
