---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/BellmanFord.cpp
    title: Graph/BellmanFord.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B
  bundledCode: "#line 1 \"test/BellmanFord.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B\"\
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
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 4 \"Graph/BellmanFord.cpp\"\
    \nusing namespace std;\n\npair<bool, vector<Weight>> BellmanFord(const Graph&\
    \ graph, int s) {\n\tint V = graph.size();\n\tvector<Weight> dist(V, INF);\n\t\
    dist[s] = 0;\n\tfor (int i = 0; i < V; ++i)\n\t\tfor (int v = 0; v < V; ++v)\n\
    \t\t\tfor (auto e : graph[v]) {\n\t\t\t\tif (dist[v] != INF && dist[e.to] > dist[v]\
    \ + e.cost) {\n\t\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\t\tif (i == V\
    \ - 1) return {true, dist};\n\t\t\t\t}\n\t\t\t}\n\treturn {false, dist};\n}\n\
    #line 4 \"test/BellmanFord.test.cpp\"\nusing namespace std;\n\nint main() {\n\t\
    int n, m, s;\n\tcin >> n >> m >> s;\n\tGraph g(n);\n\tfor (int i = 0; i < m; ++i)\
    \ {\n\t\tint s, t;\n\t\tWeight d;\n\t\tcin >> s >> t >> d;\n\t\tg[s].emplace_back(t,\
    \ d);\n\t}\n\n\tauto [flag, dist] = BellmanFord(g, s);\n\tif (!flag) {\n\t\tfor\
    \ (int i = 0; i < n; ++i) {\n\t\t\tif (dist[i] < INF) {\n\t\t\t\tcout << dist[i]\
    \ << '\\n';\n\t\t\t} else {\n\t\t\t\tcout << \"INF\\n\";\n\t\t\t}\n\t\t}\n\t}\
    \ else {\n\t\tcout << \"NEGATIVE CYCLE\\n\";\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B\"\
    \n#include \"./../Graph/BellmanFord.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tint n, m, s;\n\tcin >> n >> m >> s;\n\tGraph g(n);\n\
    \tfor (int i = 0; i < m; ++i) {\n\t\tint s, t;\n\t\tWeight d;\n\t\tcin >> s >>\
    \ t >> d;\n\t\tg[s].emplace_back(t, d);\n\t}\n\n\tauto [flag, dist] = BellmanFord(g,\
    \ s);\n\tif (!flag) {\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tif (dist[i] <\
    \ INF) {\n\t\t\t\tcout << dist[i] << '\\n';\n\t\t\t} else {\n\t\t\t\tcout << \"\
    INF\\n\";\n\t\t\t}\n\t\t}\n\t} else {\n\t\tcout << \"NEGATIVE CYCLE\\n\";\n\t\
    }\n}"
  dependsOn:
  - Graph/BellmanFord.cpp
  - Graph/GraphTemplate.cpp
  isVerificationFile: true
  path: test/BellmanFord.test.cpp
  requiredBy: []
  timestamp: '2020-10-04 14:21:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/BellmanFord.test.cpp
layout: document
redirect_from:
- /verify/test/BellmanFord.test.cpp
- /verify/test/BellmanFord.test.cpp.html
title: test/BellmanFord.test.cpp
---
