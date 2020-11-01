#pragma once
#include "./Geometric.hpp"
#include "./Vec2.hpp"
#include "./others.cpp"
#include <iostream>
#include <vector>
using namespace std;

namespace Geometric {

	struct Circle {
		Vec2 center;
		LD r;
		constexpr Circle() : center(), r(0) {}
		constexpr Circle(LD _r) : center(), r(_r) {}
		constexpr Circle(LD _x, LD _y, LD _r) : center(_x, _y), r(_r) {}
		constexpr Circle(const Vec2& _c, LD _r) : center(_c), r(_r) {}
		constexpr bool operator==(const Circle& c) const {
			return center == c.center && Equal(r, c.r);
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
		template <class Shape2DType> LD distance(const Shape2DType& shape) const {
			return Geometric::distance(*this, shape);
		}
		template <class Shape2DType> bool intersects(const Shape2DType& shape) const {
			return Geometric::intersect(*this, shape);
		}
		bool contains(const Circle& c) const {
			return center.distance(c.center) + c.r < r - EPS;
		}
		bool tangent(const Circle& c) const {
			LD l1 = center.distance(c.center), l2 = r, l3 = c.r;
			return Equal(l1 + l2 + l3, max({l1, l2, l3}) * 2);
		}
		vector<Vec2> intersections(const Circle& c) {
			Vec2 v = center - c.center;
			LD l = v.length();
			if (contains(c) || c.contains(*this)) {
				return {};
			} else if (Equal(l, r + c.r)) {
				return {c.center + v * (l / c.r)};
			} else if (Equal(r + l, c.r)) {
				return {c.center + v * (c.r / l)};
			} else if (Equal(c.r + l, r)) {
				return {center + v.rotate180() * (r / l)};
			} else if (intersects(c)) {
				LD area = TriangleArea(l, r, c.r);
				LD y = 2 * area / l, x = sqrt(r * r - y * y);
				Vec2 h = center + v.rotate180() * (x / l);
				Vec2 v2 = v.rotate90() * (y / l);
				return {h + v2, h - v2};
			} else {
				return {};
			}
		}
		friend ostream& operator<<(ostream& os, const Circle& c) {
			return os << '(' << c.center.x << ',' << c.center.y << ',' << c.r << ')';
		}
		friend istream& operator>>(istream& is, Circle& c) {
			return is >> c.center >> c.r;
		}
	};

}  // namespace Geometric
