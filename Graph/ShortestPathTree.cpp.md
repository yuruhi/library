---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    #line 4 \"Graph/ShortestPathTree.cpp\"\n\nstd::vector<int> ShortestPathTree(const\
    \ UnWeightedGraph& graph, int s) {\n\tstd::vector<int> dist(graph.size());\n\t\
    auto dfs = [&](auto&& f, int v, int p, int depth) -> void {\n\t\tdist[v] = depth;\n\
    \t\tfor (int e : graph[v]) {\n\t\t\tif (e != p) {\n\t\t\t\tf(f, e, v, depth +\
    \ 1);\n\t\t\t}\n\t\t}\n\t};\n\tdfs(dfs, s, -1, 0);\n\treturn dist;\n}\nstd::vector<Weight>\
    \ ShortestPathTree(const Graph& graph, int s) {\n\tstd::vector<Weight> dist(graph.size());\n\
    \tauto dfs = [&](auto&& f, int v, int p, Weight depth) -> void {\n\t\tdist[v]\
    \ = depth;\n\t\tfor (auto e : graph[v]) {\n\t\t\tif (e.to != p) {\n\t\t\t\tf(f,\
    \ e.to, v, depth + e.cost);\n\t\t\t}\n\t\t}\n\t};\n\tdfs(dfs, s, -1, 0);\n\treturn\
    \ dist;\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <vector>\n\nstd::vector<int>\
    \ ShortestPathTree(const UnWeightedGraph& graph, int s) {\n\tstd::vector<int>\
    \ dist(graph.size());\n\tauto dfs = [&](auto&& f, int v, int p, int depth) ->\
    \ void {\n\t\tdist[v] = depth;\n\t\tfor (int e : graph[v]) {\n\t\t\tif (e != p)\
    \ {\n\t\t\t\tf(f, e, v, depth + 1);\n\t\t\t}\n\t\t}\n\t};\n\tdfs(dfs, s, -1, 0);\n\
    \treturn dist;\n}\nstd::vector<Weight> ShortestPathTree(const Graph& graph, int\
    \ s) {\n\tstd::vector<Weight> dist(graph.size());\n\tauto dfs = [&](auto&& f,\
    \ int v, int p, Weight depth) -> void {\n\t\tdist[v] = depth;\n\t\tfor (auto e\
    \ : graph[v]) {\n\t\t\tif (e.to != p) {\n\t\t\t\tf(f, e.to, v, depth + e.cost);\n\
    \t\t\t}\n\t\t}\n\t};\n\tdfs(dfs, s, -1, 0);\n\treturn dist;\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/ShortestPathTree.cpp
  requiredBy: []
  timestamp: '2021-03-16 12:30:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/ShortestPathTree.cpp
layout: document
redirect_from:
- /library/Graph/ShortestPathTree.cpp
- /library/Graph/ShortestPathTree.cpp.html
title: Graph/ShortestPathTree.cpp
---
