---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/EnumeratePrimes.cpp
    title: math/EnumeratePrimes.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/EnumeratePrimes.test.cpp
    title: test/EnumeratePrimes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Eratosthenes.test.cpp
    title: test/Eratosthenes.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/Eratosthenes.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nvector<bool> Eratosthenes(size_t n) {\n\tvector<bool> result(n + 1,\
    \ true);\n\tresult[0] = result[1] = false;\n\tfor (size_t i = 2; i * i <= n; ++i)\
    \ {\n\t\tif (result[i]) {\n\t\t\tfor (size_t j = i * i; j <= n; j += i) result[j]\
    \ = false;\n\t\t}\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\nvector<bool> Eratosthenes(size_t\
    \ n) {\n\tvector<bool> result(n + 1, true);\n\tresult[0] = result[1] = false;\n\
    \tfor (size_t i = 2; i * i <= n; ++i) {\n\t\tif (result[i]) {\n\t\t\tfor (size_t\
    \ j = i * i; j <= n; j += i) result[j] = false;\n\t\t}\n\t}\n\treturn result;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Eratosthenes.cpp
  requiredBy:
  - math/EnumeratePrimes.cpp
  timestamp: '2021-03-07 15:45:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Eratosthenes.test.cpp
  - test/EnumeratePrimes.test.cpp
documentation_of: math/Eratosthenes.cpp
layout: document
redirect_from:
- /library/math/Eratosthenes.cpp
- /library/math/Eratosthenes.cpp.html
title: math/Eratosthenes.cpp
---
