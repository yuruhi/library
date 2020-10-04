---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Inversion.cpp\"\n// description : \u8EE2\u5012\u6570\
    \ a : { 1..N } \u306E\u9806\u5217\nlong long Inversion(const vector<int>& a, int\
    \ max_val) {\n\tlong long ans = 0;\n\tBinaryIndexedTree<int> bit(max_val + 1);\n\
    \tfor (size_t i = 0; i < a.size(); ++i) {\n\t\tans += i - bit(a[i] - 1);\n\t\t\
    bit.add(a[i], 1);\n\t}\n\treturn ans;\n}\n"
  code: "// description : \u8EE2\u5012\u6570 a : { 1..N } \u306E\u9806\u5217\nlong\
    \ long Inversion(const vector<int>& a, int max_val) {\n\tlong long ans = 0;\n\t\
    BinaryIndexedTree<int> bit(max_val + 1);\n\tfor (size_t i = 0; i < a.size(); ++i)\
    \ {\n\t\tans += i - bit(a[i] - 1);\n\t\tbit.add(a[i], 1);\n\t}\n\treturn ans;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Math/Inversion.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Inversion.cpp
layout: document
redirect_from:
- /library/Math/Inversion.cpp
- /library/Math/Inversion.cpp.html
title: Math/Inversion.cpp
---
