---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/BuildTreePathEdge.cpp\"\n// description : \u6728\u306E\
    s-t\u9593\u306E\u30D1\u30B9\u306E\u8FBA\u306E\u756A\u53F7\u3092\u6C42\u3081\u308B\
    \nvector<int> BuildTreePathEdge(const vector<vector<pair<int, int>>>& g, int s,\
    \ int t) {\n\tint n = g.size();\n\tvector<pair<int, int>> par(n, make_pair(-1,\
    \ -1));\n\tauto dfs = [&](auto&& f, int v, int p) -> void {\n\t\tfor (auto [u,\
    \ i] : g[v]) {\n\t\t\tif (u != p) {\n\t\t\t\tpar[u] = make_pair(v, i);\n\t\t\t\
    \tf(f, u, v);\n\t\t\t}\n\t\t}\n\t};\n\tdfs(dfs, t, -1);\n\tvector<int> res;\n\t\
    for (int v = s; v != t; v = par[v].first) {\n\t\tres.push_back(par[v].second);\n\
    \t}\n\treturn res;\n}\n"
  code: "// description : \u6728\u306Es-t\u9593\u306E\u30D1\u30B9\u306E\u8FBA\u306E\
    \u756A\u53F7\u3092\u6C42\u3081\u308B\nvector<int> BuildTreePathEdge(const vector<vector<pair<int,\
    \ int>>>& g, int s, int t) {\n\tint n = g.size();\n\tvector<pair<int, int>> par(n,\
    \ make_pair(-1, -1));\n\tauto dfs = [&](auto&& f, int v, int p) -> void {\n\t\t\
    for (auto [u, i] : g[v]) {\n\t\t\tif (u != p) {\n\t\t\t\tpar[u] = make_pair(v,\
    \ i);\n\t\t\t\tf(f, u, v);\n\t\t\t}\n\t\t}\n\t};\n\tdfs(dfs, t, -1);\n\tvector<int>\
    \ res;\n\tfor (int v = s; v != t; v = par[v].first) {\n\t\tres.push_back(par[v].second);\n\
    \t}\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BuildTreePathEdge.cpp
  requiredBy: []
  timestamp: '2020-07-24 18:16:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BuildTreePathEdge.cpp
layout: document
redirect_from:
- /library/Graph/BuildTreePathEdge.cpp
- /library/Graph/BuildTreePathEdge.cpp.html
title: Graph/BuildTreePathEdge.cpp
---
