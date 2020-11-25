---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
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
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 4 \"Graph/isConnected.cpp\"\
    \n#include <queue>\nusing namespace std;\n\nbool isConnected(const vector<vector<int>>&\
    \ graph, int s, int t) {\n\tint V = graph.size();\n\tqueue<int> que;\n\tque.push(s);\n\
    \tvector<bool> vis(V);\n\tvis[s] = true;\n\twhile (!que.empty()) {\n\t\tint fro\
    \ = que.front();\n\t\tque.pop();\n\t\tif (fro == t) return true;\n\t\tfor (int\
    \ e : graph[fro]) {\n\t\t\tif (!vis[e]) {\n\t\t\t\tque.push(e);\n\t\t\t\tvis[e]\
    \ = true;\n\t\t\t}\n\t\t}\n\t}\n\treturn false;\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <vector>\n#include\
    \ <queue>\nusing namespace std;\n\nbool isConnected(const vector<vector<int>>&\
    \ graph, int s, int t) {\n\tint V = graph.size();\n\tqueue<int> que;\n\tque.push(s);\n\
    \tvector<bool> vis(V);\n\tvis[s] = true;\n\twhile (!que.empty()) {\n\t\tint fro\
    \ = que.front();\n\t\tque.pop();\n\t\tif (fro == t) return true;\n\t\tfor (int\
    \ e : graph[fro]) {\n\t\t\tif (!vis[e]) {\n\t\t\t\tque.push(e);\n\t\t\t\tvis[e]\
    \ = true;\n\t\t\t}\n\t\t}\n\t}\n\treturn false;\n}\n"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/isConnected.cpp
  requiredBy: []
  timestamp: '2020-10-25 11:08:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/isConnected.cpp
layout: document
redirect_from:
- /library/Graph/isConnected.cpp
- /library/Graph/isConnected.cpp.html
title: Graph/isConnected.cpp
---