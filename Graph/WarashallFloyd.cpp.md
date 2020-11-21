---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/WarashallFloyd.test.cpp
    title: test/WarashallFloyd.test.cpp
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
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 3 \"Graph/WarashallFloyd.cpp\"\
    \n#include <algorithm>\n#line 5 \"Graph/WarashallFloyd.cpp\"\n\nbool WarashallFloyd(Matrix&\
    \ dist, Weight INF_ = numeric_limits<Weight>::max()) {\n\tint V = dist.size();\n\
    \tfor (int i = 0; i < V; ++i) {\n\t\tfor (int j = 0; j < V; ++j) {\n\t\t\tfor\
    \ (int k = 0; k < V; ++k) {\n\t\t\t\tif (dist[j][i] == INF_ || dist[i][k] == INF_)\
    \ continue;\n\t\t\t\tdist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);\n\t\
    \t\t}\n\t\t}\n\t}\n\tfor (int i = 0; i < V; ++i) {\n\t\tif (dist[i][i] < 0) return\
    \ true;\n\t}\n\treturn false;\n}\n\nvoid WarashallFloydAddEdge(Matrix& dist, const\
    \ Edge2& e) {\n\tint V = dist.size();\n\tfor (int i = 0; i < V; ++i) {\n\t\tfor\
    \ (int j = 0; j < V; ++j) {\n\t\t\tdist[i][j] = min(\n\t\t\t    dist[i][j],\n\t\
    \t\t    min(dist[i][e.u] + dist[e.v][j], dist[i][e.v] + dist[e.u][j]) + e.cost);\n\
    \t\t}\n\t}\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <algorithm>\n#include\
    \ <limits>\n\nbool WarashallFloyd(Matrix& dist, Weight INF_ = numeric_limits<Weight>::max())\
    \ {\n\tint V = dist.size();\n\tfor (int i = 0; i < V; ++i) {\n\t\tfor (int j =\
    \ 0; j < V; ++j) {\n\t\t\tfor (int k = 0; k < V; ++k) {\n\t\t\t\tif (dist[j][i]\
    \ == INF_ || dist[i][k] == INF_) continue;\n\t\t\t\tdist[j][k] = min(dist[j][k],\
    \ dist[j][i] + dist[i][k]);\n\t\t\t}\n\t\t}\n\t}\n\tfor (int i = 0; i < V; ++i)\
    \ {\n\t\tif (dist[i][i] < 0) return true;\n\t}\n\treturn false;\n}\n\nvoid WarashallFloydAddEdge(Matrix&\
    \ dist, const Edge2& e) {\n\tint V = dist.size();\n\tfor (int i = 0; i < V; ++i)\
    \ {\n\t\tfor (int j = 0; j < V; ++j) {\n\t\t\tdist[i][j] = min(\n\t\t\t    dist[i][j],\n\
    \t\t\t    min(dist[i][e.u] + dist[e.v][j], dist[i][e.v] + dist[e.u][j]) + e.cost);\n\
    \t\t}\n\t}\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/WarashallFloyd.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/WarashallFloyd.test.cpp
documentation_of: Graph/WarashallFloyd.cpp
layout: document
redirect_from:
- /library/Graph/WarashallFloyd.cpp
- /library/Graph/WarashallFloyd.cpp.html
title: Graph/WarashallFloyd.cpp
---
