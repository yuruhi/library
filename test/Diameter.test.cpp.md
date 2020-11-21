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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/Diameter.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
    \n#line 2 \"Graph/GraphTemplate.cpp\"\n#include <limits>\n#include <vector>\n\
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
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 3 \"Graph/Diameter.cpp\"\
    \n#include <utility>\n#include <tuple>\nusing namespace std;\n\ntuple<Weight,\
    \ int, int> Diameter(const Graph& graph) {\n\tauto dfs = [&](auto&& f, int v,\
    \ int p, Weight depth) -> pair<Weight, int> {\n\t\tpair<Weight, int> res(depth,\
    \ v);\n\t\tfor (auto e : graph[v]) {\n\t\t\tif (e.to != p) {\n\t\t\t\tauto res2\
    \ = f(f, e.to, v, depth + e.cost);\n\t\t\t\tif (res2.first > res.first) res =\
    \ res2;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t};\n\tauto d1 = dfs(dfs, 0, -1, 0);\n\
    \tauto d2 = dfs(dfs, d1.second, -1, 0);\n\treturn {d2.first, d1.second, d2.second};\n\
    }\n#line 4 \"Graph/DiameterPath.cpp\"\n#include <algorithm>\n#line 7 \"Graph/DiameterPath.cpp\"\
    \n#include <functional>\nusing namespace std;\n\ntuple<Weight, vector<int>> DiameterPath(const\
    \ Graph& graph) {\n\tint n = graph.size();\n\tvector<Weight> dist0(n);\n\tfunction<void(int,\
    \ int, Weight)> dfs = [&](int v, int p, Weight d) {\n\t\tdist0[v] = d;\n\t\tfor\
    \ (const auto& u : graph[v])\n\t\t\tif (u.to != p) {\n\t\t\t\tdfs(u.to, v, d +\
    \ u.cost);\n\t\t\t}\n\t};\n\tdfs(0, -1, 0);\n\n\tint s = max_element(dist0.begin(),\
    \ dist0.end()) - dist0.begin();\n\tvector<Weight> dist(n);\n\tvector<int> par(n);\n\
    \tfunction<void(int, int, Weight)> dfs2 = [&](int v, int p, Weight d) {\n\t\t\
    dist[v] = d;\n\t\tpar[v] = p;\n\t\tfor (const auto& u : graph[v])\n\t\t\tif (u.to\
    \ != p) {\n\t\t\t\tdfs2(u.to, v, d + u.cost);\n\t\t\t}\n\t};\n\tdfs2(s, -1, 0);\n\
    \tauto t = max_element(dist.begin(), dist.end());\n\tvector<int> path{t - dist.begin()};\n\
    \tfor (int p = 0; (p = par[path.back()]) != -1;) {\n\t\tpath.push_back(p);\n\t\
    }\n\treverse(path.begin(), path.end());\n\treturn {*t, path};\n}\n#line 5 \"test/Diameter.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios::sync_with_stdio(false);\n\
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
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Diameter.test.cpp
layout: document
redirect_from:
- /verify/test/Diameter.test.cpp
- /verify/test/Diameter.test.cpp.html
title: test/Diameter.test.cpp
---
