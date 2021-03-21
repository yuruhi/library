#pragma once
#include <vector>
#include <utility>
#include <iostream>

struct mint {
	using value_type = long long;
	static value_type MOD;
	value_type n;

public:
	static void set_mod(value_type _MOD) {
		MOD = _MOD;
	}
	mint(value_type x = 0) : n(x % MOD) {
		if (n < 0) n += MOD;
	}
	mint operator+() const {
		return *this;
	}
	mint operator-() const {
		return n ? MOD - n : 0;
	}
	mint& operator++() {
		if (MOD <= ++n) n = 0;
		return *this;
	}
	mint& operator--() {
		if (n <= 0) n = MOD;
		n--;
		return *this;
	}
	mint operator++(int) {
		mint t = *this;
		++*this;
		return t;
	}
	mint operator--(int) {
		mint t = *this;
		--*this;
		return t;
	}
	mint next() const {
		return ++mint(*this);
	}
	mint pred() const {
		return --mint(*this);
	}
	mint operator+(const mint& m) const {
		return mint(*this) += m;
	}
	mint operator-(const mint& m) const {
		return mint(*this) -= m;
	}
	mint operator*(const mint& m) const {
		return mint(*this) *= m;
	}
	mint operator/(const mint& m) const {
		return mint(*this) /= m;
	}
	mint& operator+=(const mint& m) {
		n += m.n;
		if (n >= MOD) n -= MOD;
		return *this;
	}
	mint& operator-=(const mint& m) {
		n -= m.n;
		if (n < 0) n += MOD;
		return *this;
	}
	mint& operator*=(const mint& m) {
		n = n * m.n % MOD;
		return *this;
	}
	mint& operator/=(const mint& m) {
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
	bool operator==(const mint& m) const {
		return n == m.n;
	}
	bool operator!=(const mint& m) const {
		return n != m.n;
	}
	template <class M> mint pow(M m) const {
		mint t = n, result = 1;
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
	}
	template <class M> mint operator^(M m) const {
		return pow(m);
	}
	friend std::ostream& operator<<(std::ostream& os, const mint& m) {
		return os << m.n;
	}
	friend std::istream& operator>>(std::istream& is, mint& m) {
		value_type x;
		std::cin >> x;
		m = mint(x);
		return is;
	}
	friend mint operator""_m(unsigned long long n) {
		return n;
	}
};
mint::value_type mint::MOD = 1000000007;
using VM = vector<mint>;
