---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/Knapsack.test.cpp
    title: test/Knapsack.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DP/Knapsack.cpp\"\n#include <vector>\n#include <algorithm>\n\
    using namespace std;\n\ntemplate <class T>\nvector<T> Knapsack(int n, int wight_limit,\
    \ const vector<T>& value,\n                   const vector<int>& weight) {\n\t\
    assert(n == static_cast<int>(value.size()));\n\tassert(n == static_cast<int>(weight.size()));\n\
    \tvector<T> dp(wight_limit + 1, 0);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor\
    \ (int j = 0; j <= wight_limit - weight[i]; ++j) {\n\t\t\tdp[j + weight[i]] =\
    \ max(dp[j + weight[i]], dp[j] + value[i]);\n\t\t}\n\t}\n\treturn dp;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\
    \ntemplate <class T>\nvector<T> Knapsack(int n, int wight_limit, const vector<T>&\
    \ value,\n                   const vector<int>& weight) {\n\tassert(n == static_cast<int>(value.size()));\n\
    \tassert(n == static_cast<int>(weight.size()));\n\tvector<T> dp(wight_limit +\
    \ 1, 0);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = 0; j <= wight_limit\
    \ - weight[i]; ++j) {\n\t\t\tdp[j + weight[i]] = max(dp[j + weight[i]], dp[j]\
    \ + value[i]);\n\t\t}\n\t}\n\treturn dp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: DP/Knapsack.cpp
  requiredBy: []
  timestamp: '2020-12-20 17:36:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/Knapsack.test.cpp
documentation_of: DP/Knapsack.cpp
layout: document
redirect_from:
- /library/DP/Knapsack.cpp
- /library/DP/Knapsack.cpp.html
title: DP/Knapsack.cpp
---
