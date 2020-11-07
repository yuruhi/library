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
    #include <utility>\nusing namespace std;\n\nclass UnionFind {\n\tvector<int> d;\n\
    \tint cnt;\n\npublic:\n\tUnionFind(int n = 0) {\n\t\tinit(n);\n\t}\n\tvoid init(int\
    \ n) {\n\t\td.assign(n, -1);\n\t\tcnt = n;\n\t}\n\tint root(int x) {\n\t\treturn\
    \ d[x] < 0 ? x : d[x] = root(d[x]);\n\t}\n\tbool unite(int x, int y) {\n\t\tx\
    \ = root(x);\n\t\ty = root(y);\n\t\tif (x == y) return false;\n\t\tif (d[x] >\
    \ d[y]) swap(x, y);\n\t\td[x] += d[y];\n\t\td[y] = x;\n\t\tcnt--;\n\t\treturn\
    \ true;\n\t}\n\tbool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\t\
    }\n\tint size(int x) {\n\t\treturn -d[root(x)];\n\t}\n\tint count_components()\
    \ const {\n\t\treturn cnt;\n\t}\n};\n#line 4 \"test/UnionFind.test.cpp\"\nusing\
    \ namespace std;\n\nint main() {\n\tint n, q;\n\tcin >> n >> q;\n\tUnionFind uf(n);\n\
    \twhile (q--) {\n\t\tint t, u, v;\n\t\tcin >> t >> u >> v;\n\t\tif (t == 0) {\n\
    \t\t\tuf.unite(u, v);\n\t\t} else {\n\t\t\tcout << uf.same(u, v) << endl;\n\t\t\
    }\n\t}\n}\n"
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
  timestamp: '2020-11-07 18:36:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/UnionFind.test.cpp
- /verify/test/UnionFind.test.cpp.html
title: test/UnionFind.test.cpp
---
