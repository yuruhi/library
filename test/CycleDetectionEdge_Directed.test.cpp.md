---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/CycleDetection.cpp
    title: Graph/CycleDetection.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "#line 1 \"test/CycleDetectionEdge_Directed.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/cycle_detection\"\n#line 2 \"Graph/CycleDetection.cpp\"\
    \n#include <vector>\n#include <stack>\n#include <utility>\n#include <algorithm>\n\
    #include <optional>\nusing namespace std;\n\npair<bool, vector<int>> CycleDetectionEdge(int\
    \ n, const vector<pair<int, int>>& edges,\n                                  \
    \         bool directed = true) {\n\tvector<vector<pair<int, int>>> graph(n);\n\
    \tfor (size_t i = 0; i < edges.size(); ++i) {\n\t\tauto [u, v] = edges[i];\n\t\
    \tgraph[u].emplace_back(v, i);\n\t\tif (!directed) graph[v].emplace_back(u, i);\n\
    \t}\n\tvector<bool> visited(n), finished(n);\n\tstack<pair<int, int>> st;\n\t\
    optional<int> pos;\n\tauto dfs = [&](auto&& f, int v, int prev) -> void {\n\t\t\
    visited[v] = true;\n\t\tfor (auto [u, i] : graph[v]) {\n\t\t\tif (!finished[u]\
    \ && (directed || u != prev)) {\n\t\t\t\tst.emplace(i, v);\n\t\t\t\tif (visited[u])\
    \ {\n\t\t\t\t\tpos = u;\n\t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t\tf(f, u, v);\n\t\
    \t\t\tif (pos) return;\n\t\t\t\tst.pop();\n\t\t\t}\n\t\t}\n\t\tfinished[v] = true;\n\
    \t};\n\tfor (int i = 0; i < n && !pos; ++i) {\n\t\tif (!visited[i]) dfs(dfs, i,\
    \ -1);\n\t}\n\n\tif (pos) {\n\t\tvector<int> cycle;\n\t\twhile (!st.empty()) {\n\
    \t\t\tauto [top, from] = st.top();\n\t\t\tst.pop();\n\t\t\tcycle.push_back(top);\n\
    \t\t\tif (from == *pos) {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\treverse(cycle.begin(),\
    \ cycle.end());\n\t\treturn {true, cycle};\n\t} else {\n\t\treturn {false, {}};\n\
    \t}\n}\n\npair<bool, vector<int>> CycleDetectionVertex(int n, const vector<pair<int,\
    \ int>>& edges,\n                                             bool directed =\
    \ true) {\n\tvector<vector<int>> graph(n);\n\tfor (auto [u, v] : edges) {\n\t\t\
    graph[u].push_back(v);\n\t\tif (!directed) graph[v].push_back(u);\n\t}\n\tvector<bool>\
    \ visited(n), finished(n);\n\tstack<int> st;\n\toptional<int> pos;\n\tauto dfs\
    \ = [&](auto&& f, int v, int prev) -> void {\n\t\tvisited[v] = true;\n\t\tst.push(v);\n\
    \t\tfor (int u : graph[v]) {\n\t\t\tif (!finished[u] && (directed || u != prev))\
    \ {\n\t\t\t\tif (visited[u]) {\n\t\t\t\t\tpos = u;\n\t\t\t\t\treturn;\n\t\t\t\t\
    }\n\t\t\t\tf(f, u, v);\n\t\t\t\tif (pos) return;\n\t\t\t}\n\t\t}\n\t\tfinished[v]\
    \ = true;\n\t\tst.pop();\n\t};\n\tfor (int i = 0; i < n && !pos; ++i) {\n\t\t\
    if (!visited[i]) dfs(dfs, i, -1);\n\t}\n\n\tif (pos) {\n\t\tvector<int> cycle;\n\
    \t\twhile (!st.empty()) {\n\t\t\tint top = st.top();\n\t\t\tst.pop();\n\t\t\t\
    cycle.push_back(top);\n\t\t\tif (top == *pos) {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\
    }\n\t\treverse(cycle.begin(), cycle.end());\n\t\treturn {true, cycle};\n\t} else\
    \ {\n\t\treturn {false, {}};\n\t}\n}\n#line 3 \"test/CycleDetectionEdge_Directed.test.cpp\"\
    \n#include <iostream>\n#line 6 \"test/CycleDetectionEdge_Directed.test.cpp\"\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, m;\n\tcin >> n >> m;\n\tvector<pair<int, int>> edges(m);\n\tfor (int\
    \ i = 0; i < m; ++i) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tedges[i] = {u,\
    \ v};\n\t}\n\tauto [detected, cycle] = CycleDetectionEdge(n, edges);\n\tif (detected)\
    \ {\n\t\tcout << cycle.size() << '\\n';\n\t\tfor (int e : cycle) {\n\t\t\tcout\
    \ << e << '\\n';\n\t\t}\n\t} else {\n\t\tcout << -1 << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n#include\
    \ \"./../Graph/CycleDetection.cpp\"\n#include <iostream>\n#include <vector>\n\
    #include <utility>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n, m;\n\tcin >> n >> m;\n\tvector<pair<int,\
    \ int>> edges(m);\n\tfor (int i = 0; i < m; ++i) {\n\t\tint u, v;\n\t\tcin >>\
    \ u >> v;\n\t\tedges[i] = {u, v};\n\t}\n\tauto [detected, cycle] = CycleDetectionEdge(n,\
    \ edges);\n\tif (detected) {\n\t\tcout << cycle.size() << '\\n';\n\t\tfor (int\
    \ e : cycle) {\n\t\t\tcout << e << '\\n';\n\t\t}\n\t} else {\n\t\tcout << -1 <<\
    \ '\\n';\n\t}\n}"
  dependsOn:
  - Graph/CycleDetection.cpp
  isVerificationFile: true
  path: test/CycleDetectionEdge_Directed.test.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/CycleDetectionEdge_Directed.test.cpp
layout: document
redirect_from:
- /verify/test/CycleDetectionEdge_Directed.test.cpp
- /verify/test/CycleDetectionEdge_Directed.test.cpp.html
title: test/CycleDetectionEdge_Directed.test.cpp
---
