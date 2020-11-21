---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/FlowTemplate.cpp
    title: Graph/FlowTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FordFulkerson.test.cpp
    title: test/FordFulkerson.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/FlowTemplate.cpp\"\n#include <vector>\n#include <limits>\n\
    using namespace std;\n\nusing FLOW = long long;\nconstexpr FLOW INF_FLOW = numeric_limits<FLOW>::max();\n\
    struct EdgeF {\n\tint to, rev;\n\tFLOW cap;\n\tEdgeF() : to(-1), rev(-1), cap(-1)\
    \ {}\n\tEdgeF(int t, int r, FLOW c) : to(t), rev(r), cap(c) {}\n};\nusing GraphF\
    \ = vector<vector<EdgeF>>;\n#line 4 \"Graph/FordFulkerson.cpp\"\nusing namespace\
    \ std;\n\nclass FordFulkerson {\n\tint n;\n\tGraphF graph;\n\tvector<bool> used;\n\
    \tFLOW dfs(int v, int t, FLOW f) {\n\t\tif (v == t) return f;\n\t\tused[v] = true;\n\
    \t\tfor (auto& e : graph[v]) {\n\t\t\tif (!used[e.to] && e.cap > 0) {\n\t\t\t\t\
    FLOW d = dfs(e.to, t, min(f, e.cap));\n\t\t\t\tif (d > 0) {\n\t\t\t\t\te.cap -=\
    \ d;\n\t\t\t\t\tgraph[e.to][e.rev].cap += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\npublic:\n\tFordFulkerson(int _n) : n(_n),\
    \ graph(n), used(n) {}\n\tconst GraphF& get_G() {\n\t\treturn graph;\n\t}\n\t\
    void add_edge(int from, int to, FLOW cap) {\n\t\tgraph[from].emplace_back(to,\
    \ graph[to].size(), cap);\n\t\tgraph[to].emplace_back(from, graph[from].size()\
    \ - 1, 0);\n\t}\n\tFLOW solve(int s, int t) {\n\t\tFLOW res = 0;\n\t\twhile (true)\
    \ {\n\t\t\tfill(used.begin(), used.end(), false);\n\t\t\tFLOW f = dfs(s, t, INF_FLOW);\n\
    \t\t\tif (!f) return res;\n\t\t\tres += f;\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n#include \"./FlowTemplate.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nclass FordFulkerson {\n\tint n;\n\tGraphF graph;\n\tvector<bool> used;\n\
    \tFLOW dfs(int v, int t, FLOW f) {\n\t\tif (v == t) return f;\n\t\tused[v] = true;\n\
    \t\tfor (auto& e : graph[v]) {\n\t\t\tif (!used[e.to] && e.cap > 0) {\n\t\t\t\t\
    FLOW d = dfs(e.to, t, min(f, e.cap));\n\t\t\t\tif (d > 0) {\n\t\t\t\t\te.cap -=\
    \ d;\n\t\t\t\t\tgraph[e.to][e.rev].cap += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\npublic:\n\tFordFulkerson(int _n) : n(_n),\
    \ graph(n), used(n) {}\n\tconst GraphF& get_G() {\n\t\treturn graph;\n\t}\n\t\
    void add_edge(int from, int to, FLOW cap) {\n\t\tgraph[from].emplace_back(to,\
    \ graph[to].size(), cap);\n\t\tgraph[to].emplace_back(from, graph[from].size()\
    \ - 1, 0);\n\t}\n\tFLOW solve(int s, int t) {\n\t\tFLOW res = 0;\n\t\twhile (true)\
    \ {\n\t\t\tfill(used.begin(), used.end(), false);\n\t\t\tFLOW f = dfs(s, t, INF_FLOW);\n\
    \t\t\tif (!f) return res;\n\t\t\tres += f;\n\t\t}\n\t}\n};\n"
  dependsOn:
  - Graph/FlowTemplate.cpp
  isVerificationFile: false
  path: Graph/FordFulkerson.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FordFulkerson.test.cpp
documentation_of: Graph/FordFulkerson.cpp
layout: document
redirect_from:
- /library/Graph/FordFulkerson.cpp
- /library/Graph/FordFulkerson.cpp.html
title: Graph/FordFulkerson.cpp
---
