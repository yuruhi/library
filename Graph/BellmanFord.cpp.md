---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BellmanFord.test.cpp
    title: test/BellmanFord.test.cpp
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
    #line 4 \"Graph/BellmanFord.cpp\"\nusing namespace std;\n\npair<bool, vector<Weight>>\
    \ BellmanFord(const Graph& graph, int start) {\n\tint V = graph.size();\n\tvector<Weight>\
    \ dist(V, INF);\n\tdist[start] = 0;\n\tfor (int i = 0; i < V; ++i)\n\t\tfor (int\
    \ v = 0; v < V; ++v)\n\t\t\tfor (auto e : graph[v]) {\n\t\t\t\tif (dist[v] !=\
    \ INF && dist[e.to] > dist[v] + e.cost) {\n\t\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\
    \t\t\t\t\tif (i == V - 1) return {true, dist};\n\t\t\t\t}\n\t\t\t}\n\treturn {false,\
    \ dist};\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <vector>\nusing\
    \ namespace std;\n\npair<bool, vector<Weight>> BellmanFord(const Graph& graph,\
    \ int start) {\n\tint V = graph.size();\n\tvector<Weight> dist(V, INF);\n\tdist[start]\
    \ = 0;\n\tfor (int i = 0; i < V; ++i)\n\t\tfor (int v = 0; v < V; ++v)\n\t\t\t\
    for (auto e : graph[v]) {\n\t\t\t\tif (dist[v] != INF && dist[e.to] > dist[v]\
    \ + e.cost) {\n\t\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\t\tif (i == V\
    \ - 1) return {true, dist};\n\t\t\t\t}\n\t\t\t}\n\treturn {false, dist};\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/BellmanFord.cpp
  requiredBy: []
  timestamp: '2021-03-14 18:03:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/BellmanFord.test.cpp
documentation_of: Graph/BellmanFord.cpp
layout: document
redirect_from:
- /library/Graph/BellmanFord.cpp
- /library/Graph/BellmanFord.cpp.html
title: Graph/BellmanFord.cpp
---
