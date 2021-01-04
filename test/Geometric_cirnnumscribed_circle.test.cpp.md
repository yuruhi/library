---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry/Circle.hpp
    title: Geometry/Circle.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/Geometric.cpp
    title: Geometry/Geometric.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/Geometric.hpp
    title: Geometry/Geometric.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/Line.hpp
    title: Geometry/Line.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/Polygon.hpp
    title: Geometry/Polygon.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/Rect.hpp
    title: Geometry/Rect.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/Triangle.hpp
    title: Geometry/Triangle.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/Vec2.hpp
    title: Geometry/Vec2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-6
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_C
  bundledCode: "#line 1 \"test/Geometric_cirnnumscribed_circle.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_C\"\
    \n#define ERROR \"1e-6\"\n#line 2 \"Geometry/Geometric.hpp\"\n#include <iostream>\n\
    #include <vector>\n#include <algorithm>\n#include <optional>\nusing namespace\
    \ std;\n\nnamespace Geometric {\n\n\tusing LD = long double;\n\tconstexpr long\
    \ double PI = 3.14159265358979323846, EPS = 1e-12;\n\n\tconstexpr bool Equal(LD\
    \ a, LD b);\n\t// a > 0 : +1\n\t// a = 0 :  0\n\t// a < 0 : -1\n\tconstexpr int\
    \ sgn(LD a);\n\tconstexpr LD deg_to_rad(LD deg);\n\tconstexpr LD rad_to_deg(LD\
    \ rad);\n\n\tstruct Vec2;\n\tstruct Line;\n\tstruct Segment;\n\tstruct Rect;\n\
    \tstruct Circle;\n\tstruct Polygon;\n\n\t// AB \u304B\u3089\u898B\u3066 BC \u304C\
    \u5DE6\u306B\u66F2\u304C\u308B   : +1\n\t// AB \u304B\u3089\u898B\u3066 BC \u304C\
    \u53F3\u306B\u66F2\u304C\u308B   : -1\n\t// ABC, CBA \u306E\u9806\u306B\u4E00\u76F4\
    \u7DDA\u4E0A\u306B\u4E26\u3076 : +2\n\t// ACB, BCA \u306E\u9806\u306B\u4E00\u76F4\
    \u7DDA\u4E0A\u306B\u4E26\u3076 :  0\n\t// BAC, CAB \u306E\u9806\u306B\u4E00\u76F4\
    \u7DDA\u4E0A\u306B\u4E26\u3076 : -2\n\tint iSP(const Vec2& a, const Vec2& b, const\
    \ Vec2& c);\n\n\t// \u2220ABC \u304C\u92ED\u89D2 : 0, \u76F4\u89D2 : 1, \u920D\
    \u89D2 : 2\n\tint angle_type(const Vec2& a, const Vec2& b, const Vec2& c);\n\n\
    \t// \u2220ABC \u306E\u5024 (radian)\n\tLD angle(const Vec2& a, const Vec2& b,\
    \ const Vec2& c);\n\n\t// \u8DDD\u96E2\n\tLD distance(const Vec2& v1, const Vec2&\
    \ v2);\n\tLD distance(const Vec2& v, const Line& l);\n\tLD distance(const Vec2&\
    \ v, const Segment& s);\n\tLD distance(const Vec2& v, const Circle& c);\n\tLD\
    \ distance(const Line& l, const Vec2& v);\n\tLD distance(const Line& l1, const\
    \ Line& l2);\n\tLD distance(const Segment& s, const Vec2& v);\n\tLD distance(const\
    \ Segment& s1, const Segment& s2);\n\tLD distance(const Circle& c, const Vec2&\
    \ v);\n\tLD distance(const Circle& c1, const Circle& c2);\n\n\t// \u4EA4\u5DEE\
    \u5224\u5B9A \uFF08\u5185\u5305\u3057\u3066\u3044\u308B\u3068\u304D\u3082 true\
    \ \u3092\u8FD4\u3059\uFF09\n\tbool intersect(const Vec2& v1, const Vec2& v2);\n\
    \tbool intersect(const Vec2& v, const Line& l);\n\tbool intersect(const Vec2&\
    \ v, const Segment& l);\n\tbool intersect(const Vec2& v, const Circle& c);\n\t\
    bool intersect(const Vec2& v, const Rect& r);\n\tbool intersect(const Vec2& v,\
    \ const Polygon& p);\n\tbool intersect(const Line& l, const Vec2& v);\n\tbool\
    \ intersect(const Line& l1, const Line& l2);\n\tbool intersect(const Line& l,\
    \ const Circle& c);\n\tbool intersect(const Segment& l, const Vec2& v);\n\tbool\
    \ intersect(const Segment& s1, const Segment& s2);\n\tbool intersect(const Segment&\
    \ s, const Circle& c);\n\tbool intersect(const Circle& c, const Vec2& v);\n\t\
    bool intersect(const Circle& c, const Line& l);\n\tbool intersect(const Circle&\
    \ c, const Segment& s);\n\tbool intersect(const Circle& c1, const Circle& c2);\n\
    \tbool intersect(const Circle& c, const Rect& r);\n\tbool intersect(const Rect&\
    \ r1, const Rect& r2);\n\tbool intersect(const Rect& r, const Circle& c);\n\t\
    bool intersect(const Polygon& p, const Vec2& v);\n\n\t// \u63A5\u3059\u308B\u304B\
    \u5224\u5B9A\n\tbool tangent(const Vec2& v1, const Vec2& v2);\n\tbool tangent(const\
    \ Vec2& v, const Line& l);\n\tbool tangent(const Vec2& v, const Segment& l);\n\
    \tbool tangent(const Vec2& v, const Circle& c);\n\tbool tangent(const Vec2& v,\
    \ const Rect& r);\n\tbool tangent(const Vec2& v, const Polygon& p);\n\tbool tangent(const\
    \ Line& l, const Vec2& v);\n\tbool tangent(const Segment& l, const Vec2& v);\n\
    \tbool tangent(const Circle& c, const Vec2& v);\n\tbool tangent(const Circle&\
    \ c1, const Circle& c2);\n\tbool tangent(const Rect& r, const Vec2& v);\n\tbool\
    \ tangent(const Polygon& p, const Vec2& v);\n\n\t// \u4EA4\u70B9\n\toptional<Vec2>\
    \ cross_point(const Line& l1, const Line& l2);\n\toptional<Vec2> cross_point(const\
    \ Segment& s1, const Segment& s2);\n\n\tvector<Vec2> cross_points(const Line&\
    \ l, const Circle& c);\n\tvector<Vec2> cross_points(const Segment& s, const Circle&\
    \ c);\n\tvector<Vec2> cross_points(const Circle& c, const Line& l);\n\tvector<Vec2>\
    \ cross_points(const Circle& c, const Segment& s);\n\tvector<Vec2> cross_points(const\
    \ Circle& c1, const Circle& c2);\n\n\t// \u5186\u306E\u63A5\u7DDA\n\tvector<Vec2>\
    \ tangent_to_circle(const Circle& c, const Vec2& v);\n}  // namespace Geometric\n\
    #line 4 \"Geometry/Vec2.hpp\"\n#include <cmath>\n\nnamespace Geometric {\n\n\t\
    struct Vec2 {\n\t\tLD x, y;\n\t\tstatic constexpr bool compare_x(const Vec2& v1,\
    \ const Vec2& v2) {\n\t\t\treturn v1.x < v2.x;\n\t\t}\n\t\tstatic constexpr bool\
    \ compare_y(const Vec2& v1, const Vec2& v2) {\n\t\t\treturn v1.y < v2.y;\n\t\t\
    }\n\t\tstatic constexpr bool compare_xy(const Vec2& v1, const Vec2& v2) {\n\t\t\
    \treturn make_pair(v1.x, v1.y) < make_pair(v2.x, v2.y);\n\t\t}\n\t\tstatic constexpr\
    \ bool compare_yx(const Vec2& v1, const Vec2& v2) {\n\t\t\treturn make_pair(v1.y,\
    \ v1.x) < make_pair(v2.y, v2.x);\n\t\t}\n\t\tstatic constexpr Vec2 zero() {\n\t\
    \t\treturn Vec2(0, 0);\n\t\t}\n\t\tconstexpr Vec2() : x(0), y(0) {}\n\t\tconstexpr\
    \ Vec2(LD _x, LD _y) : x(_x), y(_y) {}\n\t\tVec2(LD rad) : x(cos(rad)), y(sin(rad))\
    \ {}\n\t\tconstexpr bool operator==(const Vec2& v) const {\n\t\t\treturn Equal(x,\
    \ v.x) && Equal(y, v.y);\n\t\t}\n\t\tconstexpr bool operator!=(const Vec2& v)\
    \ const {\n\t\t\treturn !(*this == v);\n\t\t}\n\t\tconstexpr Vec2 operator+()\
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
    \ {\n\t\t\treturn std::abs(x - v.x) + std::abs(y - v.y);\n\t\t}\n\t\tconstexpr\
    \ LD length_square() const {\n\t\t\treturn dot(*this);\n\t\t}\n\t\tLD length()\
    \ const {\n\t\t\treturn sqrt(length_square());\n\t\t}\n\t\t// \u5185\u7A4D\n\t\
    \tconstexpr LD dot(const Vec2& v) const {\n\t\t\treturn x * v.x + y * v.y;\n\t\
    \t}\n\t\t// \u5916\u7A4D\n\t\tconstexpr LD cross(const Vec2& v) const {\n\t\t\t\
    return x * v.y - y * v.x;\n\t\t}\n\t\t// \u6B63\u898F\u5316\uFF08\u9577\u3055\u3092\
    1\u306B\u3057\u305F\uFF09\u30D9\u30AF\u30C8\u30EB\n\t\tVec2 normalized() const\
    \ {\n\t\t\treturn *this / length();\n\t\t}\n\t\t// \u539F\u70B9\u4E2D\u5FC3\u306B\
    \ rad \u56DE\u8EE2\u3057\u305F\u5EA7\u6A19\n\t\tVec2 rotation(LD rad) const {\n\
    \t\t\tLD c = cos(rad), s = sin(rad);\n\t\t\treturn {x * c - y * s, x * s + y *\
    \ c};\n\t\t}\n\t\t// \u539F\u70B9\u4E2D\u5FC3\u306E\u5186\u4E0A\u306B\u4E57\u3063\
    \u3066\u3044\u308B\u3068\u3057\u305F\u3068\u304D\u306E\u504F\u89D2\n\t\tLD angle()\
    \ const {\n\t\t\treturn atan2(y, x);\n\t\t}\n\t\t// \u6B63\u5C04\u5F71\n\t\tVec2\
    \ projection(const Line& l) const;\n\t\t// \u93E1\u6620\u5909\u63DB\n\t\tVec2\
    \ reflection(const Line& l) const;\n\t\tconstexpr Vec2 rotate90() const {\n\t\t\
    \treturn {y, -x};\n\t\t}\n\t\tconstexpr Vec2 rotate180() const {\n\t\t\treturn\
    \ {-x, -y};\n\t\t}\n\t\tconstexpr Vec2 rotate270() const {\n\t\t\treturn {-y,\
    \ x};\n\t\t}\n\t\tfriend ostream& operator<<(ostream& os, const Vec2& v) {\n\t\
    \t\treturn os << '(' << v.x << \", \" << v.y << ')';\n\t\t}\n\t\tfriend istream&\
    \ operator>>(istream& is, Vec2& v) {\n\t\t\treturn is >> v.x >> v.y;\n\t\t}\n\t\
    };\n\n}  // namespace Geometric\n#line 5 \"Geometry/Line.hpp\"\n#include <utility>\n\
    #include <tuple>\n#line 9 \"Geometry/Line.hpp\"\nusing namespace std;\n\nnamespace\
    \ Geometric {\n\n\tnamespace internal {\n\t\tstruct LineBase {\n\t\tprotected:\n\
    \t\t\tconstexpr LineBase() = default;\n\t\t\tconstexpr LineBase(const Vec2& _begin,\
    \ const Vec2& _end) : begin(_begin), end(_end) {}\n\t\t\tconstexpr LineBase(LD\
    \ begin_x, LD begin_y, LD end_x, LD end_y)\n\t\t\t    : begin(begin_x, begin_y),\
    \ end(end_x, end_y) {}\n\n\t\tpublic:\n\t\t\tVec2 begin, end;\n\t\t\tconstexpr\
    \ LineBase operator+(const Vec2& v) {\n\t\t\t\treturn LineBase(*this) += v;\n\t\
    \t\t}\n\t\t\tconstexpr LineBase operator-(const Vec2& v) {\n\t\t\t\treturn LineBase(*this)\
    \ -= v;\n\t\t\t}\n\t\t\tconstexpr LineBase& operator+=(const Vec2& v) {\n\t\t\t\
    \tbegin += v;\n\t\t\t\tend += v;\n\t\t\t\treturn *this;\n\t\t\t}\n\t\t\tconstexpr\
    \ LineBase& operator-=(const Vec2& v) {\n\t\t\t\tbegin -= v;\n\t\t\t\tend -= v;\n\
    \t\t\t\treturn *this;\n\t\t\t}\n\t\t\tconstexpr Vec2 vec() const {\n\t\t\t\treturn\
    \ end - begin;\n\t\t\t}\n\t\t\tconstexpr Vec2 counter_vec() const {\n\t\t\t\t\
    return begin - end;\n\t\t\t}\n\t\t\t// \u5E73\u884C\u5224\u5B9A\n\t\t\tconstexpr\
    \ bool is_parallel(const LineBase& l) const {\n\t\t\t\treturn sgn(vec().cross(l.vec()))\
    \ == 0;\n\t\t\t}\n\t\t\t// \u76F4\u4EA4\u5224\u5B9A\n\t\t\tconstexpr bool is_orthogonal(const\
    \ LineBase& l) const {\n\t\t\t\treturn sgn(vec().dot(l.vec())) == 0;\n\t\t\t}\n\
    \t\t\tfriend ostream& operator<<(ostream& os, const LineBase& l) {\n\t\t\t\treturn\
    \ os << '(' << l.begin << \", \" << l.end << ')';\n\t\t\t}\n\t\t\tfriend istream&\
    \ operator>>(istream& is, LineBase& l) {\n\t\t\t\treturn is >> l.begin >> l.end;\n\
    \t\t\t}\n\t\t};\n\t}  // namespace internal\n\n\tstruct Line : internal::LineBase\
    \ {\n\t\tconstexpr Line() = default;\n\t\tconstexpr Line(const Vec2& _begin, const\
    \ Vec2& _end) : LineBase(_begin, _end) {}\n\t\tconstexpr Line(LD begin_x, LD begin_y,\
    \ LD end_x, LD end_y) : LineBase(begin_x, begin_y, end_x, end_y) {}\n\t\tconstexpr\
    \ Line(const LineBase& l) : LineBase(l) {}\n\t\t// ax + by + c = 0 \u306E\u5F0F\
    \u306B\u5909\u5F62\u3059\u308B\n\t\ttuple<LD, LD, LD> abc() const {\n\t\t\tif\
    \ (sgn(begin.x - end.x) == 0) {\n\t\t\t\treturn {1, 0, -begin.x};\n\t\t\t} else\
    \ {\n\t\t\t\tLD slope = (end.y - begin.y) / (end.x - begin.x);\n\t\t\t\treturn\
    \ {slope, -1, begin.y - begin.x * slope};\n\t\t\t}\n\t\t}\n\t};\n\n\tstruct Segment\
    \ : internal::LineBase {\n\t\tconstexpr Segment() = default;\n\t\tconstexpr Segment(const\
    \ Vec2& _begin, const Vec2& _end) : LineBase(_begin, _end) {}\n\t\tconstexpr Segment(LD\
    \ begin_x, LD begin_y, LD end_x, LD end_y) : LineBase(begin_x, begin_y, end_x,\
    \ end_y) {}\n\t\tconstexpr Segment(const LineBase& l) : LineBase(l) {}\n\t};\n\
    \n}  // namespace Geometric\n#line 6 \"Geometry/Circle.hpp\"\nusing namespace\
    \ std;\n\nnamespace Geometric {\n\n\tstruct Circle {\n\t\tVec2 center;\n\t\tLD\
    \ r;\n\t\tconstexpr Circle() : center(), r(0) {}\n\t\tconstexpr Circle(LD _r)\
    \ : center(), r(_r) {}\n\t\tconstexpr Circle(LD _x, LD _y, LD _r) : center(_x,\
    \ _y), r(_r) {}\n\t\tconstexpr Circle(const Vec2& _c, LD _r) : center(_c), r(_r)\
    \ {}\n\t\tconstexpr bool operator==(const Circle& c) const {\n\t\t\treturn center\
    \ == c.center && Equal(r, c.r);\n\t\t}\n\t\tconstexpr bool operator!=(const Circle&\
    \ c) const {\n\t\t\treturn !(*this == c);\n\t\t}\n\t\tconstexpr Circle& operator+(const\
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
    }\n\t\tconstexpr LD area() const {\n\t\t\treturn r * r * PI;\n\t\t}\n\t\tconstexpr\
    \ LD perimeter() const {\n\t\t\treturn 2 * r * PI;\n\t\t}\n\t\t// c \u304C this\
    \ \u306B\u542B\u307E\u308C\u308B\uFF08\u4E00\u81F4\u3059\u308B\u3068\u304D\u3082\
    \ true \u3092\u8FD4\u3059\uFF09\n\t\tbool contains(const Circle& c) const {\n\t\
    \t\treturn sgn(distance(center, c.center) + c.r - r) <= 0;\n\t\t}\n\t\tfriend\
    \ ostream& operator<<(ostream& os, const Circle& c) {\n\t\t\treturn os << '('\
    \ << c.center.x << \", \" << c.center.y << \", \" << c.r << ')';\n\t\t}\n\t\t\
    friend istream& operator>>(istream& is, Circle& c) {\n\t\t\treturn is >> c.center\
    \ >> c.r;\n\t\t}\n\t};\n\n}  // namespace Geometric\n#line 7 \"Geometry/Triangle.hpp\"\
    \n#include <cassert>\nusing namespace std;\n\nnamespace Geometric {\n\n\tstruct\
    \ Triangle {\n\t\tVec2 p1, p2, p3;\n\t\tstatic LD area(LD a, LD b, LD c) {\n\t\
    \t\tLD s = (a + b + c) / 2;\n\t\t\treturn sqrt(s * (s - a) * (s - b) * (s - c));\n\
    \t\t}\n\t\tTriangle() = default;\n\t\tTriangle(const Vec2& _p1, const Vec2& _p2,\
    \ const Vec2& _p3)\n\t\t    : p1(_p1), p2(_p2), p3(_p3) {\n\t\t\tassert(abs(iSP(p1,\
    \ p2, p3)) == 1);\n\t\t}\n\t\ttuple<LD, LD, LD> sides() const {\n\t\t\treturn\
    \ {distance(p2, p3), distance(p1, p3), distance(p1, p2)};\n\t\t}\n\t\tLD area()\
    \ const {\n\t\t\treturn abs((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y\
    \ - p3.y)) / 2;\n\t\t}\n\t\t// \u5185\u63A5\u5186\n\t\tCircle incircle() const\
    \ {\n\t\t\tauto [l1, l2, l3] = sides();\n\t\t\tLD s = l1 + l2 + l3;\n\t\t\tLD\
    \ x = (p1.x * l1 + p2.x * l2 + p3.x * l3) / s;\n\t\t\tLD y = (p1.y * l1 + p2.y\
    \ * l2 + p3.y * l3) / s;\n\t\t\ts /= 2;\n\t\t\tLD r = sqrt((s - l1) * (s - l2)\
    \ * (s - l3) / s);\n\t\t\treturn Circle(x, y, r);\n\t\t}\n\t\t// \u5916\u63A5\u5186\
    \n\t\tCircle cirnumscribed_circle() const {\n\t\t\tLine l1((p1 + p2) / 2, (p1\
    \ + p2) / 2 + (p1 - p2).rotate270());\n\t\t\tLine l2((p1 + p3) / 2, (p1 + p3)\
    \ / 2 + (p1 - p3).rotate270());\n\t\t\tVec2 center = *cross_point(l1, l2);\n\t\
    \t\treturn Circle(center, distance(center, p1));\n\t\t}\n\t\tfriend ostream& operator<<(ostream&\
    \ os, const Triangle& t) {\n\t\t\treturn os << '(' << t.p1 << \", \" << t.p2 <<\
    \ \", \" << t.p3 << ')';\n\t\t}\n\t\tfriend istream& operator>>(istream& is, Triangle&\
    \ t) {\n\t\t\treturn is >> t.p1 >> t.p2 >> t.p3;\n\t\t}\n\t};\n\n}  // namespace\
    \ Geometric\n#line 6 \"Geometry/Rect.hpp\"\nusing namespace std;\n\nnamespace\
    \ Geometric {\n\n\tstruct Rect {\n\t\tVec2 pos, size;\n\t\tconstexpr Rect() {}\n\
    \t\tconstexpr Rect(LD _w, LD _h) : size(_w, _h) {}\n\t\tconstexpr Rect(const Vec2&\
    \ _size) : size(_size) {}\n\t\tconstexpr Rect(LD _x, LD _y, LD _w, LD _h) : pos(_x,\
    \ _y), size(_w, _h) {}\n\t\tconstexpr Rect(const Vec2& _pos, const Vec2& _size)\
    \ : pos(_pos), size(_size) {}\n\t\tconstexpr bool operator==(const Rect& r) const\
    \ {\n\t\t\treturn pos == r.pos && size == r.size;\n\t\t}\n\t\tconstexpr bool operator!=(const\
    \ Rect& r) const {\n\t\t\treturn !(*this == r);\n\t\t}\n\t\tconstexpr Rect operator+(const\
    \ Vec2& v) const {\n\t\t\treturn Rect(*this) += v;\n\t\t}\n\t\tconstexpr Rect\
    \ operator-(const Vec2& v) const {\n\t\t\treturn Rect(*this) -= v;\n\t\t}\n\t\t\
    constexpr Rect& operator+=(const Vec2& v) {\n\t\t\tpos += v;\n\t\t\treturn *this;\n\
    \t\t}\n\t\tconstexpr Rect& operator-=(const Vec2& v) {\n\t\t\tpos -= v;\n\t\t\t\
    return *this;\n\t\t}\n\t\tconstexpr Rect& set_center(const Vec2& _pos) {\n\t\t\
    \tpos = _pos - size / 2;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr LD left_x()\
    \ const {\n\t\t\treturn pos.x;\n\t\t}\n\t\tconstexpr LD right_x() const {\n\t\t\
    \treturn pos.x + size.x;\n\t\t}\n\t\tconstexpr LD top_y() const {\n\t\t\treturn\
    \ pos.y;\n\t\t}\n\t\tconstexpr LD bottom_y() const {\n\t\t\treturn pos.y + size.y;\n\
    \t\t}\n\t\tconstexpr Vec2 top_left() const {\n\t\t\treturn pos;\n\t\t}\n\t\tconstexpr\
    \ Vec2 top_right() const {\n\t\t\treturn pos + Vec2(size.x, 0);\n\t\t}\n\t\tconstexpr\
    \ Vec2 bottom_left() const {\n\t\t\treturn pos + Vec2(0, size.y);\n\t\t}\n\t\t\
    constexpr Vec2 bottom_right() const {\n\t\t\treturn pos + size;\n\t\t}\n\t\tconstexpr\
    \ Segment top() const {\n\t\t\treturn Segment(top_left(), top_right());\n\t\t\
    }\n\t\tconstexpr Segment bottom() const {\n\t\t\treturn Segment(bottom_left(),\
    \ bottom_right());\n\t\t}\n\t\tconstexpr Segment left() const {\n\t\t\treturn\
    \ Segment(top_left(), bottom_left());\n\t\t}\n\t\tconstexpr Segment right() const\
    \ {\n\t\t\treturn Segment(top_right(), bottom_right());\n\t\t}\n\t\tconstexpr\
    \ Vec2 center() const {\n\t\t\treturn pos + size / 2;\n\t\t}\n\t\tconstexpr LD\
    \ area() const {\n\t\t\treturn size.x * size.y;\n\t\t}\n\t\tconstexpr LD perimeter()\
    \ const {\n\t\t\treturn (size.x + size.y) * 2;\n\t\t}\n\t\tconstexpr bool contains(const\
    \ Rect& r) const {\n\t\t\treturn sgn(left_x() - r.left_x()) <= 0 && sgn(r.right_x()\
    \ - right_x()) <= 0 &&\n\t\t\t    sgn(top_y() - r.top_y()) <= 0 && sgn(r.bottom_y()\
    \ - bottom_y()) <= 0;\n\t\t}\n\t\tconstexpr bool contains(const Circle& c) const\
    \ {\n\t\t\treturn sgn(left_x() - c.left_x()) <= 0 && sgn(c.right_x() - right_x())\
    \ <= 0 &&\n\t\t\t    sgn(top_y() - c.top_y()) <= 0 && sgn(c.bottom_y() - bottom_y())\
    \ <= 0;\n\t\t}\n\t\tfriend ostream& operator<<(ostream& os, const Rect& r) {\n\
    \t\t\treturn os << '(' << r.pos << ',' << r.size << ')';\n\t\t}\n\t\tfriend istream&\
    \ operator>>(istream& is, Rect& r) {\n\t\t\treturn is >> r.pos >> r.size;\n\t\t\
    }\n\t};\n\n}  // namespace Geometric\n#line 10 \"Geometry/Polygon.hpp\"\nusing\
    \ namespace std;\n\nnamespace Geometric {\n\n\tstruct Polygon : vector<Vec2> {\n\
    \tpublic:\n\t\tPolygon() = default;\n\t\tPolygon(int n) : vector<Vec2>(n) {}\n\
    \t\tPolygon(const vector<Vec2>& _p) : vector<Vec2>(_p) {}\n\t\tLD area() const\
    \ {\n\t\t\tLD ans = 0;\n\t\t\tfor (size_t i = 0; i < size(); ++i) {\n\t\t\t\t\
    size_t next = i != size() - 1 ? i + 1 : 0;\n\t\t\t\tans += at(i).cross(at(next));\n\
    \t\t\t}\n\t\t\treturn abs(ans) / 2;\n\t\t}\n\t\t// \u51F8\u6027\u5224\u5B9A\uFF08\
    \u53CD\u6642\u8A08\u56DE\u308A\uFF09\n\t\tbool is_convex() const {\n\t\t\tif (size()\
    \ < 3) {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t\tfor (size_t i = 0; i < size();\
    \ ++i) {\n\t\t\t\tsize_t prev = i != 0 ? i - 1 : size() - 1;\n\t\t\t\tsize_t next\
    \ = i != size() - 1 ? i + 1 : 0;\n\t\t\t\tif (iSP(at(prev), at(i), at(next)) ==\
    \ -1) {\n\t\t\t\t\treturn false;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn true;\n\t\t\
    }\n\t\t// \u51F8\u5305\uFF08\u53CD\u6642\u8A08\u56DE\u308A\uFF09\n\t\tPolygon\
    \ convex_hull() const {\n\t\t\tvector<Vec2> ps = *this;\n\t\t\tsort(ps.begin(),\
    \ ps.end(), Vec2::compare_xy);\n\t\t\tint n = ps.size(), k = 0;\n\t\t\tPolygon\
    \ result(2 * n);\n\t\t\tfor (int i = 0; i < n; result[k++] = ps[i++]) {\n\t\t\t\
    \twhile (k >= 2 && iSP(result[k - 2], result[k - 1], ps[i]) <= 0) {\n\t\t\t\t\t\
    --k;\n\t\t\t\t}\n\t\t\t}\n\t\t\tfor (int i = n - 2, t = k + 1; i >= 0; result[k++]\
    \ = ps[i--]) {\n\t\t\t\twhile (k >= t && iSP(result[k - 2], result[k - 1], ps[i])\
    \ <= 0) {\n\t\t\t\t\t--k;\n\t\t\t\t}\n\t\t\t}\n\t\t\tresult.resize(k - 1);\n\t\
    \t\treturn result;\n\t\t}\n\t\t// \u51F8\u5305\uFF08\u4E00\u76F4\u7DDA\u4E0A\u306E\
    3\u70B9\u3092\u542B\u3081\u306A\u3044\u3001\u53CD\u6642\u8A08\u56DE\u308A\uFF09\
    \n\t\tPolygon convex_hull_no_collinear() const {\n\t\t\tvector<Vec2> ps = *this;\n\
    \t\t\tsort(ps.begin(), ps.end(), Vec2::compare_xy);\n\t\t\tint n = ps.size(),\
    \ k = 0;\n\t\t\tPolygon result(2 * n);\n\t\t\tfor (int i = 0; i < n; result[k++]\
    \ = ps[i++]) {\n\t\t\t\twhile (k >= 2 && iSP(result[k - 2], result[k - 1], ps[i])\
    \ != -1) {\n\t\t\t\t\t--k;\n\t\t\t\t}\n\t\t\t}\n\t\t\tfor (int i = n - 2, t =\
    \ k + 1; i >= 0; result[k++] = ps[i--]) {\n\t\t\t\twhile (k >= t && iSP(result[k\
    \ - 2], result[k - 1], ps[i]) != -1) {\n\t\t\t\t\t--k;\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\tresult.resize(k - 1);\n\t\t\treturn result;\n\t\t}\n\t\t// \u76F4\u5F84\n\t\
    \ttuple<LD, size_t, size_t> diameter() const {\n\t\t\tsize_t i_start = 0, j_start\
    \ = 0;\n\t\t\tfor (size_t i = 1; i < size(); ++i) {\n\t\t\t\tif (at(i).y > at(i_start).y)\
    \ i_start = i;\n\t\t\t\tif (at(i).y < at(j_start).y) j_start = i;\n\t\t\t}\n\t\
    \t\tLD max_dist = (at(i_start) - at(j_start)).length();\n\n\t\t\tauto diff = [&](int\
    \ i) {\n\t\t\t\treturn at((i + 1) % size()) - at(i);\n\t\t\t};\n\n\t\t\tsize_t\
    \ i = i_start, i_max = i_start;\n\t\t\tsize_t j = j_start, j_max = j_start;\n\t\
    \t\tdo {\n\t\t\t\tif (diff(i).cross(diff(j)) >= 0) {\n\t\t\t\t\tj = (j + 1) %\
    \ size();\n\t\t\t\t} else {\n\t\t\t\t\ti = (i + 1) % size();\n\t\t\t\t}\n\t\t\t\
    \tif (LD d = (at(i) - at(j)).length(); max_dist < d) {\n\t\t\t\t\tmax_dist = d;\n\
    \t\t\t\t\ti_max = i;\n\t\t\t\t\tj_max = j;\n\t\t\t\t}\n\t\t\t} while (i != i_start\
    \ || j != j_start);\n\t\t\treturn {max_dist, i_max, j_max};\n\t\t}\n\t\t// \u5207\
    \u65AD\n\t\tPolygon cut(const Line& l) const {\n\t\t\tPolygon result;\n\t\t\t\
    for (size_t i = 0; i < size(); ++i) {\n\t\t\t\tVec2 a = at(i), b = at(i != size()\
    \ - 1 ? i + 1 : 0);\n\t\t\t\tif (iSP(l.begin, l.end, a) != -1) {\n\t\t\t\t\tresult.push_back(a);\n\
    \t\t\t\t}\n\t\t\t\tif (iSP(l.begin, l.end, a) * iSP(l.begin, l.end, b) < 0) {\n\
    \t\t\t\t\tresult.push_back(*cross_point(Line(a, b), l));\n\t\t\t\t}\n\t\t\t}\n\
    \t\t\treturn result;\n\t\t}\n\t\tfriend ostream& operator<<(ostream& os, const\
    \ Polygon& p) {\n\t\t\tos << \"{\";\n\t\t\tfor (size_t i = 0; i < p.size(); ++i)\
    \ {\n\t\t\t\tif (i != 0) os << \", \";\n\t\t\t\tos << p[i];\n\t\t\t}\n\t\t\treturn\
    \ os << \"}\";\n\t\t}\n\t\tfriend istream& operator>>(istream& is, Polygon& p)\
    \ {\n\t\t\tfor (auto& v : p) {\n\t\t\t\tis >> v;\n\t\t\t}\n\t\t\treturn is;\n\t\
    \t}\n\t};\n\n}  // namespace Geometric\n#line 9 \"Geometry/Geometric.cpp\"\n\n\
    namespace Geometric {\n\n\tconstexpr bool Equal(LD a, LD b) {\n\t\treturn a <\
    \ b ? b - a < EPS : a - b < EPS;\n\t}\n\tconstexpr int sgn(LD a) {\n\t\treturn\
    \ a < -EPS ? -1 : a > EPS ? 1 : 0;\n\t}\n\n\tconstexpr LD deg_to_rad(LD deg) {\n\
    \t\treturn deg * PI / 180;\n\t}\n\tconstexpr LD rad_to_deg(LD rad) {\n\t\treturn\
    \ rad * 180 / PI;\n\t}\n\n\tVec2 Vec2::projection(const Line& l) const {\n\t\t\
    return l.begin +\n\t\t    l.vec().normalized() * (*this - l.begin).dot(l.vec())\
    \ / l.vec().length();\n\t}\n\tVec2 Vec2::reflection(const Line& l) const {\n\t\
    \treturn *this + (projection(l) - *this) * 2;\n\t}\n\n\tint iSP(const Vec2& a,\
    \ const Vec2& b, const Vec2& c) {\n\t\tint flag = sgn((b - a).cross(c - a));\n\
    \t\tif (flag != 0) {\n\t\t\treturn flag;\n\t\t} else {\n\t\t\tif (sgn((b - a).dot(c\
    \ - b)) > 0) {\n\t\t\t\treturn 2;\n\t\t\t} else if (sgn((a - b).dot(c - a)) >\
    \ 0) {\n\t\t\t\treturn -2;\n\t\t\t} else {\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t}\n\
    \t}\n\n\tint angle_type(const Vec2& a, const Vec2& b, const Vec2& c) {\n\t\tif\
    \ (int f = sgn((a - b).dot(c - b)); f > 0) {\n\t\t\treturn 0;\n\t\t} else if (f\
    \ == 0) {\n\t\t\treturn 1;\n\t\t} else {\n\t\t\treturn 2;\n\t\t}\n\t}\n\n\tLD\
    \ angle(const Vec2& a, const Vec2& b, const Vec2& c) {\n\t\t// return acos((a\
    \ - b).dot(c - b) / (distance(a, b) * distance(c, b)));\n\t\t// return abs((a\
    \ - b).rotation(-(c - b).angle()).angle());\n\t\treturn (c - b).rotation(-(a -\
    \ b).angle()).angle();\n\t}\n\n\tLD distance(const Vec2& v1, const Vec2& v2) {\n\
    \t\treturn hypot(v1.x - v2.x, v1.y - v2.y);\n\t}\n\tLD distance(const Vec2& v,\
    \ const Line& l) {\n\t\treturn abs(l.vec().cross(v - l.begin) / l.vec().length());\n\
    \t}\n\tLD distance(const Vec2& v, const Segment& s) {\n\t\tif (sgn(s.vec().dot(v\
    \ - s.begin)) < 0 || sgn(s.counter_vec().dot(v - s.end)) < 0) {\n\t\t\treturn\
    \ min(distance(v, s.begin), distance(v, s.end));\n\t\t} else {\n\t\t\treturn distance(Line(s),\
    \ v);\n\t\t}\n\t}\n\tLD distance(const Vec2& v, const Circle& c) {\n\t\treturn\
    \ max<LD>(0, distance(c.center, v) - c.r);\n\t}\n\tLD distance(const Line& l,\
    \ const Vec2& v) {\n\t\treturn distance(v, l);\n\t}\n\tLD distance(const Line&\
    \ l1, const Line& l2) {\n\t\treturn l1.is_parallel(l2) ? distance(l1, l2.begin)\
    \ : 0;\n\t}\n\tLD distance(const Segment& s, const Vec2& v) {\n\t\treturn distance(v,\
    \ s);\n\t}\n\tLD distance(const Segment& s1, const Segment& s2) {\n\t\tif (intersect(s1,\
    \ s2)) {\n\t\t\treturn 0;\n\t\t} else {\n\t\t\treturn min({distance(s1, s2.begin),\
    \ distance(s1, s2.end), distance(s1.begin, s2),\n\t\t\t            distance(s1.end,\
    \ s2)});\n\t\t}\n\t}\n\tLD distance(const Circle& c, const Vec2& v) {\n\t\treturn\
    \ distance(v, c);\n\t}\n\tLD distance(const Circle& c1, const Circle& c2) {\n\t\
    \treturn max<LD>(0, distance(c1.center, c2.center) - (c1.r + c2.r));\n\t}\n\n\t\
    bool intersect(const Vec2& v1, const Vec2& v2) {\n\t\treturn v1 == v2;\n\t}\n\t\
    bool intersect(const Vec2& v, const Line& l) {\n\t\treturn abs(iSP(v, l.begin,\
    \ l.end)) != -1;\n\t}\n\tbool intersect(const Vec2& v, const Segment& l) {\n\t\
    \treturn iSP(l.begin, l.end, v) == 0;\n\t}\n\tbool intersect(const Vec2& v, const\
    \ Circle& c) {\n\t\treturn distance(c.center, v) < c.r + EPS;\n\t}\n\tbool intersect(const\
    \ Vec2& v, const Rect& r) {\n\t\treturn sgn(r.left_x() - v.x) <= 0 && sgn(v.x\
    \ - r.right_x()) &&\n\t\t    sgn(r.top_y() - v.y) <= 0 && sgn(v.y - r.bottom_y());\n\
    \t}\n\tbool intersect(const Vec2& v, const Polygon& p) {\n\t\tLD theta = 0;\n\t\
    \tfor (size_t i = 0; i < p.size(); ++i) {\n\t\t\tVec2 next = p[i != p.size() -\
    \ 1 ? i + 1 : 0];\n\t\t\tif (intersect(Segment(p[i], next), v)) {\n\t\t\t\treturn\
    \ true;\n\t\t\t}\n\t\t\ttheta += angle(p[i], v, next);\n\t\t}\n\t\treturn abs(theta)\
    \ > 1;\n\t}\n\tbool intersect(const Line& l, const Vec2& v) {\n\t\treturn intersect(v,\
    \ l);\n\t}\n\tbool intersect(const Line& l1, const Line& l2) {\n\t\treturn !l1.is_parallel(l2);\n\
    \t}\n\tbool intersect(const Line& l, const Circle& c) {\n\t\treturn sgn(distance(c.center,\
    \ l) - c.r) <= 0;\n\t}\n\tbool intersect(const Segment& l, const Vec2& v) {\n\t\
    \treturn intersect(v, l);\n\t}\n\tbool intersect(const Segment& s1, const Segment&\
    \ s2) {\n\t\treturn iSP(s1.begin, s1.end, s2.begin) * iSP(s1.begin, s1.end, s2.end)\
    \ <= 0 &&\n\t\t    iSP(s2.begin, s2.end, s1.begin) * iSP(s2.begin, s2.end, s1.end)\
    \ <= 0;\n\t}\n\tbool intersect(const Segment& s, const Circle& c) {\n\t\treturn\
    \ sgn(distance(c.center, s) - c.r) <= 0;\n\t}\n\tbool intersect(const Circle&\
    \ c, const Vec2& v) {\n\t\treturn intersect(v, c);\n\t}\n\tbool intersect(const\
    \ Circle& c, const Line& l) {\n\t\treturn intersect(l, c);\n\t}\n\tbool intersect(const\
    \ Circle& c, const Segment& s) {\n\t\treturn intersect(s, c);\n\t}\n\tbool intersect(const\
    \ Circle& c1, const Circle& c2) {\n\t\treturn sgn(distance(c1.center, c2.center)\
    \ - (c1.r + c2.r)) <= 0;\n\t}\n\tbool intersect(const Circle& c, const Rect& r)\
    \ {\n\t\treturn intersect(Rect(r.pos - Vec2(0, c.r), r.size + Vec2(0, c.r * 2)),\
    \ c.center) ||\n\t\t    intersect(Rect(r.pos - Vec2(c.r, 0), r.size + Vec2(c.r\
    \ * 2, 0)), c.center) ||\n\t\t    intersect(c, r.top_left()) || intersect(c, r.top_right())\
    \ ||\n\t\t    intersect(c, r.bottom_left()) || intersect(c, r.bottom_right());\n\
    \t}\n\tbool intersect(const Rect& r1, const Rect& r2) {\n\t\treturn sgn(max(r1.left_x(),\
    \ r2.left_x()) - min(r1.right_x(), r2.right_x())) <= 0 &&\n\t\t    sgn(max(r1.top_y(),\
    \ r2.top_y()) - min(r1.bottom_y(), r2.bottom_y())) <= 0;\n\t}\n\tbool intersect(const\
    \ Rect& r, const Circle& c) {\n\t\treturn intersect(c, r);\n\t}\n\tbool intersect(const\
    \ Polygon& p, const Vec2& v) {\n\t\treturn intersect(v, p);\n\t}\n\n\tbool tangent(const\
    \ Vec2& v1, const Vec2& v2) {\n\t\treturn intersect(v1, v2);\n\t}\n\tbool tangent(const\
    \ Vec2& v, const Line& l) {\n\t\treturn intersect(v, l);\n\t}\n\tbool tangent(const\
    \ Vec2& v, const Segment& l) {\n\t\treturn intersect(v, l);\n\t}\n\tbool tangent(const\
    \ Vec2& v, const Circle& c) {\n\t\treturn sgn(distance(v, c.center) - c.r) ==\
    \ 0;\n\t}\n\tbool tangent(const Vec2& v, const Rect& r) {\n\t\treturn tangent(r.top(),\
    \ v) || tangent(r.bottom(), v) || tangent(r.left(), v) ||\n\t\t    tangent(r.right(),\
    \ v);\n\t}\n\tbool tangent(const Vec2& v, const Polygon& p) {\n\t\tfor (size_t\
    \ i = 0; i < p.size(); ++i) {\n\t\t\tif (tangent(Segment(p[i], p[(i + 1) % p.size()]),\
    \ v)) {\n\t\t\t\treturn true;\n\t\t\t}\n\t\t}\n\t\treturn false;\n\t}\n\tbool\
    \ tangent(const Line& l, const Vec2& v) {\n\t\treturn tangent(v, l);\n\t}\n\t\
    bool tangent(const Segment& l, const Vec2& v) {\n\t\treturn tangent(v, l);\n\t\
    }\n\tbool tangent(const Circle& c, const Vec2& v) {\n\t\treturn tangent(v, c);\n\
    \t}\n\tbool tangent(const Circle& c1, const Circle& c2) {\n\t\tLD l1 = distance(c1.center,\
    \ c2.center), l2 = c1.r, l3 = c2.r;\n\t\treturn sgn(l1 + l2 + l3 - max({l1, l2,\
    \ l3}) * 2) == 0;\n\t}\n\tbool tangent(const Rect& r, const Vec2& v) {\n\t\treturn\
    \ tangent(v, r);\n\t}\n\tbool tangent(const Polygon& p, const Vec2& v) {\n\t\t\
    return tangent(v, p);\n\t}\n\n\toptional<Vec2> cross_point(const Line& l1, const\
    \ Line& l2) {\n\t\tif (intersect(l1, l2)) {\n\t\t\t// return begin + vec() * abs((l.end\
    \ - begin).cross(l.vec()) /\n\t\t\t// vec().cross(l.vec()));\n\t\t\tauto [a, b,\
    \ c] = l1.abc();\n\t\t\tauto [A, B, C] = l2.abc();\n\t\t\tLD d = A * b - a * B;\n\
    \t\t\treturn Vec2((B * c - b * C) / d, (a * C - A * c) / d);\n\t\t} else {\n\t\
    \t\treturn nullopt;\n\t\t}\n\t}\n\toptional<Vec2> cross_point(const Segment& s1,\
    \ const Segment& s2) {\n\t\tif (intersect(s1, s2)) {\n\t\t\treturn cross_point(Line(s1),\
    \ Line(s2));\n\t\t} else {\n\t\t\treturn nullopt;\n\t\t}\n\t}\n\n\tvector<Vec2>\
    \ cross_points(const Line& l, const Circle& c) {\n\t\tLD dist = distance(l, c.center);\n\
    \t\tif (int f = sgn(c.r - dist); f == 1) {\n\t\t\tLD x = sqrt(c.r * c.r - dist\
    \ * dist);\n\t\t\tVec2 p = c.center.projection(l);\n\t\t\treturn {p + l.vec().normalized()\
    \ * x, p + l.counter_vec().normalized() * x};\n\t\t} else if (f == 0) {\n\t\t\t\
    return {c.center.projection(l)};\n\t\t} else {\n\t\t\treturn {};\n\t\t}\n\t}\n\
    \tvector<Vec2> cross_points(const Segment& s, const Circle& c) {\n\t\tvector<Vec2>\
    \ result;\n\t\tfor (const Vec2& v : cross_points(Line(s), c)) {\n\t\t\tif (intersect(v,\
    \ s)) {\n\t\t\t\tresult.push_back(v);\n\t\t\t}\n\t\t}\n\t\treturn result;\n\t\
    }\n\tvector<Vec2> cross_points(const Circle& c, const Line& l) {\n\t\treturn cross_points(l,\
    \ c);\n\t}\n\tvector<Vec2> cross_points(const Circle& c, const Segment& s) {\n\
    \t\treturn cross_points(s, c);\n\t}\n\tvector<Vec2> cross_points(const Circle&\
    \ c1, const Circle& c2) {\n\t\tVec2 vec = (c1.center - c2.center).normalized();\
    \  // c2 -> c1\n\t\tLD dist = distance(c1.center, c2.center);\n\t\tif (sgn(dist\
    \ - c1.r - c2.r) == 0) {\n\t\t\treturn {c2.center + vec * c2.r};\n\t\t} else if\
    \ (sgn(c1.r + dist - c2.r) == 0) {\n\t\t\treturn {c1.center + vec * c1.r};\n\t\
    \t} else if (sgn(c2.r + dist - c1.r) == 0) {\n\t\t\treturn {c2.center + vec.rotate180()\
    \ * c2.r};\n\t\t} else if (intersect(c1, c2)) {\n\t\t\tLD area = Triangle::area(dist,\
    \ c1.r, c2.r);\n\t\t\tLD y = 2 * area / dist, x = sqrt(c1.r * c1.r - y * y);\n\
    \t\t\tLD r1_s = c1.r * c1.r, r2_s = c2.r * c2.r, dist_s = dist * dist;\n\t\t\t\
    Vec2 h = c1.center + vec * (r2_s < r1_s + dist_s ? -x : x),\n\t\t\t     v2 = vec.rotate90()\
    \ * y;\n\t\t\treturn {h + v2, h - v2};\n\t\t} else {\n\t\t\treturn {};\n\t\t}\n\
    \t}\n\n\tvector<Vec2> tangent_to_circle(const Circle& c, const Vec2& v) {\n\t\t\
    LD dist = distance(c.center, v);\n\t\tif (sgn(dist - c.r) >= 0) {\n\t\t\tLD x\
    \ = sqrt(dist * dist - c.r * c.r);\n\t\t\treturn cross_points(Circle(v, x), c);\n\
    \t\t} else {\n\t\t\treturn {};\n\t\t}\n\t}\n}  // namespace Geometric\n#line 6\
    \ \"test/Geometric_cirnnumscribed_circle.test.cpp\"\nusing namespace std;\n\n\
    int main() {\n\tGeometric::Triangle t;\n\tcin >> t;\n\tGeometric::Circle ans =\
    \ t.cirnumscribed_circle();\n\tprintf(\"%.12Lf %.12Lf %.12Lf\\n\", ans.center.x,\
    \ ans.center.y, ans.r);\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_C\"\
    \n#define ERROR \"1e-6\"\n#include \"./../Geometry/Triangle.hpp\"\n#include \"\
    ./../Geometry/Geometric.cpp\"\n#include <iostream>\nusing namespace std;\n\nint\
    \ main() {\n\tGeometric::Triangle t;\n\tcin >> t;\n\tGeometric::Circle ans = t.cirnumscribed_circle();\n\
    \tprintf(\"%.12Lf %.12Lf %.12Lf\\n\", ans.center.x, ans.center.y, ans.r);\n}"
  dependsOn:
  - Geometry/Triangle.hpp
  - Geometry/Geometric.hpp
  - Geometry/Vec2.hpp
  - Geometry/Line.hpp
  - Geometry/Circle.hpp
  - Geometry/Geometric.cpp
  - Geometry/Rect.hpp
  - Geometry/Polygon.hpp
  isVerificationFile: true
  path: test/Geometric_cirnnumscribed_circle.test.cpp
  requiredBy: []
  timestamp: '2021-01-04 19:41:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Geometric_cirnnumscribed_circle.test.cpp
layout: document
redirect_from:
- /verify/test/Geometric_cirnnumscribed_circle.test.cpp
- /verify/test/Geometric_cirnnumscribed_circle.test.cpp.html
title: test/Geometric_cirnnumscribed_circle.test.cpp
---
