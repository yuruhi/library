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
    #line 4 \"Graph/BipartiteGraph.cpp\"\n#include <optional>\n#include <tuple>\n\n\
    std::optional<std::vector<bool>> BipartiteGraph(const UnWeightedGraph& graph)\
    \ {\n\tstd::size_t n = graph.size();\n\tstd::vector<std::optional<bool>> a(n);\n\
    \tauto dfs = [&](auto&& f, int v, bool color) -> bool {\n\t\ta[v] = color;\n\t\
    \tfor (int u : graph[v]) {\n\t\t\tif (a[u].has_value() ? a[u].value() == color\
    \ : !f(f, u, !color)) {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t}\n\t\treturn true;\n\
    \t};\n\tfor (std::size_t i = 0; i < n; ++i) {\n\t\tif (!a[i].has_value() && !dfs(dfs,\
    \ i, 1)) {\n\t\t\treturn std::nullopt;\n\t\t}\n\t}\n\tstd::vector<bool> result(n);\n\
    \tfor (std::size_t i = 0; i < n; ++i) {\n\t\tresult[i] = a[i].value();\n\t}\n\t\
    return result;\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <vector>\n#include\
    \ <optional>\n#include <tuple>\n\nstd::optional<std::vector<bool>> BipartiteGraph(const\
    \ UnWeightedGraph& graph) {\n\tstd::size_t n = graph.size();\n\tstd::vector<std::optional<bool>>\
    \ a(n);\n\tauto dfs = [&](auto&& f, int v, bool color) -> bool {\n\t\ta[v] = color;\n\
    \t\tfor (int u : graph[v]) {\n\t\t\tif (a[u].has_value() ? a[u].value() == color\
    \ : !f(f, u, !color)) {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t}\n\t\treturn true;\n\
    \t};\n\tfor (std::size_t i = 0; i < n; ++i) {\n\t\tif (!a[i].has_value() && !dfs(dfs,\
    \ i, 1)) {\n\t\t\treturn std::nullopt;\n\t\t}\n\t}\n\tstd::vector<bool> result(n);\n\
    \tfor (std::size_t i = 0; i < n; ++i) {\n\t\tresult[i] = a[i].value();\n\t}\n\t\
    return result;\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/BipartiteGraph.cpp
  requiredBy: []
  timestamp: '2021-03-20 17:00:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BipartiteGraph.cpp
layout: document
redirect_from:
- /library/Graph/BipartiteGraph.cpp
- /library/Graph/BipartiteGraph.cpp.html
title: Graph/BipartiteGraph.cpp
---
