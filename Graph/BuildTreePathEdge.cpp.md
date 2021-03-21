---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/BuildTreePathEdge.cpp\"\n#include <vector>\n#include\
    \ <utility>\nusing namespace std;\n\nstd::vector<int> BuildTreePathEdge(const\
    \ std::vector<std::vector<std::pair<int, int>>>& graph,\n                    \
    \               int s, int t) {\n\tint n = graph.size();\n\tstd::vector par(n,\
    \ std::pair(-1, -1));\n\tauto dfs = [&](auto&& f, int v, int p) -> void {\n\t\t\
    for (auto [u, i] : graph[v]) {\n\t\t\tif (u != p) {\n\t\t\t\tpar[u] = std::pair(v,\
    \ i);\n\t\t\t\tf(f, u, v);\n\t\t\t}\n\t\t}\n\t};\n\tdfs(dfs, t, -1);\n\tstd::vector<int>\
    \ result;\n\tfor (int v = s; v != t; v = par[v].first) {\n\t\tresult.push_back(par[v].second);\n\
    \t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\nusing namespace std;\n\
    \nstd::vector<int> BuildTreePathEdge(const std::vector<std::vector<std::pair<int,\
    \ int>>>& graph,\n                                   int s, int t) {\n\tint n\
    \ = graph.size();\n\tstd::vector par(n, std::pair(-1, -1));\n\tauto dfs = [&](auto&&\
    \ f, int v, int p) -> void {\n\t\tfor (auto [u, i] : graph[v]) {\n\t\t\tif (u\
    \ != p) {\n\t\t\t\tpar[u] = std::pair(v, i);\n\t\t\t\tf(f, u, v);\n\t\t\t}\n\t\
    \t}\n\t};\n\tdfs(dfs, t, -1);\n\tstd::vector<int> result;\n\tfor (int v = s; v\
    \ != t; v = par[v].first) {\n\t\tresult.push_back(par[v].second);\n\t}\n\treturn\
    \ result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BuildTreePathEdge.cpp
  requiredBy: []
  timestamp: '2021-03-21 10:20:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BuildTreePathEdge.cpp
layout: document
redirect_from:
- /library/Graph/BuildTreePathEdge.cpp
- /library/Graph/BuildTreePathEdge.cpp.html
title: Graph/BuildTreePathEdge.cpp
---
