---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/LCS.cpp\"\n// description : \u6700\u9577\u5171\u901A\u90E8\
    \u5206\u5217\nint LCS(const string& s, const string& t) {\n\tint n = s.size(),\
    \ m = t.size();\n\tvector<vector<int>> dp(n + 1, vector<int>(m + 1));\n\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\tfor (int j = 0; j < m; ++j) {\n\t\t\tif (s[i] == t[j])\
    \ dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);\n\t\t\tdp[i + 1][j +\
    \ 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);\n\t\t\tdp[i + 1][j + 1] = max(dp[i\
    \ + 1][j + 1], dp[i][j + 1]);\n\t\t}\n\t}\n\treturn dp[n][m];\n}\n"
  code: "// description : \u6700\u9577\u5171\u901A\u90E8\u5206\u5217\nint LCS(const\
    \ string& s, const string& t) {\n\tint n = s.size(), m = t.size();\n\tvector<vector<int>>\
    \ dp(n + 1, vector<int>(m + 1));\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int\
    \ j = 0; j < m; ++j) {\n\t\t\tif (s[i] == t[j]) dp[i + 1][j + 1] = max(dp[i +\
    \ 1][j + 1], dp[i][j] + 1);\n\t\t\tdp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i\
    \ + 1][j]);\n\t\t\tdp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);\n\t\
    \t}\n\t}\n\treturn dp[n][m];\n}"
  dependsOn: []
  isVerificationFile: false
  path: DP/LCS.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/LCS.cpp
layout: document
redirect_from:
- /library/DP/LCS.cpp
- /library/DP/LCS.cpp.html
title: DP/LCS.cpp
---
