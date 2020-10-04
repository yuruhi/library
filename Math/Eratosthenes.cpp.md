---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Eratosthenes.cpp\"\n// description : \u30A8\u30E9\u30C8\
    \u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\nvector<bool> Eratosthenes(int n) {\n\tvector<bool>\
    \ p(n + 1, true);\n\tp[0] = p[1] = false;\n\tfor (long long i = 2; i <= n; ++i)\n\
    \t\tif (p[i])\n\t\t\tfor (long long j = i * i; j <= n; j += i)\n\t\t\t\tp[j] =\
    \ false;\n\treturn p;\n}\n"
  code: "// description : \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\n\
    vector<bool> Eratosthenes(int n) {\n\tvector<bool> p(n + 1, true);\n\tp[0] = p[1]\
    \ = false;\n\tfor (long long i = 2; i <= n; ++i)\n\t\tif (p[i])\n\t\t\tfor (long\
    \ long j = i * i; j <= n; j += i)\n\t\t\t\tp[j] = false;\n\treturn p;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Eratosthenes.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Eratosthenes.cpp
layout: document
redirect_from:
- /library/Math/Eratosthenes.cpp
- /library/Math/Eratosthenes.cpp.html
title: Math/Eratosthenes.cpp
---
