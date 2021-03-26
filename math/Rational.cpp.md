---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/Rational.cpp\"\n#include <vector>\n#include <numeric>\n\
    #include <iostream>\n#include <cassert>\n\ntemplate <class T> class Rational {\n\
    public:\n\tusing value_type = T;\n\nprivate:\n\tvalue_type n, d;  // n / d\n\t\
    constexpr void coprime() {\n\t\tvalue_type g = std::gcd(n, d);\n\t\tn /= g;\n\t\
    \td /= g;\n\t\tif (d < 0) {\n\t\t\tn = -n;\n\t\t\td = -d;\n\t\t}\n\t}\n\npublic:\n\
    \tRational() = default;\n\tconstexpr Rational(value_type _n, value_type _d = 1)\
    \ : n(_n), d(_d) {\n\t\tassert(d != 0);\n\t\tcoprime();\n\t}\n\tconstexpr Rational\
    \ operator+() const {\n\t\treturn *this;\n\t}\n\tconstexpr Rational operator-()\
    \ const {\n\t\tRational r(*this);\n\t\tr.n = -r.n;\n\t\treturn r;\n\t}\n\tconstexpr\
    \ Rational& operator+(const Rational& r) const {\n\t\treturn Rational(*this) +=\
    \ r;\n\t}\n\tconstexpr Rational& operator-(const Rational& r) const {\n\t\treturn\
    \ Rational(*this) -= r;\n\t}\n\tconstexpr Rational& operator*(const Rational&\
    \ r) const {\n\t\treturn Rational(*this) *= r;\n\t}\n\tconstexpr Rational& operator/(const\
    \ Rational& r) const {\n\t\treturn Rational(*this) /= r;\n\t}\n\tconstexpr Rational&\
    \ operator+=(const Rational& r) {\n\t\tn = n * r.d + d * r.n;\n\t\td *= r.d;\n\
    \t\tcoprime();\n\t\treturn *this;\n\t}\n\tconstexpr Rational& operator-=(const\
    \ Rational& r) {\n\t\tn = n * r.d - d * r.n;\n\t\td *= r.d;\n\t\tcoprime();\n\t\
    \treturn *this;\n\t}\n\tconstexpr Rational& operator*=(const Rational& r) {\n\t\
    \tn *= r.n;\n\t\td *= r.d;\n\t\tcoprime();\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ Rational& operator/=(const Rational& r) {\n\t\tn *= r.d;\n\t\td *= r.n;\n\t\t\
    coprime();\n\t\treturn *this;\n\t}\n\tconstexpr bool operator==(const Rational&\
    \ r) const {\n\t\treturn n == r.n && d == r.d;\n\t}\n\tconstexpr bool operator!=(const\
    \ Rational& r) const {\n\t\treturn !(*this == r);\n\t}\n\tconstexpr bool operator<(const\
    \ Rational& r) const {\n\t\treturn n * r.d < d * r.n;\n\t}\n\tconstexpr bool operator<=(const\
    \ Rational& r) const {\n\t\treturn *this < r || *this == r;\n\t}\n\tconstexpr\
    \ bool operator>(const Rational& r) const {\n\t\treturn !(*this <= r);\n\t}\n\t\
    constexpr bool operator>=(const Rational& r) const {\n\t\treturn !(*this < r);\n\
    \t}\n\tconstexpr value_type denominator() const {\n\t\treturn d;\n\t}\n\tconstexpr\
    \ value_type numerator() const {\n\t\treturn n;\n\t}\n\tconstexpr Rational abs()\
    \ const {\n\t\tRational r(*this);\n\t\tr.n = std::max(r.n, -r.n);\n\t\treturn\
    \ r;\n\t}\n\tconstexpr value_type floor() const {\n\t\treturn n > 0 ? n / d :\
    \ (n - d + 1) / d;\n\t}\n\tconstexpr value_type ceil() const {\n\t\treturn (n\
    \ + d - 1) / d;\n\t}\n\tconstexpr value_type to_i() const {\n\t\treturn n / d;\n\
    \t}\n\tconstexpr float to_f() const {\n\t\treturn static_cast<float>(n) / static_cast<float>(d);\n\
    \t}\n\tconstexpr double to_d() const {\n\t\treturn static_cast<double>(n) / static_cast<double>(d);\n\
    \t}\n\tconstexpr long double to_ld() const {\n\t\treturn static_cast<long double>(n)\
    \ / static_cast<long double>(d);\n\t}\n\tfriend std::istream& operator>>(std::istream&\
    \ is, Rational& r) {\n\t\tvalue_type n, d;\n\t\tis >> n >> d;\n\t\tr = Rational(n,\
    \ d);\n\t\treturn is;\n\t}\n\tfriend std::ostream& operator<<(std::ostream& os,\
    \ const Rational& r) {\n\t\treturn os << r.n << '/' << r.d;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <numeric>\n#include <iostream>\n\
    #include <cassert>\n\ntemplate <class T> class Rational {\npublic:\n\tusing value_type\
    \ = T;\n\nprivate:\n\tvalue_type n, d;  // n / d\n\tconstexpr void coprime() {\n\
    \t\tvalue_type g = std::gcd(n, d);\n\t\tn /= g;\n\t\td /= g;\n\t\tif (d < 0) {\n\
    \t\t\tn = -n;\n\t\t\td = -d;\n\t\t}\n\t}\n\npublic:\n\tRational() = default;\n\
    \tconstexpr Rational(value_type _n, value_type _d = 1) : n(_n), d(_d) {\n\t\t\
    assert(d != 0);\n\t\tcoprime();\n\t}\n\tconstexpr Rational operator+() const {\n\
    \t\treturn *this;\n\t}\n\tconstexpr Rational operator-() const {\n\t\tRational\
    \ r(*this);\n\t\tr.n = -r.n;\n\t\treturn r;\n\t}\n\tconstexpr Rational& operator+(const\
    \ Rational& r) const {\n\t\treturn Rational(*this) += r;\n\t}\n\tconstexpr Rational&\
    \ operator-(const Rational& r) const {\n\t\treturn Rational(*this) -= r;\n\t}\n\
    \tconstexpr Rational& operator*(const Rational& r) const {\n\t\treturn Rational(*this)\
    \ *= r;\n\t}\n\tconstexpr Rational& operator/(const Rational& r) const {\n\t\t\
    return Rational(*this) /= r;\n\t}\n\tconstexpr Rational& operator+=(const Rational&\
    \ r) {\n\t\tn = n * r.d + d * r.n;\n\t\td *= r.d;\n\t\tcoprime();\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr Rational& operator-=(const Rational& r) {\n\t\tn =\
    \ n * r.d - d * r.n;\n\t\td *= r.d;\n\t\tcoprime();\n\t\treturn *this;\n\t}\n\t\
    constexpr Rational& operator*=(const Rational& r) {\n\t\tn *= r.n;\n\t\td *= r.d;\n\
    \t\tcoprime();\n\t\treturn *this;\n\t}\n\tconstexpr Rational& operator/=(const\
    \ Rational& r) {\n\t\tn *= r.d;\n\t\td *= r.n;\n\t\tcoprime();\n\t\treturn *this;\n\
    \t}\n\tconstexpr bool operator==(const Rational& r) const {\n\t\treturn n == r.n\
    \ && d == r.d;\n\t}\n\tconstexpr bool operator!=(const Rational& r) const {\n\t\
    \treturn !(*this == r);\n\t}\n\tconstexpr bool operator<(const Rational& r) const\
    \ {\n\t\treturn n * r.d < d * r.n;\n\t}\n\tconstexpr bool operator<=(const Rational&\
    \ r) const {\n\t\treturn *this < r || *this == r;\n\t}\n\tconstexpr bool operator>(const\
    \ Rational& r) const {\n\t\treturn !(*this <= r);\n\t}\n\tconstexpr bool operator>=(const\
    \ Rational& r) const {\n\t\treturn !(*this < r);\n\t}\n\tconstexpr value_type\
    \ denominator() const {\n\t\treturn d;\n\t}\n\tconstexpr value_type numerator()\
    \ const {\n\t\treturn n;\n\t}\n\tconstexpr Rational abs() const {\n\t\tRational\
    \ r(*this);\n\t\tr.n = std::max(r.n, -r.n);\n\t\treturn r;\n\t}\n\tconstexpr value_type\
    \ floor() const {\n\t\treturn n > 0 ? n / d : (n - d + 1) / d;\n\t}\n\tconstexpr\
    \ value_type ceil() const {\n\t\treturn (n + d - 1) / d;\n\t}\n\tconstexpr value_type\
    \ to_i() const {\n\t\treturn n / d;\n\t}\n\tconstexpr float to_f() const {\n\t\
    \treturn static_cast<float>(n) / static_cast<float>(d);\n\t}\n\tconstexpr double\
    \ to_d() const {\n\t\treturn static_cast<double>(n) / static_cast<double>(d);\n\
    \t}\n\tconstexpr long double to_ld() const {\n\t\treturn static_cast<long double>(n)\
    \ / static_cast<long double>(d);\n\t}\n\tfriend std::istream& operator>>(std::istream&\
    \ is, Rational& r) {\n\t\tvalue_type n, d;\n\t\tis >> n >> d;\n\t\tr = Rational(n,\
    \ d);\n\t\treturn is;\n\t}\n\tfriend std::ostream& operator<<(std::ostream& os,\
    \ const Rational& r) {\n\t\treturn os << r.n << '/' << r.d;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Rational.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Rational.cpp
layout: document
redirect_from:
- /library/math/Rational.cpp
- /library/math/Rational.cpp.html
title: math/Rational.cpp
---