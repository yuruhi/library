// shortcut : Geometric 
// description : 幾何ライブラリ
constexpr bool Equal(ld a, ld b) { return a < b ? b - a < EPS : a - b < EPS; }

struct Vec2 {
	ld x, y;
	constexpr Vec2() :x(0), y(0) {}
	constexpr Vec2(ld _x, ld _y) : x(_x), y(_y) {}
	constexpr bool operator==(const Vec2& v)const { return Equal(x, v.x) && Equal(y, v.y); }
	constexpr bool operator!=(const Vec2& v)const { return !(*this == v); }
	constexpr bool operator<(const Vec2& v)const { return x < v.x - EPS && y < v.y - EPS; }
	constexpr bool operator<=(const Vec2& v)const { return x < v.x + EPS && y < v.y + EPS; }
	constexpr Vec2 operator+()const { return *this; }
	constexpr Vec2 operator-()const { return { -x,-y }; }
	constexpr Vec2 operator+(const Vec2& v)const { return Vec2(*this) += v; }
	constexpr Vec2 operator-(const Vec2& v)const { return Vec2(*this) -= v; }
	constexpr Vec2 operator*(const Vec2& v)const { return Vec2(*this) *= v; }
	constexpr Vec2 operator/(const Vec2& v)const { return Vec2(*this) /= v; }
	constexpr Vec2 operator+(ld n)const { return Vec2(*this) += Vec2(n, n); }
	constexpr Vec2 operator-(ld n)const { return Vec2(*this) -= Vec2(n, n); }
	constexpr Vec2 operator*(ld n)const { return Vec2(*this) *= Vec2(n, n); }
	constexpr Vec2 operator/(ld n)const { return Vec2(*this) /= Vec2(n, n); }
	constexpr Vec2& operator+=(const Vec2& v) { x += v.x; y += v.y; return *this; }
	constexpr Vec2& operator-=(const Vec2& v) { x -= v.x; y -= v.y; return *this; }
	constexpr Vec2& operator*=(const Vec2& v) { x *= v.x; y *= v.y; return *this; }
	constexpr Vec2& operator/=(const Vec2& v) { x /= v.x; y /= v.y; return *this; }
	constexpr Vec2& operator+=(ld n) { x += n; x += n; return *this; }
	constexpr Vec2& operator-=(ld n) { x -= n; x -= n; return *this; }
	constexpr Vec2& operator*=(ld n) { x *= n; x *= n; return *this; }
	constexpr Vec2& operator/=(ld n) { x /= n; x /= n; return *this; }
	constexpr ld operator[](size_t i)const { return i == 0 ? x : i == 1 ? y : 0; }
	ld manhattan(const Vec2& v)const { return std::abs(x - v.x) + std::abs(y - v.y); }
	ld dist(const Vec2& v)const { return hypot(x - v.x, y - v.y); }
	Vec2 abs(const Vec2& v)const { return { std::abs(x - v.x),std::abs(y - v.y) }; }
	Vec2& swap() { std::swap(x, y); return *this; }
	constexpr ld sqr_norm()const { return x * x + y * y; }
	ld norm()const { return sqrt(sqr_norm()); }
	constexpr Vec2 rotate90()const { return { y,-x }; }
	constexpr Vec2 rotate180()const { return { -x,-y }; }
	constexpr Vec2 rotate270()const { return { -y,x }; }
};
inline ostream& operator<<(ostream& os, const Vec2& v) { return os << '(' << v.x << ',' << v.y << ')'; }
inline istream& operator>>(istream& is, Vec2& v) { return is >> v.x >> v.y; }

