---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/Dinic.cpp
    title: Graph/Dinic.cpp
  - icon: ':x:'
    path: Graph/FordFulkerson.cpp
    title: Graph/FordFulkerson.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Dinic.test.cpp
    title: test/Dinic.test.cpp
  - icon: ':x:'
    path: test/FordFulkerson.test.cpp
    title: test/FordFulkerson.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/FlowTemplate.cpp\"\n#include <vector>\n#include <limits>\n\
    \nusing FLOW = long long;\nconstexpr FLOW INF_FLOW = std::numeric_limits<FLOW>::max();\n\
    struct EdgeF {\n\tint to, rev;\n\tFLOW cap;\n\tEdgeF() : to(-1), rev(-1), cap(-1)\
    \ {}\n\tEdgeF(int t, int r, FLOW c) : to(t), rev(r), cap(c) {}\n};\nusing GraphF\
    \ = std::vector<std::vector<EdgeF>>;\n"
  code: "#pragma once\n#include <vector>\n#include <limits>\n\nusing FLOW = long long;\n\
    constexpr FLOW INF_FLOW = std::numeric_limits<FLOW>::max();\nstruct EdgeF {\n\t\
    int to, rev;\n\tFLOW cap;\n\tEdgeF() : to(-1), rev(-1), cap(-1) {}\n\tEdgeF(int\
    \ t, int r, FLOW c) : to(t), rev(r), cap(c) {}\n};\nusing GraphF = std::vector<std::vector<EdgeF>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/FlowTemplate.cpp
  requiredBy:
  - Graph/Dinic.cpp
  - Graph/FordFulkerson.cpp
  timestamp: '2021-03-21 10:20:50+09:00'
  verificationStatus: LIBRARY_SOME_WA
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
