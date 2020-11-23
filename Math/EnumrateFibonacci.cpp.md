---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/EnumrateFibonacci.test.cpp
    title: test/EnumrateFibonacci.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/EnumrateFibonacci.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate <class value_type = long long> vector<value_type> EnumrateFibonacci(int\
    \ n) {\n\tvector<value_type> result(n + 1);\n\tfor (int i = 0; i <= n; ++i) {\n\
    \t\tif (i < 2) {\n\t\t\tresult[i] = i;\n\t\t} else {\n\t\t\tresult[i] = result[i\
    \ - 1] + result[i - 2];\n\t\t}\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate <class\
    \ value_type = long long> vector<value_type> EnumrateFibonacci(int n) {\n\tvector<value_type>\
    \ result(n + 1);\n\tfor (int i = 0; i <= n; ++i) {\n\t\tif (i < 2) {\n\t\t\tresult[i]\
    \ = i;\n\t\t} else {\n\t\t\tresult[i] = result[i - 1] + result[i - 2];\n\t\t}\n\
    \t}\n\treturn result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/EnumrateFibonacci.cpp
  requiredBy: []
  timestamp: '2020-11-23 16:47:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/EnumrateFibonacci.test.cpp
documentation_of: Math/EnumrateFibonacci.cpp
layout: document
redirect_from:
- /library/Math/EnumrateFibonacci.cpp
- /library/Math/EnumrateFibonacci.cpp.html
title: Math/EnumrateFibonacci.cpp
---
