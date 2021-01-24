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
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 4 \"Graph/SpanningTree.cpp\"\
    \n#include <queue>\nusing namespace std;\n\nGraph SpanningTree(const Graph& graph,\
    \ int root) {\n\tint n = graph.size();\n\tGraph result(n);\n\tqueue<int> q;\n\t\
    q.push(root);\n\tvector<bool> flag(n);\n\tflag[root] = true;\n\twhile (!q.empty())\
    \ {\n\t\tint f = q.front();\n\t\tq.pop();\n\t\tfor (const Edge& e : graph[f])\
    \ {\n\t\t\tif (!flag[e.to]) {\n\t\t\t\tresult[f].push_back(e);\n\t\t\t\tflag[e.to]\
    \ = true;\n\t\t\t\tq.push(e.to);\n\t\t\t}\n\t\t}\n\t}\n\treturn result;\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <vector>\n#include\
    \ <queue>\nusing namespace std;\n\nGraph SpanningTree(const Graph& graph, int\
    \ root) {\n\tint n = graph.size();\n\tGraph result(n);\n\tqueue<int> q;\n\tq.push(root);\n\
    \tvector<bool> flag(n);\n\tflag[root] = true;\n\twhile (!q.empty()) {\n\t\tint\
    \ f = q.front();\n\t\tq.pop();\n\t\tfor (const Edge& e : graph[f]) {\n\t\t\tif\
    \ (!flag[e.to]) {\n\t\t\t\tresult[f].push_back(e);\n\t\t\t\tflag[e.to] = true;\n\
    \t\t\t\tq.push(e.to);\n\t\t\t}\n\t\t}\n\t}\n\treturn result;\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/SpanningTree.cpp
  requiredBy: []
  timestamp: '2020-11-23 14:52:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/SpanningTree.cpp
layout: document
redirect_from:
- /library/Graph/SpanningTree.cpp
- /library/Graph/SpanningTree.cpp.html
title: Graph/SpanningTree.cpp
---
