---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry/Geometric.hpp
    title: Geometry/Geometric.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/Line.hpp
    title: Geometry/Line.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/Vec2.hpp
    title: Geometry/Vec2.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Geometry/Geometric.cpp
    title: Geometry/Geometric.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/area_of_intersection.cpp
    title: Geometry/area_of_intersection.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/closest_pair.cpp
    title: Geometry/closest_pair.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/common_tangent.cpp
    title: Geometry/common_tangent.cpp
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Geometry/Geometric.hpp\"\n#include <iostream>\n#include\
    \ <vector>\n#include <algorithm>\n#include <optional>\n\nnamespace Geometric {\n\
    \n\tusing LD = long double;\n\tconstexpr long double PI = 3.14159265358979323846,\
    \ EPS = 1e-12;\n\n\t// a > 0 : +1\n\t// a = 0 :  0\n\t// a < 0 : -1\n\tconstexpr\
    \ int sgn(LD a);\n\tconstexpr LD deg_to_rad(LD deg);\n\tconstexpr LD rad_to_deg(LD\
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
    \ r, const Vec2& v);\n\tbool intersect(const Rect& r1, const Rect& r2);\n\tbool\
    \ intersect(const Rect& r, const Circle& c);\n\tbool intersect(const Polygon&\
    \ p, const Vec2& v);\n\n\t// \u63A5\u3059\u308B\u304B\u5224\u5B9A\n\tbool tangent(const\
    \ Vec2& v1, const Vec2& v2);\n\tbool tangent(const Vec2& v, const Line& l);\n\t\
    bool tangent(const Vec2& v, const Segment& l);\n\tbool tangent(const Vec2& v,\
    \ const Circle& c);\n\tbool tangent(const Vec2& v, const Rect& r);\n\tbool tangent(const\
    \ Vec2& v, const Polygon& p);\n\tbool tangent(const Line& l, const Vec2& v);\n\
    \tbool tangent(const Line& l, const Circle& c);\n\tbool tangent(const Line& l,\
    \ const Rect& r);\n\tbool tangent(const Segment& l, const Vec2& v);\n\tbool tangent(const\
    \ Circle& c, const Vec2& v);\n\tbool tangent(const Circle& c, const Line& l);\n\
    \tbool tangent(const Circle& c1, const Circle& c2);\n\tbool tangent(const Rect&\
    \ r, const Vec2& v);\n\tbool tangent(const Rect& r, const Line& l);\n\tbool tangent(const\
    \ Polygon& p, const Vec2& v);\n\n\t// \u4EA4\u70B9\n\tstd::optional<Vec2> cross_point(const\
    \ Line& l1, const Line& l2);\n\tstd::optional<Vec2> cross_point(const Segment&\
    \ s1, const Segment& s2);\n\n\tstd::vector<Vec2> cross_points(const Line& l, const\
    \ Circle& c);\n\tstd::vector<Vec2> cross_points(const Segment& s, const Circle&\
    \ c);\n\tstd::vector<Vec2> cross_points(const Circle& c, const Line& l);\n\tstd::vector<Vec2>\
    \ cross_points(const Circle& c, const Segment& s);\n\tstd::vector<Vec2> cross_points(const\
    \ Circle& c1, const Circle& c2);\n\n\t// \u5186\u306E\u63A5\u7DDA\n\tstd::vector<Vec2>\
    \ tangent_to_circle(const Circle& c, const Vec2& v);\n}  // namespace Geometric\n\
    #line 4 \"Geometry/Vec2.hpp\"\n#include <utility>\n#include <cmath>\n\nnamespace\
    \ Geometric {\n\n\tstruct Vec2 {\n\t\tLD x, y;\n\t\tstatic constexpr bool compare_x(const\
    \ Vec2& v1, const Vec2& v2) {\n\t\t\treturn v1.x < v2.x;\n\t\t}\n\t\tstatic constexpr\
    \ bool compare_y(const Vec2& v1, const Vec2& v2) {\n\t\t\treturn v1.y < v2.y;\n\
    \t\t}\n\t\tstatic constexpr bool compare_xy(const Vec2& v1, const Vec2& v2) {\n\
    \t\t\treturn std::make_pair(v1.x, v1.y) < std::make_pair(v2.x, v2.y);\n\t\t}\n\
    \t\tstatic constexpr bool compare_yx(const Vec2& v1, const Vec2& v2) {\n\t\t\t\
    return std::make_pair(v1.y, v1.x) < std::make_pair(v2.y, v2.x);\n\t\t}\n\t\tstatic\
    \ constexpr Vec2 zero() {\n\t\t\treturn Vec2(0, 0);\n\t\t}\n\t\tconstexpr Vec2()\
    \ : x(0), y(0) {}\n\t\tconstexpr Vec2(LD _x, LD _y) : x(_x), y(_y) {}\n\t\tVec2(LD\
    \ rad) : x(std::cos(rad)), y(std::sin(rad)) {}\n\t\tconstexpr bool operator==(const\
    \ Vec2& v) const {\n\t\t\treturn sgn(x - v.x) == 0 && sgn(y - v.y) == 0;\n\t\t\
    }\n\t\tconstexpr bool operator!=(const Vec2& v) const {\n\t\t\treturn !(*this\
    \ == v);\n\t\t}\n\t\tconstexpr Vec2 operator+() const {\n\t\t\treturn *this;\n\
    \t\t}\n\t\tconstexpr Vec2 operator-() const {\n\t\t\treturn {-x, -y};\n\t\t}\n\
    \t\tconstexpr Vec2 operator+(const Vec2& v) const {\n\t\t\treturn Vec2(*this)\
    \ += v;\n\t\t}\n\t\tconstexpr Vec2 operator-(const Vec2& v) const {\n\t\t\treturn\
    \ Vec2(*this) -= v;\n\t\t}\n\t\tconstexpr Vec2 operator*(const Vec2& v) const\
    \ {\n\t\t\treturn Vec2(*this) *= v;\n\t\t}\n\t\tconstexpr Vec2 operator/(const\
    \ Vec2& v) const {\n\t\t\treturn Vec2(*this) /= v;\n\t\t}\n\t\tconstexpr Vec2\
    \ operator+(LD n) const {\n\t\t\treturn Vec2(*this) += n;\n\t\t}\n\t\tconstexpr\
    \ Vec2 operator-(LD n) const {\n\t\t\treturn Vec2(*this) -= n;\n\t\t}\n\t\tconstexpr\
    \ Vec2 operator*(LD n) const {\n\t\t\treturn Vec2(*this) *= n;\n\t\t}\n\t\tconstexpr\
    \ Vec2 operator/(LD n) const {\n\t\t\treturn Vec2(*this) /= n;\n\t\t}\n\t\tconstexpr\
    \ Vec2& operator+=(const Vec2& v) {\n\t\t\tx += v.x;\n\t\t\ty += v.y;\n\t\t\t\
    return *this;\n\t\t}\n\t\tconstexpr Vec2& operator-=(const Vec2& v) {\n\t\t\t\
    x -= v.x;\n\t\t\ty -= v.y;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2& operator*=(const\
    \ Vec2& v) {\n\t\t\tx *= v.x;\n\t\t\ty *= v.y;\n\t\t\treturn *this;\n\t\t}\n\t\
    \tconstexpr Vec2& operator/=(const Vec2& v) {\n\t\t\tx /= v.x;\n\t\t\ty /= v.y;\n\
    \t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2& operator+=(LD n) {\n\t\t\tx +=\
    \ n;\n\t\t\ty += n;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr Vec2& operator-=(LD\
    \ n) {\n\t\t\tx -= n;\n\t\t\ty -= n;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr\
    \ Vec2& operator*=(LD n) {\n\t\t\tx *= n;\n\t\t\ty *= n;\n\t\t\treturn *this;\n\
    \t\t}\n\t\tconstexpr Vec2& operator/=(LD n) {\n\t\t\tx /= n;\n\t\t\ty /= n;\n\t\
    \t\treturn *this;\n\t\t}\n\t\tconstexpr LD operator[](size_t i) const {\n\t\t\t\
    return i == 0 ? x : i == 1 ? y : 0;\n\t\t}\n\t\tconstexpr std::pair<LD, LD> pair()\
    \ const {\n\t\t\treturn {x, y};\n\t\t}\n\t\tLD manhattan(const Vec2& v) const\
    \ {\n\t\t\treturn std::abs(x - v.x) + std::abs(y - v.y);\n\t\t}\n\t\tconstexpr\
    \ LD length_square() const {\n\t\t\treturn dot(*this);\n\t\t}\n\t\tLD length()\
    \ const {\n\t\t\treturn std::sqrt(length_square());\n\t\t}\n\t\t// \u5185\u7A4D\
    \n\t\tconstexpr LD dot(const Vec2& v) const {\n\t\t\treturn x * v.x + y * v.y;\n\
    \t\t}\n\t\t// \u5916\u7A4D\n\t\tconstexpr LD cross(const Vec2& v) const {\n\t\t\
    \treturn x * v.y - y * v.x;\n\t\t}\n\t\t// \u6B63\u898F\u5316\uFF08\u9577\u3055\
    \u30921\u306B\u3057\u305F\uFF09\u30D9\u30AF\u30C8\u30EB\n\t\tVec2 normalized()\
    \ const {\n\t\t\treturn *this / length();\n\t\t}\n\t\t// \u539F\u70B9\u4E2D\u5FC3\
    \u306B rad \u56DE\u8EE2\u3057\u305F\u5EA7\u6A19\n\t\tVec2 rotation(LD rad) const\
    \ {\n\t\t\tLD c = std::cos(rad), s = std::sin(rad);\n\t\t\treturn {x * c - y *\
    \ s, x * s + y * c};\n\t\t}\n\t\t// \u539F\u70B9\u4E2D\u5FC3\u306E\u5186\u4E0A\
    \u306B\u4E57\u3063\u3066\u3044\u308B\u3068\u3057\u305F\u3068\u304D\u306E\u504F\
    \u89D2\n\t\tLD angle() const {\n\t\t\treturn std::atan2(y, x);\n\t\t}\n\t\t//\
    \ \u6B63\u5C04\u5F71\n\t\tVec2 projection(const Line& l) const;\n\t\t// \u93E1\
    \u6620\u5909\u63DB\n\t\tVec2 reflection(const Line& l) const;\n\t\tconstexpr Vec2\
    \ rotate90() const {\n\t\t\treturn {y, -x};\n\t\t}\n\t\tconstexpr Vec2 rotate180()\
    \ const {\n\t\t\treturn {-x, -y};\n\t\t}\n\t\tconstexpr Vec2 rotate270() const\
    \ {\n\t\t\treturn {-y, x};\n\t\t}\n\t\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const Vec2& v) {\n\t\t\treturn os << '(' << v.x << \", \" << v.y << ')';\n\
    \t\t}\n\t\tfriend std::istream& operator>>(std::istream& is, Vec2& v) {\n\t\t\t\
    return is >> v.x >> v.y;\n\t\t}\n\t};\n\n}  // namespace Geometric\n#line 6 \"\
    Geometry/Line.hpp\"\n#include <tuple>\n#line 8 \"Geometry/Line.hpp\"\n\nnamespace\
    \ Geometric {\n\n\tnamespace internal {\n\t\tstruct LineBase {\n\t\tprotected:\n\
    \t\t\tconstexpr LineBase() = default;\n\t\t\tconstexpr LineBase(const Vec2& _begin,\
    \ const Vec2& _end)\n\t\t\t    : begin(_begin), end(_end) {}\n\t\t\tconstexpr\
    \ LineBase(LD begin_x, LD begin_y, LD end_x, LD end_y)\n\t\t\t    : begin(begin_x,\
    \ begin_y), end(end_x, end_y) {}\n\n\t\tpublic:\n\t\t\tVec2 begin, end;\n\t\t\t\
    constexpr LineBase operator+(const Vec2& v) {\n\t\t\t\treturn LineBase(*this)\
    \ += v;\n\t\t\t}\n\t\t\tconstexpr LineBase operator-(const Vec2& v) {\n\t\t\t\t\
    return LineBase(*this) -= v;\n\t\t\t}\n\t\t\tconstexpr LineBase& operator+=(const\
    \ Vec2& v) {\n\t\t\t\tbegin += v;\n\t\t\t\tend += v;\n\t\t\t\treturn *this;\n\t\
    \t\t}\n\t\t\tconstexpr LineBase& operator-=(const Vec2& v) {\n\t\t\t\tbegin -=\
    \ v;\n\t\t\t\tend -= v;\n\t\t\t\treturn *this;\n\t\t\t}\n\t\t\tconstexpr Vec2\
    \ vec() const {\n\t\t\t\treturn end - begin;\n\t\t\t}\n\t\t\tconstexpr Vec2 counter_vec()\
    \ const {\n\t\t\t\treturn begin - end;\n\t\t\t}\n\t\t\t// \u5E73\u884C\u5224\u5B9A\
    \n\t\t\tconstexpr bool is_parallel(const LineBase& l) const {\n\t\t\t\treturn\
    \ sgn(vec().cross(l.vec())) == 0;\n\t\t\t}\n\t\t\t// \u76F4\u4EA4\u5224\u5B9A\n\
    \t\t\tconstexpr bool is_orthogonal(const LineBase& l) const {\n\t\t\t\treturn\
    \ sgn(vec().dot(l.vec())) == 0;\n\t\t\t}\n\t\t\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const LineBase& l) {\n\t\t\t\treturn os << '(' << l.begin << \", \" << l.end\
    \ << ')';\n\t\t\t}\n\t\t\tfriend std::istream& operator>>(std::istream& is, LineBase&\
    \ l) {\n\t\t\t\treturn is >> l.begin >> l.end;\n\t\t\t}\n\t\t};\n\t}  // namespace\
    \ internal\n\n\tstruct Line : internal::LineBase {\n\t\tconstexpr Line() = default;\n\
    \t\tconstexpr Line(const Vec2& _begin, const Vec2& _end) : LineBase(_begin, _end)\
    \ {}\n\t\tconstexpr Line(LD begin_x, LD begin_y, LD end_x, LD end_y)\n\t\t   \
    \ : LineBase(begin_x, begin_y, end_x, end_y) {}\n\t\tconstexpr Line(const LineBase&\
    \ l) : LineBase(l) {}\n\t\t// ax + by + c = 0 \u306E\u5F0F\u306B\u5909\u5F62\u3059\
    \u308B\n\t\tstd::tuple<LD, LD, LD> abc() const {\n\t\t\tif (sgn(begin.x - end.x)\
    \ == 0) {\n\t\t\t\treturn {1, 0, -begin.x};\n\t\t\t} else {\n\t\t\t\tLD slope\
    \ = (end.y - begin.y) / (end.x - begin.x);\n\t\t\t\treturn {slope, -1, begin.y\
    \ - begin.x * slope};\n\t\t\t}\n\t\t}\n\t};\n\n\tstruct Segment : internal::LineBase\
    \ {\n\t\tconstexpr Segment() = default;\n\t\tconstexpr Segment(const Vec2& _begin,\
    \ const Vec2& _end) : LineBase(_begin, _end) {}\n\t\tconstexpr Segment(LD begin_x,\
    \ LD begin_y, LD end_x, LD end_y)\n\t\t    : LineBase(begin_x, begin_y, end_x,\
    \ end_y) {}\n\t\tconstexpr Segment(const LineBase& l) : LineBase(l) {}\n\t};\n\
    \n}  // namespace Geometric\n#line 6 \"Geometry/Rect.hpp\"\n\nnamespace Geometric\
    \ {\n\n\tstruct Rect {\n\t\tVec2 pos, size;\n\t\tconstexpr Rect() {}\n\t\tconstexpr\
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
    \ <= 0;\n\t\t}\n\t\tfriend std::ostream& operator<<(std::ostream& os, const Rect&\
    \ r) {\n\t\t\treturn os << '(' << r.pos << ',' << r.size << ')';\n\t\t}\n\t\t\
    friend std::istream& operator>>(std::istream& is, Rect& r) {\n\t\t\treturn is\
    \ >> r.pos >> r.size;\n\t\t}\n\t};\n\n}  // namespace Geometric\n"
  code: "#pragma once\n#include \"./Geometric.hpp\"\n#include \"./Vec2.hpp\"\n#include\
    \ \"./Line.hpp\"\n#include <iostream>\n\nnamespace Geometric {\n\n\tstruct Rect\
    \ {\n\t\tVec2 pos, size;\n\t\tconstexpr Rect() {}\n\t\tconstexpr Rect(LD _w, LD\
    \ _h) : size(_w, _h) {}\n\t\tconstexpr Rect(const Vec2& _size) : size(_size) {}\n\
    \t\tconstexpr Rect(LD _x, LD _y, LD _w, LD _h) : pos(_x, _y), size(_w, _h) {}\n\
    \t\tconstexpr Rect(const Vec2& _pos, const Vec2& _size) : pos(_pos), size(_size)\
    \ {}\n\t\tconstexpr bool operator==(const Rect& r) const {\n\t\t\treturn pos ==\
    \ r.pos && size == r.size;\n\t\t}\n\t\tconstexpr bool operator!=(const Rect& r)\
    \ const {\n\t\t\treturn !(*this == r);\n\t\t}\n\t\tconstexpr Rect operator+(const\
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
    \ <= 0;\n\t\t}\n\t\tfriend std::ostream& operator<<(std::ostream& os, const Rect&\
    \ r) {\n\t\t\treturn os << '(' << r.pos << ',' << r.size << ')';\n\t\t}\n\t\t\
    friend std::istream& operator>>(std::istream& is, Rect& r) {\n\t\t\treturn is\
    \ >> r.pos >> r.size;\n\t\t}\n\t};\n\n}  // namespace Geometric\n"
  dependsOn:
  - Geometry/Geometric.hpp
  - Geometry/Vec2.hpp
  - Geometry/Line.hpp
  isVerificationFile: false
  path: Geometry/Rect.hpp
  requiredBy:
  - Geometry/common_tangent.cpp
  - Geometry/closest_pair.cpp
  - Geometry/area_of_intersection.cpp
  - Geometry/Geometric.cpp
  timestamp: '2021-03-21 09:12:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Geometric_line_intersection.test.cpp
  - test/Geometric_cirnnumscribed_circle.test.cpp
  - test/Geometric_is_convex.test.cpp
  - test/Geometric_projection.test.cpp
  - test/Geometric_tangent_to_circle.test.cpp
  - test/Geometric_dot_cross.test.cpp
  - test/Geometric_cross_points_between_line_and_circle.test.cpp
  - test/Geometric_cross_point_of_circles.test.cpp
  - test/Geometric_segment_intersection.test.cpp
  - test/Geometric_polygon_diameter.test.cpp
  - test/Geometric_reflection.test.cpp
  - test/Geometric_area_of_intersection_between_two_circles.test.cpp
  - test/Geometric_iSP.test.cpp
  - test/Geometric_incircle_of_triangle.test.cpp
  - test/Geometric_polygon_point_containment.test.cpp
  - test/Geometric_area_of_intersection_between_circle_and_polygon.test.cpp
  - test/Geometric_polygon_cut.test.cpp
  - test/Geometric_segment_distance.test.cpp
  - test/Geometric_closest_pair.test.cpp
  - test/Geometric_is_parallel_is_orthogonal.test.cpp
  - test/Geometric_common_tangent.test.cpp
  - test/Geometric_convex_hull.test.cpp
documentation_of: Geometry/Rect.hpp
layout: document
redirect_from:
- /library/Geometry/Rect.hpp
- /library/Geometry/Rect.hpp.html
title: Geometry/Rect.hpp
---
