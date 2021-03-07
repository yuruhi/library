---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/Eratosthenes.cpp
    title: math/Eratosthenes.cpp
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
  bundledCode: "#line 2 \"math/Eratosthenes.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nvector<bool> Eratosthenes(size_t n) {\n\tvector<bool> result(n + 1,\
    \ true);\n\tresult[0] = result[1] = false;\n\tfor (size_t i = 2; i * i <= n; ++i)\
    \ {\n\t\tif (result[i]) {\n\t\t\tfor (size_t j = i * i; j <= n; j += i) result[j]\
    \ = false;\n\t\t}\n\t}\n\treturn result;\n}\n#line 4 \"math/EnumeratePrimes.cpp\"\
    \nusing namespace std;\n\nvector<int> EnumeratePrimes(int n) {\n\tvector<int>\
    \ result;\n\tauto p = Eratosthenes(n);\n\tfor (int i = 0; i <= n; ++i) {\n\t\t\
    if (p[i]) result.push_back(i);\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include \"./Eratosthenes.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nvector<int> EnumeratePrimes(int n) {\n\tvector<int> result;\n\tauto\
    \ p = Eratosthenes(n);\n\tfor (int i = 0; i <= n; ++i) {\n\t\tif (p[i]) result.push_back(i);\n\
    \t}\n\treturn result;\n}\n"
  dependsOn:
  - math/Eratosthenes.cpp
  isVerificationFile: false
  path: math/EnumeratePrimes.cpp
  requiredBy: []
  timestamp: '2021-03-07 15:45:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/EnumeratePrimes.test.cpp
documentation_of: math/EnumeratePrimes.cpp
layout: document
redirect_from:
- /library/math/EnumeratePrimes.cpp
- /library/math/EnumeratePrimes.cpp.html
title: math/EnumeratePrimes.cpp
---
