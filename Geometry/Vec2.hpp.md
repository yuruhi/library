---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry/Geometric.hpp
    title: Geometry/Geometric.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Geometry/Circle.hpp
    title: Geometry/Circle.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/ClosestPair.cpp
    title: Geometry/ClosestPair.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/Geometric.cpp
    title: Geometry/Geometric.cpp
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Geometric_area_of_intersection_between_circle_and_polygon.test.cpp
    title: test/Geometric_area_of_intersection_between_circle_and_polygon.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_area_of_intersection_between_two_circles.test.cpp
    title: test/Geometric_area_of_intersection_between_two_circles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_cirnnumscribed_circle.test.cpp
    title: test/Geometric_cirnnumscribed_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_closest_pair.test.cpp
    title: test/Geometric_closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_common_tangent.test.cpp
    title: test/Geometric_common_tangent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_convex_hull.test.cpp
    title: test/Geometric_convex_hull.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_cross_point_of_circles.test.cpp
    title: test/Geometric_cross_point_of_circles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_cross_points_between_line_and_circle.test.cpp
    title: test/Geometric_cross_points_between_line_and_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_dot_cross.test.cpp
    title: test/Geometric_dot_cross.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_iSP.test.cpp
    title: test/Geometric_iSP.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_incircle_of_triangle.test.cpp
    title: test/Geometric_incircle_of_triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_is_convex.test.cpp
    title: test/Geometric_is_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_is_parallel_is_orthogonal.test.cpp
    title: test/Geometric_is_parallel_is_orthogonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_line_intersection.test.cpp
    title: test/Geometric_line_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_polygon_cut.test.cpp
    title: test/Geometric_polygon_cut.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_polygon_diameter.test.cpp
    title: test/Geometric_polygon_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_polygon_point_containment.test.cpp
    title: test/Geometric_polygon_point_containment.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_projection.test.cpp
    title: test/Geometric_projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_reflection.test.cpp
    title: test/Geometric_reflection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_segment_distance.test.cpp
    title: test/Geometric_segment_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_segment_intersection.test.cpp
    title: test/Geometric_segment_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometric_tangent_to_circle.test.cpp
    title: test/Geometric_tangent_to_circle.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Geometry/Geometric.hpp\"\n#include <iostream>\n#include\
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
    \t// \u2220ABC \u304C\u92ED\u89D2 : 0, \u76F4\u89D2 : 1, \u920D\u89D2 : 2\n\t\
    int angle_type(const Vec2& a, const Vec2& b, const Vec2& c);\n\n\t// \u2220ABC\
    \ \u306E\u5024 (radian)\n\tLD angle(const Vec2& a, const Vec2& b, const Vec2&\
    \ c);\n\n\t// \u8DDD\u96E2\n\tLD distance(const Vec2& v1, const Vec2& v2);\n\t\
    LD distance(const Vec2& v, const Line& l);\n\tLD distance(const Vec2& v, const\
    \ Segment& s);\n\tLD distance(const Vec2& v, const Circle& c);\n\tLD distance(const\
    \ Line& l, const Vec2& v);\n\tLD distance(const Line& l1, const Line& l2);\n\t\
    LD distance(const Segment& s, const Vec2& v);\n\tLD distance(const Segment& s1,\
    \ const Segment& s2);\n\tLD distance(const Circle& c, const Vec2& v);\n\tLD distance(const\
    \ Circle& c1, const Circle& c2);\n\n\t// \u4EA4\u5DEE\u5224\u5B9A \uFF08\u5185\
    \u5305\u3057\u3066\u3044\u308B\u3068\u304D\u3082 true \u3092\u8FD4\u3059\uFF09\
    \n\tbool intersect(const Vec2& v1, const Vec2& v2);\n\tbool intersect(const Vec2&\
    \ v, const Line& l);\n\tbool intersect(const Vec2& v, const Segment& l);\n\tbool\
    \ intersect(const Vec2& v, const Circle& c);\n\tbool intersect(const Vec2& v,\
    \ const Rect& r);\n\tbool intersect(const Vec2& v, const Polygon& p);\n\tbool\
    \ intersect(const Line& l, const Vec2& v);\n\tbool intersect(const Line& l1, const\
    \ Line& l2);\n\tbool intersect(const Line& l, const Circle& c);\n\tbool intersect(const\
    \ Segment& l, const Vec2& v);\n\tbool intersect(const Segment& s1, const Segment&\
    \ s2);\n\tbool intersect(const Segment& s, const Circle& c);\n\tbool intersect(const\
    \ Circle& c, const Vec2& v);\n\tbool intersect(const Circle& c, const Line& l);\n\
    \tbool intersect(const Circle& c, const Segment& s);\n\tbool intersect(const Circle&\
    \ c1, const Circle& c2);\n\tbool intersect(const Circle& c, const Rect& r);\n\t\
    bool intersect(const Rect& r1, const Rect& r2);\n\tbool intersect(const Rect&\
    \ r, const Circle& c);\n\tbool intersect(const Polygon& p, const Vec2& v);\n\n\
    \t// \u63A5\u3059\u308B\u304B\u5224\u5B9A\n\tbool tangent(const Vec2& v1, const\
    \ Vec2& v2);\n\tbool tangent(const Vec2& v, const Line& l);\n\tbool tangent(const\
    \ Vec2& v, const Segment& l);\n\tbool tangent(const Vec2& v, const Circle& c);\n\
    \tbool tangent(const Vec2& v, const Rect& r);\n\tbool tangent(const Vec2& v, const\
    \ Polygon& p);\n\tbool tangent(const Line& l, const Vec2& v);\n\tbool tangent(const\
    \ Segment& l, const Vec2& v);\n\tbool tangent(const Circle& c, const Vec2& v);\n\
    \tbool tangent(const Circle& c1, const Circle& c2);\n\tbool tangent(const Rect&\
    \ r, const Vec2& v);\n\tbool tangent(const Polygon& p, const Vec2& v);\n\n\t//\
    \ \u4EA4\u70B9\n\toptional<Vec2> cross_point(const Line& l1, const Line& l2);\n\
    \toptional<Vec2> cross_point(const Segment& s1, const Segment& s2);\n\n\tvector<Vec2>\
    \ cross_points(const Line& l, const Circle& c);\n\tvector<Vec2> cross_points(const\
    \ Segment& s, const Circle& c);\n\tvector<Vec2> cross_points(const Circle& c,\
    \ const Line& l);\n\tvector<Vec2> cross_points(const Circle& c, const Segment&\
    \ s);\n\tvector<Vec2> cross_points(const Circle& c1, const Circle& c2);\n\n\t\
    // \u5186\u306E\u63A5\u7DDA\n\tvector<Vec2> tangent_to_circle(const Circle& c,\
    \ const Vec2& v);\n\tvector<Line> common_tangent(const Circle& c1, const Circle&\
    \ c2);\n\n\t// 2\u3064\u306E\u56F3\u5F62\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\
    \u7A4D\n\tLD area_of_intersection(const Circle& c1, const Circle& c2);\n\tLD area_of_intersection(const\
    \ Circle& c, const Polygon& p);\n\n}  // namespace Geometric\n#line 4 \"Geometry/Vec2.hpp\"\
    \n#include <cmath>\n\nnamespace Geometric {\n\n\tstruct Vec2 {\n\t\tLD x, y;\n\
    \t\tstatic constexpr bool compare_x(const Vec2& v1, const Vec2& v2) {\n\t\t\t\
    return v1.x < v2.x;\n\t\t}\n\t\tstatic constexpr bool compare_y(const Vec2& v1,\
    \ const Vec2& v2) {\n\t\t\treturn v1.y < v2.y;\n\t\t}\n\t\tstatic constexpr bool\
    \ compare_xy(const Vec2& v1, const Vec2& v2) {\n\t\t\treturn make_pair(v1.x, v1.y)\
    \ < make_pair(v2.x, v2.y);\n\t\t}\n\t\tstatic constexpr bool compare_yx(const\
    \ Vec2& v1, const Vec2& v2) {\n\t\t\treturn make_pair(v1.y, v1.x) < make_pair(v2.y,\
    \ v2.x);\n\t\t}\n\t\tstatic constexpr Vec2 zero() {\n\t\t\treturn Vec2(0, 0);\n\
    \t\t}\n\t\tconstexpr Vec2() : x(0), y(0) {}\n\t\tconstexpr Vec2(LD _x, LD _y)\
    \ : x(_x), y(_y) {}\n\t\tVec2(LD rad) : x(cos(rad)), y(sin(rad)) {}\n\t\tconstexpr\
    \ bool operator==(const Vec2& v) const {\n\t\t\treturn Equal(x, v.x) && Equal(y,\
    \ v.y);\n\t\t}\n\t\tconstexpr bool operator!=(const Vec2& v) const {\n\t\t\treturn\
    \ !(*this == v);\n\t\t}\n\t\tconstexpr bool operator<(const Vec2& v) const {\n\
    \t\t\treturn x < v.x - EPS && y < v.y - EPS;\n\t\t}\n\t\tconstexpr bool operator<=(const\
    \ Vec2& v) const {\n\t\t\treturn x < v.x + EPS && y < v.y + EPS;\n\t\t}\n\t\t\
    constexpr Vec2 operator+() const {\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr\
    \ Vec2 operator-() const {\n\t\t\treturn {-x, -y};\n\t\t}\n\t\tconstexpr Vec2\
    \ operator+(const Vec2& v) const {\n\t\t\treturn Vec2(*this) += v;\n\t\t}\n\t\t\
    constexpr Vec2 operator-(const Vec2& v) const {\n\t\t\treturn Vec2(*this) -= v;\n\
    \t\t}\n\t\tconstexpr Vec2 operator*(const Vec2& v) const {\n\t\t\treturn Vec2(*this)\
    \ *= v;\n\t\t}\n\t\tconstexpr Vec2 operator/(const Vec2& v) const {\n\t\t\treturn\
    \ Vec2(*this) /= v;\n\t\t}\n\t\tconstexpr Vec2 operator+(LD n) const {\n\t\t\t\
    return Vec2(*this) += Vec2(n, n);\n\t\t}\n\t\tconstexpr Vec2 operator-(LD n) const\
    \ {\n\t\t\treturn Vec2(*this) -= Vec2(n, n);\n\t\t}\n\t\tconstexpr Vec2 operator*(LD\
    \ n) const {\n\t\t\treturn Vec2(*this) *= Vec2(n, n);\n\t\t}\n\t\tconstexpr Vec2\
    \ operator/(LD n) const {\n\t\t\treturn Vec2(*this) /= Vec2(n, n);\n\t\t}\n\t\t\
    constexpr Vec2& operator+=(const Vec2& v) {\n\t\t\tx += v.x;\n\t\t\ty += v.y;\n\
    \t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2& operator-=(const Vec2& v) {\n\t\
    \t\tx -= v.x;\n\t\t\ty -= v.y;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2&\
    \ operator*=(const Vec2& v) {\n\t\t\tx *= v.x;\n\t\t\ty *= v.y;\n\t\t\treturn\
    \ *this;\n\t\t}\n\t\tconstexpr Vec2& operator/=(const Vec2& v) {\n\t\t\tx /= v.x;\n\
    \t\t\ty /= v.y;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2& operator+=(LD\
    \ n) {\n\t\t\tx += n;\n\t\t\tx += n;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr\
    \ Vec2& operator-=(LD n) {\n\t\t\tx -= n;\n\t\t\tx -= n;\n\t\t\treturn *this;\n\
    \t\t}\n\t\tconstexpr Vec2& operator*=(LD n) {\n\t\t\tx *= n;\n\t\t\tx *= n;\n\t\
    \t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2& operator/=(LD n) {\n\t\t\tx /= n;\n\
    \t\t\tx /= n;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr LD operator[](size_t\
    \ i) const {\n\t\t\treturn i == 0 ? x : i == 1 ? y : 0;\n\t\t}\n\t\tLD manhattan(const\
    \ Vec2& v) const {\n\t\t\treturn std::abs(x - v.x) + std::abs(y - v.y);\n\t\t\
    }\n\t\ttemplate <class Shape2DType> LD distance(const Shape2DType& shape) const\
    \ {\n\t\t\treturn Geometric::distance(*this, shape);\n\t\t}\n\t\ttemplate <class\
    \ Shape2DType> bool intersects(const Shape2DType& shape) const {\n\t\t\treturn\
    \ Geometric::intersect(*this, shape);\n\t\t}\n\t\ttemplate <class Shape2DType>\
    \ bool tangent(const Shape2DType& shape) const {\n\t\t\treturn Geometric::tangent(*this,\
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
    \ v.y;\n\t\t}\n\t};\n\n}  // namespace Geometric\n"
  code: "#pragma once\n#include \"./Geometric.hpp\"\n#include <iostream>\n#include\
    \ <cmath>\n\nnamespace Geometric {\n\n\tstruct Vec2 {\n\t\tLD x, y;\n\t\tstatic\
    \ constexpr bool compare_x(const Vec2& v1, const Vec2& v2) {\n\t\t\treturn v1.x\
    \ < v2.x;\n\t\t}\n\t\tstatic constexpr bool compare_y(const Vec2& v1, const Vec2&\
    \ v2) {\n\t\t\treturn v1.y < v2.y;\n\t\t}\n\t\tstatic constexpr bool compare_xy(const\
    \ Vec2& v1, const Vec2& v2) {\n\t\t\treturn make_pair(v1.x, v1.y) < make_pair(v2.x,\
    \ v2.y);\n\t\t}\n\t\tstatic constexpr bool compare_yx(const Vec2& v1, const Vec2&\
    \ v2) {\n\t\t\treturn make_pair(v1.y, v1.x) < make_pair(v2.y, v2.x);\n\t\t}\n\t\
    \tstatic constexpr Vec2 zero() {\n\t\t\treturn Vec2(0, 0);\n\t\t}\n\t\tconstexpr\
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
    \ shape);\n\t\t}\n\t\ttemplate <class Shape2DType> bool tangent(const Shape2DType&\
    \ shape) const {\n\t\t\treturn Geometric::tangent(*this, shape);\n\t\t}\n\t\t\
    constexpr LD length_square() const {\n\t\t\treturn dot(*this);\n\t\t}\n\t\tLD\
    \ length() const {\n\t\t\treturn sqrt(length_square());\n\t\t}\n\t\t// \u5185\u7A4D\
    \n\t\tconstexpr LD dot(const Vec2& v) const {\n\t\t\treturn x * v.x + y * v.y;\n\
    \t\t}\n\t\t// \u5916\u7A4D\n\t\tconstexpr LD cross(const Vec2& v) const {\n\t\t\
    \treturn x * v.y - y * v.x;\n\t\t}\n\t\t// \u6B63\u898F\u5316\uFF08\u9577\u3055\
    \u30921\u306B\u3057\u305F\uFF09\u30D9\u30AF\u30C8\u30EB\n\t\tVec2 normalized()\
    \ const {\n\t\t\treturn *this / length();\n\t\t}\n\t\t// \u539F\u70B9\u4E2D\u5FC3\
    \u306B rad \u56DE\u8EE2\u3057\u305F\u5EA7\u6A19\n\t\tVec2 rotation(LD rad) const\
    \ {\n\t\t\tLD c = cos(rad), s = sin(rad);\n\t\t\treturn {x * c - y * s, x * s\
    \ + y * c};\n\t\t}\n\t\t// \u539F\u70B9\u4E2D\u5FC3\u306E\u5186\u4E0A\u306B\u4E57\
    \u3063\u3066\u3044\u308B\u3068\u3057\u305F\u3068\u304D\u306E\u504F\u89D2\n\t\t\
    LD angle() const {\n\t\t\treturn atan2(y, x);\n\t\t}\n\t\t// \u6B63\u5C04\u5F71\
    \n\t\tVec2 projection(const Line& l) const;\n\t\t// \u93E1\u6620\u5909\u63DB\n\
    \t\tVec2 reflection(const Line& l) const;\n\t\tconstexpr Vec2 rotate90() const\
    \ {\n\t\t\treturn {y, -x};\n\t\t}\n\t\tconstexpr Vec2 rotate180() const {\n\t\t\
    \treturn {-x, -y};\n\t\t}\n\t\tconstexpr Vec2 rotate270() const {\n\t\t\treturn\
    \ {-y, x};\n\t\t}\n\t\tfriend ostream& operator<<(ostream& os, const Vec2& v)\
    \ {\n\t\t\treturn os << '(' << v.x << \", \" << v.y << ')';\n\t\t}\n\t\tfriend\
    \ istream& operator>>(istream& is, Vec2& v) {\n\t\t\treturn is >> v.x >> v.y;\n\
    \t\t}\n\t};\n\n}  // namespace Geometric\n"
  dependsOn:
  - Geometry/Geometric.hpp
  isVerificationFile: false
  path: Geometry/Vec2.hpp
  requiredBy:
  - Geometry/ClosestPair.cpp
  - Geometry/Geometric.cpp
  - Geometry/Triangle.hpp
  - Geometry/Circle.hpp
  - Geometry/Line.hpp
  - Geometry/Rect.hpp
  - Geometry/Polygon.hpp
  timestamp: '2020-11-03 17:35:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Geometric_iSP.test.cpp
  - test/Geometric_is_convex.test.cpp
  - test/Geometric_convex_hull.test.cpp
  - test/Geometric_segment_intersection.test.cpp
  - test/Geometric_segment_distance.test.cpp
  - test/Geometric_area_of_intersection_between_circle_and_polygon.test.cpp
  - test/Geometric_cross_points_between_line_and_circle.test.cpp
  - test/Geometric_common_tangent.test.cpp
  - test/Geometric_cross_point_of_circles.test.cpp
  - test/Geometric_cirnnumscribed_circle.test.cpp
  - test/Geometric_tangent_to_circle.test.cpp
  - test/Geometric_is_parallel_is_orthogonal.test.cpp
  - test/Geometric_projection.test.cpp
  - test/Geometric_closest_pair.test.cpp
  - test/Geometric_area_of_intersection_between_two_circles.test.cpp
  - test/Geometric_polygon_diameter.test.cpp
  - test/Geometric_reflection.test.cpp
  - test/Geometric_incircle_of_triangle.test.cpp
  - test/Geometric_polygon_cut.test.cpp
  - test/Geometric_dot_cross.test.cpp
  - test/Geometric_line_intersection.test.cpp
  - test/Geometric_polygon_point_containment.test.cpp
documentation_of: Geometry/Vec2.hpp
layout: document
redirect_from:
- /library/Geometry/Vec2.hpp
- /library/Geometry/Vec2.hpp.html
title: Geometry/Vec2.hpp
---
