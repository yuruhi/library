---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/EulerTourForVertex.cpp\"\n#include <vector>\nusing\
    \ namespace std;\n\nclass EulerTourForVertex {\n\tvector<int> ls, rs;\n\tvector<vector<int>>\
    \ graph;\n\tint k = 0;\n\tvoid dfs(int v, int p) {\n\t\tls[v] = k++;\n\t\tfor\
    \ (int u : graph[v]) {\n\t\t\tif (u != p) dfs(u, v);\n\t\t}\n\t\trs[v] = k;\n\t\
    }\n\npublic:\n\tEulerTourForVertex() {}\n\tEulerTourForVertex(int n) : ls(n),\
    \ rs(n), graph(n) {}\n\tvoid add_edge(int u, int v) {\n\t\tgraph[u].emplace_back(v);\n\
    \t\tgraph[v].emplace_back(u);\n\t}\n\tvoid build(int root) {\n\t\tk = 0;\n\t\t\
    dfs(root, -1);\n\t}\n\tint get_l(int v) const {\n\t\treturn ls[v];\n\t}\n\tint\
    \ get_r(int v) const {\n\t\treturn rs[v];\n\t}\n\tpair<int, int> get(int v) const\
    \ {\n\t\treturn {ls[v], rs[v]};\n\t}\n\tconst vector<int>& get_ls() const {\n\t\
    \treturn ls;\n\t}\n\tconst vector<int>& get_rs() const {\n\t\treturn rs;\n\t}\n\
    \ttemplate <typename F> void call(int v, F f) {\n\t\tf(ls[v], rs[v]);\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\nclass EulerTourForVertex\
    \ {\n\tvector<int> ls, rs;\n\tvector<vector<int>> graph;\n\tint k = 0;\n\tvoid\
    \ dfs(int v, int p) {\n\t\tls[v] = k++;\n\t\tfor (int u : graph[v]) {\n\t\t\t\
    if (u != p) dfs(u, v);\n\t\t}\n\t\trs[v] = k;\n\t}\n\npublic:\n\tEulerTourForVertex()\
    \ {}\n\tEulerTourForVertex(int n) : ls(n), rs(n), graph(n) {}\n\tvoid add_edge(int\
    \ u, int v) {\n\t\tgraph[u].emplace_back(v);\n\t\tgraph[v].emplace_back(u);\n\t\
    }\n\tvoid build(int root) {\n\t\tk = 0;\n\t\tdfs(root, -1);\n\t}\n\tint get_l(int\
    \ v) const {\n\t\treturn ls[v];\n\t}\n\tint get_r(int v) const {\n\t\treturn rs[v];\n\
    \t}\n\tpair<int, int> get(int v) const {\n\t\treturn {ls[v], rs[v]};\n\t}\n\t\
    const vector<int>& get_ls() const {\n\t\treturn ls;\n\t}\n\tconst vector<int>&\
    \ get_rs() const {\n\t\treturn rs;\n\t}\n\ttemplate <typename F> void call(int\
    \ v, F f) {\n\t\tf(ls[v], rs[v]);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/EulerTourForVertex.cpp
  requiredBy: []
  timestamp: '2021-01-17 16:23:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/EulerTourForVertex.cpp
layout: document
redirect_from:
- /library/Graph/EulerTourForVertex.cpp
- /library/Graph/EulerTourForVertex.cpp.html
title: Graph/EulerTourForVertex.cpp
---
