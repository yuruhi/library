#pragma once
#include "./Vec2.hpp"
#include "./Line.hpp"
#include "./Circle.hpp"
#include "./Rect.hpp"
#include "./Triangle.hpp"
#include "./Polygon.hpp"
#include "./Geometric.hpp"

namespace Geometric {

	constexpr bool Equal(LD a, LD b) {
		return a < b ? b - a < EPS : a - b < EPS;
	}
	constexpr int sgn(LD a) {
		return a < -EPS ? -1 : a > EPS ? 1 : 0;
	}

	constexpr LD deg_to_rad(LD deg) {
		return deg * PI / 180;
	}
	constexpr LD rad_to_deg(LD rad) {
		return rad * 180 / PI;
	}

	Vec2 Vec2::projection(const Line& l) const {
		return l.begin + l.vec().normalized() * (*this - l.begin).dot(l.vec()) / l.vec().length();
	}
	Vec2 Vec2::reflection(const Line& l) const {
		return *this + (projection(l) - *this) * 2;
	}

	int iSP(const Vec2& a, const Vec2& b, const Vec2& c) {
		int flag = sgn((b - a).cross(c - a));
		if (flag != 0) {
			return flag;
		} else {
			if (sgn((b - a).dot(c - b)) > 0) {
				return 2;
			} else if (sgn((a - b).dot(c - a)) > 0) {
				return -2;
			} else {
				return 0;
			}
		}
	}

	int angle_type(const Vec2& a, const Vec2& b, const Vec2& c) {
		if (int f = sgn((a - b).dot(c - b)); f > 0) {
			return 0;
		} else if (f == 0) {
			return 1;
		} else {
			return 2;
		}
	}

	LD angle(const Vec2& a, const Vec2& b, const Vec2& c) {
		// return acos((a - b).dot(c - b) / (a.distance(b) * c.distance(b)));
		// return abs((a - b).rotation(-(c - b).angle()).angle());
		return (c - b).rotation(-(a - b).angle()).angle();
	}

	LD distance(const Vec2& v1, const Vec2& v2) {
		return hypot(v1.x - v2.x, v1.y - v2.y);
	}
	LD distance(const Vec2& v, const Line& l) {
		return abs(l.vec().cross(v - l.begin) / l.vec().length());
	}
	LD distance(const Vec2& v, const Segment& s) {
		if (sgn(s.vec().dot(v - s.begin)) < 0 || sgn(s.counter_vec().dot(v - s.end)) < 0) {
			return min(v.distance(s.begin), v.distance(s.end));
		} else {
			return Line(s).distance(v);
		}
	}
	LD distance(const Vec2& v, const Circle& c) {
		return max<LD>(0, c.center.distance(v) - c.r);
	}
	LD distance(const Line& l, const Vec2& v) {
		return distance(v, l);
	}
	LD distance(const Line& l1, const Line& l2) {
		return l1.is_parallel(l2) ? l1.distance(l2.begin) : 0;
	}
	LD distance(const Segment& s, const Vec2& v) {
		return distance(v, s);
	}
	LD distance(const Segment& s1, const Segment& s2) {
		if (intersect(s1, s2)) {
			return 0;
		} else {
			return min({distance(s1, s2.begin), distance(s1, s2.end), distance(s1.begin, s2), distance(s1.end, s2)});
		}
	}
	LD distance(const Circle& c, const Vec2& v) {
		return distance(v, c);
	}
	LD distance(const Circle& c1, const Circle& c2) {
		return max<LD>(0, distance(c1.center, c2.center) - (c1.r + c2.r));
	}

