---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Euler.cpp
    title: Math/Euler.cpp
  - icon: ':heavy_check_mark:'
    path: Math/PrimeFactor.cpp
    title: Math/PrimeFactor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/RUPC/2286?year=2011
    links:
    - https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/RUPC/2286?year=2011
  bundledCode: "#line 1 \"test/EnumrateEuler.test.cpp\"\n#define PROBLEM \\\n\t\"\
    https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/RUPC/2286?year=2011\"\n\
    #line 2 \"Math/PrimeFactor.cpp\"\n#include <map>\n#include <vector>\n#include\
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
    \ 3 \"Math/Euler.cpp\"\n#include <numeric>\n\ntemplate <class T> T Euler(T x)\
    \ {\n\tT result = x;\n\tfor (auto [p, e] : PrimeFactor(x)) {\n\t\tresult = result\
    \ / p * (p - 1);\n\t}\n\treturn result;\n}\n\nvector<int> EnumrateEuler(int x)\
    \ {\n\tvector<int> result(x + 1);\n\tiota(result.begin(), result.end(), 0);\n\t\
    for (int i = 2; i <= x; ++i) {\n\t\tif (result[i] == i) {\n\t\t\tfor (int j =\
    \ i; j <= x; j += i) {\n\t\t\t\tresult[j] = result[j] / i * (i - 1);\n\t\t\t}\n\
    \t\t}\n\t}\n\treturn result;\n}\n#line 4 \"test/EnumrateEuler.test.cpp\"\n#include\
    \ <iostream>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tconst int MAX_A = 1000000;\n\tvector<int> euler = EnumrateEuler(MAX_A);\n\t\
    vector<long long> ans(MAX_A + 1, 1);\n\tfor (int i = 1; i <= MAX_A; ++i) {\n\t\
    \tans[i] = ans[i - 1] + euler[i];\n\t}\n\n\tint q;\n\tcin >> q;\n\twhile (q--)\
    \ {\n\t\tint x;\n\t\tcin >> x;\n\t\tcout << ans[x] << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \\\n\t\"https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/RUPC/2286?year=2011\"\
    \n#include \"./../Math/Euler.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\n\t\
    const int MAX_A = 1000000;\n\tvector<int> euler = EnumrateEuler(MAX_A);\n\tvector<long\
    \ long> ans(MAX_A + 1, 1);\n\tfor (int i = 1; i <= MAX_A; ++i) {\n\t\tans[i] =\
    \ ans[i - 1] + euler[i];\n\t}\n\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\t\
    int x;\n\t\tcin >> x;\n\t\tcout << ans[x] << '\\n';\n\t}\n}"
  dependsOn:
  - Math/Euler.cpp
  - Math/PrimeFactor.cpp
  isVerificationFile: true
  path: test/EnumrateEuler.test.cpp
  requiredBy: []
  timestamp: '2020-12-04 17:58:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/EnumrateEuler.test.cpp
layout: document
redirect_from:
- /verify/test/EnumrateEuler.test.cpp
- /verify/test/EnumrateEuler.test.cpp.html
title: test/EnumrateEuler.test.cpp
---
