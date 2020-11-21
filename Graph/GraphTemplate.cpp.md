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
  - icon: ':warning:'
    path: Graph/DijkstraST.cpp
    title: Graph/DijkstraST.cpp
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
  - icon: ':x:'
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
    path: test/Diameter.test.cpp
    title: test/Diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Dijkstra.test.cpp
    title: test/Dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/DijkstraBuildPath.test.cpp
    title: test/DijkstraBuildPath.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Kruskal.test.cpp
    title: test/Kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LCA.test.cpp
    title: test/LCA.test.cpp
  - icon: ':x:'
    path: test/WarashallFloyd.test.cpp
    title: test/WarashallFloyd.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/GraphTemplate.cpp\"\n#include <limits>\n#include <vector>\n\
    #include <iostream>\nusing namespace std;\n\nusing Weight = long long;\nconstexpr\
    \ Weight INF = numeric_limits<Weight>::max();\nstruct Edge {\n\tint to;\n\tWeight\
    \ cost;\n\tEdge() : to(-1), cost(-1) {}\n\tEdge(int _to, Weight _cost = 1) : to(_to),\
    \ cost(_cost) {}\n\tfriend bool operator<(const Edge& e1, const Edge& e2) {\n\t\
    \treturn e1.cost < e2.cost;\n\t}\n\tfriend bool operator>(const Edge& e1, const\
    \ Edge& e2) {\n\t\treturn e1.cost > e2.cost;\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ os, const Edge& e) {\n\t\treturn os << \"->\" << e.to << '(' << e.cost << ')';\n\
    \t}\n};\nusing Graph = vector<vector<Edge>>;\nstruct Edge2 {\n\tint from, to;\n\
    \tWeight cost;\n\tEdge2() : from(-1), to(-1), cost(0) {}\n\tEdge2(int _from, int\
    \ _to, Weight _cost) : from(_from), to(_to), cost(_cost) {}\n\tfriend bool operator<(const\
    \ Edge2& e1, const Edge2& e2) {\n\t\treturn e1.cost < e2.cost;\n\t}\n\tfriend\
    \ bool operator>(const Edge2& e1, const Edge2& e2) {\n\t\treturn e1.cost > e2.cost;\n\
    \t}\n\tfriend ostream& operator<<(ostream& os, const Edge2& e) {\n\t\treturn os\
    \ << e.from << \"->\" << e.to << '(' << e.cost << ')';\n\t}\n};\nusing Edges =\
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n"
  code: "#pragma once\n#include <limits>\n#include <vector>\n#include <iostream>\n\
    using namespace std;\n\nusing Weight = long long;\nconstexpr Weight INF = numeric_limits<Weight>::max();\n\
    struct Edge {\n\tint to;\n\tWeight cost;\n\tEdge() : to(-1), cost(-1) {}\n\tEdge(int\
    \ _to, Weight _cost = 1) : to(_to), cost(_cost) {}\n\tfriend bool operator<(const\
    \ Edge& e1, const Edge& e2) {\n\t\treturn e1.cost < e2.cost;\n\t}\n\tfriend bool\
    \ operator>(const Edge& e1, const Edge& e2) {\n\t\treturn e1.cost > e2.cost;\n\
    \t}\n\tfriend ostream& operator<<(ostream& os, const Edge& e) {\n\t\treturn os\
    \ << \"->\" << e.to << '(' << e.cost << ')';\n\t}\n};\nusing Graph = vector<vector<Edge>>;\n\
    struct Edge2 {\n\tint from, to;\n\tWeight cost;\n\tEdge2() : from(-1), to(-1),\
    \ cost(0) {}\n\tEdge2(int _from, int _to, Weight _cost) : from(_from), to(_to),\
    \ cost(_cost) {}\n\tfriend bool operator<(const Edge2& e1, const Edge2& e2) {\n\
    \t\treturn e1.cost < e2.cost;\n\t}\n\tfriend bool operator>(const Edge2& e1, const\
    \ Edge2& e2) {\n\t\treturn e1.cost > e2.cost;\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ os, const Edge2& e) {\n\t\treturn os << e.from << \"->\" << e.to << '(' << e.cost\
    \ << ')';\n\t}\n};\nusing Edges = vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/GraphTemplate.cpp
  requiredBy:
  - Graph/BellmanFord.cpp
  - Graph/LCA.cpp
  - Graph/BuildTreePath.cpp
  - Graph/Diameter.cpp
  - Graph/SpanningTree.cpp
  - Graph/DiameterPath.cpp
  - Graph/DijkstraST.cpp
  - Graph/Kruskal.cpp
  - Graph/isConnected.cpp
  - Graph/WarashallFloyd.cpp
  - Graph/Dijkstra.cpp
  - Graph/DijkstraBuildPath.cpp
  - Graph/ShortestPathTree.cpp
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/LCA.test.cpp
  - test/Dijkstra.test.cpp
  - test/Kruskal.test.cpp
  - test/Diameter.test.cpp
  - test/BellmanFord.test.cpp
  - test/WarashallFloyd.test.cpp
  - test/DijkstraBuildPath.test.cpp
documentation_of: Graph/GraphTemplate.cpp
layout: document
redirect_from:
- /library/Graph/GraphTemplate.cpp
- /library/Graph/GraphTemplate.cpp.html
title: Graph/GraphTemplate.cpp
---
