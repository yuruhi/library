---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/Dinic.cpp
    title: Graph/Dinic.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/FordFulkerson.cpp
    title: Graph/FordFulkerson.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Dinic.test.cpp
    title: test/Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/FordFulkerson.test.cpp
    title: test/FordFulkerson.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/FlowTemplate.cpp\"\n#include <vector>\n#include <limits>\n\
    using namespace std;\n\nusing FLOW = long long;\nconstexpr FLOW INF_FLOW = numeric_limits<FLOW>::max();\n\
    struct EdgeF {\n\tint to, rev;\n\tFLOW cap;\n\tEdgeF() : to(-1), rev(-1), cap(-1)\
    \ {}\n\tEdgeF(int t, int r, FLOW c) : to(t), rev(r), cap(c) {}\n};\nusing GraphF\
    \ = vector<vector<EdgeF>>;\n"
  code: "#pragma once\n#include <vector>\n#include <limits>\nusing namespace std;\n\
    \nusing FLOW = long long;\nconstexpr FLOW INF_FLOW = numeric_limits<FLOW>::max();\n\
    struct EdgeF {\n\tint to, rev;\n\tFLOW cap;\n\tEdgeF() : to(-1), rev(-1), cap(-1)\
    \ {}\n\tEdgeF(int t, int r, FLOW c) : to(t), rev(r), cap(c) {}\n};\nusing GraphF\
    \ = vector<vector<EdgeF>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/FlowTemplate.cpp
  requiredBy:
  - Graph/Dinic.cpp
  - Graph/FordFulkerson.cpp
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Dinic.test.cpp
  - test/FordFulkerson.test.cpp
documentation_of: Graph/FlowTemplate.cpp
layout: document
redirect_from:
- /library/Graph/FlowTemplate.cpp
- /library/Graph/FlowTemplate.cpp.html
title: Graph/FlowTemplate.cpp
---
