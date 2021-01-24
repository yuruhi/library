---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/Kruskal.cpp
    title: Graph/Kruskal.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Kruskal.test.cpp
    title: test/Kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/UnionFind.test.cpp
    title: test/UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/UnionFind.cpp\"\n#include <vector>\n#include\
    \ <utility>\nusing namespace std;\n\nclass UnionFind {\n\tvector<int> data_m;\n\
    \tint count_components_m;\n\npublic:\n\tUnionFind(int n = 0) {\n\t\tinit(n);\n\
    \t}\n\tvoid init(int n) {\n\t\tdata_m.assign(n, -1);\n\t\tcount_components_m =\
    \ n;\n\t}\n\tint root(int x) {\n\t\treturn data_m[x] < 0 ? x : data_m[x] = root(data_m[x]);\n\
    \t}\n\tbool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\t}\n\tbool\
    \ unite(int x, int y) {\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif (x == y) {\n\
    \t\t\treturn false;\n\t\t}\n\t\tif (data_m[x] > data_m[y]) {\n\t\t\tswap(x, y);\n\
    \t\t}\n\t\tdata_m[x] += data_m[y];\n\t\tdata_m[y] = x;\n\t\tcount_components_m--;\n\
    \t\treturn true;\n\t}\n\tint size(int x) {\n\t\treturn -data_m[root(x)];\n\t}\n\
    \tint count_components() const {\n\t\treturn count_components_m;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\nusing namespace std;\n\
    \nclass UnionFind {\n\tvector<int> data_m;\n\tint count_components_m;\n\npublic:\n\
    \tUnionFind(int n = 0) {\n\t\tinit(n);\n\t}\n\tvoid init(int n) {\n\t\tdata_m.assign(n,\
    \ -1);\n\t\tcount_components_m = n;\n\t}\n\tint root(int x) {\n\t\treturn data_m[x]\
    \ < 0 ? x : data_m[x] = root(data_m[x]);\n\t}\n\tbool same(int x, int y) {\n\t\
    \treturn root(x) == root(y);\n\t}\n\tbool unite(int x, int y) {\n\t\tx = root(x);\n\
    \t\ty = root(y);\n\t\tif (x == y) {\n\t\t\treturn false;\n\t\t}\n\t\tif (data_m[x]\
    \ > data_m[y]) {\n\t\t\tswap(x, y);\n\t\t}\n\t\tdata_m[x] += data_m[y];\n\t\t\
    data_m[y] = x;\n\t\tcount_components_m--;\n\t\treturn true;\n\t}\n\tint size(int\
    \ x) {\n\t\treturn -data_m[root(x)];\n\t}\n\tint count_components() const {\n\t\
    \treturn count_components_m;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.cpp
  requiredBy:
  - Graph/Kruskal.cpp
  timestamp: '2020-11-15 19:06:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/UnionFind.test.cpp
  - test/Kruskal.test.cpp
documentation_of: DataStructure/UnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/UnionFind.cpp
- /library/DataStructure/UnionFind.cpp.html
title: DataStructure/UnionFind.cpp
---
