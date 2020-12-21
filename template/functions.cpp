#pragma once
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <cassert>
using namespace std;

template <class T = long long> constexpr T TEN(size_t n) {
	T result = 1;
	for (size_t i = 0; i < n; ++i) result *= 10;
	return result;
}
template <class T, class U,
          enable_if_t<is_integral_v<T> && is_integral_v<U>, nullptr_t> = nullptr>
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
template <class T, enable_if_t<is_integral_v<T>, nullptr_t> = nullptr>
constexpr bool is_square(T n) {
	T s = sqrt(n);
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
template <class T, class U, enable_if_t<is_integral_v<U>, nullptr_t> = nullptr>
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
template <class T, class U, enable_if_t<is_integral_v<U>, nullptr_t> = nullptr>
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
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template <class T> bool chmin(T& a, const T& b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T> int sz(const T& v) {
	return v.size();
}
template <class T, class U> int lower_index(const T& a, const U& v) {
	return lower_bound(all(a), v) - a.begin();
}
template <class T, class U> int upper_index(const T& a, const U& v) {
	return upper_bound(all(a), v) - a.begin();
}
template <class T> auto Slice(const T& v, size_t i, size_t len) {
	return i < v.size() ? T(v.begin() + i, v.begin() + min(i + len, v.size())) : T();
}
template <class T, class U = typename T::value_type> U Gcdv(const T& v) {
	return accumulate(next(v.begin()), v.end(), U(*v.begin()), gcd<U, U>);
}
template <class T, class U = typename T::value_type> U Lcmv(const T& v) {
	return accumulate(next(v.begin()), v.end(), U(*v.begin()), lcm<U, U>);
}
namespace internal {
	template <class T, size_t N> auto make_vector(vector<int>& sizes, const T& init) {
		if constexpr (N == 1) {
			return vector(sizes[0], init);
		} else {
			int size = sizes[N - 1];
			sizes.pop_back();
			return vector(size, make_vector<T, N - 1>(sizes, init));
		}
	}
}  // namespace internal
template <class T, size_t N>
auto make_vector(const int (&sizes)[N], const T& init = T()) {
	vector s(rbegin(sizes), rend(sizes));
	return internal::make_vector<T, N>(s, init);
}
