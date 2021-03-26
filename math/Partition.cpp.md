---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Partition.test.cpp
    title: test/Partition.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/Partition.cpp\"\n#include <vector>\n\ntemplate <class\
    \ T> std::vector<std::vector<T>> Partition(int num, int sum) {\n\tstd::vector\
    \ dp(num + 1, std::vector<T>(sum + 1));\n\tdp[0][0] = 1;\n\tfor (int i = 1; i\
    \ <= num; ++i) {\n\t\tfor (int j = 0; j <= sum; ++j) {\n\t\t\tif (j - i >= 0)\
    \ {\n\t\t\t\tdp[i][j] = dp[i - 1][j] + dp[i][j - i];\n\t\t\t} else {\n\t\t\t\t\
    dp[i][j] = dp[i - 1][j];\n\t\t\t}\n\t\t}\n\t}\n\treturn dp;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <class T> std::vector<std::vector<T>>\
    \ Partition(int num, int sum) {\n\tstd::vector dp(num + 1, std::vector<T>(sum\
    \ + 1));\n\tdp[0][0] = 1;\n\tfor (int i = 1; i <= num; ++i) {\n\t\tfor (int j\
    \ = 0; j <= sum; ++j) {\n\t\t\tif (j - i >= 0) {\n\t\t\t\tdp[i][j] = dp[i - 1][j]\
    \ + dp[i][j - i];\n\t\t\t} else {\n\t\t\t\tdp[i][j] = dp[i - 1][j];\n\t\t\t}\n\
    \t\t}\n\t}\n\treturn dp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Partition.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Partition.test.cpp
documentation_of: math/Partition.cpp
layout: document
redirect_from:
- /library/math/Partition.cpp
- /library/math/Partition.cpp.html
title: math/Partition.cpp
---