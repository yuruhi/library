---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/EnumrateCombination.cpp\"\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate <class T> vector<vector<T>> EnumrateCombination(size_t\
    \ n) {\n\tvector<vector<T>> result(n + 1, vector<T>(n + 1));\n\tfor (size_t i\
    \ = 0; i <= n; ++i) result[i][0] = result[i][i] = 1;\n\tfor (size_t i = 1; i <=\
    \ n; ++i) {\n\t\tfor (size_t j = 1; j < i; ++j) {\n\t\t\tresult[i][j] = result[i\
    \ - 1][j - 1] + result[i - 1][j];\n\t\t}\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate <class\
    \ T> vector<vector<T>> EnumrateCombination(size_t n) {\n\tvector<vector<T>> result(n\
    \ + 1, vector<T>(n + 1));\n\tfor (size_t i = 0; i <= n; ++i) result[i][0] = result[i][i]\
    \ = 1;\n\tfor (size_t i = 1; i <= n; ++i) {\n\t\tfor (size_t j = 1; j < i; ++j)\
    \ {\n\t\t\tresult[i][j] = result[i - 1][j - 1] + result[i - 1][j];\n\t\t}\n\t\
    }\n\treturn result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/EnumrateCombination.cpp
  requiredBy: []
  timestamp: '2020-11-23 16:13:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/EnumrateCombination.cpp
layout: document
redirect_from:
- /library/Math/EnumrateCombination.cpp
- /library/Math/EnumrateCombination.cpp.html
title: Math/EnumrateCombination.cpp
---
