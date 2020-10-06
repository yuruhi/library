#pragma once
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
using namespace std;

template <class T, class U> inline int Lower(const T& a, const U& v) {
	return lower_bound(all(a), v) - a.begin();
}
template <class T, class U> inline int Upper(const T& a, const U& v) {
	return upper_bound(all(a), v) - a.begin();
}
template <class T> inline auto Slice(const T& v, size_t i, size_t len) {
	return i < v.size() ? T(v.begin() + i, v.begin() + min(i + len, v.size())) : T();
}
template <class T> inline T Ceil(T n, T m) {
	return (n + m - 1) / m;
}
template <class T> inline T Ceil2(T n, T m) {
	return Ceil(n, m) * m;
}
template <class T> inline T Tri(T n) {
	return (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);
}
template <class T> inline T nC2(T n) {
	return (n & 1) ? (n - 1) / 2 * n : n / 2 * (n - 1);
}
template <class T> inline T Mid(const T& l, const T& r) {
	return l + (r - l) / 2;
}
template <class T> inline bool chmax(T& a, const T& b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template <class T> inline bool chmin(T& a, const T& b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T> inline bool inRange(const T& v, const T& min, const T& max) {
	return min <= v && v < max;
}
template <class T> inline bool isSquere(T n) {
	T s = sqrt(n);
	return s * s == n || (s + 1) * (s + 1) == n;
}
template <class T = long long> inline T BIT(int b) {
	return T(1) << b;
}
template <class T, class U = typename T::value_type> inline U Gcdv(const T& v) {
	return accumulate(next(v.begin()), v.end(), U(*v.begin()), gcd<U, U>);
}
template <class T, class U = typename T::value_type> inline U Lcmv(const T& v) {
	return accumulate(next(v.begin()), v.end(), U(*v.begin()), lcm<U, U>);
}
template <class T> inline T Pow(T a, T n) {
	T r = 1;
	while (n > 0) {
		if (n & 1) r *= a;
		a *= a;
		n /= 2;
	}
	return r;
}
template <class T> inline T Powmod(T a, T n, T m = MOD) {
	T r = 1;
	while (n > 0) {
		if (n & 1)
			r = r * a % m, n--;
		else
			a = a * a % m, n /= 2;
	}
	return r;
}