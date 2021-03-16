---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ConnectedComponent.test.cpp
    title: test/ConnectedComponent.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/ConnectedComponent.cpp\"\n#include <vector>\n#include\
    \ <tuple>\n\nauto ConnectedComponent(const std::vector<std::vector<int>>& graph)\
    \ {\n\tint n = graph.size(), count_components = 0;\n\tstd::vector<int> id(n, -1);\n\
    \tstd::vector<std::vector<int>> groups(n);\n\tauto dfs = [&](auto&& f, int ID,\
    \ int v) -> void {\n\t\tid[v] = ID;\n\t\tgroups[ID].push_back(v);\n\t\tfor (int\
    \ u : graph[v]) {\n\t\t\tif (id[u] == -1) f(f, ID, u);\n\t\t}\n\t};\n\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\tif (id[i] == -1) dfs(dfs, count_components++, i);\n\
    \t}\n\tgroups.resize(count_components);\n\treturn std::tuple(count_components,\
    \ id, groups);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\n\nauto ConnectedComponent(const\
    \ std::vector<std::vector<int>>& graph) {\n\tint n = graph.size(), count_components\
    \ = 0;\n\tstd::vector<int> id(n, -1);\n\tstd::vector<std::vector<int>> groups(n);\n\
    \tauto dfs = [&](auto&& f, int ID, int v) -> void {\n\t\tid[v] = ID;\n\t\tgroups[ID].push_back(v);\n\
    \t\tfor (int u : graph[v]) {\n\t\t\tif (id[u] == -1) f(f, ID, u);\n\t\t}\n\t};\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tif (id[i] == -1) dfs(dfs, count_components++,\
    \ i);\n\t}\n\tgroups.resize(count_components);\n\treturn std::tuple(count_components,\
    \ id, groups);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ConnectedComponent.cpp
  requiredBy: []
  timestamp: '2021-03-14 18:03:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ConnectedComponent.test.cpp
documentation_of: Graph/ConnectedComponent.cpp
layout: document
redirect_from:
- /library/Graph/ConnectedComponent.cpp
- /library/Graph/ConnectedComponent.cpp.html
title: Graph/ConnectedComponent.cpp
---
