---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/CycleDetectionEdge_Directed.test.cpp
    title: test/CycleDetectionEdge_Directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/CycleDetectionEdge_Undirected.test.cpp
    title: test/CycleDetectionEdge_Undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/CycleDetectionVertex_Directed.test.cpp
    title: test/CycleDetectionVertex_Directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/CycleDetectionVertex_Undirected.test.cpp
    title: test/CycleDetectionVertex_Undirected.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/CycleDetection.cpp\"\n#include <vector>\n#include\
    \ <stack>\n#include <utility>\n#include <algorithm>\n#include <optional>\nusing\
    \ namespace std;\n\npair<bool, vector<int>> CycleDetectionEdge(int n, const vector<pair<int,\
    \ int>>& edges,\n                                           bool directed = true)\
    \ {\n\tvector<vector<pair<int, int>>> graph(n);\n\tfor (size_t i = 0; i < edges.size();\
    \ ++i) {\n\t\tauto [u, v] = edges[i];\n\t\tgraph[u].emplace_back(v, i);\n\t\t\
    if (!directed) graph[v].emplace_back(u, i);\n\t}\n\tvector<bool> visited(n), finished(n);\n\
    \tstack<pair<int, int>> st;\n\toptional<int> pos;\n\tauto dfs = [&](auto&& f,\
    \ int v, int prev) -> void {\n\t\tvisited[v] = true;\n\t\tfor (auto [u, i] : graph[v])\
    \ {\n\t\t\tif (!finished[u] && (directed || u != prev)) {\n\t\t\t\tst.emplace(i,\
    \ v);\n\t\t\t\tif (visited[u]) {\n\t\t\t\t\tpos = u;\n\t\t\t\t\treturn;\n\t\t\t\
    \t}\n\t\t\t\tf(f, u, v);\n\t\t\t\tif (pos) return;\n\t\t\t\tst.pop();\n\t\t\t\
    }\n\t\t}\n\t\tfinished[v] = true;\n\t};\n\tfor (int i = 0; i < n && !pos; ++i)\
    \ {\n\t\tif (!visited[i]) dfs(dfs, i, -1);\n\t}\n\n\tif (pos) {\n\t\tvector<int>\
    \ cycle;\n\t\twhile (!st.empty()) {\n\t\t\tauto [top, from] = st.top();\n\t\t\t\
    st.pop();\n\t\t\tcycle.push_back(top);\n\t\t\tif (from == *pos) {\n\t\t\t\tbreak;\n\
    \t\t\t}\n\t\t}\n\t\treverse(cycle.begin(), cycle.end());\n\t\treturn {true, cycle};\n\
    \t} else {\n\t\treturn {false, {}};\n\t}\n}\n\npair<bool, vector<int>> CycleDetectionVertex(const\
    \ vector<vector<int>>& graph,\n                                             bool\
    \ directed = true) {\n\tint n = graph.size();\n\tvector<bool> visited(n), finished(n);\n\
    \tstack<int> st;\n\toptional<int> pos;\n\tauto dfs = [&](auto&& f, int v, int\
    \ prev) -> void {\n\t\tvisited[v] = true;\n\t\tst.push(v);\n\t\tfor (int u : graph[v])\
    \ {\n\t\t\tif (!finished[u] && (directed || u != prev)) {\n\t\t\t\tif (visited[u])\
    \ {\n\t\t\t\t\tpos = u;\n\t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t\tf(f, u, v);\n\t\
    \t\t\tif (pos) return;\n\t\t\t}\n\t\t}\n\t\tfinished[v] = true;\n\t\tst.pop();\n\
    \t};\n\tfor (int i = 0; i < n && !pos; ++i) {\n\t\tif (!visited[i]) dfs(dfs, i,\
    \ -1);\n\t}\n\n\tif (pos) {\n\t\tvector<int> cycle;\n\t\twhile (!st.empty()) {\n\
    \t\t\tint top = st.top();\n\t\t\tst.pop();\n\t\t\tcycle.push_back(top);\n\t\t\t\
    if (top == *pos) {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\treverse(cycle.begin(),\
    \ cycle.end());\n\t\treturn {true, cycle};\n\t} else {\n\t\treturn {false, {}};\n\
    \t}\n}\n\npair<bool, vector<int>> CycleDetectionVertex(int n, const vector<pair<int,\
    \ int>>& edges,\n                                             bool directed =\
    \ true) {\n\tvector<vector<int>> graph(n);\n\tfor (auto [u, v] : edges) {\n\t\t\
    graph[u].push_back(v);\n\t\tif (!directed) graph[v].push_back(u);\n\t}\n\treturn\
    \ CycleDetectionVertex(graph, directed);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <stack>\n#include <utility>\n#include\
    \ <algorithm>\n#include <optional>\nusing namespace std;\n\npair<bool, vector<int>>\
    \ CycleDetectionEdge(int n, const vector<pair<int, int>>& edges,\n           \
    \                                bool directed = true) {\n\tvector<vector<pair<int,\
    \ int>>> graph(n);\n\tfor (size_t i = 0; i < edges.size(); ++i) {\n\t\tauto [u,\
    \ v] = edges[i];\n\t\tgraph[u].emplace_back(v, i);\n\t\tif (!directed) graph[v].emplace_back(u,\
    \ i);\n\t}\n\tvector<bool> visited(n), finished(n);\n\tstack<pair<int, int>> st;\n\
    \toptional<int> pos;\n\tauto dfs = [&](auto&& f, int v, int prev) -> void {\n\t\
    \tvisited[v] = true;\n\t\tfor (auto [u, i] : graph[v]) {\n\t\t\tif (!finished[u]\
    \ && (directed || u != prev)) {\n\t\t\t\tst.emplace(i, v);\n\t\t\t\tif (visited[u])\
    \ {\n\t\t\t\t\tpos = u;\n\t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t\tf(f, u, v);\n\t\
    \t\t\tif (pos) return;\n\t\t\t\tst.pop();\n\t\t\t}\n\t\t}\n\t\tfinished[v] = true;\n\
    \t};\n\tfor (int i = 0; i < n && !pos; ++i) {\n\t\tif (!visited[i]) dfs(dfs, i,\
    \ -1);\n\t}\n\n\tif (pos) {\n\t\tvector<int> cycle;\n\t\twhile (!st.empty()) {\n\
    \t\t\tauto [top, from] = st.top();\n\t\t\tst.pop();\n\t\t\tcycle.push_back(top);\n\
    \t\t\tif (from == *pos) {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\treverse(cycle.begin(),\
    \ cycle.end());\n\t\treturn {true, cycle};\n\t} else {\n\t\treturn {false, {}};\n\
    \t}\n}\n\npair<bool, vector<int>> CycleDetectionVertex(const vector<vector<int>>&\
    \ graph,\n                                             bool directed = true) {\n\
    \tint n = graph.size();\n\tvector<bool> visited(n), finished(n);\n\tstack<int>\
    \ st;\n\toptional<int> pos;\n\tauto dfs = [&](auto&& f, int v, int prev) -> void\
    \ {\n\t\tvisited[v] = true;\n\t\tst.push(v);\n\t\tfor (int u : graph[v]) {\n\t\
    \t\tif (!finished[u] && (directed || u != prev)) {\n\t\t\t\tif (visited[u]) {\n\
    \t\t\t\t\tpos = u;\n\t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t\tf(f, u, v);\n\t\t\t\t\
    if (pos) return;\n\t\t\t}\n\t\t}\n\t\tfinished[v] = true;\n\t\tst.pop();\n\t};\n\
    \tfor (int i = 0; i < n && !pos; ++i) {\n\t\tif (!visited[i]) dfs(dfs, i, -1);\n\
    \t}\n\n\tif (pos) {\n\t\tvector<int> cycle;\n\t\twhile (!st.empty()) {\n\t\t\t\
    int top = st.top();\n\t\t\tst.pop();\n\t\t\tcycle.push_back(top);\n\t\t\tif (top\
    \ == *pos) {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\treverse(cycle.begin(), cycle.end());\n\
    \t\treturn {true, cycle};\n\t} else {\n\t\treturn {false, {}};\n\t}\n}\n\npair<bool,\
    \ vector<int>> CycleDetectionVertex(int n, const vector<pair<int, int>>& edges,\n\
    \                                             bool directed = true) {\n\tvector<vector<int>>\
    \ graph(n);\n\tfor (auto [u, v] : edges) {\n\t\tgraph[u].push_back(v);\n\t\tif\
    \ (!directed) graph[v].push_back(u);\n\t}\n\treturn CycleDetectionVertex(graph,\
    \ directed);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/CycleDetection.cpp
  requiredBy: []
  timestamp: '2020-11-23 19:16:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/CycleDetectionVertex_Directed.test.cpp
  - test/CycleDetectionVertex_Undirected.test.cpp
  - test/CycleDetectionEdge_Undirected.test.cpp
  - test/CycleDetectionEdge_Directed.test.cpp
documentation_of: Graph/CycleDetection.cpp
layout: document
redirect_from:
- /library/Graph/CycleDetection.cpp
- /library/Graph/CycleDetection.cpp.html
title: Graph/CycleDetection.cpp
---
