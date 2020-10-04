---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Primes.cpp\"\n// description : n \u4EE5\u4E0B\u306E\
    \u7D20\u6570\u5217\u6319\nvector<int> Primes(int n) {\n\tvector<int> res;\n\t\
    auto p = Eratosthenes(n);\n\tfor (int i = 0; i <= n; ++i)\n\t\tif (p[i]) res.push_back(i);\n\
    \treturn res;\n}\n"
  code: "// description : n \u4EE5\u4E0B\u306E\u7D20\u6570\u5217\u6319\nvector<int>\
    \ Primes(int n) {\n\tvector<int> res;\n\tauto p = Eratosthenes(n);\n\tfor (int\
    \ i = 0; i <= n; ++i)\n\t\tif (p[i]) res.push_back(i);\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Primes.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Primes.cpp
layout: document
redirect_from:
- /library/Math/Primes.cpp
- /library/Math/Primes.cpp.html
title: Math/Primes.cpp
---
