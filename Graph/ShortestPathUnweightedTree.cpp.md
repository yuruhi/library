---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/ShortestPathUnweightedTree.cpp\"\n// description :\
    \ \u91CD\u3055\u306A\u3057\u6728\u306E\u6700\u77ED\u7D4C\u8DEF\nvector<int> ShortestPathTree(const\
    \ vector<vector<int>>& g, int s) {\n\tint V = g.size();\n\tvector<int> dist(V);\n\
    \tfunction<void(int, int, int)> dfs = [&](int v, int p, int depth) {\n\t\tdist[v]\
    \ = depth;\n\t\tfor (int e : g[v])\n\t\t\tif (e != p) {\n\t\t\t\tdfs(e, v, depth\
    \ + 1);\n\t\t\t}\n\t};\n\tdfs(s, -1, 0);\n\treturn dist;\n}\n"
  code: "// description : \u91CD\u3055\u306A\u3057\u6728\u306E\u6700\u77ED\u7D4C\u8DEF\
    \nvector<int> ShortestPathTree(const vector<vector<int>>& g, int s) {\n\tint V\
    \ = g.size();\n\tvector<int> dist(V);\n\tfunction<void(int, int, int)> dfs = [&](int\
    \ v, int p, int depth) {\n\t\tdist[v] = depth;\n\t\tfor (int e : g[v])\n\t\t\t\
    if (e != p) {\n\t\t\t\tdfs(e, v, depth + 1);\n\t\t\t}\n\t};\n\tdfs(s, -1, 0);\n\
    \treturn dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ShortestPathUnweightedTree.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/ShortestPathUnweightedTree.cpp
layout: document
redirect_from:
- /library/Graph/ShortestPathUnweightedTree.cpp
- /library/Graph/ShortestPathUnweightedTree.cpp.html
title: Graph/ShortestPathUnweightedTree.cpp
---
