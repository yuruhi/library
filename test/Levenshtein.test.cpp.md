---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/Levenshtein.cpp
    title: DP/Levenshtein.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/225
    links:
    - https://yukicoder.me/problems/no/225
  bundledCode: "#line 1 \"test/Levenshtein.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/225\"\
    \n#line 2 \"DP/Levenshtein.cpp\"\n#include <vector>\n#include <string>\n#include\
    \ <algorithm>\nusing namespace std;\n\nint Levenshtein(const string& s, const\
    \ string& t) {\n\tint S = s.size(), T = t.size();\n\tvector<vector<int>> dp(S\
    \ + 1, vector<int>(T + 1));\n\tfor (int i = 0; i <= S; i++)\n\t\tdp[i][0] = i;\n\
    \tfor (int i = 0; i <= T; i++)\n\t\tdp[0][i] = i;\n\tfor (int i = 1; i <= S; i++)\n\
    \t\tfor (int j = 1; j <= T; j++)\n\t\t\tdp[i][j] = min({dp[i - 1][j] + 1, dp[i][j\
    \ - 1] + 1, dp[i - 1][j - 1] + (s[i - 1] != t[j - 1])});\n\treturn dp[S][T];\n\
    }\n#line 3 \"test/Levenshtein.test.cpp\"\n#include <iostream>\n#line 5 \"test/Levenshtein.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, m;\n\tstring s, t;\n\tcin >> n >> m >> s >> t;\n\tcout << Levenshtein(s,\
    \ t) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/225\"\n#include \"./../DP/Levenshtein.cpp\"\
    \n#include <iostream>\n#include <string>\nusing namespace std;\n\nint main() {\n\
    \tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tint n, m;\n\tstring\
    \ s, t;\n\tcin >> n >> m >> s >> t;\n\tcout << Levenshtein(s, t) << '\\n';\n}"
  dependsOn:
  - DP/Levenshtein.cpp
  isVerificationFile: true
  path: test/Levenshtein.test.cpp
  requiredBy: []
  timestamp: '2020-11-16 20:30:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Levenshtein.test.cpp
layout: document
redirect_from:
- /verify/test/Levenshtein.test.cpp
- /verify/test/Levenshtein.test.cpp.html
title: test/Levenshtein.test.cpp
---
