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
    \ BinaryIndexedTree {\n\tint n, n2;\n\tvector<T> a;\n\npublic:\n\tBinaryIndexedTree(int\
    \ n_) : n(n_), n2(1), a(n_ + 1) {\n\t\twhile (n2 < n)\n\t\t\tn2 *= 2;\n\t\tn2\
    \ /= 2;\n\t}\n\tT operator()(int i) const {  // [0, i]\n\t\tassert(0 < ++i);\n\
    \t\tT res = 0;\n\t\tfor (; i > 0; i -= i & -i)\n\t\t\tres += a[i];\n\t\treturn\
    \ res;\n\t}\n\tT operator()(int i, int j) const {  // [i, j]\n\t\treturn operator()(j)\
    \ - (i ? operator()(i - 1) : 0);\n\t}\n\tT operator[](int i) const {\n\t\treturn\
    \ operator()(i, i);\n\t}\n\tvoid add(int i, T x) {\n\t\tassert(0 < ++i);\n\t\t\
    for (; i <= n; i += i & -i)\n\t\t\ta[i] += x;\n\t}\n\tint lower_bound(T k) const\
    \ {\n\t\tif (k <= 0) return 0;\n\t\tint res = 0;\n\t\tfor (int i = n2; i > 0;\
    \ i /= 2) {\n\t\t\tif (res + i <= n && a[res + i] < k) {\n\t\t\t\tk -= a[res +\
    \ i];\n\t\t\t\tres += i;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tvector<int>\
    \ to_a() const {\n\t\tvector<int> res(n);\n\t\tfor (int i = 0; i < n; ++i)\n\t\
    \t\tres[i] = operator()(i, i);\n\t\treturn res;\n\t}\n};\n#line 4 \"test/BinaryIndexedTree.test.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n, q;\n\tcin >> n >> q;\n\tBinaryIndexedTree<ll>\
    \ bit(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tll x;\n\t\tcin >> x;\n\t\tbit.add(i,\
    \ x);\n\t}\n\n\twhile (q--) {\n\t\tint com;\n\t\tcin >> com;\n\t\tif (com == 0)\
    \ {\n\t\t\tint p;\n\t\t\tll x;\n\t\t\tcin >> p >> x;\n\t\t\tbit.add(p, x);\n\t\
    \t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << bit(l, r - 1)\
    \ << endl;\n\t\t}\n\t}\n}\n"
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
  timestamp: '2020-11-07 18:36:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/BinaryIndexedTree.test.cpp
layout: document
redirect_from:
- /verify/test/BinaryIndexedTree.test.cpp
- /verify/test/BinaryIndexedTree.test.cpp.html
title: test/BinaryIndexedTree.test.cpp
---
