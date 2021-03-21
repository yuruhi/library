---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Levenshtein.test.cpp
    title: test/Levenshtein.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DP/Levenshtein.cpp\"\n#include <vector>\n#include <string>\n\
    #include <algorithm>\n\nint Levenshtein(const std::string& s, const std::string&\
    \ t) {\n\tint S = s.size(), T = t.size();\n\tstd::vector dp(S + 1, std::vector<int>(T\
    \ + 1));\n\tfor (int i = 0; i <= S; i++) dp[i][0] = i;\n\tfor (int i = 0; i <=\
    \ T; i++) dp[0][i] = i;\n\tfor (int i = 1; i <= S; i++)\n\t\tfor (int j = 1; j\
    \ <= T; j++)\n\t\t\tdp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1,\n\
    \t\t\t                dp[i - 1][j - 1] + (s[i - 1] != t[j - 1])});\n\treturn dp[S][T];\n\
    }\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <algorithm>\n\
    \nint Levenshtein(const std::string& s, const std::string& t) {\n\tint S = s.size(),\
    \ T = t.size();\n\tstd::vector dp(S + 1, std::vector<int>(T + 1));\n\tfor (int\
    \ i = 0; i <= S; i++) dp[i][0] = i;\n\tfor (int i = 0; i <= T; i++) dp[0][i] =\
    \ i;\n\tfor (int i = 1; i <= S; i++)\n\t\tfor (int j = 1; j <= T; j++)\n\t\t\t\
    dp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1,\n\t\t\t             \
    \   dp[i - 1][j - 1] + (s[i - 1] != t[j - 1])});\n\treturn dp[S][T];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/Levenshtein.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Levenshtein.test.cpp
documentation_of: DP/Levenshtein.cpp
layout: document
redirect_from:
- /library/DP/Levenshtein.cpp
- /library/DP/Levenshtein.cpp.html
title: DP/Levenshtein.cpp
---
