#pragma once
#include "./Geometric.hpp"
#include "./Geometric.cpp"
#include <vector>
#include <algorithm>

namespace Geometric {
	std::vector<Line> common_tangent(const Circle& c1, const Circle& c2) {
		LD dist = distance(c1.center, c2.center);
		Vec2 vec = (c2.center - c1.center).normalized();
		if (sgn(dist - std::abs(c1.r - c2.r)) < 0) {
			return {};
		} else if (sgn(dist - std::abs(c1.r - c2.r)) == 0) {  // 内接
			Vec2 p;
			if (c1.r > c2.r) {
				p = c2.center + vec * c2.r;
			} else {
				p = c1.center + vec.rotate180() * c1.r;
			}
			return {Line(p, p + vec.rotate90())};
		} else {
			std::vector<Line> result;
			if (sgn(c1.r - c2.r) == 0) {
				Line l(c1.center, c2.center);
				result.push_back(l + vec.rotate90() * c1.r);
				result.push_back(l + vec.rotate270() * c1.r);
			} else {
				Vec2 p = c2.center + vec * ((dist * c2.r) / (c1.r - c2.r));
				auto c1_p = tangent_to_circle(c1, p), c2_p = tangent_to_circle(c2, p);
				for (std::size_t i = 0; i < std::min(c1_p.size(), c2_p.size()); ++i) {
					result.emplace_back(c1_p[i], c2_p[i]);
				}
			}
			if (int f = sgn(dist - (c1.r + c2.r)); f > 0) {  // 交点を持たない
				Vec2 p = c1.center + vec * ((dist * c1.r) / (c1.r + c2.r));
				auto c1_p = tangent_to_circle(c1, p), c2_p = tangent_to_circle(c2, p);
				for (std::size_t i = 0; i < std::min(c1_p.size(), c2_p.size()); ++i) {
					result.emplace_back(c1_p[i], c2_p[i]);
				}
			} else if (f == 0) {  //外接
				Vec2 p = c1.center + vec * c1.r;
				result.emplace_back(p, p + vec.rotate90());
			}
			return result;
		}
	}
}  // namespace Geometric
