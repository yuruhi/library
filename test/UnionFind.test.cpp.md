---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.cpp
    title: DataStructure/UnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include <iostream>\n#line 2 \"DataStructure/UnionFind.cpp\"\n#include <vector>\n\
    #include <utility>\nusing namespace std;\n\nclass UnionFind {\n\tvector<int> data_m;\n\
    \tint count_components_m;\n\npublic:\n\tUnionFind(int n = 0) {\n\t\tinit(n);\n\
    \t}\n\tvoid init(int n) {\n\t\tdata_m.assign(n, -1);\n\t\tcount_components_m =\
    \ n;\n\t}\n\tint root(int x) {\n\t\treturn data_m[x] < 0 ? x : data_m[x] = root(data_m[x]);\n\
    \t}\n\tbool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\t}\n\tbool\
    \ unite(int x, int y) {\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif (x == y) {\n\
    \t\t\treturn false;\n\t\t}\n\t\tif (data_m[x] > data_m[y]) {\n\t\t\tswap(x, y);\n\
    \t\t}\n\t\tdata_m[x] += data_m[y];\n\t\tdata_m[y] = x;\n\t\tcount_components_m--;\n\
    \t\treturn true;\n\t}\n\tint size(int x) {\n\t\treturn -data_m[root(x)];\n\t}\n\
    \tint count_components() const {\n\t\treturn count_components_m;\n\t}\n};\n#line\
    \ 4 \"test/UnionFind.test.cpp\"\nusing namespace std;\n\nint main() {\n\tint n,\
    \ q;\n\tcin >> n >> q;\n\tUnionFind uf(n);\n\twhile (q--) {\n\t\tint t, u, v;\n\
    \t\tcin >> t >> u >> v;\n\t\tif (t == 0) {\n\t\t\tuf.unite(u, v);\n\t\t} else\
    \ {\n\t\t\tcout << uf.same(u, v) << endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <iostream>\n\
    #include \"./../DataStructure/UnionFind.cpp\"\nusing namespace std;\n\nint main()\
    \ {\n\tint n, q;\n\tcin >> n >> q;\n\tUnionFind uf(n);\n\twhile (q--) {\n\t\t\
    int t, u, v;\n\t\tcin >> t >> u >> v;\n\t\tif (t == 0) {\n\t\t\tuf.unite(u, v);\n\
    \t\t} else {\n\t\t\tcout << uf.same(u, v) << endl;\n\t\t}\n\t}\n}"
  dependsOn:
  - DataStructure/UnionFind.cpp
  isVerificationFile: true
  path: test/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2020-11-15 19:06:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/UnionFind.test.cpp
- /verify/test/UnionFind.test.cpp.html
title: test/UnionFind.test.cpp
---