inline ld TriangleArea(ld a, ld b, ld c) {
	ld s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
inline ld TriangleArea(const Vec2& v1, const Vec2& v2, const Vec2& v3) {
	return TriangleArea(v1.dist(v2), v1.dist(v3), v2.dist(v3));
}
inline ld PolygonArea(vector<Vec2> v) {
	v.push_back(v.front());
	ld ans = 0;
	for (size_t i = 0; i < v.size() - 1; ++i) {
		ans += abs(v[i].x * v[i + 1].y - v[i + 1].x * v[i].y);
	}
	return ans / 2;
}

struct Circle {
	Vec2 center; ld r;
	constexpr Circle() :center(), r(0) {}
	constexpr Circle(ld _r) : center(), r(_r) {}
	constexpr Circle(ld _x, ld _y, ld _r) : center(_x, _y), r(_r) {}
	constexpr Circle(const Vec2& _c, ld _r) : center(_c), r(_r) {}
	constexpr bool operator==(const Circle& c)const { return center == c.center && Equal(r, c.r); }
	constexpr bool operator!=(const Circle& c)const { return !(*this == c); }
	constexpr Circle& operator+(const Vec2& v)const { return Circle(*this) += v; }
	constexpr Circle& operator-(const Vec2& v)const { return Circle(*this) -= v; }
	constexpr Circle& operator+=(const Vec2& v) { center += v; return *this; }
	constexpr Circle& operator-=(const Vec2& v) { center -= v; return *this; }
	constexpr ld top_y()const { return center.y - r; }
	constexpr ld bottom_y()const { return center.y + r; }
	constexpr ld left_x()const { return center.x - r; }
	constexpr ld right_x()const { return center.x + r; }
	constexpr Vec2 top()const { return center - Vec2(0, r); }
	constexpr Vec2 bottom()const { return center + Vec2(0, r); }
	constexpr Vec2 left()const { return center - Vec2(r, 0); }
	constexpr Vec2 right()const { return center + Vec2(r, 0); }
	ld dist(const Vec2& p)const { return max<ld>(0, center.dist(p) - r); }
	ld dist(const Circle& c)const { return max<ld>(0, center.dist(c.center) - r - c.r); }
	constexpr ld area()const { return r * r * PI; }
	constexpr ld perimeter()const { return 2 * r * PI; }
	bool intersects(const Vec2& v)const { return center.dist(v) < r + EPS; }
	bool intersects(const Circle& c)const { return center.dist(c.center) < r + c.r + EPS; }
	bool contains(const Circle& c)const { return center.dist(c.center) + c.r < r - EPS; }
	bool tangent(const Circle& c)const {
		ld l1 = center.dist(c.center), l2 = r, l3 = c.r;
		return Equal(l1 + l2 + l3, max({ l1,l2,l3 }) * 2);
	}
	vector<Vec2> intersection(const Circle& c) {
		Vec2 v = center - c.center;
		ld l = v.norm();
		if (contains(c) || c.contains(*this)) {
			return {};
		} else if (Equal(l, r + c.r)) {
			return { c.center + v * (l / c.r) };
		} else if (Equal(r + l, c.r)) {
			return { c.center + v * (c.r / l) };
		} else if (Equal(c.r + l, r)) {
			return { center + v.rotate180() * (r / l) };
		} else if (intersects(c)) {
			ld area = TriangleArea(l, r, c.r);
			ld y = 2 * area / l, x = sqrt(r * r - y * y);
			Vec2 h = center + v.rotate180() * (x / l);
			Vec2 v2 = v.rotate90() * (y / l);
			return { h + v2,h - v2 };
		} else {
			return {};
		}
	}
};
inline ostream& operator<<(ostream& os, const Circle& c) {
	return os << '(' << c.center.x << ',' << c.center.y << ',' << c.r << ')';
}
inline istream& operator>>(istream& is, Circle& c) { return is >> c.center >> c.r; }

struct Rect {
	Vec2 pos, size;
	constexpr Rect() {}
	constexpr Rect(ld _w, ld _h) :size(_w, _h) {}
	constexpr Rect(const Vec2& _size) : size(_size) {}
	constexpr Rect(ld _x, ld _y, ld _w, ld _h) : pos(_x, _y), size(_w, _h) {}
	constexpr Rect(const Vec2& _pos, const Vec2& _size) : pos(_pos), size(_size) {}
	constexpr bool operator==(const Rect& r)const { return pos == r.pos && size == r.size; }
	constexpr bool operator!=(const Rect& r)const { return pos != r.pos || size != r.size; }
	constexpr Rect operator+(const Vec2& v)const { return Rect(*this) += v; }
	constexpr Rect operator-(const Vec2& v)const { return Rect(*this) -= v; }
	constexpr Rect& operator+=(const Vec2& v) { pos += v; return *this; }
	constexpr Rect& operator-=(const Vec2& v) { pos -= v; return *this; }
	constexpr Rect& set_center(const Vec2& _pos) { pos = _pos - size / 2; return *this; }
	constexpr ld left()const { return pos.x; }
	constexpr ld right()const { return pos.x + size.x; }
	constexpr ld top()const { return pos.y; }
	constexpr ld bottom()const { return pos.y + size.y; }
	constexpr Vec2 top_left()const { return pos; }
	constexpr Vec2 top_right()const { return pos + Vec2(size.x, 0); }
	constexpr Vec2 bottom_left()const { return pos + Vec2(0, size.y); }
	constexpr Vec2 bottom_right()const { return pos + size; }
	constexpr Vec2 center()const { return pos + size / 2; }
	constexpr ld area()const { return size.x * size.y; }
	constexpr ld perimeter()const { return (size.x + size.y) * 2; }
	constexpr bool intersects(const Vec2& v)const { return pos <= v && v <= bottom_right(); }
	constexpr bool intersects(const Rect& r)const {
		return max(left(), r.left()) < min(right(), r.right()) + EPS
			&& max(top(), r.top()) < min(bottom(), r.bottom()) + EPS;
	}
	constexpr bool intersects(const Circle& c)const {
		return Rect(pos - Vec2(0, c.r), size + Vec2(0, c.r * 2)).intersects(c.center)
			|| Rect(pos - Vec2(c.r, 0), size + Vec2(c.r * 2, 0)).intersects(c.center)
			|| c.intersects(top_left()) || c.intersects(top_right())
			|| c.intersects(bottom_left()) || c.intersects(bottom_right());
	}
	constexpr bool contains(const Rect& r)const {
		return top_left() <= r.top_left() && r.bottom_right() <= bottom_right();
	}
	constexpr bool contains(const Circle& c)const {
		return top_left() <= Vec2(c.left_x(), c.top_y()) && Vec2(c.right_x(), c.bottom_y()) <= bottom_right();
	}
};
inline ostream& operator<<(ostream& os, const Rect& r) {
	return os << '(' << r.pos << ',' << r.size << ')';
}
inline istream& operator>>(istream& is, Rect& r) { return is >> r.pos >> r.size; }