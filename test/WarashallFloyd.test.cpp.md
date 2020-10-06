---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/WarashallFloyd.cpp
    title: Graph/WarashallFloyd.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
  bundledCode: "#line 1 \"test/WarashallFloyd.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C\"\
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
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 3 \"Graph/WarashallFloyd.cpp\"\
    \n#include <algorithm>\n\nbool WarashallFloyd(Matrix& dist, Weight INF_ = INF)\
    \ {\n\tint V = dist.size();\n\tfor (int i = 0; i < V; ++i)\n\t\tfor (int j = 0;\
    \ j < V; ++j)\n\t\t\tfor (int k = 0; k < V; ++k) {\n\t\t\t\tif (dist[j][i] ==\
    \ INF_ || dist[i][k] == INF_) continue;\n\t\t\t\tdist[j][k] = min(dist[j][k],\
    \ dist[j][i] + dist[i][k]);\n\t\t\t}\n\tfor (int i = 0; i < V; ++i)\n\t\tif (dist[i][i]\
    \ < 0) return true;\n\treturn false;\n}\n#line 5 \"test/WarashallFloyd.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tint n, m;\n\tcin >> n >> m;\n\tMatrix\
    \ g(n, vector(n, INF));\n\tfor (int i = 0; i < n; ++i) {\n\t\tg[i][i] = 0;\n\t\
    }\n\tfor (int i = 0; i < m; ++i) {\n\t\tint s, t;\n\t\tWeight d;\n\t\tcin >> s\
    \ >> t >> d;\n\t\tg[s][t] = d;\n\t}\n\n\tbool flag = WarashallFloyd(g);\n\tif\
    \ (!flag) {\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tfor (int j = 0; j < n; ++j)\
    \ {\n\t\t\t\tif (g[i][j] < INF) {\n\t\t\t\t\tcout << g[i][j];\n\t\t\t\t} else\
    \ {\n\t\t\t\t\tcout << \"INF\";\n\t\t\t\t}\n\t\t\t\tcout << (j < n - 1 ? ' ' :\
    \ '\\n');\n\t\t\t}\n\t\t}\n\t} else {\n\t\tcout << \"NEGATIVE CYCLE\\n\";\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C\"\
    \n#include \"./../Graph/WarashallFloyd.cpp\"\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\nint main() {\n\tint n, m;\n\tcin >> n >> m;\n\tMatrix\
    \ g(n, vector(n, INF));\n\tfor (int i = 0; i < n; ++i) {\n\t\tg[i][i] = 0;\n\t\
    }\n\tfor (int i = 0; i < m; ++i) {\n\t\tint s, t;\n\t\tWeight d;\n\t\tcin >> s\
    \ >> t >> d;\n\t\tg[s][t] = d;\n\t}\n\n\tbool flag = WarashallFloyd(g);\n\tif\
    \ (!flag) {\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tfor (int j = 0; j < n; ++j)\
    \ {\n\t\t\t\tif (g[i][j] < INF) {\n\t\t\t\t\tcout << g[i][j];\n\t\t\t\t} else\
    \ {\n\t\t\t\t\tcout << \"INF\";\n\t\t\t\t}\n\t\t\t\tcout << (j < n - 1 ? ' ' :\
    \ '\\n');\n\t\t\t}\n\t\t}\n\t} else {\n\t\tcout << \"NEGATIVE CYCLE\\n\";\n\t\
    }\n}"
  dependsOn:
  - Graph/WarashallFloyd.cpp
  - Graph/GraphTemplate.cpp
  isVerificationFile: true
  path: test/WarashallFloyd.test.cpp
  requiredBy: []
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/WarashallFloyd.test.cpp
layout: document
redirect_from:
- /verify/test/WarashallFloyd.test.cpp
- /verify/test/WarashallFloyd.test.cpp.html
title: test/WarashallFloyd.test.cpp
---
