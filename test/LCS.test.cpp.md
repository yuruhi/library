---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/LCS.cpp
    title: DP/LCS.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_C
  bundledCode: "#line 1 \"test/LCS.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_C\"\
    \n#line 2 \"DP/LCS.cpp\"\n#include <vector>\n#include <string>\n#include <algorithm>\n\
    using namespace std;\n\nint LCS(const string& s, const string& t) {\n\tint n =\
    \ s.size(), m = t.size();\n\tvector<vector<int>> dp(n + 1, vector<int>(m + 1));\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = 0; j < m; ++j) {\n\t\t\tif (s[i]\
    \ == t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);\n\t\t\tdp[i\
    \ + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);\n\t\t\tdp[i + 1][j + 1] =\
    \ max(dp[i + 1][j + 1], dp[i][j + 1]);\n\t\t}\n\t}\n\treturn dp[n][m];\n}\n#line\
    \ 3 \"test/LCS.test.cpp\"\n#include <iostream>\n#line 5 \"test/LCS.test.cpp\"\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tstring s, t;\n\t\tcin >> s >> t;\n\
    \t\tcout << LCS(s, t) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_C\"\n\
    #include \"./../DP/LCS.cpp\"\n#include <iostream>\n#include <string>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tstring s, t;\n\t\tcin >> s >> t;\n\
    \t\tcout << LCS(s, t) << '\\n';\n\t}\n}"
  dependsOn:
  - DP/LCS.cpp
  isVerificationFile: true
  path: test/LCS.test.cpp
  requiredBy: []
  timestamp: '2020-11-16 22:05:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LCS.test.cpp
layout: document
redirect_from:
- /verify/test/LCS.test.cpp
- /verify/test/LCS.test.cpp.html
title: test/LCS.test.cpp
---
