---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/TopologicalSort.test.cpp
    title: test/TopologicalSort.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/TopologicalSort.cpp\"\n#include <vector>\n#include\
    \ <functional>\n#include <algorithm>\nusing namespace std;\n\nvector<int> TopologicalSort(const\
    \ vector<vector<int>>& graph) {\n\tint V = graph.size();\n\tvector<bool> visited(V);\n\
    \tvector<int> res;\n\tfunction<void(int)> dfs = [&](int u) {\n\t\tif (visited[u])\
    \ return;\n\t\tvisited[u] = true;\n\t\tfor (auto& i : graph[u])\n\t\t\tdfs(i);\n\
    \t\tres.push_back(u);\n\t};\n\tfor (int i = 0; i < V; i++)\n\t\tdfs(i);\n\treverse(res.begin(),\
    \ res.end());\n\treturn res;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n#include <algorithm>\n\
    using namespace std;\n\nvector<int> TopologicalSort(const vector<vector<int>>&\
    \ graph) {\n\tint V = graph.size();\n\tvector<bool> visited(V);\n\tvector<int>\
    \ res;\n\tfunction<void(int)> dfs = [&](int u) {\n\t\tif (visited[u]) return;\n\
    \t\tvisited[u] = true;\n\t\tfor (auto& i : graph[u])\n\t\t\tdfs(i);\n\t\tres.push_back(u);\n\
    \t};\n\tfor (int i = 0; i < V; i++)\n\t\tdfs(i);\n\treverse(res.begin(), res.end());\n\
    \treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/TopologicalSort.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/TopologicalSort.test.cpp
documentation_of: Graph/TopologicalSort.cpp
layout: document
redirect_from:
- /library/Graph/TopologicalSort.cpp
- /library/Graph/TopologicalSort.cpp.html
title: Graph/TopologicalSort.cpp
---
