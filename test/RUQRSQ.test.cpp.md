---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/RUQRSQ.cpp
    title: DataStructure/RUQRSQ.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I
  bundledCode: "#line 1 \"test/RUQRSQ.test.cpp\"\n#define IGNORE\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I\"\n#line\
    \ 2 \"DataStructure/RUQRSQ.cpp\"\n#include <vector>\n#include <optional>\n#include\
    \ <cassert>\nusing namespace std;\n\ntemplate <class T> class RUQRSQ {\n\tint\
    \ n;\n\tvector<T> node;\n\tvector<optional<T>> lazy;\n\tstatic int ceil2(int n)\
    \ {\n\t\tint m = 1;\n\t\twhile (m < n)\n\t\t\tm *= 2;\n\t\treturn m;\n\t}\n\t\
    void eval(int k, int l, int r) {\n\t\tif (lazy[k]) {\n\t\t\tnode[k] = *lazy[k];\n\
    \t\t\tif (r - l > 1) {\n\t\t\t\tlazy[2 * k + 0] = *lazy[k];\n\t\t\t\tlazy[2 *\
    \ k + 1] = *lazy[k];\n\t\t\t}\n\t\t\tlazy[k].reset();\n\t\t}\n\t}\n\tvoid update_impl(int\
    \ a, int b, const T& x, int k, int l, int r) {\n\t\teval(k, l, r);\n\t\tif (b\
    \ <= l || r <= a) {\n\t\t\treturn;\n\t\t} else if (a <= l && r <= b) {\n\t\t\t\
    lazy[k] = x;\n\t\t\teval(k, l, r);\n\t\t} else {\n\t\t\tupdate_impl(a, b, x, 2\
    \ * k + 0, l, (l + r) / 2);\n\t\t\tupdate_impl(a, b, x, 2 * k + 1, (l + r) / 2,\
    \ r);\n\t\t\tnode[k] = node[2 * k + 0] + node[2 * k + 1];\n\t\t}\n\t}\n\tT query_impl(int\
    \ a, int b, int k, int l, int r) {\n\t\tif (b <= l || r <= a) {\n\t\t\treturn\
    \ 0;\n\t\t}\n\t\teval(k, l, r);\n\t\tif (a <= l && r <= b) {\n\t\t\treturn node[k];\n\
    \t\t} else {\n\t\t\tauto vl = query_impl(a, b, 2 * k + 0, l, (l + r) / 2);\n\t\
    \t\tauto vr = query_impl(a, b, 2 * k + 1, (l + r) / 2, r);\n\t\t\treturn vl +\
    \ vr;\n\t\t}\n\t}\n\npublic:\n\tRUQRSQ(const vector<T>& vec) {\n\t\tbuild(vec);\n\
    \t}\n\tvoid build(const vector<T>& v) {\n\t\tn = ceil2(v.size());\n\t\tnode.assign(n\
    \ * 2, 0);\n\t\tlazy.assign(n * 2, nullopt);\n\t\tfor (size_t i = 0; i < v.size();\
    \ ++i) {\n\t\t\tnode[i + n] = v[i];\n\t\t}\n\t\tfor (int i = n - 1; i > 0; --i)\
    \ {\n\t\t\tnode[i] = node[i * 2 + 0] + node[i * 2 + 1];\n\t\t}\n\t}\n\tvoid update(int\
    \ l, int r, const T& x) {\n\t\tupdate_impl(l, r, x, 1, 0, n);\n\t}\n\tT operator[](int\
    \ i) {\n\t\tassert(0 <= i && i < n);\n\t\treturn operator()(i, i + 1);\n\t}\n\t\
    T operator()(int l, int r) {\n\t\tassert(0 <= l && l < r && r <= n);\n\t\treturn\
    \ query_impl(l, r, 1, 0, n);\n\t}\n\tvector<T> to_a() {\n\t\tvector<T> res(n);\n\
    \t\tfor (int i = 0; i < n; ++i) {\n\t\t\tres[i] = operator[](i);\n\t\t}\n\t\t\
    return res;\n\t}\n};\n#line 4 \"test/RUQRSQ.test.cpp\"\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tvector<int> a(n);\n\tRUQRSQ<int> seg(a);\n\t\
    while (q--) {\n\t\tint com;\n\t\tcin >> com;\n\t\tif (com == 0) {\n\t\t\tint l,\
    \ r, x;\n\t\t\tcin >> l >> r >> x;\n\t\t\tseg.update(l, r + 1, x);\n\t\t} else\
    \ {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << seg(l, r + 1) << '\\\
    n';\n\t\t}\n\t}\n}\n"
  code: "#define IGNORE\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I\"\
    \n#include \"./../DataStructure/RUQRSQ.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tvector<int> a(n);\n\tRUQRSQ<int> seg(a);\n\t\
    while (q--) {\n\t\tint com;\n\t\tcin >> com;\n\t\tif (com == 0) {\n\t\t\tint l,\
    \ r, x;\n\t\t\tcin >> l >> r >> x;\n\t\t\tseg.update(l, r + 1, x);\n\t\t} else\
    \ {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << seg(l, r + 1) << '\\\
    n';\n\t\t}\n\t}\n}"
  dependsOn:
  - DataStructure/RUQRSQ.cpp
  isVerificationFile: true
  path: test/RUQRSQ.test.cpp
  requiredBy: []
  timestamp: '2020-11-01 15:48:59+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/RUQRSQ.test.cpp
layout: document
redirect_from:
- /verify/test/RUQRSQ.test.cpp
- /verify/test/RUQRSQ.test.cpp.html
title: test/RUQRSQ.test.cpp
---
