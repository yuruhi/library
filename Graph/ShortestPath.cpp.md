---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/ShortestPath.cpp\"\n// description : \u91CD\u3055\u306A\
    \u3057\u30B0\u30E9\u30D5\u306E\u6700\u77ED\u7D4C\u8DEF O(V + E)\nvector<int> ShortestPath(const\
    \ vector<vector<int>>& G, const int s) {\n\tint V = G.size();\n\tvector<int> dist(V,\
    \ INT_MAX);\n\tdist[s] = 0;\n\tqueue<int> que;\n\tque.push(s);\n\twhile (!que.empty())\
    \ {\n\t\tint f = que.front();\n\t\tque.pop();\n\t\tfor (auto e : G[f]) {\n\t\t\
    \tif (dist[e] == INT_MAX) {\n\t\t\t\tque.push(e);\n\t\t\t\tdist[e] = dist[f] +\
    \ 1;\n\t\t\t}\n\t\t}\n\t}\n\treturn dist;\n}\n"
  code: "// description : \u91CD\u3055\u306A\u3057\u30B0\u30E9\u30D5\u306E\u6700\u77ED\
    \u7D4C\u8DEF O(V + E)\nvector<int> ShortestPath(const vector<vector<int>>& G,\
    \ const int s) {\n\tint V = G.size();\n\tvector<int> dist(V, INT_MAX);\n\tdist[s]\
    \ = 0;\n\tqueue<int> que;\n\tque.push(s);\n\twhile (!que.empty()) {\n\t\tint f\
    \ = que.front();\n\t\tque.pop();\n\t\tfor (auto e : G[f]) {\n\t\t\tif (dist[e]\
    \ == INT_MAX) {\n\t\t\t\tque.push(e);\n\t\t\t\tdist[e] = dist[f] + 1;\n\t\t\t\
    }\n\t\t}\n\t}\n\treturn dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ShortestPath.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/ShortestPath.cpp
layout: document
redirect_from:
- /library/Graph/ShortestPath.cpp
- /library/Graph/ShortestPath.cpp.html
title: Graph/ShortestPath.cpp
---
