---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BinaryIndexedTree.test.cpp
    title: test/BinaryIndexedTree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/BinaryIndexedTree.cpp\"\n#include <vector>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class BinaryIndexedTree\
    \ {\n\tint n, n2;\n\tvector<T> a;\n\npublic:\n\tBinaryIndexedTree(int n_) : n(n_),\
    \ a(n_ + 1), n2(1) {\n\t\twhile (n2 < n)\n\t\t\tn2 *= 2;\n\t\tn2 /= 2;\n\t}\n\t\
    T operator()(int i) const {  // [0, i]\n\t\tassert(0 < ++i);\n\t\tT res = 0;\n\
    \t\tfor (; i > 0; i -= i & -i)\n\t\t\tres += a[i];\n\t\treturn res;\n\t}\n\tT\
    \ operator()(int i, int j) const {  // [i, j]\n\t\treturn operator()(j) - (i ?\
    \ operator()(i - 1) : 0);\n\t}\n\tT operator[](int i) const {\n\t\treturn operator()(i,\
    \ i);\n\t}\n\tvoid add(int i, T x) {\n\t\tassert(0 < ++i);\n\t\tfor (; i <= n;\
    \ i += i & -i)\n\t\t\ta[i] += x;\n\t}\n\tint lower_bound(T k) const {\n\t\tif\
    \ (k <= 0) return 0;\n\t\tint res = 0;\n\t\tfor (int i = n2; i > 0; i /= 2) {\n\
    \t\t\tif (res + i <= n && a[res + i] < k) {\n\t\t\t\tk -= a[res + i];\n\t\t\t\t\
    res += i;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tvector<int> debug() const {\n\
    \t\tvector<int> res(n);\n\t\tfor (int i = 0; i < n; ++i)\n\t\t\tres[i] = operator()(i,\
    \ i);\n\t\treturn res;\n\t}\n};\n"
  code: "#include <vector>\n#include <cassert>\nusing namespace std;\n\ntemplate <class\
    \ T> class BinaryIndexedTree {\n\tint n, n2;\n\tvector<T> a;\n\npublic:\n\tBinaryIndexedTree(int\
    \ n_) : n(n_), a(n_ + 1), n2(1) {\n\t\twhile (n2 < n)\n\t\t\tn2 *= 2;\n\t\tn2\
    \ /= 2;\n\t}\n\tT operator()(int i) const {  // [0, i]\n\t\tassert(0 < ++i);\n\
    \t\tT res = 0;\n\t\tfor (; i > 0; i -= i & -i)\n\t\t\tres += a[i];\n\t\treturn\
    \ res;\n\t}\n\tT operator()(int i, int j) const {  // [i, j]\n\t\treturn operator()(j)\
    \ - (i ? operator()(i - 1) : 0);\n\t}\n\tT operator[](int i) const {\n\t\treturn\
    \ operator()(i, i);\n\t}\n\tvoid add(int i, T x) {\n\t\tassert(0 < ++i);\n\t\t\
    for (; i <= n; i += i & -i)\n\t\t\ta[i] += x;\n\t}\n\tint lower_bound(T k) const\
    \ {\n\t\tif (k <= 0) return 0;\n\t\tint res = 0;\n\t\tfor (int i = n2; i > 0;\
    \ i /= 2) {\n\t\t\tif (res + i <= n && a[res + i] < k) {\n\t\t\t\tk -= a[res +\
    \ i];\n\t\t\t\tres += i;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tvector<int>\
    \ debug() const {\n\t\tvector<int> res(n);\n\t\tfor (int i = 0; i < n; ++i)\n\t\
    \t\tres[i] = operator()(i, i);\n\t\treturn res;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryIndexedTree.cpp
  requiredBy: []
  timestamp: '2020-10-04 11:19:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/BinaryIndexedTree.test.cpp
documentation_of: DataStructure/BinaryIndexedTree.cpp
layout: document
redirect_from:
- /library/DataStructure/BinaryIndexedTree.cpp
- /library/DataStructure/BinaryIndexedTree.cpp.html
title: DataStructure/BinaryIndexedTree.cpp
---
