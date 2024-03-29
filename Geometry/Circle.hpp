#pragma once
#include "./Geometric.hpp"
#include "./Vec2.hpp"
#include <iostream>

namespace Geometric {

	struct Circle {
		Vec2 center;
		LD r;
		constexpr Circle() : center(), r(0) {}
		constexpr Circle(LD _r) : center(), r(_r) {}
		constexpr Circle(LD _x, LD _y, LD _r) : center(_x, _y), r(_r) {}
		constexpr Circle(const Vec2& _c, LD _r) : center(_c), r(_r) {}
		constexpr bool operator==(const Circle& c) const {
			return center == c.center && sgn(r - c.r) == 0;
		}
		constexpr bool operator!=(const Circle& c) const {
			return !(*this == c);
		}
		constexpr Circle& operator+(const Vec2& v) const {
			return Circle(*this) += v;
		}
		constexpr Circle& operator-(const Vec2& v) const {
			return Circle(*this) -= v;
		}
		constexpr Circle& operator+=(const Vec2& v) {
			center += v;
			return *this;
		}
		constexpr Circle& operator-=(const Vec2& v) {
			center -= v;
			return *this;
		}
		constexpr LD top_y() const {
			return center.y - r;
		}
		constexpr LD bottom_y() const {
			return center.y + r;
		}
		constexpr LD left_x() const {
			return center.x - r;
		}
		constexpr LD right_x() const {
			return center.x + r;
		}
		constexpr Vec2 top() const {
			return center - Vec2(0, r);
		}
		constexpr Vec2 bottom() const {
			return center + Vec2(0, r);
		}
		constexpr Vec2 left() const {
			return center - Vec2(r, 0);
		}
		constexpr Vec2 right() const {
			return center + Vec2(r, 0);
		}
		constexpr LD area() const {
			return r * r * PI;
		}
		constexpr LD perimeter() const {
			return 2 * r * PI;
		}
		// c が this に含まれる（一致するときも true を返す）
		bool contains(const Circle& c) const {
			return sgn(distance(center, c.center) + c.r - r) <= 0;
		}
		friend std::ostream& operator<<(std::ostream& os, const Circle& c) {
			return os << '(' << c.center.x << ", " << c.center.y << ", " << c.r << ')';
		}
		friend std::istream& operator>>(std::istream& is, Circle& c) {
			return is >> c.center >> c.r;
		}
	};

}  // namespace Geometric
