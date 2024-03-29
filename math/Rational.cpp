#pragma once
#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>

template <class T> class Rational {
public:
	using value_type = T;

private:
	value_type n, d;  // n / d
	constexpr void coprime() {
		value_type g = std::gcd(n, d);
		n /= g;
		d /= g;
		if (d < 0) {
			n = -n;
			d = -d;
		}
	}

public:
	Rational() = default;
	constexpr Rational(value_type _n, value_type _d = 1) : n(_n), d(_d) {
		assert(d != 0);
		coprime();
	}
	constexpr Rational operator+() const {
		return *this;
	}
	constexpr Rational operator-() const {
		Rational r(*this);
		r.n = -r.n;
		return r;
	}
	constexpr Rational& operator+(const Rational& r) const {
		return Rational(*this) += r;
	}
	constexpr Rational& operator-(const Rational& r) const {
		return Rational(*this) -= r;
	}
	constexpr Rational& operator*(const Rational& r) const {
		return Rational(*this) *= r;
	}
	constexpr Rational& operator/(const Rational& r) const {
		return Rational(*this) /= r;
	}
	constexpr Rational& operator+=(const Rational& r) {
		n = n * r.d + d * r.n;
		d *= r.d;
		coprime();
		return *this;
	}
	constexpr Rational& operator-=(const Rational& r) {
		n = n * r.d - d * r.n;
		d *= r.d;
		coprime();
		return *this;
	}
	constexpr Rational& operator*=(const Rational& r) {
		n *= r.n;
		d *= r.d;
		coprime();
		return *this;
	}
	constexpr Rational& operator/=(const Rational& r) {
		n *= r.d;
		d *= r.n;
		coprime();
		return *this;
	}
	constexpr bool operator==(const Rational& r) const {
		return n == r.n && d == r.d;
	}
	constexpr bool operator!=(const Rational& r) const {
		return !(*this == r);
	}
	constexpr bool operator<(const Rational& r) const {
		return n * r.d < d * r.n;
	}
	constexpr bool operator<=(const Rational& r) const {
		return *this < r || *this == r;
	}
	constexpr bool operator>(const Rational& r) const {
		return !(*this <= r);
	}
	constexpr bool operator>=(const Rational& r) const {
		return !(*this < r);
	}
	constexpr value_type denominator() const {
		return d;
	}
	constexpr value_type numerator() const {
		return n;
	}
	constexpr Rational abs() const {
		Rational r(*this);
		r.n = std::max(r.n, -r.n);
		return r;
	}
	constexpr value_type floor() const {
		return n > 0 ? n / d : (n - d + 1) / d;
	}
	constexpr value_type ceil() const {
		return (n + d - 1) / d;
	}
	constexpr value_type to_i() const {
		return n / d;
	}
	constexpr float to_f() const {
		return static_cast<float>(n) / static_cast<float>(d);
	}
	constexpr double to_d() const {
		return static_cast<double>(n) / static_cast<double>(d);
	}
	constexpr long double to_ld() const {
		return static_cast<long double>(n) / static_cast<long double>(d);
	}
	friend std::istream& operator>>(std::istream& is, Rational& r) {
		value_type n, d;
		is >> n >> d;
		r = Rational(n, d);
		return is;
	}
	friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
		return os << r.n << '/' << r.d;
	}
};
