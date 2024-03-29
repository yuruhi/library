#pragma once
#include "./Geometric.hpp"
#include "./Vec2.hpp"
#include "./Line.hpp"
#include "./Circle.hpp"
#include <tuple>
#include <cassert>

namespace Geometric {

	struct Triangle {
		Vec2 p1, p2, p3;
		static LD area(LD a, LD b, LD c) {
			LD s = (a + b + c) / 2;
			return sqrt(s * (s - a) * (s - b) * (s - c));
		}
		Triangle() = default;
		Triangle(const Vec2& _p1, const Vec2& _p2, const Vec2& _p3)
		    : p1(_p1), p2(_p2), p3(_p3) {
			assert(abs(iSP(p1, p2, p3)) == 1);
		}
		std::tuple<LD, LD, LD> sides() const {
			return {distance(p2, p3), distance(p1, p3), distance(p1, p2)};
		}
		LD area() const {
			return abs((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y)) / 2;
		}
		// 内接円
		Circle incircle() const {
			auto [l1, l2, l3] = sides();
			LD s = l1 + l2 + l3;
			LD x = (p1.x * l1 + p2.x * l2 + p3.x * l3) / s;
			LD y = (p1.y * l1 + p2.y * l2 + p3.y * l3) / s;
			s /= 2;
			LD r = sqrt((s - l1) * (s - l2) * (s - l3) / s);
			return Circle(x, y, r);
		}
		// 外接円
		Circle cirnumscribed_circle() const {
			Line l1((p1 + p2) / 2, (p1 + p2) / 2 + (p1 - p2).rotate270());
			Line l2((p1 + p3) / 2, (p1 + p3) / 2 + (p1 - p3).rotate270());
			Vec2 center = *cross_point(l1, l2);
			return Circle(center, distance(center, p1));
		}
		friend std::ostream& operator<<(std::ostream& os, const Triangle& t) {
			return os << '(' << t.p1 << ", " << t.p2 << ", " << t.p3 << ')';
		}
		friend std::istream& operator>>(std::istream& is, Triangle& t) {
			return is >> t.p1 >> t.p2 >> t.p3;
		}
	};

}  // namespace Geometric