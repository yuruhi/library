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
    \ {\n\t\t\tresult[i] = operator[](i);\n\t\t}\n\t\treturn result;\n\t}\n};\n#line\
    \ 4 \"Math/Inversion.cpp\"\nusing namespace std;\n\nlong long Inversion(const\
    \ vector<int>& a, int max_val) {\n\tlong long ans = 0;\n\tBinaryIndexedTree<int>\
    \ bit(max_val + 1);\n\tfor (size_t i = 0; i < a.size(); ++i) {\n\t\tans += i -\
    \ bit(a[i]);\n\t\tbit.add(a[i], 1);\n\t}\n\treturn ans;\n}\n"
  code: "#pragma once\n#include \"./../DataStructure/BinaryIndexedTree.cpp\"\n#include\
    \ <vector>\nusing namespace std;\n\nlong long Inversion(const vector<int>& a,\
    \ int max_val) {\n\tlong long ans = 0;\n\tBinaryIndexedTree<int> bit(max_val +\
    \ 1);\n\tfor (size_t i = 0; i < a.size(); ++i) {\n\t\tans += i - bit(a[i]);\n\t\
    \tbit.add(a[i], 1);\n\t}\n\treturn ans;\n}\n"
  dependsOn:
  - DataStructure/BinaryIndexedTree.cpp
  isVerificationFile: false
  path: Math/Inversion.cpp
  requiredBy: []
  timestamp: '2020-12-20 09:41:16+09:00'
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
