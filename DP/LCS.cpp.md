---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LCS.test.cpp
    title: test/LCS.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DP/LCS.cpp\"\n#include <vector>\n#include <string>\n#include\
    \ <algorithm>\n\nint LCS(const std::string& s, const std::string& t) {\n\tint\
    \ n = s.size(), m = t.size();\n\tstd::vector<std::vector<int>> dp(n + 1, std::vector<int>(m\
    \ + 1));\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = 0; j < m; ++j) {\n\
    \t\t\tif (s[i] == t[j]) dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j]\
    \ + 1);\n\t\t\tdp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i + 1][j]);\n\t\
    \t\tdp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j + 1]);\n\t\t}\n\t}\n\
    \treturn dp[n][m];\n}\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <algorithm>\n\
    \nint LCS(const std::string& s, const std::string& t) {\n\tint n = s.size(), m\
    \ = t.size();\n\tstd::vector<std::vector<int>> dp(n + 1, std::vector<int>(m +\
    \ 1));\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = 0; j < m; ++j) {\n\t\
    \t\tif (s[i] == t[j]) dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] +\
    \ 1);\n\t\t\tdp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i + 1][j]);\n\t\t\
    \tdp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j + 1]);\n\t\t}\n\t}\n\t\
    return dp[n][m];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/LCS.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
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
