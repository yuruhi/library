---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DP/LIS.cpp\"\n#include <vector>\n#include <algorithm>\n\
    using namespace std;\n\ntemplate <class T> int LIS(const vector<T>& a, T INF_\
    \ = 1e9) {\n\tint n = a.size();\n\tvector<T> dp(n, INF_);\n\tfor (auto num : a)\
    \ {\n\t\t*lower_bound(dp.begin(), dp.end(), num) = num;\n\t}\n\treturn lower_bound(dp.begin(),\
    \ dp.end(), INF_) - dp.begin();\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\
    \ntemplate <class T> int LIS(const vector<T>& a, T INF_ = 1e9) {\n\tint n = a.size();\n\
    \tvector<T> dp(n, INF_);\n\tfor (auto num : a) {\n\t\t*lower_bound(dp.begin(),\
    \ dp.end(), num) = num;\n\t}\n\treturn lower_bound(dp.begin(), dp.end(), INF_)\
    \ - dp.begin();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/LIS.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/LIS.cpp
layout: document
redirect_from:
- /library/DP/LIS.cpp
- /library/DP/LIS.cpp.html
title: DP/LIS.cpp
---
