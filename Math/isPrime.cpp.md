---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/isPrime.cpp\"\n// description : \u7D20\u6570\u5224\u5B9A\
    \uFF08\u8A66\u3057\u5272\u6CD5\uFF09\ntemplate <class T> bool isPrime(T n) {\n\
    \tif (n == 2) return true;\n\tif (n < 2 || n % 2 == 0) return false;\n\tfor (T\
    \ i = 3; i * i <= n; i += 2)\n\t\tif (n % i == 0) return false;\n\treturn true;\n\
    }\n"
  code: "// description : \u7D20\u6570\u5224\u5B9A\uFF08\u8A66\u3057\u5272\u6CD5\uFF09\
    \ntemplate <class T> bool isPrime(T n) {\n\tif (n == 2) return true;\n\tif (n\
    \ < 2 || n % 2 == 0) return false;\n\tfor (T i = 3; i * i <= n; i += 2)\n\t\t\
    if (n % i == 0) return false;\n\treturn true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/isPrime.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/isPrime.cpp
layout: document
redirect_from:
- /library/Math/isPrime.cpp
- /library/Math/isPrime.cpp.html
title: Math/isPrime.cpp
---
