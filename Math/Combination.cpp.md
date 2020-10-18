---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/Combination.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate <class T> vector<vector<T>> Combi(int n, T _Mod = 1000000007)\
    \ {\n\tvector<vector<T>> v(n, vector<T>(n));\n\tfor (int i = 0; i < n; ++i)\n\t\
    \tv[i][0] = v[i][i] = 1;\n\tfor (int k = 1; k < n; ++k)\n\t\tfor (int j = 1; j\
    \ < k; ++j)\n\t\t\tv[k][j] = (v[k - 1][j - 1] + v[k - 1][j]) % _Mod;\n\treturn\
    \ v;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate <class\
    \ T> vector<vector<T>> Combi(int n, T _Mod = 1000000007) {\n\tvector<vector<T>>\
    \ v(n, vector<T>(n));\n\tfor (int i = 0; i < n; ++i)\n\t\tv[i][0] = v[i][i] =\
    \ 1;\n\tfor (int k = 1; k < n; ++k)\n\t\tfor (int j = 1; j < k; ++j)\n\t\t\tv[k][j]\
    \ = (v[k - 1][j - 1] + v[k - 1][j]) % _Mod;\n\treturn v;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combination.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Combination.cpp
layout: document
redirect_from:
- /library/Math/Combination.cpp
- /library/Math/Combination.cpp.html
title: Math/Combination.cpp
---
