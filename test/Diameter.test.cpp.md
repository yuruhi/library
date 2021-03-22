---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Diameter.cpp
    title: Graph/Diameter.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/DiameterPath.cpp
    title: Graph/DiameterPath.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/Diameter.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
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
    Graph/Diameter.cpp\"\n#include <tuple>\n\nstd::tuple<Weight, int, int> Diameter(const\
    \ Graph& graph) {\n\tauto dfs = [&](auto&& f, int v, int p, Weight depth) -> std::pair<Weight,\
    \ int> {\n\t\tstd::pair<Weight, int> result(depth, v);\n\t\tfor (auto e : graph[v])\
    \ {\n\t\t\tif (e.to != p) {\n\t\t\t\tauto tmp = f(f, e.to, v, depth + e.cost);\n\
    \t\t\t\tif (tmp.first > result.first) result = tmp;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ result;\n\t};\n\tauto d1 = dfs(dfs, 0, -1, 0);\n\tauto d2 = dfs(dfs, d1.second,\
    \ -1, 0);\n\treturn {d2.first, d1.second, d2.second};\n}\nWeight DiameterLength(const\
    \ Graph& graph) {\n\treturn std::get<0>(Diameter(graph));\n}\n#line 4 \"Graph/DiameterPath.cpp\"\
    \n#include <algorithm>\n#line 7 \"Graph/DiameterPath.cpp\"\n#include <functional>\n\
    \nstd::tuple<Weight, std::vector<int>> DiameterPath(const Graph& graph) {\n\t\
    int n = graph.size();\n\tstd::vector<Weight> dist0(n);\n\tauto dfs = [&](auto\
    \ self, int v, int p, Weight d) -> void {\n\t\tdist0[v] = d;\n\t\tfor (const auto&\
    \ u : graph[v])\n\t\t\tif (u.to != p) {\n\t\t\t\tself(self, u.to, v, d + u.cost);\n\
    \t\t\t}\n\t};\n\tdfs(dfs, 0, -1, 0);\n\n\tint s = std::max_element(dist0.begin(),\
    \ dist0.end()) - dist0.begin();\n\tstd::vector<Weight> dist(n);\n\tstd::vector<int>\
    \ par(n);\n\tauto dfs2 = [&](auto self, int v, int p, Weight d) -> void {\n\t\t\
    dist[v] = d;\n\t\tpar[v] = p;\n\t\tfor (const auto& u : graph[v]) {\n\t\t\tif\
    \ (u.to != p) {\n\t\t\t\tself(self, u.to, v, d + u.cost);\n\t\t\t}\n\t\t}\n\t\
    };\n\tdfs2(dfs2, s, -1, 0);\n\tauto t = std::max_element(dist.begin(), dist.end());\n\
    \tstd::vector<int> path{static_cast<int>(t - dist.begin())};\n\tfor (int p = 0;\
    \ (p = par[path.back()]) != -1;) {\n\t\tpath.push_back(p);\n\t}\n\tstd::reverse(path.begin(),\
    \ path.end());\n\treturn {*t, path};\n}\n#line 5 \"test/Diameter.test.cpp\"\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios::sync_with_stdio(false);\n\
    \tint n;\n\tcin >> n;\n\tGraph g(n);\n\tfor (int i = 0; i < n - 1; i++) {\n\t\t\
    int a, b;\n\t\tWeight c;\n\t\tcin >> a >> b >> c;\n\t\tg[a].emplace_back(b, c);\n\
    \t\tg[b].emplace_back(a, c);\n\t}\n\n\tauto [dist, u, v] = Diameter(g);\n\tauto\
    \ [_dist, path] = DiameterPath(g);\n\tcout << dist << ' ' << path.size() << '\\\
    n';\n\tfor (size_t i = 0; i < path.size(); i++) {\n\t\tcout << path[i] << (i !=\
    \ path.size() - 1 ? ' ' : '\\n');\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#include\
    \ \"./../Graph/Diameter.cpp\"\n#include \"./../Graph/DiameterPath.cpp\"\n#include\
    \ <iostream>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios::sync_with_stdio(false);\n\
    \tint n;\n\tcin >> n;\n\tGraph g(n);\n\tfor (int i = 0; i < n - 1; i++) {\n\t\t\
    int a, b;\n\t\tWeight c;\n\t\tcin >> a >> b >> c;\n\t\tg[a].emplace_back(b, c);\n\
    \t\tg[b].emplace_back(a, c);\n\t}\n\n\tauto [dist, u, v] = Diameter(g);\n\tauto\
    \ [_dist, path] = DiameterPath(g);\n\tcout << dist << ' ' << path.size() << '\\\
    n';\n\tfor (size_t i = 0; i < path.size(); i++) {\n\t\tcout << path[i] << (i !=\
    \ path.size() - 1 ? ' ' : '\\n');\n\t}\n}"
  dependsOn:
  - Graph/Diameter.cpp
  - Graph/GraphTemplate.cpp
  - Graph/DiameterPath.cpp
  isVerificationFile: true
  path: test/Diameter.test.cpp
  requiredBy: []
  timestamp: '2021-03-22 17:28:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Diameter.test.cpp
layout: document
redirect_from:
- /verify/test/Diameter.test.cpp
- /verify/test/Diameter.test.cpp.html
title: test/Diameter.test.cpp
---
