---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/SpanningTree.cpp\"\n// description : \u5168\u57DF\u6728\
    \u69CB\u7BC9 \u6709\u5411\u6728\u3092\u8FD4\u3059\nGraph SpanningTree(const Graph&\
    \ g, int root) {\n\tint n = g.size();\n\tGraph res(n);\n\tqueue<int> q;\n\tq.push(root);\n\
    \tvector<bool> flag(n);\n\tflag[root] = true;\n\twhile (!q.empty()) {\n\t\tint\
    \ f = q.front();\n\t\tq.pop();\n\t\tfor (const Edge& e : g[f]) {\n\t\t\tif (!flag[e.to])\
    \ {\n\t\t\t\tres[f].push_back(e);\n\t\t\t\tflag[e.to] = true;\n\t\t\t\tq.push(e.to);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn res;\n}\n"
  code: "// description : \u5168\u57DF\u6728\u69CB\u7BC9 \u6709\u5411\u6728\u3092\u8FD4\
    \u3059\nGraph SpanningTree(const Graph& g, int root) {\n\tint n = g.size();\n\t\
    Graph res(n);\n\tqueue<int> q;\n\tq.push(root);\n\tvector<bool> flag(n);\n\tflag[root]\
    \ = true;\n\twhile (!q.empty()) {\n\t\tint f = q.front();\n\t\tq.pop();\n\t\t\
    for (const Edge& e : g[f]) {\n\t\t\tif (!flag[e.to]) {\n\t\t\t\tres[f].push_back(e);\n\
    \t\t\t\tflag[e.to] = true;\n\t\t\t\tq.push(e.to);\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/SpanningTree.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/SpanningTree.cpp
layout: document
redirect_from:
- /library/Graph/SpanningTree.cpp
- /library/Graph/SpanningTree.cpp.html
title: Graph/SpanningTree.cpp
---
