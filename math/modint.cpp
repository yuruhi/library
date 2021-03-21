#pragma once
#include "./../Utility/get_MOD.cpp"
#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

template <int MOD> struct modint {
	using value_type = long long;

private:
	value_type n;

public:
	constexpr static modint factorial(int n) {
		assert(n >= 0);
		modint result = 1;
		for (int i = 1; i <= n; ++i) {
			result *= i;
		}
		return result;
	}
	constexpr modint(const value_type x = 0) : n(x % MOD) {
		if (n < 0) n += MOD;
	}
	constexpr value_type value() const {
		return n;
	}
	constexpr int mod() const {
		return MOD;
	}
	constexpr modint operator+() const {
		return *this;
	}
	constexpr modint operator-() const {
		return n ? MOD - n : 0;
	}
	constexpr modint& operator++() {
		if (MOD <= ++n) n = 0;
		return *this;
	}
	constexpr modint& operator--() {
		if (n <= 0) n = MOD;
		n--;
		return *this;
	}
	constexpr modint operator++(int) {
		modint t = *this;
		++*this;
		return t;
	}
	constexpr modint operator--(int) {
		modint t = *this;
		--*this;
		return t;
	}
	constexpr modint next() const {
		return ++modint(*this);
	}
	constexpr modint pred() const {
		return --modint(*this);
	}
	constexpr modint& operator+=(const modint& m) {
		n += m.n;
		if (n >= MOD) n -= MOD;
		return *this;
	}
	constexpr modint& operator-=(const modint& m) {
		n -= m.n;
		if (n < 0) n += MOD;
		return *this;
	}
	constexpr modint& operator*=(const modint& m) {
		n = n * m.n % MOD;
		return *this;
	}
	constexpr modint& operator/=(const modint& m) {
		value_type a = m.n, b = MOD, u = 1, v = 0;
		while (b) {
			value_type t = a / b;
			a -= t * b;
			std::swap(a, b);
			u -= t * v;
			std::swap(u, v);
		}
		n = n * u % MOD;
		if (n < 0) n += MOD;
		return *this;
	}
	constexpr bool operator==(const modint& m) const {
		return n == m.n;
	}
	constexpr bool operator!=(const modint& m) const {
		return n != m.n;
	}
	template <class M> constexpr modint pow(M m) const {
		if (0 <= m) {
			modint t = n, result = 1;
			while (m > 0) {
				if (m & 1) {
					result *= t;
					m--;
				} else {
					t *= t;
					m >>= 1;
				}
			}
			return result;
		} else {
			return (modint(1) / n).pow(-m);
		}
	}
	friend constexpr modint operator+(const modint& a, const modint& b) {
		return modint(a) += b;
	}
	friend constexpr modint operator-(const modint& a, const modint& b) {
		return modint(a) -= b;
	}
	friend constexpr modint operator*(const modint& a, const modint& b) {
		return modint(a) *= b;
	}
	friend constexpr modint operator/(const modint& a, const modint& b) {
		return modint(a) /= b;
	}
	friend std::ostream& operator<<(std::ostream& os, const modint<MOD>& m) {
		return os << m.value();
	}
	friend std::istream& operator>>(std::istream& is, modint<MOD>& m) {
		modint<MOD>::value_type x;
		is >> x;
		m = modint(x);
		return is;
	}
};

using mint = modint<get_MOD()>;
using VM = std::vector<mint>;
mint operator""_m(unsigned long long n) {
	return n;
}
