---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Fibonacci.test.cpp
    title: test/Fibonacci.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/Fibonacci.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nvector<long long> Fibonacci(int n) {\n\tvector<long long> res(n + 1);\n\
    \tfor (int i = 0; i <= n; ++i) {\n\t\tif (i < 2) {\n\t\t\tres[i] = i;\n\t\t} else\
    \ {\n\t\t\tres[i] = res[i - 1] + res[i - 2];\n\t\t}\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\nvector<long long>\
    \ Fibonacci(int n) {\n\tvector<long long> res(n + 1);\n\tfor (int i = 0; i <=\
    \ n; ++i) {\n\t\tif (i < 2) {\n\t\t\tres[i] = i;\n\t\t} else {\n\t\t\tres[i] =\
    \ res[i - 1] + res[i - 2];\n\t\t}\n\t}\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Fibonacci.cpp
  requiredBy: []
  timestamp: '2020-10-06 19:26:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Fibonacci.test.cpp
documentation_of: Math/Fibonacci.cpp
layout: document
redirect_from:
- /library/Math/Fibonacci.cpp
- /library/Math/Fibonacci.cpp.html
title: Math/Fibonacci.cpp
---
