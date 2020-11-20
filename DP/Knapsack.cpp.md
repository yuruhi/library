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
    using namespace std;\n\ntemplate <class T>\nvector<T> Knapsack(int N, T W, const\
    \ vector<T>& v, const vector<T>& w) {\n\tvector<T> dp(W + 1, 0);\n\tfor (int i\
    \ = 0; i < N; ++i) {\n\t\tfor (int j = W; j >= 0; --j) {\n\t\t\tif (j - w[i] >=\
    \ 0) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);\n\t\t}\n\t}\n\treturn dp;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\
    \ntemplate <class T>\nvector<T> Knapsack(int N, T W, const vector<T>& v, const\
    \ vector<T>& w) {\n\tvector<T> dp(W + 1, 0);\n\tfor (int i = 0; i < N; ++i) {\n\
    \t\tfor (int j = W; j >= 0; --j) {\n\t\t\tif (j - w[i] >= 0) dp[j] = max(dp[j],\
    \ dp[j - w[i]] + v[i]);\n\t\t}\n\t}\n\treturn dp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/Knapsack.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
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
