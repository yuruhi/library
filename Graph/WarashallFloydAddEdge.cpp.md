---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/WarashallFloydAddEdge.cpp\"\n// description : \u30EF\
    \u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5 \u8FBA\u306E\u8FFD\u52A0\
    \ O(V^2)\nvoid AddEdge(Matrix& dist, const Edge2& e) {\n\tint V = dist.size();\n\
    \tfor (int i = 0; i < V; ++i)\n\t\tfor (int j = 0; j < V; ++j)\n\t\t\tdist[i][j]\
    \ = min(dist[i][j], min(dist[i][e.u] + dist[e.v][j], dist[i][e.v] + dist[e.u][j])\
    \ + e.cost);\n}\n"
  code: "// description : \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5\
    \ \u8FBA\u306E\u8FFD\u52A0 O(V^2)\nvoid AddEdge(Matrix& dist, const Edge2& e)\
    \ {\n\tint V = dist.size();\n\tfor (int i = 0; i < V; ++i)\n\t\tfor (int j = 0;\
    \ j < V; ++j)\n\t\t\tdist[i][j] = min(dist[i][j], min(dist[i][e.u] + dist[e.v][j],\
    \ dist[i][e.v] + dist[e.u][j]) + e.cost);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/WarashallFloydAddEdge.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/WarashallFloydAddEdge.cpp
layout: document
redirect_from:
- /library/Graph/WarashallFloydAddEdge.cpp
- /library/Graph/WarashallFloydAddEdge.cpp.html
title: Graph/WarashallFloydAddEdge.cpp
---
