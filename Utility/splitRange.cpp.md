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
    #include <iostream>\n#include <cassert>\n#include <optional>\nusing namespace\
    \ std;\n\ntemplate <class T> struct Range {\n\tusing value_type = T;\n\tvalue_type\
    \ x, y;  // [x, y]\n\tconstexpr Range() : x(0), y(0) {}\n\tconstexpr Range(value_type\
    \ _x, value_type _y, bool exclude_end = false)\n\t    : x(_x), y(_y - exclude_end)\
    \ {\n\t\tassert(x <= y);\n\t}\n\tconstexpr Range(const Range& _r, bool exclude_end\
    \ = false)\n\t    : x(_r.x), y(_r.y - exclude_end) {\n\t\tassert(x <= y);\n\t\
    }\n\tconstexpr bool operator==(const Range& r) const {\n\t\treturn x == r.x &&\
    \ y == r.y;\n\t}\n\tconstexpr bool operator!=(const Range& r) const {\n\t\treturn\
    \ x != r.x || y != r.y;\n\t}\n\tconstexpr bool operator<(const Range& r) const\
    \ {\n\t\treturn to_pair() < r.to_pair();\n\t}\n\tconstexpr bool operator<=(const\
    \ Range& r) const {\n\t\treturn to_pair() <= r.to_pair();\n\t}\n\tconstexpr bool\
    \ operator>(const Range& r) const {\n\t\treturn to_pair() > r.to_pair();\n\t}\n\
    \tconstexpr bool operator>=(const Range& r) const {\n\t\treturn to_pair() >= r.to_pair();\n\
    \t}\n\tconstexpr Range& operator<<=(const value_type& n) {\n\t\tx -= n;\n\t\t\
    y -= n;\n\t\treturn *this;\n\t}\n\tconstexpr Range& operator>>=(const value_type&\
    \ n) {\n\t\tx += n;\n\t\ty += n;\n\t\treturn *this;\n\t}\n\tconstexpr Range& operator*=(const\
    \ value_type& n) {\n\t\tx *= n;\n\t\ty *= n;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ Range operator<<(const value_type& n) const {\n\t\treturn Range(*this) <<= n;\n\
    \t}\n\tconstexpr Range operator>>(const value_type& n) const {\n\t\treturn Range(*this)\
    \ >>= n;\n\t}\n\tconstexpr Range operator*(const value_type& n) const {\n\t\t\
    return Range(*this) *= n;\n\t}\n\tconstexpr optional<Range> operator&(const Range&\
    \ r) const {\n\t\tif (intersects(r)) {\n\t\t\treturn Range(std::max(x, r.x), std::min(y,\
    \ r.y));\n\t\t} else {\n\t\t\treturn nullopt;\n\t\t}\n\t}\n\tconstexpr optional<Range>\
    \ operator|(const Range& r) const {\n\t\tif (intersects(r) || adjacent(r)) {\n\
    \t\t\treturn Range(std::min(x, r.x), std::max(y, r.y));\n\t\t} else {\n\t\t\t\
    return nullopt;\n\t\t}\n\t}\n\tconstexpr value_type operator[](const value_type&\
    \ n) const {  // 0-indexed\n\t\tassert(x + n <= y);\n\t\treturn x + n;\n\t}\n\t\
    constexpr Range operator[](const Range& n) const {\n\t\treturn Range(operator[](n.x),\
    \ operator[](n.y));\n\t}\n\tconstexpr pair<value_type, value_type> to_pair() const\
    \ {\n\t\treturn make_pair(x, y);\n\t}\n\tconstexpr Range open() const {\n\t\t\
    return Range(x, y + 1);\n\t}\n\tconstexpr bool include(const value_type& n) const\
    \ {\n\t\treturn x <= n && n <= y;\n\t}\n\tconstexpr bool intersects(const Range&\
    \ r) const {\n\t\treturn std::max(x, r.x) <= std::min(y, r.y);\n\t}\n\tconstexpr\
    \ bool contains(const Range& r) const {\n\t\treturn x <= r.x && r.y <= y;\n\t\
    }\n\tconstexpr bool adjacent(const Range& r) const {\n\t\treturn y + 1 == r.x\
    \ || r.y + 1 == x;\n\t}\n\tconstexpr value_type size() const {\n\t\treturn max<value_type>(0,\
    \ y - x + 1);\n\t}\n\tconstexpr value_type sum() const {\n\t\treturn (x + y) *\
    \ size() / 2;\n\t}\n\tfriend ostream& operator<<(ostream& os, const Range& r)\
    \ {\n\t\treturn os << '[' << r.x << \", \" << r.y << ']';\n\t}\n\tfriend istream&\
    \ operator>>(istream& is, Range& r) {\n\t\treturn is >> r.x >> r.y;\n\t}\n};\n\
    template <class T, class U>\nconstexpr optional<Range<T>> equal_range(const U&\
    \ a, const Range<T>& r) {\n\tauto L = lower_bound(a.begin(), a.end(), r.x) - a.begin();\n\
    \tauto R = upper_bound(a.begin(), a.end(), r.y) - a.begin();\n\treturn L == R\
    \ ? nullopt : Range<T>(L, R, true);\n}\n#line 3 \"Utility/splitRange.cpp\"\n#include\
    \ <vector>\nusing namespace std;\n\nvector<Range> split(const vector<int>& v)\
    \ {\n\tint n = v.size();\n\tvector<Range> result;\n\tif (n <= 1) {\n\t\tresult.emplace_back(0,\
    \ n - 1);\n\t\treturn result;\n\t}\n\tint x = 0;\n\tbool flag = v[0] < v[1];\n\
    \tfor (int i = 0; i < n; i++) {\n\t\tif (i == n - 1 || !((flag && v[i] < v[i +\
    \ 1]) || (!flag && v[i] > v[i + 1]))) {\n\t\t\tflag = flag ? false : true;\n\t\
    \t\tresult.emplace_back(x, i);\n\t\t\tx = i;\n\t\t}\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include \"./Range.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nvector<Range> split(const vector<int>& v) {\n\tint n = v.size();\n\t\
    vector<Range> result;\n\tif (n <= 1) {\n\t\tresult.emplace_back(0, n - 1);\n\t\
    \treturn result;\n\t}\n\tint x = 0;\n\tbool flag = v[0] < v[1];\n\tfor (int i\
    \ = 0; i < n; i++) {\n\t\tif (i == n - 1 || !((flag && v[i] < v[i + 1]) || (!flag\
    \ && v[i] > v[i + 1]))) {\n\t\t\tflag = flag ? false : true;\n\t\t\tresult.emplace_back(x,\
    \ i);\n\t\t\tx = i;\n\t\t}\n\t}\n\treturn result;\n}\n"
  dependsOn:
  - Utility/Range.cpp
  isVerificationFile: false
  path: Utility/splitRange.cpp
  requiredBy: []
  timestamp: '2020-11-23 14:52:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/splitRange.cpp
layout: document
redirect_from:
- /library/Utility/splitRange.cpp
- /library/Utility/splitRange.cpp.html
title: Utility/splitRange.cpp
---
