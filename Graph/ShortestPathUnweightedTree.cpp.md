---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/ShortestPathUnweightedTree.cpp\"\n#include <vector>\n\
    using namespace std;\n\nvector<int> ShortestPathTree(const vector<vector<int>>&\
    \ g, int s) {\n\tint V = g.size();\n\tvector<int> dist(V);\n\tauto dfs = [&](auto&&\
    \ f, int v, int p, int depth) -> void {\n\t\tdist[v] = depth;\n\t\tfor (int e\
    \ : g[v]) {\n\t\t\tif (e != p) {\n\t\t\t\tf(f, e, v, depth + 1);\n\t\t\t}\n\t\t\
    }\n\t};\n\tdfs(dfs, s, -1, 0);\n\treturn dist;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\nvector<int> ShortestPathTree(const\
    \ vector<vector<int>>& g, int s) {\n\tint V = g.size();\n\tvector<int> dist(V);\n\
    \tauto dfs = [&](auto&& f, int v, int p, int depth) -> void {\n\t\tdist[v] = depth;\n\
    \t\tfor (int e : g[v]) {\n\t\t\tif (e != p) {\n\t\t\t\tf(f, e, v, depth + 1);\n\
    \t\t\t}\n\t\t}\n\t};\n\tdfs(dfs, s, -1, 0);\n\treturn dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ShortestPathUnweightedTree.cpp
  requiredBy: []
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/ShortestPathUnweightedTree.cpp
layout: document
redirect_from:
- /library/Graph/ShortestPathUnweightedTree.cpp
- /library/Graph/ShortestPathUnweightedTree.cpp.html
title: Graph/ShortestPathUnweightedTree.cpp
---
