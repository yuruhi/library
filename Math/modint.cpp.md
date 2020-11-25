---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/Combination.cpp
    title: Math/Combination.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Partition.test.cpp
    title: test/Partition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint_pow.test.cpp
    title: test/modint_pow.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/modint.cpp\"\n#include <iostream>\n#include <vector>\n\
    #include <utility>\nusing namespace std;\n\ntemplate <int MOD> struct modint {\n\
    \tusing T = long long;\n\tT n;\n\tconstexpr modint(const T x = 0) : n(x % MOD)\
    \ {\n\t\tif (n < 0) n += MOD;\n\t}\n\tconstexpr int get_mod() const {\n\t\treturn\
    \ MOD;\n\t}\n\tconstexpr modint operator+() const {\n\t\treturn *this;\n\t}\n\t\
    constexpr modint operator-() const {\n\t\treturn n ? MOD - n : 0;\n\t}\n\tconstexpr\
    \ modint& operator++() {\n\t\tif (MOD <= ++n) n = 0;\n\t\treturn *this;\n\t}\n\
    \tconstexpr modint& operator--() {\n\t\tif (n <= 0) n = MOD;\n\t\tn--;\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr modint operator++(int) {\n\t\tmodint t = *this;\n\t\
    \t++*this;\n\t\treturn t;\n\t}\n\tconstexpr modint operator--(int) {\n\t\tmodint\
    \ t = *this;\n\t\t--*this;\n\t\treturn t;\n\t}\n\tconstexpr modint next() const\
    \ {\n\t\treturn ++modint(*this);\n\t}\n\tconstexpr modint pred() const {\n\t\t\
    return --modint(*this);\n\t}\n\tconstexpr modint operator+(const modint& m) const\
    \ {\n\t\treturn modint(*this) += m;\n\t}\n\tconstexpr modint operator-(const modint&\
    \ m) const {\n\t\treturn modint(*this) -= m;\n\t}\n\tconstexpr modint operator*(const\
    \ modint& m) const {\n\t\treturn modint(*this) *= m;\n\t}\n\tconstexpr modint\
    \ operator/(const modint& m) const {\n\t\treturn modint(*this) /= m;\n\t}\n\t\
    constexpr modint& operator+=(const modint& m) {\n\t\tn += m.n;\n\t\tif (n >= MOD)\
    \ n -= MOD;\n\t\treturn *this;\n\t}\n\tconstexpr modint& operator-=(const modint&\
    \ m) {\n\t\tn -= m.n;\n\t\tif (n < 0) n += MOD;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ modint& operator*=(const modint& m) {\n\t\tn = n * m.n % MOD;\n\t\treturn *this;\n\
    \t}\n\tconstexpr modint& operator/=(const modint& m) {\n\t\tT a = m.n, b = MOD,\
    \ u = 1, v = 0;\n\t\twhile (b) {\n\t\t\tT t = a / b;\n\t\t\ta -= t * b;\n\t\t\t\
    swap(a, b);\n\t\t\tu -= t * v;\n\t\t\tswap(u, v);\n\t\t}\n\t\tn = n * u % MOD;\n\
    \t\tif (n < 0) n += MOD;\n\t\treturn *this;\n\t}\n\tconstexpr bool operator==(const\
    \ modint& m) const {\n\t\treturn n == m.n;\n\t}\n\tconstexpr bool operator!=(const\
    \ modint& m) const {\n\t\treturn n != m.n;\n\t}\n\ttemplate <class M> constexpr\
    \ modint pow(M m) const {\n\t\tif (0 <= m) {\n\t\t\tmodint t = n, result = 1;\n\
    \t\t\twhile (m > 0) {\n\t\t\t\tif (m & 1) {\n\t\t\t\t\tresult *= t;\n\t\t\t\t\t\
    m--;\n\t\t\t\t} else {\n\t\t\t\t\tt *= t;\n\t\t\t\t\tm >>= 1;\n\t\t\t\t}\n\t\t\
    \t}\n\t\t\treturn result;\n\t\t} else {\n\t\t\treturn (modint(1) / n).pow(-m);\n\
    \t\t}\n\t}\n\ttemplate <class M> constexpr modint operator^(M m) const {\n\t\t\
    return pow(m);\n\t}\n\tfriend ostream& operator<<(ostream& os, const modint<MOD>&\
    \ m) {\n\t\treturn os << m.n;\n\t}\n\tfriend istream& operator>>(istream& is,\
    \ modint<MOD>& m) {\n\t\tlong long x;\n\t\tcin >> x;\n\t\tm = modint(x);\n\t\t\
    return is;\n\t}\n};\nusing mint = modint<1000000007>;\nusing VM = vector<mint>;\n\
    mint operator\"\"_m(unsigned long long n) {\n\treturn n;\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\n#include <utility>\n\
    using namespace std;\n\ntemplate <int MOD> struct modint {\n\tusing T = long long;\n\
    \tT n;\n\tconstexpr modint(const T x = 0) : n(x % MOD) {\n\t\tif (n < 0) n +=\
    \ MOD;\n\t}\n\tconstexpr int get_mod() const {\n\t\treturn MOD;\n\t}\n\tconstexpr\
    \ modint operator+() const {\n\t\treturn *this;\n\t}\n\tconstexpr modint operator-()\
    \ const {\n\t\treturn n ? MOD - n : 0;\n\t}\n\tconstexpr modint& operator++()\
    \ {\n\t\tif (MOD <= ++n) n = 0;\n\t\treturn *this;\n\t}\n\tconstexpr modint& operator--()\
    \ {\n\t\tif (n <= 0) n = MOD;\n\t\tn--;\n\t\treturn *this;\n\t}\n\tconstexpr modint\
    \ operator++(int) {\n\t\tmodint t = *this;\n\t\t++*this;\n\t\treturn t;\n\t}\n\
    \tconstexpr modint operator--(int) {\n\t\tmodint t = *this;\n\t\t--*this;\n\t\t\
    return t;\n\t}\n\tconstexpr modint next() const {\n\t\treturn ++modint(*this);\n\
    \t}\n\tconstexpr modint pred() const {\n\t\treturn --modint(*this);\n\t}\n\tconstexpr\
    \ modint operator+(const modint& m) const {\n\t\treturn modint(*this) += m;\n\t\
    }\n\tconstexpr modint operator-(const modint& m) const {\n\t\treturn modint(*this)\
    \ -= m;\n\t}\n\tconstexpr modint operator*(const modint& m) const {\n\t\treturn\
    \ modint(*this) *= m;\n\t}\n\tconstexpr modint operator/(const modint& m) const\
    \ {\n\t\treturn modint(*this) /= m;\n\t}\n\tconstexpr modint& operator+=(const\
    \ modint& m) {\n\t\tn += m.n;\n\t\tif (n >= MOD) n -= MOD;\n\t\treturn *this;\n\
    \t}\n\tconstexpr modint& operator-=(const modint& m) {\n\t\tn -= m.n;\n\t\tif\
    \ (n < 0) n += MOD;\n\t\treturn *this;\n\t}\n\tconstexpr modint& operator*=(const\
    \ modint& m) {\n\t\tn = n * m.n % MOD;\n\t\treturn *this;\n\t}\n\tconstexpr modint&\
    \ operator/=(const modint& m) {\n\t\tT a = m.n, b = MOD, u = 1, v = 0;\n\t\twhile\
    \ (b) {\n\t\t\tT t = a / b;\n\t\t\ta -= t * b;\n\t\t\tswap(a, b);\n\t\t\tu -=\
    \ t * v;\n\t\t\tswap(u, v);\n\t\t}\n\t\tn = n * u % MOD;\n\t\tif (n < 0) n +=\
    \ MOD;\n\t\treturn *this;\n\t}\n\tconstexpr bool operator==(const modint& m) const\
    \ {\n\t\treturn n == m.n;\n\t}\n\tconstexpr bool operator!=(const modint& m) const\
    \ {\n\t\treturn n != m.n;\n\t}\n\ttemplate <class M> constexpr modint pow(M m)\
    \ const {\n\t\tif (0 <= m) {\n\t\t\tmodint t = n, result = 1;\n\t\t\twhile (m\
    \ > 0) {\n\t\t\t\tif (m & 1) {\n\t\t\t\t\tresult *= t;\n\t\t\t\t\tm--;\n\t\t\t\
    \t} else {\n\t\t\t\t\tt *= t;\n\t\t\t\t\tm >>= 1;\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    return result;\n\t\t} else {\n\t\t\treturn (modint(1) / n).pow(-m);\n\t\t}\n\t\
    }\n\ttemplate <class M> constexpr modint operator^(M m) const {\n\t\treturn pow(m);\n\
    \t}\n\tfriend ostream& operator<<(ostream& os, const modint<MOD>& m) {\n\t\treturn\
    \ os << m.n;\n\t}\n\tfriend istream& operator>>(istream& is, modint<MOD>& m) {\n\
    \t\tlong long x;\n\t\tcin >> x;\n\t\tm = modint(x);\n\t\treturn is;\n\t}\n};\n\
    using mint = modint<1000000007>;\nusing VM = vector<mint>;\nmint operator\"\"\
    _m(unsigned long long n) {\n\treturn n;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/modint.cpp
  requiredBy:
  - Math/Combination.cpp
  timestamp: '2020-11-23 14:52:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/modint_pow.test.cpp
  - test/Partition.test.cpp
documentation_of: Math/modint.cpp
layout: document
redirect_from:
- /library/Math/modint.cpp
- /library/Math/modint.cpp.html
title: Math/modint.cpp
---