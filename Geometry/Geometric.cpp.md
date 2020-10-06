---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Geometry/Geometric.cpp\"\n#include <iostream>\n#include\
    \ <vector>\n#include <algorithm>\nusing namespace std;\n\nnamespace Geometric\
    \ {\n\n\tusing LD = long double;\n\tconstexpr long double PI = 3.14159265358979323846,\
    \ EPS = 1e-12;\n\n\tconstexpr bool Equal(LD a, LD b) {\n\t\treturn a < b ? b -\
    \ a < EPS : a - b < EPS;\n\t}\n\tconstexpr LD deg_to_rad(LD deg) {\n\t\treturn\
    \ deg * PI / 180;\n\t}\n\tconstexpr LD rad_to_deg(LD rad) {\n\t\treturn rad *\
    \ 180 / PI;\n\t}\n\n\tstruct Vec2;\n\tstruct Circle;\n\tstruct Rect;\n\tstruct\
    \ Line;\n\tinline LD TriangleArea(LD a, LD b, LD c);\n\tinline LD TriangleArea(const\
    \ Vec2& v1, const Vec2& v2, const Vec2& v3);\n\tinline LD PolygonArea(vector<Vec2>\
    \ v);\n\tinline bool IntersectsSegment(const Vec2& a, const Vec2& b, const Vec2&\
    \ c, const Vec2& d);\n\n\tstruct Vec2 {\n\t\tLD x, y;\n\t\tconstexpr Vec2() :\
    \ x(0), y(0) {}\n\t\tconstexpr Vec2(LD _x, LD _y) : x(_x), y(_y) {}\n\t\tVec2(LD\
    \ rad) : x(cos(rad)), y(sin(rad)) {}\n\t\tconstexpr bool operator==(const Vec2&\
    \ v) const {\n\t\t\treturn Equal(x, v.x) && Equal(y, v.y);\n\t\t}\n\t\tconstexpr\
    \ bool operator!=(const Vec2& v) const {\n\t\t\treturn !(*this == v);\n\t\t}\n\
    \t\tconstexpr bool operator<(const Vec2& v) const {\n\t\t\treturn x < v.x - EPS\
    \ && y < v.y - EPS;\n\t\t}\n\t\tconstexpr bool operator<=(const Vec2& v) const\
    \ {\n\t\t\treturn x < v.x + EPS && y < v.y + EPS;\n\t\t}\n\t\tconstexpr Vec2 operator+()\
    \ const {\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2 operator-() const {\n\
    \t\t\treturn {-x, -y};\n\t\t}\n\t\tconstexpr Vec2 operator+(const Vec2& v) const\
    \ {\n\t\t\treturn Vec2(*this) += v;\n\t\t}\n\t\tconstexpr Vec2 operator-(const\
    \ Vec2& v) const {\n\t\t\treturn Vec2(*this) -= v;\n\t\t}\n\t\tconstexpr Vec2\
    \ operator*(const Vec2& v) const {\n\t\t\treturn Vec2(*this) *= v;\n\t\t}\n\t\t\
    constexpr Vec2 operator/(const Vec2& v) const {\n\t\t\treturn Vec2(*this) /= v;\n\
    \t\t}\n\t\tconstexpr Vec2 operator+(LD n) const {\n\t\t\treturn Vec2(*this) +=\
    \ Vec2(n, n);\n\t\t}\n\t\tconstexpr Vec2 operator-(LD n) const {\n\t\t\treturn\
    \ Vec2(*this) -= Vec2(n, n);\n\t\t}\n\t\tconstexpr Vec2 operator*(LD n) const\
    \ {\n\t\t\treturn Vec2(*this) *= Vec2(n, n);\n\t\t}\n\t\tconstexpr Vec2 operator/(LD\
    \ n) const {\n\t\t\treturn Vec2(*this) /= Vec2(n, n);\n\t\t}\n\t\tconstexpr Vec2&\
    \ operator+=(const Vec2& v) {\n\t\t\tx += v.x;\n\t\t\ty += v.y;\n\t\t\treturn\
    \ *this;\n\t\t}\n\t\tconstexpr Vec2& operator-=(const Vec2& v) {\n\t\t\tx -= v.x;\n\
    \t\t\ty -= v.y;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2& operator*=(const\
    \ Vec2& v) {\n\t\t\tx *= v.x;\n\t\t\ty *= v.y;\n\t\t\treturn *this;\n\t\t}\n\t\
    \tconstexpr Vec2& operator/=(const Vec2& v) {\n\t\t\tx /= v.x;\n\t\t\ty /= v.y;\n\
    \t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2& operator+=(LD n) {\n\t\t\tx +=\
    \ n;\n\t\t\tx += n;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2& operator-=(LD\
    \ n) {\n\t\t\tx -= n;\n\t\t\tx -= n;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr\
    \ Vec2& operator*=(LD n) {\n\t\t\tx *= n;\n\t\t\tx *= n;\n\t\t\treturn *this;\n\
    \t\t}\n\t\tconstexpr Vec2& operator/=(LD n) {\n\t\t\tx /= n;\n\t\t\tx /= n;\n\t\
    \t\treturn *this;\n\t\t}\n\t\tconstexpr LD operator[](size_t i) const {\n\t\t\t\
    return i == 0 ? x : i == 1 ? y : 0;\n\t\t}\n\t\tLD manhattan(const Vec2& v) const\
    \ {\n\t\t\treturn std::abs(x - v.x) + std::abs(y - v.y);\n\t\t}\n\t\tLD dist(const\
    \ Vec2& v) const {\n\t\t\treturn hypot(x - v.x, y - v.y);\n\t\t}\n\t\tVec2 abs(const\
    \ Vec2& v) const {\n\t\t\treturn {std::abs(x - v.x), std::abs(y - v.y)};\n\t\t\
    }\n\t\tVec2& swap() {\n\t\t\tstd::swap(x, y);\n\t\t\treturn *this;\n\t\t}\n\t\t\
    constexpr LD sqr_norm() const {\n\t\t\treturn x * x + y * y;\n\t\t}\n\t\tLD norm()\
    \ const {\n\t\t\treturn sqrt(sqr_norm());\n\t\t}\n\t\tconstexpr Vec2 rotate90()\
    \ const {\n\t\t\treturn {y, -x};\n\t\t}\n\t\tconstexpr Vec2 rotate180() const\
    \ {\n\t\t\treturn {-x, -y};\n\t\t}\n\t\tconstexpr Vec2 rotate270() const {\n\t\
    \t\treturn {-y, x};\n\t\t}\n\t\tfriend ostream& operator<<(ostream& os, const\
    \ Vec2& v) {\n\t\t\treturn os << '(' << v.x << ',' << v.y << ')';\n\t\t}\n\t\t\
    friend istream& operator>>(istream& is, Vec2& v) {\n\t\t\treturn is >> v.x >>\
    \ v.y;\n\t\t}\n\t};\n\n\tstruct Circle {\n\t\tVec2 center;\n\t\tLD r;\n\t\tconstexpr\
    \ Circle() : center(), r(0) {}\n\t\tconstexpr Circle(LD _r) : center(), r(_r)\
    \ {}\n\t\tconstexpr Circle(LD _x, LD _y, LD _r) : center(_x, _y), r(_r) {}\n\t\
    \tconstexpr Circle(const Vec2& _c, LD _r) : center(_c), r(_r) {}\n\t\tconstexpr\
    \ bool operator==(const Circle& c) const {\n\t\t\treturn center == c.center &&\
    \ Equal(r, c.r);\n\t\t}\n\t\tconstexpr bool operator!=(const Circle& c) const\
    \ {\n\t\t\treturn !(*this == c);\n\t\t}\n\t\tconstexpr Circle& operator+(const\
    \ Vec2& v) const {\n\t\t\treturn Circle(*this) += v;\n\t\t}\n\t\tconstexpr Circle&\
    \ operator-(const Vec2& v) const {\n\t\t\treturn Circle(*this) -= v;\n\t\t}\n\t\
    \tconstexpr Circle& operator+=(const Vec2& v) {\n\t\t\tcenter += v;\n\t\t\treturn\
    \ *this;\n\t\t}\n\t\tconstexpr Circle& operator-=(const Vec2& v) {\n\t\t\tcenter\
    \ -= v;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr LD top_y() const {\n\t\t\t\
    return center.y - r;\n\t\t}\n\t\tconstexpr LD bottom_y() const {\n\t\t\treturn\
    \ center.y + r;\n\t\t}\n\t\tconstexpr LD left_x() const {\n\t\t\treturn center.x\
    \ - r;\n\t\t}\n\t\tconstexpr LD right_x() const {\n\t\t\treturn center.x + r;\n\
    \t\t}\n\t\tconstexpr Vec2 top() const {\n\t\t\treturn center - Vec2(0, r);\n\t\
    \t}\n\t\tconstexpr Vec2 bottom() const {\n\t\t\treturn center + Vec2(0, r);\n\t\
    \t}\n\t\tconstexpr Vec2 left() const {\n\t\t\treturn center - Vec2(r, 0);\n\t\t\
    }\n\t\tconstexpr Vec2 right() const {\n\t\t\treturn center + Vec2(r, 0);\n\t\t\
    }\n\t\tLD dist(const Vec2& p) const {\n\t\t\treturn max<LD>(0, center.dist(p)\
    \ - r);\n\t\t}\n\t\tLD dist(const Circle& c) const {\n\t\t\treturn max<LD>(0,\
    \ center.dist(c.center) - r - c.r);\n\t\t}\n\t\tconstexpr LD area() const {\n\t\
    \t\treturn r * r * PI;\n\t\t}\n\t\tconstexpr LD perimeter() const {\n\t\t\treturn\
    \ 2 * r * PI;\n\t\t}\n\t\tbool intersects(const Vec2& v) const {\n\t\t\treturn\
    \ center.dist(v) < r + EPS;\n\t\t}\n\t\tbool intersects(const Circle& c) const\
    \ {\n\t\t\treturn center.dist(c.center) < r + c.r + EPS;\n\t\t}\n\t\tbool contains(const\
    \ Circle& c) const {\n\t\t\treturn center.dist(c.center) + c.r < r - EPS;\n\t\t\
    }\n\t\tbool tangent(const Circle& c) const {\n\t\t\tLD l1 = center.dist(c.center),\
    \ l2 = r, l3 = c.r;\n\t\t\treturn Equal(l1 + l2 + l3, max({l1, l2, l3}) * 2);\n\
    \t\t}\n\t\tvector<Vec2> intersection(const Circle& c) {\n\t\t\tVec2 v = center\
    \ - c.center;\n\t\t\tLD l = v.norm();\n\t\t\tif (contains(c) || c.contains(*this))\
    \ {\n\t\t\t\treturn {};\n\t\t\t} else if (Equal(l, r + c.r)) {\n\t\t\t\treturn\
    \ {c.center + v * (l / c.r)};\n\t\t\t} else if (Equal(r + l, c.r)) {\n\t\t\t\t\
    return {c.center + v * (c.r / l)};\n\t\t\t} else if (Equal(c.r + l, r)) {\n\t\t\
    \t\treturn {center + v.rotate180() * (r / l)};\n\t\t\t} else if (intersects(c))\
    \ {\n\t\t\t\tLD area = TriangleArea(l, r, c.r);\n\t\t\t\tLD y = 2 * area / l,\
    \ x = sqrt(r * r - y * y);\n\t\t\t\tVec2 h = center + v.rotate180() * (x / l);\n\
    \t\t\t\tVec2 v2 = v.rotate90() * (y / l);\n\t\t\t\treturn {h + v2, h - v2};\n\t\
    \t\t} else {\n\t\t\t\treturn {};\n\t\t\t}\n\t\t}\n\t\tfriend ostream& operator<<(ostream&\
    \ os, const Circle& c) {\n\t\t\treturn os << '(' << c.center.x << ',' << c.center.y\
    \ << ',' << c.r << ')';\n\t\t}\n\t\tfriend istream& operator>>(istream& is, Circle&\
    \ c) {\n\t\t\treturn is >> c.center >> c.r;\n\t\t}\n\t};\n\n\tstruct Rect {\n\t\
    \tVec2 pos, size;\n\t\tconstexpr Rect() {}\n\t\tconstexpr Rect(LD _w, LD _h) :\
    \ size(_w, _h) {}\n\t\tconstexpr Rect(const Vec2& _size) : size(_size) {}\n\t\t\
    constexpr Rect(LD _x, LD _y, LD _w, LD _h) : pos(_x, _y), size(_w, _h) {}\n\t\t\
    constexpr Rect(const Vec2& _pos, const Vec2& _size) : pos(_pos), size(_size) {}\n\
    \t\tconstexpr bool operator==(const Rect& r) const {\n\t\t\treturn pos == r.pos\
    \ && size == r.size;\n\t\t}\n\t\tconstexpr bool operator!=(const Rect& r) const\
    \ {\n\t\t\treturn !(*this == r);\n\t\t}\n\t\tconstexpr Rect operator+(const Vec2&\
    \ v) const {\n\t\t\treturn Rect(*this) += v;\n\t\t}\n\t\tconstexpr Rect operator-(const\
    \ Vec2& v) const {\n\t\t\treturn Rect(*this) -= v;\n\t\t}\n\t\tconstexpr Rect&\
    \ operator+=(const Vec2& v) {\n\t\t\tpos += v;\n\t\t\treturn *this;\n\t\t}\n\t\
    \tconstexpr Rect& operator-=(const Vec2& v) {\n\t\t\tpos -= v;\n\t\t\treturn *this;\n\
    \t\t}\n\t\tconstexpr Rect& set_center(const Vec2& _pos) {\n\t\t\tpos = _pos -\
    \ size / 2;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr LD left() const {\n\t\t\
    \treturn pos.x;\n\t\t}\n\t\tconstexpr LD right() const {\n\t\t\treturn pos.x +\
    \ size.x;\n\t\t}\n\t\tconstexpr LD top() const {\n\t\t\treturn pos.y;\n\t\t}\n\
    \t\tconstexpr LD bottom() const {\n\t\t\treturn pos.y + size.y;\n\t\t}\n\t\tconstexpr\
    \ Vec2 top_left() const {\n\t\t\treturn pos;\n\t\t}\n\t\tconstexpr Vec2 top_right()\
    \ const {\n\t\t\treturn pos + Vec2(size.x, 0);\n\t\t}\n\t\tconstexpr Vec2 bottom_left()\
    \ const {\n\t\t\treturn pos + Vec2(0, size.y);\n\t\t}\n\t\tconstexpr Vec2 bottom_right()\
    \ const {\n\t\t\treturn pos + size;\n\t\t}\n\t\tconstexpr Vec2 center() const\
    \ {\n\t\t\treturn pos + size / 2;\n\t\t}\n\t\tconstexpr LD area() const {\n\t\t\
    \treturn size.x * size.y;\n\t\t}\n\t\tconstexpr LD perimeter() const {\n\t\t\t\
    return (size.x + size.y) * 2;\n\t\t}\n\t\tconstexpr bool intersects(const Vec2&\
    \ v) const {\n\t\t\treturn pos <= v && v <= bottom_right();\n\t\t}\n\t\tconstexpr\
    \ bool intersects(const Rect& r) const {\n\t\t\treturn max(left(), r.left()) <\
    \ min(right(), r.right()) + EPS &&\n\t\t\t    max(top(), r.top()) < min(bottom(),\
    \ r.bottom()) + EPS;\n\t\t}\n\t\tconstexpr bool intersects(const Circle& c) const\
    \ {\n\t\t\treturn Rect(pos - Vec2(0, c.r), size + Vec2(0, c.r * 2)).intersects(c.center)\
    \ ||\n\t\t\t    Rect(pos - Vec2(c.r, 0), size + Vec2(c.r * 2, 0)).intersects(c.center)\
    \ || c.intersects(top_left()) ||\n\t\t\t    c.intersects(top_right()) || c.intersects(bottom_left())\
    \ || c.intersects(bottom_right());\n\t\t}\n\t\tconstexpr bool contains(const Rect&\
    \ r) const {\n\t\t\treturn top_left() <= r.top_left() && r.bottom_right() <= bottom_right();\n\
    \t\t}\n\t\tconstexpr bool contains(const Circle& c) const {\n\t\t\treturn top_left()\
    \ <= Vec2(c.left_x(), c.top_y()) && Vec2(c.right_x(), c.bottom_y()) <= bottom_right();\n\
    \t\t}\n\t\tfriend ostream& operator<<(ostream& os, const Rect& r) {\n\t\t\treturn\
    \ os << '(' << r.pos << ',' << r.size << ')';\n\t\t}\n\t\tfriend istream& operator>>(istream&\
    \ is, Rect& r) {\n\t\t\treturn is >> r.pos >> r.size;\n\t\t}\n\t};\n\n\tstruct\
    \ Line {\n\tprivate:\n\t\tLD a, b, c;  // ax + by + c = 0\n\tpublic:\n\t\tconstexpr\
    \ Line(LD _a, LD _b, LD _c) : a(_a), b(_b), c(_c) {}\n\t\tconstexpr Line(LD x1,\
    \ LD y1, LD x2, LD y2) : a(y2 - y1), b(x1 - x2), c(y2 * (x2 - x1) - x2 * (y2 -\
    \ y1)) {}\n\t\tconstexpr Line(const Vec2& v1, const Vec2& v2) : Line(v1.x, v1.y,\
    \ v2.x, v2.y) {}\n\t\tconstexpr bool operator==(const Line& l) {\n\t\t\treturn\
    \ Equal(a, l.a) && Equal(b, l.b) && Equal(c, l.c);\n\t\t}\n\t\tconstexpr bool\
    \ operator!=(const Line& l) {\n\t\t\treturn !(*this == l);\n\t\t}\n\t\tconstexpr\
    \ LD get_x(LD y) {\n\t\t\treturn (-b * y - c) / a;\n\t\t}\n\t\tconstexpr LD get_y(LD\
    \ x) {\n\t\t\treturn (-a * x - c) / b;\n\t\t}\n\t\tLD dist(const Vec2& v) {\n\t\
    \t\treturn abs(a * v.x + b * v.y + c) / hypot(a, b);\n\t\t}\n\t\tfriend ostream&\
    \ operator<<(ostream& os, const Line& l) {\n\t\t\treturn os << l.a << \"x + \"\
    \ << l.b << \"y + \" << l.c << \" = 0\";\n\t\t}\n\t\tfriend istream& operator>>(istream&\
    \ is, Line& l) {\n\t\t\tLD x1, y1, x2, y2;\n\t\t\tis >> x1 >> y1 >> x2 >> y2;\n\
    \t\t\tl = Line(x1, y1, x2, y2);\n\t\t\treturn is;\n\t\t}\n\t};\n\n\tinline LD\
    \ TriangleArea(LD a, LD b, LD c) {\n\t\tLD s = (a + b + c) / 2;\n\t\treturn sqrt(s\
    \ * (s - a) * (s - b) * (s - c));\n\t}\n\tinline LD TriangleArea(const Vec2& v1,\
    \ const Vec2& v2, const Vec2& v3) {\n\t\treturn TriangleArea(v1.dist(v2), v1.dist(v3),\
    \ v2.dist(v3));\n\t}\n\tinline LD PolygonArea(vector<Vec2> v) {\n\t\tv.push_back(v.front());\n\
    \t\tLD ans = 0;\n\t\tfor (size_t i = 0; i < v.size() - 1; ++i) {\n\t\t\tans +=\
    \ abs(v[i].x * v[i + 1].y - v[i + 1].x * v[i].y);\n\t\t}\n\t\treturn ans / 2;\n\
    \t}\n\tinline bool IntersectsSegment(const Vec2& a, const Vec2& b, const Vec2&\
    \ c, const Vec2& d) {\n\t\tLD s, t;\n\t\ts = (a.x - b.x) * (c.y - a.y) - (a.y\
    \ - b.y) * (c.x - a.x);\n\t\tt = (a.x - b.x) * (d.y - a.y) - (a.y - b.y) * (d.x\
    \ - a.x);\n\t\tif (s * t > 0) return false;\n\t\ts = (c.x - d.x) * (a.y - c.y)\
    \ - (c.y - d.y) * (a.x - c.x);\n\t\tt = (c.x - d.x) * (b.y - c.y) - (c.y - d.y)\
    \ * (b.x - c.x);\n\t\tif (s * t > 0) return false;\n\t\treturn true;\n\t}\n} \
    \ // namespace Geometric\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\
    using namespace std;\n\nnamespace Geometric {\n\n\tusing LD = long double;\n\t\
    constexpr long double PI = 3.14159265358979323846, EPS = 1e-12;\n\n\tconstexpr\
    \ bool Equal(LD a, LD b) {\n\t\treturn a < b ? b - a < EPS : a - b < EPS;\n\t\
    }\n\tconstexpr LD deg_to_rad(LD deg) {\n\t\treturn deg * PI / 180;\n\t}\n\tconstexpr\
    \ LD rad_to_deg(LD rad) {\n\t\treturn rad * 180 / PI;\n\t}\n\n\tstruct Vec2;\n\
    \tstruct Circle;\n\tstruct Rect;\n\tstruct Line;\n\tinline LD TriangleArea(LD\
    \ a, LD b, LD c);\n\tinline LD TriangleArea(const Vec2& v1, const Vec2& v2, const\
    \ Vec2& v3);\n\tinline LD PolygonArea(vector<Vec2> v);\n\tinline bool IntersectsSegment(const\
    \ Vec2& a, const Vec2& b, const Vec2& c, const Vec2& d);\n\n\tstruct Vec2 {\n\t\
    \tLD x, y;\n\t\tconstexpr Vec2() : x(0), y(0) {}\n\t\tconstexpr Vec2(LD _x, LD\
    \ _y) : x(_x), y(_y) {}\n\t\tVec2(LD rad) : x(cos(rad)), y(sin(rad)) {}\n\t\t\
    constexpr bool operator==(const Vec2& v) const {\n\t\t\treturn Equal(x, v.x) &&\
    \ Equal(y, v.y);\n\t\t}\n\t\tconstexpr bool operator!=(const Vec2& v) const {\n\
    \t\t\treturn !(*this == v);\n\t\t}\n\t\tconstexpr bool operator<(const Vec2& v)\
    \ const {\n\t\t\treturn x < v.x - EPS && y < v.y - EPS;\n\t\t}\n\t\tconstexpr\
    \ bool operator<=(const Vec2& v) const {\n\t\t\treturn x < v.x + EPS && y < v.y\
    \ + EPS;\n\t\t}\n\t\tconstexpr Vec2 operator+() const {\n\t\t\treturn *this;\n\
    \t\t}\n\t\tconstexpr Vec2 operator-() const {\n\t\t\treturn {-x, -y};\n\t\t}\n\
    \t\tconstexpr Vec2 operator+(const Vec2& v) const {\n\t\t\treturn Vec2(*this)\
    \ += v;\n\t\t}\n\t\tconstexpr Vec2 operator-(const Vec2& v) const {\n\t\t\treturn\
    \ Vec2(*this) -= v;\n\t\t}\n\t\tconstexpr Vec2 operator*(const Vec2& v) const\
    \ {\n\t\t\treturn Vec2(*this) *= v;\n\t\t}\n\t\tconstexpr Vec2 operator/(const\
    \ Vec2& v) const {\n\t\t\treturn Vec2(*this) /= v;\n\t\t}\n\t\tconstexpr Vec2\
    \ operator+(LD n) const {\n\t\t\treturn Vec2(*this) += Vec2(n, n);\n\t\t}\n\t\t\
    constexpr Vec2 operator-(LD n) const {\n\t\t\treturn Vec2(*this) -= Vec2(n, n);\n\
    \t\t}\n\t\tconstexpr Vec2 operator*(LD n) const {\n\t\t\treturn Vec2(*this) *=\
    \ Vec2(n, n);\n\t\t}\n\t\tconstexpr Vec2 operator/(LD n) const {\n\t\t\treturn\
    \ Vec2(*this) /= Vec2(n, n);\n\t\t}\n\t\tconstexpr Vec2& operator+=(const Vec2&\
    \ v) {\n\t\t\tx += v.x;\n\t\t\ty += v.y;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr\
    \ Vec2& operator-=(const Vec2& v) {\n\t\t\tx -= v.x;\n\t\t\ty -= v.y;\n\t\t\t\
    return *this;\n\t\t}\n\t\tconstexpr Vec2& operator*=(const Vec2& v) {\n\t\t\t\
    x *= v.x;\n\t\t\ty *= v.y;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2& operator/=(const\
    \ Vec2& v) {\n\t\t\tx /= v.x;\n\t\t\ty /= v.y;\n\t\t\treturn *this;\n\t\t}\n\t\
    \tconstexpr Vec2& operator+=(LD n) {\n\t\t\tx += n;\n\t\t\tx += n;\n\t\t\treturn\
    \ *this;\n\t\t}\n\t\tconstexpr Vec2& operator-=(LD n) {\n\t\t\tx -= n;\n\t\t\t\
    x -= n;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2& operator*=(LD n) {\n\t\
    \t\tx *= n;\n\t\t\tx *= n;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2& operator/=(LD\
    \ n) {\n\t\t\tx /= n;\n\t\t\tx /= n;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr\
    \ LD operator[](size_t i) const {\n\t\t\treturn i == 0 ? x : i == 1 ? y : 0;\n\
    \t\t}\n\t\tLD manhattan(const Vec2& v) const {\n\t\t\treturn std::abs(x - v.x)\
    \ + std::abs(y - v.y);\n\t\t}\n\t\tLD dist(const Vec2& v) const {\n\t\t\treturn\
    \ hypot(x - v.x, y - v.y);\n\t\t}\n\t\tVec2 abs(const Vec2& v) const {\n\t\t\t\
    return {std::abs(x - v.x), std::abs(y - v.y)};\n\t\t}\n\t\tVec2& swap() {\n\t\t\
    \tstd::swap(x, y);\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr LD sqr_norm() const\
    \ {\n\t\t\treturn x * x + y * y;\n\t\t}\n\t\tLD norm() const {\n\t\t\treturn sqrt(sqr_norm());\n\
    \t\t}\n\t\tconstexpr Vec2 rotate90() const {\n\t\t\treturn {y, -x};\n\t\t}\n\t\
    \tconstexpr Vec2 rotate180() const {\n\t\t\treturn {-x, -y};\n\t\t}\n\t\tconstexpr\
    \ Vec2 rotate270() const {\n\t\t\treturn {-y, x};\n\t\t}\n\t\tfriend ostream&\
    \ operator<<(ostream& os, const Vec2& v) {\n\t\t\treturn os << '(' << v.x << ','\
    \ << v.y << ')';\n\t\t}\n\t\tfriend istream& operator>>(istream& is, Vec2& v)\
    \ {\n\t\t\treturn is >> v.x >> v.y;\n\t\t}\n\t};\n\n\tstruct Circle {\n\t\tVec2\
    \ center;\n\t\tLD r;\n\t\tconstexpr Circle() : center(), r(0) {}\n\t\tconstexpr\
    \ Circle(LD _r) : center(), r(_r) {}\n\t\tconstexpr Circle(LD _x, LD _y, LD _r)\
    \ : center(_x, _y), r(_r) {}\n\t\tconstexpr Circle(const Vec2& _c, LD _r) : center(_c),\
    \ r(_r) {}\n\t\tconstexpr bool operator==(const Circle& c) const {\n\t\t\treturn\
    \ center == c.center && Equal(r, c.r);\n\t\t}\n\t\tconstexpr bool operator!=(const\
    \ Circle& c) const {\n\t\t\treturn !(*this == c);\n\t\t}\n\t\tconstexpr Circle&\
    \ operator+(const Vec2& v) const {\n\t\t\treturn Circle(*this) += v;\n\t\t}\n\t\
    \tconstexpr Circle& operator-(const Vec2& v) const {\n\t\t\treturn Circle(*this)\
    \ -= v;\n\t\t}\n\t\tconstexpr Circle& operator+=(const Vec2& v) {\n\t\t\tcenter\
    \ += v;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr Circle& operator-=(const Vec2&\
    \ v) {\n\t\t\tcenter -= v;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr LD top_y()\
    \ const {\n\t\t\treturn center.y - r;\n\t\t}\n\t\tconstexpr LD bottom_y() const\
    \ {\n\t\t\treturn center.y + r;\n\t\t}\n\t\tconstexpr LD left_x() const {\n\t\t\
    \treturn center.x - r;\n\t\t}\n\t\tconstexpr LD right_x() const {\n\t\t\treturn\
    \ center.x + r;\n\t\t}\n\t\tconstexpr Vec2 top() const {\n\t\t\treturn center\
    \ - Vec2(0, r);\n\t\t}\n\t\tconstexpr Vec2 bottom() const {\n\t\t\treturn center\
    \ + Vec2(0, r);\n\t\t}\n\t\tconstexpr Vec2 left() const {\n\t\t\treturn center\
    \ - Vec2(r, 0);\n\t\t}\n\t\tconstexpr Vec2 right() const {\n\t\t\treturn center\
    \ + Vec2(r, 0);\n\t\t}\n\t\tLD dist(const Vec2& p) const {\n\t\t\treturn max<LD>(0,\
    \ center.dist(p) - r);\n\t\t}\n\t\tLD dist(const Circle& c) const {\n\t\t\treturn\
    \ max<LD>(0, center.dist(c.center) - r - c.r);\n\t\t}\n\t\tconstexpr LD area()\
    \ const {\n\t\t\treturn r * r * PI;\n\t\t}\n\t\tconstexpr LD perimeter() const\
    \ {\n\t\t\treturn 2 * r * PI;\n\t\t}\n\t\tbool intersects(const Vec2& v) const\
    \ {\n\t\t\treturn center.dist(v) < r + EPS;\n\t\t}\n\t\tbool intersects(const\
    \ Circle& c) const {\n\t\t\treturn center.dist(c.center) < r + c.r + EPS;\n\t\t\
    }\n\t\tbool contains(const Circle& c) const {\n\t\t\treturn center.dist(c.center)\
    \ + c.r < r - EPS;\n\t\t}\n\t\tbool tangent(const Circle& c) const {\n\t\t\tLD\
    \ l1 = center.dist(c.center), l2 = r, l3 = c.r;\n\t\t\treturn Equal(l1 + l2 +\
    \ l3, max({l1, l2, l3}) * 2);\n\t\t}\n\t\tvector<Vec2> intersection(const Circle&\
    \ c) {\n\t\t\tVec2 v = center - c.center;\n\t\t\tLD l = v.norm();\n\t\t\tif (contains(c)\
    \ || c.contains(*this)) {\n\t\t\t\treturn {};\n\t\t\t} else if (Equal(l, r + c.r))\
    \ {\n\t\t\t\treturn {c.center + v * (l / c.r)};\n\t\t\t} else if (Equal(r + l,\
    \ c.r)) {\n\t\t\t\treturn {c.center + v * (c.r / l)};\n\t\t\t} else if (Equal(c.r\
    \ + l, r)) {\n\t\t\t\treturn {center + v.rotate180() * (r / l)};\n\t\t\t} else\
    \ if (intersects(c)) {\n\t\t\t\tLD area = TriangleArea(l, r, c.r);\n\t\t\t\tLD\
    \ y = 2 * area / l, x = sqrt(r * r - y * y);\n\t\t\t\tVec2 h = center + v.rotate180()\
    \ * (x / l);\n\t\t\t\tVec2 v2 = v.rotate90() * (y / l);\n\t\t\t\treturn {h + v2,\
    \ h - v2};\n\t\t\t} else {\n\t\t\t\treturn {};\n\t\t\t}\n\t\t}\n\t\tfriend ostream&\
    \ operator<<(ostream& os, const Circle& c) {\n\t\t\treturn os << '(' << c.center.x\
    \ << ',' << c.center.y << ',' << c.r << ')';\n\t\t}\n\t\tfriend istream& operator>>(istream&\
    \ is, Circle& c) {\n\t\t\treturn is >> c.center >> c.r;\n\t\t}\n\t};\n\n\tstruct\
    \ Rect {\n\t\tVec2 pos, size;\n\t\tconstexpr Rect() {}\n\t\tconstexpr Rect(LD\
    \ _w, LD _h) : size(_w, _h) {}\n\t\tconstexpr Rect(const Vec2& _size) : size(_size)\
    \ {}\n\t\tconstexpr Rect(LD _x, LD _y, LD _w, LD _h) : pos(_x, _y), size(_w, _h)\
    \ {}\n\t\tconstexpr Rect(const Vec2& _pos, const Vec2& _size) : pos(_pos), size(_size)\
    \ {}\n\t\tconstexpr bool operator==(const Rect& r) const {\n\t\t\treturn pos ==\
    \ r.pos && size == r.size;\n\t\t}\n\t\tconstexpr bool operator!=(const Rect& r)\
    \ const {\n\t\t\treturn !(*this == r);\n\t\t}\n\t\tconstexpr Rect operator+(const\
    \ Vec2& v) const {\n\t\t\treturn Rect(*this) += v;\n\t\t}\n\t\tconstexpr Rect\
    \ operator-(const Vec2& v) const {\n\t\t\treturn Rect(*this) -= v;\n\t\t}\n\t\t\
    constexpr Rect& operator+=(const Vec2& v) {\n\t\t\tpos += v;\n\t\t\treturn *this;\n\
    \t\t}\n\t\tconstexpr Rect& operator-=(const Vec2& v) {\n\t\t\tpos -= v;\n\t\t\t\
    return *this;\n\t\t}\n\t\tconstexpr Rect& set_center(const Vec2& _pos) {\n\t\t\
    \tpos = _pos - size / 2;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr LD left()\
    \ const {\n\t\t\treturn pos.x;\n\t\t}\n\t\tconstexpr LD right() const {\n\t\t\t\
    return pos.x + size.x;\n\t\t}\n\t\tconstexpr LD top() const {\n\t\t\treturn pos.y;\n\
    \t\t}\n\t\tconstexpr LD bottom() const {\n\t\t\treturn pos.y + size.y;\n\t\t}\n\
    \t\tconstexpr Vec2 top_left() const {\n\t\t\treturn pos;\n\t\t}\n\t\tconstexpr\
    \ Vec2 top_right() const {\n\t\t\treturn pos + Vec2(size.x, 0);\n\t\t}\n\t\tconstexpr\
    \ Vec2 bottom_left() const {\n\t\t\treturn pos + Vec2(0, size.y);\n\t\t}\n\t\t\
    constexpr Vec2 bottom_right() const {\n\t\t\treturn pos + size;\n\t\t}\n\t\tconstexpr\
    \ Vec2 center() const {\n\t\t\treturn pos + size / 2;\n\t\t}\n\t\tconstexpr LD\
    \ area() const {\n\t\t\treturn size.x * size.y;\n\t\t}\n\t\tconstexpr LD perimeter()\
    \ const {\n\t\t\treturn (size.x + size.y) * 2;\n\t\t}\n\t\tconstexpr bool intersects(const\
    \ Vec2& v) const {\n\t\t\treturn pos <= v && v <= bottom_right();\n\t\t}\n\t\t\
    constexpr bool intersects(const Rect& r) const {\n\t\t\treturn max(left(), r.left())\
    \ < min(right(), r.right()) + EPS &&\n\t\t\t    max(top(), r.top()) < min(bottom(),\
    \ r.bottom()) + EPS;\n\t\t}\n\t\tconstexpr bool intersects(const Circle& c) const\
    \ {\n\t\t\treturn Rect(pos - Vec2(0, c.r), size + Vec2(0, c.r * 2)).intersects(c.center)\
    \ ||\n\t\t\t    Rect(pos - Vec2(c.r, 0), size + Vec2(c.r * 2, 0)).intersects(c.center)\
    \ || c.intersects(top_left()) ||\n\t\t\t    c.intersects(top_right()) || c.intersects(bottom_left())\
    \ || c.intersects(bottom_right());\n\t\t}\n\t\tconstexpr bool contains(const Rect&\
    \ r) const {\n\t\t\treturn top_left() <= r.top_left() && r.bottom_right() <= bottom_right();\n\
    \t\t}\n\t\tconstexpr bool contains(const Circle& c) const {\n\t\t\treturn top_left()\
    \ <= Vec2(c.left_x(), c.top_y()) && Vec2(c.right_x(), c.bottom_y()) <= bottom_right();\n\
    \t\t}\n\t\tfriend ostream& operator<<(ostream& os, const Rect& r) {\n\t\t\treturn\
    \ os << '(' << r.pos << ',' << r.size << ')';\n\t\t}\n\t\tfriend istream& operator>>(istream&\
    \ is, Rect& r) {\n\t\t\treturn is >> r.pos >> r.size;\n\t\t}\n\t};\n\n\tstruct\
    \ Line {\n\tprivate:\n\t\tLD a, b, c;  // ax + by + c = 0\n\tpublic:\n\t\tconstexpr\
    \ Line(LD _a, LD _b, LD _c) : a(_a), b(_b), c(_c) {}\n\t\tconstexpr Line(LD x1,\
    \ LD y1, LD x2, LD y2) : a(y2 - y1), b(x1 - x2), c(y2 * (x2 - x1) - x2 * (y2 -\
    \ y1)) {}\n\t\tconstexpr Line(const Vec2& v1, const Vec2& v2) : Line(v1.x, v1.y,\
    \ v2.x, v2.y) {}\n\t\tconstexpr bool operator==(const Line& l) {\n\t\t\treturn\
    \ Equal(a, l.a) && Equal(b, l.b) && Equal(c, l.c);\n\t\t}\n\t\tconstexpr bool\
    \ operator!=(const Line& l) {\n\t\t\treturn !(*this == l);\n\t\t}\n\t\tconstexpr\
    \ LD get_x(LD y) {\n\t\t\treturn (-b * y - c) / a;\n\t\t}\n\t\tconstexpr LD get_y(LD\
    \ x) {\n\t\t\treturn (-a * x - c) / b;\n\t\t}\n\t\tLD dist(const Vec2& v) {\n\t\
    \t\treturn abs(a * v.x + b * v.y + c) / hypot(a, b);\n\t\t}\n\t\tfriend ostream&\
    \ operator<<(ostream& os, const Line& l) {\n\t\t\treturn os << l.a << \"x + \"\
    \ << l.b << \"y + \" << l.c << \" = 0\";\n\t\t}\n\t\tfriend istream& operator>>(istream&\
    \ is, Line& l) {\n\t\t\tLD x1, y1, x2, y2;\n\t\t\tis >> x1 >> y1 >> x2 >> y2;\n\
    \t\t\tl = Line(x1, y1, x2, y2);\n\t\t\treturn is;\n\t\t}\n\t};\n\n\tinline LD\
    \ TriangleArea(LD a, LD b, LD c) {\n\t\tLD s = (a + b + c) / 2;\n\t\treturn sqrt(s\
    \ * (s - a) * (s - b) * (s - c));\n\t}\n\tinline LD TriangleArea(const Vec2& v1,\
    \ const Vec2& v2, const Vec2& v3) {\n\t\treturn TriangleArea(v1.dist(v2), v1.dist(v3),\
    \ v2.dist(v3));\n\t}\n\tinline LD PolygonArea(vector<Vec2> v) {\n\t\tv.push_back(v.front());\n\
    \t\tLD ans = 0;\n\t\tfor (size_t i = 0; i < v.size() - 1; ++i) {\n\t\t\tans +=\
    \ abs(v[i].x * v[i + 1].y - v[i + 1].x * v[i].y);\n\t\t}\n\t\treturn ans / 2;\n\
    \t}\n\tinline bool IntersectsSegment(const Vec2& a, const Vec2& b, const Vec2&\
    \ c, const Vec2& d) {\n\t\tLD s, t;\n\t\ts = (a.x - b.x) * (c.y - a.y) - (a.y\
    \ - b.y) * (c.x - a.x);\n\t\tt = (a.x - b.x) * (d.y - a.y) - (a.y - b.y) * (d.x\
    \ - a.x);\n\t\tif (s * t > 0) return false;\n\t\ts = (c.x - d.x) * (a.y - c.y)\
    \ - (c.y - d.y) * (a.x - c.x);\n\t\tt = (c.x - d.x) * (b.y - c.y) - (c.y - d.y)\
    \ * (b.x - c.x);\n\t\tif (s * t > 0) return false;\n\t\treturn true;\n\t}\n} \
    \ // namespace Geometric"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Geometric.cpp
  requiredBy: []
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Geometric.cpp
layout: document
redirect_from:
- /library/Geometry/Geometric.cpp
- /library/Geometry/Geometric.cpp.html
title: Geometry/Geometric.cpp
---
