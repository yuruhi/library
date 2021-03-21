---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/TopologicalSort.test.cpp
    title: test/TopologicalSort.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    #line 4 \"Graph/TopologicalSort.cpp\"\n#include <algorithm>\n\nstd::vector<int>\
    \ TopologicalSort(const UnWeightedTree& graph) {\n\tstd::size_t n = graph.size();\n\
    \tstd::vector<bool> visited(n);\n\tstd::vector<int> result;\n\tauto dfs = [&](auto\
    \ self, std::size_t v) -> void {\n\t\tif (visited[v]) return;\n\t\tvisited[v]\
    \ = true;\n\t\tfor (std::size_t i : graph[v]) self(self, i);\n\t\tresult.push_back(v);\n\
    \t};\n\tfor (std::size_t i = 0; i < n; i++) dfs(dfs, i);\n\tstd::reverse(result.begin(),\
    \ result.end());\n\treturn result;\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\n\nstd::vector<int> TopologicalSort(const UnWeightedTree& graph)\
    \ {\n\tstd::size_t n = graph.size();\n\tstd::vector<bool> visited(n);\n\tstd::vector<int>\
    \ result;\n\tauto dfs = [&](auto self, std::size_t v) -> void {\n\t\tif (visited[v])\
    \ return;\n\t\tvisited[v] = true;\n\t\tfor (std::size_t i : graph[v]) self(self,\
    \ i);\n\t\tresult.push_back(v);\n\t};\n\tfor (std::size_t i = 0; i < n; i++) dfs(dfs,\
    \ i);\n\tstd::reverse(result.begin(), result.end());\n\treturn result;\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/TopologicalSort.cpp
  requiredBy: []
  timestamp: '2021-03-21 10:20:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/TopologicalSort.test.cpp
documentation_of: Graph/TopologicalSort.cpp
layout: document
redirect_from:
- /library/Graph/TopologicalSort.cpp
- /library/Graph/TopologicalSort.cpp.html
title: Graph/TopologicalSort.cpp
---
