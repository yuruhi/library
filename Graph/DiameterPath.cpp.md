---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Diameter.test.cpp
    title: test/Diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/GraphTemplate.cpp\"\n#include <limits>\n#include <vector>\n\
    #include <iostream>\n\nusing Weight = long long;\nconstexpr Weight INF = std::numeric_limits<Weight>::max();\n\
    struct Edge {\n\tint to;\n\tWeight cost;\n\tEdge() : to(-1), cost(-1) {}\n\tEdge(int\
    \ _to, Weight _cost = 1) : to(_to), cost(_cost) {}\n\tfriend bool operator<(const\
    \ Edge& e1, const Edge& e2) {\n\t\treturn e1.cost < e2.cost;\n\t}\n\tfriend bool\
    \ operator>(const Edge& e1, const Edge& e2) {\n\t\treturn e1.cost > e2.cost;\n\
    \t}\n\tfriend std::ostream& operator<<(std::ostream& os, const Edge& e) {\n\t\t\
    return os << \"->\" << e.to << '(' << e.cost << ')';\n\t}\n};\nusing UnWeightedGraph\
    \ = std::vector<std::vector<int>>;\nusing Graph = std::vector<std::vector<Edge>>;\n\
    struct Edge2 {\n\tint from, to;\n\tWeight cost;\n\tEdge2() : from(-1), to(-1),\
    \ cost(0) {}\n\tEdge2(int _from, int _to, Weight _cost) : from(_from), to(_to),\
    \ cost(_cost) {}\n\tfriend bool operator<(const Edge2& e1, const Edge2& e2) {\n\
    \t\treturn e1.cost < e2.cost;\n\t}\n\tfriend bool operator>(const Edge2& e1, const\
    \ Edge2& e2) {\n\t\treturn e1.cost > e2.cost;\n\t}\n\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const Edge2& e) {\n\t\treturn os << e.from << \"->\" << e.to << '(' << e.cost\
    \ << ')';\n\t}\n};\nusing Edges = std::vector<Edge2>;\nusing Matrix = std::vector<std::vector<Weight>>;\n\
    \nauto to_graph(const UnWeightedGraph& graph) {\n\tGraph result(graph.size());\n\
    \tfor (std::size_t i = 0; i < graph.size(); ++i) {\n\t\tfor (int v : graph[i])\
    \ {\n\t\t\tresult[i].emplace_back(v, 1);\n\t\t}\n\t}\n\treturn result;\n}\nauto\
    \ to_unweighted_graph(const Graph& graph) {\n\tUnWeightedGraph result(graph.size());\n\
    \tfor (std::size_t i = 0; i < graph.size(); ++i) {\n\t\tfor (auto [v, cost] :\
    \ graph[i]) {\n\t\t\tresult[i].push_back(v);\n\t\t}\n\t}\n\treturn result;\n}\n\
    #line 4 \"Graph/DiameterPath.cpp\"\n#include <algorithm>\n#include <utility>\n\
    #include <tuple>\n#include <functional>\nusing namespace std;\n\ntuple<Weight,\
    \ vector<int>> DiameterPath(const Graph& graph) {\n\tint n = graph.size();\n\t\
    vector<Weight> dist0(n);\n\tfunction<void(int, int, Weight)> dfs = [&](int v,\
    \ int p, Weight d) {\n\t\tdist0[v] = d;\n\t\tfor (const auto& u : graph[v])\n\t\
    \t\tif (u.to != p) {\n\t\t\t\tdfs(u.to, v, d + u.cost);\n\t\t\t}\n\t};\n\tdfs(0,\
    \ -1, 0);\n\n\tint s = max_element(dist0.begin(), dist0.end()) - dist0.begin();\n\
    \tvector<Weight> dist(n);\n\tvector<int> par(n);\n\tfunction<void(int, int, Weight)>\
    \ dfs2 = [&](int v, int p, Weight d) {\n\t\tdist[v] = d;\n\t\tpar[v] = p;\n\t\t\
    for (const auto& u : graph[v])\n\t\t\tif (u.to != p) {\n\t\t\t\tdfs2(u.to, v,\
    \ d + u.cost);\n\t\t\t}\n\t};\n\tdfs2(s, -1, 0);\n\tauto t = max_element(dist.begin(),\
    \ dist.end());\n\tvector<int> path{t - dist.begin()};\n\tfor (int p = 0; (p =\
    \ par[path.back()]) != -1;) {\n\t\tpath.push_back(p);\n\t}\n\treverse(path.begin(),\
    \ path.end());\n\treturn {*t, path};\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <utility>\n#include <tuple>\n#include <functional>\nusing\
    \ namespace std;\n\ntuple<Weight, vector<int>> DiameterPath(const Graph& graph)\
    \ {\n\tint n = graph.size();\n\tvector<Weight> dist0(n);\n\tfunction<void(int,\
    \ int, Weight)> dfs = [&](int v, int p, Weight d) {\n\t\tdist0[v] = d;\n\t\tfor\
    \ (const auto& u : graph[v])\n\t\t\tif (u.to != p) {\n\t\t\t\tdfs(u.to, v, d +\
    \ u.cost);\n\t\t\t}\n\t};\n\tdfs(0, -1, 0);\n\n\tint s = max_element(dist0.begin(),\
    \ dist0.end()) - dist0.begin();\n\tvector<Weight> dist(n);\n\tvector<int> par(n);\n\
    \tfunction<void(int, int, Weight)> dfs2 = [&](int v, int p, Weight d) {\n\t\t\
    dist[v] = d;\n\t\tpar[v] = p;\n\t\tfor (const auto& u : graph[v])\n\t\t\tif (u.to\
    \ != p) {\n\t\t\t\tdfs2(u.to, v, d + u.cost);\n\t\t\t}\n\t};\n\tdfs2(s, -1, 0);\n\
    \tauto t = max_element(dist.begin(), dist.end());\n\tvector<int> path{t - dist.begin()};\n\
    \tfor (int p = 0; (p = par[path.back()]) != -1;) {\n\t\tpath.push_back(p);\n\t\
    }\n\treverse(path.begin(), path.end());\n\treturn {*t, path};\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/DiameterPath.cpp
  requiredBy: []
  timestamp: '2021-03-14 18:03:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Diameter.test.cpp
documentation_of: Graph/DiameterPath.cpp
layout: document
redirect_from:
- /library/Graph/DiameterPath.cpp
- /library/Graph/DiameterPath.cpp.html
title: Graph/DiameterPath.cpp
---
