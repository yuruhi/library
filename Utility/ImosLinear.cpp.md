---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/ImosLinear.cpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class ImosLinear\
    \ {\n\tconst int N;\n\tvector<T> X, A, B;\n\tbool flag = false;\n\npublic:\n\t\
    ImosLinear(int _n) : N(_n), X(_n), A(_n + 1), B(_n + 1) {}\n\tvoid add(int l,\
    \ int r, T a, T b) {  // [l, r) += a + (i - l) * b\n\t\tif (l >= r) return;\n\t\
    \tassert(!flag);\n\t\tl = max(min(l, N), 0);\n\t\tr = max(min(r, N), 0);\n\t\t\
    A[l] += a - b * l;\n\t\tB[l] += b;\n\t\tA[r] -= a - b * l;\n\t\tB[r] -= b;\n\t\
    }\n\tvoid build() {\n\t\tflag = true;\n\t\tfor (int i = 0; i < N; ++i) {\n\t\t\
    \tX[i] = A[i] + B[i] * i;\n\t\t\tA[i + 1] += A[i];\n\t\t\tB[i + 1] += B[i];\n\t\
    \t}\n\t}\n\tT operator[](int i) const {\n\t\tassert(flag);\n\t\treturn X[i];\n\
    \t}\n\tconst vector<T>& operator*() const {\n\t\tassert(flag);\n\t\treturn X;\n\
    \t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class T> class ImosLinear {\n\tconst int N;\n\
    \tvector<T> X, A, B;\n\tbool flag = false;\n\npublic:\n\tImosLinear(int _n) :\
    \ N(_n), X(_n), A(_n + 1), B(_n + 1) {}\n\tvoid add(int l, int r, T a, T b) {\
    \  // [l, r) += a + (i - l) * b\n\t\tif (l >= r) return;\n\t\tassert(!flag);\n\
    \t\tl = max(min(l, N), 0);\n\t\tr = max(min(r, N), 0);\n\t\tA[l] += a - b * l;\n\
    \t\tB[l] += b;\n\t\tA[r] -= a - b * l;\n\t\tB[r] -= b;\n\t}\n\tvoid build() {\n\
    \t\tflag = true;\n\t\tfor (int i = 0; i < N; ++i) {\n\t\t\tX[i] = A[i] + B[i]\
    \ * i;\n\t\t\tA[i + 1] += A[i];\n\t\t\tB[i + 1] += B[i];\n\t\t}\n\t}\n\tT operator[](int\
    \ i) const {\n\t\tassert(flag);\n\t\treturn X[i];\n\t}\n\tconst vector<T>& operator*()\
    \ const {\n\t\tassert(flag);\n\t\treturn X;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Utility/ImosLinear.cpp
  requiredBy: []
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/ImosLinear.cpp
layout: document
redirect_from:
- /library/Utility/ImosLinear.cpp
- /library/Utility/ImosLinear.cpp.html
title: Utility/ImosLinear.cpp
---
