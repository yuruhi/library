---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/WarashallFloyd.cpp
    title: Graph/WarashallFloyd.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
  bundledCode: "#line 1 \"test/WarashallFloyd.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C\"\
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
    #line 3 \"Graph/WarashallFloyd.cpp\"\n#include <algorithm>\n#line 5 \"Graph/WarashallFloyd.cpp\"\
    \n\nbool WarashallFloyd(Matrix& dist, Weight INF = std::numeric_limits<Weight>::max())\
    \ {\n\tstd::size_t n = dist.size();\n\tfor (std::size_t i = 0; i < n; ++i) {\n\
    \t\tfor (std::size_t j = 0; j < n; ++j) {\n\t\t\tfor (std::size_t k = 0; k < n;\
    \ ++k) {\n\t\t\t\tif (dist[j][i] == INF || dist[i][k] == INF) continue;\n\t\t\t\
    \tdist[j][k] = std::min(dist[j][k], dist[j][i] + dist[i][k]);\n\t\t\t}\n\t\t}\n\
    \t}\n\tfor (std::size_t i = 0; i < n; ++i) {\n\t\tif (dist[i][i] < 0) return true;\n\
    \t}\n\treturn false;\n}\n\nvoid WarashallFloydAddEdge(Matrix& dist, const Edge2&\
    \ e) {\n\tstd::size_t n = dist.size();\n\tfor (std::size_t i = 0; i < n; ++i)\
    \ {\n\t\tfor (std::size_t j = 0; j < n; ++j) {\n\t\t\tdist[i][j] = std::min(\n\
    \t\t\t    dist[i][j],\n\t\t\t    std::min(dist[i][e.from] + dist[e.to][j], dist[i][e.to]\
    \ + dist[e.from][j]) +\n\t\t\t        e.cost);\n\t\t}\n\t}\n}\n#line 5 \"test/WarashallFloyd.test.cpp\"\
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
  timestamp: '2021-03-16 12:30:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/WarashallFloyd.test.cpp
layout: document
redirect_from:
- /verify/test/WarashallFloyd.test.cpp
- /verify/test/WarashallFloyd.test.cpp.html
title: test/WarashallFloyd.test.cpp
---
