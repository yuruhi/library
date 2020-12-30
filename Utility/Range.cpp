#pragma once
#include <limits>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <optional>
using namespace std;

template <class T> struct Range {
	using value_type = T;
	value_type x, y;  // [x, y]
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
		return to_pair() < r.to_pair();
	}
	constexpr bool operator<=(const Range& r) const {
		return to_pair() <= r.to_pair();
	}
	constexpr bool operator>(const Range& r) const {
		return to_pair() > r.to_pair();
	}
	constexpr bool operator>=(const Range& r) const {
		return to_pair() >= r.to_pair();
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
	constexpr optional<Range> operator&(const Range& r) const {
		if (intersects(r)) {
			return Range(std::max(x, r.x), std::min(y, r.y));
		} else {
			return nullopt;
		}
	}
	constexpr optional<Range> operator|(const Range& r) const {
		if (intersects(r) || adjacent(r)) {
			return Range(std::min(x, r.x), std::max(y, r.y));
		} else {
			return nullopt;
		}
	}
	constexpr value_type operator[](const value_type& n) const {  // 0-indexed
		assert(x + n <= y);
		return x + n;
	}
	constexpr Range operator[](const Range& n) const {
		return Range(operator[](n.x), operator[](n.y));
	}
	constexpr pair<value_type, value_type> to_pair() const {
		return make_pair(x, y);
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
		return max<value_type>(0, y - x + 1);
	}
	constexpr value_type sum() const {
		return (x + y) * size() / 2;
	}
	friend ostream& operator<<(ostream& os, const Range& r) {
		return os << '[' << r.x << ", " << r.y << ']';
	}
	friend istream& operator>>(istream& is, Range& r) {
		return is >> r.x >> r.y;
	}
};
template <class T, class U>
constexpr optional<Range<T>> equal_range(const U& a, const Range<T>& r) {
	auto L = lower_bound(a.begin(), a.end(), r.x) - a.begin();
	auto R = upper_bound(a.begin(), a.end(), r.y) - a.begin();
	return L == R ? nullopt : Range<T>(L, R, true);
}
