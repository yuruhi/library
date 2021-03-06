#pragma once
#include <limits>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <optional>

template <class T> struct Range {
	using value_type = T;

	value_type x, y;  // [x, y]

	static constexpr bool cmp_x(const Range& r1, const Range& r2) {
		return r1.x < r2.x;
	}
	static constexpr bool cmp_y(const Range& r1, const Range& r2) {
		return r1.y < r2.y;
	}
	static constexpr bool cmp_xy(const Range& r1, const Range& r2) {
		return r1.pair() < r2.pair();
	}
	static constexpr bool cmp_yx(const Range& r1, const Range& r2) {
		return r1.anti_pair() < r2.anti_pair();
	}

	constexpr Range() : x(0), y(0) {}
	constexpr Range(value_type _x, value_type _y, bool exclude_end = false)
	    : x(_x), y(_y - !exclude_end) {
		assert(x <= y);
	}
	constexpr Range(const Range& _r, bool exclude_end = true)
	    : x(_r.x), y(_r.y - !exclude_end) {
		assert(x <= y);
	}
	constexpr bool operator==(const Range& r) const {
		return x == r.x && y == r.y;
	}
	constexpr bool operator!=(const Range& r) const {
		return x != r.x || y != r.y;
	}
	constexpr bool operator<(const Range& r) const {
		return pair() < r.pair();
	}
	constexpr bool operator<=(const Range& r) const {
		return pair() <= r.pair();
	}
	constexpr bool operator>(const Range& r) const {
		return pair() > r.pair();
	}
	constexpr bool operator>=(const Range& r) const {
		return pair() >= r.pair();
	}
	constexpr Range& operator<<=(const value_type& n) {
		x -= n;
		y -= n;
		return *this;
	}
	constexpr Range& operator>>=(const value_type& n) {
		x += n;
		y += n;
		return *this;
	}
	constexpr Range& operator*=(const value_type& n) {
		x *= n;
		y *= n;
		return *this;
	}
	constexpr Range operator<<(const value_type& n) const {
		return Range(*this) <<= n;
	}
	constexpr Range operator>>(const value_type& n) const {
		return Range(*this) >>= n;
	}
	constexpr Range operator*(const value_type& n) const {
		return Range(*this) *= n;
	}
	constexpr std::optional<Range> operator&(const Range& r) const {
		if (intersects(r)) {
			return Range(std::max(x, r.x), std::min(y, r.y));
		} else {
			return std::nullopt;
		}
	}
	constexpr std::optional<Range> operator|(const Range& r) const {
		if (intersects(r) || adjacent(r)) {
			return Range(std::min(x, r.x), std::max(y, r.y));
		} else {
			return std::nullopt;
		}
	}
	constexpr value_type operator[](const value_type& n) const {  // 0-indexed
		assert(x + n <= y);
		return x + n;
	}
	constexpr Range operator[](const Range& n) const {
		return Range(operator[](n.x), operator[](n.y));
	}
	constexpr auto pair() const {
		return std::pair(x, y);
	}
	constexpr auto anti_pair() const {
		return std::pair(y, x);
	}
	constexpr Range open() const {
		return Range(x, y + 1);
	}
	constexpr bool include(const value_type& n) const {
		return x <= n && n <= y;
	}
	constexpr bool intersects(const Range& r) const {
		return std::max(x, r.x) <= std::min(y, r.y);
	}
	constexpr bool contains(const Range& r) const {
		return x <= r.x && r.y <= y;
	}
	constexpr bool adjacent(const Range& r) const {
		return y + 1 == r.x || r.y + 1 == x;
	}
	constexpr value_type size() const {
		return std::max<value_type>(0, y - x + 1);
	}
	constexpr value_type sum() const {
		return (x + y) * size() / 2;
	}
	friend std::ostream& operator<<(std::ostream& os, const Range& r) {
		return os << '[' << r.x << ", " << r.y << ']';
	}
	friend std::istream& operator>>(std::istream& is, Range& r) {
		return is >> r.x >> r.y;
	}
};
template <class T, class U>
constexpr std::optional<Range<T>> equal_range(const U& a, const Range<T>& r) {
	auto L = std::lower_bound(a.begin(), a.end(), r.x) - a.begin();
	auto R = std::upper_bound(a.begin(), a.end(), r.y) - a.begin();
	return L == R ? std::nullopt : Range<T>(L, R, true);
}
