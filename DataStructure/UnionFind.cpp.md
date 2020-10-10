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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind.cpp\"\n#include <vector>\n#include\
    \ <utility>\nusing namespace std;\n\nclass UnionFind {\n\tvector<int> d;\n\tint\
    \ cnt;\n\npublic:\n\tUnionFind(int n = 0) {\n\t\tinit(n);\n\t}\n\tvoid init(int\
    \ n) {\n\t\td.assign(n, -1);\n\t\tcnt = n;\n\t}\n\tint root(int x) {\n\t\treturn\
    \ d[x] < 0 ? x : d[x] = root(d[x]);\n\t}\n\tbool unite(int x, int y) {\n\t\tx\
    \ = root(x);\n\t\ty = root(y);\n\t\tif (x == y) return false;\n\t\tif (d[x] >\
    \ d[y]) swap(x, y);\n\t\td[x] += d[y];\n\t\td[y] = x;\n\t\tcnt--;\n\t\treturn\
    \ true;\n\t}\n\tbool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\t\
    }\n\tint size(int x) {\n\t\treturn -d[root(x)];\n\t}\n\tint count_components()\
    \ const {\n\t\treturn cnt;\n\t}\n};\n"
  code: "#include <vector>\n#include <utility>\nusing namespace std;\n\nclass UnionFind\
    \ {\n\tvector<int> d;\n\tint cnt;\n\npublic:\n\tUnionFind(int n = 0) {\n\t\tinit(n);\n\
    \t}\n\tvoid init(int n) {\n\t\td.assign(n, -1);\n\t\tcnt = n;\n\t}\n\tint root(int\
    \ x) {\n\t\treturn d[x] < 0 ? x : d[x] = root(d[x]);\n\t}\n\tbool unite(int x,\
    \ int y) {\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif (x == y) return false;\n\
    \t\tif (d[x] > d[y]) swap(x, y);\n\t\td[x] += d[y];\n\t\td[y] = x;\n\t\tcnt--;\n\
    \t\treturn true;\n\t}\n\tbool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\
    \t}\n\tint size(int x) {\n\t\treturn -d[root(x)];\n\t}\n\tint count_components()\
    \ const {\n\t\treturn cnt;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.cpp
  requiredBy:
  - Graph/Kruskal.cpp
  timestamp: '2020-10-04 13:14:27+09:00'
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
