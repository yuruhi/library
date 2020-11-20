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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/BinaryIndexedTree.cpp\"\n#include <vector>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class BinaryIndexedTree\
    \ {\n\tint n, n2;\n\tvector<T> a;\n\npublic:\n\tBinaryIndexedTree(int n_) : n(n_),\
    \ n2(1), a(n_ + 1) {\n\t\twhile (n2 < n) n2 *= 2;\n\t\tn2 /= 2;\n\t}\n\tT operator()(int\
    \ i) const {  // [0, i]\n\t\tassert(0 < ++i);\n\t\tT res = 0;\n\t\tfor (; i >\
    \ 0; i -= i & -i) {\n\t\t\tres += a[i];\n\t\t}\n\t\treturn res;\n\t}\n\tT operator()(int\
    \ i, int j) const {  // [i, j]\n\t\treturn operator()(j) - (i ? operator()(i -\
    \ 1) : 0);\n\t}\n\tT operator[](int i) const {\n\t\treturn operator()(i, i);\n\
    \t}\n\tvoid add(int i, T x) {\n\t\tassert(0 < ++i);\n\t\tfor (; i <= n; i += i\
    \ & -i) {\n\t\t\ta[i] += x;\n\t\t}\n\t}\n\tint lower_bound(T k) const {\n\t\t\
    if (k <= 0) return 0;\n\t\tint res = 0;\n\t\tfor (int i = n2; i > 0; i /= 2) {\n\
    \t\t\tif (res + i <= n && a[res + i] < k) {\n\t\t\t\tk -= a[res + i];\n\t\t\t\t\
    res += i;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tvector<int> to_a() const {\n\
    \t\tvector<int> res(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tres[i] = operator()(i,\
    \ i);\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate <class T> class BinaryIndexedTree {\n\tint n, n2;\n\tvector<T> a;\n\
    \npublic:\n\tBinaryIndexedTree(int n_) : n(n_), n2(1), a(n_ + 1) {\n\t\twhile\
    \ (n2 < n) n2 *= 2;\n\t\tn2 /= 2;\n\t}\n\tT operator()(int i) const {  // [0,\
    \ i]\n\t\tassert(0 < ++i);\n\t\tT res = 0;\n\t\tfor (; i > 0; i -= i & -i) {\n\
    \t\t\tres += a[i];\n\t\t}\n\t\treturn res;\n\t}\n\tT operator()(int i, int j)\
    \ const {  // [i, j]\n\t\treturn operator()(j) - (i ? operator()(i - 1) : 0);\n\
    \t}\n\tT operator[](int i) const {\n\t\treturn operator()(i, i);\n\t}\n\tvoid\
    \ add(int i, T x) {\n\t\tassert(0 < ++i);\n\t\tfor (; i <= n; i += i & -i) {\n\
    \t\t\ta[i] += x;\n\t\t}\n\t}\n\tint lower_bound(T k) const {\n\t\tif (k <= 0)\
    \ return 0;\n\t\tint res = 0;\n\t\tfor (int i = n2; i > 0; i /= 2) {\n\t\t\tif\
    \ (res + i <= n && a[res + i] < k) {\n\t\t\t\tk -= a[res + i];\n\t\t\t\tres +=\
    \ i;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tvector<int> to_a() const {\n\t\t\
    vector<int> res(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tres[i] = operator()(i,\
    \ i);\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryIndexedTree.cpp
  requiredBy:
  - Math/Inversion.cpp
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Inversion.test.cpp
  - test/BinaryIndexedTree.test.cpp
  - test/EulerTourForEdge.test.cpp
documentation_of: DataStructure/BinaryIndexedTree.cpp
layout: document
redirect_from:
- /library/DataStructure/BinaryIndexedTree.cpp
- /library/DataStructure/BinaryIndexedTree.cpp.html
title: DataStructure/BinaryIndexedTree.cpp
---
