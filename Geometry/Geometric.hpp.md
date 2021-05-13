---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Geometry/Circle.hpp
    title: Geometry/Circle.hpp
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
  - icon: ':heavy_check_mark:'
    path: Geometry/Vec2.hpp
    title: Geometry/Vec2.hpp
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
    \ tangent_to_circle(const Circle& c, const Vec2& v);\n}  // namespace Geometric\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\
    #include <optional>\n\nnamespace Geometric {\n\n\tusing LD = long double;\n\t\
    constexpr long double PI = 3.14159265358979323846, EPS = 1e-12;\n\n\t// a > 0\
    \ : +1\n\t// a = 0 :  0\n\t// a < 0 : -1\n\tconstexpr int sgn(LD a);\n\tconstexpr\
    \ LD deg_to_rad(LD deg);\n\tconstexpr LD rad_to_deg(LD rad);\n\n\tstruct Vec2;\n\
    \tstruct Line;\n\tstruct Segment;\n\tstruct Rect;\n\tstruct Circle;\n\tstruct\
    \ Polygon;\n\n\t// AB \u304B\u3089\u898B\u3066 BC \u304C\u5DE6\u306B\u66F2\u304C\
    \u308B   : +1\n\t// AB \u304B\u3089\u898B\u3066 BC \u304C\u53F3\u306B\u66F2\u304C\
    \u308B   : -1\n\t// ABC, CBA \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\u306B\u4E26\
    \u3076 : +2\n\t// ACB, BCA \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\u306B\u4E26\
    \u3076 :  0\n\t// BAC, CAB \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\u306B\u4E26\
    \u3076 : -2\n\tint iSP(const Vec2& a, const Vec2& b, const Vec2& c);\n\n\t// \u2220\
    ABC \u304C\u92ED\u89D2 : 0, \u76F4\u89D2 : 1, \u920D\u89D2 : 2\n\tint angle_type(const\
    \ Vec2& a, const Vec2& b, const Vec2& c);\n\n\t// \u2220ABC \u306E\u5024 (radian)\n\
    \tLD angle(const Vec2& a, const Vec2& b, const Vec2& c);\n\n\t// \u8DDD\u96E2\n\
    \tLD distance(const Vec2& v1, const Vec2& v2);\n\tLD distance(const Vec2& v, const\
    \ Line& l);\n\tLD distance(const Vec2& v, const Segment& s);\n\tLD distance(const\
    \ Vec2& v, const Circle& c);\n\tLD distance(const Line& l, const Vec2& v);\n\t\
    LD distance(const Line& l1, const Line& l2);\n\tLD distance(const Segment& s,\
    \ const Vec2& v);\n\tLD distance(const Segment& s1, const Segment& s2);\n\tLD\
    \ distance(const Circle& c, const Vec2& v);\n\tLD distance(const Circle& c1, const\
    \ Circle& c2);\n\n\t// \u4EA4\u5DEE\u5224\u5B9A \uFF08\u5185\u5305\u3057\u3066\
    \u3044\u308B\u3068\u304D\u3082 true \u3092\u8FD4\u3059\uFF09\n\tbool intersect(const\
    \ Vec2& v1, const Vec2& v2);\n\tbool intersect(const Vec2& v, const Line& l);\n\
    \tbool intersect(const Vec2& v, const Segment& l);\n\tbool intersect(const Vec2&\
    \ v, const Circle& c);\n\tbool intersect(const Vec2& v, const Rect& r);\n\tbool\
    \ intersect(const Vec2& v, const Polygon& p);\n\tbool intersect(const Line& l,\
    \ const Vec2& v);\n\tbool intersect(const Line& l1, const Line& l2);\n\tbool intersect(const\
    \ Line& l, const Circle& c);\n\tbool intersect(const Segment& l, const Vec2& v);\n\
    \tbool intersect(const Segment& s1, const Segment& s2);\n\tbool intersect(const\
    \ Segment& s, const Circle& c);\n\tbool intersect(const Circle& c, const Vec2&\
    \ v);\n\tbool intersect(const Circle& c, const Line& l);\n\tbool intersect(const\
    \ Circle& c, const Segment& s);\n\tbool intersect(const Circle& c1, const Circle&\
    \ c2);\n\tbool intersect(const Circle& c, const Rect& r);\n\tbool intersect(const\
    \ Rect& r, const Vec2& v);\n\tbool intersect(const Rect& r1, const Rect& r2);\n\
    \tbool intersect(const Rect& r, const Circle& c);\n\tbool intersect(const Polygon&\
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
    \ tangent_to_circle(const Circle& c, const Vec2& v);\n}  // namespace Geometric\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Geometric.hpp
  requiredBy:
  - Geometry/Circle.hpp
  - Geometry/Geometric.cpp
  - Geometry/Vec2.hpp
  - Geometry/closest_pair.cpp
  - Geometry/Triangle.hpp
  - Geometry/common_tangent.cpp
  - Geometry/Polygon.hpp
  - Geometry/Rect.hpp
  - Geometry/area_of_intersection.cpp
  - Geometry/Line.hpp
  timestamp: '2021-03-21 09:12:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Geometric_polygon_diameter.test.cpp
  - test/Geometric_area_of_intersection_between_circle_and_polygon.test.cpp
  - test/Geometric_cirnnumscribed_circle.test.cpp
  - test/Geometric_reflection.test.cpp
  - test/Geometric_segment_distance.test.cpp
  - test/Geometric_is_convex.test.cpp
  - test/Geometric_dot_cross.test.cpp
  - test/Geometric_tangent_to_circle.test.cpp
  - test/Geometric_area_of_intersection_between_two_circles.test.cpp
  - test/Geometric_convex_hull.test.cpp
  - test/Geometric_incircle_of_triangle.test.cpp
  - test/Geometric_is_parallel_is_orthogonal.test.cpp
  - test/Geometric_closest_pair.test.cpp
  - test/Geometric_iSP.test.cpp
  - test/Geometric_projection.test.cpp
  - test/Geometric_line_intersection.test.cpp
  - test/Geometric_cross_point_of_circles.test.cpp
  - test/Geometric_segment_intersection.test.cpp
  - test/Geometric_common_tangent.test.cpp
  - test/Geometric_polygon_cut.test.cpp
  - test/Geometric_cross_points_between_line_and_circle.test.cpp
  - test/Geometric_polygon_point_containment.test.cpp
documentation_of: Geometry/Geometric.hpp
layout: document
redirect_from:
- /library/Geometry/Geometric.hpp
- /library/Geometry/Geometric.hpp.html
title: Geometry/Geometric.hpp
---
