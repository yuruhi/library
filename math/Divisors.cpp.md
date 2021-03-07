---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Divisors.test.cpp
    title: test/Divisors.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/Divisors.cpp\"\n#include <vector>\n#include <cmath>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> vector<T> Divisors(T\
    \ n) {\n\tassert(0 < n);\n\tvector<T> result;\n\tT i = 1;\n\tfor (; i * i < n;\
    \ ++i) {\n\t\tif (n % i == 0) result.push_back(i);\n\t}\n\tbool flag = i * i ==\
    \ n;\n\tif (flag) result.push_back(i);\n\tfor (i = (int)result.size() - 1 - flag;\
    \ i >= 0; --i) {\n\t\tresult.push_back(n / result[i]);\n\t}\n\treturn result;\n\
    }\ntemplate <class T> int DivisorsCount(T n) {\n\tassert(0 < n);\n\tint cnt =\
    \ 0;\n\tT sq = sqrt(n);\n\tfor (T i = 1; i <= sq; ++i) {\n\t\tcnt += n % i ==\
    \ 0;\n\t}\n\treturn cnt * 2 - (sq * sq == n);\n}\ntemplate <class T> T DivisorsSum(T\
    \ n) {\n\tassert(0 < n);\n\tT i = 1, result = 0;\n\tfor (; i * i < n; ++i) {\n\
    \t\tif (n % i == 0) result += i + n / i;\n\t}\n\treturn result + i * (i * i ==\
    \ n);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cmath>\n#include <cassert>\nusing\
    \ namespace std;\n\ntemplate <class T> vector<T> Divisors(T n) {\n\tassert(0 <\
    \ n);\n\tvector<T> result;\n\tT i = 1;\n\tfor (; i * i < n; ++i) {\n\t\tif (n\
    \ % i == 0) result.push_back(i);\n\t}\n\tbool flag = i * i == n;\n\tif (flag)\
    \ result.push_back(i);\n\tfor (i = (int)result.size() - 1 - flag; i >= 0; --i)\
    \ {\n\t\tresult.push_back(n / result[i]);\n\t}\n\treturn result;\n}\ntemplate\
    \ <class T> int DivisorsCount(T n) {\n\tassert(0 < n);\n\tint cnt = 0;\n\tT sq\
    \ = sqrt(n);\n\tfor (T i = 1; i <= sq; ++i) {\n\t\tcnt += n % i == 0;\n\t}\n\t\
    return cnt * 2 - (sq * sq == n);\n}\ntemplate <class T> T DivisorsSum(T n) {\n\
    \tassert(0 < n);\n\tT i = 1, result = 0;\n\tfor (; i * i < n; ++i) {\n\t\tif (n\
    \ % i == 0) result += i + n / i;\n\t}\n\treturn result + i * (i * i == n);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Divisors.cpp
  requiredBy: []
  timestamp: '2021-03-07 15:45:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Divisors.test.cpp
documentation_of: math/Divisors.cpp
layout: document
redirect_from:
- /library/math/Divisors.cpp
- /library/math/Divisors.cpp.html
title: math/Divisors.cpp
---
