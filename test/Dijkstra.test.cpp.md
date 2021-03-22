---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Dijkstra.cpp
    title: Graph/Dijkstra.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
  bundledCode: "#line 1 \"test/Dijkstra.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\"\
    \n#line 2 \"Graph/GraphTemplate.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <iostream>\n#include <limits>\n\nusing Weight = long long;\nconstexpr\
    \ Weight INF = std::numeric_limits<Weight>::max();\nstruct Edge {\n\tint to;\n\
    \tWeight cost;\n\tEdge() : to(-1), cost(-1) {}\n\tEdge(int _to, Weight _cost =\
    \ 1) : to(_to), cost(_cost) {}\n\tfriend bool operator<(const Edge& e1, const\
    \ Edge& e2) {\n\t\treturn e1.cost < e2.cost;\n\t}\n\tfriend bool operator>(const\
    \ Edge& e1, const Edge& e2) {\n\t\treturn e1.cost > e2.cost;\n\t}\n\tfriend std::ostream&\
    \ operator<<(std::ostream& os, const Edge& e) {\n\t\treturn os << \"->\" << e.to\
    \ << '(' << e.cost << ')';\n\t}\n};\nusing UnWeightedGraph = std::vector<std::vector<int>>;\n\
    using Graph = std::vector<std::vector<Edge>>;\nstruct Edge2 {\n\tint from, to;\n\
    \tWeight cost;\n\tEdge2() : from(-1), to(-1), cost(0) {}\n\tEdge2(int _from, int\
    \ _to, Weight _cost) : from(_from), to(_to), cost(_cost) {}\n\tfriend bool operator<(const\
    \ Edge2& e1, const Edge2& e2) {\n\t\treturn e1.cost < e2.cost;\n\t}\n\tfriend\
    \ bool operator>(const Edge2& e1, const Edge2& e2) {\n\t\treturn e1.cost > e2.cost;\n\
    \t}\n\tfriend std::ostream& operator<<(std::ostream& os, const Edge2& e) {\n\t\
    \treturn os << e.from << \"->\" << e.to << '(' << e.cost << ')';\n\t}\n};\nusing\
    \ UnWeightedEdges = std::vector<std::pair<int, int>>;\nusing Edges = std::vector<Edge2>;\n\
    using Matrix = std::vector<std::vector<Weight>>;\n\nauto add_edge(UnWeightedGraph&\
    \ graph, int v, int u) {\n\tgraph[v].push_back(u);\n\tgraph[u].push_back(v);\n\
    }\nauto add_edge(Graph& graph, int v, int u, Weight cost) {\n\tgraph[v].emplace_back(u,\
    \ cost);\n\tgraph[u].emplace_back(v, cost);\n}\nauto to_graph(const UnWeightedGraph&\
    \ graph, Weight cost = 1) {\n\tGraph result(graph.size());\n\tfor (std::size_t\
    \ i = 0; i < graph.size(); ++i) {\n\t\tfor (int v : graph[i]) {\n\t\t\tresult[i].emplace_back(v,\
    \ cost);\n\t\t}\n\t}\n\treturn result;\n}\nauto to_unweighted_graph(const Graph&\
    \ graph) {\n\tUnWeightedGraph result(graph.size());\n\tfor (std::size_t i = 0;\
    \ i < graph.size(); ++i) {\n\t\tfor (auto [v, cost] : graph[i]) {\n\t\t\tresult[i].push_back(v);\n\
    \t\t}\n\t}\n\treturn result;\n}\nauto to_edges(const UnWeightedGraph& graph, bool\
    \ unique = false) {\n\tstd::vector<std::pair<int, int>> edges;\n\tfor (std::size_t\
    \ i = 0; i < graph.size(); ++i) {\n\t\tfor (int v : graph[i]) {\n\t\t\tif (!unique\
    \ || static_cast<int>(i) < v) edges.emplace_back(i, v);\n\t\t}\n\t}\n\treturn\
    \ edges;\n}\nauto to_edges(const Graph& graph) {\n\tEdges edges;\n\tfor (std::size_t\
    \ i = 0; i < graph.size(); ++i) {\n\t\tfor (auto [v, cost] : graph[i]) {\n\t\t\
    \tedges.emplace_back(i, v, cost);\n\t\t}\n\t}\n\treturn edges;\n}\n#line 4 \"\
    Graph/Dijkstra.cpp\"\n#include <queue>\n#include <functional>\n#include <cassert>\n\
    \nstd::vector<Weight> Dijkstra(const Graph& graph, int s) {\n\tassert(0 <= s &&\
    \ s <= static_cast<int>(graph.size()));\n\tstd::vector<Weight> dist(graph.size(),\
    \ INF);\n\tdist[s] = 0;\n\tstd::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>>\
    \ pq;\n\tpq.emplace(s, 0);\n\twhile (!pq.empty()) {\n\t\tEdge p = pq.top();\n\t\
    \tpq.pop();\n\t\tint v = p.to;\n\t\tif (dist[v] < p.cost) continue;\n\t\tfor (auto\
    \ e : graph[v]) {\n\t\t\tif (dist[e.to] > dist[v] + e.cost) {\n\t\t\t\tdist[e.to]\
    \ = dist[v] + e.cost;\n\t\t\t\tpq.emplace(e.to, dist[e.to]);\n\t\t\t}\n\t\t}\n\
    \t}\n\treturn dist;\n}\nWeight Dijkstra(const Graph& graph, int s, int t) {\n\t\
    assert(0 <= s && s <= static_cast<int>(graph.size()));\n\tassert(0 <= t && t <=\
    \ static_cast<int>(graph.size()));\n\tstd::vector<Weight> dist(graph.size(), INF);\n\
    \tdist[s] = 0;\n\tstd::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>>\
    \ pq;\n\tpq.emplace(s, 0);\n\twhile (!pq.empty()) {\n\t\tEdge p = pq.top();\n\t\
    \tpq.pop();\n\t\tint v = p.to;\n\t\tif (v == t) return dist[t];\n\t\tif (dist[v]\
    \ < p.cost) continue;\n\t\tfor (auto e : graph[v]) {\n\t\t\tif (dist[e.to] > dist[v]\
    \ + e.cost) {\n\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\tpq.emplace(e.to,\
    \ dist[e.to]);\n\t\t\t}\n\t\t}\n\t}\n\treturn dist[t];\n}\n#line 4 \"test/Dijkstra.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, m, s;\n\tcin >> n >> m >> s;\n\tGraph g(n);\n\tfor (int i = 0; i < m;\
    \ ++i) {\n\t\tint s, t;\n\t\tWeight d;\n\t\tcin >> s >> t >> d;\n\t\tg[s].emplace_back(t,\
    \ d);\n\t}\n\n\tauto dist = Dijkstra(g, s);\n\tfor (int i = 0; i < n; ++i) {\n\
    \t\tif (dist[i] < INF) {\n\t\t\tcout << dist[i] << '\\n';\n\t\t} else {\n\t\t\t\
    cout << \"INF\\n\";\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\"\
    \n#include \"./../Graph/Dijkstra.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tint\
    \ n, m, s;\n\tcin >> n >> m >> s;\n\tGraph g(n);\n\tfor (int i = 0; i < m; ++i)\
    \ {\n\t\tint s, t;\n\t\tWeight d;\n\t\tcin >> s >> t >> d;\n\t\tg[s].emplace_back(t,\
    \ d);\n\t}\n\n\tauto dist = Dijkstra(g, s);\n\tfor (int i = 0; i < n; ++i) {\n\
    \t\tif (dist[i] < INF) {\n\t\t\tcout << dist[i] << '\\n';\n\t\t} else {\n\t\t\t\
    cout << \"INF\\n\";\n\t\t}\n\t}\n}"
  dependsOn:
  - Graph/Dijkstra.cpp
  - Graph/GraphTemplate.cpp
  isVerificationFile: true
  path: test/Dijkstra.test.cpp
  requiredBy: []
  timestamp: '2021-03-22 17:28:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/Dijkstra.test.cpp
- /verify/test/Dijkstra.test.cpp.html
title: test/Dijkstra.test.cpp
---
