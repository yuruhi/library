---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SegmentTree.cpp\"\n// description : update,\
    \ range query\ntemplate <class T> class SegmentTree {\n\tusing Func = function<T(T,\
    \ T)>;\n\tint N;\n\tT init;\n\tvector<T> A;\n\tFunc F;\n\tstatic int ceil2(int\
    \ n) {\n\t\tint m = 1;\n\t\twhile (m < n)\n\t\t\tm *= 2;\n\t\treturn m;\n\t}\n\
    \n\ttemplate <class C> int ff(int a, int b, const C& c, int k, int l, int r) const\
    \ {\n\t\tif (!c(A[k]) || r <= a || b <= l) {\n\t\t\treturn -1;\n\t\t} else if\
    \ (k >= N) {\n\t\t\treturn k - N;\n\t\t} else {\n\t\t\tint lv = ff(a, b, c, 2\
    \ * k, l, (l + r) / 2);\n\t\t\tif (lv != -1) return lv;\n\t\t\treturn ff(a, b,\
    \ c, 2 * k + 1, (l + r) / 2, r);\n\t\t}\n\t}\n\ttemplate <class C> int fl(int\
    \ a, int b, const C& c, int k, int l, int r) const {\n\t\tif (!c(A[k]) || r <=\
    \ a || b <= l) {\n\t\t\treturn -1;\n\t\t} else if (k >= N) {\n\t\t\treturn k -\
    \ N;\n\t\t} else {\n\t\t\tint rv = fl(a, b, c, 2 * k + 1, (l + r) / 2, r);\n\t\
    \t\tif (rv != -1) return rv;\n\t\t\treturn fl(a, b, c, 2 * k, l, (l + r) / 2);\n\
    \t\t}\n\t}\n\npublic:\n\tSegmentTree(int n, const T& init_, const Func& f) : N(ceil2(n)),\
    \ init(init_), A(N * 2, init), F(f) {}\n\tSegmentTree(const vector<T>& vec, const\
    \ T& init_, const Func& f) : init(init_), F(f) {\n\t\tbuild(vec);\n\t}\n\tvoid\
    \ build(const vector<T>& v) {\n\t\tN = ceil2(v.size());\n\t\tA.assign(N * 2, init);\n\
    \t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\tA[i + N] = v[i];\n\t\t}\n\t\
    \tfor (int i = N - 1; i > 0; --i) {\n\t\t\tA[i] = F(A[i * 2], A[i * 2 + 1]);\n\
    \t\t}\n\t}\n\tvoid update(int i, const T& x) {\n\t\tassert(0 <= i && i < N);\n\
    \t\tA[i += N] = x;\n\t\twhile (i >>= 1) {\n\t\t\tA[i] = F(A[i * 2], A[i * 2 +\
    \ 1]);\n\t\t}\n\t}\n\tT operator[](int i) const {\n\t\tassert(0 <= i && i < N);\n\
    \t\treturn A[i + N];\n\t}\n\tT operator()(int l, int r) const {  // [l, r)\n\t\
    \tassert(0 <= l && l < r && r <= N);\n\t\tT L = init, R = init;\n\t\tfor (l +=\
    \ N, r += N; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) L = F(L, A[l++]);\n\t\
    \t\tif (r & 1) R = F(A[--r], R);\n\t\t}\n\t\treturn F(L, R);\n\t}\n\ttemplate\
    \ <class C> int find_first(int l, int r, const C& c) const {\n\t\treturn ff(l,\
    \ r, c, 1, 0, N);\n\t}\n\ttemplate <class C> int find_last(int l, int r, const\
    \ C& c) const {\n\t\treturn fl(l, r, c, 1, 0, N);\n\t}\n\tvector<T> to_a() const\
    \ {\n\t\tvector<T> res(N);\n\t\tfor (int i = 0; i < N; ++i)\n\t\t\tres[i] = operator[](i);\n\
    \t\treturn res;\n\t}\n};\n"
  code: "// description : update, range query\ntemplate <class T> class SegmentTree\
    \ {\n\tusing Func = function<T(T, T)>;\n\tint N;\n\tT init;\n\tvector<T> A;\n\t\
    Func F;\n\tstatic int ceil2(int n) {\n\t\tint m = 1;\n\t\twhile (m < n)\n\t\t\t\
    m *= 2;\n\t\treturn m;\n\t}\n\n\ttemplate <class C> int ff(int a, int b, const\
    \ C& c, int k, int l, int r) const {\n\t\tif (!c(A[k]) || r <= a || b <= l) {\n\
    \t\t\treturn -1;\n\t\t} else if (k >= N) {\n\t\t\treturn k - N;\n\t\t} else {\n\
    \t\t\tint lv = ff(a, b, c, 2 * k, l, (l + r) / 2);\n\t\t\tif (lv != -1) return\
    \ lv;\n\t\t\treturn ff(a, b, c, 2 * k + 1, (l + r) / 2, r);\n\t\t}\n\t}\n\ttemplate\
    \ <class C> int fl(int a, int b, const C& c, int k, int l, int r) const {\n\t\t\
    if (!c(A[k]) || r <= a || b <= l) {\n\t\t\treturn -1;\n\t\t} else if (k >= N)\
    \ {\n\t\t\treturn k - N;\n\t\t} else {\n\t\t\tint rv = fl(a, b, c, 2 * k + 1,\
    \ (l + r) / 2, r);\n\t\t\tif (rv != -1) return rv;\n\t\t\treturn fl(a, b, c, 2\
    \ * k, l, (l + r) / 2);\n\t\t}\n\t}\n\npublic:\n\tSegmentTree(int n, const T&\
    \ init_, const Func& f) : N(ceil2(n)), init(init_), A(N * 2, init), F(f) {}\n\t\
    SegmentTree(const vector<T>& vec, const T& init_, const Func& f) : init(init_),\
    \ F(f) {\n\t\tbuild(vec);\n\t}\n\tvoid build(const vector<T>& v) {\n\t\tN = ceil2(v.size());\n\
    \t\tA.assign(N * 2, init);\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\t\
    A[i + N] = v[i];\n\t\t}\n\t\tfor (int i = N - 1; i > 0; --i) {\n\t\t\tA[i] = F(A[i\
    \ * 2], A[i * 2 + 1]);\n\t\t}\n\t}\n\tvoid update(int i, const T& x) {\n\t\tassert(0\
    \ <= i && i < N);\n\t\tA[i += N] = x;\n\t\twhile (i >>= 1) {\n\t\t\tA[i] = F(A[i\
    \ * 2], A[i * 2 + 1]);\n\t\t}\n\t}\n\tT operator[](int i) const {\n\t\tassert(0\
    \ <= i && i < N);\n\t\treturn A[i + N];\n\t}\n\tT operator()(int l, int r) const\
    \ {  // [l, r)\n\t\tassert(0 <= l && l < r && r <= N);\n\t\tT L = init, R = init;\n\
    \t\tfor (l += N, r += N; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) L = F(L,\
    \ A[l++]);\n\t\t\tif (r & 1) R = F(A[--r], R);\n\t\t}\n\t\treturn F(L, R);\n\t\
    }\n\ttemplate <class C> int find_first(int l, int r, const C& c) const {\n\t\t\
    return ff(l, r, c, 1, 0, N);\n\t}\n\ttemplate <class C> int find_last(int l, int\
    \ r, const C& c) const {\n\t\treturn fl(l, r, c, 1, 0, N);\n\t}\n\tvector<T> to_a()\
    \ const {\n\t\tvector<T> res(N);\n\t\tfor (int i = 0; i < N; ++i)\n\t\t\tres[i]\
    \ = operator[](i);\n\t\treturn res;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegmentTree.cpp
layout: document
redirect_from:
- /library/DataStructure/SegmentTree.cpp
- /library/DataStructure/SegmentTree.cpp.html
title: DataStructure/SegmentTree.cpp
---
