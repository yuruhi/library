#pragma once
#include "./Geometric.hpp"
#include "./Vec2.hpp"
#include "./Line.hpp"
#include <iostream>
using namespace std;

namespace Geometric {

	struct Rect {
		Vec2 pos, size;
		constexpr Rect() {}
		constexpr Rect(LD _w, LD _h) : size(_w, _h) {}
		constexpr Rect(const Vec2& _size) : size(_size) {}
		constexpr Rect(LD _x, LD _y, LD _w, LD _h) : pos(_x, _y), size(_w, _h) {}
		constexpr Rect(const Vec2& _pos, const Vec2& _size) : pos(_pos), size(_size) {}
		constexpr bool operator==(const Rect& r) const {
			return pos == r.pos && size == r.size;
		}
		constexpr bool operator!=(const Rect& r) const {
			return !(*this == r);
		}
		constexpr Rect operator+(const Vec2& v) const {
			return Rect(*this) += v;
		}
		constexpr Rect operator-(const Vec2& v) const {
			return Rect(*this) -= v;
		}
		constexpr Rect& operator+=(const Vec2& v) {
			pos += v;
			return *this;
		}
		constexpr Rect& operator-=(const Vec2& v) {
			pos -= v;
			return *this;
		}
		constexpr Rect& set_center(const Vec2& _pos) {
			pos = _pos - size / 2;
			return *this;
		}
		constexpr LD left_x() const {
			return pos.x;
		}
		constexpr LD right_x() const {
			return pos.x + size.x;
		}
		constexpr LD top_y() const {
			return pos.y;
		}
		constexpr LD bottom_y() const {
			return pos.y + size.y;
		}
		constexpr Vec2 top_left() const {
			return pos;
		}
		constexpr Vec2 top_right() const {
			return pos + Vec2(size.x, 0);
		}
		constexpr Vec2 bottom_left() const {
			return pos + Vec2(0, size.y);
		}
		constexpr Vec2 bottom_right() const {
			return pos + size;
		}
		constexpr Segment top() const {
			return Segment(top_left(), top_right());
		}
		constexpr Segment bottom() const {
			return Segment(bottom_left(), bottom_right());
		}
		constexpr Segment left() const {
			return Segment(top_left(), bottom_left());
		}
		constexpr Segment right() const {
			return Segment(top_right(), bottom_right());
		}
		constexpr Vec2 center() const {
			return pos + size / 2;
		}
		constexpr LD area() const {
			return size.x * size.y;
		}
		constexpr LD perimeter() const {
			return (size.x + size.y) * 2;
		}
		template <class Shape2DType> LD distance(const Shape2DType& shape) const {
			return Geometric::distance(*this, shape);
		}
		constexpr bool contains(const Rect& r) const {
			return top_left() <= r.top_left() && r.bottom_right() <= bottom_right();
		}
		constexpr bool contains(const Circle& c) const {
			return top_left() <= Vec2(c.left_x(), c.top_y()) && Vec2(c.right_x(), c.bottom_y()) <= bottom_right();
		}
		friend ostream& operator<<(ostream& os, const Rect& r) {
			return os << '(' << r.pos << ',' << r.size << ')';
		}
		friend istream& operator>>(istream& is, Rect& r) {
			return is >> r.pos >> r.size;
		}
	};

}  // namespace Geometric
