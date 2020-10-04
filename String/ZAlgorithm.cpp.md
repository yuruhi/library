---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ZAlgotihm.test.cpp
    title: test/ZAlgotihm.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/ZAlgorithm.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate <class T> vector<int> ZAlgorithm(const T& s) {\n\tif (s.size()\
    \ == 0) {\n\t\treturn {};\n\t}\n\tint n = s.size(), i = 1, j = 0;\n\tvector<int>\
    \ res(n);\n\tres[0] = n;\n\twhile (i < n) {\n\t\twhile (i + j < n && s[j] == s[i\
    \ + j])\n\t\t\tj++;\n\t\tres[i] = j;\n\t\tif (j == 0) {\n\t\t\ti++;\n\t\t\tcontinue;\n\
    \t\t}\n\t\tint k = 1;\n\t\twhile (i + k < n && k + res[k] < j) {\n\t\t\tres[i\
    \ + k] = res[k];\n\t\t\tk++;\n\t\t}\n\t\ti += k;\n\t\tj -= k;\n\t}\n\treturn res;\n\
    }\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate <class\
    \ T> vector<int> ZAlgorithm(const T& s) {\n\tif (s.size() == 0) {\n\t\treturn\
    \ {};\n\t}\n\tint n = s.size(), i = 1, j = 0;\n\tvector<int> res(n);\n\tres[0]\
    \ = n;\n\twhile (i < n) {\n\t\twhile (i + j < n && s[j] == s[i + j])\n\t\t\tj++;\n\
    \t\tres[i] = j;\n\t\tif (j == 0) {\n\t\t\ti++;\n\t\t\tcontinue;\n\t\t}\n\t\tint\
    \ k = 1;\n\t\twhile (i + k < n && k + res[k] < j) {\n\t\t\tres[i + k] = res[k];\n\
    \t\t\tk++;\n\t\t}\n\t\ti += k;\n\t\tj -= k;\n\t}\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/ZAlgorithm.cpp
  requiredBy: []
  timestamp: '2020-10-04 18:22:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ZAlgotihm.test.cpp
documentation_of: String/ZAlgorithm.cpp
layout: document
redirect_from:
- /library/String/ZAlgorithm.cpp
- /library/String/ZAlgorithm.cpp.html
title: String/ZAlgorithm.cpp
---
