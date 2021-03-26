---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/get_MOD.cpp
    title: Utility/get_MOD.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/Combination.cpp
    title: math/Combination.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Partition.test.cpp
    title: test/Partition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint_pow.test.cpp
    title: test/modint_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/get_MOD.cpp\"\nconstexpr long long get_MOD() {\n\
    #ifdef SET_MOD\n\treturn SET_MOD;\n#else\n\treturn 1000000007;\n#endif\n}\n#line\
    \ 3 \"math/modint.cpp\"\n#include <iostream>\n#include <vector>\n#include <utility>\n\
    #include <cassert>\n\ntemplate <int MOD> struct modint {\n\tusing value_type =\
    \ long long;\n\nprivate:\n\tvalue_type n;\n\npublic:\n\tconstexpr static modint\
    \ factorial(int n) {\n\t\tassert(n >= 0);\n\t\tmodint result = 1;\n\t\tfor (int\
    \ i = 1; i <= n; ++i) {\n\t\t\tresult *= i;\n\t\t}\n\t\treturn result;\n\t}\n\t\
    constexpr modint(const value_type x = 0) : n(x % MOD) {\n\t\tif (n < 0) n += MOD;\n\
    \t}\n\tconstexpr value_type value() const {\n\t\treturn n;\n\t}\n\tconstexpr int\
    \ mod() const {\n\t\treturn MOD;\n\t}\n\tconstexpr modint operator+() const {\n\
    \t\treturn *this;\n\t}\n\tconstexpr modint operator-() const {\n\t\treturn n ?\
    \ MOD - n : 0;\n\t}\n\tconstexpr modint& operator++() {\n\t\tif (MOD <= ++n) n\
    \ = 0;\n\t\treturn *this;\n\t}\n\tconstexpr modint& operator--() {\n\t\tif (n\
    \ <= 0) n = MOD;\n\t\tn--;\n\t\treturn *this;\n\t}\n\tconstexpr modint operator++(int)\
    \ {\n\t\tmodint t = *this;\n\t\t++*this;\n\t\treturn t;\n\t}\n\tconstexpr modint\
    \ operator--(int) {\n\t\tmodint t = *this;\n\t\t--*this;\n\t\treturn t;\n\t}\n\
    \tconstexpr modint next() const {\n\t\treturn ++modint(*this);\n\t}\n\tconstexpr\
    \ modint pred() const {\n\t\treturn --modint(*this);\n\t}\n\tconstexpr modint&\
    \ operator+=(const modint& m) {\n\t\tn += m.n;\n\t\tif (n >= MOD) n -= MOD;\n\t\
    \treturn *this;\n\t}\n\tconstexpr modint& operator-=(const modint& m) {\n\t\t\
    n -= m.n;\n\t\tif (n < 0) n += MOD;\n\t\treturn *this;\n\t}\n\tconstexpr modint&\
    \ operator*=(const modint& m) {\n\t\tn = n * m.n % MOD;\n\t\treturn *this;\n\t\
    }\n\tconstexpr modint& operator/=(const modint& m) {\n\t\tvalue_type a = m.n,\
    \ b = MOD, u = 1, v = 0;\n\t\twhile (b) {\n\t\t\tvalue_type t = a / b;\n\t\t\t\
    a -= t * b;\n\t\t\tstd::swap(a, b);\n\t\t\tu -= t * v;\n\t\t\tstd::swap(u, v);\n\
    \t\t}\n\t\tn = n * u % MOD;\n\t\tif (n < 0) n += MOD;\n\t\treturn *this;\n\t}\n\
    \tconstexpr bool operator==(const modint& m) const {\n\t\treturn n == m.n;\n\t\
    }\n\tconstexpr bool operator!=(const modint& m) const {\n\t\treturn n != m.n;\n\
    \t}\n\ttemplate <class M> constexpr modint pow(M m) const {\n\t\tif (0 <= m) {\n\
    \t\t\tmodint t = n, result = 1;\n\t\t\twhile (m > 0) {\n\t\t\t\tif (m & 1) {\n\
    \t\t\t\t\tresult *= t;\n\t\t\t\t\tm--;\n\t\t\t\t} else {\n\t\t\t\t\tt *= t;\n\t\
    \t\t\t\tm >>= 1;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn result;\n\t\t} else {\n\t\t\
    \treturn (modint(1) / n).pow(-m);\n\t\t}\n\t}\n\tfriend constexpr modint operator+(const\
    \ modint& a, const modint& b) {\n\t\treturn modint(a) += b;\n\t}\n\tfriend constexpr\
    \ modint operator-(const modint& a, const modint& b) {\n\t\treturn modint(a) -=\
    \ b;\n\t}\n\tfriend constexpr modint operator*(const modint& a, const modint&\
    \ b) {\n\t\treturn modint(a) *= b;\n\t}\n\tfriend constexpr modint operator/(const\
    \ modint& a, const modint& b) {\n\t\treturn modint(a) /= b;\n\t}\n\tfriend std::ostream&\
    \ operator<<(std::ostream& os, const modint<MOD>& m) {\n\t\treturn os << m.value();\n\
    \t}\n\tfriend std::istream& operator>>(std::istream& is, modint<MOD>& m) {\n\t\
    \tmodint<MOD>::value_type x;\n\t\tis >> x;\n\t\tm = modint(x);\n\t\treturn is;\n\
    \t}\n};\n\nusing mint = modint<get_MOD()>;\nusing VM = std::vector<mint>;\nmint\
    \ operator\"\"_m(unsigned long long n) {\n\treturn n;\n}\n"
  code: "#pragma once\n#include \"./../Utility/get_MOD.cpp\"\n#include <iostream>\n\
    #include <vector>\n#include <utility>\n#include <cassert>\n\ntemplate <int MOD>\
    \ struct modint {\n\tusing value_type = long long;\n\nprivate:\n\tvalue_type n;\n\
    \npublic:\n\tconstexpr static modint factorial(int n) {\n\t\tassert(n >= 0);\n\
    \t\tmodint result = 1;\n\t\tfor (int i = 1; i <= n; ++i) {\n\t\t\tresult *= i;\n\
    \t\t}\n\t\treturn result;\n\t}\n\tconstexpr modint(const value_type x = 0) : n(x\
    \ % MOD) {\n\t\tif (n < 0) n += MOD;\n\t}\n\tconstexpr value_type value() const\
    \ {\n\t\treturn n;\n\t}\n\tconstexpr int mod() const {\n\t\treturn MOD;\n\t}\n\
    \tconstexpr modint operator+() const {\n\t\treturn *this;\n\t}\n\tconstexpr modint\
    \ operator-() const {\n\t\treturn n ? MOD - n : 0;\n\t}\n\tconstexpr modint& operator++()\
    \ {\n\t\tif (MOD <= ++n) n = 0;\n\t\treturn *this;\n\t}\n\tconstexpr modint& operator--()\
    \ {\n\t\tif (n <= 0) n = MOD;\n\t\tn--;\n\t\treturn *this;\n\t}\n\tconstexpr modint\
    \ operator++(int) {\n\t\tmodint t = *this;\n\t\t++*this;\n\t\treturn t;\n\t}\n\
    \tconstexpr modint operator--(int) {\n\t\tmodint t = *this;\n\t\t--*this;\n\t\t\
    return t;\n\t}\n\tconstexpr modint next() const {\n\t\treturn ++modint(*this);\n\
    \t}\n\tconstexpr modint pred() const {\n\t\treturn --modint(*this);\n\t}\n\tconstexpr\
    \ modint& operator+=(const modint& m) {\n\t\tn += m.n;\n\t\tif (n >= MOD) n -=\
    \ MOD;\n\t\treturn *this;\n\t}\n\tconstexpr modint& operator-=(const modint& m)\
    \ {\n\t\tn -= m.n;\n\t\tif (n < 0) n += MOD;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ modint& operator*=(const modint& m) {\n\t\tn = n * m.n % MOD;\n\t\treturn *this;\n\
    \t}\n\tconstexpr modint& operator/=(const modint& m) {\n\t\tvalue_type a = m.n,\
    \ b = MOD, u = 1, v = 0;\n\t\twhile (b) {\n\t\t\tvalue_type t = a / b;\n\t\t\t\
    a -= t * b;\n\t\t\tstd::swap(a, b);\n\t\t\tu -= t * v;\n\t\t\tstd::swap(u, v);\n\
    \t\t}\n\t\tn = n * u % MOD;\n\t\tif (n < 0) n += MOD;\n\t\treturn *this;\n\t}\n\
    \tconstexpr bool operator==(const modint& m) const {\n\t\treturn n == m.n;\n\t\
    }\n\tconstexpr bool operator!=(const modint& m) const {\n\t\treturn n != m.n;\n\
    \t}\n\ttemplate <class M> constexpr modint pow(M m) const {\n\t\tif (0 <= m) {\n\
    \t\t\tmodint t = n, result = 1;\n\t\t\twhile (m > 0) {\n\t\t\t\tif (m & 1) {\n\
    \t\t\t\t\tresult *= t;\n\t\t\t\t\tm--;\n\t\t\t\t} else {\n\t\t\t\t\tt *= t;\n\t\
    \t\t\t\tm >>= 1;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn result;\n\t\t} else {\n\t\t\
    \treturn (modint(1) / n).pow(-m);\n\t\t}\n\t}\n\tfriend constexpr modint operator+(const\
    \ modint& a, const modint& b) {\n\t\treturn modint(a) += b;\n\t}\n\tfriend constexpr\
    \ modint operator-(const modint& a, const modint& b) {\n\t\treturn modint(a) -=\
    \ b;\n\t}\n\tfriend constexpr modint operator*(const modint& a, const modint&\
    \ b) {\n\t\treturn modint(a) *= b;\n\t}\n\tfriend constexpr modint operator/(const\
    \ modint& a, const modint& b) {\n\t\treturn modint(a) /= b;\n\t}\n\tfriend std::ostream&\
    \ operator<<(std::ostream& os, const modint<MOD>& m) {\n\t\treturn os << m.value();\n\
    \t}\n\tfriend std::istream& operator>>(std::istream& is, modint<MOD>& m) {\n\t\
    \tmodint<MOD>::value_type x;\n\t\tis >> x;\n\t\tm = modint(x);\n\t\treturn is;\n\
    \t}\n};\n\nusing mint = modint<get_MOD()>;\nusing VM = std::vector<mint>;\nmint\
    \ operator\"\"_m(unsigned long long n) {\n\treturn n;\n}\n"
  dependsOn:
  - Utility/get_MOD.cpp
  isVerificationFile: false
  path: math/modint.cpp
  requiredBy:
  - math/Combination.cpp
  timestamp: '2021-03-21 09:59:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/modint_pow.test.cpp
  - test/Partition.test.cpp
documentation_of: math/modint.cpp
layout: document
redirect_from:
- /library/math/modint.cpp
- /library/math/modint.cpp.html
title: math/modint.cpp
---