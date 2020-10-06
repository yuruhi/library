---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/Primes.cpp
    title: Math/Primes.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/Eratosthenes.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nvector<bool> Eratosthenes(int n) {\n\tvector<bool> p(n + 1, true);\n\
    \tp[0] = p[1] = false;\n\tfor (long long i = 2; i <= n; ++i)\n\t\tif (p[i])\n\t\
    \t\tfor (long long j = i * i; j <= n; j += i)\n\t\t\t\tp[j] = false;\n\treturn\
    \ p;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\nvector<bool> Eratosthenes(int\
    \ n) {\n\tvector<bool> p(n + 1, true);\n\tp[0] = p[1] = false;\n\tfor (long long\
    \ i = 2; i <= n; ++i)\n\t\tif (p[i])\n\t\t\tfor (long long j = i * i; j <= n;\
    \ j += i)\n\t\t\t\tp[j] = false;\n\treturn p;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Eratosthenes.cpp
  requiredBy:
  - Math/Primes.cpp
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Eratosthenes.cpp
layout: document
redirect_from:
- /library/Math/Eratosthenes.cpp
- /library/Math/Eratosthenes.cpp.html
title: Math/Eratosthenes.cpp
---