	bool intersect(const Vec2& v1, const Vec2& v2) {
		return v1 == v2;
	}
	bool intersect(const Vec2& v, const Line& l) {
		return abs(iSP(v, l.begin, l.end)) != -1;
	}
	bool intersect(const Vec2& v, const Segment& l) {
		return iSP(l.begin, l.end, v) == 0;
	}
	bool intersect(const Vec2& v, const Circle& c) {
		return c.center.distance(v) < c.r + EPS;
	}
	bool intersect(const Vec2& v, const Rect& r) {
		return r.pos <= v && v <= r.bottom_right();
	}
	bool intersect(const Vec2& v, const Polygon& p) {
		LD theta = 0;
		for (size_t i = 0; i < p.size(); ++i) {
			Vec2 next = p[i != p.size() - 1 ? i + 1 : 0];
			if (Segment(p[i], next).intersects(v)) {
				return true;
			}
			theta += angle(p[i], v, next);
		}
		return abs(theta) > 1;
	}
	bool intersect(const Line& l, const Vec2& v) {
		return intersect(v, l);
	}
	bool intersect(const Line& l1, const Line& l2) {
		return !l1.is_parallel(l2);
	}
	bool intersect(const Line& l, const Circle& c) {
		return sgn(distance(c.center, l) - c.r) <= 0;
	}
	bool intersect(const Segment& l, const Vec2& v) {
		return intersect(v, l);
	}
	bool intersect(const Segment& s1, const Segment& s2) {
		return iSP(s1.begin, s1.end, s2.begin) * iSP(s1.begin, s1.end, s2.end) <= 0 &&
		    iSP(s2.begin, s2.end, s1.begin) * iSP(s2.begin, s2.end, s1.end) <= 0;
	}
	bool intersect(const Segment& s, const Circle& c) {
		return sgn(distance(c.center, s) - c.r) <= 0;
	}
	bool intersect(const Circle& c, const Vec2& v) {
		return intersect(v, c);
	}
	bool intersect(const Circle& c, const Line& l) {
		return intersect(l, c);
	}
	bool intersect(const Circle& c, const Segment& s) {
		return intersect(s, c);
	}
	bool intersect(const Circle& c1, const Circle& c2) {
		return sgn(distance(c1.center, c2.center) - (c1.r + c2.r)) <= 0;
	}
	bool intersect(const Circle& c, const Rect& r) {
		return Rect(r.pos - Vec2(0, c.r), r.size + Vec2(0, c.r * 2)).intersects(c.center) ||
		    Rect(r.pos - Vec2(c.r, 0), r.size + Vec2(c.r * 2, 0)).intersects(c.center) || c.intersects(r.top_left()) ||
		    c.intersects(r.top_right()) || c.intersects(r.bottom_left()) || c.intersects(r.bottom_right());
	}
	bool intersect(const Rect& r1, const Rect& r2) {
		return sgn(max(r1.left_x(), r2.left_x()) - min(r1.right_x(), r2.right_x())) <= 0 &&
		    sgn(max(r1.top_y(), r2.top_y()) - min(r1.bottom_y(), r2.bottom_y())) <= 0;
	}
	bool intersect(const Rect& r, const Circle& c) {
		return intersect(c, r);
	}
	bool intersect(const Polygon& p, const Vec2& v) {
		return intersect(v, p);
	}

	bool tangent(const Vec2& v1, const Vec2& v2) {
		return intersect(v1, v2);
	}
	bool tangent(const Vec2& v, const Line& l) {
		return intersect(v, l);
	}
	bool tangent(const Vec2& v, const Segment& l) {
		return intersect(v, l);
	}
	bool tangent(const Vec2& v, const Circle& c) {
		return sgn(distance(v, c.center) - c.r) == 0;
	}
	bool tangent(const Vec2& v, const Rect& r) {
		return r.top().tangent(v) || r.bottom().tangent(v) || r.left().tangent(v) || r.right().tangent(v);
	}
	bool tangent(const Vec2& v, const Polygon& p) {
		for (size_t i = 0; i < p.size(); ++i) {
			if (Segment(p[i], p[(i + 1) % p.size()]).tangent(v)) {
				return true;
			}
		}
		return false;
	}
	bool tangent(const Line& l, const Vec2& v) {
		return tangent(v, l);
	}
	bool tangent(const Segment& l, const Vec2& v) {
		return tangent(v, l);
	}
	bool tangent(const Circle& c, const Vec2& v) {
		return tangent(v, c);
	}
	bool tangent(const Circle& c1, const Circle& c2) {
		LD l1 = c1.center.distance(c2.center), l2 = c1.r, l3 = c2.r;
		return sgn(l1 + l2 + l3 - max({l1, l2, l3}) * 2) == 0;
	}
	bool tangent(const Rect& r, const Vec2& v) {
		return tangent(v, r);
	}
	bool tangent(const Polygon& p, const Vec2& v) {
		return tangent(v, p);
	}

	optional<Vec2> cross_point(const Line& l1, const Line& l2) {
		if (intersect(l1, l2)) {
			// return begin + vec() * abs((l.end - begin).cross(l.vec()) / vec().cross(l.vec()));
			auto [a, b, c] = l1.abc();
			auto [A, B, C] = l2.abc();
			LD d = A * b - a * B;
			return Vec2((B * c - b * C) / d, (a * C - A * c) / d);
		} else {
			return nullopt;
		}
	}
	optional<Vec2> cross_point(const Segment& s1, const Segment& s2) {
		if (intersect(s1, s2)) {
			return cross_point(Line(s1), Line(s2));
		} else {
			return nullopt;
		}
	}

