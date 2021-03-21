---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/LowLink.cpp
    title: Graph/LowLink.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B
  bundledCode: "#line 1 \"test/Bridges.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B\"\
    \n#line 2 \"Graph/LowLink.cpp\"\n#include <vector>\n#include <utility>\n\nclass\
    \ LowLink {\n\tsize_t n;\n\tstd::vector<std::vector<int>> graph;\n\tstd::vector<bool>\
    \ visited;\n\tstd::vector<int> ord, low, articulation_points;\n\tstd::vector<std::pair<int,\
    \ int>> bridges;\n\tint k;\n\n\tvoid dfs(int v, int parent) {\n\t\tvisited[v]\
    \ = true;\n\t\tord[v] = k++;\n\t\tlow[v] = ord[v];\n\t\tint count = 0;\n\t\tbool\
    \ is_articultion_point = false;\n\t\tfor (int u : graph[v]) {\n\t\t\tif (!visited[u])\
    \ {\n\t\t\t\tcount++;\n\t\t\t\tdfs(u, v);\n\t\t\t\tlow[v] = std::min(low[v], low[u]);\n\
    \t\t\t\tif (parent != -1 && ord[v] <= low[u]) {\n\t\t\t\t\tis_articultion_point\
    \ = true;\n\t\t\t\t}\n\t\t\t\tif (ord[v] < low[u]) {\n\t\t\t\t\tbridges.emplace_back(std::min(v,\
    \ u), max(v, u));\n\t\t\t\t}\n\t\t\t} else if (u != parent) {\n\t\t\t\tlow[v]\
    \ = std::min(low[v], ord[u]);\n\t\t\t}\n\t\t}\n\t\tif (is_articultion_point ||\
    \ (parent == -1 && count > 1)) {\n\t\t\tarticulation_points.push_back(v);\n\t\t\
    }\n\t}\n\npublic:\n\tLowLink(size_t _n) : n(_n), graph(_n) {}\n\tLowLink(const\
    \ std::vector<std::vector<int>>& _graph) : n(_graph.size()), graph(_graph) {}\n\
    \tvoid add_edge(int u, int v) {\n\t\tgraph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\
    \t}\n\tauto build() {\n\t\tvisited.assign(n, false);\n\t\tord.assign(n, 0);\n\t\
    \tlow.assign(n, 0);\n\t\tarticulation_points.clear();\n\t\tbridges.clear();\n\t\
    \tk = 0;\n\t\tfor (size_t i = 0; i < n; ++i) {\n\t\t\tif (!visited[i]) dfs(i,\
    \ -1);\n\t\t}\n\t\treturn std::pair(articulation_points, bridges);\n\t}\n};\n\
    #line 3 \"test/Bridges.test.cpp\"\n#include <iostream>\n#include <algorithm>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, m;\n\tcin >> n >> m;\n\tLowLink g(n);\n\twhile (m--) {\n\t\tint u, v;\n\
    \t\tcin >> u >> v;\n\t\tg.add_edge(u, v);\n\t}\n\n\tauto [aps, bridges] = g.build();\n\
    \tsort(bridges.begin(), bridges.end());\n\tfor (auto [u, v] : bridges) {\n\t\t\
    cout << u << ' ' << v << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B\"\
    \n#include \"./../Graph/LowLink.cpp\"\n#include <iostream>\n#include <algorithm>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, m;\n\tcin >> n >> m;\n\tLowLink g(n);\n\twhile (m--) {\n\t\tint u, v;\n\
    \t\tcin >> u >> v;\n\t\tg.add_edge(u, v);\n\t}\n\n\tauto [aps, bridges] = g.build();\n\
    \tsort(bridges.begin(), bridges.end());\n\tfor (auto [u, v] : bridges) {\n\t\t\
    cout << u << ' ' << v << '\\n';\n\t}\n}"
  dependsOn:
  - Graph/LowLink.cpp
  isVerificationFile: true
  path: test/Bridges.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 10:20:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/Bridges.test.cpp
layout: document
redirect_from:
- /verify/test/Bridges.test.cpp
- /verify/test/Bridges.test.cpp.html
title: test/Bridges.test.cpp
---
