---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Mex.cpp\"\n\ntemplate <class T> int mex(const T&\
    \ a) {\n\tint x = 0;\n\tfor (int i : a) {\n\t\tif (x < i) break;\n\t\tif (i ==\
    \ x) x++;\n\t}\n\treturn x;\n}\n"
  code: "#pragma once\n\ntemplate <class T> int mex(const T& a) {\n\tint x = 0;\n\t\
    for (int i : a) {\n\t\tif (x < i) break;\n\t\tif (i == x) x++;\n\t}\n\treturn\
    \ x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Mex.cpp
  requiredBy: []
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Mex.cpp
layout: document
redirect_from:
- /library/Utility/Mex.cpp
- /library/Utility/Mex.cpp.html
title: Utility/Mex.cpp
---
