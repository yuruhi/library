---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/modintRuntime.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <iostream>\nusing namespace std;\n\nstruct mint {\n\tusing T = long long;\n\
    \tstatic T MOD;\n\tT n;\n\npublic:\n\tstatic void set_mod(T _MOD) {\n\t\tMOD =\
    \ _MOD;\n\t}\n\tmint(T x = 0) : n(x % MOD) {\n\t\tif (n < 0) n += MOD;\n\t}\n\t\
    mint operator+() const {\n\t\treturn *this;\n\t}\n\tmint operator-() const {\n\
    \t\treturn n ? MOD - n : 0;\n\t}\n\tmint& operator++() {\n\t\tif (MOD <= ++n)\
    \ n = 0;\n\t\treturn *this;\n\t}\n\tmint& operator--() {\n\t\tif (n <= 0) n =\
    \ MOD;\n\t\tn--;\n\t\treturn *this;\n\t}\n\tmint operator++(int) {\n\t\tmint t\
    \ = *this;\n\t\t++*this;\n\t\treturn t;\n\t}\n\tmint operator--(int) {\n\t\tmint\
    \ t = *this;\n\t\t--*this;\n\t\treturn t;\n\t}\n\tmint next() const {\n\t\treturn\
    \ ++mint(*this);\n\t}\n\tmint pred() const {\n\t\treturn --mint(*this);\n\t}\n\
    \tmint operator+(const mint& m) const {\n\t\treturn mint(*this) += m;\n\t}\n\t\
    mint operator-(const mint& m) const {\n\t\treturn mint(*this) -= m;\n\t}\n\tmint\
    \ operator*(const mint& m) const {\n\t\treturn mint(*this) *= m;\n\t}\n\tmint\
    \ operator/(const mint& m) const {\n\t\treturn mint(*this) /= m;\n\t}\n\tmint&\
    \ operator+=(const mint& m) {\n\t\tn += m.n;\n\t\tif (n >= MOD) n -= MOD;\n\t\t\
    return *this;\n\t}\n\tmint& operator-=(const mint& m) {\n\t\tn -= m.n;\n\t\tif\
    \ (n < 0) n += MOD;\n\t\treturn *this;\n\t}\n\tmint& operator*=(const mint& m)\
    \ {\n\t\tn = n * m.n % MOD;\n\t\treturn *this;\n\t}\n\tmint& operator/=(const\
    \ mint& m) {\n\t\tT a = m.n, b = MOD, u = 1, v = 0;\n\t\twhile (b) {\n\t\t\tT\
    \ t = a / b;\n\t\t\ta -= t * b;\n\t\t\tswap(a, b);\n\t\t\tu -= t * v;\n\t\t\t\
    swap(u, v);\n\t\t}\n\t\tn = n * u % MOD;\n\t\tif (n < 0) n += MOD;\n\t\treturn\
    \ *this;\n\t}\n\tbool operator==(const mint& m) const {\n\t\treturn n == m.n;\n\
    \t}\n\tbool operator!=(const mint& m) const {\n\t\treturn n != m.n;\n\t}\n\ttemplate\
    \ <class M> mint pow(M m) const {\n\t\tmint t = n, result = 1;\n\t\twhile (m >\
    \ 0) {\n\t\t\tif (m & 1) {\n\t\t\t\tresult *= t;\n\t\t\t\tm--;\n\t\t\t} else {\n\
    \t\t\t\tt *= t;\n\t\t\t\tm >>= 1;\n\t\t\t}\n\t\t}\n\t\treturn result;\n\t}\n\t\
    template <class M> mint operator^(M m) const {\n\t\treturn pow(m);\n\t}\n\tfriend\
    \ ostream& operator<<(ostream& os, const mint& m) {\n\t\treturn os << m.n;\n\t\
    }\n\tfriend istream& operator>>(istream& is, mint& m) {\n\t\tlong long x;\n\t\t\
    cin >> x;\n\t\tm = mint(x);\n\t\treturn is;\n\t}\n\tfriend mint operator\"\"_m(unsigned\
    \ long long n) {\n\t\treturn n;\n\t}\n};\nlong long mint::MOD = 1000000007;\n\
    using VM = vector<mint>;\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <iostream>\n\
    using namespace std;\n\nstruct mint {\n\tusing T = long long;\n\tstatic T MOD;\n\
    \tT n;\n\npublic:\n\tstatic void set_mod(T _MOD) {\n\t\tMOD = _MOD;\n\t}\n\tmint(T\
    \ x = 0) : n(x % MOD) {\n\t\tif (n < 0) n += MOD;\n\t}\n\tmint operator+() const\
    \ {\n\t\treturn *this;\n\t}\n\tmint operator-() const {\n\t\treturn n ? MOD -\
    \ n : 0;\n\t}\n\tmint& operator++() {\n\t\tif (MOD <= ++n) n = 0;\n\t\treturn\
    \ *this;\n\t}\n\tmint& operator--() {\n\t\tif (n <= 0) n = MOD;\n\t\tn--;\n\t\t\
    return *this;\n\t}\n\tmint operator++(int) {\n\t\tmint t = *this;\n\t\t++*this;\n\
    \t\treturn t;\n\t}\n\tmint operator--(int) {\n\t\tmint t = *this;\n\t\t--*this;\n\
    \t\treturn t;\n\t}\n\tmint next() const {\n\t\treturn ++mint(*this);\n\t}\n\t\
    mint pred() const {\n\t\treturn --mint(*this);\n\t}\n\tmint operator+(const mint&\
    \ m) const {\n\t\treturn mint(*this) += m;\n\t}\n\tmint operator-(const mint&\
    \ m) const {\n\t\treturn mint(*this) -= m;\n\t}\n\tmint operator*(const mint&\
    \ m) const {\n\t\treturn mint(*this) *= m;\n\t}\n\tmint operator/(const mint&\
    \ m) const {\n\t\treturn mint(*this) /= m;\n\t}\n\tmint& operator+=(const mint&\
    \ m) {\n\t\tn += m.n;\n\t\tif (n >= MOD) n -= MOD;\n\t\treturn *this;\n\t}\n\t\
    mint& operator-=(const mint& m) {\n\t\tn -= m.n;\n\t\tif (n < 0) n += MOD;\n\t\
    \treturn *this;\n\t}\n\tmint& operator*=(const mint& m) {\n\t\tn = n * m.n % MOD;\n\
    \t\treturn *this;\n\t}\n\tmint& operator/=(const mint& m) {\n\t\tT a = m.n, b\
    \ = MOD, u = 1, v = 0;\n\t\twhile (b) {\n\t\t\tT t = a / b;\n\t\t\ta -= t * b;\n\
    \t\t\tswap(a, b);\n\t\t\tu -= t * v;\n\t\t\tswap(u, v);\n\t\t}\n\t\tn = n * u\
    \ % MOD;\n\t\tif (n < 0) n += MOD;\n\t\treturn *this;\n\t}\n\tbool operator==(const\
    \ mint& m) const {\n\t\treturn n == m.n;\n\t}\n\tbool operator!=(const mint& m)\
    \ const {\n\t\treturn n != m.n;\n\t}\n\ttemplate <class M> mint pow(M m) const\
    \ {\n\t\tmint t = n, result = 1;\n\t\twhile (m > 0) {\n\t\t\tif (m & 1) {\n\t\t\
    \t\tresult *= t;\n\t\t\t\tm--;\n\t\t\t} else {\n\t\t\t\tt *= t;\n\t\t\t\tm >>=\
    \ 1;\n\t\t\t}\n\t\t}\n\t\treturn result;\n\t}\n\ttemplate <class M> mint operator^(M\
    \ m) const {\n\t\treturn pow(m);\n\t}\n\tfriend ostream& operator<<(ostream& os,\
    \ const mint& m) {\n\t\treturn os << m.n;\n\t}\n\tfriend istream& operator>>(istream&\
    \ is, mint& m) {\n\t\tlong long x;\n\t\tcin >> x;\n\t\tm = mint(x);\n\t\treturn\
    \ is;\n\t}\n\tfriend mint operator\"\"_m(unsigned long long n) {\n\t\treturn n;\n\
    \t}\n};\nlong long mint::MOD = 1000000007;\nusing VM = vector<mint>;\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/modintRuntime.cpp
  requiredBy: []
  timestamp: '2020-11-23 14:52:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/modintRuntime.cpp
layout: document
redirect_from:
- /library/Math/modintRuntime.cpp
- /library/Math/modintRuntime.cpp.html
title: Math/modintRuntime.cpp
---