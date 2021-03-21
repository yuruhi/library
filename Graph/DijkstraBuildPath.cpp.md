---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DijkstraBuildPath.test.cpp
    title: test/DijkstraBuildPath.test.cpp
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
    #line 4 \"Graph/DijkstraBuildPath.cpp\"\n#include <queue>\n#include <algorithm>\n\
    #include <functional>\n#include <utility>\n\nauto DijkstraBuildPrev(const Graph&\
    \ graph, int s) {\n\tstd::size_t n = graph.size();\n\tstd::vector<Weight> dist(n,\
    \ INF);\n\tdist[s] = 0;\n\tstd::vector<int> prev(n, -1);\n\tstd::priority_queue<Edge,\
    \ std::vector<Edge>, std::greater<Edge>> pq;\n\tpq.emplace(s, 0);\n\twhile (!pq.empty())\
    \ {\n\t\tEdge p = pq.top();\n\t\tpq.pop();\n\t\tint v = p.to;\n\t\tif (dist[v]\
    \ < p.cost) continue;\n\t\tfor (auto e : graph[v]) {\n\t\t\tif (dist[e.to] > dist[v]\
    \ + e.cost) {\n\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\tpq.emplace(e.to,\
    \ dist[e.to]);\n\t\t\t\tprev[e.to] = v;\n\t\t\t}\n\t\t}\n\t}\n\treturn std::pair(dist,\
    \ prev);\n}\nstd::vector<int> BuildPath(const std::vector<int>& prev, int t) {\n\
    \tstd::vector<int> result;\n\twhile (prev[t] != -1) {\n\t\tresult.push_back(t);\n\
    \t\tt = prev[t];\n\t}\n\tresult.push_back(t);\n\tstd::reverse(result.begin(),\
    \ result.end());\n\treturn result;\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <vector>\n#include\
    \ <queue>\n#include <algorithm>\n#include <functional>\n#include <utility>\n\n\
    auto DijkstraBuildPrev(const Graph& graph, int s) {\n\tstd::size_t n = graph.size();\n\
    \tstd::vector<Weight> dist(n, INF);\n\tdist[s] = 0;\n\tstd::vector<int> prev(n,\
    \ -1);\n\tstd::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;\n\
    \tpq.emplace(s, 0);\n\twhile (!pq.empty()) {\n\t\tEdge p = pq.top();\n\t\tpq.pop();\n\
    \t\tint v = p.to;\n\t\tif (dist[v] < p.cost) continue;\n\t\tfor (auto e : graph[v])\
    \ {\n\t\t\tif (dist[e.to] > dist[v] + e.cost) {\n\t\t\t\tdist[e.to] = dist[v]\
    \ + e.cost;\n\t\t\t\tpq.emplace(e.to, dist[e.to]);\n\t\t\t\tprev[e.to] = v;\n\t\
    \t\t}\n\t\t}\n\t}\n\treturn std::pair(dist, prev);\n}\nstd::vector<int> BuildPath(const\
    \ std::vector<int>& prev, int t) {\n\tstd::vector<int> result;\n\twhile (prev[t]\
    \ != -1) {\n\t\tresult.push_back(t);\n\t\tt = prev[t];\n\t}\n\tresult.push_back(t);\n\
    \tstd::reverse(result.begin(), result.end());\n\treturn result;\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/DijkstraBuildPath.cpp
  requiredBy: []
  timestamp: '2021-03-21 10:20:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DijkstraBuildPath.test.cpp
documentation_of: Graph/DijkstraBuildPath.cpp
layout: document
redirect_from:
- /library/Graph/DijkstraBuildPath.cpp
- /library/Graph/DijkstraBuildPath.cpp.html
title: Graph/DijkstraBuildPath.cpp
---
