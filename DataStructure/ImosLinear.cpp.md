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
  bundledCode: "#line 2 \"DataStructure/ImosLinear.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <cassert>\n\ntemplate <class T> class ImosLinear {\npublic:\n\
    \tusing value_type = T;\n\tusing data_type = std::vector<value_type>;\n\nprivate:\n\
    \tstd::size_t n;\n\tdata_type X, A, B;\n\tbool builded = false;\n\npublic:\n\t\
    ImosLinear(std::size_t _n) : n(_n), X(_n), A(_n + 1), B(_n + 1) {}\n\tvoid add(std::size_t\
    \ l, std::size_t r, value_type a,\n\t         value_type b) {  // [l, r) += a\
    \ + (i - l) * b\n\t\tif (l >= r) return;\n\t\tassert(!builded);\n\t\tl = std::min(l,\
    \ n);\n\t\tr = std::min(r, n);\n\t\tA[l] += a - b * l;\n\t\tB[l] += b;\n\t\tA[r]\
    \ -= a - b * l;\n\t\tB[r] -= b;\n\t}\n\tvoid build() {\n\t\tbuilded = true;\n\t\
    \tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\tX[i] = A[i] + B[i] * i;\n\t\t\t\
    A[i + 1] += A[i];\n\t\t\tB[i + 1] += B[i];\n\t\t}\n\t}\n\tvalue_type operator[](std::size_t\
    \ i) const {\n\t\tassert(builded);\n\t\treturn X[i];\n\t}\n\tconst data_type&\
    \ to_a() const {\n\t\tassert(builded);\n\t\treturn X;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    \ntemplate <class T> class ImosLinear {\npublic:\n\tusing value_type = T;\n\t\
    using data_type = std::vector<value_type>;\n\nprivate:\n\tstd::size_t n;\n\tdata_type\
    \ X, A, B;\n\tbool builded = false;\n\npublic:\n\tImosLinear(std::size_t _n) :\
    \ n(_n), X(_n), A(_n + 1), B(_n + 1) {}\n\tvoid add(std::size_t l, std::size_t\
    \ r, value_type a,\n\t         value_type b) {  // [l, r) += a + (i - l) * b\n\
    \t\tif (l >= r) return;\n\t\tassert(!builded);\n\t\tl = std::min(l, n);\n\t\t\
    r = std::min(r, n);\n\t\tA[l] += a - b * l;\n\t\tB[l] += b;\n\t\tA[r] -= a - b\
    \ * l;\n\t\tB[r] -= b;\n\t}\n\tvoid build() {\n\t\tbuilded = true;\n\t\tfor (std::size_t\
    \ i = 0; i < n; ++i) {\n\t\t\tX[i] = A[i] + B[i] * i;\n\t\t\tA[i + 1] += A[i];\n\
    \t\t\tB[i + 1] += B[i];\n\t\t}\n\t}\n\tvalue_type operator[](std::size_t i) const\
    \ {\n\t\tassert(builded);\n\t\treturn X[i];\n\t}\n\tconst data_type& to_a() const\
    \ {\n\t\tassert(builded);\n\t\treturn X;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/ImosLinear.cpp
  requiredBy: []
  timestamp: '2021-04-06 14:24:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ImosLinear.test.cpp
documentation_of: DataStructure/ImosLinear.cpp
layout: document
redirect_from:
- /library/DataStructure/ImosLinear.cpp
- /library/DataStructure/ImosLinear.cpp.html
title: DataStructure/ImosLinear.cpp
---
