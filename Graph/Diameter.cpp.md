---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Diameter.test.cpp
    title: test/Diameter.test.cpp
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
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 3 \"Graph/Diameter.cpp\"\
    \n#include <utility>\n#include <tuple>\nusing namespace std;\n\ntuple<Weight,\
    \ int, int> Diameter(const Graph& graph) {\n\tauto dfs = [&](auto&& f, int v,\
    \ int p, Weight depth) -> pair<Weight, int> {\n\t\tpair<Weight, int> result(depth,\
    \ v);\n\t\tfor (auto e : graph[v]) {\n\t\t\tif (e.to != p) {\n\t\t\t\tauto tmp\
    \ = f(f, e.to, v, depth + e.cost);\n\t\t\t\tif (tmp.first > result.first) result\
    \ = tmp;\n\t\t\t}\n\t\t}\n\t\treturn result;\n\t};\n\tauto d1 = dfs(dfs, 0, -1,\
    \ 0);\n\tauto d2 = dfs(dfs, d1.second, -1, 0);\n\treturn {d2.first, d1.second,\
    \ d2.second};\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <utility>\n#include\
    \ <tuple>\nusing namespace std;\n\ntuple<Weight, int, int> Diameter(const Graph&\
    \ graph) {\n\tauto dfs = [&](auto&& f, int v, int p, Weight depth) -> pair<Weight,\
    \ int> {\n\t\tpair<Weight, int> result(depth, v);\n\t\tfor (auto e : graph[v])\
    \ {\n\t\t\tif (e.to != p) {\n\t\t\t\tauto tmp = f(f, e.to, v, depth + e.cost);\n\
    \t\t\t\tif (tmp.first > result.first) result = tmp;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ result;\n\t};\n\tauto d1 = dfs(dfs, 0, -1, 0);\n\tauto d2 = dfs(dfs, d1.second,\
    \ -1, 0);\n\treturn {d2.first, d1.second, d2.second};\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/Diameter.cpp
  requiredBy: []
  timestamp: '2020-11-23 14:52:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Diameter.test.cpp
documentation_of: Graph/Diameter.cpp
layout: document
redirect_from:
- /library/Graph/Diameter.cpp
- /library/Graph/Diameter.cpp.html
title: Graph/Diameter.cpp
---
