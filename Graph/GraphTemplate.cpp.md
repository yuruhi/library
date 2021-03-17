---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/BellmanFord.cpp
    title: Graph/BellmanFord.cpp
  - icon: ':warning:'
    path: Graph/BuildTreePath.cpp
    title: Graph/BuildTreePath.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/ChinesePostman.cpp
    title: Graph/ChinesePostman.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/Diameter.cpp
    title: Graph/Diameter.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/DiameterPath.cpp
    title: Graph/DiameterPath.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/Dijkstra.cpp
    title: Graph/Dijkstra.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/DijkstraBuildPath.cpp
    title: Graph/DijkstraBuildPath.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/DirectedMinimumSpanningTree.cpp
    title: Graph/DirectedMinimumSpanningTree.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/Kruskal.cpp
    title: Graph/Kruskal.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/LCA.cpp
    title: Graph/LCA.cpp
  - icon: ':warning:'
    path: Graph/ShortestPathTree.cpp
    title: Graph/ShortestPathTree.cpp
  - icon: ':warning:'
    path: Graph/SpanningTree.cpp
    title: Graph/SpanningTree.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/TravelingSalesmanProblem.cpp
    title: Graph/TravelingSalesmanProblem.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/WarashallFloyd.cpp
    title: Graph/WarashallFloyd.cpp
  - icon: ':warning:'
    path: Graph/isConnected.cpp
    title: Graph/isConnected.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BellmanFord.test.cpp
    title: test/BellmanFord.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ChinesePostman.test.cpp
    title: test/ChinesePostman.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Diameter.test.cpp
    title: test/Diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Dijkstra.test.cpp
    title: test/Dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/DijkstraBuildPath.test.cpp
    title: test/DijkstraBuildPath.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/DirectedMinimumSpanningTree.test.cpp
    title: test/DirectedMinimumSpanningTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Kruskal.test.cpp
    title: test/Kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LCA.test.cpp
    title: test/LCA.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/TravelingSalesmanProblem.test.cpp
    title: test/TravelingSalesmanProblem.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/WarashallFloyd.test.cpp
    title: test/WarashallFloyd.test.cpp
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
    \ graph[i]) {\n\t\t\tresult[i].push_back(v);\n\t\t}\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include <limits>\n#include <vector>\n#include <iostream>\n\
    \nusing Weight = long long;\nconstexpr Weight INF = std::numeric_limits<Weight>::max();\n\
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
    \ graph[i]) {\n\t\t\tresult[i].push_back(v);\n\t\t}\n\t}\n\treturn result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/GraphTemplate.cpp
  requiredBy:
  - Graph/LCA.cpp
  - Graph/Diameter.cpp
  - Graph/DijkstraBuildPath.cpp
  - Graph/DiameterPath.cpp
  - Graph/BellmanFord.cpp
  - Graph/Dijkstra.cpp
  - Graph/BuildTreePath.cpp
  - Graph/ShortestPathTree.cpp
  - Graph/isConnected.cpp
  - Graph/WarashallFloyd.cpp
  - Graph/TravelingSalesmanProblem.cpp
  - Graph/Kruskal.cpp
  - Graph/SpanningTree.cpp
  - Graph/DirectedMinimumSpanningTree.cpp
  - Graph/ChinesePostman.cpp
  timestamp: '2021-03-14 18:03:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/WarashallFloyd.test.cpp
  - test/DijkstraBuildPath.test.cpp
  - test/DirectedMinimumSpanningTree.test.cpp
  - test/ChinesePostman.test.cpp
  - test/Kruskal.test.cpp
  - test/TravelingSalesmanProblem.test.cpp
  - test/Diameter.test.cpp
  - test/LCA.test.cpp
  - test/BellmanFord.test.cpp
  - test/Dijkstra.test.cpp
documentation_of: Graph/GraphTemplate.cpp
layout: document
redirect_from:
- /library/Graph/GraphTemplate.cpp
- /library/Graph/GraphTemplate.cpp.html
title: Graph/GraphTemplate.cpp
---
