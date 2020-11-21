---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/PartiallyPersistentUnionFind.cpp\"\n#include\
    \ <vector>\n#include <utility>\n#include <limits>\nusing namespace std;\n\nclass\
    \ PartiallyPersistentUnionFind {\n\tvector<int> par_m, rank_m, time_m;\n\tvector<vector<pair<int,\
    \ int>>> size_m;\n\tint now_m;\n\tstatic constexpr int INF = numeric_limits<int>::max();\n\
    \npublic:\n\tPartiallyPersistentUnionFind(size_t n)\n\t    : par_m(n), rank_m(n),\
    \ time_m(n, INF), size_m(n), now_m(0) {\n\t\tfor (size_t i = 0; i < n; ++i) {\n\
    \t\t\tpar_m[i] = i;\n\t\t\tsize_m[i].emplace_back(0, 1);\n\t\t}\n\t}\n\tint root(int\
    \ x, int t) const {\n\t\tif (t < time_m[x]) {\n\t\t\treturn x;\n\t\t} else {\n\
    \t\t\treturn root(par_m[x], t);\n\t\t}\n\t}\n\tbool same(int x, int y, int t)\
    \ const {\n\t\treturn root(x, t) == root(y, t);\n\t}\n\tint size(int x, int t)\
    \ const {\n\t\tx = root(x, t);\n\t\tint ok = 0, ng = size_m[x].size();\n\t\twhile\
    \ (ng - ok > 1) {\n\t\t\tint mid = (ok + ng) / 2;\n\t\t\t(size_m[x][mid].first\
    \ <= t ? ok : ng) = mid;\n\t\t}\n\t\treturn size_m[x][ok].second;\n\t}\n\tbool\
    \ unite(int x, int y) {\n\t\tnow_m++;\n\t\tx = root(x, now_m);\n\t\ty = root(y,\
    \ now_m);\n\t\tif (x == y) {\n\t\t\treturn false;\n\t\t}\n\t\tif (rank_m[x] <\
    \ rank_m[y]) {\n\t\t\tswap(x, y);\n\t\t}\n\t\tsize_m[x].emplace_back(now_m, size(x,\
    \ now_m) + size(y, now_m));\n\t\tpar_m[y] = x;\n\t\ttime_m[y] = now_m;\n\t\tif\
    \ (rank_m[x] == rank_m[y]) {\n\t\t\trank_m[x]++;\n\t\t}\n\t\treturn true;\n\t\
    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <limits>\n\
    using namespace std;\n\nclass PartiallyPersistentUnionFind {\n\tvector<int> par_m,\
    \ rank_m, time_m;\n\tvector<vector<pair<int, int>>> size_m;\n\tint now_m;\n\t\
    static constexpr int INF = numeric_limits<int>::max();\n\npublic:\n\tPartiallyPersistentUnionFind(size_t\
    \ n)\n\t    : par_m(n), rank_m(n), time_m(n, INF), size_m(n), now_m(0) {\n\t\t\
    for (size_t i = 0; i < n; ++i) {\n\t\t\tpar_m[i] = i;\n\t\t\tsize_m[i].emplace_back(0,\
    \ 1);\n\t\t}\n\t}\n\tint root(int x, int t) const {\n\t\tif (t < time_m[x]) {\n\
    \t\t\treturn x;\n\t\t} else {\n\t\t\treturn root(par_m[x], t);\n\t\t}\n\t}\n\t\
    bool same(int x, int y, int t) const {\n\t\treturn root(x, t) == root(y, t);\n\
    \t}\n\tint size(int x, int t) const {\n\t\tx = root(x, t);\n\t\tint ok = 0, ng\
    \ = size_m[x].size();\n\t\twhile (ng - ok > 1) {\n\t\t\tint mid = (ok + ng) /\
    \ 2;\n\t\t\t(size_m[x][mid].first <= t ? ok : ng) = mid;\n\t\t}\n\t\treturn size_m[x][ok].second;\n\
    \t}\n\tbool unite(int x, int y) {\n\t\tnow_m++;\n\t\tx = root(x, now_m);\n\t\t\
    y = root(y, now_m);\n\t\tif (x == y) {\n\t\t\treturn false;\n\t\t}\n\t\tif (rank_m[x]\
    \ < rank_m[y]) {\n\t\t\tswap(x, y);\n\t\t}\n\t\tsize_m[x].emplace_back(now_m,\
    \ size(x, now_m) + size(y, now_m));\n\t\tpar_m[y] = x;\n\t\ttime_m[y] = now_m;\n\
    \t\tif (rank_m[x] == rank_m[y]) {\n\t\t\trank_m[x]++;\n\t\t}\n\t\treturn true;\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PartiallyPersistentUnionFind.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/PartiallyPersistentUnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/PartiallyPersistentUnionFind.cpp
- /library/DataStructure/PartiallyPersistentUnionFind.cpp.html
title: DataStructure/PartiallyPersistentUnionFind.cpp
---