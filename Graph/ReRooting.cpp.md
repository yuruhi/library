---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ReRooting.test.cpp
    title: test/ReRooting.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/ReRooting.cpp\"\n#include <vector>\n\ntemplate <class\
    \ DP> class ReRooting {\n\tstd::size_t n;\n\tstd::vector<std::vector<int>> graph;\n\
    \tstd::vector<std::vector<DP>> dp;\n\tstd::vector<DP> ans;\n\n\tDP dfs(int v,\
    \ int p) {\n\t\tDP sum;\n\t\tfor (std::size_t i = 0; i < graph[v].size(); ++i)\
    \ {\n\t\t\tint e = graph[v][i];\n\t\t\tDP& dp_e = dp[v][i];\n\t\t\tif (e != p)\
    \ {\n\t\t\t\tdp_e = dfs(e, v);\n\t\t\t\tsum += dp_e;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ sum.add_root(v);\n\t}\n\tvoid bfs(int v, int p, const DP& dp_par) {\n\t\tfor\
    \ (std::size_t i = 0; i < graph[v].size(); ++i) {\n\t\t\tif (graph[v][i] == p)\
    \ {\n\t\t\t\tdp[v][i] = dp_par;\n\t\t\t}\n\t\t}\n\n\t\tstd::vector<DP> dp_left(graph[v].size()\
    \ + 1);\n\t\tfor (std::size_t i = 0; i < graph[v].size(); ++i) {\n\t\t\tdp_left[i\
    \ + 1] = dp_left[i] + dp[v][i];\n\t\t}\n\t\tstd::vector<DP> dp_right(graph[v].size()\
    \ + 1);\n\t\tfor (int i = graph[v].size() - 1; i >= 0; --i) {\n\t\t\tdp_right[i]\
    \ = dp_right[i + 1] + dp[v][i];\n\t\t}\n\t\tans[v] = dp_left.back().add_root(v);\n\
    \n\t\tfor (std::size_t i = 0; i < graph[v].size(); ++i) {\n\t\t\tint e = graph[v][i];\n\
    \t\t\tif (e != p) {\n\t\t\t\tbfs(e, v, (dp_left[i] + dp_right[i + 1]).add_root(v));\n\
    \t\t\t}\n\t\t}\n\t}\n\npublic:\n\tReRooting(std::size_t _n) : n(_n), graph(n),\
    \ dp(n), ans(n) {}\n\tReRooting(const std::vector<std::vector<int>>& _graph)\n\
    \t    : n(_graph.size()), graph(_graph), dp(n), ans(n) {}\n\tvoid add_edge(int\
    \ v, int u) {\n\t\tgraph[v].push_back(u);\n\t\tgraph[u].push_back(v);\n\t}\n\t\
    std::vector<DP> solve() {\n\t\tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\tdp[i].assign(graph[i].size(),\
    \ DP());\n\t\t}\n\t\tdfs(0, -1);\n\t\tbfs(0, -1, DP());\n\t\treturn ans;\n\t}\n\
    };\n\n/*\nstruct DP {\n    int dp;\n    DP(int _dp = 1) : dp(_dp) {}\n    DP operator+(const\
    \ DP& d) const {\n        return DP(*this) += d;\n    }\n    DP& operator+=(const\
    \ DP& d) {\n        return *this;\n    }\n    DP add_root([[maybe_unused]] int\
    \ v) const {\n        DP res = *this;\n\n        return res;\n    }\n};\n*/\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <class DP> class ReRooting {\n\
    \tstd::size_t n;\n\tstd::vector<std::vector<int>> graph;\n\tstd::vector<std::vector<DP>>\
    \ dp;\n\tstd::vector<DP> ans;\n\n\tDP dfs(int v, int p) {\n\t\tDP sum;\n\t\tfor\
    \ (std::size_t i = 0; i < graph[v].size(); ++i) {\n\t\t\tint e = graph[v][i];\n\
    \t\t\tDP& dp_e = dp[v][i];\n\t\t\tif (e != p) {\n\t\t\t\tdp_e = dfs(e, v);\n\t\
    \t\t\tsum += dp_e;\n\t\t\t}\n\t\t}\n\t\treturn sum.add_root(v);\n\t}\n\tvoid bfs(int\
    \ v, int p, const DP& dp_par) {\n\t\tfor (std::size_t i = 0; i < graph[v].size();\
    \ ++i) {\n\t\t\tif (graph[v][i] == p) {\n\t\t\t\tdp[v][i] = dp_par;\n\t\t\t}\n\
    \t\t}\n\n\t\tstd::vector<DP> dp_left(graph[v].size() + 1);\n\t\tfor (std::size_t\
    \ i = 0; i < graph[v].size(); ++i) {\n\t\t\tdp_left[i + 1] = dp_left[i] + dp[v][i];\n\
    \t\t}\n\t\tstd::vector<DP> dp_right(graph[v].size() + 1);\n\t\tfor (int i = graph[v].size()\
    \ - 1; i >= 0; --i) {\n\t\t\tdp_right[i] = dp_right[i + 1] + dp[v][i];\n\t\t}\n\
    \t\tans[v] = dp_left.back().add_root(v);\n\n\t\tfor (std::size_t i = 0; i < graph[v].size();\
    \ ++i) {\n\t\t\tint e = graph[v][i];\n\t\t\tif (e != p) {\n\t\t\t\tbfs(e, v, (dp_left[i]\
    \ + dp_right[i + 1]).add_root(v));\n\t\t\t}\n\t\t}\n\t}\n\npublic:\n\tReRooting(std::size_t\
    \ _n) : n(_n), graph(n), dp(n), ans(n) {}\n\tReRooting(const std::vector<std::vector<int>>&\
    \ _graph)\n\t    : n(_graph.size()), graph(_graph), dp(n), ans(n) {}\n\tvoid add_edge(int\
    \ v, int u) {\n\t\tgraph[v].push_back(u);\n\t\tgraph[u].push_back(v);\n\t}\n\t\
    std::vector<DP> solve() {\n\t\tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\tdp[i].assign(graph[i].size(),\
    \ DP());\n\t\t}\n\t\tdfs(0, -1);\n\t\tbfs(0, -1, DP());\n\t\treturn ans;\n\t}\n\
    };\n\n/*\nstruct DP {\n    int dp;\n    DP(int _dp = 1) : dp(_dp) {}\n    DP operator+(const\
    \ DP& d) const {\n        return DP(*this) += d;\n    }\n    DP& operator+=(const\
    \ DP& d) {\n        return *this;\n    }\n    DP add_root([[maybe_unused]] int\
    \ v) const {\n        DP res = *this;\n\n        return res;\n    }\n};\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ReRooting.cpp
  requiredBy: []
  timestamp: '2021-03-17 10:25:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ReRooting.test.cpp
documentation_of: Graph/ReRooting.cpp
layout: document
redirect_from:
- /library/Graph/ReRooting.cpp
- /library/Graph/ReRooting.cpp.html
title: Graph/ReRooting.cpp
---
