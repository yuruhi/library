---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/SegmentTree_old.cpp\"\n#include <vector>\n\
    #include <functional>\n#include <cassert>\nusing namespace std;\n\ntemplate <class\
    \ T> class SegmentTree {\npublic:\n\tusing value_type = T;\n\tusing func_type\
    \ = function<value_type(value_type, value_type)>;\n\nprivate:\n\tint n, original_n;\n\
    \tvalue_type init;\n\tvector<value_type> data;\n\tfunc_type func;\n\tstatic int\
    \ ceil2(int n) {\n\t\tint m = 1;\n\t\twhile (m < n) m *= 2;\n\t\treturn m;\n\t\
    }\n\n\ttemplate <class C> int ff(int a, int b, const C& c, int k, int l, int r)\
    \ const {\n\t\tif (!c(data[k]) || r <= a || b <= l) {\n\t\t\treturn -1;\n\t\t\
    } else if (k >= n) {\n\t\t\treturn k - n;\n\t\t} else {\n\t\t\tint lv = ff(a,\
    \ b, c, 2 * k, l, (l + r) / 2);\n\t\t\tif (lv != -1) return lv;\n\t\t\treturn\
    \ ff(a, b, c, 2 * k + 1, (l + r) / 2, r);\n\t\t}\n\t}\n\ttemplate <class C> int\
    \ fl(int a, int b, const C& c, int k, int l, int r) const {\n\t\tif (!c(data[k])\
    \ || r <= a || b <= l) {\n\t\t\treturn -1;\n\t\t} else if (k >= n) {\n\t\t\treturn\
    \ k - n;\n\t\t} else {\n\t\t\tint rv = fl(a, b, c, 2 * k + 1, (l + r) / 2, r);\n\
    \t\t\tif (rv != -1) return rv;\n\t\t\treturn fl(a, b, c, 2 * k, l, (l + r) / 2);\n\
    \t\t}\n\t}\n\npublic:\n\tSegmentTree(int _n, const value_type& init_, const func_type&\
    \ _func)\n\t    : n(ceil2(_n)), original_n(_n), init(init_), data(n * 2, init),\
    \ func(_func) {}\n\tSegmentTree(const vector<value_type>& vec, const value_type&\
    \ init_, const func_type& _func)\n\t    : init(init_), func(_func) {\n\t\tbuild(vec);\n\
    \t}\n\tvoid build(const vector<value_type>& v) {\n\t\tn = ceil2(v.size());\n\t\
    \toriginal_n = v.size();\n\t\tdata.assign(n * 2, init);\n\t\tfor (size_t i = 0;\
    \ i < v.size(); ++i) {\n\t\t\tdata[i + n] = v[i];\n\t\t}\n\t\tfor (int i = n -\
    \ 1; i > 0; --i) {\n\t\t\tdata[i] = func(data[i * 2], data[i * 2 + 1]);\n\t\t\
    }\n\t}\n\tvoid update(int i, const value_type& x) {\n\t\tassert(0 <= i && i <\
    \ n);\n\t\tdata[i += n] = x;\n\t\twhile (i >>= 1) {\n\t\t\tdata[i] = func(data[i\
    \ * 2], data[i * 2 + 1]);\n\t\t}\n\t}\n\tvoid add(int i, const value_type& x)\
    \ {\n\t\tupdate(i, operator[](i) + x);\n\t}\n\tvalue_type operator[](int i) const\
    \ {\n\t\tassert(0 <= i && i < n);\n\t\treturn data[i + n];\n\t}\n\tvalue_type\
    \ operator()(int l, int r) const {\n\t\tassert(0 <= l && l < r && r <= n);\n\t\
    \tvalue_type L = init, R = init;\n\t\tfor (l += n, r += n; l < r; l >>= 1, r >>=\
    \ 1) {\n\t\t\tif (l & 1) L = func(L, data[l++]);\n\t\t\tif (r & 1) R = func(data[--r],\
    \ R);\n\t\t}\n\t\treturn func(L, R);\n\t}\n\ttemplate <class C> int find_first(int\
    \ l, int r, const C& c) const {\n\t\treturn ff(l, r, c, 1, 0, n);\n\t}\n\ttemplate\
    \ <class C> int find_last(int l, int r, const C& c) const {\n\t\treturn fl(l,\
    \ r, c, 1, 0, n);\n\t}\n\tvector<value_type> to_a() const {\n\t\tvector<value_type>\
    \ res(original_n);\n\t\tfor (int i = 0; i < original_n; ++i) {\n\t\t\tres[i] =\
    \ operator[](i);\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class T> class SegmentTree {\npublic:\n\tusing\
    \ value_type = T;\n\tusing func_type = function<value_type(value_type, value_type)>;\n\
    \nprivate:\n\tint n, original_n;\n\tvalue_type init;\n\tvector<value_type> data;\n\
    \tfunc_type func;\n\tstatic int ceil2(int n) {\n\t\tint m = 1;\n\t\twhile (m <\
    \ n) m *= 2;\n\t\treturn m;\n\t}\n\n\ttemplate <class C> int ff(int a, int b,\
    \ const C& c, int k, int l, int r) const {\n\t\tif (!c(data[k]) || r <= a || b\
    \ <= l) {\n\t\t\treturn -1;\n\t\t} else if (k >= n) {\n\t\t\treturn k - n;\n\t\
    \t} else {\n\t\t\tint lv = ff(a, b, c, 2 * k, l, (l + r) / 2);\n\t\t\tif (lv !=\
    \ -1) return lv;\n\t\t\treturn ff(a, b, c, 2 * k + 1, (l + r) / 2, r);\n\t\t}\n\
    \t}\n\ttemplate <class C> int fl(int a, int b, const C& c, int k, int l, int r)\
    \ const {\n\t\tif (!c(data[k]) || r <= a || b <= l) {\n\t\t\treturn -1;\n\t\t\
    } else if (k >= n) {\n\t\t\treturn k - n;\n\t\t} else {\n\t\t\tint rv = fl(a,\
    \ b, c, 2 * k + 1, (l + r) / 2, r);\n\t\t\tif (rv != -1) return rv;\n\t\t\treturn\
    \ fl(a, b, c, 2 * k, l, (l + r) / 2);\n\t\t}\n\t}\n\npublic:\n\tSegmentTree(int\
    \ _n, const value_type& init_, const func_type& _func)\n\t    : n(ceil2(_n)),\
    \ original_n(_n), init(init_), data(n * 2, init), func(_func) {}\n\tSegmentTree(const\
    \ vector<value_type>& vec, const value_type& init_, const func_type& _func)\n\t\
    \    : init(init_), func(_func) {\n\t\tbuild(vec);\n\t}\n\tvoid build(const vector<value_type>&\
    \ v) {\n\t\tn = ceil2(v.size());\n\t\toriginal_n = v.size();\n\t\tdata.assign(n\
    \ * 2, init);\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\tdata[i + n]\
    \ = v[i];\n\t\t}\n\t\tfor (int i = n - 1; i > 0; --i) {\n\t\t\tdata[i] = func(data[i\
    \ * 2], data[i * 2 + 1]);\n\t\t}\n\t}\n\tvoid update(int i, const value_type&\
    \ x) {\n\t\tassert(0 <= i && i < n);\n\t\tdata[i += n] = x;\n\t\twhile (i >>=\
    \ 1) {\n\t\t\tdata[i] = func(data[i * 2], data[i * 2 + 1]);\n\t\t}\n\t}\n\tvoid\
    \ add(int i, const value_type& x) {\n\t\tupdate(i, operator[](i) + x);\n\t}\n\t\
    value_type operator[](int i) const {\n\t\tassert(0 <= i && i < n);\n\t\treturn\
    \ data[i + n];\n\t}\n\tvalue_type operator()(int l, int r) const {\n\t\tassert(0\
    \ <= l && l < r && r <= n);\n\t\tvalue_type L = init, R = init;\n\t\tfor (l +=\
    \ n, r += n; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) L = func(L, data[l++]);\n\
    \t\t\tif (r & 1) R = func(data[--r], R);\n\t\t}\n\t\treturn func(L, R);\n\t}\n\
    \ttemplate <class C> int find_first(int l, int r, const C& c) const {\n\t\treturn\
    \ ff(l, r, c, 1, 0, n);\n\t}\n\ttemplate <class C> int find_last(int l, int r,\
    \ const C& c) const {\n\t\treturn fl(l, r, c, 1, 0, n);\n\t}\n\tvector<value_type>\
    \ to_a() const {\n\t\tvector<value_type> res(original_n);\n\t\tfor (int i = 0;\
    \ i < original_n; ++i) {\n\t\t\tres[i] = operator[](i);\n\t\t}\n\t\treturn res;\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree_old.cpp
  requiredBy: []
  timestamp: '2021-01-01 21:04:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegmentTree_old.cpp
layout: document
redirect_from:
- /library/DataStructure/SegmentTree_old.cpp
- /library/DataStructure/SegmentTree_old.cpp.html
title: DataStructure/SegmentTree_old.cpp
---
