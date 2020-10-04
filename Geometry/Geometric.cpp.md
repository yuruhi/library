---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Geometry/Geometric.cpp\"\n// description : \u5E7E\u4F55\n\
    constexpr bool Equal(LD a, LD b) {\n\treturn a < b ? b - a < EPS : a - b < EPS;\n\
    }\nconstexpr LD deg_to_rad(LD deg) {\n\treturn deg * PI / 180;\n}\nconstexpr LD\
    \ rad_to_deg(LD rad) {\n\treturn rad * 180 / PI;\n}\n\nstruct Vec2;\nstruct Circle;\n\
    struct Rect;\nstruct Line;\ninline LD TriangleArea(LD a, LD b, LD c);\ninline\
    \ LD TriangleArea(const Vec2& v1, const Vec2& v2, const Vec2& v3);\ninline LD\
    \ PolygonArea(vector<Vec2> v);\ninline bool IntersectsSegment(const Vec2& a, const\
    \ Vec2& b, const Vec2& c, const Vec2& d);\n\nstruct Vec2 {\n\tLD x, y;\n\tconstexpr\
    \ Vec2() : x(0), y(0) {}\n\tconstexpr Vec2(LD _x, LD _y) : x(_x), y(_y) {}\n\t\
    Vec2(LD rad) : x(cos(rad)), y(sin(rad)) {}\n\tconstexpr bool operator==(const\
    \ Vec2& v) const {\n\t\treturn Equal(x, v.x) && Equal(y, v.y);\n\t}\n\tconstexpr\
    \ bool operator!=(const Vec2& v) const {\n\t\treturn !(*this == v);\n\t}\n\tconstexpr\
    \ bool operator<(const Vec2& v) const {\n\t\treturn x < v.x - EPS && y < v.y -\
    \ EPS;\n\t}\n\tconstexpr bool operator<=(const Vec2& v) const {\n\t\treturn x\
    \ < v.x + EPS && y < v.y + EPS;\n\t}\n\tconstexpr Vec2 operator+() const {\n\t\
    \treturn *this;\n\t}\n\tconstexpr Vec2 operator-() const {\n\t\treturn {-x, -y};\n\
    \t}\n\tconstexpr Vec2 operator+(const Vec2& v) const {\n\t\treturn Vec2(*this)\
    \ += v;\n\t}\n\tconstexpr Vec2 operator-(const Vec2& v) const {\n\t\treturn Vec2(*this)\
    \ -= v;\n\t}\n\tconstexpr Vec2 operator*(const Vec2& v) const {\n\t\treturn Vec2(*this)\
    \ *= v;\n\t}\n\tconstexpr Vec2 operator/(const Vec2& v) const {\n\t\treturn Vec2(*this)\
    \ /= v;\n\t}\n\tconstexpr Vec2 operator+(LD n) const {\n\t\treturn Vec2(*this)\
    \ += Vec2(n, n);\n\t}\n\tconstexpr Vec2 operator-(LD n) const {\n\t\treturn Vec2(*this)\
    \ -= Vec2(n, n);\n\t}\n\tconstexpr Vec2 operator*(LD n) const {\n\t\treturn Vec2(*this)\
    \ *= Vec2(n, n);\n\t}\n\tconstexpr Vec2 operator/(LD n) const {\n\t\treturn Vec2(*this)\
    \ /= Vec2(n, n);\n\t}\n\tconstexpr Vec2& operator+=(const Vec2& v) {\n\t\tx +=\
    \ v.x;\n\t\ty += v.y;\n\t\treturn *this;\n\t}\n\tconstexpr Vec2& operator-=(const\
    \ Vec2& v) {\n\t\tx -= v.x;\n\t\ty -= v.y;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ Vec2& operator*=(const Vec2& v) {\n\t\tx *= v.x;\n\t\ty *= v.y;\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr Vec2& operator/=(const Vec2& v) {\n\t\tx /= v.x;\n\t\
    \ty /= v.y;\n\t\treturn *this;\n\t}\n\tconstexpr Vec2& operator+=(LD n) {\n\t\t\
    x += n;\n\t\tx += n;\n\t\treturn *this;\n\t}\n\tconstexpr Vec2& operator-=(LD\
    \ n) {\n\t\tx -= n;\n\t\tx -= n;\n\t\treturn *this;\n\t}\n\tconstexpr Vec2& operator*=(LD\
    \ n) {\n\t\tx *= n;\n\t\tx *= n;\n\t\treturn *this;\n\t}\n\tconstexpr Vec2& operator/=(LD\
    \ n) {\n\t\tx /= n;\n\t\tx /= n;\n\t\treturn *this;\n\t}\n\tconstexpr LD operator[](size_t\
    \ i) const {\n\t\treturn i == 0 ? x : i == 1 ? y : 0;\n\t}\n\tLD manhattan(const\
    \ Vec2& v) const {\n\t\treturn std::abs(x - v.x) + std::abs(y - v.y);\n\t}\n\t\
    LD dist(const Vec2& v) const {\n\t\treturn hypot(x - v.x, y - v.y);\n\t}\n\tVec2\
    \ abs(const Vec2& v) const {\n\t\treturn {std::abs(x - v.x), std::abs(y - v.y)};\n\
    \t}\n\tVec2& swap() {\n\t\tstd::swap(x, y);\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ LD sqr_norm() const {\n\t\treturn x * x + y * y;\n\t}\n\tLD norm() const {\n\
    \t\treturn sqrt(sqr_norm());\n\t}\n\tconstexpr Vec2 rotate90() const {\n\t\treturn\
    \ {y, -x};\n\t}\n\tconstexpr Vec2 rotate180() const {\n\t\treturn {-x, -y};\n\t\
    }\n\tconstexpr Vec2 rotate270() const {\n\t\treturn {-y, x};\n\t}\n\tfriend ostream&\
    \ operator<<(ostream& os, const Vec2& v) {\n\t\treturn os << '(' << v.x << ','\
    \ << v.y << ')';\n\t}\n\tfriend istream& operator>>(istream& is, Vec2& v) {\n\t\
    \treturn is >> v.x >> v.y;\n\t}\n};\n\nstruct Circle {\n\tVec2 center;\n\tLD r;\n\
    \tconstexpr Circle() : center(), r(0) {}\n\tconstexpr Circle(LD _r) : center(),\
    \ r(_r) {}\n\tconstexpr Circle(LD _x, LD _y, LD _r) : center(_x, _y), r(_r) {}\n\
    \tconstexpr Circle(const Vec2& _c, LD _r) : center(_c), r(_r) {}\n\tconstexpr\
    \ bool operator==(const Circle& c) const {\n\t\treturn center == c.center && Equal(r,\
    \ c.r);\n\t}\n\tconstexpr bool operator!=(const Circle& c) const {\n\t\treturn\
    \ !(*this == c);\n\t}\n\tconstexpr Circle& operator+(const Vec2& v) const {\n\t\
    \treturn Circle(*this) += v;\n\t}\n\tconstexpr Circle& operator-(const Vec2& v)\
    \ const {\n\t\treturn Circle(*this) -= v;\n\t}\n\tconstexpr Circle& operator+=(const\
    \ Vec2& v) {\n\t\tcenter += v;\n\t\treturn *this;\n\t}\n\tconstexpr Circle& operator-=(const\
    \ Vec2& v) {\n\t\tcenter -= v;\n\t\treturn *this;\n\t}\n\tconstexpr LD top_y()\
    \ const {\n\t\treturn center.y - r;\n\t}\n\tconstexpr LD bottom_y() const {\n\t\
    \treturn center.y + r;\n\t}\n\tconstexpr LD left_x() const {\n\t\treturn center.x\
    \ - r;\n\t}\n\tconstexpr LD right_x() const {\n\t\treturn center.x + r;\n\t}\n\
    \tconstexpr Vec2 top() const {\n\t\treturn center - Vec2(0, r);\n\t}\n\tconstexpr\
    \ Vec2 bottom() const {\n\t\treturn center + Vec2(0, r);\n\t}\n\tconstexpr Vec2\
    \ left() const {\n\t\treturn center - Vec2(r, 0);\n\t}\n\tconstexpr Vec2 right()\
    \ const {\n\t\treturn center + Vec2(r, 0);\n\t}\n\tLD dist(const Vec2& p) const\
    \ {\n\t\treturn max<LD>(0, center.dist(p) - r);\n\t}\n\tLD dist(const Circle&\
    \ c) const {\n\t\treturn max<LD>(0, center.dist(c.center) - r - c.r);\n\t}\n\t\
    constexpr LD area() const {\n\t\treturn r * r * PI;\n\t}\n\tconstexpr LD perimeter()\
    \ const {\n\t\treturn 2 * r * PI;\n\t}\n\tbool intersects(const Vec2& v) const\
    \ {\n\t\treturn center.dist(v) < r + EPS;\n\t}\n\tbool intersects(const Circle&\
    \ c) const {\n\t\treturn center.dist(c.center) < r + c.r + EPS;\n\t}\n\tbool contains(const\
    \ Circle& c) const {\n\t\treturn center.dist(c.center) + c.r < r - EPS;\n\t}\n\
    \tbool tangent(const Circle& c) const {\n\t\tLD l1 = center.dist(c.center), l2\
    \ = r, l3 = c.r;\n\t\treturn Equal(l1 + l2 + l3, max({l1, l2, l3}) * 2);\n\t}\n\
    \tvector<Vec2> intersection(const Circle& c) {\n\t\tVec2 v = center - c.center;\n\
    \t\tLD l = v.norm();\n\t\tif (contains(c) || c.contains(*this)) {\n\t\t\treturn\
    \ {};\n\t\t} else if (Equal(l, r + c.r)) {\n\t\t\treturn {c.center + v * (l /\
    \ c.r)};\n\t\t} else if (Equal(r + l, c.r)) {\n\t\t\treturn {c.center + v * (c.r\
    \ / l)};\n\t\t} else if (Equal(c.r + l, r)) {\n\t\t\treturn {center + v.rotate180()\
    \ * (r / l)};\n\t\t} else if (intersects(c)) {\n\t\t\tLD area = TriangleArea(l,\
    \ r, c.r);\n\t\t\tLD y = 2 * area / l, x = sqrt(r * r - y * y);\n\t\t\tVec2 h\
    \ = center + v.rotate180() * (x / l);\n\t\t\tVec2 v2 = v.rotate90() * (y / l);\n\
    \t\t\treturn {h + v2, h - v2};\n\t\t} else {\n\t\t\treturn {};\n\t\t}\n\t}\n\t\
    friend ostream& operator<<(ostream& os, const Circle& c) {\n\t\treturn os << '('\
    \ << c.center.x << ',' << c.center.y << ',' << c.r << ')';\n\t}\n\tfriend istream&\
    \ operator>>(istream& is, Circle& c) {\n\t\treturn is >> c.center >> c.r;\n\t\
    }\n};\n\nstruct Rect {\n\tVec2 pos, size;\n\tconstexpr Rect() {}\n\tconstexpr\
    \ Rect(LD _w, LD _h) : size(_w, _h) {}\n\tconstexpr Rect(const Vec2& _size) :\
    \ size(_size) {}\n\tconstexpr Rect(LD _x, LD _y, LD _w, LD _h) : pos(_x, _y),\
    \ size(_w, _h) {}\n\tconstexpr Rect(const Vec2& _pos, const Vec2& _size) : pos(_pos),\
    \ size(_size) {}\n\tconstexpr bool operator==(const Rect& r) const {\n\t\treturn\
    \ pos == r.pos && size == r.size;\n\t}\n\tconstexpr bool operator!=(const Rect&\
    \ r) const {\n\t\treturn !(*this == r);\n\t}\n\tconstexpr Rect operator+(const\
    \ Vec2& v) const {\n\t\treturn Rect(*this) += v;\n\t}\n\tconstexpr Rect operator-(const\
    \ Vec2& v) const {\n\t\treturn Rect(*this) -= v;\n\t}\n\tconstexpr Rect& operator+=(const\
    \ Vec2& v) {\n\t\tpos += v;\n\t\treturn *this;\n\t}\n\tconstexpr Rect& operator-=(const\
    \ Vec2& v) {\n\t\tpos -= v;\n\t\treturn *this;\n\t}\n\tconstexpr Rect& set_center(const\
    \ Vec2& _pos) {\n\t\tpos = _pos - size / 2;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ LD left() const {\n\t\treturn pos.x;\n\t}\n\tconstexpr LD right() const {\n\t\
    \treturn pos.x + size.x;\n\t}\n\tconstexpr LD top() const {\n\t\treturn pos.y;\n\
    \t}\n\tconstexpr LD bottom() const {\n\t\treturn pos.y + size.y;\n\t}\n\tconstexpr\
    \ Vec2 top_left() const {\n\t\treturn pos;\n\t}\n\tconstexpr Vec2 top_right()\
    \ const {\n\t\treturn pos + Vec2(size.x, 0);\n\t}\n\tconstexpr Vec2 bottom_left()\
    \ const {\n\t\treturn pos + Vec2(0, size.y);\n\t}\n\tconstexpr Vec2 bottom_right()\
    \ const {\n\t\treturn pos + size;\n\t}\n\tconstexpr Vec2 center() const {\n\t\t\
    return pos + size / 2;\n\t}\n\tconstexpr LD area() const {\n\t\treturn size.x\
    \ * size.y;\n\t}\n\tconstexpr LD perimeter() const {\n\t\treturn (size.x + size.y)\
    \ * 2;\n\t}\n\tconstexpr bool intersects(const Vec2& v) const {\n\t\treturn pos\
    \ <= v && v <= bottom_right();\n\t}\n\tconstexpr bool intersects(const Rect& r)\
    \ const {\n\t\treturn max(left(), r.left()) < min(right(), r.right()) + EPS &&\n\
    \t\t    max(top(), r.top()) < min(bottom(), r.bottom()) + EPS;\n\t}\n\tconstexpr\
    \ bool intersects(const Circle& c) const {\n\t\treturn Rect(pos - Vec2(0, c.r),\
    \ size + Vec2(0, c.r * 2)).intersects(c.center) ||\n\t\t    Rect(pos - Vec2(c.r,\
    \ 0), size + Vec2(c.r * 2, 0)).intersects(c.center) || c.intersects(top_left())\
    \ ||\n\t\t    c.intersects(top_right()) || c.intersects(bottom_left()) || c.intersects(bottom_right());\n\
    \t}\n\tconstexpr bool contains(const Rect& r) const {\n\t\treturn top_left() <=\
    \ r.top_left() && r.bottom_right() <= bottom_right();\n\t}\n\tconstexpr bool contains(const\
    \ Circle& c) const {\n\t\treturn top_left() <= Vec2(c.left_x(), c.top_y()) &&\
    \ Vec2(c.right_x(), c.bottom_y()) <= bottom_right();\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ os, const Rect& r) {\n\t\treturn os << '(' << r.pos << ',' << r.size << ')';\n\
    \t}\n\tfriend istream& operator>>(istream& is, Rect& r) {\n\t\treturn is >> r.pos\
    \ >> r.size;\n\t}\n};\n\nstruct Line {\nprivate:\n\tLD a, b, c;  // ax + by +\
    \ c = 0\npublic:\n\tconstexpr Line(LD _a, LD _b, LD _c) : a(_a), b(_b), c(_c)\
    \ {}\n\tconstexpr Line(LD x1, LD y1, LD x2, LD y2) : a(y2 - y1), b(x1 - x2), c(y2\
    \ * (x2 - x1) - x2 * (y2 - y1)) {}\n\tconstexpr Line(const Vec2& v1, const Vec2&\
    \ v2) : Line(v1.x, v1.y, v2.x, v2.y) {}\n\tconstexpr bool operator==(const Line&\
    \ l) {\n\t\treturn Equal(a, l.a) && Equal(b, l.b) && Equal(c, l.c);\n\t}\n\tconstexpr\
    \ bool operator!=(const Line& l) {\n\t\treturn !(*this == l);\n\t}\n\tconstexpr\
    \ LD get_x(LD y) {\n\t\treturn (-b * y - c) / a;\n\t}\n\tconstexpr LD get_y(LD\
    \ x) {\n\t\treturn (-a * x - c) / b;\n\t}\n\tLD dist(const Vec2& v) {\n\t\treturn\
    \ abs(a * v.x + b * v.y + c) / hypot(a, b);\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ os, const Line& l) {\n\t\treturn os << l.a << \"x + \" << l.b << \"y + \" <<\
    \ l.c << \" = 0\";\n\t}\n\tfriend istream& operator>>(istream& is, Line& l) {\n\
    \t\tLD x1, y1, x2, y2;\n\t\tis >> x1 >> y1 >> x2 >> y2;\n\t\tl = Line(x1, y1,\
    \ x2, y2);\n\t\treturn is;\n\t}\n};\n\ninline LD TriangleArea(LD a, LD b, LD c)\
    \ {\n\tLD s = (a + b + c) / 2;\n\treturn sqrt(s * (s - a) * (s - b) * (s - c));\n\
    }\ninline LD TriangleArea(const Vec2& v1, const Vec2& v2, const Vec2& v3) {\n\t\
    return TriangleArea(v1.dist(v2), v1.dist(v3), v2.dist(v3));\n}\ninline LD PolygonArea(vector<Vec2>\
    \ v) {\n\tv.push_back(v.front());\n\tLD ans = 0;\n\tfor (size_t i = 0; i < v.size()\
    \ - 1; ++i) {\n\t\tans += abs(v[i].x * v[i + 1].y - v[i + 1].x * v[i].y);\n\t\
    }\n\treturn ans / 2;\n}\ninline bool IntersectsSegment(const Vec2& a, const Vec2&\
    \ b, const Vec2& c, const Vec2& d) {\n\tLD s, t;\n\ts = (a.x - b.x) * (c.y - a.y)\
    \ - (a.y - b.y) * (c.x - a.x);\n\tt = (a.x - b.x) * (d.y - a.y) - (a.y - b.y)\
    \ * (d.x - a.x);\n\tif (s * t > 0) return false;\n\ts = (c.x - d.x) * (a.y - c.y)\
    \ - (c.y - d.y) * (a.x - c.x);\n\tt = (c.x - d.x) * (b.y - c.y) - (c.y - d.y)\
    \ * (b.x - c.x);\n\tif (s * t > 0) return false;\n\treturn true;\n}\n"
  code: "// description : \u5E7E\u4F55\nconstexpr bool Equal(LD a, LD b) {\n\treturn\
    \ a < b ? b - a < EPS : a - b < EPS;\n}\nconstexpr LD deg_to_rad(LD deg) {\n\t\
    return deg * PI / 180;\n}\nconstexpr LD rad_to_deg(LD rad) {\n\treturn rad * 180\
    \ / PI;\n}\n\nstruct Vec2;\nstruct Circle;\nstruct Rect;\nstruct Line;\ninline\
    \ LD TriangleArea(LD a, LD b, LD c);\ninline LD TriangleArea(const Vec2& v1, const\
    \ Vec2& v2, const Vec2& v3);\ninline LD PolygonArea(vector<Vec2> v);\ninline bool\
    \ IntersectsSegment(const Vec2& a, const Vec2& b, const Vec2& c, const Vec2& d);\n\
    \nstruct Vec2 {\n\tLD x, y;\n\tconstexpr Vec2() : x(0), y(0) {}\n\tconstexpr Vec2(LD\
    \ _x, LD _y) : x(_x), y(_y) {}\n\tVec2(LD rad) : x(cos(rad)), y(sin(rad)) {}\n\
    \tconstexpr bool operator==(const Vec2& v) const {\n\t\treturn Equal(x, v.x) &&\
    \ Equal(y, v.y);\n\t}\n\tconstexpr bool operator!=(const Vec2& v) const {\n\t\t\
    return !(*this == v);\n\t}\n\tconstexpr bool operator<(const Vec2& v) const {\n\
    \t\treturn x < v.x - EPS && y < v.y - EPS;\n\t}\n\tconstexpr bool operator<=(const\
    \ Vec2& v) const {\n\t\treturn x < v.x + EPS && y < v.y + EPS;\n\t}\n\tconstexpr\
    \ Vec2 operator+() const {\n\t\treturn *this;\n\t}\n\tconstexpr Vec2 operator-()\
    \ const {\n\t\treturn {-x, -y};\n\t}\n\tconstexpr Vec2 operator+(const Vec2& v)\
    \ const {\n\t\treturn Vec2(*this) += v;\n\t}\n\tconstexpr Vec2 operator-(const\
    \ Vec2& v) const {\n\t\treturn Vec2(*this) -= v;\n\t}\n\tconstexpr Vec2 operator*(const\
    \ Vec2& v) const {\n\t\treturn Vec2(*this) *= v;\n\t}\n\tconstexpr Vec2 operator/(const\
    \ Vec2& v) const {\n\t\treturn Vec2(*this) /= v;\n\t}\n\tconstexpr Vec2 operator+(LD\
    \ n) const {\n\t\treturn Vec2(*this) += Vec2(n, n);\n\t}\n\tconstexpr Vec2 operator-(LD\
    \ n) const {\n\t\treturn Vec2(*this) -= Vec2(n, n);\n\t}\n\tconstexpr Vec2 operator*(LD\
    \ n) const {\n\t\treturn Vec2(*this) *= Vec2(n, n);\n\t}\n\tconstexpr Vec2 operator/(LD\
    \ n) const {\n\t\treturn Vec2(*this) /= Vec2(n, n);\n\t}\n\tconstexpr Vec2& operator+=(const\
    \ Vec2& v) {\n\t\tx += v.x;\n\t\ty += v.y;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ Vec2& operator-=(const Vec2& v) {\n\t\tx -= v.x;\n\t\ty -= v.y;\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr Vec2& operator*=(const Vec2& v) {\n\t\tx *= v.x;\n\t\
    \ty *= v.y;\n\t\treturn *this;\n\t}\n\tconstexpr Vec2& operator/=(const Vec2&\
    \ v) {\n\t\tx /= v.x;\n\t\ty /= v.y;\n\t\treturn *this;\n\t}\n\tconstexpr Vec2&\
    \ operator+=(LD n) {\n\t\tx += n;\n\t\tx += n;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ Vec2& operator-=(LD n) {\n\t\tx -= n;\n\t\tx -= n;\n\t\treturn *this;\n\t}\n\
    \tconstexpr Vec2& operator*=(LD n) {\n\t\tx *= n;\n\t\tx *= n;\n\t\treturn *this;\n\
    \t}\n\tconstexpr Vec2& operator/=(LD n) {\n\t\tx /= n;\n\t\tx /= n;\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr LD operator[](size_t i) const {\n\t\treturn i == 0\
    \ ? x : i == 1 ? y : 0;\n\t}\n\tLD manhattan(const Vec2& v) const {\n\t\treturn\
    \ std::abs(x - v.x) + std::abs(y - v.y);\n\t}\n\tLD dist(const Vec2& v) const\
    \ {\n\t\treturn hypot(x - v.x, y - v.y);\n\t}\n\tVec2 abs(const Vec2& v) const\
    \ {\n\t\treturn {std::abs(x - v.x), std::abs(y - v.y)};\n\t}\n\tVec2& swap() {\n\
    \t\tstd::swap(x, y);\n\t\treturn *this;\n\t}\n\tconstexpr LD sqr_norm() const\
    \ {\n\t\treturn x * x + y * y;\n\t}\n\tLD norm() const {\n\t\treturn sqrt(sqr_norm());\n\
    \t}\n\tconstexpr Vec2 rotate90() const {\n\t\treturn {y, -x};\n\t}\n\tconstexpr\
    \ Vec2 rotate180() const {\n\t\treturn {-x, -y};\n\t}\n\tconstexpr Vec2 rotate270()\
    \ const {\n\t\treturn {-y, x};\n\t}\n\tfriend ostream& operator<<(ostream& os,\
    \ const Vec2& v) {\n\t\treturn os << '(' << v.x << ',' << v.y << ')';\n\t}\n\t\
    friend istream& operator>>(istream& is, Vec2& v) {\n\t\treturn is >> v.x >> v.y;\n\
    \t}\n};\n\nstruct Circle {\n\tVec2 center;\n\tLD r;\n\tconstexpr Circle() : center(),\
    \ r(0) {}\n\tconstexpr Circle(LD _r) : center(), r(_r) {}\n\tconstexpr Circle(LD\
    \ _x, LD _y, LD _r) : center(_x, _y), r(_r) {}\n\tconstexpr Circle(const Vec2&\
    \ _c, LD _r) : center(_c), r(_r) {}\n\tconstexpr bool operator==(const Circle&\
    \ c) const {\n\t\treturn center == c.center && Equal(r, c.r);\n\t}\n\tconstexpr\
    \ bool operator!=(const Circle& c) const {\n\t\treturn !(*this == c);\n\t}\n\t\
    constexpr Circle& operator+(const Vec2& v) const {\n\t\treturn Circle(*this) +=\
    \ v;\n\t}\n\tconstexpr Circle& operator-(const Vec2& v) const {\n\t\treturn Circle(*this)\
    \ -= v;\n\t}\n\tconstexpr Circle& operator+=(const Vec2& v) {\n\t\tcenter += v;\n\
    \t\treturn *this;\n\t}\n\tconstexpr Circle& operator-=(const Vec2& v) {\n\t\t\
    center -= v;\n\t\treturn *this;\n\t}\n\tconstexpr LD top_y() const {\n\t\treturn\
    \ center.y - r;\n\t}\n\tconstexpr LD bottom_y() const {\n\t\treturn center.y +\
    \ r;\n\t}\n\tconstexpr LD left_x() const {\n\t\treturn center.x - r;\n\t}\n\t\
    constexpr LD right_x() const {\n\t\treturn center.x + r;\n\t}\n\tconstexpr Vec2\
    \ top() const {\n\t\treturn center - Vec2(0, r);\n\t}\n\tconstexpr Vec2 bottom()\
    \ const {\n\t\treturn center + Vec2(0, r);\n\t}\n\tconstexpr Vec2 left() const\
    \ {\n\t\treturn center - Vec2(r, 0);\n\t}\n\tconstexpr Vec2 right() const {\n\t\
    \treturn center + Vec2(r, 0);\n\t}\n\tLD dist(const Vec2& p) const {\n\t\treturn\
    \ max<LD>(0, center.dist(p) - r);\n\t}\n\tLD dist(const Circle& c) const {\n\t\
    \treturn max<LD>(0, center.dist(c.center) - r - c.r);\n\t}\n\tconstexpr LD area()\
    \ const {\n\t\treturn r * r * PI;\n\t}\n\tconstexpr LD perimeter() const {\n\t\
    \treturn 2 * r * PI;\n\t}\n\tbool intersects(const Vec2& v) const {\n\t\treturn\
    \ center.dist(v) < r + EPS;\n\t}\n\tbool intersects(const Circle& c) const {\n\
    \t\treturn center.dist(c.center) < r + c.r + EPS;\n\t}\n\tbool contains(const\
    \ Circle& c) const {\n\t\treturn center.dist(c.center) + c.r < r - EPS;\n\t}\n\
    \tbool tangent(const Circle& c) const {\n\t\tLD l1 = center.dist(c.center), l2\
    \ = r, l3 = c.r;\n\t\treturn Equal(l1 + l2 + l3, max({l1, l2, l3}) * 2);\n\t}\n\
    \tvector<Vec2> intersection(const Circle& c) {\n\t\tVec2 v = center - c.center;\n\
    \t\tLD l = v.norm();\n\t\tif (contains(c) || c.contains(*this)) {\n\t\t\treturn\
    \ {};\n\t\t} else if (Equal(l, r + c.r)) {\n\t\t\treturn {c.center + v * (l /\
    \ c.r)};\n\t\t} else if (Equal(r + l, c.r)) {\n\t\t\treturn {c.center + v * (c.r\
    \ / l)};\n\t\t} else if (Equal(c.r + l, r)) {\n\t\t\treturn {center + v.rotate180()\
    \ * (r / l)};\n\t\t} else if (intersects(c)) {\n\t\t\tLD area = TriangleArea(l,\
    \ r, c.r);\n\t\t\tLD y = 2 * area / l, x = sqrt(r * r - y * y);\n\t\t\tVec2 h\
    \ = center + v.rotate180() * (x / l);\n\t\t\tVec2 v2 = v.rotate90() * (y / l);\n\
    \t\t\treturn {h + v2, h - v2};\n\t\t} else {\n\t\t\treturn {};\n\t\t}\n\t}\n\t\
    friend ostream& operator<<(ostream& os, const Circle& c) {\n\t\treturn os << '('\
    \ << c.center.x << ',' << c.center.y << ',' << c.r << ')';\n\t}\n\tfriend istream&\
    \ operator>>(istream& is, Circle& c) {\n\t\treturn is >> c.center >> c.r;\n\t\
    }\n};\n\nstruct Rect {\n\tVec2 pos, size;\n\tconstexpr Rect() {}\n\tconstexpr\
    \ Rect(LD _w, LD _h) : size(_w, _h) {}\n\tconstexpr Rect(const Vec2& _size) :\
    \ size(_size) {}\n\tconstexpr Rect(LD _x, LD _y, LD _w, LD _h) : pos(_x, _y),\
    \ size(_w, _h) {}\n\tconstexpr Rect(const Vec2& _pos, const Vec2& _size) : pos(_pos),\
    \ size(_size) {}\n\tconstexpr bool operator==(const Rect& r) const {\n\t\treturn\
    \ pos == r.pos && size == r.size;\n\t}\n\tconstexpr bool operator!=(const Rect&\
    \ r) const {\n\t\treturn !(*this == r);\n\t}\n\tconstexpr Rect operator+(const\
    \ Vec2& v) const {\n\t\treturn Rect(*this) += v;\n\t}\n\tconstexpr Rect operator-(const\
    \ Vec2& v) const {\n\t\treturn Rect(*this) -= v;\n\t}\n\tconstexpr Rect& operator+=(const\
    \ Vec2& v) {\n\t\tpos += v;\n\t\treturn *this;\n\t}\n\tconstexpr Rect& operator-=(const\
    \ Vec2& v) {\n\t\tpos -= v;\n\t\treturn *this;\n\t}\n\tconstexpr Rect& set_center(const\
    \ Vec2& _pos) {\n\t\tpos = _pos - size / 2;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ LD left() const {\n\t\treturn pos.x;\n\t}\n\tconstexpr LD right() const {\n\t\
    \treturn pos.x + size.x;\n\t}\n\tconstexpr LD top() const {\n\t\treturn pos.y;\n\
    \t}\n\tconstexpr LD bottom() const {\n\t\treturn pos.y + size.y;\n\t}\n\tconstexpr\
    \ Vec2 top_left() const {\n\t\treturn pos;\n\t}\n\tconstexpr Vec2 top_right()\
    \ const {\n\t\treturn pos + Vec2(size.x, 0);\n\t}\n\tconstexpr Vec2 bottom_left()\
    \ const {\n\t\treturn pos + Vec2(0, size.y);\n\t}\n\tconstexpr Vec2 bottom_right()\
    \ const {\n\t\treturn pos + size;\n\t}\n\tconstexpr Vec2 center() const {\n\t\t\
    return pos + size / 2;\n\t}\n\tconstexpr LD area() const {\n\t\treturn size.x\
    \ * size.y;\n\t}\n\tconstexpr LD perimeter() const {\n\t\treturn (size.x + size.y)\
    \ * 2;\n\t}\n\tconstexpr bool intersects(const Vec2& v) const {\n\t\treturn pos\
    \ <= v && v <= bottom_right();\n\t}\n\tconstexpr bool intersects(const Rect& r)\
    \ const {\n\t\treturn max(left(), r.left()) < min(right(), r.right()) + EPS &&\n\
    \t\t    max(top(), r.top()) < min(bottom(), r.bottom()) + EPS;\n\t}\n\tconstexpr\
    \ bool intersects(const Circle& c) const {\n\t\treturn Rect(pos - Vec2(0, c.r),\
    \ size + Vec2(0, c.r * 2)).intersects(c.center) ||\n\t\t    Rect(pos - Vec2(c.r,\
    \ 0), size + Vec2(c.r * 2, 0)).intersects(c.center) || c.intersects(top_left())\
    \ ||\n\t\t    c.intersects(top_right()) || c.intersects(bottom_left()) || c.intersects(bottom_right());\n\
    \t}\n\tconstexpr bool contains(const Rect& r) const {\n\t\treturn top_left() <=\
    \ r.top_left() && r.bottom_right() <= bottom_right();\n\t}\n\tconstexpr bool contains(const\
    \ Circle& c) const {\n\t\treturn top_left() <= Vec2(c.left_x(), c.top_y()) &&\
    \ Vec2(c.right_x(), c.bottom_y()) <= bottom_right();\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ os, const Rect& r) {\n\t\treturn os << '(' << r.pos << ',' << r.size << ')';\n\
    \t}\n\tfriend istream& operator>>(istream& is, Rect& r) {\n\t\treturn is >> r.pos\
    \ >> r.size;\n\t}\n};\n\nstruct Line {\nprivate:\n\tLD a, b, c;  // ax + by +\
    \ c = 0\npublic:\n\tconstexpr Line(LD _a, LD _b, LD _c) : a(_a), b(_b), c(_c)\
    \ {}\n\tconstexpr Line(LD x1, LD y1, LD x2, LD y2) : a(y2 - y1), b(x1 - x2), c(y2\
    \ * (x2 - x1) - x2 * (y2 - y1)) {}\n\tconstexpr Line(const Vec2& v1, const Vec2&\
    \ v2) : Line(v1.x, v1.y, v2.x, v2.y) {}\n\tconstexpr bool operator==(const Line&\
    \ l) {\n\t\treturn Equal(a, l.a) && Equal(b, l.b) && Equal(c, l.c);\n\t}\n\tconstexpr\
    \ bool operator!=(const Line& l) {\n\t\treturn !(*this == l);\n\t}\n\tconstexpr\
    \ LD get_x(LD y) {\n\t\treturn (-b * y - c) / a;\n\t}\n\tconstexpr LD get_y(LD\
    \ x) {\n\t\treturn (-a * x - c) / b;\n\t}\n\tLD dist(const Vec2& v) {\n\t\treturn\
    \ abs(a * v.x + b * v.y + c) / hypot(a, b);\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ os, const Line& l) {\n\t\treturn os << l.a << \"x + \" << l.b << \"y + \" <<\
    \ l.c << \" = 0\";\n\t}\n\tfriend istream& operator>>(istream& is, Line& l) {\n\
    \t\tLD x1, y1, x2, y2;\n\t\tis >> x1 >> y1 >> x2 >> y2;\n\t\tl = Line(x1, y1,\
    \ x2, y2);\n\t\treturn is;\n\t}\n};\n\ninline LD TriangleArea(LD a, LD b, LD c)\
    \ {\n\tLD s = (a + b + c) / 2;\n\treturn sqrt(s * (s - a) * (s - b) * (s - c));\n\
    }\ninline LD TriangleArea(const Vec2& v1, const Vec2& v2, const Vec2& v3) {\n\t\
    return TriangleArea(v1.dist(v2), v1.dist(v3), v2.dist(v3));\n}\ninline LD PolygonArea(vector<Vec2>\
    \ v) {\n\tv.push_back(v.front());\n\tLD ans = 0;\n\tfor (size_t i = 0; i < v.size()\
    \ - 1; ++i) {\n\t\tans += abs(v[i].x * v[i + 1].y - v[i + 1].x * v[i].y);\n\t\
    }\n\treturn ans / 2;\n}\ninline bool IntersectsSegment(const Vec2& a, const Vec2&\
    \ b, const Vec2& c, const Vec2& d) {\n\tLD s, t;\n\ts = (a.x - b.x) * (c.y - a.y)\
    \ - (a.y - b.y) * (c.x - a.x);\n\tt = (a.x - b.x) * (d.y - a.y) - (a.y - b.y)\
    \ * (d.x - a.x);\n\tif (s * t > 0) return false;\n\ts = (c.x - d.x) * (a.y - c.y)\
    \ - (c.y - d.y) * (a.x - c.x);\n\tt = (c.x - d.x) * (b.y - c.y) - (c.y - d.y)\
    \ * (b.x - c.x);\n\tif (s * t > 0) return false;\n\treturn true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Geometric.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Geometric.cpp
layout: document
redirect_from:
- /library/Geometry/Geometric.cpp
- /library/Geometry/Geometric.cpp.html
title: Geometry/Geometric.cpp
---
