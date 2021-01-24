---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ImosLinear.test.cpp
    title: test/ImosLinear.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/ImosLinear.cpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class ImosLinear\
    \ {\npublic:\n\tusing value_type = T;\n\tusing data_type = vector<value_type>;\n\
    \nprivate:\n\tsize_t n;\n\tdata_type X, A, B;\n\tbool builded = false;\n\npublic:\n\
    \tImosLinear(size_t _n) : n(_n), X(_n), A(_n + 1), B(_n + 1) {}\n\tvoid add(size_t\
    \ l, size_t r, value_type a,\n\t         value_type b) {  // [l, r) += a + (i\
    \ - l) * b\n\t\tif (l >= r) return;\n\t\tassert(!builded);\n\t\tl = min(l, n);\n\
    \t\tr = min(r, n);\n\t\tA[l] += a - b * l;\n\t\tB[l] += b;\n\t\tA[r] -= a - b\
    \ * l;\n\t\tB[r] -= b;\n\t}\n\tvoid build() {\n\t\tbuilded = true;\n\t\tfor (size_t\
    \ i = 0; i < n; ++i) {\n\t\t\tX[i] = A[i] + B[i] * i;\n\t\t\tA[i + 1] += A[i];\n\
    \t\t\tB[i + 1] += B[i];\n\t\t}\n\t}\n\tvalue_type operator[](size_t i) const {\n\
    \t\tassert(builded);\n\t\treturn X[i];\n\t}\n\tconst data_type& to_a() const {\n\
    \t\tassert(builded);\n\t\treturn X;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class T> class ImosLinear {\npublic:\n\tusing\
    \ value_type = T;\n\tusing data_type = vector<value_type>;\n\nprivate:\n\tsize_t\
    \ n;\n\tdata_type X, A, B;\n\tbool builded = false;\n\npublic:\n\tImosLinear(size_t\
    \ _n) : n(_n), X(_n), A(_n + 1), B(_n + 1) {}\n\tvoid add(size_t l, size_t r,\
    \ value_type a,\n\t         value_type b) {  // [l, r) += a + (i - l) * b\n\t\t\
    if (l >= r) return;\n\t\tassert(!builded);\n\t\tl = min(l, n);\n\t\tr = min(r,\
    \ n);\n\t\tA[l] += a - b * l;\n\t\tB[l] += b;\n\t\tA[r] -= a - b * l;\n\t\tB[r]\
    \ -= b;\n\t}\n\tvoid build() {\n\t\tbuilded = true;\n\t\tfor (size_t i = 0; i\
    \ < n; ++i) {\n\t\t\tX[i] = A[i] + B[i] * i;\n\t\t\tA[i + 1] += A[i];\n\t\t\t\
    B[i + 1] += B[i];\n\t\t}\n\t}\n\tvalue_type operator[](size_t i) const {\n\t\t\
    assert(builded);\n\t\treturn X[i];\n\t}\n\tconst data_type& to_a() const {\n\t\
    \tassert(builded);\n\t\treturn X;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/ImosLinear.cpp
  requiredBy: []
  timestamp: '2020-11-21 20:49:59+09:00'
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
