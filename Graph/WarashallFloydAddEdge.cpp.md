---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/WarashallFloydAddEdge.cpp\"\n#include <algorithm>\n\
    using namespace std;\n\nvoid WarashallFloydAddEdge(Matrix& dist, const Edge2&\
    \ e) {\n\tint V = dist.size();\n\tfor (int i = 0; i < V; ++i)\n\t\tfor (int j\
    \ = 0; j < V; ++j)\n\t\t\tdist[i][j] = min(\n\t\t\t    dist[i][j],\n\t\t\t   \
    \ min(dist[i][e.u] + dist[e.v][j], dist[i][e.v] + dist[e.u][j]) + e.cost);\n}\n"
  code: "#pragma once\n#include <algorithm>\nusing namespace std;\n\nvoid WarashallFloydAddEdge(Matrix&\
    \ dist, const Edge2& e) {\n\tint V = dist.size();\n\tfor (int i = 0; i < V; ++i)\n\
    \t\tfor (int j = 0; j < V; ++j)\n\t\t\tdist[i][j] = min(\n\t\t\t    dist[i][j],\n\
    \t\t\t    min(dist[i][e.u] + dist[e.v][j], dist[i][e.v] + dist[e.u][j]) + e.cost);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/WarashallFloydAddEdge.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/WarashallFloydAddEdge.cpp
layout: document
redirect_from:
- /library/Graph/WarashallFloydAddEdge.cpp
- /library/Graph/WarashallFloydAddEdge.cpp.html
title: Graph/WarashallFloydAddEdge.cpp
---
