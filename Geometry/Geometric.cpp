// description : 幾何
constexpr bool Equal(LD a, LD b) {
	return a < b ? b - a < EPS : a - b < EPS;
}
constexpr LD deg_to_rad(LD deg) {
	return deg * PI / 180;
}
constexpr LD rad_to_deg(LD rad) {
	return rad * 180 / PI;
}

struct Vec2;
struct Circle;
struct Rect;
struct Line;
inline LD TriangleArea(LD a, LD b, LD c);
inline LD TriangleArea(const Vec2 &v1, const Vec2 &v2, const Vec2 &v3);
inline LD PolygonArea(vector<Vec2> v);
inline bool IntersectsSegment(const Vec2 &a, const Vec2 &b, const Vec2 &c, const Vec2 &d);

struct Vec2 {
	LD x, y;
	constexpr Vec2() : x(0), y(0) {}
	constexpr Vec2(LD _x, LD _y) : x(_x), y(_y) {}
	Vec2(LD rad) : x(cos(rad)), y(sin(rad)) {}
	constexpr bool operator==(const Vec2 &v) const {
		return Equal(x, v.x) && Equal(y, v.y);
	}
	constexpr bool operator!=(const Vec2 &v) const {
		return !(*this == v);
	}
	constexpr bool operator<(const Vec2 &v) const {
		return x < v.x - EPS && y < v.y - EPS;
	}
	constexpr bool operator<=(const Vec2 &v) const {
		return x < v.x + EPS && y < v.y + EPS;
	}
	constexpr Vec2 operator+() const {
		return *this;
	}
	constexpr Vec2 operator-() const {
		return {-x, -y};
	}
	constexpr Vec2 operator+(const Vec2 &v) const {
		return Vec2(*this) += v;
	}
	constexpr Vec2 operator-(const Vec2 &v) const {
		return Vec2(*this) -= v;
	}
	constexpr Vec2 operator*(const Vec2 &v) const {
		return Vec2(*this) *= v;
	}
	constexpr Vec2 operator/(const Vec2 &v) const {
		return Vec2(*this) /= v;
	}
	constexpr Vec2 operator+(LD n) const {
		return Vec2(*this) += Vec2(n, n);
	}
	constexpr Vec2 operator-(LD n) const {
		return Vec2(*this) -= Vec2(n, n);
	}
	constexpr Vec2 operator*(LD n) const {
		return Vec2(*this) *= Vec2(n, n);
	}
	constexpr Vec2 operator/(LD n) const {
		return Vec2(*this) /= Vec2(n, n);
	}
	constexpr Vec2 &operator+=(const Vec2 &v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	constexpr Vec2 &operator-=(const Vec2 &v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}
	constexpr Vec2 &operator*=(const Vec2 &v) {
		x *= v.x;
		y *= v.y;
		return *this;
	}
	constexpr Vec2 &operator/=(const Vec2 &v) {
		x /= v.x;
		y /= v.y;
		return *this;
	}
	constexpr Vec2 &operator+=(LD n) {
		x += n;
		x += n;
		return *this;
	}
	constexpr Vec2 &operator-=(LD n) {
		x -= n;
		x -= n;
		return *this;
	}
	constexpr Vec2 &operator*=(LD n) {
		x *= n;
		x *= n;
		return *this;
	}
	constexpr Vec2 &operator/=(LD n) {
		x /= n;
		x /= n;
		return *this;
	}
	constexpr LD operator[](size_t i) const {
		return i == 0 ? x : i == 1 ? y : 0;
	}
	LD manhattan(const Vec2 &v) const {
		return std::abs(x - v.x) + std::abs(y - v.y);
	}
	LD dist(const Vec2 &v) const {
		return hypot(x - v.x, y - v.y);
	}
	Vec2 abs(const Vec2 &v) const {
		return {std::abs(x - v.x), std::abs(y - v.y)};
	}
	Vec2 &swap() {
		std::swap(x, y);
		return *this;
	}
	constexpr LD sqr_norm() const {
		return x * x + y * y;
	}
	LD norm() const {
		return sqrt(sqr_norm());
	}
	constexpr Vec2 rotate90() const {
		return {y, -x};
	}
	constexpr Vec2 rotate180() const {
		return {-x, -y};
	}
	constexpr Vec2 rotate270() const {
		return {-y, x};
	}
	friend ostream &operator<<(ostream &os, const Vec2 &v) {
		return os << '(' << v.x << ',' << v.y << ')';
	}
	friend istream &operator>>(istream &is, Vec2 &v) {
		return is >> v.x >> v.y;
	}
};

struct Circle {
	Vec2 center;
	LD r;
	constexpr Circle() : center(), r(0) {}
	constexpr Circle(LD _r) : center(), r(_r) {}
	constexpr Circle(LD _x, LD _y, LD _r) : center(_x, _y), r(_r) {}
	constexpr Circle(const Vec2 &_c, LD _r) : center(_c), r(_r) {}
	constexpr bool operator==(const Circle &c) const {
		return center == c.center && Equal(r, c.r);
	}
	constexpr bool operator!=(const Circle &c) const {
		return !(*this == c);
	}
	constexpr Circle &operator+(const Vec2 &v) const {
		return Circle(*this) += v;
	}
	constexpr Circle &operator-(const Vec2 &v) const {
		return Circle(*this) -= v;
	}
	constexpr Circle &operator+=(const Vec2 &v) {
		center += v;
		return *this;
	}
	constexpr Circle &operator-=(const Vec2 &v) {
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
	LD dist(const Vec2 &p) const {
		return max<LD>(0, center.dist(p) - r);
	}
	LD dist(const Circle &c) const {
		return max<LD>(0, center.dist(c.center) - r - c.r);
	}
	constexpr LD area() const {
		return r * r * PI;
	}
	constexpr LD perimeter() const {
		return 2 * r * PI;
	}
	bool intersects(const Vec2 &v) const {
		return center.dist(v) < r + EPS;
	}
	bool intersects(const Circle &c) const {
		return center.dist(c.center) < r + c.r + EPS;
	}
	bool contains(const Circle &c) const {
		return center.dist(c.center) + c.r < r - EPS;
	}
	bool tangent(const Circle &c) const {
		LD l1 = center.dist(c.center), l2 = r, l3 = c.r;
		return Equal(l1 + l2 + l3, max({l1, l2, l3}) * 2);
	}
	vector<Vec2> intersection(const Circle &c) {
		Vec2 v = center - c.center;
		LD l = v.norm();
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
	friend ostream &operator<<(ostream &os, const Circle &c) {
		return os << '(' << c.center.x << ',' << c.center.y << ',' << c.r << ')';
	}
	friend istream &operator>>(istream &is, Circle &c) {
		return is >> c.center >> c.r;
	}
};

struct Rect {
	Vec2 pos, size;
	constexpr Rect() {}
	constexpr Rect(LD _w, LD _h) : size(_w, _h) {}
	constexpr Rect(const Vec2 &_size) : size(_size) {}
	constexpr Rect(LD _x, LD _y, LD _w, LD _h) : pos(_x, _y), size(_w, _h) {}
	constexpr Rect(const Vec2 &_pos, const Vec2 &_size) : pos(_pos), size(_size) {}
	constexpr bool operator==(const Rect &r) const {
		return pos == r.pos && size == r.size;
	}
	constexpr bool operator!=(const Rect &r) const {
		return !(*this == r);
	}
	constexpr Rect operator+(const Vec2 &v) const {
		return Rect(*this) += v;
	}
	constexpr Rect operator-(const Vec2 &v) const {
		return Rect(*this) -= v;
	}
	constexpr Rect &operator+=(const Vec2 &v) {
		pos += v;
		return *this;
	}
	constexpr Rect &operator-=(const Vec2 &v) {
		pos -= v;
		return *this;
	}
	constexpr Rect &set_center(const Vec2 &_pos) {
		pos = _pos - size / 2;
		return *this;
	}
	constexpr LD left() const {
		return pos.x;
	}
	constexpr LD right() const {
		return pos.x + size.x;
	}
	constexpr LD top() const {
		return pos.y;
	}
	constexpr LD bottom() const {
		return pos.y + size.y;
	}
	constexpr Vec2 top_left() const {
		return pos;
	}
	constexpr Vec2 top_right() const {
		return pos + Vec2(size.x, 0);
	}
	constexpr Vec2 bottom_left() const {
		return pos + Vec2(0, size.y);
	}
	constexpr Vec2 bottom_right() const {
		return pos + size;
	}
	constexpr Vec2 center() const {
		return pos + size / 2;
	}
	constexpr LD area() const {
		return size.x * size.y;
	}
	constexpr LD perimeter() const {
		return (size.x + size.y) * 2;
	}
	constexpr bool intersects(const Vec2 &v) const {
		return pos <= v && v <= bottom_right();
	}
	constexpr bool intersects(const Rect &r) const {
		return max(left(), r.left()) < min(right(), r.right()) + EPS &&
		    max(top(), r.top()) < min(bottom(), r.bottom()) + EPS;
	}
	constexpr bool intersects(const Circle &c) const {
		return Rect(pos - Vec2(0, c.r), size + Vec2(0, c.r * 2)).intersects(c.center) ||
		    Rect(pos - Vec2(c.r, 0), size + Vec2(c.r * 2, 0)).intersects(c.center) || c.intersects(top_left()) ||
		    c.intersects(top_right()) || c.intersects(bottom_left()) || c.intersects(bottom_right());
	}
	constexpr bool contains(const Rect &r) const {
		return top_left() <= r.top_left() && r.bottom_right() <= bottom_right();
	}
	constexpr bool contains(const Circle &c) const {
		return top_left() <= Vec2(c.left_x(), c.top_y()) && Vec2(c.right_x(), c.bottom_y()) <= bottom_right();
	}
	friend ostream &operator<<(ostream &os, const Rect &r) {
		return os << '(' << r.pos << ',' << r.size << ')';
	}
	friend istream &operator>>(istream &is, Rect &r) {
		return is >> r.pos >> r.size;
	}
};

struct Line {
private:
	LD a, b, c;  // ax + by + c = 0
public:
	constexpr Line(LD _a, LD _b, LD _c) : a(_a), b(_b), c(_c) {}
	constexpr Line(LD x1, LD y1, LD x2, LD y2) : a(y2 - y1), b(x1 - x2), c(y2 * (x2 - x1) - x2 * (y2 - y1)) {}
	constexpr Line(const Vec2 &v1, const Vec2 &v2) : Line(v1.x, v1.y, v2.x, v2.y) {}
	constexpr bool operator==(const Line &l) {
		return Equal(a, l.a) && Equal(b, l.b) && Equal(c, l.c);
	}
	constexpr bool operator!=(const Line &l) {
		return !(*this == l);
	}
	constexpr LD get_x(LD y) {
		return (-b * y - c) / a;
	}
	constexpr LD get_y(LD x) {
		return (-a * x - c) / b;
	}
	LD dist(const Vec2 &v) {
		return abs(a * v.x + b * v.y + c) / hypot(a, b);
	}
	friend ostream &operator<<(ostream &os, const Line &l) {
		return os << l.a << "x + " << l.b << "y + " << l.c << " = 0";
	}
	friend istream &operator>>(istream &is, Line &l) {
		LD x1, y1, x2, y2;
		is >> x1 >> y1 >> x2 >> y2;
		l = Line(x1, y1, x2, y2);
		return is;
	}
};

inline LD TriangleArea(LD a, LD b, LD c) {
	LD s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
inline LD TriangleArea(const Vec2 &v1, const Vec2 &v2, const Vec2 &v3) {
	return TriangleArea(v1.dist(v2), v1.dist(v3), v2.dist(v3));
}
inline LD PolygonArea(vector<Vec2> v) {
	v.push_back(v.front());
	LD ans = 0;
	for (size_t i = 0; i < v.size() - 1; ++i) {
		ans += abs(v[i].x * v[i + 1].y - v[i + 1].x * v[i].y);
	}
	return ans / 2;
}
inline bool IntersectsSegment(const Vec2 &a, const Vec2 &b, const Vec2 &c, const Vec2 &d) {
	LD s, t;
	s = (a.x - b.x) * (c.y - a.y) - (a.y - b.y) * (c.x - a.x);
	t = (a.x - b.x) * (d.y - a.y) - (a.y - b.y) * (d.x - a.x);
	if (s * t > 0) return false;
	s = (c.x - d.x) * (a.y - c.y) - (c.y - d.y) * (a.x - c.x);
	t = (c.x - d.x) * (b.y - c.y) - (c.y - d.y) * (b.x - c.x);
	if (s * t > 0) return false;
	return true;
}
