---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/Euler.cpp
    title: math/Euler.cpp
  - icon: ':heavy_check_mark:'
    path: math/PrimeFactor.cpp
    title: math/PrimeFactor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/RUPC/2286?year=2011
    links:
    - https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/RUPC/2286?year=2011
  bundledCode: "#line 1 \"test/EnumerateEuler.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/RUPC/2286?year=2011\"\
    \n#line 2 \"math/PrimeFactor.cpp\"\n#include <map>\n#include <vector>\n#include\
    \ <utility>\n#include <cassert>\nusing namespace std;\n\ntemplate <class T> vector<pair<T,\
    \ int>> PrimeFactor(T n) {\n\tassert(1 <= n);\n\tif (n == 1) {\n\t\treturn {};\n\
    \t}\n\tvector<pair<T, int>> result;\n\tfor (T i = 2; i * i <= n; ++i) {\n\t\t\
    if (n % i == 0) {\n\t\t\tresult.emplace_back(i, 0);\n\t\t\twhile (n % i == 0)\
    \ {\n\t\t\t\tresult.back().second++;\n\t\t\t\tn /= i;\n\t\t\t}\n\t\t}\n\t}\n\t\
    if (n != 1) {\n\t\tresult.emplace_back(n, 1);\n\t}\n\treturn result;\n}\ntemplate\
    \ <class T> map<T, int> PrimeFactor_map(T n) {\n\tassert(1 <= n);\n\tif (n ==\
    \ 1) {\n\t\treturn {};\n\t}\n\tmap<T, int> result;\n\tfor (T i = 2; i * i <= n;\
    \ ++i) {\n\t\twhile (n % i == 0) {\n\t\t\tresult[i]++;\n\t\t\tn /= i;\n\t\t}\n\
    \t}\n\tif (n != 1) {\n\t\tresult[n] = 1;\n\t}\n\treturn result;\n}\ntemplate <class\
    \ T> vector<T> PrimeFactor_vector(T n) {\n\tassert(1 <= n);\n\tif (n == 1) {\n\
    \t\treturn {};\n\t}\n\tvector<T> result;\n\tfor (T i = 2; i * i <= n; ++i) {\n\
    \t\twhile (n % i == 0) {\n\t\t\tresult.push_back(i);\n\t\t\tn /= i;\n\t\t}\n\t\
    }\n\tif (n != 1) {\n\t\tresult.push_back(n);\n\t}\n\treturn result;\n}\n#line\
    \ 3 \"math/Euler.cpp\"\n#include <numeric>\n\ntemplate <class T> T Euler(T x)\
    \ {\n\tT result = x;\n\tfor (auto [p, e] : PrimeFactor(x)) {\n\t\tresult = result\
    \ / p * (p - 1);\n\t}\n\treturn result;\n}\n\nvector<int> EnumerateEuler(int x)\
    \ {\n\tvector<int> result(x + 1);\n\tiota(result.begin(), result.end(), 0);\n\t\
    for (int i = 2; i <= x; ++i) {\n\t\tif (result[i] == i) {\n\t\t\tfor (int j =\
    \ i; j <= x; j += i) {\n\t\t\t\tresult[j] = result[j] / i * (i - 1);\n\t\t\t}\n\
    \t\t}\n\t}\n\treturn result;\n}\n#line 3 \"test/EnumerateEuler.test.cpp\"\n#include\
    \ <iostream>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tconst int MAX_A = 1000000;\n\tvector<int> euler = EnumerateEuler(MAX_A);\n\
    \tvector<long long> ans(MAX_A + 1, 1);\n\tfor (int i = 1; i <= MAX_A; ++i) {\n\
    \t\tans[i] = ans[i - 1] + euler[i];\n\t}\n\n\tint q;\n\tcin >> q;\n\twhile (q--)\
    \ {\n\t\tint x;\n\t\tcin >> x;\n\t\tcout << ans[x] << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/RUPC/2286?year=2011\"\
    \n#include \"./../math/Euler.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\n\t\
    const int MAX_A = 1000000;\n\tvector<int> euler = EnumerateEuler(MAX_A);\n\tvector<long\
    \ long> ans(MAX_A + 1, 1);\n\tfor (int i = 1; i <= MAX_A; ++i) {\n\t\tans[i] =\
    \ ans[i - 1] + euler[i];\n\t}\n\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\t\
    int x;\n\t\tcin >> x;\n\t\tcout << ans[x] << '\\n';\n\t}\n}"
  dependsOn:
  - math/Euler.cpp
  - math/PrimeFactor.cpp
  isVerificationFile: true
  path: test/EnumerateEuler.test.cpp
  requiredBy: []
  timestamp: '2021-03-07 15:45:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/EnumerateEuler.test.cpp
layout: document
redirect_from:
- /verify/test/EnumerateEuler.test.cpp
- /verify/test/EnumerateEuler.test.cpp.html
title: test/EnumerateEuler.test.cpp
---
