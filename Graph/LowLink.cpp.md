---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ArticulationPoints.test.cpp
    title: test/ArticulationPoints.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Bridges.test.cpp
    title: test/Bridges.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/LowLink.cpp\"\n#include <vector>\n#include <utility>\n\
    using namespace std;\n\nclass LowLink {\n\tsize_t n;\n\tvector<vector<int>> graph;\n\
    \tvector<bool> visited;\n\tvector<int> ord, low, articulation_points;\n\tvector<pair<int,\
    \ int>> bridges;\n\tint k;\n\n\tvoid dfs(int v, int parent) {\n\t\tvisited[v]\
    \ = true;\n\t\tord[v] = k++;\n\t\tlow[v] = ord[v];\n\t\tint count = 0;\n\t\tbool\
    \ is_articultion_point = false;\n\t\tfor (int u : graph[v]) {\n\t\t\tif (!visited[u])\
    \ {\n\t\t\t\tcount++;\n\t\t\t\tdfs(u, v);\n\t\t\t\tlow[v] = min(low[v], low[u]);\n\
    \t\t\t\tif (parent != -1 && ord[v] <= low[u]) {\n\t\t\t\t\tis_articultion_point\
    \ = true;\n\t\t\t\t}\n\t\t\t\tif (ord[v] < low[u]) {\n\t\t\t\t\tbridges.emplace_back(min(v,\
    \ u), max(v, u));\n\t\t\t\t}\n\t\t\t} else if (u != parent) {\n\t\t\t\tlow[v]\
    \ = min(low[v], ord[u]);\n\t\t\t}\n\t\t}\n\t\tif (is_articultion_point || (parent\
    \ == -1 && count > 1)) {\n\t\t\tarticulation_points.push_back(v);\n\t\t}\n\t}\n\
    \npublic:\n\tLowLink(size_t _n) : n(_n), graph(_n) {}\n\tLowLink(const vector<vector<int>>&\
    \ _graph) : n(_graph.size()), graph(_graph) {}\n\tvoid add_edge(int u, int v)\
    \ {\n\t\tgraph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\t}\n\tpair<vector<int>,\
    \ vector<pair<int, int>>> build() {\n\t\tvisited.assign(n, false);\n\t\tord.assign(n,\
    \ 0);\n\t\tlow.assign(n, 0);\n\t\tarticulation_points.clear();\n\t\tbridges.clear();\n\
    \t\tk = 0;\n\t\tfor (size_t i = 0; i < n; ++i) {\n\t\t\tif (!visited[i]) dfs(i,\
    \ -1);\n\t\t}\n\t\treturn {articulation_points, bridges};\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\nusing namespace std;\n\
    \nclass LowLink {\n\tsize_t n;\n\tvector<vector<int>> graph;\n\tvector<bool> visited;\n\
    \tvector<int> ord, low, articulation_points;\n\tvector<pair<int, int>> bridges;\n\
    \tint k;\n\n\tvoid dfs(int v, int parent) {\n\t\tvisited[v] = true;\n\t\tord[v]\
    \ = k++;\n\t\tlow[v] = ord[v];\n\t\tint count = 0;\n\t\tbool is_articultion_point\
    \ = false;\n\t\tfor (int u : graph[v]) {\n\t\t\tif (!visited[u]) {\n\t\t\t\tcount++;\n\
    \t\t\t\tdfs(u, v);\n\t\t\t\tlow[v] = min(low[v], low[u]);\n\t\t\t\tif (parent\
    \ != -1 && ord[v] <= low[u]) {\n\t\t\t\t\tis_articultion_point = true;\n\t\t\t\
    \t}\n\t\t\t\tif (ord[v] < low[u]) {\n\t\t\t\t\tbridges.emplace_back(min(v, u),\
    \ max(v, u));\n\t\t\t\t}\n\t\t\t} else if (u != parent) {\n\t\t\t\tlow[v] = min(low[v],\
    \ ord[u]);\n\t\t\t}\n\t\t}\n\t\tif (is_articultion_point || (parent == -1 && count\
    \ > 1)) {\n\t\t\tarticulation_points.push_back(v);\n\t\t}\n\t}\n\npublic:\n\t\
    LowLink(size_t _n) : n(_n), graph(_n) {}\n\tLowLink(const vector<vector<int>>&\
    \ _graph) : n(_graph.size()), graph(_graph) {}\n\tvoid add_edge(int u, int v)\
    \ {\n\t\tgraph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\t}\n\tpair<vector<int>,\
    \ vector<pair<int, int>>> build() {\n\t\tvisited.assign(n, false);\n\t\tord.assign(n,\
    \ 0);\n\t\tlow.assign(n, 0);\n\t\tarticulation_points.clear();\n\t\tbridges.clear();\n\
    \t\tk = 0;\n\t\tfor (size_t i = 0; i < n; ++i) {\n\t\t\tif (!visited[i]) dfs(i,\
    \ -1);\n\t\t}\n\t\treturn {articulation_points, bridges};\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/LowLink.cpp
  requiredBy: []
  timestamp: '2020-11-05 19:42:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Bridges.test.cpp
  - test/ArticulationPoints.test.cpp
documentation_of: Graph/LowLink.cpp
layout: document
redirect_from:
- /library/Graph/LowLink.cpp
- /library/Graph/LowLink.cpp.html
title: Graph/LowLink.cpp
---