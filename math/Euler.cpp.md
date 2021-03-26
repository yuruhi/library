---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/PrimeFactor.cpp
    title: math/PrimeFactor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/EnumerateEuler.test.cpp
    title: test/EnumerateEuler.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Euler.test.cpp
    title: test/Euler.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    return result;\n}\n#line 4 \"math/Euler.cpp\"\n#include <numeric>\n\ntemplate\
    \ <class T> T Euler(T x) {\n\tT result = x;\n\tfor (auto [p, e] : PrimeFactor(x))\
    \ {\n\t\tresult = result / p * (p - 1);\n\t}\n\treturn result;\n}\n\nstd::vector<int>\
    \ EnumerateEuler(int x) {\n\tstd::vector<int> result(x + 1);\n\tstd::iota(result.begin(),\
    \ result.end(), 0);\n\tfor (int i = 2; i <= x; ++i) {\n\t\tif (result[i] == i)\
    \ {\n\t\t\tfor (int j = i; j <= x; j += i) {\n\t\t\t\tresult[j] = result[j] /\
    \ i * (i - 1);\n\t\t\t}\n\t\t}\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include \"./PrimeFactor.cpp\"\n#include <vector>\n#include\
    \ <numeric>\n\ntemplate <class T> T Euler(T x) {\n\tT result = x;\n\tfor (auto\
    \ [p, e] : PrimeFactor(x)) {\n\t\tresult = result / p * (p - 1);\n\t}\n\treturn\
    \ result;\n}\n\nstd::vector<int> EnumerateEuler(int x) {\n\tstd::vector<int> result(x\
    \ + 1);\n\tstd::iota(result.begin(), result.end(), 0);\n\tfor (int i = 2; i <=\
    \ x; ++i) {\n\t\tif (result[i] == i) {\n\t\t\tfor (int j = i; j <= x; j += i)\
    \ {\n\t\t\t\tresult[j] = result[j] / i * (i - 1);\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ result;\n}\n"
  dependsOn:
  - math/PrimeFactor.cpp
  isVerificationFile: false
  path: math/Euler.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Euler.test.cpp
  - test/EnumerateEuler.test.cpp
documentation_of: math/Euler.cpp
layout: document
redirect_from:
- /library/math/Euler.cpp
- /library/math/Euler.cpp.html
title: math/Euler.cpp
---