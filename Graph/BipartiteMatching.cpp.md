---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BipartiteMatching.test.cpp
    title: test/BipartiteMatching.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/BipartiteMatching.cpp\"\n#include <vector>\n#include\
    \ <utility>\n#include <algorithm>\n#include <cassert>\nusing namespace std;\n\n\
    class BipartiteMatching {\n\tsize_t left, right;\n\tvector<vector<int>> graph;\n\
    \tvector<bool> used;\n\tvector<int> left_match, right_match;\n\tbool dfs(int v)\
    \ {\n\t\tif (used[v]) {\n\t\t\treturn false;\n\t\t}\n\t\tused[v] = true;\n\t\t\
    for (int u : graph[v]) {\n\t\t\tif (right_match[u] == -1 || dfs(right_match[u]))\
    \ {\n\t\t\t\tleft_match[v] = u;\n\t\t\t\tright_match[u] = v;\n\t\t\t\treturn true;\n\
    \t\t\t}\n\t\t}\n\t\treturn false;\n\t}\n\npublic:\n\tBipartiteMatching(size_t\
    \ _left, size_t _right)\n\t    : left(_left),\n\t      right(_right),\n\t    \
    \  graph(left),\n\t      used(left),\n\t      left_match(left),\n\t      right_match(right)\
    \ {}\n\tBipartiteMatching(size_t _left, size_t _right, const vector<vector<int>>&\
    \ _graph)\n\t    : left(_left),\n\t      right(_right),\n\t      graph(_graph),\n\
    \t      used(left),\n\t      left_match(left),\n\t      right_match(right) {\n\
    \t\tassert(graph.size() == left);\n\t}\n\tvoid add_edge(int l, int r) {\n\t\t\
    graph[l].push_back(r);\n\t}\n\tint solve() {\n\t\tint res = 0;\n\t\tfill(left_match.begin(),\
    \ left_match.end(), -1);\n\t\tfill(right_match.begin(), right_match.end(), -1);\n\
    \t\tfill(used.begin(), used.end(), false);\n\t\tfor (bool update = true; update;)\
    \ {\n\t\t\tupdate = false;\n\t\t\tfor (size_t i = 0; i < left; ++i) {\n\t\t\t\t\
    if (left_match[i] == -1 && dfs(i)) {\n\t\t\t\t\tupdate = true;\n\t\t\t\t\t++res;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tif (update) {\n\t\t\t\tfill(used.begin(), used.end(),\
    \ false);\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tvector<pair<int, int>> edges()\
    \ const {\n\t\tvector<pair<int, int>> res;\n\t\tfor (size_t i = 0; i < left; ++i)\
    \ {\n\t\t\tif (left_match[i] != -1) {\n\t\t\t\tres.emplace_back(i, left_match[i]);\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\nclass BipartiteMatching {\n\tsize_t\
    \ left, right;\n\tvector<vector<int>> graph;\n\tvector<bool> used;\n\tvector<int>\
    \ left_match, right_match;\n\tbool dfs(int v) {\n\t\tif (used[v]) {\n\t\t\treturn\
    \ false;\n\t\t}\n\t\tused[v] = true;\n\t\tfor (int u : graph[v]) {\n\t\t\tif (right_match[u]\
    \ == -1 || dfs(right_match[u])) {\n\t\t\t\tleft_match[v] = u;\n\t\t\t\tright_match[u]\
    \ = v;\n\t\t\t\treturn true;\n\t\t\t}\n\t\t}\n\t\treturn false;\n\t}\n\npublic:\n\
    \tBipartiteMatching(size_t _left, size_t _right)\n\t    : left(_left),\n\t   \
    \   right(_right),\n\t      graph(left),\n\t      used(left),\n\t      left_match(left),\n\
    \t      right_match(right) {}\n\tBipartiteMatching(size_t _left, size_t _right,\
    \ const vector<vector<int>>& _graph)\n\t    : left(_left),\n\t      right(_right),\n\
    \t      graph(_graph),\n\t      used(left),\n\t      left_match(left),\n\t   \
    \   right_match(right) {\n\t\tassert(graph.size() == left);\n\t}\n\tvoid add_edge(int\
    \ l, int r) {\n\t\tgraph[l].push_back(r);\n\t}\n\tint solve() {\n\t\tint res =\
    \ 0;\n\t\tfill(left_match.begin(), left_match.end(), -1);\n\t\tfill(right_match.begin(),\
    \ right_match.end(), -1);\n\t\tfill(used.begin(), used.end(), false);\n\t\tfor\
    \ (bool update = true; update;) {\n\t\t\tupdate = false;\n\t\t\tfor (size_t i\
    \ = 0; i < left; ++i) {\n\t\t\t\tif (left_match[i] == -1 && dfs(i)) {\n\t\t\t\t\
    \tupdate = true;\n\t\t\t\t\t++res;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (update) {\n\t\
    \t\t\tfill(used.begin(), used.end(), false);\n\t\t\t}\n\t\t}\n\t\treturn res;\n\
    \t}\n\tvector<pair<int, int>> edges() const {\n\t\tvector<pair<int, int>> res;\n\
    \t\tfor (size_t i = 0; i < left; ++i) {\n\t\t\tif (left_match[i] != -1) {\n\t\t\
    \t\tres.emplace_back(i, left_match[i]);\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BipartiteMatching.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/BipartiteMatching.test.cpp
documentation_of: Graph/BipartiteMatching.cpp
layout: document
redirect_from:
- /library/Graph/BipartiteMatching.cpp
- /library/Graph/BipartiteMatching.cpp.html
title: Graph/BipartiteMatching.cpp
---
