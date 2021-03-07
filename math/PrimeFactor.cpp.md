---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/Euler.cpp
    title: math/Euler.cpp
  - icon: ':warning:'
    path: math/Moebius.cpp
    title: math/Moebius.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/EnumerateEuler.test.cpp
    title: test/EnumerateEuler.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Euler.test.cpp
    title: test/Euler.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/PrimeFactor.test.cpp
    title: test/PrimeFactor.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/PrimeFactor.cpp\"\n#include <map>\n#include <vector>\n\
    #include <utility>\n#include <cassert>\nusing namespace std;\n\ntemplate <class\
    \ T> vector<pair<T, int>> PrimeFactor(T n) {\n\tassert(1 <= n);\n\tif (n == 1)\
    \ {\n\t\treturn {};\n\t}\n\tvector<pair<T, int>> result;\n\tfor (T i = 2; i *\
    \ i <= n; ++i) {\n\t\tif (n % i == 0) {\n\t\t\tresult.emplace_back(i, 0);\n\t\t\
    \twhile (n % i == 0) {\n\t\t\t\tresult.back().second++;\n\t\t\t\tn /= i;\n\t\t\
    \t}\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tresult.emplace_back(n, 1);\n\t}\n\treturn\
    \ result;\n}\ntemplate <class T> map<T, int> PrimeFactor_map(T n) {\n\tassert(1\
    \ <= n);\n\tif (n == 1) {\n\t\treturn {};\n\t}\n\tmap<T, int> result;\n\tfor (T\
    \ i = 2; i * i <= n; ++i) {\n\t\twhile (n % i == 0) {\n\t\t\tresult[i]++;\n\t\t\
    \tn /= i;\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tresult[n] = 1;\n\t}\n\treturn result;\n\
    }\ntemplate <class T> vector<T> PrimeFactor_vector(T n) {\n\tassert(1 <= n);\n\
    \tif (n == 1) {\n\t\treturn {};\n\t}\n\tvector<T> result;\n\tfor (T i = 2; i *\
    \ i <= n; ++i) {\n\t\twhile (n % i == 0) {\n\t\t\tresult.push_back(i);\n\t\t\t\
    n /= i;\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tresult.push_back(n);\n\t}\n\treturn\
    \ result;\n}\n"
  code: "#pragma once\n#include <map>\n#include <vector>\n#include <utility>\n#include\
    \ <cassert>\nusing namespace std;\n\ntemplate <class T> vector<pair<T, int>> PrimeFactor(T\
    \ n) {\n\tassert(1 <= n);\n\tif (n == 1) {\n\t\treturn {};\n\t}\n\tvector<pair<T,\
    \ int>> result;\n\tfor (T i = 2; i * i <= n; ++i) {\n\t\tif (n % i == 0) {\n\t\
    \t\tresult.emplace_back(i, 0);\n\t\t\twhile (n % i == 0) {\n\t\t\t\tresult.back().second++;\n\
    \t\t\t\tn /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tresult.emplace_back(n,\
    \ 1);\n\t}\n\treturn result;\n}\ntemplate <class T> map<T, int> PrimeFactor_map(T\
    \ n) {\n\tassert(1 <= n);\n\tif (n == 1) {\n\t\treturn {};\n\t}\n\tmap<T, int>\
    \ result;\n\tfor (T i = 2; i * i <= n; ++i) {\n\t\twhile (n % i == 0) {\n\t\t\t\
    result[i]++;\n\t\t\tn /= i;\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tresult[n] = 1;\n\
    \t}\n\treturn result;\n}\ntemplate <class T> vector<T> PrimeFactor_vector(T n)\
    \ {\n\tassert(1 <= n);\n\tif (n == 1) {\n\t\treturn {};\n\t}\n\tvector<T> result;\n\
    \tfor (T i = 2; i * i <= n; ++i) {\n\t\twhile (n % i == 0) {\n\t\t\tresult.push_back(i);\n\
    \t\t\tn /= i;\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tresult.push_back(n);\n\t}\n\t\
    return result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/PrimeFactor.cpp
  requiredBy:
  - math/Euler.cpp
  - math/Moebius.cpp
  timestamp: '2021-03-07 15:45:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/PrimeFactor.test.cpp
  - test/Euler.test.cpp
  - test/EnumerateEuler.test.cpp
documentation_of: math/PrimeFactor.cpp
layout: document
redirect_from:
- /library/math/PrimeFactor.cpp
- /library/math/PrimeFactor.cpp.html
title: math/PrimeFactor.cpp
---
