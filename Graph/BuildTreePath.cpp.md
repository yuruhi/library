---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/BuildTreePath.cpp\"\n// description : s-t \u9593\u306E\
    \u30D1\u30B9\u3092\u6C42\u3081\u308B\nvector<int> BuildPathTree(const Graph& g,\
    \ int s, int t) {\n\tint n = g.size();\n\tvector<int> par(n);\n\tfunction<void(int,\
    \ int)> dfs = [&](int v, int p) {\n\t\tfor (const auto& u : g[v])\n\t\t\tif (u.to\
    \ != p) {\n\t\t\t\tpar[u.to] = v;\n\t\t\t\tdfs(u.to, v);\n\t\t\t}\n\t};\n\tdfs(s,\
    \ -1);\n\tvector<int> path{t};\n\twhile (path.back() != s) {\n\t\tpath.push_back(par[path.back()]);\n\
    \t}\n\treverse(path.begin(), path.end());\n\treturn path;\n}\n"
  code: "// description : s-t \u9593\u306E\u30D1\u30B9\u3092\u6C42\u3081\u308B\nvector<int>\
    \ BuildPathTree(const Graph& g, int s, int t) {\n\tint n = g.size();\n\tvector<int>\
    \ par(n);\n\tfunction<void(int, int)> dfs = [&](int v, int p) {\n\t\tfor (const\
    \ auto& u : g[v])\n\t\t\tif (u.to != p) {\n\t\t\t\tpar[u.to] = v;\n\t\t\t\tdfs(u.to,\
    \ v);\n\t\t\t}\n\t};\n\tdfs(s, -1);\n\tvector<int> path{t};\n\twhile (path.back()\
    \ != s) {\n\t\tpath.push_back(par[path.back()]);\n\t}\n\treverse(path.begin(),\
    \ path.end());\n\treturn path;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BuildTreePath.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BuildTreePath.cpp
layout: document
redirect_from:
- /library/Graph/BuildTreePath.cpp
- /library/Graph/BuildTreePath.cpp.html
title: Graph/BuildTreePath.cpp
---
