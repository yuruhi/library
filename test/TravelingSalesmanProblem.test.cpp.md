---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/TravelingSalesmanProblem.cpp
    title: Graph/TravelingSalesmanProblem.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A
  bundledCode: "#line 1 \"test/TravelingSalesmanProblem.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A\"\n#line 2 \"Graph/GraphTemplate.cpp\"\
    \n#include <limits>\n#include <vector>\n#include <iostream>\nusing namespace std;\n\
    \nusing Weight = long long;\nconstexpr Weight INF = numeric_limits<Weight>::max();\n\
    struct Edge {\n\tint to;\n\tWeight cost;\n\tEdge() : to(-1), cost(-1) {}\n\tEdge(int\
    \ _to, Weight _cost = 1) : to(_to), cost(_cost) {}\n\tfriend bool operator<(const\
    \ Edge& e1, const Edge& e2) {\n\t\treturn e1.cost < e2.cost;\n\t}\n\tfriend bool\
    \ operator>(const Edge& e1, const Edge& e2) {\n\t\treturn e1.cost > e2.cost;\n\
    \t}\n\tfriend ostream& operator<<(ostream& os, const Edge& e) {\n\t\treturn os\
    \ << \"->\" << e.to << '(' << e.cost << ')';\n\t}\n};\nusing Graph = vector<vector<Edge>>;\n\
    struct Edge2 {\n\tint from, to;\n\tWeight cost;\n\tEdge2() : from(-1), to(-1),\
    \ cost(0) {}\n\tEdge2(int _from, int _to, Weight _cost) : from(_from), to(_to),\
    \ cost(_cost) {}\n\tfriend bool operator<(const Edge2& e1, const Edge2& e2) {\n\
    \t\treturn e1.cost < e2.cost;\n\t}\n\tfriend bool operator>(const Edge2& e1, const\
    \ Edge2& e2) {\n\t\treturn e1.cost > e2.cost;\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ os, const Edge2& e) {\n\t\treturn os << e.from << \"->\" << e.to << '(' << e.cost\
    \ << ')';\n\t}\n};\nusing Edges = vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n\
    #line 3 \"Graph/TravelingSalesmanProblem.cpp\"\n\nWeight TravelingSelesman(const\
    \ Matrix& graph, const Weight INF = 1000000000000000000ll) {\n\tint n = graph.size();\n\
    \tvector dp(1 << n, vector(n, INF));\n\tdp.back()[0] = 0;\n\tfor (int s = (1 <<\
    \ n) - 2; s >= 0; --s) {\n\t\tfor (int v = 0; v < n; ++v) {\n\t\t\tfor (int u\
    \ = 0; u < n; ++u) {\n\t\t\t\tif (!(s & (1 << u))) {\n\t\t\t\t\tdp[s][v] = min(dp[s][v],\
    \ dp[s | (1 << u)][u] + graph[v][u]);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ dp[0][0];\n}\n#line 4 \"test/TravelingSalesmanProblem.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tconstexpr Weight inf = 1e18;\n\tint n, m;\n\tcin >> n >> m;\n\tMatrix g(n,\
    \ vector(n, inf));\n\tfor (int i = 0; i < n; ++i) {\n\t\tg[i][i] = 0;\n\t}\n\t\
    for (int i = 0; i < m; ++i) {\n\t\tint s, t;\n\t\tWeight d;\n\t\tcin >> s >> t\
    \ >> d;\n\t\tg[s][t] = d;\n\t}\n\n\tWeight ans = TravelingSelesman(g, inf);\n\t\
    cout << (ans < inf ? ans : -1) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A\"\n#include\
    \ \"./../Graph/TravelingSalesmanProblem.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tconstexpr Weight inf = 1e18;\n\tint n, m;\n\tcin >> n >> m;\n\tMatrix g(n,\
    \ vector(n, inf));\n\tfor (int i = 0; i < n; ++i) {\n\t\tg[i][i] = 0;\n\t}\n\t\
    for (int i = 0; i < m; ++i) {\n\t\tint s, t;\n\t\tWeight d;\n\t\tcin >> s >> t\
    \ >> d;\n\t\tg[s][t] = d;\n\t}\n\n\tWeight ans = TravelingSelesman(g, inf);\n\t\
    cout << (ans < inf ? ans : -1) << '\\n';\n}"
  dependsOn:
  - Graph/TravelingSalesmanProblem.cpp
  - Graph/GraphTemplate.cpp
  isVerificationFile: true
  path: test/TravelingSalesmanProblem.test.cpp
  requiredBy: []
  timestamp: '2020-12-05 16:06:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/TravelingSalesmanProblem.test.cpp
layout: document
redirect_from:
- /verify/test/TravelingSalesmanProblem.test.cpp
- /verify/test/TravelingSalesmanProblem.test.cpp.html
title: test/TravelingSalesmanProblem.test.cpp
---
