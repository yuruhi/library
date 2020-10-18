---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/DijkstraBuildPath.cpp
    title: Graph/DijkstraBuildPath.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/DijkstraBuildPath.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\
    \n\n#line 2 \"Graph/GraphTemplate.cpp\"\n#include <limits>\n#include <vector>\n\
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
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 4 \"Graph/DijkstraBuildPath.cpp\"\
    \n#include <algorithm>\n#include <utility>\n#include <queue>\nusing namespace\
    \ std;\n\npair<vector<Weight>, vector<int>> DijkstraBuildPrev(const Graph& graph,\
    \ int s) {\n\tint V = graph.size();\n\tvector<Weight> dist(V, INF);\n\tdist[s]\
    \ = 0;\n\tvector<int> prev(V, -1);\n\tpriority_queue<Edge, vector<Edge>, greater<Edge>>\
    \ pq;\n\tpq.emplace(s, 0);\n\twhile (!pq.empty()) {\n\t\tEdge p = pq.top();\n\t\
    \tpq.pop();\n\t\tint v = p.to;\n\t\tif (dist[v] < p.cost) continue;\n\t\tfor (auto\
    \ e : graph[v]) {\n\t\t\tif (dist[e.to] > dist[v] + e.cost) {\n\t\t\t\tdist[e.to]\
    \ = dist[v] + e.cost;\n\t\t\t\tpq.emplace(e.to, dist[e.to]);\n\t\t\t\tprev[e.to]\
    \ = v;\n\t\t\t}\n\t\t}\n\t}\n\treturn {dist, prev};\n}\nvector<int> BuildPath(const\
    \ vector<int>& prev, int t) {\n\tvector<int> res;\n\twhile (prev[t] != -1) {\n\
    \t\tres.push_back(t);\n\t\tt = prev[t];\n\t}\n\tres.push_back(t);\n\treverse(res.begin(),\
    \ res.end());\n\treturn res;\n}\n#line 5 \"test/DijkstraBuildPath.test.cpp\"\n\
    using namespace std;\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\
    \n\tint n, m, s, t;\n\tcin >> n >> m >> s >> t;\n\n\tGraph g(n);\n\tfor (int i\
    \ = 0; i < m; ++i) {\n\t\tint a, b;\n\t\tWeight c;\n\t\tcin >> a >> b >> c;\n\t\
    \tg[a].emplace_back(b, c);\n\t}\n\n\tauto [dist, prev] = DijkstraBuildPrev(g,\
    \ s);\n\tauto path = BuildPath(prev, t);\n\n\tif (dist[t] < INF) {\n\t\tcout <<\
    \ dist[t] << ' ' << path.size() - 1 << endl;\n\t\tfor (size_t i = 0; i < path.size()\
    \ - 1; i++) {\n\t\t\tcout << path[i] << ' ' << path[i + 1] << endl;\n\t\t}\n\t\
    } else {\n\t\tcout << -1 << endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"./../Graph/DijkstraBuildPath.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\n\tint n,\
    \ m, s, t;\n\tcin >> n >> m >> s >> t;\n\n\tGraph g(n);\n\tfor (int i = 0; i <\
    \ m; ++i) {\n\t\tint a, b;\n\t\tWeight c;\n\t\tcin >> a >> b >> c;\n\t\tg[a].emplace_back(b,\
    \ c);\n\t}\n\n\tauto [dist, prev] = DijkstraBuildPrev(g, s);\n\tauto path = BuildPath(prev,\
    \ t);\n\n\tif (dist[t] < INF) {\n\t\tcout << dist[t] << ' ' << path.size() - 1\
    \ << endl;\n\t\tfor (size_t i = 0; i < path.size() - 1; i++) {\n\t\t\tcout <<\
    \ path[i] << ' ' << path[i + 1] << endl;\n\t\t}\n\t} else {\n\t\tcout << -1 <<\
    \ endl;\n\t}\n}"
  dependsOn:
  - Graph/DijkstraBuildPath.cpp
  - Graph/GraphTemplate.cpp
  isVerificationFile: true
  path: test/DijkstraBuildPath.test.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DijkstraBuildPath.test.cpp
layout: document
redirect_from:
- /verify/test/DijkstraBuildPath.test.cpp
- /verify/test/DijkstraBuildPath.test.cpp.html
title: test/DijkstraBuildPath.test.cpp
---
