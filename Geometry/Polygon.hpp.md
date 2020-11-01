---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry/Geometric.hpp
    title: Geometry/Geometric.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/Vec2.hpp
    title: Geometry/Vec2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Geometric_is_convex.test.cpp
    title: test/Geometric_is_convex.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Geometry/Geometric.hpp\"\n#include <iostream>\n#include\
    \ <vector>\n#include <algorithm>\nusing namespace std;\n\nnamespace Geometric\
    \ {\n\n\tusing LD = long double;\n\tconstexpr long double PI = 3.14159265358979323846,\
    \ EPS = 1e-12;\n\n\tconstexpr bool Equal(LD a, LD b);\n\t// a > 0 : +1\n\t// a\
    \ = 0 :  0\n\t// a < 0 : -1\n\tconstexpr int sgn(LD a);\n\tconstexpr LD deg_to_rad(LD\
    \ deg);\n\tconstexpr LD rad_to_deg(LD rad);\n\n\tstruct Vec2;\n\tstruct Line;\n\
    \tstruct Segment;\n\tstruct Rect;\n\tstruct Circle;\n\tstruct Polygon;\n\n\t//\
    \ AB \u304B\u3089\u898B\u3066 BC \u304C\u5DE6\u306B\u66F2\u304C\u308B   : +1\n\
    \t// AB \u304B\u3089\u898B\u3066 BC \u304C\u53F3\u306B\u66F2\u304C\u308B   : -1\n\
    \t// ABC, CBA \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\u306B\u4E26\u3076 : +2\n\
    \t// ACB, BCA \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\u306B\u4E26\u3076 : \
    \ 0\n\t// BAC, CAB \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\u306B\u4E26\u3076\
    \ : -2\n\tint iSP(const Vec2& a, const Vec2& b, const Vec2& c);\n\n\t// \u89D2\
    ABC \u304C\u92ED\u89D2 : 0, \u76F4\u89D2 : 1, \u920D\u89D2 : 2\n\tint angle_type(const\
    \ Vec2& a, const Vec2& b, const Vec2& c);\n\n\t// \u8DDD\u96E2\n\tLD distance(const\
    \ Vec2& v1, const Vec2& v2);\n\tLD distance(const Vec2& v, const Line& l);\n\t\
    LD distance(const Vec2& v, const Segment& s);\n\tLD distance(const Vec2& v, const\
    \ Circle& c);\n\tLD distance(const Line& l, const Vec2& v);\n\tLD distance(const\
    \ Line& l1, const Line& l2);\n\tLD distance(const Segment& s, const Vec2& v);\n\
    \tLD distance(const Segment& s1, const Segment& s2);\n\tLD distance(const Circle&\
    \ c, const Vec2& v);\n\tLD distance(const Circle& c1, const Circle& c2);\n\n\t\
    // \u4EA4\u5DEE\u5224\u5B9A \uFF08\u5185\u5305\u3057\u3066\u3044\u308B\u3068\u304D\
    \u3082 true \u3092\u8FD4\u3059\uFF09\n\tbool intersect(const Vec2& v1, const Vec2&\
    \ v2);\n\tbool intersect(const Vec2& v, const Line& l);\n\tbool intersect(const\
    \ Vec2& v, const Segment& l);\n\tbool intersect(const Vec2& v, const Circle& c);\n\
    \tbool intersect(const Vec2& v, const Rect& r);\n\tbool intersect(const Line&\
    \ l, const Vec2& v);\n\tbool intersect(const Line& l1, const Line& l2);\n\tbool\
    \ intersect(const Line& l, const Circle& c);\n\tbool intersect(const Segment&\
    \ l, const Vec2& v);\n\tbool intersect(const Segment& s1, const Segment& s2);\n\
    \tbool intersect(const Segment& s, const Circle& c);\n\tbool intersect(const Circle&\
    \ c, const Vec2& v);\n\tbool intersect(const Circle& c, const Line& l);\n\tbool\
    \ intersect(const Circle& c, const Segment& s);\n\tbool intersect(const Circle&\
    \ c1, const Circle& c2);\n\tbool intersect(const Circle& c, const Rect& r);\n\t\
    bool intersect(const Rect& r1, const Rect& r2);\n\tbool intersect(const Rect&\
    \ r, const Circle& c);\n\n}  // namespace Geometric\n#line 4 \"Geometry/Vec2.hpp\"\
    \n#include <cmath>\n\nnamespace Geometric {\n\n\tstruct Vec2 {\n\t\tLD x, y;\n\
    \t\tconstexpr Vec2() : x(0), y(0) {}\n\t\tconstexpr Vec2(LD _x, LD _y) : x(_x),\
    \ y(_y) {}\n\t\tVec2(LD rad) : x(cos(rad)), y(sin(rad)) {}\n\t\tconstexpr bool\
    \ operator==(const Vec2& v) const {\n\t\t\treturn Equal(x, v.x) && Equal(y, v.y);\n\
    \t\t}\n\t\tconstexpr bool operator!=(const Vec2& v) const {\n\t\t\treturn !(*this\
    \ == v);\n\t\t}\n\t\tconstexpr bool operator<(const Vec2& v) const {\n\t\t\treturn\
    \ x < v.x - EPS && y < v.y - EPS;\n\t\t}\n\t\tconstexpr bool operator<=(const\
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
    \ Geometric::intersect(*this, shape);\n\t\t}\n\t\tconstexpr LD length_square()\
    \ const {\n\t\t\treturn dot(*this);\n\t\t}\n\t\tLD length() const {\n\t\t\treturn\
    \ sqrt(length_square());\n\t\t}\n\t\t// \u5185\u7A4D\n\t\tconstexpr LD dot(const\
    \ Vec2& v) const {\n\t\t\treturn x * v.x + y * v.y;\n\t\t}\n\t\t// \u5916\u7A4D\
    \n\t\tconstexpr LD cross(const Vec2& v) const {\n\t\t\treturn x * v.y - y * v.x;\n\
    \t\t}\n\t\t// \u6B63\u898F\u5316\uFF08\u9577\u3055\u30921\u306B\u3057\u305F\uFF09\
    \u30D9\u30AF\u30C8\u30EB\n\t\tVec2 normalized() const {\n\t\t\treturn *this /\
    \ length();\n\t\t}\n\t\t// \u539F\u70B9\u4E2D\u5FC3\u306B rad \u56DE\u8EE2\u3057\
    \u305F\u5EA7\u6A19\n\t\tVec2 rotation(LD rad) const {\n\t\t\tLD c = cos(rad),\
    \ s = sin(rad);\n\t\t\treturn {x * c - y * s, x * s + y * c};\n\t\t}\n\t\t// \u539F\
    \u70B9\u4E2D\u5FC3\u306E\u5186\u4E0A\u306B\u4E57\u3063\u3066\u3044\u308B\u3068\
    \u3057\u305F\u3068\u304D\u306E\u504F\u89D2\n\t\tLD angle() const {\n\t\t\treturn\
    \ atan2(y, x);\n\t\t}\n\t\t// \u6B63\u5C04\u5F71\n\t\tVec2 projection(const Line&\
    \ l);\n\t\t// \u93E1\u6620\u5909\u63DB\n\t\tVec2 reflection(const Line& l);\n\t\
    \tconstexpr Vec2 rotate90() const {\n\t\t\treturn {y, -x};\n\t\t}\n\t\tconstexpr\
    \ Vec2 rotate180() const {\n\t\t\treturn {-x, -y};\n\t\t}\n\t\tconstexpr Vec2\
    \ rotate270() const {\n\t\t\treturn {-y, x};\n\t\t}\n\t\tfriend ostream& operator<<(ostream&\
    \ os, const Vec2& v) {\n\t\t\treturn os << '(' << v.x << \", \" << v.y << ')';\n\
    \t\t}\n\t\tfriend istream& operator>>(istream& is, Vec2& v) {\n\t\t\treturn is\
    \ >> v.x >> v.y;\n\t\t}\n\t};\n\n}  // namespace Geometric\n#line 6 \"Geometry/Polygon.hpp\"\
    \nusing namespace std;\n\nnamespace Geometric {\n\n\tstruct Polygon {\n\tprivate:\n\
    \t\tvector<Vec2> p;\n\n\tpublic:\n\t\tPolygon(const vector<Vec2>& _p) : p(_p)\
    \ {}\n\t\tsize_t size() const {\n\t\t\treturn p.size();\n\t\t}\n\t\tLD area()\
    \ const {\n\t\t\tLD ans = 0;\n\t\t\tfor (size_t i = 0; i < size(); ++i) {\n\t\t\
    \t\tsize_t next = i < size() - 1 ? i : 0;\n\t\t\t\tans += abs(p[i].x * p[next].y\
    \ - p[next].x * p[i].y);\n\t\t\t}\n\t\t\treturn ans / 2;\n\t\t}\n\t\t// \u53CD\
    \u6642\u8A08\u56DE\u308A\n\t\tbool is_convex() const {\n\t\t\tif (size() < 3)\
    \ {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t\tfor (size_t i = 0; i < size(); ++i)\
    \ {\n\t\t\t\tsize_t prev = i != 0 ? i - 1 : size() - 1;\n\t\t\t\tsize_t next =\
    \ i != size() - 1 ? i + 1 : 0;\n\t\t\t\tif (iSP(p[prev], p[i], p[next]) == -1)\
    \ {\n\t\t\t\t\treturn false;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn true;\n\t\t}\n\t\
    };\n\n}  // namespace Geometric\n"
  code: "#pragma once\n#include \"./Geometric.hpp\"\n#include \"./Vec2.hpp\"\n#include\
    \ <iostream>\n#include <vector>\nusing namespace std;\n\nnamespace Geometric {\n\
    \n\tstruct Polygon {\n\tprivate:\n\t\tvector<Vec2> p;\n\n\tpublic:\n\t\tPolygon(const\
    \ vector<Vec2>& _p) : p(_p) {}\n\t\tsize_t size() const {\n\t\t\treturn p.size();\n\
    \t\t}\n\t\tLD area() const {\n\t\t\tLD ans = 0;\n\t\t\tfor (size_t i = 0; i <\
    \ size(); ++i) {\n\t\t\t\tsize_t next = i < size() - 1 ? i : 0;\n\t\t\t\tans +=\
    \ abs(p[i].x * p[next].y - p[next].x * p[i].y);\n\t\t\t}\n\t\t\treturn ans / 2;\n\
    \t\t}\n\t\t// \u53CD\u6642\u8A08\u56DE\u308A\n\t\tbool is_convex() const {\n\t\
    \t\tif (size() < 3) {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t\tfor (size_t i = 0;\
    \ i < size(); ++i) {\n\t\t\t\tsize_t prev = i != 0 ? i - 1 : size() - 1;\n\t\t\
    \t\tsize_t next = i != size() - 1 ? i + 1 : 0;\n\t\t\t\tif (iSP(p[prev], p[i],\
    \ p[next]) == -1) {\n\t\t\t\t\treturn false;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ true;\n\t\t}\n\t};\n\n}  // namespace Geometric"
  dependsOn:
  - Geometry/Geometric.hpp
  - Geometry/Vec2.hpp
  isVerificationFile: false
  path: Geometry/Polygon.hpp
  requiredBy: []
  timestamp: '2020-11-01 17:39:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Geometric_is_convex.test.cpp
documentation_of: Geometry/Polygon.hpp
layout: document
redirect_from:
- /library/Geometry/Polygon.hpp
- /library/Geometry/Polygon.hpp.html
title: Geometry/Polygon.hpp
---
