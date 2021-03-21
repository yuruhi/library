---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LCA.test.cpp
    title: test/LCA.test.cpp
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
    #line 4 \"Graph/LCA.cpp\"\n#include <utility>\n#include <cmath>\n\nclass LCA {\n\
    \tconst std::size_t n;\n\tconst int LOG;\n\tstd::vector<int> dist;\n\tstd::vector<std::vector<int>>\
    \ table;\n\tvoid dfs(const Graph& graph, int v, int p, int d) {\n\t\ttable[0][v]\
    \ = p;\n\t\tdist[v] = d;\n\t\tfor (auto e : graph[v])\n\t\t\tif (e.to != p) {\n\
    \t\t\t\tdfs(graph, e.to, v, d + 1);\n\t\t\t}\n\t}\n\npublic:\n\tLCA(const Graph&\
    \ graph, const int root)\n\t    : n(graph.size()), LOG(log2(n) + 1), dist(n),\
    \ table(LOG, std::vector<int>(n)) {\n\t\tdfs(graph, root, -1, 0);\n\t\tfor (int\
    \ k = 0; k + 1 < LOG; ++k) {\n\t\t\tfor (std::size_t v = 0; v < n; ++v) {\n\t\t\
    \t\tif (table[k][v] < 0) {\n\t\t\t\t\ttable[k + 1][v] = -1;\n\t\t\t\t} else {\n\
    \t\t\t\t\ttable[k + 1][v] = table[k][table[k][v]];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t}\n\tint operator()(int u, int v) {\n\t\tif (dist[u] > dist[v]) std::swap(u,\
    \ v);\n\t\tfor (int k = 0; k < LOG; ++k) {\n\t\t\tif ((dist[v] - dist[u]) >> k\
    \ & 1) {\n\t\t\t\tv = table[k][v];\n\t\t\t}\n\t\t}\n\t\tif (u == v) return u;\n\
    \t\tfor (int k = LOG - 1; k >= 0; --k) {\n\t\t\tif (table[k][u] != table[k][v])\
    \ {\n\t\t\t\tu = table[k][u];\n\t\t\t\tv = table[k][v];\n\t\t\t}\n\t\t}\n\t\t\
    return table[0][u];\n\t}\n};\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <vector>\n#include\
    \ <utility>\n#include <cmath>\n\nclass LCA {\n\tconst std::size_t n;\n\tconst\
    \ int LOG;\n\tstd::vector<int> dist;\n\tstd::vector<std::vector<int>> table;\n\
    \tvoid dfs(const Graph& graph, int v, int p, int d) {\n\t\ttable[0][v] = p;\n\t\
    \tdist[v] = d;\n\t\tfor (auto e : graph[v])\n\t\t\tif (e.to != p) {\n\t\t\t\t\
    dfs(graph, e.to, v, d + 1);\n\t\t\t}\n\t}\n\npublic:\n\tLCA(const Graph& graph,\
    \ const int root)\n\t    : n(graph.size()), LOG(log2(n) + 1), dist(n), table(LOG,\
    \ std::vector<int>(n)) {\n\t\tdfs(graph, root, -1, 0);\n\t\tfor (int k = 0; k\
    \ + 1 < LOG; ++k) {\n\t\t\tfor (std::size_t v = 0; v < n; ++v) {\n\t\t\t\tif (table[k][v]\
    \ < 0) {\n\t\t\t\t\ttable[k + 1][v] = -1;\n\t\t\t\t} else {\n\t\t\t\t\ttable[k\
    \ + 1][v] = table[k][table[k][v]];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tint operator()(int\
    \ u, int v) {\n\t\tif (dist[u] > dist[v]) std::swap(u, v);\n\t\tfor (int k = 0;\
    \ k < LOG; ++k) {\n\t\t\tif ((dist[v] - dist[u]) >> k & 1) {\n\t\t\t\tv = table[k][v];\n\
    \t\t\t}\n\t\t}\n\t\tif (u == v) return u;\n\t\tfor (int k = LOG - 1; k >= 0; --k)\
    \ {\n\t\t\tif (table[k][u] != table[k][v]) {\n\t\t\t\tu = table[k][u];\n\t\t\t\
    \tv = table[k][v];\n\t\t\t}\n\t\t}\n\t\treturn table[0][u];\n\t}\n};\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/LCA.cpp
  requiredBy: []
  timestamp: '2021-03-21 10:20:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LCA.test.cpp
documentation_of: Graph/LCA.cpp
layout: document
redirect_from:
- /library/Graph/LCA.cpp
- /library/Graph/LCA.cpp.html
title: Graph/LCA.cpp
---
