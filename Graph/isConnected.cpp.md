---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/isConnected.cpp\"\n// description : \u9023\u7D50\u5224\
    \u5B9A\nbool isConnected(const Graph& graph, int s, int t) {\n\tint V = graph.size();\n\
    \tqueue<int> que;\n\tque.push(s);\n\tvector<bool> vis(V);\n\tvis[s] = true;\n\t\
    while (!que.empty()) {\n\t\tint fro = que.front();\n\t\tque.pop();\n\t\tif (fro\
    \ == t) return true;\n\t\tfor (auto e : graph[fro])\n\t\t\tif (!vis[e.to]) {\n\
    \t\t\t\tque.push(e.to);\n\t\t\t\tvis[e.to] = true;\n\t\t\t}\n\t}\n\treturn false;\n\
    }\n"
  code: "// description : \u9023\u7D50\u5224\u5B9A\nbool isConnected(const Graph&\
    \ graph, int s, int t) {\n\tint V = graph.size();\n\tqueue<int> que;\n\tque.push(s);\n\
    \tvector<bool> vis(V);\n\tvis[s] = true;\n\twhile (!que.empty()) {\n\t\tint fro\
    \ = que.front();\n\t\tque.pop();\n\t\tif (fro == t) return true;\n\t\tfor (auto\
    \ e : graph[fro])\n\t\t\tif (!vis[e.to]) {\n\t\t\t\tque.push(e.to);\n\t\t\t\t\
    vis[e.to] = true;\n\t\t\t}\n\t}\n\treturn false;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/isConnected.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/isConnected.cpp
layout: document
redirect_from:
- /library/Graph/isConnected.cpp
- /library/Graph/isConnected.cpp.html
title: Graph/isConnected.cpp
---
