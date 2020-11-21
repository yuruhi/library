---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Knapsack.test.cpp
    title: test/Knapsack.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DP/Knapsack.cpp\"\n#include <vector>\n#include <algorithm>\n\
    using namespace std;\n\ntemplate <class T>\nvector<T> Knapsack(int n, T weight_limit,\
    \ const vector<T>& value, const vector<T>& weight) {\n\tvector<T> dp(weight_limit\
    \ + 1, 0);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = weight_limit; j\
    \ >= 0; --j) {\n\t\t\tif (j - weight[i] >= 0) dp[j] = max(dp[j], dp[j - weight[i]]\
    \ + value[i]);\n\t\t}\n\t}\n\treturn dp;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\
    \ntemplate <class T>\nvector<T> Knapsack(int n, T weight_limit, const vector<T>&\
    \ value, const vector<T>& weight) {\n\tvector<T> dp(weight_limit + 1, 0);\n\t\
    for (int i = 0; i < n; ++i) {\n\t\tfor (int j = weight_limit; j >= 0; --j) {\n\
    \t\t\tif (j - weight[i] >= 0) dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);\n\
    \t\t}\n\t}\n\treturn dp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/Knapsack.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Knapsack.test.cpp
documentation_of: DP/Knapsack.cpp
layout: document
redirect_from:
- /library/DP/Knapsack.cpp
- /library/DP/Knapsack.cpp.html
title: DP/Knapsack.cpp
---
