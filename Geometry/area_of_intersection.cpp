#pragma once
#include "./Geometric.hpp"
#include "./Geometric.cpp"

namespace Geometric {
	LD area_of_intersection(const Circle& c1, const Circle& c2) {
		if (c1.contains(c2)) {
			return c2.area();
		} else if (c2.contains(c1)) {
			return c1.area();
		} else if (intersect(c1, c2)) {
			LD dist = distance(c1.center, c2.center);
			LD r1_s = c1.r * c1.r, r2_s = c2.r * c2.r, dist_s = dist * dist;
			LD angle1 = acos((r1_s + dist_s - r2_s) / (2 * c1.r * dist));
			LD angle2 = acos((r2_s + dist_s - r1_s) / (2 * c2.r * dist));
			return r1_s * (angle1 - sin(angle1 * 2) / 2) +
			    r2_s * (angle2 - sin(angle2 * 2) / 2);
		} else {
			return 0;
		}
	}
	LD area_of_intersection(const Circle& c, const Polygon& p) {
		auto signed_area = [c](Vec2 x, Vec2 y, bool triangle) {
			if (triangle) {
				return x.cross(y) / 2;
			} else {
				return c.r * c.r * angle(x, Vec2::zero(), y) / 2;
			}
		};

		// 円 c と 三角形 {(0, 0), a, b} の共通部分の面積
		auto circle_and_triangle = [signed_area](Circle c, Vec2 a, Vec2 b) -> LD {
			a -= c.center;
			b -= c.center;
			c.center -= c.center;
			if (sgn(distance(a, b)) == 0) {
				return 0;
			} else if (bool in_a = intersect(a, c), in_b = intersect(b, c); in_a && in_b) {
				return signed_area(a, b, true);
			} else if (auto points = cross_points(c, Segment(a, b)); points.empty()) {
				return signed_area(a, b, false);
			} else {
				Vec2 p1 = points.front(), p2 = points.back();
				swap(p1, p2);
				return signed_area(p1, p2, true) + signed_area(a, p1, in_a) +
				    signed_area(p2, b, in_b);
			}
		};

		LD area = 0;
		for (size_t i = 0; i < p.size(); ++i) {
			area += circle_and_triangle(c, p[i], p[i != p.size() - 1 ? i + 1 : 0]);
		}
		return area;
	}
}  // namespace Geometric
