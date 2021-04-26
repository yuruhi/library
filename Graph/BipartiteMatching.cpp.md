---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BipartiteMatching.test.cpp
    title: test/BipartiteMatching.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/BipartiteMatching.cpp\"\n#include <vector>\n#include\
    \ <utility>\n#include <algorithm>\n#include <cassert>\n\nclass BipartiteMatching\
    \ {\n\tstd::size_t left, right;\n\tstd::vector<std::vector<int>> graph;\n\tstd::vector<bool>\
    \ used;\n\tstd::vector<int> left_match, right_match;\n\tbool dfs(int v) {\n\t\t\
    if (used[v]) {\n\t\t\treturn false;\n\t\t}\n\t\tused[v] = true;\n\t\tfor (int\
    \ u : graph[v]) {\n\t\t\tif (right_match[u] == -1 || dfs(right_match[u])) {\n\t\
    \t\t\tleft_match[v] = u;\n\t\t\t\tright_match[u] = v;\n\t\t\t\treturn true;\n\t\
    \t\t}\n\t\t}\n\t\treturn false;\n\t}\n\npublic:\n\tBipartiteMatching(std::size_t\
    \ _left, std::size_t _right)\n\t    : left(_left),\n\t      right(_right),\n\t\
    \      graph(left),\n\t      used(left),\n\t      left_match(left),\n\t      right_match(right)\
    \ {}\n\tBipartiteMatching(std::size_t _left, std::size_t _right,\n\t         \
    \         const std::vector<std::vector<int>>& _graph)\n\t    : left(_left),\n\
    \t      right(_right),\n\t      graph(_graph),\n\t      used(left),\n\t      left_match(left),\n\
    \t      right_match(right) {\n\t\tassert(graph.size() == left);\n\t}\n\tBipartiteMatching(std::size_t\
    \ _left, std::size_t _right,\n\t                  const std::vector<std::pair<int,\
    \ int>>& edges)\n\t    : left(_left),\n\t      right(_right),\n\t      graph(left),\n\
    \t      used(left),\n\t      left_match(left),\n\t      right_match(right) {\n\
    \t\tfor (auto [u, v] : edges) {\n\t\t\tgraph[u].push_back(v);\n\t\t}\n\t}\n\t\
    void add_edge(int l, int r) {\n\t\tgraph[l].push_back(r);\n\t}\n\tint solve()\
    \ {\n\t\tint result = 0;\n\t\tstd::fill(left_match.begin(), left_match.end(),\
    \ -1);\n\t\tstd::fill(right_match.begin(), right_match.end(), -1);\n\t\tstd::fill(used.begin(),\
    \ used.end(), false);\n\t\tfor (bool update = true; update;) {\n\t\t\tupdate =\
    \ false;\n\t\t\tfor (std::size_t i = 0; i < left; ++i) {\n\t\t\t\tif (left_match[i]\
    \ == -1 && dfs(i)) {\n\t\t\t\t\tupdate = true;\n\t\t\t\t\t++result;\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\tif (update) {\n\t\t\t\tstd::fill(used.begin(), used.end(), false);\n\
    \t\t\t}\n\t\t}\n\t\treturn result;\n\t}\n\tstd::vector<std::pair<int, int>> edges()\
    \ const {\n\t\tstd::vector<std::pair<int, int>> result;\n\t\tfor (std::size_t\
    \ i = 0; i < left; ++i) {\n\t\t\tif (left_match[i] != -1) {\n\t\t\t\tresult.emplace_back(i,\
    \ left_match[i]);\n\t\t\t}\n\t\t}\n\t\treturn result;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <cassert>\n\nclass BipartiteMatching {\n\tstd::size_t left, right;\n\t\
    std::vector<std::vector<int>> graph;\n\tstd::vector<bool> used;\n\tstd::vector<int>\
    \ left_match, right_match;\n\tbool dfs(int v) {\n\t\tif (used[v]) {\n\t\t\treturn\
    \ false;\n\t\t}\n\t\tused[v] = true;\n\t\tfor (int u : graph[v]) {\n\t\t\tif (right_match[u]\
    \ == -1 || dfs(right_match[u])) {\n\t\t\t\tleft_match[v] = u;\n\t\t\t\tright_match[u]\
    \ = v;\n\t\t\t\treturn true;\n\t\t\t}\n\t\t}\n\t\treturn false;\n\t}\n\npublic:\n\
    \tBipartiteMatching(std::size_t _left, std::size_t _right)\n\t    : left(_left),\n\
    \t      right(_right),\n\t      graph(left),\n\t      used(left),\n\t      left_match(left),\n\
    \t      right_match(right) {}\n\tBipartiteMatching(std::size_t _left, std::size_t\
    \ _right,\n\t                  const std::vector<std::vector<int>>& _graph)\n\t\
    \    : left(_left),\n\t      right(_right),\n\t      graph(_graph),\n\t      used(left),\n\
    \t      left_match(left),\n\t      right_match(right) {\n\t\tassert(graph.size()\
    \ == left);\n\t}\n\tBipartiteMatching(std::size_t _left, std::size_t _right,\n\
    \t                  const std::vector<std::pair<int, int>>& edges)\n\t    : left(_left),\n\
    \t      right(_right),\n\t      graph(left),\n\t      used(left),\n\t      left_match(left),\n\
    \t      right_match(right) {\n\t\tfor (auto [u, v] : edges) {\n\t\t\tgraph[u].push_back(v);\n\
    \t\t}\n\t}\n\tvoid add_edge(int l, int r) {\n\t\tgraph[l].push_back(r);\n\t}\n\
    \tint solve() {\n\t\tint result = 0;\n\t\tstd::fill(left_match.begin(), left_match.end(),\
    \ -1);\n\t\tstd::fill(right_match.begin(), right_match.end(), -1);\n\t\tstd::fill(used.begin(),\
    \ used.end(), false);\n\t\tfor (bool update = true; update;) {\n\t\t\tupdate =\
    \ false;\n\t\t\tfor (std::size_t i = 0; i < left; ++i) {\n\t\t\t\tif (left_match[i]\
    \ == -1 && dfs(i)) {\n\t\t\t\t\tupdate = true;\n\t\t\t\t\t++result;\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\tif (update) {\n\t\t\t\tstd::fill(used.begin(), used.end(), false);\n\
    \t\t\t}\n\t\t}\n\t\treturn result;\n\t}\n\tstd::vector<std::pair<int, int>> edges()\
    \ const {\n\t\tstd::vector<std::pair<int, int>> result;\n\t\tfor (std::size_t\
    \ i = 0; i < left; ++i) {\n\t\t\tif (left_match[i] != -1) {\n\t\t\t\tresult.emplace_back(i,\
    \ left_match[i]);\n\t\t\t}\n\t\t}\n\t\treturn result;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BipartiteMatching.cpp
  requiredBy: []
  timestamp: '2021-04-20 17:21:17+09:00'
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
