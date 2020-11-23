---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Eratosthenes.cpp
    title: Math/Eratosthenes.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/EnumratePrimes.test.cpp
    title: test/EnumratePrimes.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/Eratosthenes.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nvector<bool> Eratosthenes(size_t n) {\n\tvector<bool> result(n + 1,\
    \ true);\n\tresult[0] = result[1] = false;\n\tfor (size_t i = 2; i * i <= n; ++i)\
    \ {\n\t\tif (result[i]) {\n\t\t\tfor (size_t j = i * i; j <= n; j += i) result[j]\
    \ = false;\n\t\t}\n\t}\n\treturn result;\n}\n#line 4 \"Math/EnumratePrimes.cpp\"\
    \nusing namespace std;\n\nvector<int> EnumratePrimes(int n) {\n\tvector<int> result;\n\
    \tauto p = Eratosthenes(n);\n\tfor (int i = 0; i <= n; ++i) {\n\t\tif (p[i]) result.push_back(i);\n\
    \t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include \"./Eratosthenes.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nvector<int> EnumratePrimes(int n) {\n\tvector<int> result;\n\tauto p\
    \ = Eratosthenes(n);\n\tfor (int i = 0; i <= n; ++i) {\n\t\tif (p[i]) result.push_back(i);\n\
    \t}\n\treturn result;\n}\n"
  dependsOn:
  - Math/Eratosthenes.cpp
  isVerificationFile: false
  path: Math/EnumratePrimes.cpp
  requiredBy: []
  timestamp: '2020-11-23 16:14:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/EnumratePrimes.test.cpp
documentation_of: Math/EnumratePrimes.cpp
layout: document
redirect_from:
- /library/Math/EnumratePrimes.cpp
- /library/Math/EnumratePrimes.cpp.html
title: Math/EnumratePrimes.cpp
---
