---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/EulerTourForEdge.test.cpp
    title: test/EulerTourForEdge.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/EulerTourForEdge.cpp\"\n#include <vector>\n#include\
    \ <utility>\n#include <cassert>\n#include <functional>\nusing namespace std;\n\
    \nclass EulerTourForEdge {\n\tvector<vector<int>> graph;\n\tvector<int> ls, rs;\n\
    \tint pos = 0;\n\tbool flag = false;\n\tvoid dfs(int v, int p = -1) {\n\t\tls[v]\
    \ = pos++;\n\t\tfor (int u : graph[v])\n\t\t\tif (u != p) {\n\t\t\t\tdfs(u, v);\n\
    \t\t\t}\n\t\trs[v] = pos++;\n\t}\n\npublic:\n\tEulerTourForEdge(int n) : graph(n),\
    \ ls(n), rs(n) {}\n\tEulerTourForEdge(const vector<vector<int>>& _graph) : graph(_graph),\
    \ ls(graph.size()), rs(graph.size()) {}\n\tvoid add_edge(int u, int v) {\n\t\t\
    graph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\t}\n\tvoid build(int root\
    \ = 0) {\n\t\tflag = true;\n\t\tpos = 0;\n\t\tdfs(root);\n\t}\n\tint size() const\
    \ {\n\t\tassert(flag);\n\t\treturn pos;\n\t}\n\tint l(int i) const {\n\t\tassert(flag);\n\
    \t\treturn ls[i];\n\t}\n\tint r(int i) const {\n\t\tassert(flag);\n\t\treturn\
    \ rs[i];\n\t}\n\tpair<int, int> operator()(int i) {\n\t\tassert(flag);\n\t\treturn\
    \ make_pair(ls[i], rs[i]);\n\t}\n\tconst vector<int>& get_ls() const {\n\t\treturn\
    \ ls;\n\t}\n\tconst vector<int>& get_rs() const {\n\t\treturn rs;\n\t}\n\tint\
    \ operator[](int i) {\n\t\tassert(flag);\n\t\treturn ls[i];\n\t}\n\ttemplate <class\
    \ T> auto call(int v, function<T(int, int)>&& f) {\n\t\tassert(flag);\n\t\treturn\
    \ f(ls[v], rs[v]);\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <cassert>\n\
    #include <functional>\nusing namespace std;\n\nclass EulerTourForEdge {\n\tvector<vector<int>>\
    \ graph;\n\tvector<int> ls, rs;\n\tint pos = 0;\n\tbool flag = false;\n\tvoid\
    \ dfs(int v, int p = -1) {\n\t\tls[v] = pos++;\n\t\tfor (int u : graph[v])\n\t\
    \t\tif (u != p) {\n\t\t\t\tdfs(u, v);\n\t\t\t}\n\t\trs[v] = pos++;\n\t}\n\npublic:\n\
    \tEulerTourForEdge(int n) : graph(n), ls(n), rs(n) {}\n\tEulerTourForEdge(const\
    \ vector<vector<int>>& _graph) : graph(_graph), ls(graph.size()), rs(graph.size())\
    \ {}\n\tvoid add_edge(int u, int v) {\n\t\tgraph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\
    \t}\n\tvoid build(int root = 0) {\n\t\tflag = true;\n\t\tpos = 0;\n\t\tdfs(root);\n\
    \t}\n\tint size() const {\n\t\tassert(flag);\n\t\treturn pos;\n\t}\n\tint l(int\
    \ i) const {\n\t\tassert(flag);\n\t\treturn ls[i];\n\t}\n\tint r(int i) const\
    \ {\n\t\tassert(flag);\n\t\treturn rs[i];\n\t}\n\tpair<int, int> operator()(int\
    \ i) {\n\t\tassert(flag);\n\t\treturn make_pair(ls[i], rs[i]);\n\t}\n\tconst vector<int>&\
    \ get_ls() const {\n\t\treturn ls;\n\t}\n\tconst vector<int>& get_rs() const {\n\
    \t\treturn rs;\n\t}\n\tint operator[](int i) {\n\t\tassert(flag);\n\t\treturn\
    \ ls[i];\n\t}\n\ttemplate <class T> auto call(int v, function<T(int, int)>&& f)\
    \ {\n\t\tassert(flag);\n\t\treturn f(ls[v], rs[v]);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/EulerTourForEdge.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/EulerTourForEdge.test.cpp
documentation_of: Graph/EulerTourForEdge.cpp
layout: document
redirect_from:
- /library/Graph/EulerTourForEdge.cpp
- /library/Graph/EulerTourForEdge.cpp.html
title: Graph/EulerTourForEdge.cpp
---
