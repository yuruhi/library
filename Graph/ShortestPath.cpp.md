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
    #include <climits>\nusing namespace std;\n\nvector<int> ShortestPath(const vector<vector<int>>&\
    \ graph, const int s) {\n\tint V = graph.size();\n\tvector<int> dist(V, INT_MAX);\n\
    \tdist[s] = 0;\n\tqueue<int> que;\n\tque.push(s);\n\twhile (!que.empty()) {\n\t\
    \tint f = que.front();\n\t\tque.pop();\n\t\tfor (auto e : graph[f]) {\n\t\t\t\
    if (dist[e] == INT_MAX) {\n\t\t\t\tque.push(e);\n\t\t\t\tdist[e] = dist[f] + 1;\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn dist;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\n#include <climits>\nusing\
    \ namespace std;\n\nvector<int> ShortestPath(const vector<vector<int>>& graph,\
    \ const int s) {\n\tint V = graph.size();\n\tvector<int> dist(V, INT_MAX);\n\t\
    dist[s] = 0;\n\tqueue<int> que;\n\tque.push(s);\n\twhile (!que.empty()) {\n\t\t\
    int f = que.front();\n\t\tque.pop();\n\t\tfor (auto e : graph[f]) {\n\t\t\tif\
    \ (dist[e] == INT_MAX) {\n\t\t\t\tque.push(e);\n\t\t\t\tdist[e] = dist[f] + 1;\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ShortestPath.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/ShortestPath.cpp
layout: document
redirect_from:
- /library/Graph/ShortestPath.cpp
- /library/Graph/ShortestPath.cpp.html
title: Graph/ShortestPath.cpp
---
