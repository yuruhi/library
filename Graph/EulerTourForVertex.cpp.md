---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/EulerTourForVertex.cpp\"\n// description : \u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC\nclass EulerTourForVertex {\n\tvector<int> ls,\
    \ rs;\n\tint pos = 0;\n\tvoid dfs(int v, int p) {\n\t\tls[v] = pos++;\n\t\tfor\
    \ (int u : G[v]) {\n\t\t\tif (u != p) dfs(u, v);\n\t\t}\n\t\trs[v] = pos;\n\t\
    }\n\npublic:\n\tvector<vector<int>> G;\n\tEulerTourForVertex() {}\n\tEulerTourForVertex(int\
    \ n) : ls(n), rs(n), G(n) {}\n\tvoid add_edge(int u, int v) {\n\t\tG[u].emplace_back(v);\n\
    \t\tG[v].emplace_back(u);\n\t}\n\tvoid build(int r = 0) {\n\t\tpos = 0;\n\t\t\
    dfs(r, -1);\n\t}\n\tint operator[](int v) {\n\t\treturn ls[v];\n\t}\n\tint r(int\
    \ v) {\n\t\treturn rs[v];\n\t}\n\ttemplate <typename F> void exec(int v, F f)\
    \ {\n\t\tf(ls[v], rs[v]);\n\t}\n};\n"
  code: "// description : \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\nclass EulerTourForVertex\
    \ {\n\tvector<int> ls, rs;\n\tint pos = 0;\n\tvoid dfs(int v, int p) {\n\t\tls[v]\
    \ = pos++;\n\t\tfor (int u : G[v]) {\n\t\t\tif (u != p) dfs(u, v);\n\t\t}\n\t\t\
    rs[v] = pos;\n\t}\n\npublic:\n\tvector<vector<int>> G;\n\tEulerTourForVertex()\
    \ {}\n\tEulerTourForVertex(int n) : ls(n), rs(n), G(n) {}\n\tvoid add_edge(int\
    \ u, int v) {\n\t\tG[u].emplace_back(v);\n\t\tG[v].emplace_back(u);\n\t}\n\tvoid\
    \ build(int r = 0) {\n\t\tpos = 0;\n\t\tdfs(r, -1);\n\t}\n\tint operator[](int\
    \ v) {\n\t\treturn ls[v];\n\t}\n\tint r(int v) {\n\t\treturn rs[v];\n\t}\n\ttemplate\
    \ <typename F> void exec(int v, F f) {\n\t\tf(ls[v], rs[v]);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/EulerTourForVertex.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/EulerTourForVertex.cpp
layout: document
redirect_from:
- /library/Graph/EulerTourForVertex.cpp
- /library/Graph/EulerTourForVertex.cpp.html
title: Graph/EulerTourForVertex.cpp
---
