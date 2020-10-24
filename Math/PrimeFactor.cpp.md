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
    path: test/Euler.test.cpp
    title: test/Euler.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/PrimeFactor.test.cpp
    title: test/PrimeFactor.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/PrimeFactor.cpp\"\n#include <map>\n#include <vector>\n\
    #include <utility>\n#include <cassert>\nusing namespace std;\n\ntemplate <class\
    \ T> vector<pair<T, int>> PrimeFactor(T n) {\n\tassert(1 <= n);\n\tif (n == 1)\
    \ {\n\t\treturn {};\n\t}\n\tvector<pair<T, int>> res;\n\tfor (T i = 2; i * i <=\
    \ n; ++i) {\n\t\tif (n % i == 0) {\n\t\t\tres.emplace_back(i, 0);\n\t\t\twhile\
    \ (n % i == 0) {\n\t\t\t\tres.back().second++;\n\t\t\t\tn /= i;\n\t\t\t}\n\t\t\
    }\n\t}\n\tif (n != 1) {\n\t\tres.emplace_back(n, 1);\n\t}\n\treturn res;\n}\n\
    template <class T> map<T, int> PrimeFactor_map(T n) {\n\tassert(1 <= n);\n\tif\
    \ (n == 1) {\n\t\treturn {};\n\t}\n\tmap<T, int> res;\n\tfor (T i = 2; i * i <=\
    \ n; ++i) {\n\t\twhile (n % i == 0) {\n\t\t\tres[i]++;\n\t\t\tn /= i;\n\t\t}\n\
    \t}\n\tif (n != 1) {\n\t\tres[n] = 1;\n\t}\n\treturn res;\n}\ntemplate <class\
    \ T> vector<T> PrimeFactor_vector(T n) {\n\tassert(1 <= n);\n\tif (n == 1) {\n\
    \t\treturn {};\n\t}\n\tvector<T> res;\n\tfor (T i = 2; i * i <= n; ++i) {\n\t\t\
    while (n % i == 0) {\n\t\t\tres.push_back(i);\n\t\t\tn /= i;\n\t\t}\n\t}\n\tif\
    \ (n != 1) {\n\t\tres.push_back(n);\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n#include <map>\n#include <vector>\n#include <utility>\n#include\
    \ <cassert>\nusing namespace std;\n\ntemplate <class T> vector<pair<T, int>> PrimeFactor(T\
    \ n) {\n\tassert(1 <= n);\n\tif (n == 1) {\n\t\treturn {};\n\t}\n\tvector<pair<T,\
    \ int>> res;\n\tfor (T i = 2; i * i <= n; ++i) {\n\t\tif (n % i == 0) {\n\t\t\t\
    res.emplace_back(i, 0);\n\t\t\twhile (n % i == 0) {\n\t\t\t\tres.back().second++;\n\
    \t\t\t\tn /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tres.emplace_back(n,\
    \ 1);\n\t}\n\treturn res;\n}\ntemplate <class T> map<T, int> PrimeFactor_map(T\
    \ n) {\n\tassert(1 <= n);\n\tif (n == 1) {\n\t\treturn {};\n\t}\n\tmap<T, int>\
    \ res;\n\tfor (T i = 2; i * i <= n; ++i) {\n\t\twhile (n % i == 0) {\n\t\t\tres[i]++;\n\
    \t\t\tn /= i;\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tres[n] = 1;\n\t}\n\treturn res;\n\
    }\ntemplate <class T> vector<T> PrimeFactor_vector(T n) {\n\tassert(1 <= n);\n\
    \tif (n == 1) {\n\t\treturn {};\n\t}\n\tvector<T> res;\n\tfor (T i = 2; i * i\
    \ <= n; ++i) {\n\t\twhile (n % i == 0) {\n\t\t\tres.push_back(i);\n\t\t\tn /=\
    \ i;\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tres.push_back(n);\n\t}\n\treturn res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/PrimeFactor.cpp
  requiredBy:
  - Math/Moebius.cpp
  - Math/Euler.cpp
  timestamp: '2020-10-24 16:02:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/PrimeFactor.test.cpp
  - test/Euler.test.cpp
documentation_of: Math/PrimeFactor.cpp
layout: document
redirect_from:
- /library/Math/PrimeFactor.cpp
- /library/Math/PrimeFactor.cpp.html
title: Math/PrimeFactor.cpp
---
