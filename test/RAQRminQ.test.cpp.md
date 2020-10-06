---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RAQRminQ.cpp
    title: DataStructure/RAQRminQ.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H
  bundledCode: "#line 1 \"test/RAQRminQ.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H\"\
    \n#line 2 \"DataStructure/RAQRminQ.cpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class RAQRmQ {\n\
    \tint n;\n\tT init;\n\tvector<T> node, lazy;\n\tstatic int ceil2(int n) {\n\t\t\
    int m = 1;\n\t\twhile (m < n)\n\t\t\tm *= 2;\n\t\treturn m;\n\t}\n\tvoid eval(int\
    \ k, int l, int r) {\n\t\tif (lazy[k] != 0) {\n\t\t\tnode[k] += lazy[k];\n\t\t\
    \tif (r - l > 1) {\n\t\t\t\tlazy[2 * k + 0] += lazy[k];\n\t\t\t\tlazy[2 * k +\
    \ 1] += lazy[k];\n\t\t\t}\n\t\t\tlazy[k] = 0;\n\t\t}\n\t}\n\tvoid add_impl(int\
    \ a, int b, const T& x, int k, int l, int r) {\n\t\teval(k, l, r);\n\t\tif (b\
    \ <= l || r <= a) {\n\t\t\treturn;\n\t\t} else if (a <= l && r <= b) {\n\t\t\t\
    lazy[k] += x;\n\t\t\teval(k, l, r);\n\t\t} else {\n\t\t\tadd_impl(a, b, x, 2 *\
    \ k + 0, l, (l + r) / 2);\n\t\t\tadd_impl(a, b, x, 2 * k + 1, (l + r) / 2, r);\n\
    \t\t\tnode[k] = min(node[2 * k + 0], node[2 * k + 1]);\n\t\t}\n\t}\n\tT query_impl(int\
    \ a, int b, int k, int l, int r) {\n\t\tif (b <= l || r <= a) {\n\t\t\treturn\
    \ init;\n\t\t}\n\t\teval(k, l, r);\n\t\tif (a <= l && r <= b) {\n\t\t\treturn\
    \ node[k];\n\t\t} else {\n\t\t\tauto vl = query_impl(a, b, 2 * k + 0, l, (l +\
    \ r) / 2);\n\t\t\tauto vr = query_impl(a, b, 2 * k + 1, (l + r) / 2, r);\n\t\t\
    \treturn min(vl, vr);\n\t\t}\n\t}\n\npublic:\n\tRAQRmQ(const vector<T>& vec, const\
    \ T& _init) : init(_init) {\n\t\tbuild(vec);\n\t}\n\tvoid build(const vector<T>&\
    \ v) {\n\t\tn = ceil2(v.size());\n\t\tnode.assign(n * 2, init);\n\t\tlazy.assign(n\
    \ * 2, 0);\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\tnode[i + n] = v[i];\n\
    \t\t}\n\t\tfor (int i = n - 1; i > 0; --i) {\n\t\t\tnode[i] = min(node[i * 2 +\
    \ 0], node[i * 2 + 1]);\n\t\t}\n\t}\n\tvoid add(int l, int r, const T& x) {\n\t\
    \tadd_impl(l, r, x, 1, 0, n);\n\t}\n\tT operator[](int i) {\n\t\tassert(0 <= i\
    \ && i < n);\n\t\treturn operator()(i, i + 1);\n\t}\n\tT operator()(int l, int\
    \ r) {\n\t\tassert(0 <= l && l < r && r <= n);\n\t\treturn query_impl(l, r, 1,\
    \ 0, n);\n\t}\n\tvector<T> to_a() {\n\t\tvector<T> res(n);\n\t\tfor (int i = 0;\
    \ i < n; ++i) {\n\t\t\tres[i] = operator[](i);\n\t\t}\n\t\treturn res;\n\t}\n\
    };\n#line 3 \"test/RAQRminQ.test.cpp\"\n#include <iostream>\n#line 5 \"test/RAQRminQ.test.cpp\"\
    \n#include <limits>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n, q;\n\tcin >> n >> q;\n\tRAQRmQ<int>\
    \ seg(vector<int>(n), numeric_limits<int>::max());\n\twhile (q--) {\n\t\tint com;\n\
    \t\tcin >> com;\n\t\tif (com == 0) {\n\t\t\tint l, r, x;\n\t\t\tcin >> l >> r\
    \ >> x;\n\t\t\tseg.add(l, r + 1, x);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin\
    \ >> l >> r;\n\t\t\tcout << seg(l, r + 1) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H\"\
    \n#include \"./../DataStructure/RAQRminQ.cpp\"\n#include <iostream>\n#include\
    \ <vector>\n#include <limits>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n, q;\n\tcin >> n >> q;\n\tRAQRmQ<int>\
    \ seg(vector<int>(n), numeric_limits<int>::max());\n\twhile (q--) {\n\t\tint com;\n\
    \t\tcin >> com;\n\t\tif (com == 0) {\n\t\t\tint l, r, x;\n\t\t\tcin >> l >> r\
    \ >> x;\n\t\t\tseg.add(l, r + 1, x);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin\
    \ >> l >> r;\n\t\t\tcout << seg(l, r + 1) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - DataStructure/RAQRminQ.cpp
  isVerificationFile: true
  path: test/RAQRminQ.test.cpp
  requiredBy: []
  timestamp: '2020-10-06 22:30:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/RAQRminQ.test.cpp
layout: document
redirect_from:
- /verify/test/RAQRminQ.test.cpp
- /verify/test/RAQRminQ.test.cpp.html
title: test/RAQRminQ.test.cpp
---
