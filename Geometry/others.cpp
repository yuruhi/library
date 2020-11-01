#pragma once
#include "./Geometric.hpp"
#include "./Vec2.hpp"

namespace Geometric {

	LD TriangleArea(LD a, LD b, LD c) {
		LD s = (a + b + c) / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}
	LD TriangleArea(const Vec2& v1, const Vec2& v2, const Vec2& v3) {
		return TriangleArea(v1.distance(v2), v1.distance(v3), v2.distance(v3));
	}

}  // namespace Geometric
