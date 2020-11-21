---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Pair.cpp\"\n#include <utility>\n#include <tuple>\n\
    #include <iostream>\nusing namespace std;\n\ntemplate <class T> struct Pair {\n\
    \tusing value_type = T;\n\tstatic constexpr bool cmp_x(const Pair<value_type>&\
    \ p1, const Pair<value_type>& p2) {\n\t\treturn p1.xy() < p2.xy();\n\t}\n\tstatic\
    \ constexpr bool cmp_y(const Pair<value_type>& p1, const Pair<value_type>& p2)\
    \ {\n\t\treturn p1.yx() < p2.yx();\n\t}\n\tstatic constexpr value_type get_x(const\
    \ Pair<value_type>& p) {\n\t\treturn p.x;\n\t}\n\tstatic constexpr value_type\
    \ get_y(const Pair<value_type>& p) {\n\t\treturn p.y;\n\t}\n\n\tvalue_type x,\
    \ y;\n\tconstexpr Pair() : x(), y() {}\n\tconstexpr Pair(value_type _x, value_type\
    \ _y) : x(_x), y(_y) {}\n\tconstexpr Pair(const pair<value_type, value_type>&\
    \ xy) : x(xy.first), y(xy.second) {}\n\tconstexpr Pair(const tuple<value_type,\
    \ value_type>& xy)\n\t    : x(get<0>(xy)), y(get<0>(xy)) {}\n\tconstexpr Pair\
    \ operator+() const {\n\t\treturn *this;\n\t}\n\tconstexpr Pair operator-() const\
    \ {\n\t\treturn {-x, -y};\n\t}\n\tconstexpr Pair operator+(const Pair& p) const\
    \ {\n\t\treturn Pair(*this) += p;\n\t}\n\tconstexpr Pair operator-(const Pair&\
    \ p) const {\n\t\treturn Pair(*this) -= p;\n\t}\n\tconstexpr Pair operator*(const\
    \ Pair& p) const {\n\t\treturn Pair(*this) *= p;\n\t}\n\tconstexpr Pair operator/(const\
    \ Pair& p) const {\n\t\treturn Pair(*this) /= p;\n\t}\n\tconstexpr Pair operator%(const\
    \ Pair& p) const {\n\t\treturn Pair(*this) %= p;\n\t}\n\tconstexpr Pair operator+(value_type\
    \ n) const {\n\t\treturn Pair(*this) += n;\n\t}\n\tconstexpr Pair operator-(value_type\
    \ n) const {\n\t\treturn Pair(*this) -= n;\n\t}\n\tconstexpr Pair operator*(value_type\
    \ n) const {\n\t\treturn Pair(*this) *= n;\n\t}\n\tconstexpr Pair operator/(value_type\
    \ n) const {\n\t\treturn Pair(*this) /= n;\n\t}\n\tconstexpr Pair operator%(value_type\
    \ n) const {\n\t\treturn Pair(*this) %= n;\n\t}\n\tconstexpr Pair& operator+=(const\
    \ Pair& p) {\n\t\tx += p.x;\n\t\ty += p.y;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ Pair& operator-=(const Pair& p) {\n\t\tx -= p.x;\n\t\ty -= p.y;\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr Pair& operator*=(const Pair& p) {\n\t\tx *= p.x;\n\t\
    \ty *= p.y;\n\t\treturn *this;\n\t}\n\tconstexpr Pair& operator/=(const Pair&\
    \ p) {\n\t\tx /= p.x;\n\t\ty /= p.y;\n\t\treturn *this;\n\t}\n\tconstexpr Pair&\
    \ operator%=(const Pair& p) {\n\t\tx %= p.x;\n\t\ty %= p.y;\n\t\treturn *this;\n\
    \t}\n\tconstexpr Pair& operator+=(value_type n) {\n\t\tx += n;\n\t\ty += n;\n\t\
    \treturn *this;\n\t}\n\tconstexpr Pair& operator-=(value_type n) {\n\t\tx -= n;\n\
    \t\ty -= n;\n\t\treturn *this;\n\t}\n\tconstexpr Pair& operator*=(value_type n)\
    \ {\n\t\tx *= n;\n\t\ty *= n;\n\t\treturn *this;\n\t}\n\tconstexpr Pair& operator/=(value_type\
    \ n) {\n\t\tx /= n;\n\t\ty /= n;\n\t\treturn *this;\n\t}\n\tconstexpr Pair& operator%=(value_type\
    \ n) {\n\t\tx %= n;\n\t\ty %= n;\n\t\treturn *this;\n\t}\n\tconstexpr bool operator==(const\
    \ Pair& p) const {\n\t\treturn x == p.x && y == p.y;\n\t}\n\tconstexpr bool operator!=(const\
    \ Pair& p) const {\n\t\treturn x != p.x || y != p.y;\n\t}\n\tconstexpr bool operator<(const\
    \ Pair& p) const {\n\t\treturn x < p.x || (!(p.x < x) && y < p.y);\n\t}\n\tconstexpr\
    \ bool operator>(const Pair& p) const {\n\t\treturn p < *this;\n\t}\n\tconstexpr\
    \ bool operator<=(const Pair& p) const {\n\t\treturn !(p < *this);\n\t}\n\tconstexpr\
    \ bool operator>=(const Pair& p) const {\n\t\treturn !(*this < p);\n\t}\n\tconstexpr\
    \ value_type operator[](size_t i) const {\n\t\tassert(0 <= i && i < 2);\n\t\t\
    return i == 0 ? x : y;\n\t}\n\tconstexpr pair<value_type, value_type> to_pair()\
    \ const {\n\t\treturn {x, y};\n\t}\n\tconstexpr tuple<value_type, value_type>\
    \ to_tuple() const {\n\t\treturn {x, y};\n\t}\n\tconstexpr Pair xy() const {\n\
    \t\treturn {x, y};\n\t}\n\tconstexpr Pair yx() const {\n\t\treturn {y, x};\n\t\
    }\n\tconstexpr operator tuple<value_type&, value_type&>() {\n\t\treturn tuple<value_type&,\
    \ value_type&>(x, y);\n\t}\n\tfriend ostream& operator<<(ostream& os, const Pair&\
    \ p) {\n\t\treturn os << p.x << ' ' << p.y;\n\t}\n\tfriend istream& operator>>(istream&\
    \ is, Pair& p) {\n\t\treturn is >> p.x >> p.y;\n\t}\n};\nnamespace std {\n\ttemplate\
    \ <class T> struct tuple_size<Pair<T>> : integral_constant<size_t, 2> {};\n\t\
    template <size_t N, class T> struct tuple_element<N, Pair<T>> { using type = T;\
    \ };\n}  // namespace std\ntemplate <size_t N, class T> T get(const Pair<T>& p)\
    \ {\n\treturn N == 0 ? p.x : p.y;\n}\n"
  code: "#pragma once\n#include <utility>\n#include <tuple>\n#include <iostream>\n\
    using namespace std;\n\ntemplate <class T> struct Pair {\n\tusing value_type =\
    \ T;\n\tstatic constexpr bool cmp_x(const Pair<value_type>& p1, const Pair<value_type>&\
    \ p2) {\n\t\treturn p1.xy() < p2.xy();\n\t}\n\tstatic constexpr bool cmp_y(const\
    \ Pair<value_type>& p1, const Pair<value_type>& p2) {\n\t\treturn p1.yx() < p2.yx();\n\
    \t}\n\tstatic constexpr value_type get_x(const Pair<value_type>& p) {\n\t\treturn\
    \ p.x;\n\t}\n\tstatic constexpr value_type get_y(const Pair<value_type>& p) {\n\
    \t\treturn p.y;\n\t}\n\n\tvalue_type x, y;\n\tconstexpr Pair() : x(), y() {}\n\
    \tconstexpr Pair(value_type _x, value_type _y) : x(_x), y(_y) {}\n\tconstexpr\
    \ Pair(const pair<value_type, value_type>& xy) : x(xy.first), y(xy.second) {}\n\
    \tconstexpr Pair(const tuple<value_type, value_type>& xy)\n\t    : x(get<0>(xy)),\
    \ y(get<0>(xy)) {}\n\tconstexpr Pair operator+() const {\n\t\treturn *this;\n\t\
    }\n\tconstexpr Pair operator-() const {\n\t\treturn {-x, -y};\n\t}\n\tconstexpr\
    \ Pair operator+(const Pair& p) const {\n\t\treturn Pair(*this) += p;\n\t}\n\t\
    constexpr Pair operator-(const Pair& p) const {\n\t\treturn Pair(*this) -= p;\n\
    \t}\n\tconstexpr Pair operator*(const Pair& p) const {\n\t\treturn Pair(*this)\
    \ *= p;\n\t}\n\tconstexpr Pair operator/(const Pair& p) const {\n\t\treturn Pair(*this)\
    \ /= p;\n\t}\n\tconstexpr Pair operator%(const Pair& p) const {\n\t\treturn Pair(*this)\
    \ %= p;\n\t}\n\tconstexpr Pair operator+(value_type n) const {\n\t\treturn Pair(*this)\
    \ += n;\n\t}\n\tconstexpr Pair operator-(value_type n) const {\n\t\treturn Pair(*this)\
    \ -= n;\n\t}\n\tconstexpr Pair operator*(value_type n) const {\n\t\treturn Pair(*this)\
    \ *= n;\n\t}\n\tconstexpr Pair operator/(value_type n) const {\n\t\treturn Pair(*this)\
    \ /= n;\n\t}\n\tconstexpr Pair operator%(value_type n) const {\n\t\treturn Pair(*this)\
    \ %= n;\n\t}\n\tconstexpr Pair& operator+=(const Pair& p) {\n\t\tx += p.x;\n\t\
    \ty += p.y;\n\t\treturn *this;\n\t}\n\tconstexpr Pair& operator-=(const Pair&\
    \ p) {\n\t\tx -= p.x;\n\t\ty -= p.y;\n\t\treturn *this;\n\t}\n\tconstexpr Pair&\
    \ operator*=(const Pair& p) {\n\t\tx *= p.x;\n\t\ty *= p.y;\n\t\treturn *this;\n\
    \t}\n\tconstexpr Pair& operator/=(const Pair& p) {\n\t\tx /= p.x;\n\t\ty /= p.y;\n\
    \t\treturn *this;\n\t}\n\tconstexpr Pair& operator%=(const Pair& p) {\n\t\tx %=\
    \ p.x;\n\t\ty %= p.y;\n\t\treturn *this;\n\t}\n\tconstexpr Pair& operator+=(value_type\
    \ n) {\n\t\tx += n;\n\t\ty += n;\n\t\treturn *this;\n\t}\n\tconstexpr Pair& operator-=(value_type\
    \ n) {\n\t\tx -= n;\n\t\ty -= n;\n\t\treturn *this;\n\t}\n\tconstexpr Pair& operator*=(value_type\
    \ n) {\n\t\tx *= n;\n\t\ty *= n;\n\t\treturn *this;\n\t}\n\tconstexpr Pair& operator/=(value_type\
    \ n) {\n\t\tx /= n;\n\t\ty /= n;\n\t\treturn *this;\n\t}\n\tconstexpr Pair& operator%=(value_type\
    \ n) {\n\t\tx %= n;\n\t\ty %= n;\n\t\treturn *this;\n\t}\n\tconstexpr bool operator==(const\
    \ Pair& p) const {\n\t\treturn x == p.x && y == p.y;\n\t}\n\tconstexpr bool operator!=(const\
    \ Pair& p) const {\n\t\treturn x != p.x || y != p.y;\n\t}\n\tconstexpr bool operator<(const\
    \ Pair& p) const {\n\t\treturn x < p.x || (!(p.x < x) && y < p.y);\n\t}\n\tconstexpr\
    \ bool operator>(const Pair& p) const {\n\t\treturn p < *this;\n\t}\n\tconstexpr\
    \ bool operator<=(const Pair& p) const {\n\t\treturn !(p < *this);\n\t}\n\tconstexpr\
    \ bool operator>=(const Pair& p) const {\n\t\treturn !(*this < p);\n\t}\n\tconstexpr\
    \ value_type operator[](size_t i) const {\n\t\tassert(0 <= i && i < 2);\n\t\t\
    return i == 0 ? x : y;\n\t}\n\tconstexpr pair<value_type, value_type> to_pair()\
    \ const {\n\t\treturn {x, y};\n\t}\n\tconstexpr tuple<value_type, value_type>\
    \ to_tuple() const {\n\t\treturn {x, y};\n\t}\n\tconstexpr Pair xy() const {\n\
    \t\treturn {x, y};\n\t}\n\tconstexpr Pair yx() const {\n\t\treturn {y, x};\n\t\
    }\n\tconstexpr operator tuple<value_type&, value_type&>() {\n\t\treturn tuple<value_type&,\
    \ value_type&>(x, y);\n\t}\n\tfriend ostream& operator<<(ostream& os, const Pair&\
    \ p) {\n\t\treturn os << p.x << ' ' << p.y;\n\t}\n\tfriend istream& operator>>(istream&\
    \ is, Pair& p) {\n\t\treturn is >> p.x >> p.y;\n\t}\n};\nnamespace std {\n\ttemplate\
    \ <class T> struct tuple_size<Pair<T>> : integral_constant<size_t, 2> {};\n\t\
    template <size_t N, class T> struct tuple_element<N, Pair<T>> { using type = T;\
    \ };\n}  // namespace std\ntemplate <size_t N, class T> T get(const Pair<T>& p)\
    \ {\n\treturn N == 0 ? p.x : p.y;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Pair.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Pair.cpp
layout: document
redirect_from:
- /library/Utility/Pair.cpp
- /library/Utility/Pair.cpp.html
title: Utility/Pair.cpp
---
