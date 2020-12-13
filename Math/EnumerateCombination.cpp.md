---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/EnumerateCombination.cpp\"\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate <class T> vector<vector<T>> EnumerateCombination(size_t\
    \ n) {\n\tvector<vector<T>> result(n + 1, vector<T>(n + 1));\n\tfor (size_t i\
    \ = 0; i <= n; ++i) result[i][0] = result[i][i] = 1;\n\tfor (size_t i = 1; i <=\
    \ n; ++i) {\n\t\tfor (size_t j = 1; j < i; ++j) {\n\t\t\tresult[i][j] = result[i\
    \ - 1][j - 1] + result[i - 1][j];\n\t\t}\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate <class\
    \ T> vector<vector<T>> EnumerateCombination(size_t n) {\n\tvector<vector<T>> result(n\
    \ + 1, vector<T>(n + 1));\n\tfor (size_t i = 0; i <= n; ++i) result[i][0] = result[i][i]\
    \ = 1;\n\tfor (size_t i = 1; i <= n; ++i) {\n\t\tfor (size_t j = 1; j < i; ++j)\
    \ {\n\t\t\tresult[i][j] = result[i - 1][j - 1] + result[i - 1][j];\n\t\t}\n\t\
    }\n\treturn result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/EnumerateCombination.cpp
  requiredBy: []
  timestamp: '2020-12-13 11:47:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/EnumerateCombination.cpp
layout: document
redirect_from:
- /library/Math/EnumerateCombination.cpp
- /library/Math/EnumerateCombination.cpp.html
title: Math/EnumerateCombination.cpp
---
