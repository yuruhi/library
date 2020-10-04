---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Rational.cpp\"\n// description : \u6709\u7406\u6570\
    \nclass Rational {\n\tusing value_type = long long;\n\tvalue_type n, d;  // n\
    \ / d\n\tconstexpr void coprime() {\n\t\tvalue_type g = gcd(n, d);\n\t\tn /= g;\n\
    \t\td /= g;\n\t\tif (d < 0) {\n\t\t\tn = -n;\n\t\t\td = -d;\n\t\t}\n\t}\n\npublic:\n\
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
    \ const {\n\t\tRational r(*this);\n\t\tr.n = max(r.n, -r.n);\n\t\treturn r;\n\t\
    }\n\tconstexpr value_type floor() const {\n\t\treturn n > 0 ? n / d : (n - d +\
    \ 1) / d;\n\t}\n\tconstexpr value_type ceil() const {\n\t\treturn (n + d - 1)\
    \ / d;\n\t}\n\tconstexpr value_type to_i() const {\n\t\treturn n / d;\n\t}\n\t\
    constexpr double to_d() {\n\t\treturn static_cast<double>(n) / static_cast<double>(d);\n\
    \t}\n\tconstexpr double to_ld() {\n\t\treturn static_cast<long double>(n) / static_cast<long\
    \ double>(d);\n\t}\n\tfriend istream& operator>>(istream& is, Rational& r) {\n\
    \t\tvalue_type n, d;\n\t\tis >> n >> d;\n\t\tr = Rational(n, d);\n\t\treturn is;\n\
    \t}\n\tfriend ostream& operator<<(ostream& os, const Rational& r) {\n\t\treturn\
    \ os << r.n << '/' << r.d;\n\t}\n};\n"
  code: "// description : \u6709\u7406\u6570\nclass Rational {\n\tusing value_type\
    \ = long long;\n\tvalue_type n, d;  // n / d\n\tconstexpr void coprime() {\n\t\
    \tvalue_type g = gcd(n, d);\n\t\tn /= g;\n\t\td /= g;\n\t\tif (d < 0) {\n\t\t\t\
    n = -n;\n\t\t\td = -d;\n\t\t}\n\t}\n\npublic:\n\tRational() = default;\n\tconstexpr\
    \ Rational(value_type _n, value_type _d = 1) : n(_n), d(_d) {\n\t\tassert(d !=\
    \ 0);\n\t\tcoprime();\n\t}\n\tconstexpr Rational operator+() const {\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr Rational operator-() const {\n\t\tRational r(*this);\n\
    \t\tr.n = -r.n;\n\t\treturn r;\n\t}\n\tconstexpr Rational& operator+(const Rational&\
    \ r) const {\n\t\treturn Rational(*this) += r;\n\t}\n\tconstexpr Rational& operator-(const\
    \ Rational& r) const {\n\t\treturn Rational(*this) -= r;\n\t}\n\tconstexpr Rational&\
    \ operator*(const Rational& r) const {\n\t\treturn Rational(*this) *= r;\n\t}\n\
    \tconstexpr Rational& operator/(const Rational& r) const {\n\t\treturn Rational(*this)\
    \ /= r;\n\t}\n\tconstexpr Rational& operator+=(const Rational& r) {\n\t\tn = n\
    \ * r.d + d * r.n;\n\t\td *= r.d;\n\t\tcoprime();\n\t\treturn *this;\n\t}\n\t\
    constexpr Rational& operator-=(const Rational& r) {\n\t\tn = n * r.d - d * r.n;\n\
    \t\td *= r.d;\n\t\tcoprime();\n\t\treturn *this;\n\t}\n\tconstexpr Rational& operator*=(const\
    \ Rational& r) {\n\t\tn *= r.n;\n\t\td *= r.d;\n\t\tcoprime();\n\t\treturn *this;\n\
    \t}\n\tconstexpr Rational& operator/=(const Rational& r) {\n\t\tn *= r.d;\n\t\t\
    d *= r.n;\n\t\tcoprime();\n\t\treturn *this;\n\t}\n\tconstexpr bool operator==(const\
    \ Rational& r) const {\n\t\treturn n == r.n && d == r.d;\n\t}\n\tconstexpr bool\
    \ operator!=(const Rational& r) const {\n\t\treturn !(*this == r);\n\t}\n\tconstexpr\
    \ bool operator<(const Rational& r) const {\n\t\treturn n * r.d < d * r.n;\n\t\
    }\n\tconstexpr bool operator<=(const Rational& r) const {\n\t\treturn *this <\
    \ r || *this == r;\n\t}\n\tconstexpr bool operator>(const Rational& r) const {\n\
    \t\treturn !(*this <= r);\n\t}\n\tconstexpr bool operator>=(const Rational& r)\
    \ const {\n\t\treturn !(*this < r);\n\t}\n\tconstexpr value_type denominator()\
    \ const {\n\t\treturn d;\n\t}\n\tconstexpr value_type numerator() const {\n\t\t\
    return n;\n\t}\n\tconstexpr Rational abs() const {\n\t\tRational r(*this);\n\t\
    \tr.n = max(r.n, -r.n);\n\t\treturn r;\n\t}\n\tconstexpr value_type floor() const\
    \ {\n\t\treturn n > 0 ? n / d : (n - d + 1) / d;\n\t}\n\tconstexpr value_type\
    \ ceil() const {\n\t\treturn (n + d - 1) / d;\n\t}\n\tconstexpr value_type to_i()\
    \ const {\n\t\treturn n / d;\n\t}\n\tconstexpr double to_d() {\n\t\treturn static_cast<double>(n)\
    \ / static_cast<double>(d);\n\t}\n\tconstexpr double to_ld() {\n\t\treturn static_cast<long\
    \ double>(n) / static_cast<long double>(d);\n\t}\n\tfriend istream& operator>>(istream&\
    \ is, Rational& r) {\n\t\tvalue_type n, d;\n\t\tis >> n >> d;\n\t\tr = Rational(n,\
    \ d);\n\t\treturn is;\n\t}\n\tfriend ostream& operator<<(ostream& os, const Rational&\
    \ r) {\n\t\treturn os << r.n << '/' << r.d;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/Rational.cpp
  requiredBy: []
  timestamp: '2020-08-25 19:33:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Rational.cpp
layout: document
redirect_from:
- /library/Math/Rational.cpp
- /library/Math/Rational.cpp.html
title: Math/Rational.cpp
---
