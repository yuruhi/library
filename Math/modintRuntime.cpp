#pragma once
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

struct mint {
	using T = long long;
	static T MOD;
	T n;

public:
	static void set_mod(T _MOD) {
		MOD = _MOD;
	}
	mint(T x = 0) : n(x % MOD) {
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
		T a = m.n, b = MOD, u = 1, v = 0;
		while (b) {
			T t = a / b;
			a -= t * b;
			swap(a, b);
			u -= t * v;
			swap(u, v);
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
	mint pow(T m) const {
		mint t = n, res = 1;
		while (m > 0) {
			if (m & 1) res *= t;
			t *= t;
			m >>= 1;
		}
		return res;
	}
	mint operator^(T m) const {
		return pow(m);
	}
	friend ostream& operator<<(ostream& os, const mint& m) {
		return os << m.n;
	}
	friend istream& operator>>(istream& is, mint& m) {
		long long x;
		cin >> x;
		m = mint(x);
		return is;
	}
	friend mint operator""_m(unsigned long long n) {
		return n;
	}
};
long long mint::MOD = 1000000007;
using VM = vector<mint>;