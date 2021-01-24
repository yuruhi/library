---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 4 \"Graph/BuildTreePath.cpp\"\
    \n#include <algorithm>\nusing namespace std;\n\nvector<int> BuildPathTree(const\
    \ Graph& graph, int s, int t) {\n\tint n = graph.size();\n\tvector<int> par(n);\n\
    \tauto dfs = [&](auto&& f, int v, int p) -> void {\n\t\tfor (const auto& u : graph[v])\
    \ {\n\t\t\tif (u.to != p) {\n\t\t\t\tpar[u.to] = v;\n\t\t\t\tf(f, u.to, v);\n\t\
    \t\t}\n\t\t}\n\t};\n\tdfs(dfs, s, -1);\n\tvector<int> path{t};\n\twhile (path.back()\
    \ != s) {\n\t\tpath.push_back(par[path.back()]);\n\t}\n\treverse(path.begin(),\
    \ path.end());\n\treturn path;\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\nusing namespace std;\n\nvector<int> BuildPathTree(const Graph&\
    \ graph, int s, int t) {\n\tint n = graph.size();\n\tvector<int> par(n);\n\tauto\
    \ dfs = [&](auto&& f, int v, int p) -> void {\n\t\tfor (const auto& u : graph[v])\
    \ {\n\t\t\tif (u.to != p) {\n\t\t\t\tpar[u.to] = v;\n\t\t\t\tf(f, u.to, v);\n\t\
    \t\t}\n\t\t}\n\t};\n\tdfs(dfs, s, -1);\n\tvector<int> path{t};\n\twhile (path.back()\
    \ != s) {\n\t\tpath.push_back(par[path.back()]);\n\t}\n\treverse(path.begin(),\
    \ path.end());\n\treturn path;\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/BuildTreePath.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BuildTreePath.cpp
layout: document
redirect_from:
- /library/Graph/BuildTreePath.cpp
- /library/Graph/BuildTreePath.cpp.html
title: Graph/BuildTreePath.cpp
---
