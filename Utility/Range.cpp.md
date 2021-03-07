---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Utility/splitRange.cpp
    title: Utility/splitRange.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Range.cpp\"\n#include <limits>\n#include <algorithm>\n\
    #include <iostream>\n#include <cassert>\n#include <optional>\n\ntemplate <class\
    \ T> struct Range {\n\tusing value_type = T;\n\n\tvalue_type x, y;  // [x, y]\n\
    \n\tstatic constexpr bool cmp_x(const Range& r1, const Range& r2) {\n\t\treturn\
    \ r1.x < r2.x;\n\t}\n\tstatic constexpr bool cmp_y(const Range& r1, const Range&\
    \ r2) {\n\t\treturn r1.y < r2.y;\n\t}\n\tstatic constexpr bool cmp_xy(const Range&\
    \ r1, const Range& r2) {\n\t\treturn r1.pair() < r2.pair();\n\t}\n\tstatic constexpr\
    \ bool cmp_yx(const Range& r1, const Range& r2) {\n\t\treturn r1.anti_pair() <\
    \ r2.anti_pair();\n\t}\n\n\tconstexpr Range() : x(0), y(0) {}\n\tconstexpr Range(value_type\
    \ _x, value_type _y, bool exclude_end = false)\n\t    : x(_x), y(_y - !exclude_end)\
    \ {\n\t\tassert(x <= y);\n\t}\n\tconstexpr Range(const Range& _r, bool exclude_end\
    \ = true)\n\t    : x(_r.x), y(_r.y - !exclude_end) {\n\t\tassert(x <= y);\n\t\
    }\n\tconstexpr bool operator==(const Range& r) const {\n\t\treturn x == r.x &&\
    \ y == r.y;\n\t}\n\tconstexpr bool operator!=(const Range& r) const {\n\t\treturn\
    \ x != r.x || y != r.y;\n\t}\n\tconstexpr bool operator<(const Range& r) const\
    \ {\n\t\treturn pair() < r.pair();\n\t}\n\tconstexpr bool operator<=(const Range&\
    \ r) const {\n\t\treturn pair() <= r.pair();\n\t}\n\tconstexpr bool operator>(const\
    \ Range& r) const {\n\t\treturn pair() > r.pair();\n\t}\n\tconstexpr bool operator>=(const\
    \ Range& r) const {\n\t\treturn pair() >= r.pair();\n\t}\n\tconstexpr Range& operator<<=(const\
    \ value_type& n) {\n\t\tx -= n;\n\t\ty -= n;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ Range& operator>>=(const value_type& n) {\n\t\tx += n;\n\t\ty += n;\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr Range& operator*=(const value_type& n) {\n\t\tx *=\
    \ n;\n\t\ty *= n;\n\t\treturn *this;\n\t}\n\tconstexpr Range operator<<(const\
    \ value_type& n) const {\n\t\treturn Range(*this) <<= n;\n\t}\n\tconstexpr Range\
    \ operator>>(const value_type& n) const {\n\t\treturn Range(*this) >>= n;\n\t\
    }\n\tconstexpr Range operator*(const value_type& n) const {\n\t\treturn Range(*this)\
    \ *= n;\n\t}\n\tconstexpr std::optional<Range> operator&(const Range& r) const\
    \ {\n\t\tif (intersects(r)) {\n\t\t\treturn Range(std::max(x, r.x), std::min(y,\
    \ r.y));\n\t\t} else {\n\t\t\treturn std::nullopt;\n\t\t}\n\t}\n\tconstexpr std::optional<Range>\
    \ operator|(const Range& r) const {\n\t\tif (intersects(r) || adjacent(r)) {\n\
    \t\t\treturn Range(std::min(x, r.x), std::max(y, r.y));\n\t\t} else {\n\t\t\t\
    return std::nullopt;\n\t\t}\n\t}\n\tconstexpr value_type operator[](const value_type&\
    \ n) const {  // 0-indexed\n\t\tassert(x + n <= y);\n\t\treturn x + n;\n\t}\n\t\
    constexpr Range operator[](const Range& n) const {\n\t\treturn Range(operator[](n.x),\
    \ operator[](n.y));\n\t}\n\tconstexpr auto pair() const {\n\t\treturn std::pair(x,\
    \ y);\n\t}\n\tconstexpr auto anti_pair() const {\n\t\treturn std::pair(y, x);\n\
    \t}\n\tconstexpr Range open() const {\n\t\treturn Range(x, y + 1);\n\t}\n\tconstexpr\
    \ bool include(const value_type& n) const {\n\t\treturn x <= n && n <= y;\n\t\
    }\n\tconstexpr bool intersects(const Range& r) const {\n\t\treturn std::max(x,\
    \ r.x) <= std::min(y, r.y);\n\t}\n\tconstexpr bool contains(const Range& r) const\
    \ {\n\t\treturn x <= r.x && r.y <= y;\n\t}\n\tconstexpr bool adjacent(const Range&\
    \ r) const {\n\t\treturn y + 1 == r.x || r.y + 1 == x;\n\t}\n\tconstexpr value_type\
    \ size() const {\n\t\treturn std::max<value_type>(0, y - x + 1);\n\t}\n\tconstexpr\
    \ value_type sum() const {\n\t\treturn (x + y) * size() / 2;\n\t}\n\tfriend std::ostream&\
    \ operator<<(std::ostream& os, const Range& r) {\n\t\treturn os << '[' << r.x\
    \ << \", \" << r.y << ']';\n\t}\n\tfriend std::istream& operator>>(std::istream&\
    \ is, Range& r) {\n\t\treturn is >> r.x >> r.y;\n\t}\n};\ntemplate <class T, class\
    \ U>\nconstexpr std::optional<Range<T>> equal_range(const U& a, const Range<T>&\
    \ r) {\n\tauto L = std::lower_bound(a.begin(), a.end(), r.x) - a.begin();\n\t\
    auto R = std::upper_bound(a.begin(), a.end(), r.y) - a.begin();\n\treturn L ==\
    \ R ? std::nullopt : Range<T>(L, R, true);\n}\n"
  code: "#pragma once\n#include <limits>\n#include <algorithm>\n#include <iostream>\n\
    #include <cassert>\n#include <optional>\n\ntemplate <class T> struct Range {\n\
    \tusing value_type = T;\n\n\tvalue_type x, y;  // [x, y]\n\n\tstatic constexpr\
    \ bool cmp_x(const Range& r1, const Range& r2) {\n\t\treturn r1.x < r2.x;\n\t\
    }\n\tstatic constexpr bool cmp_y(const Range& r1, const Range& r2) {\n\t\treturn\
    \ r1.y < r2.y;\n\t}\n\tstatic constexpr bool cmp_xy(const Range& r1, const Range&\
    \ r2) {\n\t\treturn r1.pair() < r2.pair();\n\t}\n\tstatic constexpr bool cmp_yx(const\
    \ Range& r1, const Range& r2) {\n\t\treturn r1.anti_pair() < r2.anti_pair();\n\
    \t}\n\n\tconstexpr Range() : x(0), y(0) {}\n\tconstexpr Range(value_type _x, value_type\
    \ _y, bool exclude_end = false)\n\t    : x(_x), y(_y - !exclude_end) {\n\t\tassert(x\
    \ <= y);\n\t}\n\tconstexpr Range(const Range& _r, bool exclude_end = true)\n\t\
    \    : x(_r.x), y(_r.y - !exclude_end) {\n\t\tassert(x <= y);\n\t}\n\tconstexpr\
    \ bool operator==(const Range& r) const {\n\t\treturn x == r.x && y == r.y;\n\t\
    }\n\tconstexpr bool operator!=(const Range& r) const {\n\t\treturn x != r.x ||\
    \ y != r.y;\n\t}\n\tconstexpr bool operator<(const Range& r) const {\n\t\treturn\
    \ pair() < r.pair();\n\t}\n\tconstexpr bool operator<=(const Range& r) const {\n\
    \t\treturn pair() <= r.pair();\n\t}\n\tconstexpr bool operator>(const Range& r)\
    \ const {\n\t\treturn pair() > r.pair();\n\t}\n\tconstexpr bool operator>=(const\
    \ Range& r) const {\n\t\treturn pair() >= r.pair();\n\t}\n\tconstexpr Range& operator<<=(const\
    \ value_type& n) {\n\t\tx -= n;\n\t\ty -= n;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ Range& operator>>=(const value_type& n) {\n\t\tx += n;\n\t\ty += n;\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr Range& operator*=(const value_type& n) {\n\t\tx *=\
    \ n;\n\t\ty *= n;\n\t\treturn *this;\n\t}\n\tconstexpr Range operator<<(const\
    \ value_type& n) const {\n\t\treturn Range(*this) <<= n;\n\t}\n\tconstexpr Range\
    \ operator>>(const value_type& n) const {\n\t\treturn Range(*this) >>= n;\n\t\
    }\n\tconstexpr Range operator*(const value_type& n) const {\n\t\treturn Range(*this)\
    \ *= n;\n\t}\n\tconstexpr std::optional<Range> operator&(const Range& r) const\
    \ {\n\t\tif (intersects(r)) {\n\t\t\treturn Range(std::max(x, r.x), std::min(y,\
    \ r.y));\n\t\t} else {\n\t\t\treturn std::nullopt;\n\t\t}\n\t}\n\tconstexpr std::optional<Range>\
    \ operator|(const Range& r) const {\n\t\tif (intersects(r) || adjacent(r)) {\n\
    \t\t\treturn Range(std::min(x, r.x), std::max(y, r.y));\n\t\t} else {\n\t\t\t\
    return std::nullopt;\n\t\t}\n\t}\n\tconstexpr value_type operator[](const value_type&\
    \ n) const {  // 0-indexed\n\t\tassert(x + n <= y);\n\t\treturn x + n;\n\t}\n\t\
    constexpr Range operator[](const Range& n) const {\n\t\treturn Range(operator[](n.x),\
    \ operator[](n.y));\n\t}\n\tconstexpr auto pair() const {\n\t\treturn std::pair(x,\
    \ y);\n\t}\n\tconstexpr auto anti_pair() const {\n\t\treturn std::pair(y, x);\n\
    \t}\n\tconstexpr Range open() const {\n\t\treturn Range(x, y + 1);\n\t}\n\tconstexpr\
    \ bool include(const value_type& n) const {\n\t\treturn x <= n && n <= y;\n\t\
    }\n\tconstexpr bool intersects(const Range& r) const {\n\t\treturn std::max(x,\
    \ r.x) <= std::min(y, r.y);\n\t}\n\tconstexpr bool contains(const Range& r) const\
    \ {\n\t\treturn x <= r.x && r.y <= y;\n\t}\n\tconstexpr bool adjacent(const Range&\
    \ r) const {\n\t\treturn y + 1 == r.x || r.y + 1 == x;\n\t}\n\tconstexpr value_type\
    \ size() const {\n\t\treturn std::max<value_type>(0, y - x + 1);\n\t}\n\tconstexpr\
    \ value_type sum() const {\n\t\treturn (x + y) * size() / 2;\n\t}\n\tfriend std::ostream&\
    \ operator<<(std::ostream& os, const Range& r) {\n\t\treturn os << '[' << r.x\
    \ << \", \" << r.y << ']';\n\t}\n\tfriend std::istream& operator>>(std::istream&\
    \ is, Range& r) {\n\t\treturn is >> r.x >> r.y;\n\t}\n};\ntemplate <class T, class\
    \ U>\nconstexpr std::optional<Range<T>> equal_range(const U& a, const Range<T>&\
    \ r) {\n\tauto L = std::lower_bound(a.begin(), a.end(), r.x) - a.begin();\n\t\
    auto R = std::upper_bound(a.begin(), a.end(), r.y) - a.begin();\n\treturn L ==\
    \ R ? std::nullopt : Range<T>(L, R, true);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Range.cpp
  requiredBy:
  - Utility/splitRange.cpp
  timestamp: '2021-03-06 16:44:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Range.cpp
layout: document
redirect_from:
- /library/Utility/Range.cpp
- /library/Utility/Range.cpp.html
title: Utility/Range.cpp
---
