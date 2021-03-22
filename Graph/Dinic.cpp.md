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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/FlowTemplate.cpp\"\n#include <vector>\n#include <iostream>\n\
    #include <limits>\n\nusing FLOW = long long;\nconstexpr FLOW INF_FLOW = std::numeric_limits<FLOW>::max();\n\
    struct EdgeF {\n\tint to, rev;\n\tFLOW cap;\n\tEdgeF() : to(-1), rev(-1), cap(-1)\
    \ {}\n\tEdgeF(int t, int r, FLOW c) : to(t), rev(r), cap(c) {}\n\tfriend std::ostream&\
    \ operator<<(std::ostream& os, const EdgeF& e) {\n\t\treturn os << \"->\" << e.to\
    \ << \"(\" << e.cap << \")\";\n\t}\n};\nusing GraphF = std::vector<std::vector<EdgeF>>;\n\
    #line 4 \"Graph/Dinic.cpp\"\n#include <algorithm>\n#include <queue>\n#include\
    \ <cassert>\n\nclass Dinic {\n\tint n;\n\tGraphF graph;\n\tstd::vector<int> level,\
    \ iter;\n\tvoid bfs(int s) {\n\t\tstd::fill(level.begin(), level.end(), -1);\n\
    \t\tlevel[s] = 0;\n\t\tstd::queue<int> q;\n\t\tq.push(s);\n\t\twhile (!q.empty())\
    \ {\n\t\t\tint v = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto& e : graph[v])\
    \ {\n\t\t\t\tif (e.cap > 0 && level[e.to] < 0) {\n\t\t\t\t\tlevel[e.to] = level[v]\
    \ + 1;\n\t\t\t\t\tq.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tFLOW dfs(int\
    \ v, int t, FLOW f) {\n\t\tif (v == t) return f;\n\t\tfor (int i = iter[v]; i\
    \ < graph[v].size(); ++i) {\n\t\t\tauto& e = graph[v][i];\n\t\t\tif (e.cap > 0\
    \ && level[v] < level[e.to]) {\n\t\t\t\tFLOW d = dfs(e.to, t, std::min(f, e.cap));\n\
    \t\t\t\tif (d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tgraph[e.to][e.rev].cap\
    \ += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\
    public:\n\tDinic(std::size_t _n) : n(_n), graph(n), level(n), iter(n) {}\n\tconst\
    \ GraphF& get_graph() {\n\t\treturn graph;\n\t}\n\tvoid add_edge(int from, int\
    \ to, FLOW cap) {\n\t\tassert(0 <= from && from < n);\n\t\tassert(0 <= to && to\
    \ < n);\n\t\tgraph[from].emplace_back(to, graph[to].size(), cap);\n\t\tgraph[to].emplace_back(from,\
    \ graph[from].size() - 1, 0);\n\t}\n\tFLOW solve(int s, int t) {\n\t\tFLOW result\
    \ = 0;\n\t\twhile (true) {\n\t\t\tbfs(s);\n\t\t\tif (level[t] < 0) return result;\n\
    \t\t\tstd::fill(iter.begin(), iter.end(), 0);\n\t\t\tFLOW f;\n\t\t\twhile ((f\
    \ = dfs(s, t, INF_FLOW)) > 0) result += f;\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n#include \"./FlowTemplate.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <queue>\n#include <cassert>\n\nclass Dinic {\n\tint n;\n\
    \tGraphF graph;\n\tstd::vector<int> level, iter;\n\tvoid bfs(int s) {\n\t\tstd::fill(level.begin(),\
    \ level.end(), -1);\n\t\tlevel[s] = 0;\n\t\tstd::queue<int> q;\n\t\tq.push(s);\n\
    \t\twhile (!q.empty()) {\n\t\t\tint v = q.front();\n\t\t\tq.pop();\n\t\t\tfor\
    \ (auto& e : graph[v]) {\n\t\t\t\tif (e.cap > 0 && level[e.to] < 0) {\n\t\t\t\t\
    \tlevel[e.to] = level[v] + 1;\n\t\t\t\t\tq.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\
    \t}\n\t}\n\tFLOW dfs(int v, int t, FLOW f) {\n\t\tif (v == t) return f;\n\t\t\
    for (int i = iter[v]; i < graph[v].size(); ++i) {\n\t\t\tauto& e = graph[v][i];\n\
    \t\t\tif (e.cap > 0 && level[v] < level[e.to]) {\n\t\t\t\tFLOW d = dfs(e.to, t,\
    \ std::min(f, e.cap));\n\t\t\t\tif (d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\t\
    graph[e.to][e.rev].cap += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t\treturn 0;\n\t}\n\npublic:\n\tDinic(std::size_t _n) : n(_n), graph(n), level(n),\
    \ iter(n) {}\n\tconst GraphF& get_graph() {\n\t\treturn graph;\n\t}\n\tvoid add_edge(int\
    \ from, int to, FLOW cap) {\n\t\tassert(0 <= from && from < n);\n\t\tassert(0\
    \ <= to && to < n);\n\t\tgraph[from].emplace_back(to, graph[to].size(), cap);\n\
    \t\tgraph[to].emplace_back(from, graph[from].size() - 1, 0);\n\t}\n\tFLOW solve(int\
    \ s, int t) {\n\t\tFLOW result = 0;\n\t\twhile (true) {\n\t\t\tbfs(s);\n\t\t\t\
    if (level[t] < 0) return result;\n\t\t\tstd::fill(iter.begin(), iter.end(), 0);\n\
    \t\t\tFLOW f;\n\t\t\twhile ((f = dfs(s, t, INF_FLOW)) > 0) result += f;\n\t\t\
    }\n\t}\n};\n"
  dependsOn:
  - Graph/FlowTemplate.cpp
  isVerificationFile: false
  path: Graph/Dinic.cpp
  requiredBy: []
  timestamp: '2021-03-22 17:27:46+09:00'
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
