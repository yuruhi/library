---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/isPrime.test.cpp
    title: test/isPrime.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/isPrime.cpp\"\n\ntemplate <class T> bool isPrime(T\
    \ n) {\n\tif (n == 2) return true;\n\tif (n < 2 || n % 2 == 0) return false;\n\
    \tfor (T i = 3; i * i <= n; i += 2) {\n\t\tif (n % i == 0) return false;\n\t}\n\
    \treturn true;\n}\n"
  code: "#pragma once\n\ntemplate <class T> bool isPrime(T n) {\n\tif (n == 2) return\
    \ true;\n\tif (n < 2 || n % 2 == 0) return false;\n\tfor (T i = 3; i * i <= n;\
    \ i += 2) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/isPrime.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/isPrime.test.cpp
documentation_of: Math/isPrime.cpp
layout: document
redirect_from:
- /library/Math/isPrime.cpp
- /library/Math/isPrime.cpp.html
title: Math/isPrime.cpp
---
