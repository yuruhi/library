#pragma once
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <tuple>
#include <cassert>

template <class T = long long> constexpr T TEN(std::size_t n) {
	T result = 1;
	for (std::size_t i = 0; i < n; ++i) result *= 10;
	return result;
}
template <
    class T, class U,
    std::enable_if_t<std::is_integral_v<T> && std::is_integral_v<U>, std::nullptr_t> = nullptr>
constexpr auto div_ceil(T n, U m) {
	return (n + m - 1) / m;
}
template <class T, class U> constexpr auto div_ceil2(T n, U m) {
	return div_ceil(n, m) * m;
}
template <class T> constexpr T triangle(T n) {
	return (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);
}
template <class T> constexpr T nC2(T n) {
	return (n & 1) ? (n - 1) / 2 * n : n / 2 * (n - 1);
}
template <class T, class U> constexpr auto middle(const T& l, const U& r) {
	return l + (r - l) / 2;
}
template <class T, class U, class V>
constexpr bool in_range(const T& v, const U& lower, const V& upper) {
	return lower <= v && v < upper;
}
template <class T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
constexpr bool is_square(T n) {
	T s = std::sqrt(n);
	return s * s == n || (s + 1) * (s + 1) == n;
}
template <class T = long long> constexpr T BIT(int b) {
	return T(1) << b;
}
template <class T> constexpr int BIT(T x, int i) {
	return (x & (T(1) << i)) ? 1 : 0;
}
template <class T> constexpr int Sgn(T x) {
	return (0 < x) - (0 > x);
}
template <class T> bool is_leap(T year) {
	return !(year % 4) && (year % 100 || !(year % 400));
}
template <class T, class U, std::enable_if_t<std::is_integral_v<U>, std::nullptr_t> = nullptr>
constexpr T Pow(T a, U n) {
	assert(n >= 0);
	T result = 1;
	while (n > 0) {
		if (n & 1) {
			result *= a;
			n--;
		} else {
			a *= a;
			n >>= 1;
		}
	}
	return result;
}
template <class T, class U, std::enable_if_t<std::is_integral_v<U>, std::nullptr_t> = nullptr>
constexpr T Powmod(T a, U n, T mod) {
	assert(n >= 0);
	if (a > mod) a %= mod;
	T result = 1;
	while (n > 0) {
		if (n & 1) {
			result = result * a % mod;
			n--;
		} else {
			a = a * a % mod;
			n >>= 1;
		}
	}
	return result;
}
template <class T> bool chmax(T& a, const T& b) {
	return a < b ? a = b, true : false;
}
template <class T> bool chmin(T& a, const T& b) {
	return a > b ? a = b, true : false;
}
template <class T> int sz(const T& v) {
	return v.size();
}
template <class T, class U> int lower_index(const T& a, const U& v) {
	return std::lower_bound(a.begin(), a.end(), v) - a.begin();
}
template <class T, class U, class F> int lower_index(const T& a, const U& v, const F& f) {
	return std::lower_bound(a.begin(), a.end(), v, f) - a.begin();
}
template <class T, class U> int upper_index(const T& a, const U& v) {
	return std::upper_bound(a.begin(), a.end(), v) - a.begin();
}
template <class T, class U, class F> int upper_index(const T& a, const U& v, const F& f) {
	return std::upper_bound(a.begin(), a.end(), v, f) - a.begin();
}
template <class T, class U = typename T::value_type> U Gcdv(const T& v) {
	return std::accumulate(std::next(v.begin()), v.end(), U(*v.begin()), std::gcd<U, U>);
}
template <class T, class U = typename T::value_type> U Lcmv(const T& v) {
	return std::accumulate(std::next(v.begin()), v.end(), U(*v.begin()), std::lcm<U, U>);
}
template <class T> T& Concat(T& v, const T& vec) {
	v.insert(v.end(), vec.begin(), vec.end());
	return v;
}
namespace internal {
	template <class T, std::size_t N>
	auto make_vector(std::vector<int>& sizes, const T& init) {
		if constexpr (N == 1) {
			return std::vector(sizes[0], init);
		} else {
			int size = sizes[N - 1];
			sizes.pop_back();
			return std::vector(size, make_vector<T, N - 1>(sizes, init));
		}
	}
}  // namespace internal
template <class T, std::size_t N>
auto make_vector(const int (&sizes)[N], const T& init = T()) {
	std::vector s(std::rbegin(sizes), std::rend(sizes));
	return internal::make_vector<T, N>(s, init);
}
template <class F> struct rec_lambda {
	F f;
	rec_lambda(F&& f_) : f(std::forward<F>(f_)) {}
	template <class... Args> auto operator()(Args&&... args) const {
		return f(*this, std::forward<Args>(args)...);
	}
};

namespace lambda {
	auto char_to_int = [](char c) {
		return c - '0';
	};
	auto lower_to_int = [](char c) {
		return c - 'a';
	};
	auto upper_to_int = [](char c) {
		return c - 'A';
	};
	auto int_to_char = [](int i) -> char {
		return '0' + i;
	};
	auto int_to_lower = [](int i) -> char {
		return 'a' + i;
	};
	auto int_to_upper = [](int i) -> char {
		return 'A' + i;
	};
	auto is_odd = [](auto n) {
		return n % 2 == 1;
	};
	auto is_even = [](auto n) {
		return n % 2 == 0;
	};
	auto is_positive = [](auto n) {
		return n > 0;
	};
	auto is_negative = [](auto n) {
		return n < 0;
	};
	auto increment = [](auto n) {
		return ++n;
	};
	auto decrement = [](auto n) {
		return --n;
	};
	auto self = [](const auto& n) {
		return n;
	};
	auto first = [](const auto& n) {
		return n.first;
	};
	auto second = [](const auto& n) {
		return n.second;
	};
	template <class T> auto cast() {
		return [](const auto& n) {
			return static_cast<T>(n);
		};
	};
	template <class T> auto equal_to(const T& x) {
		return [x](auto y) {
			return x == y;
		};
	}
	template <std::size_t I> auto get() {
		return [](const auto& n) {
			return std::get<I>(n);
		};
	}
	template <class F> auto cmp(F&& f) {
		return [f](const auto& a, const auto& b) {
			return f(a) < f(b);
		};
	}
}  // namespace lambda
