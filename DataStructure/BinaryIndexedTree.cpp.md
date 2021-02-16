---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/Inversion.cpp
    title: Math/Inversion.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BinaryIndexedTree.test.cpp
    title: test/BinaryIndexedTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/EulerTourForEdge.test.cpp
    title: test/EulerTourForEdge.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Inversion.test.cpp
    title: test/Inversion.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/BinaryIndexedTree.cpp\"\n#include <vector>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class BinaryIndexedTree\
    \ {\npublic:\n\tusing value_type = T;\n\nprivate:\n\tint n, n2;\n\tvector<value_type>\
    \ a;\n\npublic:\n\tBinaryIndexedTree(int n_) : n(n_), n2(1), a(n_ + 1) {\n\t\t\
    while (n2 < n) n2 *= 2;\n\t\tn2 /= 2;\n\t}\n\tvalue_type operator()(int i) const\
    \ {  // [0, i)\n\t\tif (i == 0) return 0;\n\t\tassert(0 < i && i <= n);\n\t\t\
    value_type result = 0;\n\t\tfor (; i > 0; i -= i & -i) {\n\t\t\tresult += a[i];\n\
    \t\t}\n\t\treturn result;\n\t}\n\tvalue_type operator()(int l, int r) const {\
    \  // [l, r)\n\t\treturn operator()(r) - operator()(l);\n\t}\n\tvalue_type operator[](int\
    \ i) const {\n\t\treturn operator()(i, i + 1);\n\t}\n\tvoid add(int i, value_type\
    \ x) {\n\t\tassert(0 < ++i);\n\t\tfor (; i <= n; i += i & -i) {\n\t\t\ta[i] +=\
    \ x;\n\t\t}\n\t}\n\tint lower_bound(value_type k) const {\n\t\tif (k <= 0) return\
    \ 0;\n\t\tint result = 0;\n\t\tfor (int i = n2; i > 0; i /= 2) {\n\t\t\tif (result\
    \ + i <= n && a[result + i] < k) {\n\t\t\t\tk -= a[result + i];\n\t\t\t\tresult\
    \ += i;\n\t\t\t}\n\t\t}\n\t\treturn result;\n\t}\n\tvector<value_type> to_a()\
    \ const {\n\t\tvector<value_type> result(n);\n\t\tfor (int i = 0; i < n; ++i)\
    \ {\n\t\t\tresult[i] = operator[](i);\n\t\t}\n\t\treturn result;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate <class T> class BinaryIndexedTree {\npublic:\n\tusing value_type =\
    \ T;\n\nprivate:\n\tint n, n2;\n\tvector<value_type> a;\n\npublic:\n\tBinaryIndexedTree(int\
    \ n_) : n(n_), n2(1), a(n_ + 1) {\n\t\twhile (n2 < n) n2 *= 2;\n\t\tn2 /= 2;\n\
    \t}\n\tvalue_type operator()(int i) const {  // [0, i)\n\t\tif (i == 0) return\
    \ 0;\n\t\tassert(0 < i && i <= n);\n\t\tvalue_type result = 0;\n\t\tfor (; i >\
    \ 0; i -= i & -i) {\n\t\t\tresult += a[i];\n\t\t}\n\t\treturn result;\n\t}\n\t\
    value_type operator()(int l, int r) const {  // [l, r)\n\t\treturn operator()(r)\
    \ - operator()(l);\n\t}\n\tvalue_type operator[](int i) const {\n\t\treturn operator()(i,\
    \ i + 1);\n\t}\n\tvoid add(int i, value_type x) {\n\t\tassert(0 < ++i);\n\t\t\
    for (; i <= n; i += i & -i) {\n\t\t\ta[i] += x;\n\t\t}\n\t}\n\tint lower_bound(value_type\
    \ k) const {\n\t\tif (k <= 0) return 0;\n\t\tint result = 0;\n\t\tfor (int i =\
    \ n2; i > 0; i /= 2) {\n\t\t\tif (result + i <= n && a[result + i] < k) {\n\t\t\
    \t\tk -= a[result + i];\n\t\t\t\tresult += i;\n\t\t\t}\n\t\t}\n\t\treturn result;\n\
    \t}\n\tvector<value_type> to_a() const {\n\t\tvector<value_type> result(n);\n\t\
    \tfor (int i = 0; i < n; ++i) {\n\t\t\tresult[i] = operator[](i);\n\t\t}\n\t\t\
    return result;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryIndexedTree.cpp
  requiredBy:
  - Math/Inversion.cpp
  timestamp: '2020-12-20 09:41:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/EulerTourForEdge.test.cpp
  - test/Inversion.test.cpp
  - test/BinaryIndexedTree.test.cpp
documentation_of: DataStructure/BinaryIndexedTree.cpp
layout: document
redirect_from:
- /library/DataStructure/BinaryIndexedTree.cpp
- /library/DataStructure/BinaryIndexedTree.cpp.html
title: DataStructure/BinaryIndexedTree.cpp
---
