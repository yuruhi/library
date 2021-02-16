---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/Euler.cpp
    title: Math/Euler.cpp
  - icon: ':warning:'
    path: Math/Moebius.cpp
    title: Math/Moebius.cpp
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
  bundledCode: "#line 2 \"Math/PrimeFactor.cpp\"\n#include <map>\n#include <vector>\n\
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
  path: Math/PrimeFactor.cpp
  requiredBy:
  - Math/Euler.cpp
  - Math/Moebius.cpp
  timestamp: '2020-11-23 14:52:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/PrimeFactor.test.cpp
  - test/Euler.test.cpp
  - test/EnumerateEuler.test.cpp
documentation_of: Math/PrimeFactor.cpp
layout: document
redirect_from:
- /library/Math/PrimeFactor.cpp
- /library/Math/PrimeFactor.cpp.html
title: Math/PrimeFactor.cpp
---
