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
  bundledCode: "#line 2 \"math/Eratosthenes.cpp\"\n#include <vector>\n\nstd::vector<bool>\
    \ Eratosthenes(size_t n) {\n\tstd::vector<bool> result(n + 1, true);\n\tresult[0]\
    \ = result[1] = false;\n\tfor (size_t i = 2; i * i <= n; ++i) {\n\t\tif (result[i])\
    \ {\n\t\t\tfor (size_t j = i * i; j <= n; j += i) result[j] = false;\n\t\t}\n\t\
    }\n\treturn result;\n}\n#line 4 \"math/EnumeratePrimes.cpp\"\n\nstd::vector<int>\
    \ EnumeratePrimes(std::size_t n) {\n\tstd::vector<int> result;\n\tauto p = Eratosthenes(n);\n\
    \tfor (std::size_t i = 2; i <= n; ++i) {\n\t\tif (p[i]) result.push_back(i);\n\
    \t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include \"./Eratosthenes.cpp\"\n#include <vector>\n\nstd::vector<int>\
    \ EnumeratePrimes(std::size_t n) {\n\tstd::vector<int> result;\n\tauto p = Eratosthenes(n);\n\
    \tfor (std::size_t i = 2; i <= n; ++i) {\n\t\tif (p[i]) result.push_back(i);\n\
    \t}\n\treturn result;\n}\n"
  dependsOn:
  - math/Eratosthenes.cpp
  isVerificationFile: false
  path: math/EnumeratePrimes.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
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
