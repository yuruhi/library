---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Partition.test.cpp
    title: test/Partition.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/Partition.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate <class T> vector<vector<T>> Partition(int num, int sum) {\n\
    \tvector<vector<T>> dp(num + 1, vector<T>(sum + 1));\n\tdp[0][0] = 1;\n\tfor (int\
    \ i = 1; i <= num; ++i) {\n\t\tfor (int j = 0; j <= sum; ++j) {\n\t\t\tif (j -\
    \ i >= 0) {\n\t\t\t\tdp[i][j] = dp[i - 1][j] + dp[i][j - i];\n\t\t\t} else {\n\
    \t\t\t\tdp[i][j] = dp[i - 1][j];\n\t\t\t}\n\t\t}\n\t}\n\treturn dp;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate <class\
    \ T> vector<vector<T>> Partition(int num, int sum) {\n\tvector<vector<T>> dp(num\
    \ + 1, vector<T>(sum + 1));\n\tdp[0][0] = 1;\n\tfor (int i = 1; i <= num; ++i)\
    \ {\n\t\tfor (int j = 0; j <= sum; ++j) {\n\t\t\tif (j - i >= 0) {\n\t\t\t\tdp[i][j]\
    \ = dp[i - 1][j] + dp[i][j - i];\n\t\t\t} else {\n\t\t\t\tdp[i][j] = dp[i - 1][j];\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn dp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Partition.cpp
  requiredBy: []
  timestamp: '2020-11-23 16:29:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Partition.test.cpp
documentation_of: Math/Partition.cpp
layout: document
redirect_from:
- /library/Math/Partition.cpp
- /library/Math/Partition.cpp.html
title: Math/Partition.cpp
---
