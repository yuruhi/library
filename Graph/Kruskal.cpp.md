---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.cpp
    title: DataStructure/UnionFind.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Kruskal.test.cpp
    title: test/Kruskal.test.cpp
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
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 3 \"DataStructure/UnionFind.cpp\"\
    \n#include <utility>\nusing namespace std;\n\nclass UnionFind {\n\tvector<int>\
    \ data_m;\n\tint count_components_m;\n\npublic:\n\tUnionFind(int n = 0) {\n\t\t\
    init(n);\n\t}\n\tvoid init(int n) {\n\t\tdata_m.assign(n, -1);\n\t\tcount_components_m\
    \ = n;\n\t}\n\tint root(int x) {\n\t\treturn data_m[x] < 0 ? x : data_m[x] = root(data_m[x]);\n\
    \t}\n\tbool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\t}\n\tbool\
    \ unite(int x, int y) {\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif (x == y) {\n\
    \t\t\treturn false;\n\t\t}\n\t\tif (data_m[x] > data_m[y]) {\n\t\t\tswap(x, y);\n\
    \t\t}\n\t\tdata_m[x] += data_m[y];\n\t\tdata_m[y] = x;\n\t\tcount_components_m--;\n\
    \t\treturn true;\n\t}\n\tint size(int x) {\n\t\treturn -data_m[root(x)];\n\t}\n\
    \tint count_components() const {\n\t\treturn count_components_m;\n\t}\n};\n#line\
    \ 4 \"Graph/Kruskal.cpp\"\n#include <algorithm>\nusing namespace std;\n\nWeight\
    \ Kruskal(int V, Edges& graph) {\n\tsort(graph.begin(), graph.end(), [](const\
    \ Edge2& e1, const Edge2& e2) {\n\t\treturn e1.cost < e2.cost;\n\t});\n\tWeight\
    \ res = 0;\n\tUnionFind uf(V);\n\tfor (auto e : graph) {\n\t\tif (uf.unite(e.from,\
    \ e.to)) {\n\t\t\tres += e.cost;\n\t\t}\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include \"./../DataStructure/UnionFind.cpp\"\
    \n#include <algorithm>\nusing namespace std;\n\nWeight Kruskal(int V, Edges& graph)\
    \ {\n\tsort(graph.begin(), graph.end(), [](const Edge2& e1, const Edge2& e2) {\n\
    \t\treturn e1.cost < e2.cost;\n\t});\n\tWeight res = 0;\n\tUnionFind uf(V);\n\t\
    for (auto e : graph) {\n\t\tif (uf.unite(e.from, e.to)) {\n\t\t\tres += e.cost;\n\
    \t\t}\n\t}\n\treturn res;\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  - DataStructure/UnionFind.cpp
  isVerificationFile: false
  path: Graph/Kruskal.cpp
  requiredBy: []
  timestamp: '2020-11-15 19:06:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Kruskal.test.cpp
documentation_of: Graph/Kruskal.cpp
layout: document
redirect_from:
- /library/Graph/Kruskal.cpp
- /library/Graph/Kruskal.cpp.html
title: Graph/Kruskal.cpp
---
