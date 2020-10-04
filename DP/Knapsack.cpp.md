---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/Knapsack.cpp\"\n// description : 01\u30CA\u30C3\u30D7\
    \u30B6\u30C3\u30AF\u554F\u984C\ntemplate <class T> vector<T> Knapsack(int N, T\
    \ W, const vector<T>& v, const vector<T>& w) {\n\tvector<T> dp(W + 1, 0);\n\t\
    for (int i = 0; i < N; ++i) {\n\t\tfor (int j = W; j >= 0; --j) {\n\t\t\tif (j\
    \ - w[i] >= 0) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);\n\t\t}\n\t}\n\treturn\
    \ dp;\n}\n"
  code: "// description : 01\u30CA\u30C3\u30D7\u30B6\u30C3\u30AF\u554F\u984C\ntemplate\
    \ <class T> vector<T> Knapsack(int N, T W, const vector<T>& v, const vector<T>&\
    \ w) {\n\tvector<T> dp(W + 1, 0);\n\tfor (int i = 0; i < N; ++i) {\n\t\tfor (int\
    \ j = W; j >= 0; --j) {\n\t\t\tif (j - w[i] >= 0) dp[j] = max(dp[j], dp[j - w[i]]\
    \ + v[i]);\n\t\t}\n\t}\n\treturn dp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: DP/Knapsack.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/Knapsack.cpp
layout: document
redirect_from:
- /library/DP/Knapsack.cpp
- /library/DP/Knapsack.cpp.html
title: DP/Knapsack.cpp
---
