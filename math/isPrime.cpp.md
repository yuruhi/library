---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/isPrime.test.cpp
    title: test/isPrime.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/isPrime.cpp\"\n\ntemplate <class T> bool isPrime(T\
    \ n) {\n\tif (n == 2) return true;\n\tif (n < 2 || n % 2 == 0) return false;\n\
    \tfor (T i = 3; i * i <= n; i += 2) {\n\t\tif (n % i == 0) return false;\n\t}\n\
    \treturn true;\n}\n"
  code: "#pragma once\n\ntemplate <class T> bool isPrime(T n) {\n\tif (n == 2) return\
    \ true;\n\tif (n < 2 || n % 2 == 0) return false;\n\tfor (T i = 3; i * i <= n;\
    \ i += 2) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/isPrime.cpp
  requiredBy: []
  timestamp: '2021-03-07 15:45:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/isPrime.test.cpp
documentation_of: math/isPrime.cpp
layout: document
redirect_from:
- /library/math/isPrime.cpp
- /library/math/isPrime.cpp.html
title: math/isPrime.cpp
---
