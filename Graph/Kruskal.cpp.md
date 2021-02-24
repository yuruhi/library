---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/UnionFind.cpp
    title: DataStructure/UnionFind.cpp
  - icon: ':question:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/Kruskal.test.cpp
    title: test/Kruskal.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \n#include <utility>\n\nclass UnionFind {\n\tstd::size_t n;\n\tstd::vector<int>\
    \ data_m;\n\tint count_components_m;\n\npublic:\n\tUnionFind(int _n = 0) {\n\t\
    \tinit(_n);\n\t}\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\tdata_m.assign(n, -1);\n\
    \t\tcount_components_m = n;\n\t}\n\tint root(int x) {\n\t\treturn data_m[x] <\
    \ 0 ? x : data_m[x] = root(data_m[x]);\n\t}\n\tbool same(int x, int y) {\n\t\t\
    return root(x) == root(y);\n\t}\n\tbool unite(int x, int y) {\n\t\tx = root(x);\n\
    \t\ty = root(y);\n\t\tif (x == y) {\n\t\t\treturn false;\n\t\t}\n\t\tif (data_m[x]\
    \ > data_m[y]) {\n\t\t\tstd::swap(x, y);\n\t\t}\n\t\tdata_m[x] += data_m[y];\n\
    \t\tdata_m[y] = x;\n\t\tcount_components_m--;\n\t\treturn true;\n\t}\n\tint size(int\
    \ x) {\n\t\treturn -data_m[root(x)];\n\t}\n\tint count_components() const {\n\t\
    \treturn count_components_m;\n\t}\n\tstd::vector<int> roots() {\n\t\tstd::vector<int>\
    \ result;\n\t\tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\tif (root(i) == i)\
    \ result.push_back(i);\n\t\t}\n\t\treturn result;\n\t}\n\tstd::vector<std::vector<int>>\
    \ groups() {\n\t\tstd::vector<int> root_buf(n), group_size(n);\n\t\tfor (std::size_t\
    \ i = 0; i < n; i++) {\n\t\t\troot_buf[i] = root(i);\n\t\t\tgroup_size[root_buf[i]]++;\n\
    \t\t}\n\t\tstd::vector<std::vector<int>> result(n);\n\t\tfor (std::size_t i =\
    \ 0; i < n; i++) {\n\t\t\tresult[i].reserve(group_size[i]);\n\t\t}\n\t\tfor (std::size_t\
    \ i = 0; i < n; i++) {\n\t\t\tresult[root_buf[i]].push_back(i);\n\t\t}\n\t\tresult.erase(std::remove_if(result.begin(),\
    \ result.end(),\n\t\t                            [&](const std::vector<int>& v)\
    \ { return v.empty(); }),\n\t\t             result.end());\n\t\treturn result;\n\
    \t}\n};\n#line 4 \"Graph/Kruskal.cpp\"\n#include <algorithm>\nusing namespace\
    \ std;\n\nWeight Kruskal(int V, Edges& graph) {\n\tsort(graph.begin(), graph.end(),\n\
    \t     [](const Edge2& e1, const Edge2& e2) { return e1.cost < e2.cost; });\n\t\
    Weight result = 0;\n\tUnionFind uf(V);\n\tfor (auto e : graph) {\n\t\tif (uf.unite(e.from,\
    \ e.to)) {\n\t\t\tresult += e.cost;\n\t\t}\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include \"./../DataStructure/UnionFind.cpp\"\
    \n#include <algorithm>\nusing namespace std;\n\nWeight Kruskal(int V, Edges& graph)\
    \ {\n\tsort(graph.begin(), graph.end(),\n\t     [](const Edge2& e1, const Edge2&\
    \ e2) { return e1.cost < e2.cost; });\n\tWeight result = 0;\n\tUnionFind uf(V);\n\
    \tfor (auto e : graph) {\n\t\tif (uf.unite(e.from, e.to)) {\n\t\t\tresult += e.cost;\n\
    \t\t}\n\t}\n\treturn result;\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  - DataStructure/UnionFind.cpp
  isVerificationFile: false
  path: Graph/Kruskal.cpp
  requiredBy: []
  timestamp: '2021-02-24 20:48:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/Kruskal.test.cpp
documentation_of: Graph/Kruskal.cpp
layout: document
redirect_from:
- /library/Graph/Kruskal.cpp
- /library/Graph/Kruskal.cpp.html
title: Graph/Kruskal.cpp
---
