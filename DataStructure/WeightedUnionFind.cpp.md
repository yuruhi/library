---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/WeightedUnionFind.test..cpp
    title: test/WeightedUnionFind.test..cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/WeightedUnionFind.cpp\"\n#include <vector>\n\
    #include <utility>\nusing namespace std;\n\ntemplate <class T> class WeightedUnionFind\
    \ {\npublic:\n\tusing value_type = T;\n\nprivate:\n\tvector<int> par_m, rank_m;\n\
    \tvector<value_type> weight_m;\n\npublic:\n\tWeightedUnionFind(int n) : par_m(n),\
    \ rank_m(n, 0), weight_m(n, 0) {\n\t\tfor (int i = 0; i < n; ++i) par_m[i] = i;\n\
    \t}\n\tint root(int x) {\n\t\tif (par_m[x] == x) {\n\t\t\treturn x;\n\t\t} else\
    \ {\n\t\t\tint r = root(par_m[x]);\n\t\t\tweight_m[x] += weight_m[par_m[x]];\n\
    \t\t\treturn par_m[x] = r;\n\t\t}\n\t}\n\tvalue_type weight(int x) {\n\t\troot(x);\n\
    \t\treturn weight_m[x];\n\t}\n\tbool same(int x, int y) {\n\t\treturn root(x)\
    \ == root(y);\n\t}\n\tbool merge(int x, int y, value_type w) {\n\t\tw += weight(x);\n\
    \t\tw -= weight(y);\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif (x == y) return\
    \ false;\n\t\tif (rank_m[x] < rank_m[y]) {\n\t\t\tswap(x, y);\n\t\t\tw = -w;\n\
    \t\t}\n\t\tif (rank_m[x] == rank_m[y]) rank_m[x]++;\n\t\tpar_m[y] = x;\n\t\tweight_m[y]\
    \ = w;\n\t\treturn true;\n\t}\n\tvalue_type diff(int x, int y) {\n\t\treturn weight(y)\
    \ - weight(x);\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\nusing namespace std;\n\
    \ntemplate <class T> class WeightedUnionFind {\npublic:\n\tusing value_type =\
    \ T;\n\nprivate:\n\tvector<int> par_m, rank_m;\n\tvector<value_type> weight_m;\n\
    \npublic:\n\tWeightedUnionFind(int n) : par_m(n), rank_m(n, 0), weight_m(n, 0)\
    \ {\n\t\tfor (int i = 0; i < n; ++i) par_m[i] = i;\n\t}\n\tint root(int x) {\n\
    \t\tif (par_m[x] == x) {\n\t\t\treturn x;\n\t\t} else {\n\t\t\tint r = root(par_m[x]);\n\
    \t\t\tweight_m[x] += weight_m[par_m[x]];\n\t\t\treturn par_m[x] = r;\n\t\t}\n\t\
    }\n\tvalue_type weight(int x) {\n\t\troot(x);\n\t\treturn weight_m[x];\n\t}\n\t\
    bool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\t}\n\tbool merge(int\
    \ x, int y, value_type w) {\n\t\tw += weight(x);\n\t\tw -= weight(y);\n\t\tx =\
    \ root(x);\n\t\ty = root(y);\n\t\tif (x == y) return false;\n\t\tif (rank_m[x]\
    \ < rank_m[y]) {\n\t\t\tswap(x, y);\n\t\t\tw = -w;\n\t\t}\n\t\tif (rank_m[x] ==\
    \ rank_m[y]) rank_m[x]++;\n\t\tpar_m[y] = x;\n\t\tweight_m[y] = w;\n\t\treturn\
    \ true;\n\t}\n\tvalue_type diff(int x, int y) {\n\t\treturn weight(y) - weight(x);\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/WeightedUnionFind.cpp
  requiredBy: []
  timestamp: '2020-11-26 13:12:58+09:00'
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
