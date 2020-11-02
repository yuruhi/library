#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
using namespace std;

namespace Geometric {

	using LD = long double;
	constexpr long double PI = 3.14159265358979323846, EPS = 1e-12;

	constexpr bool Equal(LD a, LD b);
	// a > 0 : +1
	// a = 0 :  0
	// a < 0 : -1
	constexpr int sgn(LD a);
	constexpr LD deg_to_rad(LD deg);
	constexpr LD rad_to_deg(LD rad);

	struct Vec2;
	struct Line;
	struct Segment;
	struct Rect;
	struct Circle;
	struct Polygon;

	// AB から見て BC が左に曲がる   : +1
	// AB から見て BC が右に曲がる   : -1
	// ABC, CBA の順に一直線上に並ぶ : +2
	// ACB, BCA の順に一直線上に並ぶ :  0
	// BAC, CAB の順に一直線上に並ぶ : -2
	int iSP(const Vec2& a, const Vec2& b, const Vec2& c);

	// 角ABC が鋭角 : 0, 直角 : 1, 鈍角 : 2
	int angle_type(const Vec2& a, const Vec2& b, const Vec2& c);

	// 距離
	LD distance(const Vec2& v1, const Vec2& v2);
	LD distance(const Vec2& v, const Line& l);
	LD distance(const Vec2& v, const Segment& s);
	LD distance(const Vec2& v, const Circle& c);
	LD distance(const Line& l, const Vec2& v);
	LD distance(const Line& l1, const Line& l2);
	LD distance(const Segment& s, const Vec2& v);
	LD distance(const Segment& s1, const Segment& s2);
	LD distance(const Circle& c, const Vec2& v);
	LD distance(const Circle& c1, const Circle& c2);

	// 交差判定 （内包しているときも true を返す）
	bool intersect(const Vec2& v1, const Vec2& v2);
	bool intersect(const Vec2& v, const Line& l);
	bool intersect(const Vec2& v, const Segment& l);
	bool intersect(const Vec2& v, const Circle& c);
	bool intersect(const Vec2& v, const Rect& r);
	bool intersect(const Line& l, const Vec2& v);
	bool intersect(const Line& l1, const Line& l2);
	bool intersect(const Line& l, const Circle& c);
	bool intersect(const Segment& l, const Vec2& v);
	bool intersect(const Segment& s1, const Segment& s2);
	bool intersect(const Segment& s, const Circle& c);
	bool intersect(const Circle& c, const Vec2& v);
	bool intersect(const Circle& c, const Line& l);
	bool intersect(const Circle& c, const Segment& s);
	bool intersect(const Circle& c1, const Circle& c2);
	bool intersect(const Circle& c, const Rect& r);
	bool intersect(const Rect& r1, const Rect& r2);
	bool intersect(const Rect& r, const Circle& c);

	// 交点
	optional<Vec2> cross_point(const Line& l1, const Line& l2);
	optional<Vec2> cross_point(const Segment& s1, const Segment& s2);

	vector<Vec2> cross_points(const Line& l, const Circle& c);
	vector<Vec2> cross_points(const Circle& c, const Line& l);
	vector<Vec2> cross_points(const Circle& c1, const Circle& c2);

	// 円の接線
	vector<Vec2> tangent_to_circle(const Circle& c, const Vec2& v);

}  // namespace Geometric
