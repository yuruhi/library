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
  bundledCode: "#line 2 \"math/modintRuntime.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <iostream>\n\nstruct mint {\n\tusing value_type = long long;\n\tinline\
    \ static value_type MOD = 1000000007;\n\nprivate:\n\tvalue_type n;\n\npublic:\n\
    \tstatic modint factorial(int n) {\n\t\tassert(n >= 0);\n\t\tmodint result = 1;\n\
    \t\tfor (int i = 1; i <= n; ++i) {\n\t\t\tresult *= i;\n\t\t}\n\t\treturn result;\n\
    \t}\n\tmint(value_type x = 0) : n(x % MOD) {\n\t\tif (n < 0) n += MOD;\n\t}\n\t\
    value_type value() const {\n\t\treturn n;\n\t}\n\tmint operator+() const {\n\t\
    \treturn *this;\n\t}\n\tmint operator-() const {\n\t\treturn n ? MOD - n : 0;\n\
    \t}\n\tmint& operator++() {\n\t\tif (MOD <= ++n) n = 0;\n\t\treturn *this;\n\t\
    }\n\tmint& operator--() {\n\t\tif (n <= 0) n = MOD;\n\t\tn--;\n\t\treturn *this;\n\
    \t}\n\tmint operator++(int) {\n\t\tmint t = *this;\n\t\t++*this;\n\t\treturn t;\n\
    \t}\n\tmint operator--(int) {\n\t\tmint t = *this;\n\t\t--*this;\n\t\treturn t;\n\
    \t}\n\tmint next() const {\n\t\treturn ++mint(*this);\n\t}\n\tmint pred() const\
    \ {\n\t\treturn --mint(*this);\n\t}\n\tmint operator+(const mint& m) const {\n\
    \t\treturn mint(*this) += m;\n\t}\n\tmint operator-(const mint& m) const {\n\t\
    \treturn mint(*this) -= m;\n\t}\n\tmint operator*(const mint& m) const {\n\t\t\
    return mint(*this) *= m;\n\t}\n\tmint operator/(const mint& m) const {\n\t\treturn\
    \ mint(*this) /= m;\n\t}\n\tmint& operator+=(const mint& m) {\n\t\tn += m.n;\n\
    \t\tif (n >= MOD) n -= MOD;\n\t\treturn *this;\n\t}\n\tmint& operator-=(const\
    \ mint& m) {\n\t\tn -= m.n;\n\t\tif (n < 0) n += MOD;\n\t\treturn *this;\n\t}\n\
    \tmint& operator*=(const mint& m) {\n\t\tn = n * m.n % MOD;\n\t\treturn *this;\n\
    \t}\n\tmint& operator/=(const mint& m) {\n\t\tvalue_type a = m.n, b = MOD, u =\
    \ 1, v = 0;\n\t\twhile (b) {\n\t\t\tvalue_type t = a / b;\n\t\t\ta -= t * b;\n\
    \t\t\tstd::swap(a, b);\n\t\t\tu -= t * v;\n\t\t\tstd::swap(u, v);\n\t\t}\n\t\t\
    n = n * u % MOD;\n\t\tif (n < 0) n += MOD;\n\t\treturn *this;\n\t}\n\tbool operator==(const\
    \ mint& m) const {\n\t\treturn n == m.n;\n\t}\n\tbool operator!=(const mint& m)\
    \ const {\n\t\treturn n != m.n;\n\t}\n\ttemplate <class M> mint pow(M m) const\
    \ {\n\t\tmint t = n, result = 1;\n\t\twhile (m > 0) {\n\t\t\tif (m & 1) {\n\t\t\
    \t\tresult *= t;\n\t\t\t\tm--;\n\t\t\t} else {\n\t\t\t\tt *= t;\n\t\t\t\tm >>=\
    \ 1;\n\t\t\t}\n\t\t}\n\t\treturn result;\n\t}\n\ttemplate <class M> mint operator^(M\
    \ m) const {\n\t\treturn pow(m);\n\t}\n\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const mint& m) {\n\t\treturn os << m.n;\n\t}\n\tfriend std::istream& operator>>(std::istream&\
    \ is, mint& m) {\n\t\tvalue_type x;\n\t\tstd::cin >> x;\n\t\tm = mint(x);\n\t\t\
    return is;\n\t}\n\ttemplate <class Scanner> void scan() {\n\t\tScanner::scan(n);\n\
    \t\tn %= MOD;\n\t\tif (n < 0) n += MOD;\n\t}\n\ttemplate <class Printer> void\
    \ print(const Printer& out) const {\n\t\tout.print(value());\n\t}\n\tfriend mint\
    \ operator\"\"_m(unsigned long long n) {\n\t\treturn n;\n\t}\n};\nusing VM = vector<mint>;\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <iostream>\n\
    \nstruct mint {\n\tusing value_type = long long;\n\tinline static value_type MOD\
    \ = 1000000007;\n\nprivate:\n\tvalue_type n;\n\npublic:\n\tstatic modint factorial(int\
    \ n) {\n\t\tassert(n >= 0);\n\t\tmodint result = 1;\n\t\tfor (int i = 1; i <=\
    \ n; ++i) {\n\t\t\tresult *= i;\n\t\t}\n\t\treturn result;\n\t}\n\tmint(value_type\
    \ x = 0) : n(x % MOD) {\n\t\tif (n < 0) n += MOD;\n\t}\n\tvalue_type value() const\
    \ {\n\t\treturn n;\n\t}\n\tmint operator+() const {\n\t\treturn *this;\n\t}\n\t\
    mint operator-() const {\n\t\treturn n ? MOD - n : 0;\n\t}\n\tmint& operator++()\
    \ {\n\t\tif (MOD <= ++n) n = 0;\n\t\treturn *this;\n\t}\n\tmint& operator--()\
    \ {\n\t\tif (n <= 0) n = MOD;\n\t\tn--;\n\t\treturn *this;\n\t}\n\tmint operator++(int)\
    \ {\n\t\tmint t = *this;\n\t\t++*this;\n\t\treturn t;\n\t}\n\tmint operator--(int)\
    \ {\n\t\tmint t = *this;\n\t\t--*this;\n\t\treturn t;\n\t}\n\tmint next() const\
    \ {\n\t\treturn ++mint(*this);\n\t}\n\tmint pred() const {\n\t\treturn --mint(*this);\n\
    \t}\n\tmint operator+(const mint& m) const {\n\t\treturn mint(*this) += m;\n\t\
    }\n\tmint operator-(const mint& m) const {\n\t\treturn mint(*this) -= m;\n\t}\n\
    \tmint operator*(const mint& m) const {\n\t\treturn mint(*this) *= m;\n\t}\n\t\
    mint operator/(const mint& m) const {\n\t\treturn mint(*this) /= m;\n\t}\n\tmint&\
    \ operator+=(const mint& m) {\n\t\tn += m.n;\n\t\tif (n >= MOD) n -= MOD;\n\t\t\
    return *this;\n\t}\n\tmint& operator-=(const mint& m) {\n\t\tn -= m.n;\n\t\tif\
    \ (n < 0) n += MOD;\n\t\treturn *this;\n\t}\n\tmint& operator*=(const mint& m)\
    \ {\n\t\tn = n * m.n % MOD;\n\t\treturn *this;\n\t}\n\tmint& operator/=(const\
    \ mint& m) {\n\t\tvalue_type a = m.n, b = MOD, u = 1, v = 0;\n\t\twhile (b) {\n\
    \t\t\tvalue_type t = a / b;\n\t\t\ta -= t * b;\n\t\t\tstd::swap(a, b);\n\t\t\t\
    u -= t * v;\n\t\t\tstd::swap(u, v);\n\t\t}\n\t\tn = n * u % MOD;\n\t\tif (n <\
    \ 0) n += MOD;\n\t\treturn *this;\n\t}\n\tbool operator==(const mint& m) const\
    \ {\n\t\treturn n == m.n;\n\t}\n\tbool operator!=(const mint& m) const {\n\t\t\
    return n != m.n;\n\t}\n\ttemplate <class M> mint pow(M m) const {\n\t\tmint t\
    \ = n, result = 1;\n\t\twhile (m > 0) {\n\t\t\tif (m & 1) {\n\t\t\t\tresult *=\
    \ t;\n\t\t\t\tm--;\n\t\t\t} else {\n\t\t\t\tt *= t;\n\t\t\t\tm >>= 1;\n\t\t\t\
    }\n\t\t}\n\t\treturn result;\n\t}\n\ttemplate <class M> mint operator^(M m) const\
    \ {\n\t\treturn pow(m);\n\t}\n\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const mint& m) {\n\t\treturn os << m.n;\n\t}\n\tfriend std::istream& operator>>(std::istream&\
    \ is, mint& m) {\n\t\tvalue_type x;\n\t\tstd::cin >> x;\n\t\tm = mint(x);\n\t\t\
    return is;\n\t}\n\ttemplate <class Scanner> void scan() {\n\t\tScanner::scan(n);\n\
    \t\tn %= MOD;\n\t\tif (n < 0) n += MOD;\n\t}\n\ttemplate <class Printer> void\
    \ print(const Printer& out) const {\n\t\tout.print(value());\n\t}\n\tfriend mint\
    \ operator\"\"_m(unsigned long long n) {\n\t\treturn n;\n\t}\n};\nusing VM = vector<mint>;\n"
  dependsOn: []
  isVerificationFile: false
  path: math/modintRuntime.cpp
  requiredBy: []
  timestamp: '2021-04-19 17:40:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modintRuntime.cpp
layout: document
redirect_from:
- /library/math/modintRuntime.cpp
- /library/math/modintRuntime.cpp.html
title: math/modintRuntime.cpp
---
