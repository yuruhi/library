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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2891
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2891
  bundledCode: "#line 1 \"test/CycleDetectionVertex_Undirected.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2891\"\n#line 2 \"Graph/CycleDetection.cpp\"\
    \n#include <vector>\n#include <stack>\n#include <algorithm>\n#include <optional>\n\
    using namespace std;\n\noptional<vector<int>> CycleDetectionEdge(int n, const\
    \ vector<pair<int, int>>& edges,\n                                         bool\
    \ directed = true) {\n\tvector<vector<pair<int, int>>> graph(n);\n\tfor (size_t\
    \ i = 0; i < edges.size(); ++i) {\n\t\tauto [u, v] = edges[i];\n\t\tgraph[u].emplace_back(v,\
    \ i);\n\t\tif (!directed) graph[v].emplace_back(u, i);\n\t}\n\tvector<bool> visited(n),\
    \ finished(n);\n\tstack<pair<int, int>> st;\n\toptional<int> pos;\n\tauto dfs\
    \ = [&](auto&& f, int v, int prev_edge) -> void {\n\t\tvisited[v] = true;\n\t\t\
    for (auto [u, i] : graph[v]) {\n\t\t\tif (!finished[u] && (directed || i != prev_edge))\
    \ {\n\t\t\t\tst.emplace(i, v);\n\t\t\t\tif (visited[u]) {\n\t\t\t\t\tpos = u;\n\
    \t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t\tf(f, u, i);\n\t\t\t\tif (pos) return;\n\t\
    \t\t\tst.pop();\n\t\t\t}\n\t\t}\n\t\tfinished[v] = true;\n\t};\n\tfor (int i =\
    \ 0; i < n && !pos; ++i) {\n\t\tif (!visited[i]) dfs(dfs, i, -1);\n\t}\n\n\tif\
    \ (pos) {\n\t\tvector<int> cycle;\n\t\twhile (!st.empty()) {\n\t\t\tauto [top,\
    \ from] = st.top();\n\t\t\tst.pop();\n\t\t\tcycle.push_back(top);\n\t\t\tif (from\
    \ == *pos) {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\treverse(cycle.begin(), cycle.end());\n\
    \t\treturn cycle;\n\t} else {\n\t\treturn nullopt;\n\t}\n}\n\noptional<vector<int>>\
    \ CycleDetectionVertex(const vector<vector<int>>& graph,\n                   \
    \                        bool directed = true) {\n\tint n = graph.size();\n\t\
    vector<bool> visited(n), finished(n);\n\tstack<int> st;\n\toptional<int> pos;\n\
    \tauto dfs = [&](auto&& f, int v, int prev) -> void {\n\t\tvisited[v] = true;\n\
    \t\tst.push(v);\n\t\tfor (int u : graph[v]) {\n\t\t\tif (!finished[u] && (directed\
    \ || u != prev)) {\n\t\t\t\tif (visited[u]) {\n\t\t\t\t\tpos = u;\n\t\t\t\t\t\
    return;\n\t\t\t\t}\n\t\t\t\tf(f, u, v);\n\t\t\t\tif (pos) return;\n\t\t\t}\n\t\
    \t}\n\t\tfinished[v] = true;\n\t\tst.pop();\n\t};\n\tfor (int i = 0; i < n &&\
    \ !pos; ++i) {\n\t\tif (!visited[i]) dfs(dfs, i, -1);\n\t}\n\n\tif (pos) {\n\t\
    \tvector<int> cycle;\n\t\twhile (!st.empty()) {\n\t\t\tint top = st.top();\n\t\
    \t\tst.pop();\n\t\t\tcycle.push_back(top);\n\t\t\tif (top == *pos) {\n\t\t\t\t\
    break;\n\t\t\t}\n\t\t}\n\t\treverse(cycle.begin(), cycle.end());\n\t\treturn cycle;\n\
    \t} else {\n\t\treturn nullopt;\n\t}\n}\n\noptional<vector<int>> CycleDetectionVertex(int\
    \ n, const vector<pair<int, int>>& edges,\n                                  \
    \         bool directed = true) {\n\tvector<vector<int>> graph(n);\n\tfor (auto\
    \ [u, v] : edges) {\n\t\tgraph[u].push_back(v);\n\t\tif (!directed) graph[v].push_back(u);\n\
    \t}\n\treturn CycleDetectionVertex(graph, directed);\n}\n#line 3 \"test/CycleDetectionVertex_Undirected.test.cpp\"\
    \n#include <iostream>\n#line 5 \"test/CycleDetectionVertex_Undirected.test.cpp\"\
    \n#include <cassert>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n;\n\tcin >> n;\n\tvector<pair<int,\
    \ int>> edges(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tint u, v;\n\t\tcin >>\
    \ u >> v;\n\t\tu--;\n\t\tv--;\n\t\tedges[i] = {u, v};\n\t}\n\tauto cycle = CycleDetectionVertex(n,\
    \ edges, false);\n\tassert(cycle);\n\tvector<bool> flag(n);\n\tfor (int i : *cycle)\
    \ {\n\t\tflag[i] = true;\n\t}\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint\
    \ a, b;\n\t\tcin >> a >> b;\n\t\ta--;\n\t\tb--;\n\t\tif (flag[a] && flag[b]) {\n\
    \t\t\tcout << 2 << '\\n';\n\t\t} else {\n\t\t\tcout << 1 << '\\n';\n\t\t}\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2891\"\n#include\
    \ \"./../Graph/CycleDetection.cpp\"\n#include <iostream>\n#include <vector>\n\
    #include <cassert>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n;\n\tcin >> n;\n\tvector<pair<int,\
    \ int>> edges(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tint u, v;\n\t\tcin >>\
    \ u >> v;\n\t\tu--;\n\t\tv--;\n\t\tedges[i] = {u, v};\n\t}\n\tauto cycle = CycleDetectionVertex(n,\
    \ edges, false);\n\tassert(cycle);\n\tvector<bool> flag(n);\n\tfor (int i : *cycle)\
    \ {\n\t\tflag[i] = true;\n\t}\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint\
    \ a, b;\n\t\tcin >> a >> b;\n\t\ta--;\n\t\tb--;\n\t\tif (flag[a] && flag[b]) {\n\
    \t\t\tcout << 2 << '\\n';\n\t\t} else {\n\t\t\tcout << 1 << '\\n';\n\t\t}\n\t\
    }\n}"
  dependsOn:
  - Graph/CycleDetection.cpp
  isVerificationFile: true
  path: test/CycleDetectionVertex_Undirected.test.cpp
  requiredBy: []
  timestamp: '2021-01-14 21:53:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/CycleDetectionVertex_Undirected.test.cpp
layout: document
redirect_from:
- /verify/test/CycleDetectionVertex_Undirected.test.cpp
- /verify/test/CycleDetectionVertex_Undirected.test.cpp.html
title: test/CycleDetectionVertex_Undirected.test.cpp
---
