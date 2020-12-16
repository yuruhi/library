---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Dijkstra.cpp
    title: Graph/Dijkstra.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ChinesePostman.test.cpp
    title: test/ChinesePostman.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/GraphTemplate.cpp\"\n#include <limits>\n#include <vector>\n\
    #include <iostream>\nusing namespace std;\n\nusing Weight = long long;\nconstexpr\
    \ Weight INF = numeric_limits<Weight>::max();\nstruct Edge {\n\tint to;\n\tWeight\
    \ cost;\n\tEdge() : to(-1), cost(-1) {}\n\tEdge(int _to, Weight _cost = 1) : to(_to),\
    \ cost(_cost) {}\n\tfriend bool operator<(const Edge& e1, const Edge& e2) {\n\t\
    \treturn e1.cost < e2.cost;\n\t}\n\tfriend bool operator>(const Edge& e1, const\
    \ Edge& e2) {\n\t\treturn e1.cost > e2.cost;\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ os, const Edge& e) {\n\t\treturn os << \"->\" << e.to << '(' << e.cost << ')';\n\
    \t}\n};\nusing Graph = vector<vector<Edge>>;\nstruct Edge2 {\n\tint from, to;\n\
    \tWeight cost;\n\tEdge2() : from(-1), to(-1), cost(0) {}\n\tEdge2(int _from, int\
    \ _to, Weight _cost) : from(_from), to(_to), cost(_cost) {}\n\tfriend bool operator<(const\
    \ Edge2& e1, const Edge2& e2) {\n\t\treturn e1.cost < e2.cost;\n\t}\n\tfriend\
    \ bool operator>(const Edge2& e1, const Edge2& e2) {\n\t\treturn e1.cost > e2.cost;\n\
    \t}\n\tfriend ostream& operator<<(ostream& os, const Edge2& e) {\n\t\treturn os\
    \ << e.from << \"->\" << e.to << '(' << e.cost << ')';\n\t}\n};\nusing Edges =\
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 4 \"Graph/Dijkstra.cpp\"\
    \n#include <queue>\nusing namespace std;\n\nvector<Weight> Dijkstra(const Graph&\
    \ graph, int s) {\n\tint V = graph.size();\n\tvector<Weight> dist(V, INF);\n\t\
    dist[s] = 0;\n\tpriority_queue<Edge, vector<Edge>, greater<Edge>> pq;\n\tpq.emplace(s,\
    \ 0);\n\twhile (!pq.empty()) {\n\t\tEdge p = pq.top();\n\t\tpq.pop();\n\t\tint\
    \ v = p.to;\n\t\tif (dist[v] < p.cost) continue;\n\t\tfor (auto e : graph[v])\
    \ {\n\t\t\tif (dist[e.to] > dist[v] + e.cost) {\n\t\t\t\tdist[e.to] = dist[v]\
    \ + e.cost;\n\t\t\t\tpq.emplace(e.to, dist[e.to]);\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ dist;\n}\nWeight Dijkstra(const Graph& graph, int s, int t) {\n\tint V = graph.size();\n\
    \tvector<Weight> dist(V, INF);\n\tdist[s] = 0;\n\tpriority_queue<Edge, vector<Edge>,\
    \ greater<Edge>> pq;\n\tpq.emplace(s, 0);\n\twhile (!pq.empty()) {\n\t\tEdge p\
    \ = pq.top();\n\t\tpq.pop();\n\t\tint v = p.to;\n\t\tif (v == t) return dist[t];\n\
    \t\tif (dist[v] < p.cost) continue;\n\t\tfor (auto e : graph[v]) {\n\t\t\tif (dist[e.to]\
    \ > dist[v] + e.cost) {\n\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\tpq.emplace(e.to,\
    \ dist[e.to]);\n\t\t\t}\n\t\t}\n\t}\n\treturn dist[t];\n}\n#line 4 \"Graph/ChinesePostman.cpp\"\
    \nusing namespace std;\n\nWeight ChinesePostman(const Graph& graph) {\n\tsize_t\
    \ n = graph.size();\n\tWeight sum = 0;\n\tvector<int> odds;\n\tfor (size_t v =\
    \ 0; v < n; ++v) {\n\t\tfor (const auto& e : graph[v]) sum += e.cost;\n\t\tif\
    \ (graph[v].size() % 2 == 1) odds.push_back(v);\n\t}\n\tsum /= 2;\n\n\tsize_t\
    \ m = odds.size(), M = 1 << m;\n\tMatrix dist(m, vector<Weight>(m));\n\tfor (size_t\
    \ i = 0; i < m; ++i) {\n\t\tauto dist_v = Dijkstra(graph, odds[i]);\n\t\tfor (size_t\
    \ j = 0; j < m; ++j) {\n\t\t\tdist[i][j] = dist_v[odds[j]];\n\t\t}\n\t}\n\n\t\
    vector<Weight> dp(M, INF);\n\tdp[0] = 0;\n\tfor (size_t s = 0; s < M; ++s) {\n\
    \t\tfor (size_t i = 0; i < m; ++i) {\n\t\t\tif (!(s & (1 << i))) {\n\t\t\t\tfor\
    \ (size_t j = i + 1; j < m; ++j) {\n\t\t\t\t\tif (!(s & (1 << j))) {\n\t\t\t\t\
    \t\tsize_t t = s | (1 << i) | (1 << j);\n\t\t\t\t\t\tdp[t] = min(dp[t], dp[s]\
    \ + dist[i][j]);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\treturn sum +\
    \ dp[M - 1];\n}\n"
  code: "#pragma once\n#include \"./Dijkstra.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\nWeight ChinesePostman(const Graph& graph) {\n\tsize_t n = graph.size();\n\
    \tWeight sum = 0;\n\tvector<int> odds;\n\tfor (size_t v = 0; v < n; ++v) {\n\t\
    \tfor (const auto& e : graph[v]) sum += e.cost;\n\t\tif (graph[v].size() % 2 ==\
    \ 1) odds.push_back(v);\n\t}\n\tsum /= 2;\n\n\tsize_t m = odds.size(), M = 1 <<\
    \ m;\n\tMatrix dist(m, vector<Weight>(m));\n\tfor (size_t i = 0; i < m; ++i) {\n\
    \t\tauto dist_v = Dijkstra(graph, odds[i]);\n\t\tfor (size_t j = 0; j < m; ++j)\
    \ {\n\t\t\tdist[i][j] = dist_v[odds[j]];\n\t\t}\n\t}\n\n\tvector<Weight> dp(M,\
    \ INF);\n\tdp[0] = 0;\n\tfor (size_t s = 0; s < M; ++s) {\n\t\tfor (size_t i =\
    \ 0; i < m; ++i) {\n\t\t\tif (!(s & (1 << i))) {\n\t\t\t\tfor (size_t j = i +\
    \ 1; j < m; ++j) {\n\t\t\t\t\tif (!(s & (1 << j))) {\n\t\t\t\t\t\tsize_t t = s\
    \ | (1 << i) | (1 << j);\n\t\t\t\t\t\tdp[t] = min(dp[t], dp[s] + dist[i][j]);\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\treturn sum + dp[M - 1];\n}\n"
  dependsOn:
  - Graph/Dijkstra.cpp
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/ChinesePostman.cpp
  requiredBy: []
  timestamp: '2020-12-15 12:46:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ChinesePostman.test.cpp
documentation_of: Graph/ChinesePostman.cpp
layout: document
redirect_from:
- /library/Graph/ChinesePostman.cpp
- /library/Graph/ChinesePostman.cpp.html
title: Graph/ChinesePostman.cpp
---
