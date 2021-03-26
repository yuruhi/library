---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/extGcd.test.cpp
    title: test/extGcd.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/extGcd.cpp\"\n#include <tuple>\n\ntemplate <class T>\
    \ T extGcd(T a, T b, T& x, T& y) {\n\tT d = a;\n\tif (b != 0) {\n\t\td = extGcd(b,\
    \ a % b, y, x);\n\t\ty -= (a / b) * x;\n\t} else {\n\t\tx = 1;\n\t\ty = 0;\n\t\
    }\n\treturn d;\n}\n\ntemplate <class T> std::tuple<T, T, T> extGcd(T a, T b) {\n\
    \tT x, y;\n\tT gcd = extGcd(a, b, x, y);\n\treturn {gcd, x, y};\n}\n"
  code: "#pragma once\n#include <tuple>\n\ntemplate <class T> T extGcd(T a, T b, T&\
    \ x, T& y) {\n\tT d = a;\n\tif (b != 0) {\n\t\td = extGcd(b, a % b, y, x);\n\t\
    \ty -= (a / b) * x;\n\t} else {\n\t\tx = 1;\n\t\ty = 0;\n\t}\n\treturn d;\n}\n\
    \ntemplate <class T> std::tuple<T, T, T> extGcd(T a, T b) {\n\tT x, y;\n\tT gcd\
    \ = extGcd(a, b, x, y);\n\treturn {gcd, x, y};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/extGcd.cpp
  requiredBy: []
  timestamp: '2021-03-07 15:45:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/extGcd.test.cpp
documentation_of: math/extGcd.cpp
layout: document
redirect_from:
- /library/math/extGcd.cpp
- /library/math/extGcd.cpp.html
title: math/extGcd.cpp
---