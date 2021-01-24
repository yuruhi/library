---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Eratosthenes.cpp
    title: Math/Eratosthenes.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/EnumeratePrimes.test.cpp
    title: test/EnumeratePrimes.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/Eratosthenes.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nvector<bool> Eratosthenes(size_t n) {\n\tvector<bool> result(n + 1,\
    \ true);\n\tresult[0] = result[1] = false;\n\tfor (size_t i = 2; i * i <= n; ++i)\
    \ {\n\t\tif (result[i]) {\n\t\t\tfor (size_t j = i * i; j <= n; j += i) result[j]\
    \ = false;\n\t\t}\n\t}\n\treturn result;\n}\n#line 4 \"Math/EnumeratePrimes.cpp\"\
    \nusing namespace std;\n\nvector<int> EnumeratePrimes(int n) {\n\tvector<int>\
    \ result;\n\tauto p = Eratosthenes(n);\n\tfor (int i = 0; i <= n; ++i) {\n\t\t\
    if (p[i]) result.push_back(i);\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include \"./Eratosthenes.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nvector<int> EnumeratePrimes(int n) {\n\tvector<int> result;\n\tauto\
    \ p = Eratosthenes(n);\n\tfor (int i = 0; i <= n; ++i) {\n\t\tif (p[i]) result.push_back(i);\n\
    \t}\n\treturn result;\n}\n"
  dependsOn:
  - Math/Eratosthenes.cpp
  isVerificationFile: false
  path: Math/EnumeratePrimes.cpp
  requiredBy: []
  timestamp: '2020-12-13 11:47:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/EnumeratePrimes.test.cpp
documentation_of: Math/EnumeratePrimes.cpp
layout: document
redirect_from:
- /library/Math/EnumeratePrimes.cpp
- /library/Math/EnumeratePrimes.cpp.html
title: Math/EnumeratePrimes.cpp
---
