---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/PrimeFactor.cpp
    title: math/PrimeFactor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/PrimeFactor.cpp\"\n#include <map>\n#include <vector>\n\
    #include <utility>\n#include <cassert>\n\ntemplate <class T> std::vector<std::pair<T,\
    \ int>> PrimeFactor(T n) {\n\tassert(1 <= n);\n\tif (n == 1) {\n\t\treturn {};\n\
    \t}\n\tstd::vector<std::pair<T, int>> result;\n\tfor (T i = 2; i * i <= n; ++i)\
    \ {\n\t\tif (n % i == 0) {\n\t\t\tresult.emplace_back(i, 0);\n\t\t\twhile (n %\
    \ i == 0) {\n\t\t\t\tresult.back().second++;\n\t\t\t\tn /= i;\n\t\t\t}\n\t\t}\n\
    \t}\n\tif (n != 1) {\n\t\tresult.emplace_back(n, 1);\n\t}\n\treturn result;\n\
    }\ntemplate <class T> std::map<T, int> PrimeFactor_map(T n) {\n\tassert(1 <= n);\n\
    \tif (n == 1) {\n\t\treturn {};\n\t}\n\tstd::map<T, int> result;\n\tfor (T i =\
    \ 2; i * i <= n; ++i) {\n\t\twhile (n % i == 0) {\n\t\t\tresult[i]++;\n\t\t\t\
    n /= i;\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tresult[n] = 1;\n\t}\n\treturn result;\n\
    }\ntemplate <class T> std::vector<T> PrimeFactor_vector(T n) {\n\tassert(1 <=\
    \ n);\n\tif (n == 1) {\n\t\treturn {};\n\t}\n\tstd::vector<T> result;\n\tfor (T\
    \ i = 2; i * i <= n; ++i) {\n\t\twhile (n % i == 0) {\n\t\t\tresult.push_back(i);\n\
    \t\t\tn /= i;\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tresult.push_back(n);\n\t}\n\t\
    return result;\n}\n#line 4 \"math/Moebius.cpp\"\n\ntemplate <class T> std::map<T,\
    \ int> Moebius(T n) {\n\tstd::map<T, int> result;\n\tauto primes = PrimeFactor(n);\n\
    \tint m = primes.size();\n\tfor (int bit = 0; bit < (1 << m); ++bit) {\n\t\tint\
    \ mul = 1, d = 1;\n\t\tfor (int i = 0; i < m; ++i) {\n\t\t\tif (bit & (1 << i))\
    \ {\n\t\t\t\tmul *= -1;\n\t\t\t\td *= primes[i].first;\n\t\t\t}\n\t\t}\n\t\tresult[d]\
    \ = mul;\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include \"./PrimeFactor.cpp\"\n#include <map>\n\ntemplate\
    \ <class T> std::map<T, int> Moebius(T n) {\n\tstd::map<T, int> result;\n\tauto\
    \ primes = PrimeFactor(n);\n\tint m = primes.size();\n\tfor (int bit = 0; bit\
    \ < (1 << m); ++bit) {\n\t\tint mul = 1, d = 1;\n\t\tfor (int i = 0; i < m; ++i)\
    \ {\n\t\t\tif (bit & (1 << i)) {\n\t\t\t\tmul *= -1;\n\t\t\t\td *= primes[i].first;\n\
    \t\t\t}\n\t\t}\n\t\tresult[d] = mul;\n\t}\n\treturn result;\n}"
  dependsOn:
  - math/PrimeFactor.cpp
  isVerificationFile: false
  path: math/Moebius.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Moebius.cpp
layout: document
redirect_from:
- /library/math/Moebius.cpp
- /library/math/Moebius.cpp.html
title: math/Moebius.cpp
---
