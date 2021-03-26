---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/HLD_LCA.test.cpp
    title: test/HLD_LCA.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/HLD_edge.test.cpp
    title: test/HLD_edge.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/HLD_subtree_edge.test.cpp
    title: test/HLD_subtree_edge.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/HLD_vertex.test.cpp
    title: test/HLD_vertex.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/HeavyLightDecomposition.cpp\"\n#include <vector>\n\
    #include <cassert>\n\nclass HLD {\n\tint n;\n\tstd::vector<std::vector<int>> graph;\n\
    \tstd::vector<int> parent, size;\n\tint k;\n\tstd::vector<int> head, hld, index,\
    \ out_index;\n\tbool builded = false;\n\n\tint calc_size(int v, int p, int d)\
    \ {\n\t\tparent[v] = p;\n\t\tsize[v] = 1;\n\t\tfor (int u : graph[v]) {\n\t\t\t\
    if (u != p) {\n\t\t\t\tsize[v] += calc_size(u, v, d + 1);\n\t\t\t}\n\t\t}\n\t\t\
    return size[v];\n\t}\n\tvoid rec(int v, int p, int root) {\n\t\thead[v] = root;\n\
    \t\tindex[v] = k;\n\t\thld[k++] = v;\n\n\t\tint heavy_vertex = -1, max_size =\
    \ 0;\n\t\tfor (int u : graph[v]) {\n\t\t\tif (u != p && max_size < size[u]) {\n\
    \t\t\t\tmax_size = size[u];\n\t\t\t\theavy_vertex = u;\n\t\t\t}\n\t\t}\n\t\tif\
    \ (heavy_vertex != -1) {\n\t\t\trec(heavy_vertex, v, root);\n\t\t\tfor (int u\
    \ : graph[v]) {\n\t\t\t\tif (u != heavy_vertex && u != p) {\n\t\t\t\t\trec(u,\
    \ v, u);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tout_index[v] = k;\n\t}\n\npublic:\n\t\
    HLD(int _n) : n(_n), graph(_n) {}\n\tHLD(const std::vector<std::vector<int>>&\
    \ _graph) : n(_graph.size()), graph(_graph) {}\n\tvoid add_edge(int u, int v)\
    \ {\n\t\tgraph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\t\tbuilded = false;\n\
    \t}\n\tvoid build(int root) {\n\t\tparent.assign(n, -1);\n\t\tsize.assign(n, 0);\n\
    \t\tcalc_size(root, -1, 1);\n\t\tk = 0;\n\t\thead.assign(n, 0);\n\t\thld.assign(n,\
    \ 0);\n\t\tindex.assign(n, 0);\n\t\tout_index.assign(n, 0);\n\t\trec(root, -1,\
    \ root);\n\t\tbuilded = true;\n\t}\n\tconst std::vector<std::vector<int>>& get_graph()\
    \ const {\n\t\tassert(builded);\n\t\treturn graph;\n\t}\n\tconst std::vector<int>&\
    \ get_parent() const {\n\t\tassert(builded);\n\t\treturn parent;\n\t}\n\tconst\
    \ std::vector<int>& get_size() const {\n\t\tassert(builded);\n\t\treturn size;\n\
    \t}\n\tconst std::vector<int>& get_head() const {\n\t\tassert(builded);\n\t\t\
    return head;\n\t}\n\tconst std::vector<int>& get_hld() const {\n\t\tassert(builded);\n\
    \t\treturn hld;\n\t}\n\tconst std::vector<int>& get_index() const {\n\t\tassert(builded);\n\
    \t\treturn index;\n\t}\n\tconst std::vector<int>& get_out_index() const {\n\t\t\
    assert(builded);\n\t\treturn out_index;\n\t}\n\tint operator[](int v) const {\n\
    \t\tassert(builded);\n\t\treturn index[v];\n\t}\n\n\ttemplate <class F> void each_vertex(int\
    \ v, int u, F f) const {\n\t\tassert(builded);\n\t\twhile (true) {\n\t\t\tif (index[v]\
    \ > index[u]) std::swap(v, u);\n\t\t\tif (head[v] != head[u]) {\n\t\t\t\tf(index[head[u]],\
    \ index[u] + 1);\n\t\t\t\tu = parent[head[u]];\n\t\t\t} else {\n\t\t\t\tf(index[v],\
    \ index[u] + 1);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t}\n\ttemplate <class F> void\
    \ each_subtree_vertex(int v, F f) const {\n\t\tassert(builded);\n\t\tf(index[v],\
    \ out_index[v]);\n\t}\n\ttemplate <class F> void each_edge(int v, int u, F f)\
    \ const {\n\t\tassert(builded);\n\t\twhile (true) {\n\t\t\tif (index[v] > index[u])\
    \ std::swap(v, u);\n\t\t\tif (head[v] != head[u]) {\n\t\t\t\tf(index[head[u]],\
    \ index[u] + 1);\n\t\t\t\tu = parent[head[u]];\n\t\t\t} else {\n\t\t\t\tif (v\
    \ != u) f(index[v] + 1, index[u] + 1);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t}\n\t\
    template <class F> void each_subtree_edge(int v, F f) const {\n\t\tassert(builded);\n\
    \t\tf(index[v] + 1, out_index[v]);\n\t}\n\tstd::vector<std::pair<int, int>> query_vertex(int\
    \ u, int v) const {\n\t\tassert(builded);\n\t\tstd::vector<std::pair<int, int>>\
    \ result;\n\t\teach_vertex(u, v, [&](int a, int b) { result.emplace_back(a, b);\
    \ });\n\t\treturn result;\n\t}\n\tstd::pair<int, int> query_subtree_vertex(int\
    \ v) const {\n\t\tassert(builded);\n\t\tstd::pair<int, int> result;\n\t\teach_subtree_vertex(v,\
    \ [&](int a, int b) { result = {a, b}; });\n\t\treturn result;\n\t}\n\tstd::vector<std::pair<int,\
    \ int>> query_edge(int u, int v) const {\n\t\tassert(builded);\n\t\tstd::vector<std::pair<int,\
    \ int>> result;\n\t\teach_edge(u, v, [&](int a, int b) { result.emplace_back(a,\
    \ b); });\n\t\treturn result;\n\t}\n\tstd::pair<int, int> query_subtree_edge(int\
    \ v) const {\n\t\tassert(builded);\n\t\tstd::pair<int, int> result;\n\t\teach_subtree_edge(v,\
    \ [&](int a, int b) { result = {a, b}; });\n\t\treturn result;\n\t}\n\tint lca(int\
    \ u, int v) const {\n\t\twhile (true) {\n\t\t\tif (index[u] > index[v]) std::swap(u,\
    \ v);\n\t\t\tif (head[u] != head[v]) {\n\t\t\t\tv = parent[head[v]];\n\t\t\t}\
    \ else {\n\t\t\t\treturn u;\n\t\t\t}\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nclass HLD {\n\tint\
    \ n;\n\tstd::vector<std::vector<int>> graph;\n\tstd::vector<int> parent, size;\n\
    \tint k;\n\tstd::vector<int> head, hld, index, out_index;\n\tbool builded = false;\n\
    \n\tint calc_size(int v, int p, int d) {\n\t\tparent[v] = p;\n\t\tsize[v] = 1;\n\
    \t\tfor (int u : graph[v]) {\n\t\t\tif (u != p) {\n\t\t\t\tsize[v] += calc_size(u,\
    \ v, d + 1);\n\t\t\t}\n\t\t}\n\t\treturn size[v];\n\t}\n\tvoid rec(int v, int\
    \ p, int root) {\n\t\thead[v] = root;\n\t\tindex[v] = k;\n\t\thld[k++] = v;\n\n\
    \t\tint heavy_vertex = -1, max_size = 0;\n\t\tfor (int u : graph[v]) {\n\t\t\t\
    if (u != p && max_size < size[u]) {\n\t\t\t\tmax_size = size[u];\n\t\t\t\theavy_vertex\
    \ = u;\n\t\t\t}\n\t\t}\n\t\tif (heavy_vertex != -1) {\n\t\t\trec(heavy_vertex,\
    \ v, root);\n\t\t\tfor (int u : graph[v]) {\n\t\t\t\tif (u != heavy_vertex &&\
    \ u != p) {\n\t\t\t\t\trec(u, v, u);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tout_index[v]\
    \ = k;\n\t}\n\npublic:\n\tHLD(int _n) : n(_n), graph(_n) {}\n\tHLD(const std::vector<std::vector<int>>&\
    \ _graph) : n(_graph.size()), graph(_graph) {}\n\tvoid add_edge(int u, int v)\
    \ {\n\t\tgraph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\t\tbuilded = false;\n\
    \t}\n\tvoid build(int root) {\n\t\tparent.assign(n, -1);\n\t\tsize.assign(n, 0);\n\
    \t\tcalc_size(root, -1, 1);\n\t\tk = 0;\n\t\thead.assign(n, 0);\n\t\thld.assign(n,\
    \ 0);\n\t\tindex.assign(n, 0);\n\t\tout_index.assign(n, 0);\n\t\trec(root, -1,\
    \ root);\n\t\tbuilded = true;\n\t}\n\tconst std::vector<std::vector<int>>& get_graph()\
    \ const {\n\t\tassert(builded);\n\t\treturn graph;\n\t}\n\tconst std::vector<int>&\
    \ get_parent() const {\n\t\tassert(builded);\n\t\treturn parent;\n\t}\n\tconst\
    \ std::vector<int>& get_size() const {\n\t\tassert(builded);\n\t\treturn size;\n\
    \t}\n\tconst std::vector<int>& get_head() const {\n\t\tassert(builded);\n\t\t\
    return head;\n\t}\n\tconst std::vector<int>& get_hld() const {\n\t\tassert(builded);\n\
    \t\treturn hld;\n\t}\n\tconst std::vector<int>& get_index() const {\n\t\tassert(builded);\n\
    \t\treturn index;\n\t}\n\tconst std::vector<int>& get_out_index() const {\n\t\t\
    assert(builded);\n\t\treturn out_index;\n\t}\n\tint operator[](int v) const {\n\
    \t\tassert(builded);\n\t\treturn index[v];\n\t}\n\n\ttemplate <class F> void each_vertex(int\
    \ v, int u, F f) const {\n\t\tassert(builded);\n\t\twhile (true) {\n\t\t\tif (index[v]\
    \ > index[u]) std::swap(v, u);\n\t\t\tif (head[v] != head[u]) {\n\t\t\t\tf(index[head[u]],\
    \ index[u] + 1);\n\t\t\t\tu = parent[head[u]];\n\t\t\t} else {\n\t\t\t\tf(index[v],\
    \ index[u] + 1);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t}\n\ttemplate <class F> void\
    \ each_subtree_vertex(int v, F f) const {\n\t\tassert(builded);\n\t\tf(index[v],\
    \ out_index[v]);\n\t}\n\ttemplate <class F> void each_edge(int v, int u, F f)\
    \ const {\n\t\tassert(builded);\n\t\twhile (true) {\n\t\t\tif (index[v] > index[u])\
    \ std::swap(v, u);\n\t\t\tif (head[v] != head[u]) {\n\t\t\t\tf(index[head[u]],\
    \ index[u] + 1);\n\t\t\t\tu = parent[head[u]];\n\t\t\t} else {\n\t\t\t\tif (v\
    \ != u) f(index[v] + 1, index[u] + 1);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t}\n\t\
    template <class F> void each_subtree_edge(int v, F f) const {\n\t\tassert(builded);\n\
    \t\tf(index[v] + 1, out_index[v]);\n\t}\n\tstd::vector<std::pair<int, int>> query_vertex(int\
    \ u, int v) const {\n\t\tassert(builded);\n\t\tstd::vector<std::pair<int, int>>\
    \ result;\n\t\teach_vertex(u, v, [&](int a, int b) { result.emplace_back(a, b);\
    \ });\n\t\treturn result;\n\t}\n\tstd::pair<int, int> query_subtree_vertex(int\
    \ v) const {\n\t\tassert(builded);\n\t\tstd::pair<int, int> result;\n\t\teach_subtree_vertex(v,\
    \ [&](int a, int b) { result = {a, b}; });\n\t\treturn result;\n\t}\n\tstd::vector<std::pair<int,\
    \ int>> query_edge(int u, int v) const {\n\t\tassert(builded);\n\t\tstd::vector<std::pair<int,\
    \ int>> result;\n\t\teach_edge(u, v, [&](int a, int b) { result.emplace_back(a,\
    \ b); });\n\t\treturn result;\n\t}\n\tstd::pair<int, int> query_subtree_edge(int\
    \ v) const {\n\t\tassert(builded);\n\t\tstd::pair<int, int> result;\n\t\teach_subtree_edge(v,\
    \ [&](int a, int b) { result = {a, b}; });\n\t\treturn result;\n\t}\n\tint lca(int\
    \ u, int v) const {\n\t\twhile (true) {\n\t\t\tif (index[u] > index[v]) std::swap(u,\
    \ v);\n\t\t\tif (head[u] != head[v]) {\n\t\t\t\tv = parent[head[v]];\n\t\t\t}\
    \ else {\n\t\t\t\treturn u;\n\t\t\t}\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/HeavyLightDecomposition.cpp
  requiredBy: []
  timestamp: '2021-03-21 11:17:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/HLD_vertex.test.cpp
  - test/HLD_subtree_edge.test.cpp
  - test/HLD_edge.test.cpp
  - test/HLD_LCA.test.cpp
documentation_of: Graph/HeavyLightDecomposition.cpp
layout: document
redirect_from:
- /library/Graph/HeavyLightDecomposition.cpp
- /library/Graph/HeavyLightDecomposition.cpp.html
title: Graph/HeavyLightDecomposition.cpp
---
