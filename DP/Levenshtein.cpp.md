---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/Levenshtein.cpp\"\n// description : \u7DE8\u96C6\u8DDD\
    \u96E2\nint Levenshtein(const string& s, const string& t) {\n\tint S = s.size(),\
    \ T = t.size();\n\tvector<vector<int>> dp(S + 1, vector<int>(T + 1));\n\tfor (int\
    \ i = 0; i <= S; i++)\n\t\tdp[i][0] = i;\n\tfor (int i = 0; i <= T; i++)\n\t\t\
    dp[0][i] = i;\n\tfor (int i = 1; i <= S; i++)\n\t\tfor (int j = 1; j <= T; j++)\n\
    \t\t\tdp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (s[i\
    \ - 1] != t[j - 1])});\n\treturn dp[S][T];\n}\n"
  code: "// description : \u7DE8\u96C6\u8DDD\u96E2\nint Levenshtein(const string&\
    \ s, const string& t) {\n\tint S = s.size(), T = t.size();\n\tvector<vector<int>>\
    \ dp(S + 1, vector<int>(T + 1));\n\tfor (int i = 0; i <= S; i++)\n\t\tdp[i][0]\
    \ = i;\n\tfor (int i = 0; i <= T; i++)\n\t\tdp[0][i] = i;\n\tfor (int i = 1; i\
    \ <= S; i++)\n\t\tfor (int j = 1; j <= T; j++)\n\t\t\tdp[i][j] = min({dp[i - 1][j]\
    \ + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (s[i - 1] != t[j - 1])});\n\treturn\
    \ dp[S][T];\n}"
  dependsOn: []
  isVerificationFile: false
  path: DP/Levenshtein.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/Levenshtein.cpp
layout: document
redirect_from:
- /library/DP/Levenshtein.cpp
- /library/DP/Levenshtein.cpp.html
title: DP/Levenshtein.cpp
---