	vector<Vec2> cross_points(const Line& l, const Circle& c) {
		LD dist = distance(l, c.center);
		if (int f = sgn(c.r - dist); f == 1) {
			LD x = sqrt(c.r * c.r - dist * dist);
			Vec2 p = c.center.projection(l);
			return {p + l.vec().normalized() * x, p + l.counter_vec().normalized() * x};
		} else if (f == 0) {
			return {c.center.projection(l)};
		} else {
			return {};
		}
	}
	vector<Vec2> cross_points(const Segment& s, const Circle& c) {
		vector<Vec2> res;
		for (const Vec2& v : cross_points(Line(s), c)) {
			if (v.intersects(s)) {
				res.push_back(v);
			}
		}
		return res;
	}
	vector<Vec2> cross_points(const Circle& c, const Line& l) {
		return cross_points(l, c);
	}
	vector<Vec2> cross_points(const Circle& c, const Segment& s) {
		return cross_points(s, c);
	}
	vector<Vec2> cross_points(const Circle& c1, const Circle& c2) {
		Vec2 vec = (c1.center - c2.center).normalized();  // c2 -> c1
		LD dist = c1.center.distance(c2.center);
		if (sgn(dist - c1.r - c2.r) == 0) {
			return {c2.center + vec * c2.r};
		} else if (sgn(c1.r + dist - c2.r) == 0) {
			return {c1.center + vec * c1.r};
		} else if (sgn(c2.r + dist - c1.r) == 0) {
			return {c2.center + vec.rotate180() * c2.r};
		} else if (intersect(c1, c2)) {
			LD area = Triangle::area(dist, c1.r, c2.r);
			LD y = 2 * area / dist, x = sqrt(c1.r * c1.r - y * y);
			LD r1_s = c1.r * c1.r, r2_s = c2.r * c2.r, dist_s = dist * dist;
			Vec2 h = c1.center + vec * (r2_s < r1_s + dist_s ? -x : x), v2 = vec.rotate90() * y;
			return {h + v2, h - v2};
		} else {
			return {};
		}
	}

	vector<Vec2> tangent_to_circle(const Circle& c, const Vec2& v) {
		LD dist = c.center.distance(v);
		if (sgn(dist - c.r) >= 0) {
			LD x = sqrt(dist * dist - c.r * c.r);
			return Circle(v, x).cross_points(c);
		} else {
			return {};
		}
	}

	vector<Line> common_tangent(const Circle& c1, const Circle& c2) {
		LD dist = distance(c1.center, c2.center);
		Vec2 vec = (c2.center - c1.center).normalized();
		if (sgn(dist - abs(c1.r - c2.r)) < 0) {
			return {};
		} else if (sgn(dist - abs(c1.r - c2.r)) == 0) {  // 内接
			Vec2 p;
			if (c1.r > c2.r) {
				p = c2.center + vec * c2.r;
			} else {
				p = c1.center + vec.rotate180() * c1.r;
			}
			return {Line(p, p + vec.rotate90())};
		} else {
			vector<Line> res;
			if (sgn(c1.r - c2.r) == 0) {
				Line l(c1.center, c2.center);
				res.push_back(l + vec.rotate90() * c1.r);
				res.push_back(l + vec.rotate270() * c1.r);
			} else {
				Vec2 p = c2.center + vec * ((dist * c2.r) / (c1.r - c2.r));
				auto c1_p = tangent_to_circle(c1, p), c2_p = tangent_to_circle(c2, p);
				for (size_t i = 0; i < min(c1_p.size(), c2_p.size()); ++i) {
					res.emplace_back(c1_p[i], c2_p[i]);
				}
			}
			if (int f = sgn(dist - (c1.r + c2.r)); f > 0) {  // 交点を持たない
				Vec2 p = c1.center + vec * ((dist * c1.r) / (c1.r + c2.r));
				auto c1_p = tangent_to_circle(c1, p), c2_p = tangent_to_circle(c2, p);
				for (size_t i = 0; i < min(c1_p.size(), c2_p.size()); ++i) {
					res.emplace_back(c1_p[i], c2_p[i]);
				}
			} else if (f == 0) {  //外接
				Vec2 p = c1.center + vec * c1.r;
				res.emplace_back(p, p + vec.rotate90());
			}
			return res;
		}
	}

	LD area_of_intersection(const Circle& c1, const Circle& c2) {
		if (c1.contains(c2)) {
			return c2.area();
		} else if (c2.contains(c1)) {
			return c1.area();
		} else if (c1.intersects(c2)) {
			LD dist = c1.center.distance(c2.center);
			LD r1_s = c1.r * c1.r, r2_s = c2.r * c2.r, dist_s = dist * dist;
			LD angle1 = acos((r1_s + dist_s - r2_s) / (2 * c1.r * dist));
			LD angle2 = acos((r2_s + dist_s - r1_s) / (2 * c2.r * dist));
			return r1_s * (angle1 - sin(angle1 * 2) / 2) + r2_s * (angle2 - sin(angle2 * 2) / 2);
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
			if (sgn(a.distance(b)) == 0) {
				return 0;
			} else if (bool in_a = a.intersects(c), in_b = b.intersects(c); in_a && in_b) {
				return signed_area(a, b, true);
			} else if (auto points = c.cross_points(Segment(a, b)); points.empty()) {
				return signed_area(a, b, false);
			} else {
				Vec2 p1 = points.front(), p2 = points.back();
				swap(p1, p2);
				return signed_area(p1, p2, true) + signed_area(a, p1, in_a) + signed_area(p2, b, in_b);
			}
		};

		LD area = 0;
		for (size_t i = 0; i < p.size(); ++i) {
			LD res = circle_and_triangle(c, p[i], p[i != p.size() - 1 ? i + 1 : 0]);
			area += res;
		}
		return area;
	}

}  // namespace Geometric
