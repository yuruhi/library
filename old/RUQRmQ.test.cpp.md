---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: old/RUQRminQ.cpp
    title: old/RUQRminQ.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F
  bundledCode: "#line 1 \"old/RUQRmQ.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F\"\
    \n#line 2 \"old/RUQRminQ.cpp\"\n#include <vector>\n#include <optional>\n#include\
    \ <cassert>\nusing namespace std;\n\ntemplate <class T> class RUQRmQ {\n\tint\
    \ n;\n\tT init;\n\tvector<T> node;\n\tvector<optional<T>> lazy;\n\tstatic int\
    \ ceil2(int n) {\n\t\tint m = 1;\n\t\twhile (m < n) m *= 2;\n\t\treturn m;\n\t\
    }\n\tvoid eval(int k, int l, int r) {\n\t\tif (lazy[k]) {\n\t\t\tnode[k] = *lazy[k];\n\
    \t\t\tif (r - l > 1) {\n\t\t\t\tlazy[2 * k + 0] = *lazy[k];\n\t\t\t\tlazy[2 *\
    \ k + 1] = *lazy[k];\n\t\t\t}\n\t\t\tlazy[k].reset();\n\t\t}\n\t}\n\tvoid update_impl(int\
    \ a, int b, const T& x, int k, int l, int r) {\n\t\teval(k, l, r);\n\t\tif (b\
    \ <= l || r <= a) {\n\t\t\treturn;\n\t\t} else if (a <= l && r <= b) {\n\t\t\t\
    lazy[k] = x;\n\t\t\teval(k, l, r);\n\t\t} else {\n\t\t\tupdate_impl(a, b, x, 2\
    \ * k + 0, l, (l + r) / 2);\n\t\t\tupdate_impl(a, b, x, 2 * k + 1, (l + r) / 2,\
    \ r);\n\t\t\tnode[k] = min(node[2 * k + 0], node[2 * k + 1]);\n\t\t}\n\t}\n\t\
    T query_impl(int a, int b, int k, int l, int r) {\n\t\tif (b <= l || r <= a) {\n\
    \t\t\treturn init;\n\t\t}\n\t\teval(k, l, r);\n\t\tif (a <= l && r <= b) {\n\t\
    \t\treturn node[k];\n\t\t} else {\n\t\t\tauto vl = query_impl(a, b, 2 * k + 0,\
    \ l, (l + r) / 2);\n\t\t\tauto vr = query_impl(a, b, 2 * k + 1, (l + r) / 2, r);\n\
    \t\t\treturn min(vl, vr);\n\t\t}\n\t}\n\npublic:\n\tRUQRmQ(const vector<T>& vec,\
    \ const T& _init) : init(_init) {\n\t\tbuild(vec);\n\t}\n\tvoid build(const vector<T>&\
    \ v) {\n\t\tn = ceil2(v.size());\n\t\tnode.assign(n * 2, init);\n\t\tlazy.assign(n\
    \ * 2, nullopt);\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\tnode[i +\
    \ n] = v[i];\n\t\t}\n\t\tfor (int i = n - 1; i > 0; --i) {\n\t\t\tnode[i] = min(node[i\
    \ * 2 + 0], node[i * 2 + 1]);\n\t\t}\n\t}\n\tvoid update(int l, int r, const T&\
    \ x) {\n\t\tupdate_impl(l, r, x, 1, 0, n);\n\t}\n\tT operator[](int i) {\n\t\t\
    assert(0 <= i && i < n);\n\t\treturn operator()(i, i + 1);\n\t}\n\tT operator()(int\
    \ l, int r) {\n\t\tassert(0 <= l && l < r && r <= n);\n\t\treturn query_impl(l,\
    \ r, 1, 0, n);\n\t}\n\tvector<T> to_a() {\n\t\tvector<T> res(n);\n\t\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\t\tres[i] = operator[](i);\n\t\t}\n\t\treturn res;\n\
    \t}\n};\n#line 3 \"old/RUQRmQ.test.cpp\"\n#include <iostream>\n#include <limits>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tRUQRmQ<int> seg(vector(n, numeric_limits<int>::max()),\
    \ numeric_limits<int>::max());\n\twhile (q--) {\n\t\tint com;\n\t\tcin >> com;\n\
    \t\tif (com == 0) {\n\t\t\tint l, r, x;\n\t\t\tcin >> l >> r >> x;\n\t\t\tseg.update(l,\
    \ r + 1, x);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout\
    \ << seg(l, r + 1) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F\"\
    \n#include \"./../old/RUQRminQ.cpp\"\n#include <iostream>\n#include <limits>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tRUQRmQ<int> seg(vector(n, numeric_limits<int>::max()),\
    \ numeric_limits<int>::max());\n\twhile (q--) {\n\t\tint com;\n\t\tcin >> com;\n\
    \t\tif (com == 0) {\n\t\t\tint l, r, x;\n\t\t\tcin >> l >> r >> x;\n\t\t\tseg.update(l,\
    \ r + 1, x);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout\
    \ << seg(l, r + 1) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - old/RUQRminQ.cpp
  isVerificationFile: true
  path: old/RUQRmQ.test.cpp
  requiredBy: []
  timestamp: '2021-01-02 15:13:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: old/RUQRmQ.test.cpp
layout: document
redirect_from:
- /verify/old/RUQRmQ.test.cpp
- /verify/old/RUQRmQ.test.cpp.html
title: old/RUQRmQ.test.cpp
---
