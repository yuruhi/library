---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree.cpp
    title: DataStructure/BinaryIndexedTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Inversion.test.cpp
    title: test/Inversion.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/BinaryIndexedTree.cpp\"\n#include <vector>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class BinaryIndexedTree\
    \ {\n\tint n, n2;\n\tvector<T> a;\n\npublic:\n\tBinaryIndexedTree(int n_) : n(n_),\
    \ n2(1), a(n_ + 1) {\n\t\twhile (n2 < n)\n\t\t\tn2 *= 2;\n\t\tn2 /= 2;\n\t}\n\t\
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
    \ i);\n\t\treturn res;\n\t}\n};\n#line 4 \"Math/Inversion.cpp\"\nusing namespace\
    \ std;\n\nlong long Inversion(const vector<int>& a, int max_val) {\n\tlong long\
    \ ans = 0;\n\tBinaryIndexedTree<int> bit(max_val + 1);\n\tfor (size_t i = 0; i\
    \ < a.size(); ++i) {\n\t\tans += i - bit(a[i] - 1);\n\t\tbit.add(a[i], 1);\n\t\
    }\n\treturn ans;\n}\n"
  code: "#pragma once\n#include \"./../DataStructure/BinaryIndexedTree.cpp\"\n#include\
    \ <vector>\nusing namespace std;\n\nlong long Inversion(const vector<int>& a,\
    \ int max_val) {\n\tlong long ans = 0;\n\tBinaryIndexedTree<int> bit(max_val +\
    \ 1);\n\tfor (size_t i = 0; i < a.size(); ++i) {\n\t\tans += i - bit(a[i] - 1);\n\
    \t\tbit.add(a[i], 1);\n\t}\n\treturn ans;\n}"
  dependsOn:
  - DataStructure/BinaryIndexedTree.cpp
  isVerificationFile: false
  path: Math/Inversion.cpp
  requiredBy: []
  timestamp: '2020-10-06 22:30:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Inversion.test.cpp
documentation_of: Math/Inversion.cpp
layout: document
redirect_from:
- /library/Math/Inversion.cpp
- /library/Math/Inversion.cpp.html
title: Math/Inversion.cpp
---
