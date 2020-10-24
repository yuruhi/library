---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/PrimeFactor.cpp
    title: Math/PrimeFactor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ (n != 1) {\n\t\tres.push_back(n);\n\t}\n\treturn res;\n}\n#line 4 \"Math/Moebius.cpp\"\
    \nusing namespace std;\n\ntemplate <class T> map<T, int> Moebius(T n) {\n\tmap<T,\
    \ int> res;\n\tauto primes = PrimeFactor(n);\n\tint m = primes.size();\n\tfor\
    \ (int bit = 0; bit < (1 << m); ++bit) {\n\t\tint mul = 1, d = 1;\n\t\tfor (int\
    \ i = 0; i < m; ++i) {\n\t\t\tif (bit & (1 << i)) {\n\t\t\t\tmul *= -1;\n\t\t\t\
    \td *= primes[i].first;\n\t\t\t}\n\t\t}\n\t\tres[d] = mul;\n\t}\n\treturn res;\n\
    }\n"
  code: "#pragma once\n#include \"./PrimeFactor.cpp\"\n#include <map>\nusing namespace\
    \ std;\n\ntemplate <class T> map<T, int> Moebius(T n) {\n\tmap<T, int> res;\n\t\
    auto primes = PrimeFactor(n);\n\tint m = primes.size();\n\tfor (int bit = 0; bit\
    \ < (1 << m); ++bit) {\n\t\tint mul = 1, d = 1;\n\t\tfor (int i = 0; i < m; ++i)\
    \ {\n\t\t\tif (bit & (1 << i)) {\n\t\t\t\tmul *= -1;\n\t\t\t\td *= primes[i].first;\n\
    \t\t\t}\n\t\t}\n\t\tres[d] = mul;\n\t}\n\treturn res;\n}"
  dependsOn:
  - Math/PrimeFactor.cpp
  isVerificationFile: false
  path: Math/Moebius.cpp
  requiredBy: []
  timestamp: '2020-10-24 16:02:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Moebius.cpp
layout: document
redirect_from:
- /library/Math/Moebius.cpp
- /library/Math/Moebius.cpp.html
title: Math/Moebius.cpp
---
