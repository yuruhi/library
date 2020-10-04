---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/LCA.cpp
    title: Graph/LCA.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/LCA.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
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
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 4 \"Graph/LCA.cpp\"\
    \n#include <utility>\n#include <cmath>\nusing namespace std;\n\nclass LCA {\n\t\
    const int V, LOG;\n\tvector<int> dist;\n\tvector<vector<int>> table;\n\tvoid dfs(const\
    \ Graph& g, int v, int p, int d) {\n\t\ttable[0][v] = p;\n\t\tdist[v] = d;\n\t\
    \tfor (auto e : g[v])\n\t\t\tif (e.to != p) {\n\t\t\t\tdfs(g, e.to, v, d + 1);\n\
    \t\t\t}\n\t}\n\npublic:\n\tLCA(const Graph& g, const int root) : V(g.size()),\
    \ LOG(log2(V) + 1), dist(V), table(LOG, vector<int>(V)) {\n\t\tdfs(g, root, -1,\
    \ 0);\n\t\tfor (int k = 0; k + 1 < LOG; ++k) {\n\t\t\tfor (int v = 0; v < V; ++v)\
    \ {\n\t\t\t\tif (table[k][v] < 0) {\n\t\t\t\t\ttable[k + 1][v] = -1;\n\t\t\t\t\
    } else {\n\t\t\t\t\ttable[k + 1][v] = table[k][table[k][v]];\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t}\n\tint operator()(int u, int v) {\n\t\tif (dist[u] > dist[v]) swap(u,\
    \ v);\n\t\tfor (int k = 0; k < LOG; ++k) {\n\t\t\tif ((dist[v] - dist[u]) >> k\
    \ & 1) {\n\t\t\t\tv = table[k][v];\n\t\t\t}\n\t\t}\n\t\tif (u == v) return u;\n\
    \t\tfor (int k = LOG - 1; k >= 0; --k) {\n\t\t\tif (table[k][u] != table[k][v])\
    \ {\n\t\t\t\tu = table[k][u];\n\t\t\t\tv = table[k][v];\n\t\t\t}\n\t\t}\n\t\t\
    return table[0][u];\n\t}\n};\n#line 4 \"test/LCA.test.cpp\"\nusing namespace std;\n\
    \nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tint\
    \ n, q;\n\tcin >> n >> q;\n\tGraph g(n);\n\tfor (int i = 1; i < n; ++i) {\n\t\t\
    int p;\n\t\tcin >> p;\n\t\tg[i].emplace_back(p, 1);\n\t\tg[p].emplace_back(i,\
    \ 1);\n\t}\n\n\tLCA lca(g, 0);\n\twhile (q--) {\n\t\tint u, v;\n\t\tcin >> u >>\
    \ v;\n\t\tcout << lca(u, v) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"./../Graph/LCA.cpp\"\
    \n#include <iostream>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n, q;\n\tcin >> n >> q;\n\tGraph g(n);\n\
    \tfor (int i = 1; i < n; ++i) {\n\t\tint p;\n\t\tcin >> p;\n\t\tg[i].emplace_back(p,\
    \ 1);\n\t\tg[p].emplace_back(i, 1);\n\t}\n\n\tLCA lca(g, 0);\n\twhile (q--) {\n\
    \t\tint u, v;\n\t\tcin >> u >> v;\n\t\tcout << lca(u, v) << '\\n';\n\t}\n}"
  dependsOn:
  - Graph/LCA.cpp
  - Graph/GraphTemplate.cpp
  isVerificationFile: true
  path: test/LCA.test.cpp
  requiredBy: []
  timestamp: '2020-10-04 14:21:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LCA.test.cpp
layout: document
redirect_from:
- /verify/test/LCA.test.cpp
- /verify/test/LCA.test.cpp.html
title: test/LCA.test.cpp
---
