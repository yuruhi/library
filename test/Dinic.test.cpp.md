---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Dinic.cpp
    title: Graph/Dinic.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/FlowTemplate.cpp
    title: Graph/FlowTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
  bundledCode: "#line 1 \"test/Dinic.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\
    \n#line 2 \"Graph/FlowTemplate.cpp\"\n#include <vector>\n#include <limits>\nusing\
    \ namespace std;\n\nusing FLOW = long long;\nconstexpr FLOW INF_FLOW = numeric_limits<FLOW>::max();\n\
    struct EdgeF {\n\tint to, rev;\n\tFLOW cap;\n\tEdgeF() : to(-1), rev(-1), cap(-1)\
    \ {}\n\tEdgeF(int t, int r, FLOW c) : to(t), rev(r), cap(c) {}\n};\nusing GraphF\
    \ = vector<vector<EdgeF>>;\n#line 4 \"Graph/Dinic.cpp\"\n#include <algorithm>\n\
    #include <queue>\nusing namespace std;\n\nclass Dinic {\n\tint V;\n\tGraphF graph;\n\
    \tvector<int> level, iter;\n\tvoid bfs(int s) {\n\t\tfill(level.begin(), level.end(),\
    \ -1);\n\t\tlevel[s] = 0;\n\t\tqueue<int> q;\n\t\tq.push(s);\n\t\twhile (!q.empty())\
    \ {\n\t\t\tint v = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto& e : graph[v])\
    \ {\n\t\t\t\tif (e.cap > 0 && level[e.to] < 0) {\n\t\t\t\t\tlevel[e.to] = level[v]\
    \ + 1;\n\t\t\t\t\tq.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tFLOW dfs(int\
    \ v, int t, FLOW f) {\n\t\tif (v == t) return f;\n\t\tfor (int i = iter[v]; i\
    \ < graph[v].size(); ++i) {\n\t\t\tauto& e = graph[v][i];\n\t\t\tif (e.cap > 0\
    \ && level[v] < level[e.to]) {\n\t\t\t\tFLOW d = dfs(e.to, t, min(f, e.cap));\n\
    \t\t\t\tif (d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tgraph[e.to][e.rev].cap\
    \ += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\
    public:\n\tDinic(int v) : V(v), graph(v), level(v), iter(v) {}\n\tconst GraphF&\
    \ get_graph() {\n\t\treturn graph;\n\t}\n\tvoid add_edge(int from, int to, FLOW\
    \ cap) {\n\t\tgraph[from].emplace_back(to, graph[to].size(), cap);\n\t\tgraph[to].emplace_back(from,\
    \ graph[from].size() - 1, 0);\n\t}\n\tFLOW solve(int s, int t) {\n\t\tFLOW result\
    \ = 0;\n\t\twhile (true) {\n\t\t\tbfs(s);\n\t\t\tif (level[t] < 0) return result;\n\
    \t\t\tfill(iter.begin(), iter.end(), 0);\n\t\t\tFLOW f;\n\t\t\twhile ((f = dfs(s,\
    \ t, INF_FLOW)) > 0) result += f;\n\t\t}\n\t}\n};\n#line 3 \"test/Dinic.test.cpp\"\
    \n#include <iostream>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n, m;\n\tcin >> n >> m;\n\tDinic g(n);\n\
    \tfor (int i = 0; i < m; ++i) {\n\t\tint u, v;\n\t\tFLOW d;\n\t\tcin >> u >> v\
    \ >> d;\n\t\tg.add_edge(u, v, d);\n\t}\n\tcout << g.solve(0, n - 1) << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\
    \n#include \"./../Graph/Dinic.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tint\
    \ n, m;\n\tcin >> n >> m;\n\tDinic g(n);\n\tfor (int i = 0; i < m; ++i) {\n\t\t\
    int u, v;\n\t\tFLOW d;\n\t\tcin >> u >> v >> d;\n\t\tg.add_edge(u, v, d);\n\t\
    }\n\tcout << g.solve(0, n - 1) << '\\n';\n}"
  dependsOn:
  - Graph/Dinic.cpp
  - Graph/FlowTemplate.cpp
  isVerificationFile: true
  path: test/Dinic.test.cpp
  requiredBy: []
  timestamp: '2020-11-23 14:52:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Dinic.test.cpp
layout: document
redirect_from:
- /verify/test/Dinic.test.cpp
- /verify/test/Dinic.test.cpp.html
title: test/Dinic.test.cpp
---
