---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/ShortestPathTree.cpp\"\n// description : \u6728\u306E\
    \u6700\u77ED\u7D4C\u8DEF\nvector<Weight> ShortestPathTree(const Graph& g, int\
    \ s) {\n\tint V = g.size();\n\tvector<Weight> dist(V);\n\tfunction<void(int, int,\
    \ Weight)> dfs = [&](int v, int p, Weight depth) {\n\t\tdist[v] = depth;\n\t\t\
    for (auto e : g[v])\n\t\t\tif (e.to != p) {\n\t\t\t\tdfs(e.to, v, depth + e.cost);\n\
    \t\t\t}\n\t};\n\tdfs(s, -1, 0);\n\treturn dist;\n}\n"
  code: "// description : \u6728\u306E\u6700\u77ED\u7D4C\u8DEF\nvector<Weight> ShortestPathTree(const\
    \ Graph& g, int s) {\n\tint V = g.size();\n\tvector<Weight> dist(V);\n\tfunction<void(int,\
    \ int, Weight)> dfs = [&](int v, int p, Weight depth) {\n\t\tdist[v] = depth;\n\
    \t\tfor (auto e : g[v])\n\t\t\tif (e.to != p) {\n\t\t\t\tdfs(e.to, v, depth +\
    \ e.cost);\n\t\t\t}\n\t};\n\tdfs(s, -1, 0);\n\treturn dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ShortestPathTree.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/ShortestPathTree.cpp
layout: document
redirect_from:
- /library/Graph/ShortestPathTree.cpp
- /library/Graph/ShortestPathTree.cpp.html
title: Graph/ShortestPathTree.cpp
---
