---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/Eratosthenes.cpp
    title: Math/Eratosthenes.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/Eratosthenes.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nvector<bool> Eratosthenes(int n) {\n\tvector<bool> p(n + 1, true);\n\
    \tp[0] = p[1] = false;\n\tfor (long long i = 2; i <= n; ++i)\n\t\tif (p[i])\n\t\
    \t\tfor (long long j = i * i; j <= n; j += i)\n\t\t\t\tp[j] = false;\n\treturn\
    \ p;\n}\n#line 4 \"Math/Primes.cpp\"\nusing namespace std;\n\nvector<int> Primes(int\
    \ n) {\n\tvector<int> res;\n\tauto p = Eratosthenes(n);\n\tfor (int i = 0; i <=\
    \ n; ++i)\n\t\tif (p[i]) res.push_back(i);\n\treturn res;\n}\n"
  code: "#pragma once\n#include \"./Eratosthenes.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nvector<int> Primes(int n) {\n\tvector<int> res;\n\tauto p = Eratosthenes(n);\n\
    \tfor (int i = 0; i <= n; ++i)\n\t\tif (p[i]) res.push_back(i);\n\treturn res;\n\
    }\n"
  dependsOn:
  - Math/Eratosthenes.cpp
  isVerificationFile: false
  path: Math/Primes.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Primes.cpp
layout: document
redirect_from:
- /library/Math/Primes.cpp
- /library/Math/Primes.cpp.html
title: Math/Primes.cpp
---
