---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/TopologicalSort.cpp
    title: Graph/TopologicalSort.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B
  bundledCode: "#line 1 \"test/TopologicalSort.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B\"\
    \n#line 2 \"Graph/TopologicalSort.cpp\"\n#include <vector>\n#include <algorithm>\n\
    using namespace std;\n\nvector<int> TopologicalSort(const vector<vector<int>>&\
    \ graph) {\n\tsize_t n = graph.size();\n\tvector<bool> visited(n);\n\tvector<int>\
    \ result;\n\tauto dfs = [&](auto self, size_t v) -> void {\n\t\tif (visited[v])\
    \ return;\n\t\tvisited[v] = true;\n\t\tfor (size_t i : graph[v]) self(self, i);\n\
    \t\tresult.push_back(v);\n\t};\n\tfor (size_t i = 0; i < n; i++) dfs(dfs, i);\n\
    \treverse(result.begin(), result.end());\n\treturn result;\n}\n#line 3 \"test/TopologicalSort.test.cpp\"\
    \n#include <iostream>\n#line 5 \"test/TopologicalSort.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, m;\n\tcin >> n >> m;\n\tvector<vector<int>> g(n);\n\tfor (int i = 0;\
    \ i < m; ++i) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tg[u].push_back(v);\n\t\
    }\n\tfor (int i : TopologicalSort(g)) {\n\t\tcout << i << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B\"\
    \n#include \"./../Graph/TopologicalSort.cpp\"\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, m;\n\tcin >> n >> m;\n\tvector<vector<int>> g(n);\n\tfor (int i = 0;\
    \ i < m; ++i) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tg[u].push_back(v);\n\t\
    }\n\tfor (int i : TopologicalSort(g)) {\n\t\tcout << i << '\\n';\n\t}\n}"
  dependsOn:
  - Graph/TopologicalSort.cpp
  isVerificationFile: true
  path: test/TopologicalSort.test.cpp
  requiredBy: []
  timestamp: '2020-11-23 14:52:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/TopologicalSort.test.cpp
layout: document
redirect_from:
- /verify/test/TopologicalSort.test.cpp
- /verify/test/TopologicalSort.test.cpp.html
title: test/TopologicalSort.test.cpp
---