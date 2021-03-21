---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/FlowTemplate.cpp
    title: Graph/FlowTemplate.cpp
  - icon: ':x:'
    path: Graph/FordFulkerson.cpp
    title: Graph/FordFulkerson.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
  bundledCode: "#line 1 \"test/FordFulkerson.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\
    \n#line 2 \"Graph/FlowTemplate.cpp\"\n#include <vector>\n#include <limits>\n\n\
    using FLOW = long long;\nconstexpr FLOW INF_FLOW = std::numeric_limits<FLOW>::max();\n\
    struct EdgeF {\n\tint to, rev;\n\tFLOW cap;\n\tEdgeF() : to(-1), rev(-1), cap(-1)\
    \ {}\n\tEdgeF(int t, int r, FLOW c) : to(t), rev(r), cap(c) {}\n};\nusing GraphF\
    \ = std::vector<std::vector<EdgeF>>;\n#line 4 \"Graph/FordFulkerson.cpp\"\n\n\
    class FordFulkerson {\n\tint n;\n\tGraphF graph;\n\tstd::vector<bool> used;\n\t\
    FLOW dfs(int v, int t, FLOW f) {\n\t\tif (v == t) return f;\n\t\tused[v] = true;\n\
    \t\tfor (auto& e : graph[v]) {\n\t\t\tif (!used[e.to] && e.cap > 0) {\n\t\t\t\t\
    FLOW d = dfs(e.to, t, min(f, e.cap));\n\t\t\t\tif (d > 0) {\n\t\t\t\t\te.cap -=\
    \ d;\n\t\t\t\t\tgraph[e.to][e.rev].cap += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\npublic:\n\tFordFulkerson(std::size_t n)\
    \ :  graph(n), used(n) {}\n\tconst GraphF& get_G() {\n\t\treturn graph;\n\t}\n\
    \tvoid add_edge(int from, int to, FLOW cap) {\n\t\tgraph[from].emplace_back(to,\
    \ graph[to].size(), cap);\n\t\tgraph[to].emplace_back(from, graph[from].size()\
    \ - 1, 0);\n\t}\n\tFLOW solve(int s, int t) {\n\t\tFLOW result = 0;\n\t\twhile\
    \ (true) {\n\t\t\tstd::fill(used.begin(), used.end(), false);\n\t\t\tFLOW f =\
    \ dfs(s, t, INF_FLOW);\n\t\t\tif (!f) return result;\n\t\t\tresult += f;\n\t\t\
    }\n\t}\n};\n#line 3 \"test/FordFulkerson.test.cpp\"\n#include <iostream>\nusing\
    \ namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, m;\n\tcin >> n >> m;\n\tFordFulkerson g(n);\n\tfor (int i = 0; i < m;\
    \ ++i) {\n\t\tint u, v;\n\t\tFLOW d;\n\t\tcin >> u >> v >> d;\n\t\tg.add_edge(u,\
    \ v, d);\n\t}\n\tcout << g.solve(0, n - 1) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\
    \n#include \"./../Graph/FordFulkerson.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, m;\n\tcin >> n >> m;\n\tFordFulkerson g(n);\n\tfor (int i = 0; i < m;\
    \ ++i) {\n\t\tint u, v;\n\t\tFLOW d;\n\t\tcin >> u >> v >> d;\n\t\tg.add_edge(u,\
    \ v, d);\n\t}\n\tcout << g.solve(0, n - 1) << '\\n';\n}"
  dependsOn:
  - Graph/FordFulkerson.cpp
  - Graph/FlowTemplate.cpp
  isVerificationFile: true
  path: test/FordFulkerson.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 10:20:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/FordFulkerson.test.cpp
layout: document
redirect_from:
- /verify/test/FordFulkerson.test.cpp
- /verify/test/FordFulkerson.test.cpp.html
title: test/FordFulkerson.test.cpp
---
