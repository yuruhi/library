---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Partition.cpp
    title: Math/Partition.cpp
  - icon: ':heavy_check_mark:'
    path: Math/modint.cpp
    title: Math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/269
    links:
    - https://yukicoder.me/problems/no/269
  bundledCode: "#line 1 \"test/Partition.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/269\"\
    \n#line 2 \"Math/Partition.cpp\"\n#include <vector>\nusing namespace std;\n\n\
    template <class T> vector<vector<T>> Partition(int num, int sum) {\n\tvector<vector<T>>\
    \ dp(num + 1, vector<T>(sum + 1));\n\tdp[0][0] = 1;\n\tfor (int i = 1; i <= num;\
    \ ++i) {\n\t\tfor (int j = 0; j <= sum; ++j) {\n\t\t\tif (j - i >= 0) {\n\t\t\t\
    \tdp[i][j] = dp[i - 1][j] + dp[i][j - i];\n\t\t\t} else {\n\t\t\t\tdp[i][j] =\
    \ dp[i - 1][j];\n\t\t\t}\n\t\t}\n\t}\n\treturn dp;\n}\n#line 2 \"Math/modint.cpp\"\
    \n#include <iostream>\n#line 4 \"Math/modint.cpp\"\n#include <utility>\nusing\
    \ namespace std;\n\ntemplate <int MOD> struct modint {\n\tusing T = long long;\n\
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
    _m(unsigned long long n) {\n\treturn n;\n}\n#line 5 \"test/Partition.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tint n, s, k;\n\tcin >> n >> s >> k;\n\
    \tint sum = s - n * (n - 1) / 2 * k;\n\tif (sum < 0) {\n\t\tcout << 0 << '\\n';\n\
    \t} else {\n\t\tcout << Partition<mint>(n, sum)[n][sum] << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/269\"\n#include \"./../Math/Partition.cpp\"\
    \n#include \"./../Math/modint.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tint n, s, k;\n\tcin >> n >> s >> k;\n\tint sum = s - n * (n\
    \ - 1) / 2 * k;\n\tif (sum < 0) {\n\t\tcout << 0 << '\\n';\n\t} else {\n\t\tcout\
    \ << Partition<mint>(n, sum)[n][sum] << '\\n';\n\t}\n}"
  dependsOn:
  - Math/Partition.cpp
  - Math/modint.cpp
  isVerificationFile: true
  path: test/Partition.test.cpp
  requiredBy: []
  timestamp: '2020-11-23 16:29:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Partition.test.cpp
layout: document
redirect_from:
- /verify/test/Partition.test.cpp
- /verify/test/Partition.test.cpp.html
title: test/Partition.test.cpp
---
