---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LIS.test.cpp
    title: test/LIS.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DP/LIS.cpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <limits>\nusing namespace std;\n\ntemplate <class T> int LIS(const vector<T>&\
    \ a) {\n\tconstexpr T INF = numeric_limits<T>::max();\n\tint n = a.size();\n\t\
    vector<T> dp(n, INF);\n\tfor (auto num : a) {\n\t\t*lower_bound(dp.begin(), dp.end(),\
    \ num) = num;\n\t}\n\treturn lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n\
    }\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <limits>\n\
    using namespace std;\n\ntemplate <class T> int LIS(const vector<T>& a) {\n\tconstexpr\
    \ T INF = numeric_limits<T>::max();\n\tint n = a.size();\n\tvector<T> dp(n, INF);\n\
    \tfor (auto num : a) {\n\t\t*lower_bound(dp.begin(), dp.end(), num) = num;\n\t\
    }\n\treturn lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/LIS.cpp
  requiredBy: []
  timestamp: '2020-11-16 21:22:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LIS.test.cpp
documentation_of: DP/LIS.cpp
layout: document
redirect_from:
- /library/DP/LIS.cpp
- /library/DP/LIS.cpp.html
title: DP/LIS.cpp
---
