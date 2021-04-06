#pragma once
#include <utility>
#include <tuple>
#include <iostream>

template <class T> struct Pair {
	using value_type = T;
	static constexpr bool cmp_x(const Pair<value_type>& p1, const Pair<value_type>& p2) {
		return p1.xy() < p2.xy();
	}
	static constexpr bool cmp_y(const Pair<value_type>& p1, const Pair<value_type>& p2) {
		return p1.yx() < p2.yx();
	}
	static constexpr value_type get_x(const Pair<value_type>& p) {
		return p.x;
	}
	static constexpr value_type get_y(const Pair<value_type>& p) {
		return p.y;
	}

	value_type x, y;
	constexpr Pair() : x(), y() {}
	constexpr Pair(value_type _x, value_type _y) : x(_x), y(_y) {}
	constexpr Pair(const std::pair<value_type, value_type>& xy) : x(xy.first), y(xy.second) {}
	constexpr Pair(const std::tuple<value_type, value_type>& xy)
	    : x(get<0>(xy)), y(get<1>(xy)) {}
	constexpr Pair operator+() const {
		return *this;
	}
	constexpr Pair operator-() const {
		return {-x, -y};
	}
	constexpr Pair operator+(const Pair& p) const {
		return Pair(*this) += p;
	}
	constexpr Pair operator-(const Pair& p) const {
		return Pair(*this) -= p;
	}
	constexpr Pair operator*(const Pair& p) const {
		return Pair(*this) *= p;
	}
	constexpr Pair operator/(const Pair& p) const {
		return Pair(*this) /= p;
	}
	constexpr Pair operator%(const Pair& p) const {
		return Pair(*this) %= p;
	}
	constexpr Pair operator+(value_type n) const {
		return Pair(*this) += n;
	}
	constexpr Pair operator-(value_type n) const {
		return Pair(*this) -= n;
	}
	constexpr Pair operator*(value_type n) const {
		return Pair(*this) *= n;
	}
	constexpr Pair operator/(value_type n) const {
		return Pair(*this) /= n;
	}
	constexpr Pair operator%(value_type n) const {
		return Pair(*this) %= n;
	}
	constexpr Pair& operator+=(const Pair& p) {
		x += p.x;
		y += p.y;
		return *this;
	}
	constexpr Pair& operator-=(const Pair& p) {
		x -= p.x;
		y -= p.y;
		return *this;
	}
	constexpr Pair& operator*=(const Pair& p) {
		x *= p.x;
		y *= p.y;
		return *this;
	}
	constexpr Pair& operator/=(const Pair& p) {
		x /= p.x;
		y /= p.y;
		return *this;
	}
	constexpr Pair& operator%=(const Pair& p) {
		x %= p.x;
		y %= p.y;
		return *this;
	}
	constexpr Pair& operator+=(value_type n) {
		x += n;
		y += n;
		return *this;
	}
	constexpr Pair& operator-=(value_type n) {
		x -= n;
		y -= n;
		return *this;
	}
	constexpr Pair& operator*=(value_type n) {
		x *= n;
		y *= n;
		return *this;
	}
	constexpr Pair& operator/=(value_type n) {
		x /= n;
		y /= n;
		return *this;
	}
	constexpr Pair& operator%=(value_type n) {
		x %= n;
		y %= n;
		return *this;
	}
	constexpr bool operator==(const Pair& p) const {
		return x == p.x && y == p.y;
	}
	constexpr bool operator!=(const Pair& p) const {
		return x != p.x || y != p.y;
	}
	constexpr bool operator<(const Pair& p) const {
		return x < p.x || (!(p.x < x) && y < p.y);
	}
	constexpr bool operator>(const Pair& p) const {
		return p < *this;
	}
	constexpr bool operator<=(const Pair& p) const {
		return !(p < *this);
	}
	constexpr bool operator>=(const Pair& p) const {
		return !(*this < p);
	}
	constexpr value_type operator[](size_t i) const {
		assert(0 <= i && i < 2);
		return i == 0 ? x : y;
	}
	constexpr auto to_pair() const {
		return std::pair(x, y);
	}
	constexpr auto to_tuple() const {
		return std::tuple(x, y);
	}
	constexpr Pair xy() const {
		return {x, y};
	}
	constexpr Pair yx() const {
		return {y, x};
	}
	constexpr operator std::tuple<value_type&, value_type&>() {
		return std::tuple<value_type&, value_type&>(x, y);
	}
	friend std::ostream& operator<<(std::ostream& os, const Pair& p) {
		return os << p.x << ' ' << p.y;
	}
	friend std::istream& operator>>(std::istream& is, Pair& p) {
		return is >> p.x >> p.y;
	}
};
namespace std {
	template <class T> struct tuple_size<Pair<T>> : integral_constant<size_t, 2> {};
	template <size_t N, class T> struct tuple_element<N, Pair<T>> { using type = T; };
}  // namespace std
template <size_t N, class T> T get(const Pair<T>& p) {
	return N == 0 ? p.x : p.y;
}
