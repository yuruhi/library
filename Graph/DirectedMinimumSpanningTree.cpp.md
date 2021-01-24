---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/CycleDetection.cpp
    title: Graph/CycleDetection.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DirectedMinimumSpanningTree.test.cpp
    title: test/DirectedMinimumSpanningTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 3 \"Graph/CycleDetection.cpp\"\
    \n#include <stack>\n#include <algorithm>\n#include <optional>\nusing namespace\
    \ std;\n\noptional<vector<int>> CycleDetectionEdge(int n, const vector<pair<int,\
    \ int>>& edges,\n                                         bool directed = true)\
    \ {\n\tvector<vector<pair<int, int>>> graph(n);\n\tfor (size_t i = 0; i < edges.size();\
    \ ++i) {\n\t\tauto [u, v] = edges[i];\n\t\tgraph[u].emplace_back(v, i);\n\t\t\
    if (!directed) graph[v].emplace_back(u, i);\n\t}\n\tvector<bool> visited(n), finished(n);\n\
    \tstack<pair<int, int>> st;\n\toptional<int> pos;\n\tauto dfs = [&](auto&& f,\
    \ int v, int prev_edge) -> void {\n\t\tvisited[v] = true;\n\t\tfor (auto [u, i]\
    \ : graph[v]) {\n\t\t\tif (!finished[u] && (directed || i != prev_edge)) {\n\t\
    \t\t\tst.emplace(i, v);\n\t\t\t\tif (visited[u]) {\n\t\t\t\t\tpos = u;\n\t\t\t\
    \t\treturn;\n\t\t\t\t}\n\t\t\t\tf(f, u, i);\n\t\t\t\tif (pos) return;\n\t\t\t\t\
    st.pop();\n\t\t\t}\n\t\t}\n\t\tfinished[v] = true;\n\t};\n\tfor (int i = 0; i\
    \ < n && !pos; ++i) {\n\t\tif (!visited[i]) dfs(dfs, i, -1);\n\t}\n\n\tif (pos)\
    \ {\n\t\tvector<int> cycle;\n\t\twhile (!st.empty()) {\n\t\t\tauto [top, from]\
    \ = st.top();\n\t\t\tst.pop();\n\t\t\tcycle.push_back(top);\n\t\t\tif (from ==\
    \ *pos) {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\treverse(cycle.begin(), cycle.end());\n\
    \t\treturn cycle;\n\t} else {\n\t\treturn nullopt;\n\t}\n}\n\noptional<vector<int>>\
    \ CycleDetectionVertex(const vector<vector<int>>& graph,\n                   \
    \                        bool directed = true) {\n\tint n = graph.size();\n\t\
    vector<bool> visited(n), finished(n);\n\tstack<int> st;\n\toptional<int> pos;\n\
    \tauto dfs = [&](auto&& f, int v, int prev) -> void {\n\t\tvisited[v] = true;\n\
    \t\tst.push(v);\n\t\tfor (int u : graph[v]) {\n\t\t\tif (!finished[u] && (directed\
    \ || u != prev)) {\n\t\t\t\tif (visited[u]) {\n\t\t\t\t\tpos = u;\n\t\t\t\t\t\
    return;\n\t\t\t\t}\n\t\t\t\tf(f, u, v);\n\t\t\t\tif (pos) return;\n\t\t\t}\n\t\
    \t}\n\t\tfinished[v] = true;\n\t\tst.pop();\n\t};\n\tfor (int i = 0; i < n &&\
    \ !pos; ++i) {\n\t\tif (!visited[i]) dfs(dfs, i, -1);\n\t}\n\n\tif (pos) {\n\t\
    \tvector<int> cycle;\n\t\twhile (!st.empty()) {\n\t\t\tint top = st.top();\n\t\
    \t\tst.pop();\n\t\t\tcycle.push_back(top);\n\t\t\tif (top == *pos) {\n\t\t\t\t\
    break;\n\t\t\t}\n\t\t}\n\t\treverse(cycle.begin(), cycle.end());\n\t\treturn cycle;\n\
    \t} else {\n\t\treturn nullopt;\n\t}\n}\n\noptional<vector<int>> CycleDetectionVertex(int\
    \ n, const vector<pair<int, int>>& edges,\n                                  \
    \         bool directed = true) {\n\tvector<vector<int>> graph(n);\n\tfor (auto\
    \ [u, v] : edges) {\n\t\tgraph[u].push_back(v);\n\t\tif (!directed) graph[v].push_back(u);\n\
    \t}\n\treturn CycleDetectionVertex(graph, directed);\n}\n#line 5 \"Graph/DirectedMinimumSpanningTree.cpp\"\
    \n#include <utility>\n#include <numeric>\nusing namespace std;\n\nclass DirectedMinimumSpanningTree\
    \ {\n\tint n;\n\tEdges edges;\n\npublic:\n\tDirectedMinimumSpanningTree(int _n)\
    \ : n(_n) {}\n\tvoid add_edge(int from, int to, Weight cost) {\n\t\tif (from !=\
    \ to) {\n\t\t\tedges.emplace_back(from, to, cost);\n\t\t}\n\t}\n\tWeight solve(int\
    \ root) {\n\t\tvector<vector<Edge>> in_edges(n);\n\t\tfor (auto edge : edges)\
    \ {\n\t\t\tif (root != edge.to) {\n\t\t\t\tin_edges[edge.to].emplace_back(edge.from,\
    \ edge.cost);\n\t\t\t}\n\t\t}\n\n\t\tvector<pair<int, int>> min_edges;\n\t\tvector<Weight>\
    \ min_costs;\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tif (in_edges[i].empty())\
    \ continue;\n\t\t\tpair<int, int> min_edge;\n\t\t\tWeight min_cost = INF;\n\t\t\
    \tfor (auto edge : in_edges[i]) {\n\t\t\t\tif (min_cost > edge.cost) {\n\t\t\t\
    \t\tmin_edge = pair(edge.to, i);\n\t\t\t\t\tmin_cost = edge.cost;\n\t\t\t\t}\n\
    \t\t\t}\n\t\t\tmin_edges.push_back(min_edge);\n\t\t\tmin_costs.push_back(min_cost);\n\
    \t\t}\n\n\t\tif (auto cycle_opt = CycleDetectionEdge(n, min_edges); cycle_opt)\
    \ {\n\t\t\tconst auto& cycle = cycle_opt.value();\n\n\t\t\tvector<Weight> minus(n);\n\
    \t\t\tvector<bool> on_cycle(n);\n\t\t\tWeight cycle_cost_sum = 0;\n\t\t\tfor (int\
    \ i : cycle) {\n\t\t\t\tminus[min_edges[i].second] = min_costs[i];\n\t\t\t\ton_cycle[min_edges[i].first]\
    \ = true;\n\t\t\t\tcycle_cost_sum += min_costs[i];\n\t\t\t}\n\n\t\t\tint compressed_vertex\
    \ = min_edges[cycle.front()].first;\n\t\t\tDirectedMinimumSpanningTree sub(n);\n\
    \t\t\tfor (size_t i = 0; i < edges.size(); ++i) {\n\t\t\t\tauto edge = edges[i];\n\
    \t\t\t\tif (on_cycle[edge.to]) {\n\t\t\t\t\tif (on_cycle[edge.from]) continue;\n\
    \t\t\t\t\tedge.cost -= minus[edge.to];\n\t\t\t\t\tedge.to = compressed_vertex;\n\
    \t\t\t\t}\n\t\t\t\tif (on_cycle[edge.from]) {\n\t\t\t\t\tedge.from = compressed_vertex;\n\
    \t\t\t\t}\n\t\t\t\tsub.add_edge(edge.from, edge.to, edge.cost);\n\t\t\t}\n\t\t\
    \treturn cycle_cost_sum + sub.solve(root);\n\t\t} else {\n\t\t\treturn accumulate(min_costs.begin(),\
    \ min_costs.end(), Weight(0));\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include \"./Graph/CycleDetection.cpp\"\
    \n#include <vector>\n#include <utility>\n#include <numeric>\nusing namespace std;\n\
    \nclass DirectedMinimumSpanningTree {\n\tint n;\n\tEdges edges;\n\npublic:\n\t\
    DirectedMinimumSpanningTree(int _n) : n(_n) {}\n\tvoid add_edge(int from, int\
    \ to, Weight cost) {\n\t\tif (from != to) {\n\t\t\tedges.emplace_back(from, to,\
    \ cost);\n\t\t}\n\t}\n\tWeight solve(int root) {\n\t\tvector<vector<Edge>> in_edges(n);\n\
    \t\tfor (auto edge : edges) {\n\t\t\tif (root != edge.to) {\n\t\t\t\tin_edges[edge.to].emplace_back(edge.from,\
    \ edge.cost);\n\t\t\t}\n\t\t}\n\n\t\tvector<pair<int, int>> min_edges;\n\t\tvector<Weight>\
    \ min_costs;\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tif (in_edges[i].empty())\
    \ continue;\n\t\t\tpair<int, int> min_edge;\n\t\t\tWeight min_cost = INF;\n\t\t\
    \tfor (auto edge : in_edges[i]) {\n\t\t\t\tif (min_cost > edge.cost) {\n\t\t\t\
    \t\tmin_edge = pair(edge.to, i);\n\t\t\t\t\tmin_cost = edge.cost;\n\t\t\t\t}\n\
    \t\t\t}\n\t\t\tmin_edges.push_back(min_edge);\n\t\t\tmin_costs.push_back(min_cost);\n\
    \t\t}\n\n\t\tif (auto cycle_opt = CycleDetectionEdge(n, min_edges); cycle_opt)\
    \ {\n\t\t\tconst auto& cycle = cycle_opt.value();\n\n\t\t\tvector<Weight> minus(n);\n\
    \t\t\tvector<bool> on_cycle(n);\n\t\t\tWeight cycle_cost_sum = 0;\n\t\t\tfor (int\
    \ i : cycle) {\n\t\t\t\tminus[min_edges[i].second] = min_costs[i];\n\t\t\t\ton_cycle[min_edges[i].first]\
    \ = true;\n\t\t\t\tcycle_cost_sum += min_costs[i];\n\t\t\t}\n\n\t\t\tint compressed_vertex\
    \ = min_edges[cycle.front()].first;\n\t\t\tDirectedMinimumSpanningTree sub(n);\n\
    \t\t\tfor (size_t i = 0; i < edges.size(); ++i) {\n\t\t\t\tauto edge = edges[i];\n\
    \t\t\t\tif (on_cycle[edge.to]) {\n\t\t\t\t\tif (on_cycle[edge.from]) continue;\n\
    \t\t\t\t\tedge.cost -= minus[edge.to];\n\t\t\t\t\tedge.to = compressed_vertex;\n\
    \t\t\t\t}\n\t\t\t\tif (on_cycle[edge.from]) {\n\t\t\t\t\tedge.from = compressed_vertex;\n\
    \t\t\t\t}\n\t\t\t\tsub.add_edge(edge.from, edge.to, edge.cost);\n\t\t\t}\n\t\t\
    \treturn cycle_cost_sum + sub.solve(root);\n\t\t} else {\n\t\t\treturn accumulate(min_costs.begin(),\
    \ min_costs.end(), Weight(0));\n\t\t}\n\t}\n};"
  dependsOn:
  - Graph/GraphTemplate.cpp
  - Graph/CycleDetection.cpp
  isVerificationFile: false
  path: Graph/DirectedMinimumSpanningTree.cpp
  requiredBy: []
  timestamp: '2021-01-14 21:53:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DirectedMinimumSpanningTree.test.cpp
documentation_of: Graph/DirectedMinimumSpanningTree.cpp
layout: document
redirect_from:
- /library/Graph/DirectedMinimumSpanningTree.cpp
- /library/Graph/DirectedMinimumSpanningTree.cpp.html
title: Graph/DirectedMinimumSpanningTree.cpp
---
