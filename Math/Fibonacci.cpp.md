---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Fibonacci.cpp\"\n// description : \u30D5\u30A3\u30DC\
    \u30CA\u30C3\u30C1\u6570\u5217\nvector<long long> getFib(int n) {\n\tvector<long\
    \ long> res(n + 1);\n\tfor (int i = 0; i <= n; ++i) {\n\t\tif (i < 2) {\n\t\t\t\
    res[i] = i;\n\t\t} else {\n\t\t\tres[i] = res[i - 1] + res[i - 2];\n\t\t}\n\t\
    }\n\treturn res;\n}\n"
  code: "// description : \u30D5\u30A3\u30DC\u30CA\u30C3\u30C1\u6570\u5217\nvector<long\
    \ long> getFib(int n) {\n\tvector<long long> res(n + 1);\n\tfor (int i = 0; i\
    \ <= n; ++i) {\n\t\tif (i < 2) {\n\t\t\tres[i] = i;\n\t\t} else {\n\t\t\tres[i]\
    \ = res[i - 1] + res[i - 2];\n\t\t}\n\t}\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Fibonacci.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Fibonacci.cpp
layout: document
redirect_from:
- /library/Math/Fibonacci.cpp
- /library/Math/Fibonacci.cpp.html
title: Math/Fibonacci.cpp
---
