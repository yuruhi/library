---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/PrimeFactor.cpp
    title: Math/PrimeFactor.cpp
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
    \ result;\n}\n#line 3 \"Math/Euler.cpp\"\n#include <numeric>\n\ntemplate <class\
    \ T> T Euler(T x) {\n\tT result = x;\n\tfor (auto [p, e] : PrimeFactor(x)) {\n\
    \t\tresult = result / p * (p - 1);\n\t}\n\treturn result;\n}\n\nvector<int> EnumerateEuler(int\
    \ x) {\n\tvector<int> result(x + 1);\n\tiota(result.begin(), result.end(), 0);\n\
    \tfor (int i = 2; i <= x; ++i) {\n\t\tif (result[i] == i) {\n\t\t\tfor (int j\
    \ = i; j <= x; j += i) {\n\t\t\t\tresult[j] = result[j] / i * (i - 1);\n\t\t\t\
    }\n\t\t}\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include \"./PrimeFactor.cpp\"\n#include <numeric>\n\ntemplate\
    \ <class T> T Euler(T x) {\n\tT result = x;\n\tfor (auto [p, e] : PrimeFactor(x))\
    \ {\n\t\tresult = result / p * (p - 1);\n\t}\n\treturn result;\n}\n\nvector<int>\
    \ EnumerateEuler(int x) {\n\tvector<int> result(x + 1);\n\tiota(result.begin(),\
    \ result.end(), 0);\n\tfor (int i = 2; i <= x; ++i) {\n\t\tif (result[i] == i)\
    \ {\n\t\t\tfor (int j = i; j <= x; j += i) {\n\t\t\t\tresult[j] = result[j] /\
    \ i * (i - 1);\n\t\t\t}\n\t\t}\n\t}\n\treturn result;\n}"
  dependsOn:
  - Math/PrimeFactor.cpp
  isVerificationFile: false
  path: Math/Euler.cpp
  requiredBy: []
  timestamp: '2020-12-13 11:47:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Euler.test.cpp
  - test/EnumerateEuler.test.cpp
documentation_of: Math/Euler.cpp
layout: document
redirect_from:
- /library/Math/Euler.cpp
- /library/Math/Euler.cpp.html
title: Math/Euler.cpp
---
