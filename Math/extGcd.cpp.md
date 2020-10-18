---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/extGcd.test.cpp
    title: test/extGcd.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/extGcd.cpp\"\n\ntemplate <class T> T extGcd(T a, T\
    \ b, T& x, T& y) {\n\tT d = a;\n\tif (b != 0) {\n\t\td = extGcd(b, a % b, y, x);\n\
    \t\ty -= (a / b) * x;\n\t} else {\n\t\tx = 1;\n\t\ty = 0;\n\t}\n\treturn d;\n\
    }\n"
  code: "#pragma once\n\ntemplate <class T> T extGcd(T a, T b, T& x, T& y) {\n\tT\
    \ d = a;\n\tif (b != 0) {\n\t\td = extGcd(b, a % b, y, x);\n\t\ty -= (a / b) *\
    \ x;\n\t} else {\n\t\tx = 1;\n\t\ty = 0;\n\t}\n\treturn d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/extGcd.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/extGcd.test.cpp
documentation_of: Math/extGcd.cpp
layout: document
redirect_from:
- /library/Math/extGcd.cpp
- /library/Math/extGcd.cpp.html
title: Math/extGcd.cpp
---
