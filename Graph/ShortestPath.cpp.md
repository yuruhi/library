---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/ShortestPath.cpp\"\n#include <vector>\n#include <queue>\n\
    #include <optional>\n#include <limits>\nusing namespace std;\n\nvector<int> ShortestPath(const\
    \ vector<vector<int>>& graph, int s,\n                         int inf = numeric_limits<int>::max())\
    \ {\n\tint V = graph.size();\n\tvector<int> dist(V, inf);\n\tdist[s] = 0;\n\t\
    queue<int> que;\n\tque.push(s);\n\twhile (!que.empty()) {\n\t\tint f = que.front();\n\
    \t\tque.pop();\n\t\tfor (auto e : graph[f]) {\n\t\t\tif (dist[e] == inf) {\n\t\
    \t\t\tque.push(e);\n\t\t\t\tdist[e] = dist[f] + 1;\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ dist;\n}\nint ShortestPathST(const vector<vector<int>>& graph, int s, int t,\n\
    \                   int inf = numeric_limits<int>::max()) {\n\tsize_t n = graph.size();\n\
    \tvector<int> dist(n, inf);\n\tdist[s] = 0;\n\tqueue<int> que;\n\tque.push(s);\n\
    \twhile (!que.empty()) {\n\t\tint v = que.front();\n\t\tif (v == t) return dist[t];\n\
    \t\tque.pop();\n\t\tfor (auto u : graph[v]) {\n\t\t\tif (dist[u] == inf) {\n\t\
    \t\t\tque.push(u);\n\t\t\t\tdist[u] = dist[v] + 1;\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ dist[t];\n}\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\n#include <optional>\n\
    #include <limits>\nusing namespace std;\n\nvector<int> ShortestPath(const vector<vector<int>>&\
    \ graph, int s,\n                         int inf = numeric_limits<int>::max())\
    \ {\n\tint V = graph.size();\n\tvector<int> dist(V, inf);\n\tdist[s] = 0;\n\t\
    queue<int> que;\n\tque.push(s);\n\twhile (!que.empty()) {\n\t\tint f = que.front();\n\
    \t\tque.pop();\n\t\tfor (auto e : graph[f]) {\n\t\t\tif (dist[e] == inf) {\n\t\
    \t\t\tque.push(e);\n\t\t\t\tdist[e] = dist[f] + 1;\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ dist;\n}\nint ShortestPathST(const vector<vector<int>>& graph, int s, int t,\n\
    \                   int inf = numeric_limits<int>::max()) {\n\tsize_t n = graph.size();\n\
    \tvector<int> dist(n, inf);\n\tdist[s] = 0;\n\tqueue<int> que;\n\tque.push(s);\n\
    \twhile (!que.empty()) {\n\t\tint v = que.front();\n\t\tif (v == t) return dist[t];\n\
    \t\tque.pop();\n\t\tfor (auto u : graph[v]) {\n\t\t\tif (dist[u] == inf) {\n\t\
    \t\t\tque.push(u);\n\t\t\t\tdist[u] = dist[v] + 1;\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ dist[t];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ShortestPath.cpp
  requiredBy: []
  timestamp: '2021-01-01 17:28:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/ShortestPath.cpp
layout: document
redirect_from:
- /library/Graph/ShortestPath.cpp
- /library/Graph/ShortestPath.cpp.html
title: Graph/ShortestPath.cpp
---
