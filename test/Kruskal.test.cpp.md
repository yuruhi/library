---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.cpp
    title: DataStructure/UnionFind.cpp
  - icon: ':question:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/Kruskal.cpp
    title: Graph/Kruskal.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A
  bundledCode: "#line 1 \"test/Kruskal.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A\"\
    \n#line 2 \"Graph/GraphTemplate.cpp\"\n#include <limits>\n#include <vector>\n\
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
    #line 3 \"DataStructure/UnionFind.cpp\"\n#include <utility>\n#include <algorithm>\n\
    \nclass UnionFind {\n\tstd::size_t n;\n\tstd::vector<int> data_m;\n\tint count_components_m;\n\
    \npublic:\n\tUnionFind(int _n = 0) {\n\t\tinit(_n);\n\t}\n\tvoid init(int _n)\
    \ {\n\t\tn = _n;\n\t\tdata_m.assign(n, -1);\n\t\tcount_components_m = n;\n\t}\n\
    \tint root(int x) {\n\t\treturn data_m[x] < 0 ? x : data_m[x] = root(data_m[x]);\n\
    \t}\n\tbool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\t}\n\tbool\
    \ unite(int x, int y) {\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif (x == y) {\n\
    \t\t\treturn false;\n\t\t}\n\t\tif (data_m[x] > data_m[y]) {\n\t\t\tstd::swap(x,\
    \ y);\n\t\t}\n\t\tdata_m[x] += data_m[y];\n\t\tdata_m[y] = x;\n\t\tcount_components_m--;\n\
    \t\treturn true;\n\t}\n\tint size(int x) {\n\t\treturn -data_m[root(x)];\n\t}\n\
    \tint count_components() const {\n\t\treturn count_components_m;\n\t}\n\tstd::vector<int>\
    \ roots() {\n\t\tstd::vector<int> result;\n\t\tfor (std::size_t i = 0; i < n;\
    \ ++i) {\n\t\t\tif (root(i) == static_cast<int>(i)) result.push_back(i);\n\t\t\
    }\n\t\treturn result;\n\t}\n\tstd::vector<std::vector<int>> groups() {\n\t\tstd::vector<int>\
    \ root_buf(n), group_size(n);\n\t\tfor (std::size_t i = 0; i < n; i++) {\n\t\t\
    \troot_buf[i] = root(i);\n\t\t\tgroup_size[root_buf[i]]++;\n\t\t}\n\t\tstd::vector<std::vector<int>>\
    \ result(n);\n\t\tfor (std::size_t i = 0; i < n; i++) {\n\t\t\tresult[i].reserve(group_size[i]);\n\
    \t\t}\n\t\tfor (std::size_t i = 0; i < n; i++) {\n\t\t\tresult[root_buf[i]].push_back(i);\n\
    \t\t}\n\t\tresult.erase(std::remove_if(result.begin(), result.end(),\n\t\t   \
    \                         [&](const std::vector<int>& v) { return v.empty(); }),\n\
    \t\t             result.end());\n\t\treturn result;\n\t}\n};\n#line 5 \"Graph/Kruskal.cpp\"\
    \n\nWeight Kruskal(int V, Edges& graph) {\n\tstd::sort(graph.begin(), graph.end(),\n\
    \t          [](const Edge2& e1, const Edge2& e2) { return e1.cost < e2.cost; });\n\
    \tWeight result = 0;\n\tUnionFind uf(V);\n\tfor (auto e : graph) {\n\t\tif (uf.unite(e.from,\
    \ e.to)) {\n\t\t\tresult += e.cost;\n\t\t}\n\t}\n\treturn result;\n}\n#line 4\
    \ \"test/Kruskal.test.cpp\"\nusing namespace std;\n\nint main() {\n\tint n, m;\n\
    \tcin >> n >> m;\n\tEdges edges(m);\n\tfor (int i = 0; i < m; ++i) {\n\t\tint\
    \ s, t;\n\t\tWeight d;\n\t\tcin >> s >> t >> d;\n\t\tedges[i] = Edge2(s, t, d);\n\
    \t}\n\n\tcout << Kruskal(n, edges) << '\\n';\n}\n"
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
  timestamp: '2021-03-21 10:20:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Kruskal.test.cpp
layout: document
redirect_from:
- /verify/test/Kruskal.test.cpp
- /verify/test/Kruskal.test.cpp.html
title: test/Kruskal.test.cpp
---
