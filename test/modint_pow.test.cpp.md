---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/get_MOD.cpp
    title: Utility/get_MOD.cpp
  - icon: ':heavy_check_mark:'
    path: math/modint.cpp
    title: math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_B
  bundledCode: "#line 1 \"test/modint_pow.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_B\"\
    \n#line 2 \"Utility/get_MOD.cpp\"\nconstexpr long long get_MOD() {\n#ifdef SET_MOD\n\
    \treturn SET_MOD;\n#else\n\treturn 1000000007;\n#endif\n}\n#line 3 \"math/modint.cpp\"\
    \n#include <iostream>\n#include <vector>\n#include <utility>\n#include <cassert>\n\
    \ntemplate <int MOD> struct modint {\n\tusing value_type = long long;\n\nprivate:\n\
    \tvalue_type n;\n\npublic:\n\tconstexpr static modint factorial(int n) {\n\t\t\
    assert(n >= 0);\n\t\tmodint result = 1;\n\t\tfor (int i = 1; i <= n; ++i) {\n\t\
    \t\tresult *= i;\n\t\t}\n\t\treturn result;\n\t}\n\tconstexpr modint(const value_type\
    \ x = 0) : n(x % MOD) {\n\t\tif (n < 0) n += MOD;\n\t}\n\tconstexpr value_type\
    \ value() const {\n\t\treturn n;\n\t}\n\tconstexpr int mod() const {\n\t\treturn\
    \ MOD;\n\t}\n\tconstexpr modint operator+() const {\n\t\treturn *this;\n\t}\n\t\
    constexpr modint operator-() const {\n\t\treturn n ? MOD - n : 0;\n\t}\n\tconstexpr\
    \ modint& operator++() {\n\t\tif (MOD <= ++n) n = 0;\n\t\treturn *this;\n\t}\n\
    \tconstexpr modint& operator--() {\n\t\tif (n <= 0) n = MOD;\n\t\tn--;\n\t\treturn\
    \ *this;\n\t}\n\tconstexpr modint operator++(int) {\n\t\tmodint t = *this;\n\t\
    \t++*this;\n\t\treturn t;\n\t}\n\tconstexpr modint operator--(int) {\n\t\tmodint\
    \ t = *this;\n\t\t--*this;\n\t\treturn t;\n\t}\n\tconstexpr modint next() const\
    \ {\n\t\treturn ++modint(*this);\n\t}\n\tconstexpr modint pred() const {\n\t\t\
    return --modint(*this);\n\t}\n\tconstexpr modint& operator+=(const modint& m)\
    \ {\n\t\tn += m.n;\n\t\tif (n >= MOD) n -= MOD;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ modint& operator-=(const modint& m) {\n\t\tn -= m.n;\n\t\tif (n < 0) n += MOD;\n\
    \t\treturn *this;\n\t}\n\tconstexpr modint& operator*=(const modint& m) {\n\t\t\
    n = n * m.n % MOD;\n\t\treturn *this;\n\t}\n\tconstexpr modint& operator/=(const\
    \ modint& m) {\n\t\tvalue_type a = m.n, b = MOD, u = 1, v = 0;\n\t\twhile (b)\
    \ {\n\t\t\tvalue_type t = a / b;\n\t\t\ta -= t * b;\n\t\t\tstd::swap(a, b);\n\t\
    \t\tu -= t * v;\n\t\t\tstd::swap(u, v);\n\t\t}\n\t\tn = n * u % MOD;\n\t\tif (n\
    \ < 0) n += MOD;\n\t\treturn *this;\n\t}\n\tconstexpr bool operator==(const modint&\
    \ m) const {\n\t\treturn n == m.n;\n\t}\n\tconstexpr bool operator!=(const modint&\
    \ m) const {\n\t\treturn n != m.n;\n\t}\n\ttemplate <class M> constexpr modint\
    \ pow(M m) const {\n\t\tif (0 <= m) {\n\t\t\tmodint t = n, result = 1;\n\t\t\t\
    while (m > 0) {\n\t\t\t\tif (m & 1) {\n\t\t\t\t\tresult *= t;\n\t\t\t\t\tm--;\n\
    \t\t\t\t} else {\n\t\t\t\t\tt *= t;\n\t\t\t\t\tm >>= 1;\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\treturn result;\n\t\t} else {\n\t\t\treturn (modint(1) / n).pow(-m);\n\t\t\
    }\n\t}\n\tfriend constexpr modint operator+(const modint& a, const modint& b)\
    \ {\n\t\treturn modint(a) += b;\n\t}\n\tfriend constexpr modint operator-(const\
    \ modint& a, const modint& b) {\n\t\treturn modint(a) -= b;\n\t}\n\tfriend constexpr\
    \ modint operator*(const modint& a, const modint& b) {\n\t\treturn modint(a) *=\
    \ b;\n\t}\n\tfriend constexpr modint operator/(const modint& a, const modint&\
    \ b) {\n\t\treturn modint(a) /= b;\n\t}\n\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const modint<MOD>& m) {\n\t\treturn os << m.value();\n\t}\n\tfriend std::istream&\
    \ operator>>(std::istream& is, modint<MOD>& m) {\n\t\tmodint<MOD>::value_type\
    \ x;\n\t\tis >> x;\n\t\tm = modint(x);\n\t\treturn is;\n\t}\n\ttemplate <class\
    \ Scanner> void scan() {\n\t\tScanner::scan(n);\n\t\tn %= MOD;\n\t\tif (n < 0)\
    \ n += MOD;\n\t}\n\ttemplate <class Printer> void print(const Printer& out) const\
    \ {\n\t\tout.print(value());\n\t}\n};\n\nusing mint = modint<get_MOD()>;\nusing\
    \ VM = std::vector<mint>;\nmint operator\"\"_m(unsigned long long n) {\n\treturn\
    \ n;\n}\n#line 4 \"test/modint_pow.test.cpp\"\nusing namespace std;\n\nint main()\
    \ {\n\tint m, n;\n\tcin >> m >> n;\n\tcout << mint(m).pow(n) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_B\"\
    \n#include \"./../math/modint.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tint m, n;\n\tcin >> m >> n;\n\tcout << mint(m).pow(n) << '\\\
    n';\n}"
  dependsOn:
  - math/modint.cpp
  - Utility/get_MOD.cpp
  isVerificationFile: true
  path: test/modint_pow.test.cpp
  requiredBy: []
  timestamp: '2021-04-19 17:40:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/modint_pow.test.cpp
layout: document
redirect_from:
- /verify/test/modint_pow.test.cpp
- /verify/test/modint_pow.test.cpp.html
title: test/modint_pow.test.cpp
---
