---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/FibonacciTable.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate <class value_type = long long> vector<value_type> FibonacciTable(int\
    \ n) {\n\tvector<value_type> res(n + 1);\n\tfor (int i = 0; i <= n; ++i) {\n\t\
    \tif (i < 2) {\n\t\t\tres[i] = i;\n\t\t} else {\n\t\t\tres[i] = res[i - 1] + res[i\
    \ - 2];\n\t\t}\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate <class\
    \ value_type = long long> vector<value_type> FibonacciTable(int n) {\n\tvector<value_type>\
    \ res(n + 1);\n\tfor (int i = 0; i <= n; ++i) {\n\t\tif (i < 2) {\n\t\t\tres[i]\
    \ = i;\n\t\t} else {\n\t\t\tres[i] = res[i - 1] + res[i - 2];\n\t\t}\n\t}\n\t\
    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/FibonacciTable.cpp
  requiredBy: []
  timestamp: '2020-10-28 22:10:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/FibonacciTable.cpp
layout: document
redirect_from:
- /library/Math/FibonacciTable.cpp
- /library/Math/FibonacciTable.cpp.html
title: Math/FibonacciTable.cpp
---
