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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_D
  bundledCode: "#line 1 \"test/Euler.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_D\"\
    \n#line 2 \"Math/PrimeFactor.cpp\"\n#include <map>\n#include <vector>\n#include\
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
    \ 3 \"Math/Euler.cpp\"\n\ntemplate <class T> T Euler(T x) {\n\tT result = x;\n\
    \tfor (auto [p, e] : PrimeFactor(x)) {\n\t\tresult = result / p * (p - 1);\n\t\
    }\n\treturn result;\n}\n#line 3 \"test/Euler.test.cpp\"\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n\tlong long x;\n\tcin >> x;\n\tcout << Euler(x)\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_D\"\
    \n#include \"./../Math/Euler.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tlong long x;\n\tcin >> x;\n\tcout << Euler(x) << '\\n';\n}"
  dependsOn:
  - Math/Euler.cpp
  - Math/PrimeFactor.cpp
  isVerificationFile: true
  path: test/Euler.test.cpp
  requiredBy: []
  timestamp: '2020-11-23 14:52:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Euler.test.cpp
layout: document
redirect_from:
- /verify/test/Euler.test.cpp
- /verify/test/Euler.test.cpp.html
title: test/Euler.test.cpp
---