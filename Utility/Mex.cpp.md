---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Utility/Mex.cpp\"\n// description : a \u306B\u542B\u307E\
    \u308C\u306A\u3044\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570\ntemplate <class\
    \ T> int mex(const T& a) {\n\tint x = 0;\n\tfor (int i : a) {\n\t\tif (x < i)\
    \ break;\n\t\tif (i == x) x++;\n\t}\n\treturn x;\n}\n"
  code: "// description : a \u306B\u542B\u307E\u308C\u306A\u3044\u6700\u5C0F\u306E\
    \u975E\u8CA0\u6574\u6570\ntemplate <class T> int mex(const T& a) {\n\tint x =\
    \ 0;\n\tfor (int i : a) {\n\t\tif (x < i) break;\n\t\tif (i == x) x++;\n\t}\n\t\
    return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Mex.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Mex.cpp
layout: document
redirect_from:
- /library/Utility/Mex.cpp
- /library/Utility/Mex.cpp.html
title: Utility/Mex.cpp
---
