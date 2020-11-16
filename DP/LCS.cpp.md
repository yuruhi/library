---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LCS.test.cpp
    title: test/LCS.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DP/LCS.cpp\"\n#include <vector>\n#include <string>\n#include\
    \ <algorithm>\nusing namespace std;\n\nint LCS(const string& s, const string&\
    \ t) {\n\tint n = s.size(), m = t.size();\n\tvector<vector<int>> dp(n + 1, vector<int>(m\
    \ + 1));\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = 0; j < m; ++j) {\n\
    \t\t\tif (s[i] == t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);\n\
    \t\t\tdp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);\n\t\t\tdp[i + 1][j\
    \ + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);\n\t\t}\n\t}\n\treturn dp[n][m];\n\
    }\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <algorithm>\n\
    using namespace std;\n\nint LCS(const string& s, const string& t) {\n\tint n =\
    \ s.size(), m = t.size();\n\tvector<vector<int>> dp(n + 1, vector<int>(m + 1));\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = 0; j < m; ++j) {\n\t\t\tif (s[i]\
    \ == t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);\n\t\t\tdp[i\
    \ + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);\n\t\t\tdp[i + 1][j + 1] =\
    \ max(dp[i + 1][j + 1], dp[i][j + 1]);\n\t\t}\n\t}\n\treturn dp[n][m];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/LCS.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LCS.test.cpp
documentation_of: DP/LCS.cpp
layout: document
redirect_from:
- /library/DP/LCS.cpp
- /library/DP/LCS.cpp.html
title: DP/LCS.cpp
---
