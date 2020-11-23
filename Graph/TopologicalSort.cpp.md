---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/StronglyConnectedComponents.test.cpp
    title: test/StronglyConnectedComponents.test.cpp
  - icon: ':x:'
    path: test/TopologicalSort.test.cpp
    title: test/TopologicalSort.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/TopologicalSort.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\nusing namespace std;\n\nvector<int> TopologicalSort(const vector<vector<int>>&\
    \ graph) {\n\tsize_t n = graph.size();\n\tvector<bool> visited(n);\n\tvector<int>\
    \ res;\n\tauto dfs = [&](auto self, size_t v) {\n\t\tif (visited[v]) return;\n\
    \t\tvisited[v] = true;\n\t\tfor (size_t i : graph[v]) dfs(i);\n\t\tres.push_back(v);\n\
    \t};\n\tfor (size_t i = 0; i < n; i++) dfs(i);\n\treverse(res.begin(), res.end());\n\
    \treturn res;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\
    \nvector<int> TopologicalSort(const vector<vector<int>>& graph) {\n\tsize_t n\
    \ = graph.size();\n\tvector<bool> visited(n);\n\tvector<int> res;\n\tauto dfs\
    \ = [&](auto self, size_t v) {\n\t\tif (visited[v]) return;\n\t\tvisited[v] =\
    \ true;\n\t\tfor (size_t i : graph[v]) dfs(i);\n\t\tres.push_back(v);\n\t};\n\t\
    for (size_t i = 0; i < n; i++) dfs(i);\n\treverse(res.begin(), res.end());\n\t\
    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/TopologicalSort.cpp
  requiredBy: []
  timestamp: '2020-11-22 20:04:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/TopologicalSort.test.cpp
  - test/StronglyConnectedComponents.test.cpp
documentation_of: Graph/TopologicalSort.cpp
layout: document
redirect_from:
- /library/Graph/TopologicalSort.cpp
- /library/Graph/TopologicalSort.cpp.html
title: Graph/TopologicalSort.cpp
---
