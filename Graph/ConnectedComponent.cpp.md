---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ConnectedComponent.test.cpp
    title: test/ConnectedComponent.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/ConnectedComponent.cpp\"\n#include <vector>\n#include\
    \ <tuple>\nusing namespace std;\n\ntuple<int, vector<int>, vector<vector<int>>>\
    \ ConnectedComponent(\n    const vector<vector<int>>& graph) {\n\tint n = graph.size(),\
    \ count_components = 0;\n\tvector<int> id(n, -1);\n\tvector<vector<int>> groups(n);\n\
    \tauto dfs = [&](auto&& f, int ID, int v) -> void {\n\t\tid[v] = ID;\n\t\tgroups[ID].push_back(v);\n\
    \t\tfor (int u : graph[v]) {\n\t\t\tif (id[u] == -1) f(f, ID, u);\n\t\t}\n\t};\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tif (id[i] == -1) dfs(dfs, count_components++,\
    \ i);\n\t}\n\tgroups.resize(count_components);\n\treturn {count_components, id,\
    \ groups};\n}\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\nusing namespace std;\n\
    \ntuple<int, vector<int>, vector<vector<int>>> ConnectedComponent(\n    const\
    \ vector<vector<int>>& graph) {\n\tint n = graph.size(), count_components = 0;\n\
    \tvector<int> id(n, -1);\n\tvector<vector<int>> groups(n);\n\tauto dfs = [&](auto&&\
    \ f, int ID, int v) -> void {\n\t\tid[v] = ID;\n\t\tgroups[ID].push_back(v);\n\
    \t\tfor (int u : graph[v]) {\n\t\t\tif (id[u] == -1) f(f, ID, u);\n\t\t}\n\t};\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tif (id[i] == -1) dfs(dfs, count_components++,\
    \ i);\n\t}\n\tgroups.resize(count_components);\n\treturn {count_components, id,\
    \ groups};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ConnectedComponent.cpp
  requiredBy: []
  timestamp: '2020-11-22 20:04:46+09:00'
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
