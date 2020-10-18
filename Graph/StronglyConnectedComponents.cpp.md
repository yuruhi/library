---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/StronglyConnectedComponents.cpp\"\n#include <vector>\n\
    #include <algorithm>\nusing namespace std;\n\nclass StronglyConnectedComponents\
    \ {\n\tint V;\n\tvector<vector<int>> G, rG;\n\tvector<bool> used;\n\tvector<int>\
    \ cmp;\n\tint k = 0;\n\tvector<int> vs;\n\tvoid dfs(int v) {\n\t\tused[v] = true;\n\
    \t\tfor (auto e : G[v]) {\n\t\t\tif (!used[e]) dfs(e);\n\t\t}\n\t\tvs.push_back(v);\n\
    \t}\n\tvoid rdfs(int v, int k) {\n\t\tused[v] = true;\n\t\tcmp[v] = k;\n\t\tfor\
    \ (auto e : rG[v]) {\n\t\t\tif (!used[e]) rdfs(e, k);\n\t\t}\n\t}\n\npublic:\n\
    \tStronglyConnectedComponents(int v) : V(v), G(V), rG(V), used(V), cmp(V) {}\n\
    \tvoid add_edge(int s, int t) {\n\t\tG[s].push_back(t);\n\t\trG[t].push_back(s);\n\
    \t}\n\tint operator[](int i) const {\n\t\treturn cmp[i];\n\t}\n\tint build() {\n\
    \t\tvs.clear();\n\t\tfill(used.begin(), used.end(), false);\n\t\tfor (int i =\
    \ 0; i < V; ++i) {\n\t\t\tif (!used[i]) dfs(i);\n\t\t}\n\t\tk = 0;\n\t\tfill(used.begin(),\
    \ used.end(), false);\n\t\tfor (int i = vs.size() - 1; i >= 0; --i) {\n\t\t\t\
    if (!used[vs[i]]) rdfs(vs[i], k++);\n\t\t}\n\t\treturn k;\n\t}\n\tvector<vector<int>>\
    \ make_DAG() {\n\t\tvector<vector<int>> res(k);\n\t\tfor (int i = 0; i < V; ++i)\n\
    \t\t\tfor (auto e : G[i]) {\n\t\t\t\tif (cmp[i] != cmp[e]) res[cmp[i]].push_back(cmp[e]);\n\
    \t\t\t}\n\t\tfor (auto& v : res) {\n\t\t\tsort(v.begin(), v.end());\n\t\t\tv.erase(unique(v.begin(),\
    \ v.end()), v.end());\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\
    \nclass StronglyConnectedComponents {\n\tint V;\n\tvector<vector<int>> G, rG;\n\
    \tvector<bool> used;\n\tvector<int> cmp;\n\tint k = 0;\n\tvector<int> vs;\n\t\
    void dfs(int v) {\n\t\tused[v] = true;\n\t\tfor (auto e : G[v]) {\n\t\t\tif (!used[e])\
    \ dfs(e);\n\t\t}\n\t\tvs.push_back(v);\n\t}\n\tvoid rdfs(int v, int k) {\n\t\t\
    used[v] = true;\n\t\tcmp[v] = k;\n\t\tfor (auto e : rG[v]) {\n\t\t\tif (!used[e])\
    \ rdfs(e, k);\n\t\t}\n\t}\n\npublic:\n\tStronglyConnectedComponents(int v) : V(v),\
    \ G(V), rG(V), used(V), cmp(V) {}\n\tvoid add_edge(int s, int t) {\n\t\tG[s].push_back(t);\n\
    \t\trG[t].push_back(s);\n\t}\n\tint operator[](int i) const {\n\t\treturn cmp[i];\n\
    \t}\n\tint build() {\n\t\tvs.clear();\n\t\tfill(used.begin(), used.end(), false);\n\
    \t\tfor (int i = 0; i < V; ++i) {\n\t\t\tif (!used[i]) dfs(i);\n\t\t}\n\t\tk =\
    \ 0;\n\t\tfill(used.begin(), used.end(), false);\n\t\tfor (int i = vs.size() -\
    \ 1; i >= 0; --i) {\n\t\t\tif (!used[vs[i]]) rdfs(vs[i], k++);\n\t\t}\n\t\treturn\
    \ k;\n\t}\n\tvector<vector<int>> make_DAG() {\n\t\tvector<vector<int>> res(k);\n\
    \t\tfor (int i = 0; i < V; ++i)\n\t\t\tfor (auto e : G[i]) {\n\t\t\t\tif (cmp[i]\
    \ != cmp[e]) res[cmp[i]].push_back(cmp[e]);\n\t\t\t}\n\t\tfor (auto& v : res)\
    \ {\n\t\t\tsort(v.begin(), v.end());\n\t\t\tv.erase(unique(v.begin(), v.end()),\
    \ v.end());\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/StronglyConnectedComponents.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/StronglyConnectedComponents.cpp
layout: document
redirect_from:
- /library/Graph/StronglyConnectedComponents.cpp
- /library/Graph/StronglyConnectedComponents.cpp.html
title: Graph/StronglyConnectedComponents.cpp
---
