---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/WeightedUnionFind.test..cpp
    title: test/WeightedUnionFind.test..cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/WeightedUnionFind.cpp\"\n#include <vector>\n\
    #include <utility>\nusing namespace std;\n\ntemplate <class T> class WeightedUnionFind\
    \ {\n\tvector<int> par, rank;\n\tvector<T> weight_;\n\npublic:\n\tWeightedUnionFind(int\
    \ n) : par(n), rank(n, 0), weight_(n, 0) {\n\t\tfor (int i = 0; i < n; ++i)\n\t\
    \t\tpar[i] = i;\n\t}\n\tint root(int x) {\n\t\tif (par[x] == x) return x;\n\t\t\
    int r = root(par[x]);\n\t\tweight_[x] += weight_[par[x]];\n\t\treturn par[x] =\
    \ r;\n\t}\n\tT weight(int x) {\n\t\troot(x);\n\t\treturn weight_[x];\n\t}\n\t\
    bool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\t}\n\tbool merge(int\
    \ x, int y, T w) {\n\t\tw += weight(x);\n\t\tw -= weight(y);\n\t\tx = root(x);\n\
    \t\ty = root(y);\n\t\tif (x == y) return false;\n\t\tif (rank[x] < rank[y]) {\n\
    \t\t\tswap(x, y);\n\t\t\tw = -w;\n\t\t}\n\t\tif (rank[x] == rank[y]) rank[x]++;\n\
    \t\tpar[y] = x;\n\t\tweight_[y] = w;\n\t\treturn true;\n\t}\n\tT diff(int x, int\
    \ y) {\n\t\treturn weight(y) - weight(x);\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\nusing namespace std;\n\
    \ntemplate <class T> class WeightedUnionFind {\n\tvector<int> par, rank;\n\tvector<T>\
    \ weight_;\n\npublic:\n\tWeightedUnionFind(int n) : par(n), rank(n, 0), weight_(n,\
    \ 0) {\n\t\tfor (int i = 0; i < n; ++i)\n\t\t\tpar[i] = i;\n\t}\n\tint root(int\
    \ x) {\n\t\tif (par[x] == x) return x;\n\t\tint r = root(par[x]);\n\t\tweight_[x]\
    \ += weight_[par[x]];\n\t\treturn par[x] = r;\n\t}\n\tT weight(int x) {\n\t\t\
    root(x);\n\t\treturn weight_[x];\n\t}\n\tbool same(int x, int y) {\n\t\treturn\
    \ root(x) == root(y);\n\t}\n\tbool merge(int x, int y, T w) {\n\t\tw += weight(x);\n\
    \t\tw -= weight(y);\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif (x == y) return\
    \ false;\n\t\tif (rank[x] < rank[y]) {\n\t\t\tswap(x, y);\n\t\t\tw = -w;\n\t\t\
    }\n\t\tif (rank[x] == rank[y]) rank[x]++;\n\t\tpar[y] = x;\n\t\tweight_[y] = w;\n\
    \t\treturn true;\n\t}\n\tT diff(int x, int y) {\n\t\treturn weight(y) - weight(x);\n\
    \t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/WeightedUnionFind.cpp
  requiredBy: []
  timestamp: '2020-10-04 16:56:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/WeightedUnionFind.test..cpp
documentation_of: DataStructure/WeightedUnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/WeightedUnionFind.cpp
- /library/DataStructure/WeightedUnionFind.cpp.html
title: DataStructure/WeightedUnionFind.cpp
---
