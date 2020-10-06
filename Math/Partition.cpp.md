---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/Partition.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate <class T> vector<vector<T>> Partition(int n, int m) {\n\tvector<vector<T>>\
    \ dp(m + 1, vector<T>(n + 1));\n\tdp[0][0] = 1;\n\tfor (int i = 1; i <= m; ++i)\
    \ {\n\t\tfor (int j = 0; j <= n; ++j) {\n\t\t\tif (j - i >= 0) {\n\t\t\t\tdp[i][j]\
    \ = dp[i - 1][j] + dp[i][j - i];\n\t\t\t} else {\n\t\t\t\tdp[i][j] = dp[i - 1][j];\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn dp;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate <class\
    \ T> vector<vector<T>> Partition(int n, int m) {\n\tvector<vector<T>> dp(m + 1,\
    \ vector<T>(n + 1));\n\tdp[0][0] = 1;\n\tfor (int i = 1; i <= m; ++i) {\n\t\t\
    for (int j = 0; j <= n; ++j) {\n\t\t\tif (j - i >= 0) {\n\t\t\t\tdp[i][j] = dp[i\
    \ - 1][j] + dp[i][j - i];\n\t\t\t} else {\n\t\t\t\tdp[i][j] = dp[i - 1][j];\n\t\
    \t\t}\n\t\t}\n\t}\n\treturn dp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Partition.cpp
  requiredBy: []
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Partition.cpp
layout: document
redirect_from:
- /library/Math/Partition.cpp
- /library/Math/Partition.cpp.html
title: Math/Partition.cpp
---
