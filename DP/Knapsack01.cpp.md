---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Knapsack01.test.cpp
    title: test/Knapsack01.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DP/Knapsack01.cpp\"\n#include <vector>\n#include <algorithm>\n\
    using namespace std;\n\ntemplate <class T>\nvector<T> Knapsack01(int n, int wight_limit,\
    \ const vector<T>& value,\n                     const vector<int>& weight) {\n\
    \tvector<T> dp(wight_limit + 1, 0);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor\
    \ (int j = 0; j <= wight_limit - weight[i]; ++j) {\n\t\t\tdp[j + weight[i]] =\
    \ max(dp[j + weight[i]], dp[j] + value[i]);\n\t\t}\n\t}\n\treturn dp;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\
    \ntemplate <class T>\nvector<T> Knapsack01(int n, int wight_limit, const vector<T>&\
    \ value,\n                     const vector<int>& weight) {\n\tvector<T> dp(wight_limit\
    \ + 1, 0);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = 0; j <= wight_limit\
    \ - weight[i]; ++j) {\n\t\t\tdp[j + weight[i]] = max(dp[j + weight[i]], dp[j]\
    \ + value[i]);\n\t\t}\n\t}\n\treturn dp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: DP/Knapsack01.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Knapsack01.test.cpp
documentation_of: DP/Knapsack01.cpp
layout: document
redirect_from:
- /library/DP/Knapsack01.cpp
- /library/DP/Knapsack01.cpp.html
title: DP/Knapsack01.cpp
---