---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/BipartiteGraph.cpp\"\n// description : \u4E8C\u90E8\
    \u30B0\u30E9\u30D5\u5224\u5B9A O(V + E)\ntuple<bool, vector<bool>> BipartiteGraph(const\
    \ vector<vector<int>>& g) {\n\tint n = g.size();\n\tvector<int> a(n);\n\tbool\
    \ flag = true;\n\tauto dfs = [&](auto&& f, int v, int color) -> bool {\n\t\ta[v]\
    \ = color;\n\t\tfor (int u : g[v]) {\n\t\t\tif (a[u] == color || (a[u] == 0 &&\
    \ !f(f, u, color * -1))) {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ true;\n\t};\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (a[i] == 0 && !dfs(dfs,\
    \ 0, 1)) {\n\t\t\treturn {false, vector<bool>()};\n\t\t}\n\t}\n\tvector<bool>\
    \ res(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tres[i] = a[i] == 1;\n\t}\n\treturn\
    \ {flag, res};\n}\n"
  code: "// description : \u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A O(V + E)\ntuple<bool,\
    \ vector<bool>> BipartiteGraph(const vector<vector<int>>& g) {\n\tint n = g.size();\n\
    \tvector<int> a(n);\n\tbool flag = true;\n\tauto dfs = [&](auto&& f, int v, int\
    \ color) -> bool {\n\t\ta[v] = color;\n\t\tfor (int u : g[v]) {\n\t\t\tif (a[u]\
    \ == color || (a[u] == 0 && !f(f, u, color * -1))) {\n\t\t\t\treturn false;\n\t\
    \t\t}\n\t\t}\n\t\treturn true;\n\t};\n\tfor (int i = 0; i < n; ++i) {\n\t\tif\
    \ (a[i] == 0 && !dfs(dfs, 0, 1)) {\n\t\t\treturn {false, vector<bool>()};\n\t\t\
    }\n\t}\n\tvector<bool> res(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tres[i] =\
    \ a[i] == 1;\n\t}\n\treturn {flag, res};\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BipartiteGraph.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BipartiteGraph.cpp
layout: document
redirect_from:
- /library/Graph/BipartiteGraph.cpp
- /library/Graph/BipartiteGraph.cpp.html
title: Graph/BipartiteGraph.cpp
---
