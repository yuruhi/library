#pragma once
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
using namespace std;

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
template <class T> T div_ceil(T n, T m) {
	return (n + m - 1) / m;
}
template <class T> T div_ceil2(T n, T m) {
	return div_ceil(n, m) * m;
}
template <class T> T triangle(T n) {
	return (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);
}
template <class T> T nC2(T n) {
	return (n & 1) ? (n - 1) / 2 * n : n / 2 * (n - 1);
}
template <class T> T middle(const T& l, const T& r) {
	return l + (r - l) / 2;
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
template <class T> bool in_range(const T& v, const T& min, const T& max) {
	return min <= v && v < max;
}
template <class T> bool in_square(T n) {
	T s = sqrt(n);
	return s * s == n || (s + 1) * (s + 1) == n;
}
template <class T = long long> T BIT(int b) {
	return T(1) << b;
}
template <class T, class U = typename T::value_type> U Gcdv(const T& v) {
	return accumulate(next(v.begin()), v.end(), U(*v.begin()), gcd<U, U>);
}
template <class T, class U = typename T::value_type> U Lcmv(const T& v) {
	return accumulate(next(v.begin()), v.end(), U(*v.begin()), lcm<U, U>);
}
template <class T, class U> T Pow(T a, U n) {
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
template <class T, class U> T Powmod(T a, U n, T mod) {
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
