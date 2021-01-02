---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/HLD_edge.test.cpp
    title: test/HLD_edge.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/HLD_vertex.test.cpp
    title: test/HLD_vertex.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/HeavyLightDecomposition.cpp\"\n#include <vector>\n\
    #include <cassert>\nusing namespace std;\n\nclass HLD {\n\tint n;\n\tvector<vector<int>>\
    \ graph;\n\tvector<int> parent, size, depth;\n\tint k;\n\tvector<int> head, hld,\
    \ index;\n\tbool builded = false;\n\n\tint calc_size(int v, int p, int d) {\n\t\
    \tparent[v] = p;\n\t\tsize[v] = 1;\n\t\tdepth[v] = 1;\n\t\tfor (int u : graph[v])\
    \ {\n\t\t\tif (u != p) {\n\t\t\t\tsize[v] += calc_size(u, v, d + 1);\n\t\t\t}\n\
    \t\t}\n\t\treturn size[v];\n\t}\n\tvoid rec(int v, int p, int root) {\n\t\thead[v]\
    \ = root;\n\t\tindex[v] = k;\n\t\thld[k++] = v;\n\n\t\tint heavy_vertex = -1,\
    \ max_size = 0;\n\t\tfor (int u : graph[v]) {\n\t\t\tif (u != p && max_size <\
    \ size[u]) {\n\t\t\t\tmax_size = size[u];\n\t\t\t\theavy_vertex = u;\n\t\t\t}\n\
    \t\t}\n\t\tif (heavy_vertex == -1) return;\n\t\trec(heavy_vertex, v, root);\n\t\
    \tfor (int u : graph[v]) {\n\t\t\tif (u != heavy_vertex && u != p) {\n\t\t\t\t\
    rec(u, v, u);\n\t\t\t}\n\t\t}\n\t}\n\npublic:\n\tHLD(int _n) : n(_n), graph(_n)\
    \ {}\n\tHLD(const vector<vector<int>>& _graph) : n(_graph.size()), graph(_graph)\
    \ {}\n\tvoid add_edge(int u, int v) {\n\t\tgraph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\
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
    \ b); });\n\t\treturn result;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\nusing namespace std;\n\
    \nclass HLD {\n\tint n;\n\tvector<vector<int>> graph;\n\tvector<int> parent, size,\
    \ depth;\n\tint k;\n\tvector<int> head, hld, index;\n\tbool builded = false;\n\
    \n\tint calc_size(int v, int p, int d) {\n\t\tparent[v] = p;\n\t\tsize[v] = 1;\n\
    \t\tdepth[v] = 1;\n\t\tfor (int u : graph[v]) {\n\t\t\tif (u != p) {\n\t\t\t\t\
    size[v] += calc_size(u, v, d + 1);\n\t\t\t}\n\t\t}\n\t\treturn size[v];\n\t}\n\
    \tvoid rec(int v, int p, int root) {\n\t\thead[v] = root;\n\t\tindex[v] = k;\n\
    \t\thld[k++] = v;\n\n\t\tint heavy_vertex = -1, max_size = 0;\n\t\tfor (int u\
    \ : graph[v]) {\n\t\t\tif (u != p && max_size < size[u]) {\n\t\t\t\tmax_size =\
    \ size[u];\n\t\t\t\theavy_vertex = u;\n\t\t\t}\n\t\t}\n\t\tif (heavy_vertex ==\
    \ -1) return;\n\t\trec(heavy_vertex, v, root);\n\t\tfor (int u : graph[v]) {\n\
    \t\t\tif (u != heavy_vertex && u != p) {\n\t\t\t\trec(u, v, u);\n\t\t\t}\n\t\t\
    }\n\t}\n\npublic:\n\tHLD(int _n) : n(_n), graph(_n) {}\n\tHLD(const vector<vector<int>>&\
    \ _graph) : n(_graph.size()), graph(_graph) {}\n\tvoid add_edge(int u, int v)\
    \ {\n\t\tgraph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\t\tbuilded = false;\n\
    \t}\n\tvoid build(int root) {\n\t\tparent.assign(n, -1);\n\t\tsize.assign(n, 0);\n\
    \t\tdepth.assign(n, 0);\n\t\tcalc_size(root, -1, 1);\n\t\tk = 0;\n\t\thead.assign(n,\
    \ 0);\n\t\thld.assign(n, 0);\n\t\tindex.assign(n, 0);\n\t\trec(root, -1, root);\n\
    \t\tbuilded = true;\n\t}\n\tconst vector<int>& get_head() const {\n\t\tassert(builded);\n\
    \t\treturn head;\n\t}\n\tconst vector<int>& get_hld() const {\n\t\tassert(builded);\n\
    \t\treturn hld;\n\t}\n\tconst vector<int>& get_index() const {\n\t\tassert(builded);\n\
    \t\treturn index;\n\t}\n\tint operator[](int v) const {\n\t\tassert(builded);\n\
    \t\treturn index[v];\n\t}\n\n\ttemplate <class F> void each_vertex(int v, int\
    \ u, F f) const {\n\t\tassert(builded);\n\t\twhile (true) {\n\t\t\tif (index[v]\
    \ > index[u]) swap(v, u);\n\t\t\tif (head[v] != head[u]) {\n\t\t\t\tf(index[head[u]],\
    \ index[u]);\n\t\t\t\tu = parent[head[u]];\n\t\t\t} else {\n\t\t\t\tf(index[v],\
    \ index[u]);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t}\n\ttemplate <class F> void each_edge(int\
    \ v, int u, F f) const {\n\t\tassert(builded);\n\t\twhile (true) {\n\t\t\tif (index[v]\
    \ > index[u]) swap(v, u);\n\t\t\tif (head[v] != head[u]) {\n\t\t\t\tf(index[head[u]],\
    \ index[u]);\n\t\t\t\tu = parent[head[u]];\n\t\t\t} else {\n\t\t\t\tif (v != u)\
    \ f(index[v] + 1, index[u]);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t}\n\tvector<pair<int,\
    \ int>> query_vertex(int u, int v) {\n\t\tassert(builded);\n\t\tvector<pair<int,\
    \ int>> result;\n\t\teach_vertex(u, v, [&](int a, int b) { result.emplace_back(a,\
    \ b); });\n\t\treturn result;\n\t}\n\tvector<pair<int, int>> query_edge(int u,\
    \ int v) {\n\t\tassert(builded);\n\t\tvector<pair<int, int>> result;\n\t\teach_edge(u,\
    \ v, [&](int a, int b) { result.emplace_back(a, b); });\n\t\treturn result;\n\t\
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/HeavyLightDecomposition.cpp
  requiredBy: []
  timestamp: '2020-12-23 14:02:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/HLD_vertex.test.cpp
  - test/HLD_edge.test.cpp
documentation_of: Graph/HeavyLightDecomposition.cpp
layout: document
redirect_from:
- /library/Graph/HeavyLightDecomposition.cpp
- /library/Graph/HeavyLightDecomposition.cpp.html
title: Graph/HeavyLightDecomposition.cpp
---
