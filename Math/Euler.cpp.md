---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/PrimeFactor.cpp
    title: Math/PrimeFactor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Euler.test.cpp
    title: test/Euler.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/PrimeFactor.cpp\"\n#include <map>\n#include <vector>\n\
    #include <utility>\n#include <cassert>\nusing namespace std;\n\ntemplate <class\
    \ T> vector<pair<T, int>> PrimeFactor(T n) {\n\tassert(2 <= n);\n\tvector<pair<T,\
    \ int>> res;\n\tfor (T i = 2; i * i <= n; ++i) {\n\t\tif (n % i == 0) {\n\t\t\t\
    res.emplace_back(i, 0);\n\t\t\twhile (n % i == 0) {\n\t\t\t\tres.back().second++;\n\
    \t\t\t\tn /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tres.emplace_back(n,\
    \ 1);\n\t}\n\treturn res;\n}\ntemplate <class T> map<T, int> PrimeFactor_map(T\
    \ n) {\n\tassert(2 <= n);\n\tmap<T, int> res;\n\tfor (T i = 2; i * i <= n; ++i)\
    \ {\n\t\twhile (n % i == 0) {\n\t\t\tres[i]++;\n\t\t\tn /= i;\n\t\t}\n\t}\n\t\
    if (n != 1) {\n\t\tres[n] = 1;\n\t}\n\treturn res;\n}\ntemplate <class T> vector<T>\
    \ PrimeFactor_vector(T n) {\n\tassert(2 <= n);\n\tvector<T> res;\n\tfor (T i =\
    \ 2; i * i <= n; ++i) {\n\t\twhile (n % i == 0) {\n\t\t\tres.push_back(i);\n\t\
    \t\tn /= i;\n\t\t}\n\t}\n\tif (n != 1) {\n\t\tres.push_back(n);\n\t}\n\treturn\
    \ res;\n}\n#line 2 \"Math/Euler.cpp\"\n\ntemplate <class T> T Euler(T x) {\n\t\
    T res = x;\n\tfor (auto [p, e] : PrimeFactor(x)) {\n\t\tres = res / p * (p - 1);\n\
    \t}\n\treturn res;\n}\n"
  code: "#include \"./PrimeFactor.cpp\"\n\ntemplate <class T> T Euler(T x) {\n\tT\
    \ res = x;\n\tfor (auto [p, e] : PrimeFactor(x)) {\n\t\tres = res / p * (p - 1);\n\
    \t}\n\treturn res;\n}"
  dependsOn:
  - Math/PrimeFactor.cpp
  isVerificationFile: false
  path: Math/Euler.cpp
  requiredBy: []
  timestamp: '2020-10-04 16:56:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Euler.test.cpp
documentation_of: Math/Euler.cpp
layout: document
redirect_from:
- /library/Math/Euler.cpp
- /library/Math/Euler.cpp.html
title: Math/Euler.cpp
---
