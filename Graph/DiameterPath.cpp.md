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
  bundledCode: "#line 2 \"Graph/GraphTemplate.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <iostream>\n#include <limits>\n\nusing Weight = long long;\nconstexpr\
    \ Weight INF = std::numeric_limits<Weight>::max();\nstruct Edge {\n\tint to;\n\
    \tWeight cost;\n\tEdge() : to(-1), cost(-1) {}\n\tEdge(int _to, Weight _cost =\
    \ 1) : to(_to), cost(_cost) {}\n\tfriend bool operator<(const Edge& e1, const\
    \ Edge& e2) {\n\t\treturn e1.cost < e2.cost;\n\t}\n\tfriend bool operator>(const\
    \ Edge& e1, const Edge& e2) {\n\t\treturn e1.cost > e2.cost;\n\t}\n\tfriend std::ostream&\
    \ operator<<(std::ostream& os, const Edge& e) {\n\t\treturn os << \"->\" << e.to\
    \ << '(' << e.cost << ')';\n\t}\n};\nusing UnWeightedGraph = std::vector<std::vector<int>>;\n\
    using Graph = std::vector<std::vector<Edge>>;\nstruct Edge2 {\n\tint from, to;\n\
    \tWeight cost;\n\tEdge2() : from(-1), to(-1), cost(0) {}\n\tEdge2(int _from, int\
    \ _to, Weight _cost) : from(_from), to(_to), cost(_cost) {}\n\tfriend bool operator<(const\
    \ Edge2& e1, const Edge2& e2) {\n\t\treturn e1.cost < e2.cost;\n\t}\n\tfriend\
    \ bool operator>(const Edge2& e1, const Edge2& e2) {\n\t\treturn e1.cost > e2.cost;\n\
    \t}\n\tfriend std::ostream& operator<<(std::ostream& os, const Edge2& e) {\n\t\
    \treturn os << e.from << \"->\" << e.to << '(' << e.cost << ')';\n\t}\n};\nusing\
    \ UnWeightedEdges = std::vector<std::pair<int, int>>;\nusing Edges = std::vector<Edge2>;\n\
    using Matrix = std::vector<std::vector<Weight>>;\n\nauto add_edge(UnWeightedGraph&\
    \ graph, int v, int u) {\n\tgraph[v].push_back(u);\n\tgraph[u].push_back(v);\n\
    }\nauto add_edge(Graph& graph, int v, int u, Weight cost) {\n\tgraph[v].emplace_back(u,\
    \ cost);\n\tgraph[u].emplace_back(v, cost);\n}\nauto to_graph(const UnWeightedGraph&\
    \ graph, Weight cost = 1) {\n\tGraph result(graph.size());\n\tfor (std::size_t\
    \ i = 0; i < graph.size(); ++i) {\n\t\tfor (int v : graph[i]) {\n\t\t\tresult[i].emplace_back(v,\
    \ cost);\n\t\t}\n\t}\n\treturn result;\n}\nauto to_unweighted_graph(const Graph&\
    \ graph) {\n\tUnWeightedGraph result(graph.size());\n\tfor (std::size_t i = 0;\
    \ i < graph.size(); ++i) {\n\t\tfor (auto [v, cost] : graph[i]) {\n\t\t\tresult[i].push_back(v);\n\
    \t\t}\n\t}\n\treturn result;\n}\nauto to_edges(const UnWeightedGraph& graph, bool\
    \ unique = false) {\n\tstd::vector<std::pair<int, int>> edges;\n\tfor (std::size_t\
    \ i = 0; i < graph.size(); ++i) {\n\t\tfor (int v : graph[i]) {\n\t\t\tif (!unique\
    \ || static_cast<int>(i) < v) edges.emplace_back(i, v);\n\t\t}\n\t}\n\treturn\
    \ edges;\n}\nauto to_edges(const Graph& graph) {\n\tEdges edges;\n\tfor (std::size_t\
    \ i = 0; i < graph.size(); ++i) {\n\t\tfor (auto [v, cost] : graph[i]) {\n\t\t\
    \tedges.emplace_back(i, v, cost);\n\t\t}\n\t}\n\treturn edges;\n}\n#line 4 \"\
    Graph/DiameterPath.cpp\"\n#include <algorithm>\n#line 6 \"Graph/DiameterPath.cpp\"\
    \n#include <tuple>\n#include <functional>\n\nstd::tuple<Weight, std::vector<int>>\
    \ DiameterPath(const Graph& graph) {\n\tint n = graph.size();\n\tstd::vector<Weight>\
    \ dist0(n);\n\tauto dfs = [&](auto self, int v, int p, Weight d) -> void {\n\t\
    \tdist0[v] = d;\n\t\tfor (const auto& u : graph[v])\n\t\t\tif (u.to != p) {\n\t\
    \t\t\tself(self, u.to, v, d + u.cost);\n\t\t\t}\n\t};\n\tdfs(dfs, 0, -1, 0);\n\
    \n\tint s = std::max_element(dist0.begin(), dist0.end()) - dist0.begin();\n\t\
    std::vector<Weight> dist(n);\n\tstd::vector<int> par(n);\n\tauto dfs2 = [&](auto\
    \ self, int v, int p, Weight d) -> void {\n\t\tdist[v] = d;\n\t\tpar[v] = p;\n\
    \t\tfor (const auto& u : graph[v]) {\n\t\t\tif (u.to != p) {\n\t\t\t\tself(self,\
    \ u.to, v, d + u.cost);\n\t\t\t}\n\t\t}\n\t};\n\tdfs2(dfs2, s, -1, 0);\n\tauto\
    \ t = std::max_element(dist.begin(), dist.end());\n\tstd::vector<int> path{static_cast<int>(t\
    \ - dist.begin())};\n\tfor (int p = 0; (p = par[path.back()]) != -1;) {\n\t\t\
    path.push_back(p);\n\t}\n\tstd::reverse(path.begin(), path.end());\n\treturn {*t,\
    \ path};\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <utility>\n#include <tuple>\n#include <functional>\n\n\
    std::tuple<Weight, std::vector<int>> DiameterPath(const Graph& graph) {\n\tint\
    \ n = graph.size();\n\tstd::vector<Weight> dist0(n);\n\tauto dfs = [&](auto self,\
    \ int v, int p, Weight d) -> void {\n\t\tdist0[v] = d;\n\t\tfor (const auto& u\
    \ : graph[v])\n\t\t\tif (u.to != p) {\n\t\t\t\tself(self, u.to, v, d + u.cost);\n\
    \t\t\t}\n\t};\n\tdfs(dfs, 0, -1, 0);\n\n\tint s = std::max_element(dist0.begin(),\
    \ dist0.end()) - dist0.begin();\n\tstd::vector<Weight> dist(n);\n\tstd::vector<int>\
    \ par(n);\n\tauto dfs2 = [&](auto self, int v, int p, Weight d) -> void {\n\t\t\
    dist[v] = d;\n\t\tpar[v] = p;\n\t\tfor (const auto& u : graph[v]) {\n\t\t\tif\
    \ (u.to != p) {\n\t\t\t\tself(self, u.to, v, d + u.cost);\n\t\t\t}\n\t\t}\n\t\
    };\n\tdfs2(dfs2, s, -1, 0);\n\tauto t = std::max_element(dist.begin(), dist.end());\n\
    \tstd::vector<int> path{static_cast<int>(t - dist.begin())};\n\tfor (int p = 0;\
    \ (p = par[path.back()]) != -1;) {\n\t\tpath.push_back(p);\n\t}\n\tstd::reverse(path.begin(),\
    \ path.end());\n\treturn {*t, path};\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/DiameterPath.cpp
  requiredBy: []
  timestamp: '2021-03-22 17:28:05+09:00'
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
