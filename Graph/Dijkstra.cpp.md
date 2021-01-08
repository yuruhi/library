---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/ChinesePostman.cpp
    title: Graph/ChinesePostman.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ChinesePostman.test.cpp
    title: test/ChinesePostman.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Dijkstra.test.cpp
    title: test/Dijkstra.test.cpp
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
    \n#include <queue>\n#include <cassert>\nusing namespace std;\n\nvector<Weight>\
    \ Dijkstra(const Graph& graph, int s) {\n\tassert(0 <= s && s <= static_cast<int>(graph.size()));\n\
    \tvector<Weight> dist(graph.size(), INF);\n\tdist[s] = 0;\n\tpriority_queue<Edge,\
    \ vector<Edge>, greater<Edge>> pq;\n\tpq.emplace(s, 0);\n\twhile (!pq.empty())\
    \ {\n\t\tEdge p = pq.top();\n\t\tpq.pop();\n\t\tint v = p.to;\n\t\tif (dist[v]\
    \ < p.cost) continue;\n\t\tfor (auto e : graph[v]) {\n\t\t\tif (dist[e.to] > dist[v]\
    \ + e.cost) {\n\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\tpq.emplace(e.to,\
    \ dist[e.to]);\n\t\t\t}\n\t\t}\n\t}\n\treturn dist;\n}\nWeight Dijkstra(const\
    \ Graph& graph, int s, int t) {\n\tassert(0 <= s && s <= static_cast<int>(graph.size()));\n\
    \tassert(0 <= t && t <= static_cast<int>(graph.size()));\n\tvector<Weight> dist(graph.size(),\
    \ INF);\n\tdist[s] = 0;\n\tpriority_queue<Edge, vector<Edge>, greater<Edge>> pq;\n\
    \tpq.emplace(s, 0);\n\twhile (!pq.empty()) {\n\t\tEdge p = pq.top();\n\t\tpq.pop();\n\
    \t\tint v = p.to;\n\t\tif (v == t) return dist[t];\n\t\tif (dist[v] < p.cost)\
    \ continue;\n\t\tfor (auto e : graph[v]) {\n\t\t\tif (dist[e.to] > dist[v] + e.cost)\
    \ {\n\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\tpq.emplace(e.to, dist[e.to]);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn dist[t];\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <vector>\n#include\
    \ <queue>\n#include <cassert>\nusing namespace std;\n\nvector<Weight> Dijkstra(const\
    \ Graph& graph, int s) {\n\tassert(0 <= s && s <= static_cast<int>(graph.size()));\n\
    \tvector<Weight> dist(graph.size(), INF);\n\tdist[s] = 0;\n\tpriority_queue<Edge,\
    \ vector<Edge>, greater<Edge>> pq;\n\tpq.emplace(s, 0);\n\twhile (!pq.empty())\
    \ {\n\t\tEdge p = pq.top();\n\t\tpq.pop();\n\t\tint v = p.to;\n\t\tif (dist[v]\
    \ < p.cost) continue;\n\t\tfor (auto e : graph[v]) {\n\t\t\tif (dist[e.to] > dist[v]\
    \ + e.cost) {\n\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\tpq.emplace(e.to,\
    \ dist[e.to]);\n\t\t\t}\n\t\t}\n\t}\n\treturn dist;\n}\nWeight Dijkstra(const\
    \ Graph& graph, int s, int t) {\n\tassert(0 <= s && s <= static_cast<int>(graph.size()));\n\
    \tassert(0 <= t && t <= static_cast<int>(graph.size()));\n\tvector<Weight> dist(graph.size(),\
    \ INF);\n\tdist[s] = 0;\n\tpriority_queue<Edge, vector<Edge>, greater<Edge>> pq;\n\
    \tpq.emplace(s, 0);\n\twhile (!pq.empty()) {\n\t\tEdge p = pq.top();\n\t\tpq.pop();\n\
    \t\tint v = p.to;\n\t\tif (v == t) return dist[t];\n\t\tif (dist[v] < p.cost)\
    \ continue;\n\t\tfor (auto e : graph[v]) {\n\t\t\tif (dist[e.to] > dist[v] + e.cost)\
    \ {\n\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\tpq.emplace(e.to, dist[e.to]);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn dist[t];\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/Dijkstra.cpp
  requiredBy:
  - Graph/ChinesePostman.cpp
  timestamp: '2021-01-08 17:47:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Dijkstra.test.cpp
  - test/ChinesePostman.test.cpp
documentation_of: Graph/Dijkstra.cpp
layout: document
redirect_from:
- /library/Graph/Dijkstra.cpp
- /library/Graph/Dijkstra.cpp.html
title: Graph/Dijkstra.cpp
---
