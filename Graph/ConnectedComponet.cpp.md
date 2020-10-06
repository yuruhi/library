---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/ConnectedComponet.cpp\"\n#include <vector>\n#include\
    \ <tuple>\nusing namespace std;\n\ntuple<int, vector<int>, vector<vector<int>>>\
    \ ConnectedComponet(const vector<vector<int>>& g) {\n\tint V = g.size(), N = 0;\n\
    \tvector<int> id(V, -1);\n\tvector<vector<int>> ind(V);\n\tauto dfs = [&](auto&&\
    \ f, int ID, int v) -> void {\n\t\tid[v] = ID;\n\t\tind[ID].push_back(v);\n\t\t\
    for (auto e : g[v])\n\t\t\tif (id[e] == -1) f(f, ID, e);\n\t};\n\tfor (int i =\
    \ 0; i < V; ++i)\n\t\tif (id[i] == -1) dfs(dfs, N++, i);\n\tind.resize(N);\n\t\
    return make_tuple(N, id, ind);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\nusing namespace std;\n\
    \ntuple<int, vector<int>, vector<vector<int>>> ConnectedComponet(const vector<vector<int>>&\
    \ g) {\n\tint V = g.size(), N = 0;\n\tvector<int> id(V, -1);\n\tvector<vector<int>>\
    \ ind(V);\n\tauto dfs = [&](auto&& f, int ID, int v) -> void {\n\t\tid[v] = ID;\n\
    \t\tind[ID].push_back(v);\n\t\tfor (auto e : g[v])\n\t\t\tif (id[e] == -1) f(f,\
    \ ID, e);\n\t};\n\tfor (int i = 0; i < V; ++i)\n\t\tif (id[i] == -1) dfs(dfs,\
    \ N++, i);\n\tind.resize(N);\n\treturn make_tuple(N, id, ind);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ConnectedComponet.cpp
  requiredBy: []
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/ConnectedComponet.cpp
layout: document
redirect_from:
- /library/Graph/ConnectedComponet.cpp
- /library/Graph/ConnectedComponet.cpp.html
title: Graph/ConnectedComponet.cpp
---
