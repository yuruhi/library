---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/TopologicalSort.test.cpp
    title: test/TopologicalSort.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/TopologicalSort.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\nusing namespace std;\n\nvector<int> TopologicalSort(const vector<vector<int>>&\
    \ graph) {\n\tsize_t n = graph.size();\n\tvector<bool> visited(n);\n\tvector<int>\
    \ result;\n\tauto dfs = [&](auto self, size_t v) -> void {\n\t\tif (visited[v])\
    \ return;\n\t\tvisited[v] = true;\n\t\tfor (size_t i : graph[v]) self(self, i);\n\
    \t\tresult.push_back(v);\n\t};\n\tfor (size_t i = 0; i < n; i++) dfs(dfs, i);\n\
    \treverse(result.begin(), result.end());\n\treturn result;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\
    \nvector<int> TopologicalSort(const vector<vector<int>>& graph) {\n\tsize_t n\
    \ = graph.size();\n\tvector<bool> visited(n);\n\tvector<int> result;\n\tauto dfs\
    \ = [&](auto self, size_t v) -> void {\n\t\tif (visited[v]) return;\n\t\tvisited[v]\
    \ = true;\n\t\tfor (size_t i : graph[v]) self(self, i);\n\t\tresult.push_back(v);\n\
    \t};\n\tfor (size_t i = 0; i < n; i++) dfs(dfs, i);\n\treverse(result.begin(),\
    \ result.end());\n\treturn result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/TopologicalSort.cpp
  requiredBy: []
  timestamp: '2020-11-23 14:52:17+09:00'
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
