---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/BuildTreePathEdge.cpp\"\n#include <vector>\n#include\
    \ <utility>\nusing namespace std;\n\nvector<int> BuildTreePathEdge(const vector<vector<pair<int,\
    \ int>>>& graph, int s, int t) {\n\tint n = graph.size();\n\tvector<pair<int,\
    \ int>> par(n, make_pair(-1, -1));\n\tauto dfs = [&](auto&& f, int v, int p) ->\
    \ void {\n\t\tfor (auto [u, i] : graph[v]) {\n\t\t\tif (u != p) {\n\t\t\t\tpar[u]\
    \ = make_pair(v, i);\n\t\t\t\tf(f, u, v);\n\t\t\t}\n\t\t}\n\t};\n\tdfs(dfs, t,\
    \ -1);\n\tvector<int> res;\n\tfor (int v = s; v != t; v = par[v].first) {\n\t\t\
    res.push_back(par[v].second);\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\nusing namespace std;\n\
    \nvector<int> BuildTreePathEdge(const vector<vector<pair<int, int>>>& graph, int\
    \ s, int t) {\n\tint n = graph.size();\n\tvector<pair<int, int>> par(n, make_pair(-1,\
    \ -1));\n\tauto dfs = [&](auto&& f, int v, int p) -> void {\n\t\tfor (auto [u,\
    \ i] : graph[v]) {\n\t\t\tif (u != p) {\n\t\t\t\tpar[u] = make_pair(v, i);\n\t\
    \t\t\tf(f, u, v);\n\t\t\t}\n\t\t}\n\t};\n\tdfs(dfs, t, -1);\n\tvector<int> res;\n\
    \tfor (int v = s; v != t; v = par[v].first) {\n\t\tres.push_back(par[v].second);\n\
    \t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BuildTreePathEdge.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BuildTreePathEdge.cpp
layout: document
redirect_from:
- /library/Graph/BuildTreePathEdge.cpp
- /library/Graph/BuildTreePathEdge.cpp.html
title: Graph/BuildTreePathEdge.cpp
---
