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
    ERROR: 1e-8
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
  bundledCode: "#line 1 \"test/Geometric_reflection.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B\"\n#define ERROR\
    \ \"1e-8\"\n#line 2 \"Geometry/Geometric.hpp\"\n#include <iostream>\n#include\
    \ <vector>\n#include <algorithm>\n#include <optional>\nusing namespace std;\n\n\
    namespace Geometric {\n\n\tusing LD = long double;\n\tconstexpr long double PI\
    \ = 3.14159265358979323846, EPS = 1e-12;\n\n\tconstexpr bool Equal(LD a, LD b);\n\
    \t// a > 0 : +1\n\t// a = 0 :  0\n\t// a < 0 : -1\n\tconstexpr int sgn(LD a);\n\
    \tconstexpr LD deg_to_rad(LD deg);\n\tconstexpr LD rad_to_deg(LD rad);\n\n\tstruct\
    \ Vec2;\n\tstruct Line;\n\tstruct Segment;\n\tstruct Rect;\n\tstruct Circle;\n\
    \tstruct Polygon;\n\n\t// AB \u304B\u3089\u898B\u3066 BC \u304C\u5DE6\u306B\u66F2\
    \u304C\u308B   : +1\n\t// AB \u304B\u3089\u898B\u3066 BC \u304C\u53F3\u306B\u66F2\
    \u304C\u308B   : -1\n\t// ABC, CBA \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\u306B\
    \u4E26\u3076 : +2\n\t// ACB, BCA \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\u306B\
    \u4E26\u3076 :  0\n\t// BAC, CAB \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\u306B\
    \u4E26\u3076 : -2\n\tint iSP(const Vec2& a, const Vec2& b, const Vec2& c);\n\n\
    \t// \u89D2ABC \u304C\u92ED\u89D2 : 0, \u76F4\u89D2 : 1, \u920D\u89D2 : 2\n\t\
    int angle_type(const Vec2& a, const Vec2& b, const Vec2& c);\n\n\t// \u8DDD\u96E2\
    \n\tLD distance(const Vec2& v1, const Vec2& v2);\n\tLD distance(const Vec2& v,\
    \ const Line& l);\n\tLD distance(const Vec2& v, const Segment& s);\n\tLD distance(const\
    \ Vec2& v, const Circle& c);\n\tLD distance(const Line& l, const Vec2& v);\n\t\
    LD distance(const Line& l1, const Line& l2);\n\tLD distance(const Segment& s,\
    \ const Vec2& v);\n\tLD distance(const Segment& s1, const Segment& s2);\n\tLD\
    \ distance(const Circle& c, const Vec2& v);\n\tLD distance(const Circle& c1, const\
    \ Circle& c2);\n\n\t// \u4EA4\u5DEE\u5224\u5B9A \uFF08\u5185\u5305\u3057\u3066\
    \u3044\u308B\u3068\u304D\u3082 true \u3092\u8FD4\u3059\uFF09\n\tbool intersect(const\
    \ Vec2& v1, const Vec2& v2);\n\tbool intersect(const Vec2& v, const Line& l);\n\
    \tbool intersect(const Vec2& v, const Segment& l);\n\tbool intersect(const Vec2&\
    \ v, const Circle& c);\n\tbool intersect(const Vec2& v, const Rect& r);\n\tbool\
    \ intersect(const Line& l, const Vec2& v);\n\tbool intersect(const Line& l1, const\
    \ Line& l2);\n\tbool intersect(const Line& l, const Circle& c);\n\tbool intersect(const\
    \ Segment& l, const Vec2& v);\n\tbool intersect(const Segment& s1, const Segment&\
    \ s2);\n\tbool intersect(const Segment& s, const Circle& c);\n\tbool intersect(const\
    \ Circle& c, const Vec2& v);\n\tbool intersect(const Circle& c, const Line& l);\n\
    \tbool intersect(const Circle& c, const Segment& s);\n\tbool intersect(const Circle&\
    \ c1, const Circle& c2);\n\tbool intersect(const Circle& c, const Rect& r);\n\t\
    bool intersect(const Rect& r1, const Rect& r2);\n\tbool intersect(const Rect&\
    \ r, const Circle& c);\n\n\t// \u4EA4\u70B9\n\toptional<Vec2> cross_point(const\
    \ Line& l1, const Line& l2);\n\toptional<Vec2> cross_point(const Segment& s1,\
    \ const Segment& s2);\n\n\tvector<Vec2> cross_points(const Line& l, const Circle&\
    \ c);\n\tvector<Vec2> cross_points(const Circle& c,const Line& l);\n\tvector<Vec2>\
    \ cross_points(const Circle& c1, const Circle& c2);\n\n}  // namespace Geometric\n\
    #line 4 \"Geometry/Vec2.hpp\"\n#include <cmath>\n\nnamespace Geometric {\n\n\t\
    struct Vec2 {\n\t\tLD x, y;\n\t\tstatic bool compare_x(const Vec2& v1, const Vec2&\
    \ v2) {\n\t\t\treturn v1.x < v2.x;\n\t\t}\n\t\tstatic bool compare_y(const Vec2&\
    \ v1, const Vec2& v2) {\n\t\t\treturn v1.y < v2.y;\n\t\t}\n\t\tstatic bool compare_xy(const\
    \ Vec2& v1, const Vec2& v2) {\n\t\t\treturn make_pair(v1.x, v1.y) < make_pair(v2.x,\
    \ v2.y);\n\t\t}\n\t\tstatic bool compare_yx(const Vec2& v1, const Vec2& v2) {\n\
    \t\t\treturn make_pair(v1.y, v1.x) < make_pair(v2.y, v2.x);\n\t\t}\n\t\tconstexpr\
    \ Vec2() : x(0), y(0) {}\n\t\tconstexpr Vec2(LD _x, LD _y) : x(_x), y(_y) {}\n\
    \t\tVec2(LD rad) : x(cos(rad)), y(sin(rad)) {}\n\t\tconstexpr bool operator==(const\
    \ Vec2& v) const {\n\t\t\treturn Equal(x, v.x) && Equal(y, v.y);\n\t\t}\n\t\t\
    constexpr bool operator!=(const Vec2& v) const {\n\t\t\treturn !(*this == v);\n\
    \t\t}\n\t\tconstexpr bool operator<(const Vec2& v) const {\n\t\t\treturn x < v.x\
    \ - EPS && y < v.y - EPS;\n\t\t}\n\t\tconstexpr bool operator<=(const Vec2& v)\
    \ const {\n\t\t\treturn x < v.x + EPS && y < v.y + EPS;\n\t\t}\n\t\tconstexpr\
    \ Vec2 operator+() const {\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2 operator-()\
    \ const {\n\t\t\treturn {-x, -y};\n\t\t}\n\t\tconstexpr Vec2 operator+(const Vec2&\
    \ v) const {\n\t\t\treturn Vec2(*this) += v;\n\t\t}\n\t\tconstexpr Vec2 operator-(const\
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
    \ {\n\t\t\treturn std::abs(x - v.x) + std::abs(y - v.y);\n\t\t}\n\t\ttemplate\
    \ <class Shape2DType> LD distance(const Shape2DType& shape) const {\n\t\t\treturn\
    \ Geometric::distance(*this, shape);\n\t\t}\n\t\ttemplate <class Shape2DType>\
    \ bool intersects(const Shape2DType& shape) const {\n\t\t\treturn Geometric::intersect(*this,\
    \ shape);\n\t\t}\n\t\tconstexpr LD length_square() const {\n\t\t\treturn dot(*this);\n\
    \t\t}\n\t\tLD length() const {\n\t\t\treturn sqrt(length_square());\n\t\t}\n\t\
    \t// \u5185\u7A4D\n\t\tconstexpr LD dot(const Vec2& v) const {\n\t\t\treturn x\
    \ * v.x + y * v.y;\n\t\t}\n\t\t// \u5916\u7A4D\n\t\tconstexpr LD cross(const Vec2&\
    \ v) const {\n\t\t\treturn x * v.y - y * v.x;\n\t\t}\n\t\t// \u6B63\u898F\u5316\
    \uFF08\u9577\u3055\u30921\u306B\u3057\u305F\uFF09\u30D9\u30AF\u30C8\u30EB\n\t\t\
    Vec2 normalized() const {\n\t\t\treturn *this / length();\n\t\t}\n\t\t// \u539F\
    \u70B9\u4E2D\u5FC3\u306B rad \u56DE\u8EE2\u3057\u305F\u5EA7\u6A19\n\t\tVec2 rotation(LD\
    \ rad) const {\n\t\t\tLD c = cos(rad), s = sin(rad);\n\t\t\treturn {x * c - y\
    \ * s, x * s + y * c};\n\t\t}\n\t\t// \u539F\u70B9\u4E2D\u5FC3\u306E\u5186\u4E0A\
    \u306B\u4E57\u3063\u3066\u3044\u308B\u3068\u3057\u305F\u3068\u304D\u306E\u504F\
    \u89D2\n\t\tLD angle() const {\n\t\t\treturn atan2(y, x);\n\t\t}\n\t\t// \u6B63\
    \u5C04\u5F71\n\t\tVec2 projection(const Line& l) const;\n\t\t// \u93E1\u6620\u5909\
    \u63DB\n\t\tVec2 reflection(const Line& l) const;\n\t\tconstexpr Vec2 rotate90()\
    \ const {\n\t\t\treturn {y, -x};\n\t\t}\n\t\tconstexpr Vec2 rotate180() const\
    \ {\n\t\t\treturn {-x, -y};\n\t\t}\n\t\tconstexpr Vec2 rotate270() const {\n\t\
    \t\treturn {-y, x};\n\t\t}\n\t\tfriend ostream& operator<<(ostream& os, const\
    \ Vec2& v) {\n\t\t\treturn os << '(' << v.x << \", \" << v.y << ')';\n\t\t}\n\t\
    \tfriend istream& operator>>(istream& is, Vec2& v) {\n\t\t\treturn is >> v.x >>\
    \ v.y;\n\t\t}\n\t};\n\n}  // namespace Geometric\n#line 5 \"Geometry/Line.hpp\"\
    \n#include <utility>\n#include <tuple>\n#line 9 \"Geometry/Line.hpp\"\nusing namespace\
    \ std;\n\nnamespace Geometric {\n\n\tnamespace internal {\n\t\tstruct LineBase\
    \ {\n\t\tprotected:\n\t\t\tconstexpr LineBase() = default;\n\t\t\tconstexpr LineBase(const\
    \ Vec2& _begin, const Vec2& _end) : begin(_begin), end(_end) {}\n\t\t\tconstexpr\
    \ LineBase(LD begin_x, LD begin_y, LD end_x, LD end_y)\n\t\t\t    : begin(begin_x,\
    \ begin_y), end(end_x, end_y) {}\n\n\t\tpublic:\n\t\t\tVec2 begin, end;\n\t\t\t\
    constexpr Vec2 vec() const {\n\t\t\t\treturn end - begin;\n\t\t\t}\n\t\t\tconstexpr\
    \ Vec2 counter_vec() const {\n\t\t\t\treturn begin - end;\n\t\t\t}\n\t\t\t// \u5E73\
    \u884C\u5224\u5B9A\n\t\t\tconstexpr bool is_parallel(const LineBase& l) const\
    \ {\n\t\t\t\treturn sgn(vec().cross(l.vec())) == 0;\n\t\t\t}\n\t\t\t// \u76F4\u4EA4\
    \u5224\u5B9A\n\t\t\tconstexpr bool is_orthogonal(const LineBase& l) const {\n\t\
    \t\t\treturn sgn(vec().dot(l.vec())) == 0;\n\t\t\t}\n\t\t\tfriend ostream& operator<<(ostream&\
    \ os, const LineBase& l) {\n\t\t\t\treturn os << '(' << l.begin << \", \" << l.end\
    \ << ')';\n\t\t\t}\n\t\t\tfriend istream& operator>>(istream& is, LineBase& l)\
    \ {\n\t\t\t\treturn is >> l.begin >> l.end;\n\t\t\t}\n\t\t};\n\t}  // namespace\
    \ internal\n\n\tstruct Line : internal::LineBase {\n\t\tLine() = default;\n\t\t\
    Line(const Vec2& _begin, const Vec2& _end) : LineBase(_begin, _end) {}\n\t\tconstexpr\
    \ Line(LD begin_x, LD begin_y, LD end_x, LD end_y) : LineBase(begin_x, begin_y,\
    \ end_x, end_y) {}\n\t\tLine(const LineBase& l) : LineBase(l) {}\n\t\ttemplate\
    \ <class Shape2DType> LD distance(const Shape2DType& shape) const {\n\t\t\treturn\
    \ Geometric::distance(*this, shape);\n\t\t}\n\t\ttemplate <class Shape2DType>\
    \ bool intersects(const Shape2DType& shape) const {\n\t\t\treturn Geometric::intersect(*this,\
    \ shape);\n\t\t}\n\t\ttemplate <class Shape2DType> optional<Vec2> cross_point(const\
    \ Shape2DType& shape) const {\n\t\t\treturn Geometric::cross_point(*this, shape);\n\
    \t\t}\n\t\ttemplate <class Shape2DType> vector<Vec2> cross_points(const Shape2DType&\
    \ shape) const {\n\t\t\treturn Geometric::cross_points(*this, shape);\n\t\t}\n\
    \t\t// ax + by + c = 0 \u306E\u5F0F\u306B\u5909\u5F62\u3059\u308B\n\t\ttuple<LD,\
    \ LD, LD> abc() const {\n\t\t\tif (sgn(begin.x - end.x) == 0) {\n\t\t\t\treturn\
    \ {1, 0, -begin.x};\n\t\t\t} else {\n\t\t\t\tLD slope = (end.y - begin.y) / (end.x\
    \ - begin.x);\n\t\t\t\treturn {slope, -1, begin.y - begin.x * slope};\n\t\t\t\
    }\n\t\t}\n\t};\n\n\tstruct Segment : internal::LineBase {\n\t\tSegment() = default;\n\
    \t\tSegment(const Vec2& _begin, const Vec2& _end) : LineBase(_begin, _end) {}\n\
    \t\tconstexpr Segment(LD begin_x, LD begin_y, LD end_x, LD end_y) : LineBase(begin_x,\
    \ begin_y, end_x, end_y) {}\n\t\tSegment(const LineBase& l) : LineBase(l) {}\n\
    \t\ttemplate <class Shape2DType> LD distance(const Shape2DType& shape) const {\n\
    \t\t\treturn Geometric::distance(*this, shape);\n\t\t}\n\t\ttemplate <class Shape2DType>\
    \ bool intersects(const Shape2DType& shape) const {\n\t\t\treturn Geometric::intersect(*this,\
    \ shape);\n\t\t}\n\t\ttemplate <class Shape2DType> optional<Vec2> cross_point(const\
    \ Shape2DType& shape) const {\n\t\t\treturn Geometric::cross_point(*this, shape);\n\
    \t\t}\n\t\ttemplate <class Shape2DType> vector<Vec2> cross_points(const Shape2DType&\
    \ shape) const {\n\t\t\treturn Geometric::cross_points(*this, shape);\n\t\t}\n\
    \t};\n\n}  // namespace Geometric\n#line 6 \"Geometry/Circle.hpp\"\nusing namespace\
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
    \ LD perimeter() const {\n\t\t\treturn 2 * r * PI;\n\t\t}\n\t\ttemplate <class\
    \ Shape2DType> LD distance(const Shape2DType& shape) const {\n\t\t\treturn Geometric::distance(*this,\
    \ shape);\n\t\t}\n\t\ttemplate <class Shape2DType> bool intersects(const Shape2DType&\
    \ shape) const {\n\t\t\treturn Geometric::intersect(*this, shape);\n\t\t}\n\t\t\
    template <class Shape2DType> vector<Vec2> cross_points(const Shape2DType& shape)\
    \ const {\n\t\t\treturn Geometric::cross_points(*this, shape);\n\t\t}\n\t\tbool\
    \ contains(const Circle& c) const {\n\t\t\treturn center.distance(c.center) +\
    \ c.r < r - EPS;\n\t\t}\n\t\tbool tangent(const Circle& c) const {\n\t\t\tLD l1\
    \ = center.distance(c.center), l2 = r, l3 = c.r;\n\t\t\treturn Equal(l1 + l2 +\
    \ l3, max({l1, l2, l3}) * 2);\n\t\t}\n\t\tfriend ostream& operator<<(ostream&\
    \ os, const Circle& c) {\n\t\t\treturn os << '(' << c.center.x << ',' << c.center.y\
    \ << ',' << c.r << ')';\n\t\t}\n\t\tfriend istream& operator>>(istream& is, Circle&\
    \ c) {\n\t\t\treturn is >> c.center >> c.r;\n\t\t}\n\t};\n\n}  // namespace Geometric\n\
    #line 5 \"Geometry/Rect.hpp\"\nusing namespace std;\n\nnamespace Geometric {\n\
    \n\tstruct Rect {\n\t\tVec2 pos, size;\n\t\tconstexpr Rect() {}\n\t\tconstexpr\
    \ Rect(LD _w, LD _h) : size(_w, _h) {}\n\t\tconstexpr Rect(const Vec2& _size)\
    \ : size(_size) {}\n\t\tconstexpr Rect(LD _x, LD _y, LD _w, LD _h) : pos(_x, _y),\
    \ size(_w, _h) {}\n\t\tconstexpr Rect(const Vec2& _pos, const Vec2& _size) : pos(_pos),\
    \ size(_size) {}\n\t\tconstexpr bool operator==(const Rect& r) const {\n\t\t\t\
    return pos == r.pos && size == r.size;\n\t\t}\n\t\tconstexpr bool operator!=(const\
    \ Rect& r) const {\n\t\t\treturn !(*this == r);\n\t\t}\n\t\tconstexpr Rect operator+(const\
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
    \ const {\n\t\t\treturn (size.x + size.y) * 2;\n\t\t}\n\t\ttemplate <class Shape2DType>\
    \ LD distance(const Shape2DType& shape) const {\n\t\t\treturn Geometric::distance(*this,\
    \ shape);\n\t\t}\n\t\ttemplate <class Shape2DType> bool intersects(const Shape2DType&\
    \ shape) const {\n\t\t\treturn Geometric::intersect(*this, shape);\n\t\t}\n\t\t\
    constexpr bool contains(const Rect& r) const {\n\t\t\treturn top_left() <= r.top_left()\
    \ && r.bottom_right() <= bottom_right();\n\t\t}\n\t\tconstexpr bool contains(const\
    \ Circle& c) const {\n\t\t\treturn top_left() <= Vec2(c.left_x(), c.top_y()) &&\
    \ Vec2(c.right_x(), c.bottom_y()) <= bottom_right();\n\t\t}\n\t\tfriend ostream&\
    \ operator<<(ostream& os, const Rect& r) {\n\t\t\treturn os << '(' << r.pos <<\
    \ ',' << r.size << ')';\n\t\t}\n\t\tfriend istream& operator>>(istream& is, Rect&\
    \ r) {\n\t\t\treturn is >> r.pos >> r.size;\n\t\t}\n\t};\n\n}  // namespace Geometric\n\
    #line 7 \"Geometry/Triangle.hpp\"\n#include <cassert>\nusing namespace std;\n\n\
    namespace Geometric {\n\n\tstruct Triangle {\n\t\tVec2 p1, p2, p3;\n\t\tstatic\
    \ LD area(LD a, LD b, LD c) {\n\t\t\tLD s = (a + b + c) / 2;\n\t\t\treturn sqrt(s\
    \ * (s - a) * (s - b) * (s - c));\n\t\t}\n\t\tTriangle() = default;\n\t\tTriangle(const\
    \ Vec2& _p1, const Vec2& _p2, const Vec2& _p3) : p1(_p1), p2(_p2), p3(_p3) {\n\
    \t\t\tassert(abs(iSP(p1, p2, p3)) == 1);\n\t\t}\n\t\ttuple<LD, LD, LD> sides()\
    \ const {\n\t\t\treturn {p2.distance(p3), p1.distance(p3), p1.distance(p2)};\n\
    \t\t}\n\t\tLD area() const {\n\t\t\tauto [l1, l2, l3] = sides();\n\t\t\treturn\
    \ area(l1, l2, l3);\n\t\t}\n\t\t// \u5185\u63A5\u5186\n\t\tCircle incircle() const\
    \ {\n\t\t\tauto [l1, l2, l3] = sides();\n\t\t\tLD s = l1 + l2 + l3;\n\t\t\tLD\
    \ x = (p1.x * l1 + p2.x * l2 + p3.x * l3) / s;\n\t\t\tLD y = (p1.y * l1 + p2.y\
    \ * l2 + p3.y * l3) / s;\n\t\t\ts /= 2;\n\t\t\tLD r = sqrt((s - l1) * (s - l2)\
    \ * (s - l3) / s);\n\t\t\treturn Circle(x, y, r);\n\t\t}\n\t\t// \u5916\u63A5\u5186\
    \n\t\tCircle cirnumscribed_circle() const {\n\t\t\tLine l1((p1 + p2) / 2, (p1\
    \ + p2) / 2 + (p1 - p2).rotate270());\n\t\t\tLine l2((p1 + p3) / 2, (p1 + p3)\
    \ / 2 + (p1 - p3).rotate270());\n\t\t\tVec2 center = *l1.cross_point(l2);\n\t\t\
    \treturn Circle(center, center.distance(p1));\n\t\t}\n\t\tfriend ostream& operator<<(ostream&\
    \ os, const Triangle& t) {\n\t\t\treturn os << '(' << t.p1 << \", \" << t.p2 <<\
    \ \", \" << t.p3 << ')';\n\t\t}\n\t\tfriend istream& operator>>(istream& is, Triangle&\
    \ t) {\n\t\t\treturn is >> t.p1 >> t.p2 >> t.p3;\n\t\t}\n\t};\n\n}  // namespace\
    \ Geometric\n#line 8 \"Geometry/Geometric.cpp\"\n\nnamespace Geometric {\n\n\t\
    constexpr bool Equal(LD a, LD b) {\n\t\treturn a < b ? b - a < EPS : a - b < EPS;\n\
    \t}\n\t// a > 0  : +1\n\t// a == 0 :  0\n\t// a < 0  : -1\n\tconstexpr int sgn(LD\
    \ a) {\n\t\treturn a < -EPS ? -1 : a > EPS ? 1 : 0;\n\t}\n\n\tconstexpr LD deg_to_rad(LD\
    \ deg) {\n\t\treturn deg * PI / 180;\n\t}\n\tconstexpr LD rad_to_deg(LD rad) {\n\
    \t\treturn rad * 180 / PI;\n\t}\n\n\tVec2 Vec2::projection(const Line& l) const\
    \ {\n\t\treturn l.begin + l.vec().normalized() * (*this - l.begin).dot(l.vec())\
    \ / l.vec().length();\n\t}\n\tVec2 Vec2::reflection(const Line& l) const {\n\t\
    \treturn *this + (projection(l) - *this) * 2;\n\t}\n\n\tint iSP(const Vec2& a,\
    \ const Vec2& b, const Vec2& c) {\n\t\tint flag = sgn((b - a).cross(c - a));\n\
    \t\tif (flag != 0) {\n\t\t\treturn flag;\n\t\t} else {\n\t\t\tif (sgn((b - a).dot(c\
    \ - b)) > 0) {\n\t\t\t\treturn 2;\n\t\t\t} else if (sgn((a - b).dot(c - a)) >\
    \ 0) {\n\t\t\t\treturn -2;\n\t\t\t} else {\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t}\n\
    \t}\n\n\tint angle_type(const Vec2& a, const Vec2& b, const Vec2& c) {\n\t\tif\
    \ (int f = sgn((a - b).dot(c - b)); f > 0) {\n\t\t\treturn 0;\n\t\t} else if (f\
    \ == 0) {\n\t\t\treturn 1;\n\t\t} else {\n\t\t\treturn 2;\n\t\t}\n\t}\n\n\tLD\
    \ distance(const Vec2& v1, const Vec2& v2) {\n\t\treturn hypot(v1.x - v2.x, v1.y\
    \ - v2.y);\n\t}\n\tLD distance(const Vec2& v, const Line& l) {\n\t\treturn abs(l.vec().cross(v\
    \ - l.begin) / l.vec().length());\n\t}\n\tLD distance(const Vec2& v, const Segment&\
    \ s) {\n\t\tif (sgn(s.vec().dot(v - s.begin)) < 0 || sgn(s.counter_vec().dot(v\
    \ - s.end)) < 0) {\n\t\t\treturn min(v.distance(s.begin), v.distance(s.end));\n\
    \t\t} else {\n\t\t\treturn Line(s).distance(v);\n\t\t}\n\t}\n\tLD distance(const\
    \ Vec2& v, const Circle& c) {\n\t\treturn max<LD>(0, c.center.distance(v) - c.r);\n\
    \t}\n\tLD distance(const Line& l, const Vec2& v) {\n\t\treturn distance(v, l);\n\
    \t}\n\tLD distance(const Line& l1, const Line& l2) {\n\t\treturn l1.is_parallel(l2)\
    \ ? l1.distance(l2.begin) : 0;\n\t}\n\tLD distance(const Segment& s, const Vec2&\
    \ v) {\n\t\treturn distance(v, s);\n\t}\n\tLD distance(const Segment& s1, const\
    \ Segment& s2) {\n\t\tif (intersect(s1, s2)) {\n\t\t\treturn 0;\n\t\t} else {\n\
    \t\t\treturn min({distance(s1, s2.begin), distance(s1, s2.end), distance(s1.begin,\
    \ s2), distance(s1.end, s2)});\n\t\t}\n\t}\n\tLD distance(const Circle& c, const\
    \ Vec2& v) {\n\t\treturn distance(v, c);\n\t}\n\tLD distance(const Circle& c1,\
    \ const Circle& c2) {\n\t\treturn max<LD>(0, distance(c1.center, c2.center) -\
    \ (c1.r + c2.r));\n\t}\n\n\tbool intersect(const Vec2& v1, const Vec2& v2) {\n\
    \t\treturn v1 == v2;\n\t}\n\tbool intersect(const Vec2& v, const Line& l) {\n\t\
    \treturn abs(iSP(v, l.begin, l.end)) != -1;\n\t}\n\tbool intersect(const Vec2&\
    \ v, const Segment& l) {\n\t\treturn iSP(l.begin, l.end, v) == 0;\n\t}\n\tbool\
    \ intersect(const Vec2& v, const Circle& c) {\n\t\treturn c.center.distance(v)\
    \ < c.r + EPS;\n\t}\n\tbool intersect(const Vec2& v, const Rect& r) {\n\t\treturn\
    \ r.pos <= v && v <= r.bottom_right();\n\t}\n\tbool intersect(const Line& l, const\
    \ Vec2& v) {\n\t\treturn intersect(v, l);\n\t}\n\tbool intersect(const Line& l1,\
    \ const Line& l2) {\n\t\treturn !l1.is_parallel(l2);\n\t}\n\tbool intersect(const\
    \ Line& l, const Circle& c) {\n\t\treturn sgn(distance(c.center, l) - c.r) <=\
    \ 0;\n\t}\n\tbool intersect(const Segment& l, const Vec2& v) {\n\t\treturn intersect(v,\
    \ l);\n\t}\n\tbool intersect(const Segment& s1, const Segment& s2) {\n\t\treturn\
    \ iSP(s1.begin, s1.end, s2.begin) * iSP(s1.begin, s1.end, s2.end) <= 0 &&\n\t\t\
    \    iSP(s2.begin, s2.end, s1.begin) * iSP(s2.begin, s2.end, s1.end) <= 0;\n\t\
    }\n\tbool intersect(const Segment& s, const Circle& c) {\n\t\treturn sgn(distance(c.center,\
    \ s) - c.r) <= 0;\n\t}\n\tbool intersect(const Circle& c, const Vec2& v) {\n\t\
    \treturn intersect(v, c);\n\t}\n\tbool intersect(const Circle& c, const Line&\
    \ l) {\n\t\treturn intersect(l, c);\n\t}\n\tbool intersect(const Circle& c, const\
    \ Segment& s) {\n\t\treturn intersect(s, c);\n\t}\n\tbool intersect(const Circle&\
    \ c1, const Circle& c2) {\n\t\treturn sgn(distance(c1.center, c2.center) - (c1.r\
    \ + c2.r)) <= 0;\n\t}\n\tbool intersect(const Circle& c, const Rect& r) {\n\t\t\
    return Rect(r.pos - Vec2(0, c.r), r.size + Vec2(0, c.r * 2)).intersects(c.center)\
    \ ||\n\t\t    Rect(r.pos - Vec2(c.r, 0), r.size + Vec2(c.r * 2, 0)).intersects(c.center)\
    \ || c.intersects(r.top_left()) ||\n\t\t    c.intersects(r.top_right()) || c.intersects(r.bottom_left())\
    \ || c.intersects(r.bottom_right());\n\t}\n\tbool intersect(const Rect& r1, const\
    \ Rect& r2) {\n\t\treturn max(r1.left(), r2.left()) < min(r1.right(), r2.right())\
    \ + EPS &&\n\t\t    max(r1.top(), r2.top()) < min(r1.bottom(), r2.bottom()) +\
    \ EPS;\n\t}\n\tbool intersect(const Rect& r, const Circle& c) {\n\t\treturn intersect(c,\
    \ r);\n\t}\n\n\toptional<Vec2> cross_point(const Line& l1, const Line& l2) {\n\
    \t\tif (intersect(l1, l2)) {\n\t\t\t// return begin + vec() * abs((l.end - begin).cross(l.vec())\
    \ / vec().cross(l.vec()));\n\t\t\tauto [a, b, c] = l1.abc();\n\t\t\tauto [A, B,\
    \ C] = l2.abc();\n\t\t\tLD d = A * b - a * B;\n\t\t\treturn Vec2((B * c - b *\
    \ C) / d, (a * C - A * c) / d);\n\t\t} else {\n\t\t\treturn nullopt;\n\t\t}\n\t\
    }\n\toptional<Vec2> cross_point(const Segment& s1, const Segment& s2) {\n\t\t\
    if (intersect(s1, s2)) {\n\t\t\treturn cross_point(Line(s1), Line(s2));\n\t\t\
    } else {\n\t\t\treturn nullopt;\n\t\t}\n\t}\n\n\tvector<Vec2> cross_points(const\
    \ Line& l, const Circle& c) {\n\t\tLD dist = distance(l, c.center);\n\t\tif (int\
    \ f = sgn(c.r - dist); f == 1) {\n\t\t\tLD x = sqrt(c.r * c.r - dist * dist);\n\
    \t\t\tVec2 p = c.center.projection(l);\n\t\t\treturn {p + l.vec().normalized()\
    \ * x, p + l.counter_vec().normalized() * x};\n\t\t} else if (f == 0) {\n\t\t\t\
    return {c.center.projection(l)};\n\t\t} else {\n\t\t\treturn {};\n\t\t}\n\t}\n\
    \tvector<Vec2> cross_points(const Circle& c, const Line& l) {\n\t\treturn cross_points(l,\
    \ c);\n\t}\n\tvector<Vec2> cross_points(const Circle& c1, const Circle& c2) {\n\
    \t\tVec2 vec = (c1.center - c2.center).normalized();  // c2 -> c1\n\t\tLD dist\
    \ = c1.center.distance(c2.center);\n\t\tif (c1.contains(c2) || c2.contains(c1))\
    \ {\n\t\t\treturn {};\n\t\t} else if (sgn(dist - c1.r - c2.r) == 0) {\n\t\t\t\
    return {c2.center + vec * c2.r};\n\t\t} else if (sgn(c1.r + dist - c2.r) == 0)\
    \ {\n\t\t\treturn {c1.center + vec * c1.r};\n\t\t} else if (sgn(c2.r + dist -\
    \ c1.r) == 0) {\n\t\t\treturn {c2.center + vec.rotate180() * c2.r};\n\t\t} else\
    \ if (intersect(c1, c2)) {\n\t\t\tLD area = Triangle::area(dist, c1.r, c2.r);\n\
    \t\t\tLD y = 2 * area / dist, x = sqrt(c1.r * c1.r - y * y);\n\t\t\tLD r1_s =\
    \ c1.r * c1.r, r2_s = c2.r * c2.r, dist_s = dist * dist;\n\t\t\tVec2 h = c1.center\
    \ + vec * (r2_s < r1_s + dist_s ? -x : x), v2 = vec.rotate90() * y;\n\t\t\treturn\
    \ {h + v2, h - v2};\n\t\t} else {\n\t\t\treturn {};\n\t\t}\n\t}\n\n}  // namespace\
    \ Geometric\n#line 6 \"test/Geometric_reflection.test.cpp\"\nusing namespace std;\n\
    \nint main() {\n\tGeometric::Line l;\n\tcin >> l;\n\tint q;\n\tcin >> q;\n\twhile\
    \ (q--) {\n\t\tGeometric::Vec2 p;\n\t\tcin >> p;\n\t\tGeometric::Vec2 ans = p.reflection(l);\n\
    \t\tprintf(\"%.12Lf %.12Lf\\n\", ans.x, ans.y);\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B\"\
    \n#define ERROR \"1e-8\"\n#include \"./../Geometry/Vec2.hpp\"\n#include \"./../Geometry/Geometric.cpp\"\
    \n#include <iostream>\nusing namespace std;\n\nint main() {\n\tGeometric::Line\
    \ l;\n\tcin >> l;\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tGeometric::Vec2\
    \ p;\n\t\tcin >> p;\n\t\tGeometric::Vec2 ans = p.reflection(l);\n\t\tprintf(\"\
    %.12Lf %.12Lf\\n\", ans.x, ans.y);\n\t}\n}"
  dependsOn:
  - Geometry/Vec2.hpp
  - Geometry/Geometric.hpp
  - Geometry/Geometric.cpp
  - Geometry/Line.hpp
  - Geometry/Circle.hpp
  - Geometry/Rect.hpp
  - Geometry/Triangle.hpp
  isVerificationFile: true
  path: test/Geometric_reflection.test.cpp
  requiredBy: []
  timestamp: '2020-11-02 16:43:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Geometric_reflection.test.cpp
layout: document
redirect_from:
- /verify/test/Geometric_reflection.test.cpp
- /verify/test/Geometric_reflection.test.cpp.html
title: test/Geometric_reflection.test.cpp
---
