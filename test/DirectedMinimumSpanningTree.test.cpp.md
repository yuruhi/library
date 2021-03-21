---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/CycleDetection.cpp
    title: Graph/CycleDetection.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/DirectedMinimumSpanningTree.cpp
    title: Graph/DirectedMinimumSpanningTree.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_B
  bundledCode: "#line 1 \"test/DirectedMinimumSpanningTree.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_B\"\n#line\
    \ 2 \"Graph/GraphTemplate.cpp\"\n#include <limits>\n#include <vector>\n#include\
    \ <iostream>\n\nusing Weight = long long;\nconstexpr Weight INF = std::numeric_limits<Weight>::max();\n\
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
    #line 3 \"Graph/CycleDetection.cpp\"\n#include <stack>\n#include <algorithm>\n\
    #include <optional>\n\nstd::optional<std::vector<int>> CycleDetectionEdge(\n \
    \   int n, const std::vector<std::pair<int, int>>& edges, bool directed = true)\
    \ {\n\tstd::vector<std::vector<std::pair<int, int>>> graph(n);\n\tfor (std::size_t\
    \ i = 0; i < edges.size(); ++i) {\n\t\tauto [u, v] = edges[i];\n\t\tgraph[u].emplace_back(v,\
    \ i);\n\t\tif (!directed) graph[v].emplace_back(u, i);\n\t}\n\tstd::vector<bool>\
    \ visited(n), finished(n);\n\tstd::stack<std::pair<int, int>> st;\n\tstd::optional<int>\
    \ pos;\n\tauto dfs = [&](auto&& f, int v, int prev_edge) -> void {\n\t\tvisited[v]\
    \ = true;\n\t\tfor (auto [u, i] : graph[v]) {\n\t\t\tif (!finished[u] && (directed\
    \ || i != prev_edge)) {\n\t\t\t\tst.emplace(i, v);\n\t\t\t\tif (visited[u]) {\n\
    \t\t\t\t\tpos = u;\n\t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t\tf(f, u, i);\n\t\t\t\t\
    if (pos) return;\n\t\t\t\tst.pop();\n\t\t\t}\n\t\t}\n\t\tfinished[v] = true;\n\
    \t};\n\tfor (int i = 0; i < n && !pos; ++i) {\n\t\tif (!visited[i]) dfs(dfs, i,\
    \ -1);\n\t}\n\n\tif (pos) {\n\t\tstd::vector<int> cycle;\n\t\twhile (!st.empty())\
    \ {\n\t\t\tauto [top, from] = st.top();\n\t\t\tst.pop();\n\t\t\tcycle.push_back(top);\n\
    \t\t\tif (from == *pos) {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tstd::reverse(cycle.begin(),\
    \ cycle.end());\n\t\treturn cycle;\n\t} else {\n\t\treturn std::nullopt;\n\t}\n\
    }\n\nstd::optional<std::vector<int>> CycleDetectionVertex(\n    const std::vector<std::vector<int>>&\
    \ graph, bool directed = true) {\n\tint n = graph.size();\n\tstd::vector<bool>\
    \ visited(n), finished(n);\n\tstd::stack<int> st;\n\tstd::optional<int> pos;\n\
    \tauto dfs = [&](auto&& f, int v, int prev) -> void {\n\t\tvisited[v] = true;\n\
    \t\tst.push(v);\n\t\tfor (int u : graph[v]) {\n\t\t\tif (!finished[u] && (directed\
    \ || u != prev)) {\n\t\t\t\tif (visited[u]) {\n\t\t\t\t\tpos = u;\n\t\t\t\t\t\
    return;\n\t\t\t\t}\n\t\t\t\tf(f, u, v);\n\t\t\t\tif (pos) return;\n\t\t\t}\n\t\
    \t}\n\t\tfinished[v] = true;\n\t\tst.pop();\n\t};\n\tfor (int i = 0; i < n &&\
    \ !pos; ++i) {\n\t\tif (!visited[i]) dfs(dfs, i, -1);\n\t}\n\n\tif (pos) {\n\t\
    \tstd::vector<int> cycle;\n\t\twhile (!st.empty()) {\n\t\t\tint top = st.top();\n\
    \t\t\tst.pop();\n\t\t\tcycle.push_back(top);\n\t\t\tif (top == *pos) {\n\t\t\t\
    \tbreak;\n\t\t\t}\n\t\t}\n\t\tstd::reverse(cycle.begin(), cycle.end());\n\t\t\
    return cycle;\n\t} else {\n\t\treturn std::nullopt;\n\t}\n}\n\nauto CycleDetectionVertex(int\
    \ n, const std::vector<std::pair<int, int>>& edges,\n                        \
    \  bool directed = true) {\n\tstd::vector<std::vector<int>> graph(n);\n\tfor (auto\
    \ [u, v] : edges) {\n\t\tgraph[u].push_back(v);\n\t\tif (!directed) graph[v].push_back(u);\n\
    \t}\n\treturn CycleDetectionVertex(graph, directed);\n}\n#line 5 \"Graph/DirectedMinimumSpanningTree.cpp\"\
    \n#include <utility>\n#include <numeric>\n\nclass DirectedMinimumSpanningTree\
    \ {\n\tint n;\n\tEdges edges;\n\npublic:\n\tDirectedMinimumSpanningTree(int _n)\
    \ : n(_n) {}\n\tvoid add_edge(int from, int to, Weight cost) {\n\t\tif (from !=\
    \ to) {\n\t\t\tedges.emplace_back(from, to, cost);\n\t\t}\n\t}\n\tWeight solve(int\
    \ root) {\n\t\tstd::vector<std::vector<Edge>> in_edges(n);\n\t\tfor (auto edge\
    \ : edges) {\n\t\t\tif (root != edge.to) {\n\t\t\t\tin_edges[edge.to].emplace_back(edge.from,\
    \ edge.cost);\n\t\t\t}\n\t\t}\n\n\t\tstd::vector<std::pair<int, int>> min_edges;\n\
    \t\tstd::vector<Weight> min_costs;\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\t\
    if (in_edges[i].empty()) continue;\n\t\t\tstd::pair<int, int> min_edge;\n\t\t\t\
    Weight min_cost = INF;\n\t\t\tfor (auto edge : in_edges[i]) {\n\t\t\t\tif (min_cost\
    \ > edge.cost) {\n\t\t\t\t\tmin_edge = std::pair(edge.to, i);\n\t\t\t\t\tmin_cost\
    \ = edge.cost;\n\t\t\t\t}\n\t\t\t}\n\t\t\tmin_edges.push_back(min_edge);\n\t\t\
    \tmin_costs.push_back(min_cost);\n\t\t}\n\n\t\tif (auto cycle_opt = CycleDetectionEdge(n,\
    \ min_edges); cycle_opt) {\n\t\t\tconst auto& cycle = cycle_opt.value();\n\n\t\
    \t\tstd::vector<Weight> minus(n);\n\t\t\tstd::vector<bool> on_cycle(n);\n\t\t\t\
    Weight cycle_cost_sum = 0;\n\t\t\tfor (int i : cycle) {\n\t\t\t\tminus[min_edges[i].second]\
    \ = min_costs[i];\n\t\t\t\ton_cycle[min_edges[i].first] = true;\n\t\t\t\tcycle_cost_sum\
    \ += min_costs[i];\n\t\t\t}\n\n\t\t\tint compressed_vertex = min_edges[cycle.front()].first;\n\
    \t\t\tDirectedMinimumSpanningTree sub(n);\n\t\t\tfor (std::size_t i = 0; i < edges.size();\
    \ ++i) {\n\t\t\t\tauto edge = edges[i];\n\t\t\t\tif (on_cycle[edge.to]) {\n\t\t\
    \t\t\tif (on_cycle[edge.from]) continue;\n\t\t\t\t\tedge.cost -= minus[edge.to];\n\
    \t\t\t\t\tedge.to = compressed_vertex;\n\t\t\t\t}\n\t\t\t\tif (on_cycle[edge.from])\
    \ {\n\t\t\t\t\tedge.from = compressed_vertex;\n\t\t\t\t}\n\t\t\t\tsub.add_edge(edge.from,\
    \ edge.to, edge.cost);\n\t\t\t}\n\t\t\treturn cycle_cost_sum + sub.solve(root);\n\
    \t\t} else {\n\t\t\treturn std::accumulate(min_costs.begin(), min_costs.end(),\
    \ Weight(0));\n\t\t}\n\t}\n};\n#line 4 \"test/DirectedMinimumSpanningTree.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tint n, m, r;\n\tcin >> n >> m >> r;\n\tDirectedMinimumSpanningTree dmst(n);\n\
    \tfor (int i = 0; i < m; ++i) {\n\t\tint s, t;\n\t\tWeight cost;\n\t\tcin >> s\
    \ >> t >> cost;\n\t\tdmst.add_edge(s, t, cost);\n\t}\n\tcout << dmst.solve(r)\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_B\"\
    \n#include \"./../Graph/DirectedMinimumSpanningTree.cpp\"\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tint n, m, r;\n\tcin >> n >> m >> r;\n\tDirectedMinimumSpanningTree dmst(n);\n\
    \tfor (int i = 0; i < m; ++i) {\n\t\tint s, t;\n\t\tWeight cost;\n\t\tcin >> s\
    \ >> t >> cost;\n\t\tdmst.add_edge(s, t, cost);\n\t}\n\tcout << dmst.solve(r)\
    \ << '\\n';\n}"
  dependsOn:
  - Graph/DirectedMinimumSpanningTree.cpp
  - Graph/GraphTemplate.cpp
  - Graph/CycleDetection.cpp
  isVerificationFile: true
  path: test/DirectedMinimumSpanningTree.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 10:20:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DirectedMinimumSpanningTree.test.cpp
layout: document
redirect_from:
- /verify/test/DirectedMinimumSpanningTree.test.cpp
- /verify/test/DirectedMinimumSpanningTree.test.cpp.html
title: test/DirectedMinimumSpanningTree.test.cpp
---
