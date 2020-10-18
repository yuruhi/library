---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/PrimeFactor.cpp
    title: Math/PrimeFactor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A
  bundledCode: "#line 1 \"test/PrimeFactor.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A\"\
    \n#line 2 \"Math/PrimeFactor.cpp\"\n#include <map>\n#include <vector>\n#include\
    \ <utility>\n#include <cassert>\nusing namespace std;\n\ntemplate <class T> vector<pair<T,\
    \ int>> PrimeFactor(T n) {\n\tassert(2 <= n);\n\tvector<pair<T, int>> res;\n\t\
    for (T i = 2; i * i <= n; ++i) {\n\t\tif (n % i == 0) {\n\t\t\tres.emplace_back(i,\
    \ 0);\n\t\t\twhile (n % i == 0) {\n\t\t\t\tres.back().second++;\n\t\t\t\tn /=\
    \ i;\n\t\t\t}\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tres.emplace_back(n, 1);\n\t}\n\
    \treturn res;\n}\ntemplate <class T> map<T, int> PrimeFactor_map(T n) {\n\tassert(2\
    \ <= n);\n\tmap<T, int> res;\n\tfor (T i = 2; i * i <= n; ++i) {\n\t\twhile (n\
    \ % i == 0) {\n\t\t\tres[i]++;\n\t\t\tn /= i;\n\t\t}\n\t}\n\tif (n != 1) {\n\t\
    \tres[n] = 1;\n\t}\n\treturn res;\n}\ntemplate <class T> vector<T> PrimeFactor_vector(T\
    \ n) {\n\tassert(2 <= n);\n\tvector<T> res;\n\tfor (T i = 2; i * i <= n; ++i)\
    \ {\n\t\twhile (n % i == 0) {\n\t\t\tres.push_back(i);\n\t\t\tn /= i;\n\t\t}\n\
    \t}\n\tif (n != 1) {\n\t\tres.push_back(n);\n\t}\n\treturn res;\n}\n#line 3 \"\
    test/PrimeFactor.test.cpp\"\n#include <iostream>\nusing namespace std;\n\nint\
    \ main() {\n\tint n;\n\tcin >> n;\n\tcout << n << ':';\n\tfor (auto [p, e] : PrimeFactor(n))\
    \ {\n\t\twhile (e--) {\n\t\t\tcout << ' ' << p;\n\t\t}\n\t}\n\tcout << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A\"\
    \n#include \"./../Math/PrimeFactor.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tint n;\n\tcin >> n;\n\tcout << n << ':';\n\tfor (auto\
    \ [p, e] : PrimeFactor(n)) {\n\t\twhile (e--) {\n\t\t\tcout << ' ' << p;\n\t\t\
    }\n\t}\n\tcout << '\\n';\n}"
  dependsOn:
  - Math/PrimeFactor.cpp
  isVerificationFile: true
  path: test/PrimeFactor.test.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/PrimeFactor.test.cpp
layout: document
redirect_from:
- /verify/test/PrimeFactor.test.cpp
- /verify/test/PrimeFactor.test.cpp.html
title: test/PrimeFactor.test.cpp
---
