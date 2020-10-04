---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.cpp
    title: DataStructure/UnionFind.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/Kruskal.cpp
    title: Graph/Kruskal.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A
  bundledCode: "#line 1 \"test/Kruskal.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A\"\
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
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 2 \"DataStructure/UnionFind.cpp\"\
    \n#include <utility>\nusing namespace std;\n\nclass UnionFind {\n\tvector<int>\
    \ d;\n\tint cnt;\n\npublic:\n\tUnionFind(int n = 0) {\n\t\tinit(n);\n\t}\n\tvoid\
    \ init(int n) {\n\t\td.assign(n, -1);\n\t\tcnt = n;\n\t}\n\tint root(int x) {\n\
    \t\treturn d[x] < 0 ? x : d[x] = root(d[x]);\n\t}\n\tbool unite(int x, int y)\
    \ {\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif (x == y) return false;\n\t\tif\
    \ (d[x] > d[y]) swap(x, y);\n\t\td[x] += d[y];\n\t\td[y] = x;\n\t\tcnt--;\n\t\t\
    return true;\n\t}\n\tbool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\
    \t}\n\tint size(int x) {\n\t\treturn -d[root(x)];\n\t}\n\tint count_components()\
    \ const {\n\t\treturn cnt;\n\t}\n};\n#line 4 \"Graph/Kruskal.cpp\"\n#include <algorithm>\n\
    using namespace std;\n\nWeight Kruskal(int V, Edges& graph) {\n\tsort(graph.begin(),\
    \ graph.end(), [](const Edge2& e1, const Edge2& e2) {\n\t\treturn e1.cost < e2.cost;\n\
    \t});\n\tWeight res = 0;\n\tUnionFind uf(V);\n\tfor (auto e : graph) {\n\t\tif\
    \ (uf.unite(e.from, e.to)) {\n\t\t\tres += e.cost;\n\t\t}\n\t}\n\treturn res;\n\
    }\n#line 4 \"test/Kruskal.test.cpp\"\nusing namespace std;\n\nint main() {\n\t\
    int n, m;\n\tcin >> n >> m;\n\tEdges edges(m);\n\tfor (int i = 0; i < m; ++i)\
    \ {\n\t\tint s, t;\n\t\tWeight d;\n\t\tcin >> s >> t >> d;\n\t\tedges[i] = Edge2(s,\
    \ t, d);\n\t}\n\n\tcout << Kruskal(n, edges) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A\"\
    \n#include \"./../Graph/Kruskal.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tint n, m;\n\tcin >> n >> m;\n\tEdges edges(m);\n\tfor (int i\
    \ = 0; i < m; ++i) {\n\t\tint s, t;\n\t\tWeight d;\n\t\tcin >> s >> t >> d;\n\t\
    \tedges[i] = Edge2(s, t, d);\n\t}\n\n\tcout << Kruskal(n, edges) << '\\n';\n}"
  dependsOn:
  - Graph/Kruskal.cpp
  - Graph/GraphTemplate.cpp
  - DataStructure/UnionFind.cpp
  isVerificationFile: true
  path: test/Kruskal.test.cpp
  requiredBy: []
  timestamp: '2020-10-04 14:21:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Kruskal.test.cpp
layout: document
redirect_from:
- /verify/test/Kruskal.test.cpp
- /verify/test/Kruskal.test.cpp.html
title: test/Kruskal.test.cpp
---
