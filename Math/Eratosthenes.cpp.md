---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/EnumeratePrimes.cpp
    title: Math/EnumeratePrimes.cpp
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
  bundledCode: "#line 2 \"Math/Eratosthenes.cpp\"\n#include <vector>\nusing namespace\
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
  path: Math/Eratosthenes.cpp
  requiredBy:
  - Math/EnumeratePrimes.cpp
  timestamp: '2020-11-23 16:14:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Eratosthenes.test.cpp
  - test/EnumeratePrimes.test.cpp
documentation_of: Math/Eratosthenes.cpp
layout: document
redirect_from:
- /library/Math/Eratosthenes.cpp
- /library/Math/Eratosthenes.cpp.html
title: Math/Eratosthenes.cpp
---
