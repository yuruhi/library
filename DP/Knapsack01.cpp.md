---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Knapsack01.test.cpp
    title: test/Knapsack01.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DP/Knapsack01.cpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <cassert>\n\ntemplate <class T>\nstd::vector<T> Knapsack01(int n, int\
    \ weight_limit, const std::vector<T>& value,\n                          const\
    \ std::vector<int>& weight) {\n\tassert(n == static_cast<int>(value.size()));\n\
    \tassert(n == static_cast<int>(weight.size()));\n\tstd::vector<T> dp(weight_limit\
    \ + 1, 0);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = weight_limit; j\
    \ >= 0; --j) {\n\t\t\tif (j - weight[i] >= 0) dp[j] = std::max(dp[j], dp[j - weight[i]]\
    \ + value[i]);\n\t\t}\n\t}\n\treturn dp;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    \ntemplate <class T>\nstd::vector<T> Knapsack01(int n, int weight_limit, const\
    \ std::vector<T>& value,\n                          const std::vector<int>& weight)\
    \ {\n\tassert(n == static_cast<int>(value.size()));\n\tassert(n == static_cast<int>(weight.size()));\n\
    \tstd::vector<T> dp(weight_limit + 1, 0);\n\tfor (int i = 0; i < n; ++i) {\n\t\
    \tfor (int j = weight_limit; j >= 0; --j) {\n\t\t\tif (j - weight[i] >= 0) dp[j]\
    \ = std::max(dp[j], dp[j - weight[i]] + value[i]);\n\t\t}\n\t}\n\treturn dp;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/Knapsack01.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
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
