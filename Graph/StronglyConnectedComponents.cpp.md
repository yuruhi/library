---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/StronglyConnectedComponents.test.cpp
    title: test/StronglyConnectedComponents.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/StronglyConnectedComponents.cpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <cassert>\n\nclass StronglyConnectedComponents\
    \ {\n\tint n;\n\tstd::vector<std::vector<int>> graph, rgraph;\n\tstd::vector<bool>\
    \ used;\n\tstd::vector<int> cmp, vs;\n\tint k;\n\tbool builded = false;\n\tvoid\
    \ dfs(int v) {\n\t\tused[v] = true;\n\t\tfor (auto e : graph[v]) {\n\t\t\tif (!used[e])\
    \ dfs(e);\n\t\t}\n\t\tvs.push_back(v);\n\t}\n\tvoid rdfs(int v, int k) {\n\t\t\
    used[v] = true;\n\t\tcmp[v] = k;\n\t\tfor (auto e : rgraph[v]) {\n\t\t\tif (!used[e])\
    \ rdfs(e, k);\n\t\t}\n\t}\n\npublic:\n\tStronglyConnectedComponents(int _n) :\
    \ n(_n), graph(n), rgraph(n) {}\n\tStronglyConnectedComponents(const std::vector<std::vector<int>>&\
    \ _graph)\n\t    : n(_graph.size()), graph(_graph), rgraph(n) {\n\t\tfor (int\
    \ v = 0; v < n; ++v) {\n\t\t\tfor (int u : graph[v]) {\n\t\t\t\trgraph[u].push_back(v);\n\
    \t\t\t}\n\t\t}\n\t}\n\tvoid add_edge(int s, int t) {\n\t\tbuilded = false;\n\t\
    \tgraph[s].push_back(t);\n\t\trgraph[t].push_back(s);\n\t}\n\tint build() {\n\t\
    \tvs.clear();\n\t\tused.assign(n, false);\n\t\tcmp.assign(n, 0);\n\t\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\t\tif (!used[i]) dfs(i);\n\t\t}\n\t\tk = 0;\n\t\tstd::fill(used.begin(),\
    \ used.end(), false);\n\t\tfor (int i = vs.size() - 1; i >= 0; --i) {\n\t\t\t\
    if (!used[vs[i]]) rdfs(vs[i], k++);\n\t\t}\n\t\tbuilded = true;\n\t\treturn k;\n\
    \t}\n\tint operator[](int i) const {\n\t\tassert(builded);\n\t\treturn cmp[i];\n\
    \t}\n\tconst std::vector<int>& get_cmp() const {\n\t\tassert(builded);\n\t\treturn\
    \ cmp;\n\t}\n\tconst std::vector<std::vector<int>>& get_graph() const {\n\t\t\
    assert(builded);\n\t\treturn graph;\n\t}\n\tint count_strongly_components() const\
    \ {\n\t\tassert(builded);\n\t\treturn k;\n\t}\n\tstd::vector<std::vector<int>>\
    \ groups() const {\n\t\tassert(builded);\n\t\tstd::vector<std::vector<int>> result(k);\n\
    \t\tfor (int i = 0; i < n; ++i) {\n\t\t\tresult[cmp[i]].push_back(i);\n\t\t}\n\
    \t\treturn result;\n\t}\n\tstd::vector<std::vector<int>> make_DAG() const {\n\t\
    \tassert(builded);\n\t\tstd::vector<std::vector<int>> result(k);\n\t\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\t\tfor (auto e : graph[i]) {\n\t\t\t\tif (cmp[i] !=\
    \ cmp[e]) {\n\t\t\t\t\tresult[cmp[i]].push_back(cmp[e]);\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t\tfor (auto& v : result) {\n\t\t\tstd::sort(v.begin(), v.end());\n\t\t\
    \tv.erase(unique(v.begin(), v.end()), v.end());\n\t\t}\n\t\treturn result;\n\t\
    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    \nclass StronglyConnectedComponents {\n\tint n;\n\tstd::vector<std::vector<int>>\
    \ graph, rgraph;\n\tstd::vector<bool> used;\n\tstd::vector<int> cmp, vs;\n\tint\
    \ k;\n\tbool builded = false;\n\tvoid dfs(int v) {\n\t\tused[v] = true;\n\t\t\
    for (auto e : graph[v]) {\n\t\t\tif (!used[e]) dfs(e);\n\t\t}\n\t\tvs.push_back(v);\n\
    \t}\n\tvoid rdfs(int v, int k) {\n\t\tused[v] = true;\n\t\tcmp[v] = k;\n\t\tfor\
    \ (auto e : rgraph[v]) {\n\t\t\tif (!used[e]) rdfs(e, k);\n\t\t}\n\t}\n\npublic:\n\
    \tStronglyConnectedComponents(int _n) : n(_n), graph(n), rgraph(n) {}\n\tStronglyConnectedComponents(const\
    \ std::vector<std::vector<int>>& _graph)\n\t    : n(_graph.size()), graph(_graph),\
    \ rgraph(n) {\n\t\tfor (int v = 0; v < n; ++v) {\n\t\t\tfor (int u : graph[v])\
    \ {\n\t\t\t\trgraph[u].push_back(v);\n\t\t\t}\n\t\t}\n\t}\n\tvoid add_edge(int\
    \ s, int t) {\n\t\tbuilded = false;\n\t\tgraph[s].push_back(t);\n\t\trgraph[t].push_back(s);\n\
    \t}\n\tint build() {\n\t\tvs.clear();\n\t\tused.assign(n, false);\n\t\tcmp.assign(n,\
    \ 0);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tif (!used[i]) dfs(i);\n\t\t}\n\
    \t\tk = 0;\n\t\tstd::fill(used.begin(), used.end(), false);\n\t\tfor (int i =\
    \ vs.size() - 1; i >= 0; --i) {\n\t\t\tif (!used[vs[i]]) rdfs(vs[i], k++);\n\t\
    \t}\n\t\tbuilded = true;\n\t\treturn k;\n\t}\n\tint operator[](int i) const {\n\
    \t\tassert(builded);\n\t\treturn cmp[i];\n\t}\n\tconst std::vector<int>& get_cmp()\
    \ const {\n\t\tassert(builded);\n\t\treturn cmp;\n\t}\n\tconst std::vector<std::vector<int>>&\
    \ get_graph() const {\n\t\tassert(builded);\n\t\treturn graph;\n\t}\n\tint count_strongly_components()\
    \ const {\n\t\tassert(builded);\n\t\treturn k;\n\t}\n\tstd::vector<std::vector<int>>\
    \ groups() const {\n\t\tassert(builded);\n\t\tstd::vector<std::vector<int>> result(k);\n\
    \t\tfor (int i = 0; i < n; ++i) {\n\t\t\tresult[cmp[i]].push_back(i);\n\t\t}\n\
    \t\treturn result;\n\t}\n\tstd::vector<std::vector<int>> make_DAG() const {\n\t\
    \tassert(builded);\n\t\tstd::vector<std::vector<int>> result(k);\n\t\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\t\tfor (auto e : graph[i]) {\n\t\t\t\tif (cmp[i] !=\
    \ cmp[e]) {\n\t\t\t\t\tresult[cmp[i]].push_back(cmp[e]);\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t\tfor (auto& v : result) {\n\t\t\tstd::sort(v.begin(), v.end());\n\t\t\
    \tv.erase(unique(v.begin(), v.end()), v.end());\n\t\t}\n\t\treturn result;\n\t\
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/StronglyConnectedComponents.cpp
  requiredBy: []
  timestamp: '2021-03-21 10:20:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/StronglyConnectedComponents.test.cpp
documentation_of: Graph/StronglyConnectedComponents.cpp
layout: document
redirect_from:
- /library/Graph/StronglyConnectedComponents.cpp
- /library/Graph/StronglyConnectedComponents.cpp.html
title: Graph/StronglyConnectedComponents.cpp
---
