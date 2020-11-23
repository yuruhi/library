---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/isLeap.test.cpp
    title: test/isLeap.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/isLeap.cpp\"\n\nbool isLeap(int y) {\n\treturn !(y\
    \ % 4) && (y % 100 || !(y % 400));\n}\n"
  code: "#pragma once\n\nbool isLeap(int y) {\n\treturn !(y % 4) && (y % 100 || !(y\
    \ % 400));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/isLeap.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/isLeap.test.cpp
documentation_of: Utility/isLeap.cpp
layout: document
redirect_from:
- /library/Utility/isLeap.cpp
- /library/Utility/isLeap.cpp.html
title: Utility/isLeap.cpp
---
