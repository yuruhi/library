---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/RAQRMaxQ.cpp\"\n#include <vector>\n#include\
    \ <cassert>\nusing namespace std;\n\ntemplate <class T> class RAQRMQ {\n\tint\
    \ n;\n\tT init;\n\tvector<T> node, lazy;\n\tstatic int ceil2(int n) {\n\t\tint\
    \ m = 1;\n\t\twhile (m < n)\n\t\t\tm *= 2;\n\t\treturn m;\n\t}\n\tvoid eval(int\
    \ k, int l, int r) {\n\t\tif (lazy[k] != 0) {\n\t\t\tnode[k] += lazy[k];\n\t\t\
    \tif (r - l > 1) {\n\t\t\t\tlazy[2 * k + 0] += lazy[k];\n\t\t\t\tlazy[2 * k +\
    \ 1] += lazy[k];\n\t\t\t}\n\t\t\tlazy[k] = 0;\n\t\t}\n\t}\n\tvoid add_impl(int\
    \ a, int b, const T& x, int k, int l, int r) {\n\t\teval(k, l, r);\n\t\tif (b\
    \ <= l || r <= a) {\n\t\t\treturn;\n\t\t} else if (a <= l && r <= b) {\n\t\t\t\
    lazy[k] += x;\n\t\t\teval(k, l, r);\n\t\t} else {\n\t\t\tadd_impl(a, b, x, 2 *\
    \ k + 0, l, (l + r) / 2);\n\t\t\tadd_impl(a, b, x, 2 * k + 1, (l + r) / 2, r);\n\
    \t\t\tnode[k] = max(node[2 * k + 0], node[2 * k + 1]);\n\t\t}\n\t}\n\tT query_impl(int\
    \ a, int b, int k, int l, int r) {\n\t\tif (b <= l || r <= a) {\n\t\t\treturn\
    \ init;\n\t\t}\n\t\teval(k, l, r);\n\t\tif (a <= l && r <= b) {\n\t\t\treturn\
    \ node[k];\n\t\t} else {\n\t\t\tauto vl = query_impl(a, b, 2 * k + 0, l, (l +\
    \ r) / 2);\n\t\t\tauto vr = query_impl(a, b, 2 * k + 1, (l + r) / 2, r);\n\t\t\
    \treturn max(vl, vr);\n\t\t}\n\t}\n\npublic:\n\tRAQRMQ(const vector<T>& vec, const\
    \ T& _init) : init(_init) {\n\t\tbuild(vec);\n\t}\n\tvoid build(const vector<T>&\
    \ v) {\n\t\tn = ceil2(v.size());\n\t\tnode.assign(n * 2, init);\n\t\tlazy.assign(n\
    \ * 2, 0);\n\t\tfor (int i = 0; i < v.size(); ++i) {\n\t\t\tnode[i + n] = v[i];\n\
    \t\t}\n\t\tfor (int i = n - 1; i > 0; --i) {\n\t\t\tnode[i] = max(node[i * 2 +\
    \ 0], node[i * 2 + 1]);\n\t\t}\n\t}\n\tvoid add(int l, int r, const T& x) {\n\t\
    \tadd_impl(l, r, x, 1, 0, n);\n\t}\n\tT operator[](int i) {\n\t\tassert(0 <= i\
    \ && i < n);\n\t\treturn operator()(i, i + 1);\n\t}\n\tT operator()(int l, int\
    \ r) {\n\t\tl = clamp(l, 0, n - 1);\n\t\tr = clamp(r, 0 + 1, n);\n\t\tassert(l\
    \ < r);\n\t\treturn query_impl(l, r, 1, 0, n);\n\t}\n\tvector<T> to_a() {\n\t\t\
    vector<T> res(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tres[i] = operator[](i);\n\
    \t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate <class T> class RAQRMQ {\n\tint n;\n\tT init;\n\tvector<T> node, lazy;\n\
    \tstatic int ceil2(int n) {\n\t\tint m = 1;\n\t\twhile (m < n)\n\t\t\tm *= 2;\n\
    \t\treturn m;\n\t}\n\tvoid eval(int k, int l, int r) {\n\t\tif (lazy[k] != 0)\
    \ {\n\t\t\tnode[k] += lazy[k];\n\t\t\tif (r - l > 1) {\n\t\t\t\tlazy[2 * k + 0]\
    \ += lazy[k];\n\t\t\t\tlazy[2 * k + 1] += lazy[k];\n\t\t\t}\n\t\t\tlazy[k] = 0;\n\
    \t\t}\n\t}\n\tvoid add_impl(int a, int b, const T& x, int k, int l, int r) {\n\
    \t\teval(k, l, r);\n\t\tif (b <= l || r <= a) {\n\t\t\treturn;\n\t\t} else if\
    \ (a <= l && r <= b) {\n\t\t\tlazy[k] += x;\n\t\t\teval(k, l, r);\n\t\t} else\
    \ {\n\t\t\tadd_impl(a, b, x, 2 * k + 0, l, (l + r) / 2);\n\t\t\tadd_impl(a, b,\
    \ x, 2 * k + 1, (l + r) / 2, r);\n\t\t\tnode[k] = max(node[2 * k + 0], node[2\
    \ * k + 1]);\n\t\t}\n\t}\n\tT query_impl(int a, int b, int k, int l, int r) {\n\
    \t\tif (b <= l || r <= a) {\n\t\t\treturn init;\n\t\t}\n\t\teval(k, l, r);\n\t\
    \tif (a <= l && r <= b) {\n\t\t\treturn node[k];\n\t\t} else {\n\t\t\tauto vl\
    \ = query_impl(a, b, 2 * k + 0, l, (l + r) / 2);\n\t\t\tauto vr = query_impl(a,\
    \ b, 2 * k + 1, (l + r) / 2, r);\n\t\t\treturn max(vl, vr);\n\t\t}\n\t}\n\npublic:\n\
    \tRAQRMQ(const vector<T>& vec, const T& _init) : init(_init) {\n\t\tbuild(vec);\n\
    \t}\n\tvoid build(const vector<T>& v) {\n\t\tn = ceil2(v.size());\n\t\tnode.assign(n\
    \ * 2, init);\n\t\tlazy.assign(n * 2, 0);\n\t\tfor (int i = 0; i < v.size(); ++i)\
    \ {\n\t\t\tnode[i + n] = v[i];\n\t\t}\n\t\tfor (int i = n - 1; i > 0; --i) {\n\
    \t\t\tnode[i] = max(node[i * 2 + 0], node[i * 2 + 1]);\n\t\t}\n\t}\n\tvoid add(int\
    \ l, int r, const T& x) {\n\t\tadd_impl(l, r, x, 1, 0, n);\n\t}\n\tT operator[](int\
    \ i) {\n\t\tassert(0 <= i && i < n);\n\t\treturn operator()(i, i + 1);\n\t}\n\t\
    T operator()(int l, int r) {\n\t\tl = clamp(l, 0, n - 1);\n\t\tr = clamp(r, 0\
    \ + 1, n);\n\t\tassert(l < r);\n\t\treturn query_impl(l, r, 1, 0, n);\n\t}\n\t\
    vector<T> to_a() {\n\t\tvector<T> res(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\
    \t\t\tres[i] = operator[](i);\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RAQRMaxQ.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/RAQRMaxQ.cpp
layout: document
redirect_from:
- /library/DataStructure/RAQRMaxQ.cpp
- /library/DataStructure/RAQRMaxQ.cpp.html
title: DataStructure/RAQRMaxQ.cpp
---
