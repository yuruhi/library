#pragma once
#include "./Vec2.hpp"
#include "./Line.hpp"
#include "./Circle.hpp"
#include "./Rect.hpp"
#include "./Geometric.hpp"

namespace Geometric {

	constexpr bool Equal(LD a, LD b) {
		return a < b ? b - a < EPS : a - b < EPS;
	}
	// a > 0  : +1
	// a == 0 :  0
	// a < 0  : -1
	constexpr int sgn(LD a) {
		return a < -EPS ? -1 : a > EPS ? 1 : 0;
	}

	constexpr LD deg_to_rad(LD deg) {
		return deg * PI / 180;
	}
	constexpr LD rad_to_deg(LD rad) {
		return rad * 180 / PI;
	}

	Vec2 Vec2::projection(const Line& l) {
		return l.begin + l.vec().normalized() * (*this - l.begin).dot(l.vec()) / l.vec().length();
	}
	Vec2 Vec2::reflection(const Line& l) {
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
	bool intersect(const Vec2& v, const Circle& c) {
		return c.center.distance(v) < c.r + EPS;
	}
	bool intersect(const Vec2& v, const Rect& r) {
		return r.pos <= v && v <= r.bottom_right();
	}
	bool intersect(const Line& l1, const Line& l2) {
		return !l1.is_parallel(l2);
	}
	bool intersect(const Line& l, const Circle& c) {
		return sgn(distance(c.center, l) - c.r) <= 0;
	}
	bool intersect(const Segment& s1, const Segment& s2) {
		return iSP(s1.begin, s1.end, s2.begin) * iSP(s1.begin, s1.end, s2.end) <= 0 &&
		    iSP(s2.begin, s2.end, s1.begin) * iSP(s2.begin, s2.end, s1.end) <= 0;
	}
	// 内包しているときも true を返す
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
		return max(r1.left(), r2.left()) < min(r1.right(), r2.right()) + EPS &&
		    max(r1.top(), r2.top()) < min(r1.bottom(), r2.bottom()) + EPS;
	}
	bool intersect(const Rect& r, const Circle& c) {
		return intersect(c, r);
	}

}  // namespace Geometric
