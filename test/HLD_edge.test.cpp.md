---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RAQRSQ.cpp
    title: DataStructure/RAQRSQ.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/HeavyLightDecomposition.cpp
    title: Graph/HeavyLightDecomposition.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_E
  bundledCode: "#line 1 \"test/HLD_edge.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_E\"\
    \n#line 2 \"Graph/HeavyLightDecomposition.cpp\"\n#include <vector>\n#include <cassert>\n\
    using namespace std;\n\nclass HLD {\n\tint n;\n\tvector<vector<int>> graph;\n\t\
    vector<int> parent, size, depth;\n\tint k;\n\tvector<int> head, hld, index;\n\t\
    bool builded = false;\n\n\tint calc_size(int v, int p, int d) {\n\t\tparent[v]\
    \ = p;\n\t\tsize[v] = 1;\n\t\tdepth[v] = 1;\n\t\tfor (int u : graph[v]) {\n\t\t\
    \tif (u != p) {\n\t\t\t\tsize[v] += calc_size(u, v, d + 1);\n\t\t\t}\n\t\t}\n\t\
    \treturn size[v];\n\t}\n\tvoid rec(int v, int p, int root) {\n\t\thead[v] = root;\n\
    \t\tindex[v] = k;\n\t\thld[k++] = v;\n\n\t\tint heavy_vertex = -1, max_size =\
    \ 0;\n\t\tfor (int u : graph[v]) {\n\t\t\tif (u != p && max_size < size[u]) {\n\
    \t\t\t\tmax_size = size[u];\n\t\t\t\theavy_vertex = u;\n\t\t\t}\n\t\t}\n\t\tif\
    \ (heavy_vertex == -1) return;\n\t\trec(heavy_vertex, v, root);\n\t\tfor (int\
    \ u : graph[v]) {\n\t\t\tif (u != heavy_vertex && u != p) {\n\t\t\t\trec(u, v,\
    \ u);\n\t\t\t}\n\t\t}\n\t}\n\npublic:\n\tHLD(int _n) : n(_n), graph(_n) {}\n\t\
    HLD(const vector<vector<int>>& _graph) : n(_graph.size()), graph(_graph) {}\n\t\
    void add_edge(int u, int v) {\n\t\tgraph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\
    \t\tbuilded = false;\n\t}\n\tvoid build(int root) {\n\t\tparent.assign(n, -1);\n\
    \t\tsize.assign(n, 0);\n\t\tdepth.assign(n, 0);\n\t\tcalc_size(root, -1, 1);\n\
    \t\tk = 0;\n\t\thead.assign(n, 0);\n\t\thld.assign(n, 0);\n\t\tindex.assign(n,\
    \ 0);\n\t\trec(root, -1, root);\n\t\tbuilded = true;\n\t}\n\tconst vector<int>&\
    \ get_head() const {\n\t\tassert(builded);\n\t\treturn head;\n\t}\n\tconst vector<int>&\
    \ get_hld() const {\n\t\tassert(builded);\n\t\treturn hld;\n\t}\n\tconst vector<int>&\
    \ get_index() const {\n\t\tassert(builded);\n\t\treturn index;\n\t}\n\tint operator[](int\
    \ v) const {\n\t\tassert(builded);\n\t\treturn index[v];\n\t}\n\n\ttemplate <class\
    \ F> void each_vertex(int v, int u, F f) const {\n\t\tassert(builded);\n\t\twhile\
    \ (true) {\n\t\t\tif (index[v] > index[u]) swap(v, u);\n\t\t\tif (head[v] != head[u])\
    \ {\n\t\t\t\tf(index[head[u]], index[u]);\n\t\t\t\tu = parent[head[u]];\n\t\t\t\
    } else {\n\t\t\t\tf(index[v], index[u]);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t}\n\
    \ttemplate <class F> void each_edge(int v, int u, F f) const {\n\t\tassert(builded);\n\
    \t\twhile (true) {\n\t\t\tif (index[v] > index[u]) swap(v, u);\n\t\t\tif (head[v]\
    \ != head[u]) {\n\t\t\t\tf(index[head[u]], index[u]);\n\t\t\t\tu = parent[head[u]];\n\
    \t\t\t} else {\n\t\t\t\tif (v != u) f(index[v] + 1, index[u]);\n\t\t\t\tbreak;\n\
    \t\t\t}\n\t\t}\n\t}\n\tvector<pair<int, int>> query_vertex(int u, int v) {\n\t\
    \tassert(builded);\n\t\tvector<pair<int, int>> result;\n\t\teach_vertex(u, v,\
    \ [&](int a, int b) { result.emplace_back(a, b); });\n\t\treturn result;\n\t}\n\
    \tvector<pair<int, int>> query_edge(int u, int v) {\n\t\tassert(builded);\n\t\t\
    vector<pair<int, int>> result;\n\t\teach_edge(u, v, [&](int a, int b) { result.emplace_back(a,\
    \ b); });\n\t\treturn result;\n\t}\n};\n#line 4 \"DataStructure/RAQRSQ.cpp\"\n\
    using namespace std;\n\ntemplate <class T> class RAQRSQ {\n\tint n;\n\tT init;\n\
    \tvector<T> node, lazy;\n\tstatic int ceil2(int n) {\n\t\tint m = 1;\n\t\twhile\
    \ (m < n) m *= 2;\n\t\treturn m;\n\t}\n\tvoid eval(int k, int l, int r) {\n\t\t\
    if (lazy[k] != 0) {\n\t\t\tnode[k] += lazy[k];\n\t\t\tif (r - l > 1) {\n\t\t\t\
    \tlazy[2 * k + 0] += lazy[k] / 2;\n\t\t\t\tlazy[2 * k + 1] += lazy[k] / 2;\n\t\
    \t\t}\n\t\t\tlazy[k] = 0;\n\t\t}\n\t}\n\tvoid add_impl(int a, int b, const T&\
    \ x, int k, int l, int r) {\n\t\teval(k, l, r);\n\t\tif (b <= l || r <= a) {\n\
    \t\t\treturn;\n\t\t} else if (a <= l && r <= b) {\n\t\t\tlazy[k] += x * (r - l);\n\
    \t\t\teval(k, l, r);\n\t\t} else {\n\t\t\tadd_impl(a, b, x, 2 * k + 0, l, (l +\
    \ r) / 2);\n\t\t\tadd_impl(a, b, x, 2 * k + 1, (l + r) / 2, r);\n\t\t\tnode[k]\
    \ = node[2 * k + 0] + node[2 * k + 1];\n\t\t}\n\t}\n\tT query_impl(int a, int\
    \ b, int k, int l, int r) {\n\t\tif (b <= l || r <= a) {\n\t\t\treturn init;\n\
    \t\t}\n\t\teval(k, l, r);\n\t\tif (a <= l && r <= b) {\n\t\t\treturn node[k];\n\
    \t\t} else {\n\t\t\tauto vl = query_impl(a, b, 2 * k + 0, l, (l + r) / 2);\n\t\
    \t\tauto vr = query_impl(a, b, 2 * k + 1, (l + r) / 2, r);\n\t\t\treturn vl +\
    \ vr;\n\t\t}\n\t}\n\npublic:\n\tRAQRSQ(const vector<T>& vec, const T& _init) :\
    \ init(_init) {\n\t\tbuild(vec);\n\t}\n\tvoid build(const vector<T>& v) {\n\t\t\
    n = ceil2(v.size());\n\t\tnode.assign(n * 2, init);\n\t\tlazy.assign(n * 2, 0);\n\
    \t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\tnode[i + n] = v[i];\n\t\t}\n\
    \t\tfor (size_t i = n - 1; i > 0; --i) {\n\t\t\tnode[i] = node[i * 2 + 0] + node[i\
    \ * 2 + 1];\n\t\t}\n\t}\n\tvoid add(int l, int r, const T& x) {\n\t\tadd_impl(l,\
    \ r, x, 1, 0, n);\n\t}\n\tT operator[](int i) {\n\t\tassert(0 <= i && i < n);\n\
    \t\treturn operator()(i, i + 1);\n\t}\n\tT operator()(int l, int r) {\n\t\tassert(0\
    \ <= l && l < r && r <= n);\n\t\treturn query_impl(l, r, 1, 0, n);\n\t}\n\tvector<T>\
    \ to_a() {\n\t\tvector<T> res(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tres[i]\
    \ = operator[](i);\n\t\t}\n\t\treturn res;\n\t}\n};\n#line 4 \"test/HLD_edge.test.cpp\"\
    \n#include <iostream>\n#line 6 \"test/HLD_edge.test.cpp\"\nusing namespace std;\n\
    using ll = long long;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tint n;\n\tcin >> n;\n\tHLD hld(n);\n\tfor (int v = 0; v < n; ++v) {\n\t\t\
    int k;\n\t\tcin >> k;\n\t\twhile (k--) {\n\t\t\tint u;\n\t\t\tcin >> u;\n\t\t\t\
    hld.add_edge(v, u);\n\t\t}\n\t}\n\thld.build(0);\n\n\tRAQRSQ<ll> seg(vector(n,\
    \ 0ll), 0);\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint com;\n\t\tcin >>\
    \ com;\n\t\tif (com == 0) {\n\t\t\tint v;\n\t\t\tll w;\n\t\t\tcin >> v >> w;\n\
    \t\t\thld.each_edge(0, v, [&](int a, int b) { seg.add(a, b + 1, w); });\n\t\t\
    } else if (com == 1) {\n\t\t\tint u;\n\t\t\tcin >> u;\n\t\t\tll ans = 0;\n\t\t\
    \thld.each_edge(0, u, [&](int a, int b) { ans += seg(a, b + 1); });\n\t\t\tcout\
    \ << ans << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_E\"\
    \n#include \"./../Graph/HeavyLightDecomposition.cpp\"\n#include \"./../DataStructure/RAQRSQ.cpp\"\
    \n#include <iostream>\n#include <vector>\nusing namespace std;\nusing ll = long\
    \ long;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tint n;\n\tcin >> n;\n\tHLD hld(n);\n\tfor (int v = 0; v < n; ++v) {\n\t\t\
    int k;\n\t\tcin >> k;\n\t\twhile (k--) {\n\t\t\tint u;\n\t\t\tcin >> u;\n\t\t\t\
    hld.add_edge(v, u);\n\t\t}\n\t}\n\thld.build(0);\n\n\tRAQRSQ<ll> seg(vector(n,\
    \ 0ll), 0);\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint com;\n\t\tcin >>\
    \ com;\n\t\tif (com == 0) {\n\t\t\tint v;\n\t\t\tll w;\n\t\t\tcin >> v >> w;\n\
    \t\t\thld.each_edge(0, v, [&](int a, int b) { seg.add(a, b + 1, w); });\n\t\t\
    } else if (com == 1) {\n\t\t\tint u;\n\t\t\tcin >> u;\n\t\t\tll ans = 0;\n\t\t\
    \thld.each_edge(0, u, [&](int a, int b) { ans += seg(a, b + 1); });\n\t\t\tcout\
    \ << ans << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - Graph/HeavyLightDecomposition.cpp
  - DataStructure/RAQRSQ.cpp
  isVerificationFile: true
  path: test/HLD_edge.test.cpp
  requiredBy: []
  timestamp: '2020-12-23 14:02:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/HLD_edge.test.cpp
layout: document
redirect_from:
- /verify/test/HLD_edge.test.cpp
- /verify/test/HLD_edge.test.cpp.html
title: test/HLD_edge.test.cpp
---
