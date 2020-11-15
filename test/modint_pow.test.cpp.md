---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/modint.cpp
    title: Math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_B
  bundledCode: "#line 1 \"test/modint_pow.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_B\"\
    \n#line 2 \"Math/modint.cpp\"\n#include <iostream>\n#include <vector>\n#include\
    \ <utility>\nusing namespace std;\n\ntemplate <int MOD> struct modint {\n\tusing\
    \ T = long long;\n\tT n;\n\tconstexpr modint(const T x = 0) : n(x % MOD) {\n\t\
    \tif (n < 0) n += MOD;\n\t}\n\tconstexpr int get_mod() const {\n\t\treturn MOD;\n\
    \t}\n\tconstexpr modint operator+() const {\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ modint operator-() const {\n\t\treturn n ? MOD - n : 0;\n\t}\n\tconstexpr modint&\
    \ operator++() {\n\t\tif (MOD <= ++n) n = 0;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ modint& operator--() {\n\t\tif (n <= 0) n = MOD;\n\t\tn--;\n\t\treturn *this;\n\
    \t}\n\tconstexpr modint operator++(int) {\n\t\tmodint t = *this;\n\t\t++*this;\n\
    \t\treturn t;\n\t}\n\tconstexpr modint operator--(int) {\n\t\tmodint t = *this;\n\
    \t\t--*this;\n\t\treturn t;\n\t}\n\tconstexpr modint next() const {\n\t\treturn\
    \ ++modint(*this);\n\t}\n\tconstexpr modint pred() const {\n\t\treturn --modint(*this);\n\
    \t}\n\tconstexpr modint operator+(const modint& m) const {\n\t\treturn modint(*this)\
    \ += m;\n\t}\n\tconstexpr modint operator-(const modint& m) const {\n\t\treturn\
    \ modint(*this) -= m;\n\t}\n\tconstexpr modint operator*(const modint& m) const\
    \ {\n\t\treturn modint(*this) *= m;\n\t}\n\tconstexpr modint operator/(const modint&\
    \ m) const {\n\t\treturn modint(*this) /= m;\n\t}\n\tconstexpr modint& operator+=(const\
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
    \ const {\n\t\tif (0 <= m) {\n\t\t\tmodint t = n, res = 1;\n\t\t\twhile (m > 0)\
    \ {\n\t\t\t\tif (m & 1) res *= t;\n\t\t\t\tt *= t;\n\t\t\t\tm >>= 1;\n\t\t\t}\n\
    \t\t\treturn res;\n\t\t} else {\n\t\t\treturn (modint(1) / n).pow(-m);\n\t\t}\n\
    \t}\n\ttemplate <class M> constexpr modint operator^(M m) const {\n\t\treturn\
    \ pow(m);\n\t}\n\tfriend ostream& operator<<(ostream& os, const modint<MOD>& m)\
    \ {\n\t\treturn os << m.n;\n\t}\n\tfriend istream& operator>>(istream& is, modint<MOD>&\
    \ m) {\n\t\tlong long x;\n\t\tcin >> x;\n\t\tm = modint(x);\n\t\treturn is;\n\t\
    }\n};\nusing mint = modint<1000000007>;\nusing VM = vector<mint>;\nmint operator\"\
    \"_m(unsigned long long n) {\n\treturn n;\n}\n#line 4 \"test/modint_pow.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tint m, n;\n\tcin >> m >> n;\n\tcout\
    \ << mint(m).pow(n) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_B\"\
    \n#include \"./../Math/modint.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tint m, n;\n\tcin >> m >> n;\n\tcout << mint(m).pow(n) << '\\\
    n';\n}"
  dependsOn:
  - Math/modint.cpp
  isVerificationFile: true
  path: test/modint_pow.test.cpp
  requiredBy: []
  timestamp: '2020-11-15 09:14:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/modint_pow.test.cpp
layout: document
redirect_from:
- /verify/test/modint_pow.test.cpp
- /verify/test/modint_pow.test.cpp.html
title: test/modint_pow.test.cpp
---
