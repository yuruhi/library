---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Utility/splitRange.cpp\"\n// description : { 1,2,3,2,1,2,1\
    \ } -> { [0-2], [2-4], [4-5], [5-6] }\nvector<Range> split(const vector<int>&\
    \ v) {\n\tint n = v.size();\n\tvector<Range> res;\n\tif (n <= 1) {\n\t\tres.emplace_back(0,\
    \ n - 1);\n\t\treturn res;\n\t}\n\tint x = 0;\n\tbool flag = v[0] < v[1];\n\t\
    for (int i = 0; i < n; i++) {\n\t\tif (i == n - 1 || !((flag && v[i] < v[i + 1])\
    \ || (!flag && v[i] > v[i + 1]))) {\n\t\t\tflag = flag ? false : true;\n\t\t\t\
    res.emplace_back(x, i);\n\t\t\tx = i;\n\t\t}\n\t}\n\treturn res;\n}\n"
  code: "// description : { 1,2,3,2,1,2,1 } -> { [0-2], [2-4], [4-5], [5-6] }\nvector<Range>\
    \ split(const vector<int>& v) {\n\tint n = v.size();\n\tvector<Range> res;\n\t\
    if (n <= 1) {\n\t\tres.emplace_back(0, n - 1);\n\t\treturn res;\n\t}\n\tint x\
    \ = 0;\n\tbool flag = v[0] < v[1];\n\tfor (int i = 0; i < n; i++) {\n\t\tif (i\
    \ == n - 1 || !((flag && v[i] < v[i + 1]) || (!flag && v[i] > v[i + 1]))) {\n\t\
    \t\tflag = flag ? false : true;\n\t\t\tres.emplace_back(x, i);\n\t\t\tx = i;\n\
    \t\t}\n\t}\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Utility/splitRange.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/splitRange.cpp
layout: document
redirect_from:
- /library/Utility/splitRange.cpp
- /library/Utility/splitRange.cpp.html
title: Utility/splitRange.cpp
---
