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
  bundledCode: "#line 2 \"Graph/EulerTourForVertex.cpp\"\n#include <vector>\nusing\
    \ namespace std;\n\nclass EulerTourForVertex {\n\tvector<int> ls_m, rs_m;\n\t\
    vector<vector<int>> graph;\n\tint k = 0;\n\tvoid dfs(int v, int p) {\n\t\tls_m[v]\
    \ = k++;\n\t\tfor (int u : graph[v]) {\n\t\t\tif (u != p) dfs(u, v);\n\t\t}\n\t\
    \trs_m[v] = k;\n\t}\n\npublic:\n\tEulerTourForVertex() {}\n\tEulerTourForVertex(int\
    \ n) : ls_m(n), rs_m(n), graph(n) {}\n\tEulerTourForVertex(const vector<vector<int>>&\
    \ _graph)\n\t    : ls_m(_graph.size()), rs_m(_graph.size()), graph(_graph) {}\n\
    \tvoid add_edge(int u, int v) {\n\t\tgraph[u].emplace_back(v);\n\t\tgraph[v].emplace_back(u);\n\
    \t}\n\tvoid build(int root) {\n\t\tk = 0;\n\t\tdfs(root, -1);\n\t}\n\tint l(int\
    \ v) const {\n\t\treturn ls_m[v];\n\t}\n\tint r(int v) const {\n\t\treturn rs_m[v];\n\
    \t}\n\tpair<int, int> get(int v) const {\n\t\treturn {ls_m[v], rs_m[v]};\n\t}\n\
    \tconst vector<int>& ls() const {\n\t\treturn ls_m;\n\t}\n\tconst vector<int>&\
    \ rs() const {\n\t\treturn rs_m;\n\t}\n\ttemplate <typename F> void call(int v,\
    \ F f) {\n\t\tf(ls_m[v], rs_m[v]);\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\nclass EulerTourForVertex\
    \ {\n\tvector<int> ls_m, rs_m;\n\tvector<vector<int>> graph;\n\tint k = 0;\n\t\
    void dfs(int v, int p) {\n\t\tls_m[v] = k++;\n\t\tfor (int u : graph[v]) {\n\t\
    \t\tif (u != p) dfs(u, v);\n\t\t}\n\t\trs_m[v] = k;\n\t}\n\npublic:\n\tEulerTourForVertex()\
    \ {}\n\tEulerTourForVertex(int n) : ls_m(n), rs_m(n), graph(n) {}\n\tEulerTourForVertex(const\
    \ vector<vector<int>>& _graph)\n\t    : ls_m(_graph.size()), rs_m(_graph.size()),\
    \ graph(_graph) {}\n\tvoid add_edge(int u, int v) {\n\t\tgraph[u].emplace_back(v);\n\
    \t\tgraph[v].emplace_back(u);\n\t}\n\tvoid build(int root) {\n\t\tk = 0;\n\t\t\
    dfs(root, -1);\n\t}\n\tint l(int v) const {\n\t\treturn ls_m[v];\n\t}\n\tint r(int\
    \ v) const {\n\t\treturn rs_m[v];\n\t}\n\tpair<int, int> get(int v) const {\n\t\
    \treturn {ls_m[v], rs_m[v]};\n\t}\n\tconst vector<int>& ls() const {\n\t\treturn\
    \ ls_m;\n\t}\n\tconst vector<int>& rs() const {\n\t\treturn rs_m;\n\t}\n\ttemplate\
    \ <typename F> void call(int v, F f) {\n\t\tf(ls_m[v], rs_m[v]);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/EulerTourForVertex.cpp
  requiredBy: []
  timestamp: '2021-01-20 17:22:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/EulerTourForVertex.cpp
layout: document
redirect_from:
- /library/Graph/EulerTourForVertex.cpp
- /library/Graph/EulerTourForVertex.cpp.html
title: Graph/EulerTourForVertex.cpp
---
