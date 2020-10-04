---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/DijkstraST.cpp\"\n// description : \u59CB\u70B9\u3068\
    \u7D42\u70B9\u3092\u6307\u5B9A\u3059\u308B\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\
    \u6CD5\nWeight Dijkstra(const Graph& graph, int s, int t) {\n\tint V = graph.size();\n\
    \tvector<Weight> dist(V, INF);\n\tdist[s] = 0;\n\tpriority_queue<Edge, vector<Edge>,\
    \ greater<Edge>> pq;\n\tpq.emplace(s, 0);\n\twhile (!pq.empty()) {\n\t\tEdge p\
    \ = pq.top();\n\t\tpq.pop();\n\t\tint v = p.to;\n\t\tif (v == t) return dist[t];\n\
    \t\tif (dist[v] < p.cost) continue;\n\t\tfor (auto e : graph[v]) {\n\t\t\tif (dist[e.to]\
    \ > dist[v] + e.cost) {\n\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\tpq.emplace(e.to,\
    \ dist[e.to]);\n\t\t\t}\n\t\t}\n\t}\n\treturn dist[t];\n}\n"
  code: "// description : \u59CB\u70B9\u3068\u7D42\u70B9\u3092\u6307\u5B9A\u3059\u308B\
    \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\nWeight Dijkstra(const Graph& graph,\
    \ int s, int t) {\n\tint V = graph.size();\n\tvector<Weight> dist(V, INF);\n\t\
    dist[s] = 0;\n\tpriority_queue<Edge, vector<Edge>, greater<Edge>> pq;\n\tpq.emplace(s,\
    \ 0);\n\twhile (!pq.empty()) {\n\t\tEdge p = pq.top();\n\t\tpq.pop();\n\t\tint\
    \ v = p.to;\n\t\tif (v == t) return dist[t];\n\t\tif (dist[v] < p.cost) continue;\n\
    \t\tfor (auto e : graph[v]) {\n\t\t\tif (dist[e.to] > dist[v] + e.cost) {\n\t\t\
    \t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\tpq.emplace(e.to, dist[e.to]);\n\t\t\
    \t}\n\t\t}\n\t}\n\treturn dist[t];\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/DijkstraST.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/DijkstraST.cpp
layout: document
redirect_from:
- /library/Graph/DijkstraST.cpp
- /library/Graph/DijkstraST.cpp.html
title: Graph/DijkstraST.cpp
---
