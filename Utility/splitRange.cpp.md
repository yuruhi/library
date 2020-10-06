---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Utility/Range.cpp
    title: Utility/Range.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Range.cpp\"\n#include <limits>\n#include <algorithm>\n\
    #include <iostream>\n#include <cassert>\nusing namespace std;\n\ntemplate <class\
    \ T> struct Range {\n\tstatic constexpr Range nil() {\n\t\treturn {numeric_limits<T>::min(),\
    \ numeric_limits<T>::min()};\n\t}\n\tT x, y;  // [x, y]\n\tconstexpr Range() :\
    \ x(0), y(0){};\n\tconstexpr Range(T _x, T _y, bool exclude_end = false) : x(_x),\
    \ y(_y - exclude_end) {\n\t\tassert(x <= y);\n\t}\n\tconstexpr Range(const Range&\
    \ _r, bool exclude_end = false) : x(_r.x), y(_r.y - exclude_end) {\n\t\tassert(x\
    \ <= y);\n\t}\n\tconstexpr operator bool() const {\n\t\treturn *this != nil();\n\
    \t}\n\tconstexpr bool operator==(const Range& r) const {\n\t\treturn x == r.x\
    \ && y == r.y;\n\t}\n\tconstexpr bool operator!=(const Range& r) const {\n\t\t\
    return x != r.x || y != r.y;\n\t}\n\tconstexpr bool operator<(const Range& r)\
    \ const {\n\t\treturn to_pair() < r.to_pair();\n\t}\n\tconstexpr bool operator<=(const\
    \ Range& r) const {\n\t\treturn to_pair() <= r.to_pair();\n\t}\n\tconstexpr bool\
    \ operator>(const Range& r) const {\n\t\treturn to_pair() > r.to_pair();\n\t}\n\
    \tconstexpr bool operator>=(const Range& r) const {\n\t\treturn to_pair() >= r.to_pair();\n\
    \t}\n\tconstexpr Range& operator<<=(const T& n) {\n\t\tx -= n;\n\t\ty -= n;\n\t\
    \treturn *this;\n\t}\n\tconstexpr Range& operator>>=(const T& n) {\n\t\tx += n;\n\
    \t\ty += n;\n\t\treturn *this;\n\t}\n\tconstexpr Range& operator*=(const T& n)\
    \ {\n\t\tx *= n;\n\t\ty *= n;\n\t\treturn *this;\n\t}\n\tconstexpr Range operator<<(const\
    \ T& n) const {\n\t\treturn Range(*this) <<= n;\n\t}\n\tconstexpr Range operator>>(const\
    \ T& n) const {\n\t\treturn Range(*this) >>= n;\n\t}\n\tconstexpr Range operator*(const\
    \ T& n) const {\n\t\treturn Range(*this) *= n;\n\t}\n\tconstexpr Range& operator&=(const\
    \ Range& r) {\n\t\tif (intersects(r)) {\n\t\t\tx = std::max(x, r.x);\n\t\t\ty\
    \ = std::min(y, r.y);\n\t\t} else {\n\t\t\t*this = nil();\n\t\t}\n\t\treturn *this;\n\
    \t}\n\tconstexpr Range& operator|=(const Range& r) {\n\t\tif (intersects(r) ||\
    \ adjacent(r)) {\n\t\t\tx = std::min(x, r.x);\n\t\t\ty = std::max(y, r.y);\n\t\
    \t} else {\n\t\t\t*this = nil();\n\t\t}\n\t\treturn *this;\n\t}\n\tconstexpr Range\
    \ operator&(const Range& r) const {\n\t\treturn Range(*this) &= r;\n\t}\n\tconstexpr\
    \ Range operator|(const Range& r) const {\n\t\treturn Range(*this) |= r;\n\t}\n\
    \tconstexpr T operator[](const T& n) const {  // 0-indexed\n\t\tassert(x + n <=\
    \ y);\n\t\treturn x + n;\n\t}\n\tconstexpr Range operator[](const Range& n) const\
    \ {\n\t\treturn Range(operator[](n.x), operator[](n.y));\n\t}\n\tconstexpr pair<T,\
    \ T> to_pair() const {\n\t\treturn make_pair(x, y);\n\t}\n\tconstexpr Range open()\
    \ const {\n\t\treturn Range(x, y + 1);\n\t}\n\tconstexpr bool include(const T&\
    \ n) const {\n\t\treturn x <= n && n <= y;\n\t}\n\tconstexpr bool intersects(const\
    \ Range& r) const {\n\t\treturn std::max(x, r.x) <= std::min(y, r.y);\n\t}\n\t\
    constexpr bool contains(const Range& r) const {\n\t\treturn x <= r.x && r.y <=\
    \ y;\n\t}\n\tconstexpr bool adjacent(const Range& r) const {\n\t\treturn y + 1\
    \ == r.x || r.y + 1 == x;\n\t}\n\tconstexpr T size() const {\n\t\treturn *this\
    \ ? max<T>(0, y - x + 1) : 0;\n\t}\n\tconstexpr T sum() const {\n\t\treturn (x\
    \ + y) * size() / 2;\n\t}\n\tfriend ostream& operator<<(ostream& os, const Range&\
    \ r) {\n\t\treturn (r == Range::nil()) ? (os << \"[nil]\") : (os << '[' << r.x\
    \ << \", \" << r.y << ']');\n\t}\n\tfriend istream& operator>>(istream& is, Range&\
    \ r) {\n\t\treturn is >> r.x >> r.y;\n\t}\n};\ntemplate <class T, class U> constexpr\
    \ Range<T> equal_range(const U& a, const Range<T>& r) {\n\tauto L = lower_bound(a.begin(),\
    \ a.end(), r.x) - a.begin();\n\tauto R = upper_bound(a.begin(), a.end(), r.y)\
    \ - a.begin();\n\treturn L == R ? Range<T>::nil() : Range<T>(L, R, true);\n}\n\
    #line 3 \"Utility/splitRange.cpp\"\n#include <vector>\nusing namespace std;\n\n\
    vector<Range> split(const vector<int>& v) {\n\tint n = v.size();\n\tvector<Range>\
    \ res;\n\tif (n <= 1) {\n\t\tres.emplace_back(0, n - 1);\n\t\treturn res;\n\t\
    }\n\tint x = 0;\n\tbool flag = v[0] < v[1];\n\tfor (int i = 0; i < n; i++) {\n\
    \t\tif (i == n - 1 || !((flag && v[i] < v[i + 1]) || (!flag && v[i] > v[i + 1])))\
    \ {\n\t\t\tflag = flag ? false : true;\n\t\t\tres.emplace_back(x, i);\n\t\t\t\
    x = i;\n\t\t}\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n#include \"./Range.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nvector<Range> split(const vector<int>& v) {\n\tint n = v.size();\n\t\
    vector<Range> res;\n\tif (n <= 1) {\n\t\tres.emplace_back(0, n - 1);\n\t\treturn\
    \ res;\n\t}\n\tint x = 0;\n\tbool flag = v[0] < v[1];\n\tfor (int i = 0; i < n;\
    \ i++) {\n\t\tif (i == n - 1 || !((flag && v[i] < v[i + 1]) || (!flag && v[i]\
    \ > v[i + 1]))) {\n\t\t\tflag = flag ? false : true;\n\t\t\tres.emplace_back(x,\
    \ i);\n\t\t\tx = i;\n\t\t}\n\t}\n\treturn res;\n}"
  dependsOn:
  - Utility/Range.cpp
  isVerificationFile: false
  path: Utility/splitRange.cpp
  requiredBy: []
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/splitRange.cpp
layout: document
redirect_from:
- /library/Utility/splitRange.cpp
- /library/Utility/splitRange.cpp.html
title: Utility/splitRange.cpp
---
