---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/get_MOD.cpp
    title: Utility/get_MOD.cpp
  - icon: ':heavy_check_mark:'
    path: math/Partition.cpp
    title: math/Partition.cpp
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
    PROBLEM: https://yukicoder.me/problems/no/269
    links:
    - https://yukicoder.me/problems/no/269
  bundledCode: "#line 1 \"test/Partition.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/269\"\
    \n#line 2 \"math/Partition.cpp\"\n#include <vector>\nusing namespace std;\n\n\
    template <class T> vector<vector<T>> Partition(int num, int sum) {\n\tvector<vector<T>>\
    \ dp(num + 1, vector<T>(sum + 1));\n\tdp[0][0] = 1;\n\tfor (int i = 1; i <= num;\
    \ ++i) {\n\t\tfor (int j = 0; j <= sum; ++j) {\n\t\t\tif (j - i >= 0) {\n\t\t\t\
    \tdp[i][j] = dp[i - 1][j] + dp[i][j - i];\n\t\t\t} else {\n\t\t\t\tdp[i][j] =\
    \ dp[i - 1][j];\n\t\t\t}\n\t\t}\n\t}\n\treturn dp;\n}\n#line 2 \"Utility/get_MOD.cpp\"\
    \nconstexpr long long get_MOD() {\n#ifdef SET_MOD\n\treturn SET_MOD;\n#else\n\t\
    return 1000000007;\n#endif\n}\n#line 3 \"math/modint.cpp\"\n#include <iostream>\n\
    #line 5 \"math/modint.cpp\"\n#include <utility>\n#include <cassert>\n\ntemplate\
    \ <int MOD> struct modint {\n\tusing value_type = long long;\n\nprivate:\n\tvalue_type\
    \ n;\n\npublic:\n\tconstexpr static modint factorial(int n) {\n\t\tassert(n >=\
    \ 0);\n\t\tmodint result = 1;\n\t\tfor (int i = 1; i <= n; ++i) {\n\t\t\tresult\
    \ *= i;\n\t\t}\n\t\treturn result;\n\t}\n\tconstexpr modint(const value_type x\
    \ = 0) : n(x % MOD) {\n\t\tif (n < 0) n += MOD;\n\t}\n\tconstexpr value_type value()\
    \ const {\n\t\treturn n;\n\t}\n\tconstexpr int mod() const {\n\t\treturn MOD;\n\
    \t}\n\tconstexpr modint operator+() const {\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ modint operator-() const {\n\t\treturn n ? MOD - n : 0;\n\t}\n\tconstexpr modint&\
    \ operator++() {\n\t\tif (MOD <= ++n) n = 0;\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ modint& operator--() {\n\t\tif (n <= 0) n = MOD;\n\t\tn--;\n\t\treturn *this;\n\
    \t}\n\tconstexpr modint operator++(int) {\n\t\tmodint t = *this;\n\t\t++*this;\n\
    \t\treturn t;\n\t}\n\tconstexpr modint operator--(int) {\n\t\tmodint t = *this;\n\
    \t\t--*this;\n\t\treturn t;\n\t}\n\tconstexpr modint next() const {\n\t\treturn\
    \ ++modint(*this);\n\t}\n\tconstexpr modint pred() const {\n\t\treturn --modint(*this);\n\
    \t}\n\tconstexpr modint& operator+=(const modint& m) {\n\t\tn += m.n;\n\t\tif\
    \ (n >= MOD) n -= MOD;\n\t\treturn *this;\n\t}\n\tconstexpr modint& operator-=(const\
    \ modint& m) {\n\t\tn -= m.n;\n\t\tif (n < 0) n += MOD;\n\t\treturn *this;\n\t\
    }\n\tconstexpr modint& operator*=(const modint& m) {\n\t\tn = n * m.n % MOD;\n\
    \t\treturn *this;\n\t}\n\tconstexpr modint& operator/=(const modint& m) {\n\t\t\
    value_type a = m.n, b = MOD, u = 1, v = 0;\n\t\twhile (b) {\n\t\t\tvalue_type\
    \ t = a / b;\n\t\t\ta -= t * b;\n\t\t\tstd::swap(a, b);\n\t\t\tu -= t * v;\n\t\
    \t\tstd::swap(u, v);\n\t\t}\n\t\tn = n * u % MOD;\n\t\tif (n < 0) n += MOD;\n\t\
    \treturn *this;\n\t}\n\tconstexpr bool operator==(const modint& m) const {\n\t\
    \treturn n == m.n;\n\t}\n\tconstexpr bool operator!=(const modint& m) const {\n\
    \t\treturn n != m.n;\n\t}\n\ttemplate <class M> constexpr modint pow(M m) const\
    \ {\n\t\tif (0 <= m) {\n\t\t\tmodint t = n, result = 1;\n\t\t\twhile (m > 0) {\n\
    \t\t\t\tif (m & 1) {\n\t\t\t\t\tresult *= t;\n\t\t\t\t\tm--;\n\t\t\t\t} else {\n\
    \t\t\t\t\tt *= t;\n\t\t\t\t\tm >>= 1;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn result;\n\
    \t\t} else {\n\t\t\treturn (modint(1) / n).pow(-m);\n\t\t}\n\t}\n\tfriend constexpr\
    \ modint operator+(const modint& a, const modint& b) {\n\t\treturn modint(a) +=\
    \ b;\n\t}\n\tfriend constexpr modint operator-(const modint& a, const modint&\
    \ b) {\n\t\treturn modint(a) -= b;\n\t}\n\tfriend constexpr modint operator*(const\
    \ modint& a, const modint& b) {\n\t\treturn modint(a) *= b;\n\t}\n\tfriend constexpr\
    \ modint operator/(const modint& a, const modint& b) {\n\t\treturn modint(a) /=\
    \ b;\n\t}\n\tfriend std::ostream& operator<<(std::ostream& os, const modint<MOD>&\
    \ m) {\n\t\treturn os << m.value();\n\t}\n\tfriend std::istream& operator>>(std::istream&\
    \ is, modint<MOD>& m) {\n\t\tmodint<MOD>::value_type x;\n\t\tstd::cin >> x;\n\t\
    \tm = modint(x);\n\t\treturn is;\n\t}\n};\n\nusing mint = modint<get_MOD()>;\n\
    using VM = std::vector<mint>;\nmint operator\"\"_m(unsigned long long n) {\n\t\
    return n;\n}\n#line 5 \"test/Partition.test.cpp\"\nusing namespace std;\n\nint\
    \ main() {\n\tint n, s, k;\n\tcin >> n >> s >> k;\n\tint sum = s - n * (n - 1)\
    \ / 2 * k;\n\tif (sum < 0) {\n\t\tcout << 0 << '\\n';\n\t} else {\n\t\tcout <<\
    \ Partition<mint>(n, sum)[n][sum] << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/269\"\n#include \"./../math/Partition.cpp\"\
    \n#include \"./../math/modint.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tint n, s, k;\n\tcin >> n >> s >> k;\n\tint sum = s - n * (n\
    \ - 1) / 2 * k;\n\tif (sum < 0) {\n\t\tcout << 0 << '\\n';\n\t} else {\n\t\tcout\
    \ << Partition<mint>(n, sum)[n][sum] << '\\n';\n\t}\n}"
  dependsOn:
  - math/Partition.cpp
  - math/modint.cpp
  - Utility/get_MOD.cpp
  isVerificationFile: true
  path: test/Partition.test.cpp
  requiredBy: []
  timestamp: '2021-03-18 10:36:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Partition.test.cpp
layout: document
redirect_from:
- /verify/test/Partition.test.cpp
- /verify/test/Partition.test.cpp.html
title: test/Partition.test.cpp
---
