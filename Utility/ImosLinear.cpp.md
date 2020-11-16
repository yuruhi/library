---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ImosLinear.test.cpp
    title: test/ImosLinear.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/ImosLinear.cpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class ImosLinear\
    \ {\npublic:\n\tusing value_type = T;\n\nprivate:\n\tconst int N;\n\tvector<value_type>\
    \ X, A, B;\n\tbool builded = false;\n\npublic:\n\tImosLinear(int _n) : N(_n),\
    \ X(_n), A(_n + 1), B(_n + 1) {}\n\tvoid add(int l, int r, value_type a, value_type\
    \ b) {  // [l, r) += a + (i - l) * b\n\t\tif (l >= r) return;\n\t\tassert(!builded);\n\
    \t\tl = max(min(l, N), 0);\n\t\tr = max(min(r, N), 0);\n\t\tA[l] += a - b * l;\n\
    \t\tB[l] += b;\n\t\tA[r] -= a - b * l;\n\t\tB[r] -= b;\n\t}\n\tvoid build() {\n\
    \t\tbuilded = true;\n\t\tfor (int i = 0; i < N; ++i) {\n\t\t\tX[i] = A[i] + B[i]\
    \ * i;\n\t\t\tA[i + 1] += A[i];\n\t\t\tB[i + 1] += B[i];\n\t\t}\n\t}\n\tvalue_type\
    \ operator[](int i) const {\n\t\tassert(builded);\n\t\treturn X[i];\n\t}\n\tconst\
    \ vector<value_type>& to_a() const {\n\t\tassert(builded);\n\t\treturn X;\n\t\
    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class T> class ImosLinear {\npublic:\n\tusing\
    \ value_type = T;\n\nprivate:\n\tconst int N;\n\tvector<value_type> X, A, B;\n\
    \tbool builded = false;\n\npublic:\n\tImosLinear(int _n) : N(_n), X(_n), A(_n\
    \ + 1), B(_n + 1) {}\n\tvoid add(int l, int r, value_type a, value_type b) { \
    \ // [l, r) += a + (i - l) * b\n\t\tif (l >= r) return;\n\t\tassert(!builded);\n\
    \t\tl = max(min(l, N), 0);\n\t\tr = max(min(r, N), 0);\n\t\tA[l] += a - b * l;\n\
    \t\tB[l] += b;\n\t\tA[r] -= a - b * l;\n\t\tB[r] -= b;\n\t}\n\tvoid build() {\n\
    \t\tbuilded = true;\n\t\tfor (int i = 0; i < N; ++i) {\n\t\t\tX[i] = A[i] + B[i]\
    \ * i;\n\t\t\tA[i + 1] += A[i];\n\t\t\tB[i + 1] += B[i];\n\t\t}\n\t}\n\tvalue_type\
    \ operator[](int i) const {\n\t\tassert(builded);\n\t\treturn X[i];\n\t}\n\tconst\
    \ vector<value_type>& to_a() const {\n\t\tassert(builded);\n\t\treturn X;\n\t\
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/ImosLinear.cpp
  requiredBy: []
  timestamp: '2020-11-16 21:01:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ImosLinear.test.cpp
documentation_of: Utility/ImosLinear.cpp
layout: document
redirect_from:
- /library/Utility/ImosLinear.cpp
- /library/Utility/ImosLinear.cpp.html
title: Utility/ImosLinear.cpp
---
