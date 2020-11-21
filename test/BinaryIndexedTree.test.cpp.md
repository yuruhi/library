---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree.cpp
    title: DataStructure/BinaryIndexedTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/BinaryIndexedTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#include <iostream>\n#line 2 \"DataStructure/BinaryIndexedTree.cpp\"\n#include\
    \ <vector>\n#include <cassert>\nusing namespace std;\n\ntemplate <class T> class\
    \ BinaryIndexedTree {\npublic:\n\tusing value_type = T;\n\nprivate:\n\tint n,\
    \ n2;\n\tvector<value_type> a;\n\npublic:\n\tBinaryIndexedTree(int n_) : n(n_),\
    \ n2(1), a(n_ + 1) {\n\t\twhile (n2 < n) n2 *= 2;\n\t\tn2 /= 2;\n\t}\n\tvalue_type\
    \ operator()(int i) const {  // [0, i]\n\t\tassert(0 < ++i);\n\t\tvalue_type result\
    \ = 0;\n\t\tfor (; i > 0; i -= i & -i) {\n\t\t\tresult += a[i];\n\t\t}\n\t\treturn\
    \ result;\n\t}\n\tvalue_type operator()(int i, int j) const {  // [i, j]\n\t\t\
    return operator()(j) - (i ? operator()(i - 1) : 0);\n\t}\n\tvalue_type operator[](int\
    \ i) const {\n\t\treturn operator()(i, i);\n\t}\n\tvoid add(int i, value_type\
    \ x) {\n\t\tassert(0 < ++i);\n\t\tfor (; i <= n; i += i & -i) {\n\t\t\ta[i] +=\
    \ x;\n\t\t}\n\t}\n\tint lower_bound(value_type k) const {\n\t\tif (k <= 0) return\
    \ 0;\n\t\tint result = 0;\n\t\tfor (int i = n2; i > 0; i /= 2) {\n\t\t\tif (result\
    \ + i <= n && a[result + i] < k) {\n\t\t\t\tk -= a[result + i];\n\t\t\t\tresult\
    \ += i;\n\t\t\t}\n\t\t}\n\t\treturn result;\n\t}\n\tvector<value_type> to_a()\
    \ const {\n\t\tvector<value_type> result(n);\n\t\tfor (int i = 0; i < n; ++i)\
    \ {\n\t\t\tresult[i] = operator()(i, i);\n\t\t}\n\t\treturn result;\n\t}\n};\n\
    #line 4 \"test/BinaryIndexedTree.test.cpp\"\nusing namespace std;\nusing ll =\
    \ long long;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tBinaryIndexedTree<ll> bit(n);\n\tfor (int i =\
    \ 0; i < n; ++i) {\n\t\tll x;\n\t\tcin >> x;\n\t\tbit.add(i, x);\n\t}\n\n\twhile\
    \ (q--) {\n\t\tint com;\n\t\tcin >> com;\n\t\tif (com == 0) {\n\t\t\tint p;\n\t\
    \t\tll x;\n\t\t\tcin >> p >> x;\n\t\t\tbit.add(p, x);\n\t\t} else {\n\t\t\tint\
    \ l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << bit(l, r - 1) << endl;\n\t\t}\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n#include \"./../DataStructure/BinaryIndexedTree.cpp\"\nusing\
    \ namespace std;\nusing ll = long long;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n, q;\n\tcin >> n >> q;\n\tBinaryIndexedTree<ll>\
    \ bit(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tll x;\n\t\tcin >> x;\n\t\tbit.add(i,\
    \ x);\n\t}\n\n\twhile (q--) {\n\t\tint com;\n\t\tcin >> com;\n\t\tif (com == 0)\
    \ {\n\t\t\tint p;\n\t\t\tll x;\n\t\t\tcin >> p >> x;\n\t\t\tbit.add(p, x);\n\t\
    \t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << bit(l, r - 1)\
    \ << endl;\n\t\t}\n\t}\n}"
  dependsOn:
  - DataStructure/BinaryIndexedTree.cpp
  isVerificationFile: true
  path: test/BinaryIndexedTree.test.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/BinaryIndexedTree.test.cpp
layout: document
redirect_from:
- /verify/test/BinaryIndexedTree.test.cpp
- /verify/test/BinaryIndexedTree.test.cpp.html
title: test/BinaryIndexedTree.test.cpp
---
