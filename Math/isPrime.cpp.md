---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/isPrime.cpp
layout: document
redirect_from:
- /library/Math/isPrime.cpp
- /library/Math/isPrime.cpp.html
title: Math/isPrime.cpp
---
