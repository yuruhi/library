---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"old/RAUQRSQ.cpp\"\n#include <vector>\n#include <optional>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class RAUQRSQ {\n\
    \tint n;\n\tT init;\n\tvector<T> node, lazy_a;\n\tvector<optional<T>> lazy_u;\n\
    \tstatic int ceil2(int n) {\n\t\tint m = 1;\n\t\twhile (m < n) m *= 2;\n\t\treturn\
    \ m;\n\t}\n\tvoid set_lazy_a(int i, const T& x) {\n\t\tlazy_a[i] += x;\n\t}\n\t\
    void set_lazy_u(int i, const T& x) {\n\t\tlazy_a[i] = 0;\n\t\tlazy_u[i] = x;\n\
    \t}\n\tvoid eval(int k, int l, int r) {\n\t\tif (lazy_u[k]) {\n\t\t\tnode[k] =\
    \ *lazy_u[k];\n\t\t\tif (r - l > 1) {\n\t\t\t\tset_lazy_u(2 * k + 0, *lazy_u[k]);\n\
    \t\t\t\tset_lazy_u(2 * k + 1, *lazy_u[k]);\n\t\t\t}\n\t\t\tlazy_u[k].reset();\n\
    \t\t}\n\t\tif (lazy_a[k] != 0) {\n\t\t\tnode[k] += lazy_a[k];\n\t\t\tif (r - l\
    \ > 1) {\n\t\t\t\tset_lazy_a(2 * k + 0, lazy_a[k] / 2);\n\t\t\t\tset_lazy_a(2\
    \ * k + 1, lazy_a[k] / 2);\n\t\t\t}\n\t\t\tlazy_a[k] = 0;\n\t\t}\n\t}\n\tvoid\
    \ add_impl(int a, int b, const T& x, int k, int l, int r) {\n\t\teval(k, l, r);\n\
    \t\tif (b <= l || r <= a) {\n\t\t\treturn;\n\t\t} else if (a <= l && r <= b) {\n\
    \t\t\tset_lazy_a(k, x * (r - l));\n\t\t\teval(k, l, r);\n\t\t} else {\n\t\t\t\
    add_impl(a, b, x, 2 * k + 0, l, (l + r) / 2);\n\t\t\tadd_impl(a, b, x, 2 * k +\
    \ 1, (l + r) / 2, r);\n\t\t\tnode[k] = node[2 * k + 0] + node[2 * k + 1];\n\t\t\
    }\n\t}\n\tvoid update_impl(int a, int b, const T& x, int k, int l, int r) {\n\t\
    \teval(k, l, r);\n\t\tif (b <= l || r <= a) {\n\t\t\treturn;\n\t\t} else if (a\
    \ <= l && r <= b) {\n\t\t\tset_lazy_u(k, x);\n\t\t\teval(k, l, r);\n\t\t} else\
    \ {\n\t\t\tupdate_impl(a, b, x, 2 * k + 0, l, (l + r) / 2);\n\t\t\tupdate_impl(a,\
    \ b, x, 2 * k + 1, (l + r) / 2, r);\n\t\t\tnode[k] = node[2 * k + 0] + node[2\
    \ * k + 1];\n\t\t}\n\t}\n\tT query_impl(int a, int b, int k, int l, int r) {\n\
    \t\tif (b <= l || r <= a) {\n\t\t\treturn init;\n\t\t}\n\t\teval(k, l, r);\n\t\
    \tif (a <= l && r <= b) {\n\t\t\treturn node[k];\n\t\t} else {\n\t\t\tauto vl\
    \ = query_impl(a, b, 2 * k + 0, l, (l + r) / 2);\n\t\t\tauto vr = query_impl(a,\
    \ b, 2 * k + 1, (l + r) / 2, r);\n\t\t\treturn vl + vr;\n\t\t}\n\t}\n\npublic:\n\
    \tRAUQRSQ(const vector<T>& vec, const T& _init) : init(_init) {\n\t\tbuild(vec);\n\
    \t}\n\tvoid build(const vector<T>& v) {\n\t\tn = ceil2(v.size());\n\t\tnode.assign(n\
    \ * 2, init);\n\t\tlazy_a.assign(n * 2, 0);\n\t\tlazy_u.assign(n * 2, nullopt);\n\
    \t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\tnode[i + n] = v[i];\n\t\t}\n\
    \t\tfor (int i = n - 1; i > 0; --i) {\n\t\t\tnode[i] = node[i * 2 + 0] + node[i\
    \ * 2 + 1];\n\t\t}\n\t}\n\tvoid add(int l, int r, const T& x) {\n\t\tadd_impl(l,\
    \ r, x, 1, 0, n);\n\t}\n\tvoid update(int l, int r, const T& x) {\n\t\tupdate_impl(l,\
    \ r, x, 1, 0, n);\n\t}\n\tT operator[](int i) {\n\t\tassert(0 <= i && i < n);\n\
    \t\treturn operator()(i, i + 1);\n\t}\n\tT operator()(int l, int r) {\n\t\tassert(0\
    \ <= l && l < r && r <= n);\n\t\treturn query_impl(l, r, 1, 0, n);\n\t}\n\tvector<T>\
    \ to_a() {\n\t\tvector<T> res(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tres[i]\
    \ = operator[](i);\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class T> class RAUQRSQ {\n\tint n;\n\tT init;\n\
    \tvector<T> node, lazy_a;\n\tvector<optional<T>> lazy_u;\n\tstatic int ceil2(int\
    \ n) {\n\t\tint m = 1;\n\t\twhile (m < n) m *= 2;\n\t\treturn m;\n\t}\n\tvoid\
    \ set_lazy_a(int i, const T& x) {\n\t\tlazy_a[i] += x;\n\t}\n\tvoid set_lazy_u(int\
    \ i, const T& x) {\n\t\tlazy_a[i] = 0;\n\t\tlazy_u[i] = x;\n\t}\n\tvoid eval(int\
    \ k, int l, int r) {\n\t\tif (lazy_u[k]) {\n\t\t\tnode[k] = *lazy_u[k];\n\t\t\t\
    if (r - l > 1) {\n\t\t\t\tset_lazy_u(2 * k + 0, *lazy_u[k]);\n\t\t\t\tset_lazy_u(2\
    \ * k + 1, *lazy_u[k]);\n\t\t\t}\n\t\t\tlazy_u[k].reset();\n\t\t}\n\t\tif (lazy_a[k]\
    \ != 0) {\n\t\t\tnode[k] += lazy_a[k];\n\t\t\tif (r - l > 1) {\n\t\t\t\tset_lazy_a(2\
    \ * k + 0, lazy_a[k] / 2);\n\t\t\t\tset_lazy_a(2 * k + 1, lazy_a[k] / 2);\n\t\t\
    \t}\n\t\t\tlazy_a[k] = 0;\n\t\t}\n\t}\n\tvoid add_impl(int a, int b, const T&\
    \ x, int k, int l, int r) {\n\t\teval(k, l, r);\n\t\tif (b <= l || r <= a) {\n\
    \t\t\treturn;\n\t\t} else if (a <= l && r <= b) {\n\t\t\tset_lazy_a(k, x * (r\
    \ - l));\n\t\t\teval(k, l, r);\n\t\t} else {\n\t\t\tadd_impl(a, b, x, 2 * k +\
    \ 0, l, (l + r) / 2);\n\t\t\tadd_impl(a, b, x, 2 * k + 1, (l + r) / 2, r);\n\t\
    \t\tnode[k] = node[2 * k + 0] + node[2 * k + 1];\n\t\t}\n\t}\n\tvoid update_impl(int\
    \ a, int b, const T& x, int k, int l, int r) {\n\t\teval(k, l, r);\n\t\tif (b\
    \ <= l || r <= a) {\n\t\t\treturn;\n\t\t} else if (a <= l && r <= b) {\n\t\t\t\
    set_lazy_u(k, x);\n\t\t\teval(k, l, r);\n\t\t} else {\n\t\t\tupdate_impl(a, b,\
    \ x, 2 * k + 0, l, (l + r) / 2);\n\t\t\tupdate_impl(a, b, x, 2 * k + 1, (l + r)\
    \ / 2, r);\n\t\t\tnode[k] = node[2 * k + 0] + node[2 * k + 1];\n\t\t}\n\t}\n\t\
    T query_impl(int a, int b, int k, int l, int r) {\n\t\tif (b <= l || r <= a) {\n\
    \t\t\treturn init;\n\t\t}\n\t\teval(k, l, r);\n\t\tif (a <= l && r <= b) {\n\t\
    \t\treturn node[k];\n\t\t} else {\n\t\t\tauto vl = query_impl(a, b, 2 * k + 0,\
    \ l, (l + r) / 2);\n\t\t\tauto vr = query_impl(a, b, 2 * k + 1, (l + r) / 2, r);\n\
    \t\t\treturn vl + vr;\n\t\t}\n\t}\n\npublic:\n\tRAUQRSQ(const vector<T>& vec,\
    \ const T& _init) : init(_init) {\n\t\tbuild(vec);\n\t}\n\tvoid build(const vector<T>&\
    \ v) {\n\t\tn = ceil2(v.size());\n\t\tnode.assign(n * 2, init);\n\t\tlazy_a.assign(n\
    \ * 2, 0);\n\t\tlazy_u.assign(n * 2, nullopt);\n\t\tfor (size_t i = 0; i < v.size();\
    \ ++i) {\n\t\t\tnode[i + n] = v[i];\n\t\t}\n\t\tfor (int i = n - 1; i > 0; --i)\
    \ {\n\t\t\tnode[i] = node[i * 2 + 0] + node[i * 2 + 1];\n\t\t}\n\t}\n\tvoid add(int\
    \ l, int r, const T& x) {\n\t\tadd_impl(l, r, x, 1, 0, n);\n\t}\n\tvoid update(int\
    \ l, int r, const T& x) {\n\t\tupdate_impl(l, r, x, 1, 0, n);\n\t}\n\tT operator[](int\
    \ i) {\n\t\tassert(0 <= i && i < n);\n\t\treturn operator()(i, i + 1);\n\t}\n\t\
    T operator()(int l, int r) {\n\t\tassert(0 <= l && l < r && r <= n);\n\t\treturn\
    \ query_impl(l, r, 1, 0, n);\n\t}\n\tvector<T> to_a() {\n\t\tvector<T> res(n);\n\
    \t\tfor (int i = 0; i < n; ++i) {\n\t\t\tres[i] = operator[](i);\n\t\t}\n\t\t\
    return res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old/RAUQRSQ.cpp
  requiredBy: []
  timestamp: '2021-01-02 15:13:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/RAUQRSQ.cpp
layout: document
redirect_from:
- /library/old/RAUQRSQ.cpp
- /library/old/RAUQRSQ.cpp.html
title: old/RAUQRSQ.cpp
---