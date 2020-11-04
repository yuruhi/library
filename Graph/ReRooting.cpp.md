---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/ReRooting.cpp\"\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate <class DP> class ReRooting {\n\tint n;\n\tvector<vector<int>>\
    \ g;\n\tvector<vector<DP>> dp;\n\tvector<DP> ans;\n\n\tDP dfs(int v, int p) {\n\
    \t\tDP sum;\n\t\tfor (size_t i = 0; i < g[v].size(); ++i) {\n\t\t\tint e = g[v][i];\n\
    \t\t\tDP& dp_e = dp[v][i];\n\t\t\tif (e != p) {\n\t\t\t\tdp_e = dfs(e, v);\n\t\
    \t\t\tsum += dp_e;\n\t\t\t}\n\t\t}\n\t\treturn sum.add_root(v);\n\t}\n\tvoid bfs(int\
    \ v, int p, const DP& dp_par) {\n\t\tfor (size_t i = 0; i < g[v].size(); ++i)\
    \ {\n\t\t\tif (g[v][i] == p) {\n\t\t\t\tdp[v][i] = dp_par;\n\t\t\t}\n\t\t}\n\n\
    \t\tvector<DP> dp_left(g[v].size() + 1);\n\t\tfor (size_t i = 0; i < g[v].size();\
    \ ++i) {\n\t\t\tdp_left[i + 1] = dp_left[i] + dp[v][i];\n\t\t}\n\t\tvector<DP>\
    \ dp_right(g[v].size() + 1);\n\t\tfor (int i = g[v].size() - 1; i >= 0; --i) {\n\
    \t\t\tdp_right[i] = dp_right[i + 1] + dp[v][i];\n\t\t}\n\t\tans[v] = dp_left.back().add_root(v);\n\
    \n\t\tfor (size_t i = 0; i < g[v].size(); ++i) {\n\t\t\tint e = g[v][i];\n\t\t\
    \tif (e != p) {\n\t\t\t\tbfs(e, v, (dp_left[i] + dp_right[i + 1]).add_root(v));\n\
    \t\t\t}\n\t\t}\n\t}\n\npublic:\n\tReRooting(const vector<vector<int>>& _g) : n(_g.size()),\
    \ g(_g), dp(n), ans(n) {\n\t\tfor (int i = 0; i < n; ++i)\n\t\t\tdp[i].resize(g[i].size());\n\
    \t}\n\tvector<DP> solve() {\n\t\tdfs(0, -1);\n\t\tbfs(0, -1, DP());\n\t\treturn\
    \ ans;\n\t}\n};\n\n/*\nstruct DP {\n    int dp;\n    DP(int _dp = 1) : dp(_dp)\
    \ {}\n    DP operator+(const DP& d) const {\n        return DP(*this) += d;\n\
    \    }\n    DP& operator+=(const DP& d) {\n        return *this;\n    }\n    DP\
    \ add_root([[maybe_unused]] int v) const {\n        DP res = *this;\n\n      \
    \  return res;\n    }\n};\n*/\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate <class\
    \ DP> class ReRooting {\n\tint n;\n\tvector<vector<int>> g;\n\tvector<vector<DP>>\
    \ dp;\n\tvector<DP> ans;\n\n\tDP dfs(int v, int p) {\n\t\tDP sum;\n\t\tfor (size_t\
    \ i = 0; i < g[v].size(); ++i) {\n\t\t\tint e = g[v][i];\n\t\t\tDP& dp_e = dp[v][i];\n\
    \t\t\tif (e != p) {\n\t\t\t\tdp_e = dfs(e, v);\n\t\t\t\tsum += dp_e;\n\t\t\t}\n\
    \t\t}\n\t\treturn sum.add_root(v);\n\t}\n\tvoid bfs(int v, int p, const DP& dp_par)\
    \ {\n\t\tfor (size_t i = 0; i < g[v].size(); ++i) {\n\t\t\tif (g[v][i] == p) {\n\
    \t\t\t\tdp[v][i] = dp_par;\n\t\t\t}\n\t\t}\n\n\t\tvector<DP> dp_left(g[v].size()\
    \ + 1);\n\t\tfor (size_t i = 0; i < g[v].size(); ++i) {\n\t\t\tdp_left[i + 1]\
    \ = dp_left[i] + dp[v][i];\n\t\t}\n\t\tvector<DP> dp_right(g[v].size() + 1);\n\
    \t\tfor (int i = g[v].size() - 1; i >= 0; --i) {\n\t\t\tdp_right[i] = dp_right[i\
    \ + 1] + dp[v][i];\n\t\t}\n\t\tans[v] = dp_left.back().add_root(v);\n\n\t\tfor\
    \ (size_t i = 0; i < g[v].size(); ++i) {\n\t\t\tint e = g[v][i];\n\t\t\tif (e\
    \ != p) {\n\t\t\t\tbfs(e, v, (dp_left[i] + dp_right[i + 1]).add_root(v));\n\t\t\
    \t}\n\t\t}\n\t}\n\npublic:\n\tReRooting(const vector<vector<int>>& _g) : n(_g.size()),\
    \ g(_g), dp(n), ans(n) {\n\t\tfor (int i = 0; i < n; ++i)\n\t\t\tdp[i].resize(g[i].size());\n\
    \t}\n\tvector<DP> solve() {\n\t\tdfs(0, -1);\n\t\tbfs(0, -1, DP());\n\t\treturn\
    \ ans;\n\t}\n};\n\n/*\nstruct DP {\n    int dp;\n    DP(int _dp = 1) : dp(_dp)\
    \ {}\n    DP operator+(const DP& d) const {\n        return DP(*this) += d;\n\
    \    }\n    DP& operator+=(const DP& d) {\n        return *this;\n    }\n    DP\
    \ add_root([[maybe_unused]] int v) const {\n        DP res = *this;\n\n      \
    \  return res;\n    }\n};\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ReRooting.cpp
  requiredBy: []
  timestamp: '2020-11-04 21:37:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/ReRooting.cpp
layout: document
redirect_from:
- /library/Graph/ReRooting.cpp
- /library/Graph/ReRooting.cpp.html
title: Graph/ReRooting.cpp
---
