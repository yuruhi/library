---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/FlowTemplate.cpp
    title: Graph/FlowTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Dinic.test.cpp
    title: test/Dinic.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/FlowTemplate.cpp\"\n#include <vector>\n#include <limits>\n\
    using namespace std;\n\nusing FLOW = long long;\nconstexpr FLOW INF_FLOW = numeric_limits<FLOW>::max();\n\
    struct EdgeF {\n\tint to, rev;\n\tFLOW cap;\n\tEdgeF() : to(-1), rev(-1), cap(-1)\
    \ {}\n\tEdgeF(int t, int r, FLOW c) : to(t), rev(r), cap(c) {}\n};\nusing GraphF\
    \ = vector<vector<EdgeF>>;\n#line 4 \"Graph/Dinic.cpp\"\n#include <algorithm>\n\
    #include <queue>\nusing namespace std;\n\nclass Dinic {\n\tint V;\n\tGraphF G;\n\
    \tvector<int> level, iter;\n\tvoid bfs(int s) {\n\t\tfill(level.begin(), level.end(),\
    \ -1);\n\t\tlevel[s] = 0;\n\t\tqueue<int> q;\n\t\tq.push(s);\n\t\twhile (!q.empty())\
    \ {\n\t\t\tint v = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto& e : G[v]) {\n\t\
    \t\t\tif (e.cap > 0 && level[e.to] < 0) {\n\t\t\t\t\tlevel[e.to] = level[v] +\
    \ 1;\n\t\t\t\t\tq.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tFLOW dfs(int\
    \ v, int t, FLOW f) {\n\t\tif (v == t) return f;\n\t\tfor (int i = iter[v]; i\
    \ < G[v].size(); ++i) {\n\t\t\tauto& e = G[v][i];\n\t\t\tif (e.cap > 0 && level[v]\
    \ < level[e.to]) {\n\t\t\t\tFLOW d = dfs(e.to, t, min(f, e.cap));\n\t\t\t\tif\
    \ (d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tG[e.to][e.rev].cap += d;\n\t\t\t\
    \t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\npublic:\n\tDinic(int\
    \ v) : V(v), G(v), level(v), iter(v) {}\n\tconst GraphF& get_G() {\n\t\treturn\
    \ G;\n\t}\n\tvoid add_edge(int from, int to, FLOW cap) {\n\t\tG[from].emplace_back(to,\
    \ G[to].size(), cap);\n\t\tG[to].emplace_back(from, G[from].size() - 1, 0);\n\t\
    }\n\tFLOW solve(int s, int t) {\n\t\tFLOW res = 0;\n\t\twhile (true) {\n\t\t\t\
    bfs(s);\n\t\t\tif (level[t] < 0) return res;\n\t\t\tfill(iter.begin(), iter.end(),\
    \ 0);\n\t\t\tFLOW f;\n\t\t\twhile ((f = dfs(s, t, INF_FLOW)) > 0)\n\t\t\t\tres\
    \ += f;\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n#include \"./FlowTemplate.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <queue>\nusing namespace std;\n\nclass Dinic {\n\tint\
    \ V;\n\tGraphF G;\n\tvector<int> level, iter;\n\tvoid bfs(int s) {\n\t\tfill(level.begin(),\
    \ level.end(), -1);\n\t\tlevel[s] = 0;\n\t\tqueue<int> q;\n\t\tq.push(s);\n\t\t\
    while (!q.empty()) {\n\t\t\tint v = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto&\
    \ e : G[v]) {\n\t\t\t\tif (e.cap > 0 && level[e.to] < 0) {\n\t\t\t\t\tlevel[e.to]\
    \ = level[v] + 1;\n\t\t\t\t\tq.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\t\
    FLOW dfs(int v, int t, FLOW f) {\n\t\tif (v == t) return f;\n\t\tfor (int i =\
    \ iter[v]; i < G[v].size(); ++i) {\n\t\t\tauto& e = G[v][i];\n\t\t\tif (e.cap\
    \ > 0 && level[v] < level[e.to]) {\n\t\t\t\tFLOW d = dfs(e.to, t, min(f, e.cap));\n\
    \t\t\t\tif (d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tG[e.to][e.rev].cap += d;\n\
    \t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\npublic:\n\
    \tDinic(int v) : V(v), G(v), level(v), iter(v) {}\n\tconst GraphF& get_G() {\n\
    \t\treturn G;\n\t}\n\tvoid add_edge(int from, int to, FLOW cap) {\n\t\tG[from].emplace_back(to,\
    \ G[to].size(), cap);\n\t\tG[to].emplace_back(from, G[from].size() - 1, 0);\n\t\
    }\n\tFLOW solve(int s, int t) {\n\t\tFLOW res = 0;\n\t\twhile (true) {\n\t\t\t\
    bfs(s);\n\t\t\tif (level[t] < 0) return res;\n\t\t\tfill(iter.begin(), iter.end(),\
    \ 0);\n\t\t\tFLOW f;\n\t\t\twhile ((f = dfs(s, t, INF_FLOW)) > 0)\n\t\t\t\tres\
    \ += f;\n\t\t}\n\t}\n};"
  dependsOn:
  - Graph/FlowTemplate.cpp
  isVerificationFile: false
  path: Graph/Dinic.cpp
  requiredBy: []
  timestamp: '2020-10-04 14:21:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Dinic.test.cpp
documentation_of: Graph/Dinic.cpp
layout: document
redirect_from:
- /library/Graph/Dinic.cpp
- /library/Graph/Dinic.cpp.html
title: Graph/Dinic.cpp
---
